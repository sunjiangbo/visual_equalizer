/*
 * Purpose: Create image for VGA monitor after receiving magnitude of FFT
 * computed in the FPGA.
 * Author: Andrew Powell
 */
#include <stdint.h>
#include <math.h>
#include "xparameters.h"
#include "xscugic.h"
#include "xaxidma.h"
#include "display_ctrl.h"
#include "xil_assert.h"
#include "xil_mmu.h"
#include "mat.h"
#include "shared.h"

using namespace la;
using namespace shared;

#define INCT_DEVICE_ID					( XPAR_PS7_SCUGIC_0_DEVICE_ID )
#define FFT_PROCESS_DMA_DEVICE_ID		( XPAR_AXI_DMA_0_DEVICE_ID )
#define FFT_PROCESS_DMA_S2MM_INT_ID		( XPAR_FABRIC_AXI_DMA_0_S2MM_INTROUT_INTR )
#define CPU_0_INT_ID					( 2 )
#define CPU_0_DEVICE_ID					( 1 )
#define CPU_1_DEVICE_ID					( 2 )
#define VGA_DISPLAY_ADDR				( XPAR_AXI_DISPCTRL_0_S_AXI_BASEADDR )
#define VGA_VDMA_DEVICE_ID				( XPAR_AXI_VDMA_0_DEVICE_ID )
#define VGA_DISPLAY_IS_HDMI				( 0 )
#define VGA_DISPLAY_WIDTH				( 640 )
#define VGA_DISPLAY_HEIGHT				( 480 )
#define VGA_DISPLAY_MODE				( VMODE_640x480 )
#define VGA_DISPLAY_STRIDE				( sizeof(uint32_t)*VGA_DISPLAY_WIDTH )
#define VGA_DISPLAY_BUFF_ADDR			( 0x300000 )
#define VGA_FFT_REC_AMOUNT				( 128 )
#define VGA_FFT_REC_HEIGHT				( VGA_DISPLAY_HEIGHT )
#define VGA_FFT_REC_WIDTH				( VGA_DISPLAY_WIDTH/VGA_FFT_REC_AMOUNT )
#define VGA_FFT_SAMPLES_START			( 0 )
#define VGA_FFT_SAMPLES_SIZE			( BUFFER_LEN*5/12 )
#define VGA_FFT_SAMPLES_PER_REC_WIDTH	( VGA_FFT_SAMPLES_SIZE/VGA_FFT_REC_AMOUNT )
#define VGA_FFT_SAMPLES_TO_SUM			( VGA_FFT_SAMPLES_PER_REC_WIDTH )

typedef pixel<uint8_t,4> display_pixel;
typedef mat<display_pixel,VGA_DISPLAY_HEIGHT,VGA_DISPLAY_WIDTH,VGA_DISPLAY_STRIDE> display_mat;

XScuGic intc_obj;
XAxiDma process_dma_obj;
DisplayCtrl display_obj;
display_mat* framebuffs = reinterpret_cast<display_mat*>( VGA_DISPLAY_BUFF_ADDR );
u32* frameptrs[ DISPLAY_NUM_FRAMES ];

struct fft_struct
{
	volatile display_pixel pix_empty[ VGA_FFT_REC_AMOUNT ];
	volatile display_pixel pix_fill[ VGA_FFT_REC_AMOUNT ];
	double prev_logs[ VGA_FFT_REC_AMOUNT ];
}
fft_objs;


void fft_process_dma_s2mm_handler( void* param );

int XAxiDma_CfgInitialize2(XAxiDma * InstancePtr, XAxiDma_Config *Config);

int main()
{
	/* Initialize the interrupt driver. */
	{
		XScuGic_Config* config;
		int Status;

		config = XScuGic_LookupConfig( INCT_DEVICE_ID );
		Xil_AssertNonvoid( config!=NULL );
		Status = XScuGic_CfgInitialize( &intc_obj, config, config->CpuBaseAddress );
		Xil_AssertNonvoid( Status==XST_SUCCESS );

		/* The interrupt controller needs to be associated with the CPU's interrupt. */
		Xil_ExceptionRegisterHandler( XIL_EXCEPTION_ID_IRQ_INT,
				reinterpret_cast<Xil_ExceptionHandler>( XScuGic_InterruptHandler ),
				 &intc_obj );
	}

	/* Initialize the dma associated with the fft core. A separate configuration
	method is created from the original to ensure the DMA core is not put in reset. */
	{
		int Status;
		XAxiDma_Config* config;

		config = XAxiDma_LookupConfig( FFT_PROCESS_DMA_DEVICE_ID );
		Xil_AssertNonvoid( config!=NULL );
		Status = XAxiDma_CfgInitialize2( &process_dma_obj, config );
		Xil_AssertNonvoid( Status==XST_SUCCESS );

		/* Associate interrupt request routine with interrupt controller. */
		Status = XScuGic_Connect( &intc_obj, FFT_PROCESS_DMA_S2MM_INT_ID, fft_process_dma_s2mm_handler, NULL );
		Xil_AssertNonvoid( Status==XST_SUCCESS );
		XScuGic_Enable( &intc_obj, FFT_PROCESS_DMA_S2MM_INT_ID );
	}

	/* Configure the display. */
	{
		/* Initialize the frame buffer memory. */
		{
			//display_pixel pix( 255, 255, 255, 0 ); /* BGR_ */
			INTPTR cur_addr = VGA_DISPLAY_BUFF_ADDR;
			INTPTR end_addr = VGA_DISPLAY_BUFF_ADDR+(sizeof(display_mat)*DISPLAY_NUM_FRAMES);

			/* Configure memory as device share-able. */
			while ( cur_addr<end_addr )
			{
				Xil_SetTlbAttributes( cur_addr, DEVICE_MEMORY|SHAREABLE );
				cur_addr += 0x100000;
			}
			Xil_SetTlbAttributes( cur_addr, DEVICE_MEMORY|SHAREABLE );

			/* Acquire array of frame buffer pointers and initialize memory. */
			for ( int each_frame=0; each_frame<DISPLAY_NUM_FRAMES; each_frame++ )
				frameptrs[ each_frame ] = reinterpret_cast<u32*>( &framebuffs[ each_frame ] );
		}

		/* Initialize the VDMA and display controller. */
		{
			int Status;

			Status = DisplayInitialize( &display_obj, VGA_VDMA_DEVICE_ID, VGA_DISPLAY_ADDR,
					VGA_DISPLAY_IS_HDMI, frameptrs,	static_cast<u32>( VGA_DISPLAY_STRIDE ) );
			Xil_AssertNonvoid( Status==XST_SUCCESS );
			Status = DisplaySetMode( &display_obj, &VGA_DISPLAY_MODE );
			Xil_AssertNonvoid( Status==XST_SUCCESS );
		}
	}

	/* Configure OCM memory so that samples can be read from it without
	worrying about the cache hierarchy. */
	{
		Xil_SetTlbAttributes( BUFFER_BASE_ADDR, DEVICE_MEMORY|SHAREABLE );
	}

	/* Have all the colors for the rectangles pre-generated. */
	{
		for ( int each_rec=0; each_rec<VGA_FFT_REC_AMOUNT; each_rec++ )
		{
			volatile uint8_t* data_empty = fft_objs.pix_empty[ each_rec ].get();
			volatile uint8_t* data_fill = fft_objs.pix_fill[ each_rec ].get();

			uint8_t color_0 = static_cast<uint8_t>( each_rec*255/VGA_FFT_REC_AMOUNT );
			uint8_t color_1 = static_cast<uint8_t>( (VGA_FFT_REC_AMOUNT-1-each_rec)*255/VGA_FFT_REC_AMOUNT );

			data_empty[ 0 ] = 0;
			data_empty[ 1 ] = color_1;
			data_empty[ 2 ] = color_0;
			data_fill[ 0 ] = 0;
			data_fill[ 1 ] = color_0;
			data_fill[ 2 ] = color_1;
		}
	}

	/* Start CPU1's application. */
	{
		/* Enable the interrupt on CPU1. */
		Xil_ExceptionEnable();

		/* Start display. */
		{
			int Status;
			Status = DisplayChangeFrame( &display_obj , 0 );
			Xil_AssertNonvoid( Status==XST_SUCCESS );
			Status = DisplayStart( &display_obj );
			Xil_AssertNonvoid( Status==XST_SUCCESS );
		}

		/* Send interrupt to CPU0, signaling CPU1 has been configured and is ready for operation. */
		{
			int Status;
			Status = XScuGic_SoftwareIntr( &intc_obj, CPU_0_INT_ID, CPU_0_DEVICE_ID );
			Xil_AssertNonvoid( Status==XST_SUCCESS );
		}

		/* Block and wait for interrupt. The main loop of this
		application doesn't need to do anything since all operations
		are done through the interrupt service routine. */
		while ( true )
		{
			__asm__ ( "wfi" );
		}
	}

	return 0;
}

void fft_process_dma_s2mm_handler( void* param )
{
	( void ) param;

	/* Acknowledge the interrupt. */
	XAxiDma_IntrAckIrq( &process_dma_obj, XAXIDMA_IRQ_IOC_MASK, XAXIDMA_DEVICE_TO_DMA );

	/* Draw visual equalizer. */
	{
		static display_pixel pix_0( 255, 0, 0, 0 );
		static display_pixel pix_1( 0, 255, 0, 0 );
		BUFFER_TYPE* sample_ptr = getbufferset().getouput().getref()+VGA_FFT_SAMPLES_START;
		double* prev_log_ptr = fft_objs.prev_logs;
		int col = 0;
		double prev_log = 0;
		display_pixel* pix_fill_ptr = const_cast<display_pixel*>( fft_objs.pix_fill );
		display_pixel* pix_empty_ptr = const_cast<display_pixel*>( fft_objs.pix_empty );

		while ( col<VGA_DISPLAY_WIDTH )
		{
			BUFFER_TYPE avg = 0;
			double curr_log;
			int rec_height;
			uint8_t color;

			/* Get average. */
			{
				BUFFER_TYPE* beg_ptr = sample_ptr;
				BUFFER_TYPE* end_ptr = sample_ptr+VGA_FFT_SAMPLES_TO_SUM;
				while ( beg_ptr!=end_ptr )
					avg += *(beg_ptr++);
				avg /= VGA_FFT_SAMPLES_TO_SUM;
			}

			/* Generate log. */
			if ( avg!=0 )
			{
				curr_log = log(static_cast<double>(avg))*60 - VGA_DISPLAY_HEIGHT/5;
			}
			else
			{
				curr_log = 0;
			}

			/* The value that's eventually displayed is actually
			a weight average for smoothing, specifically EWMA. */
			curr_log = 0.20*curr_log + 0.25*prev_log + 0.55*(*prev_log_ptr);
			prev_log = curr_log;
			*prev_log_ptr = curr_log;

			/* Impose limits on the rectangle height. */
			rec_height = static_cast<int>(curr_log);
			if ( rec_height>=VGA_FFT_REC_HEIGHT )
				rec_height = VGA_FFT_REC_HEIGHT-1;
			if ( rec_height<=0 )
				rec_height = 0;

			/* Have the background fill color change according to height! */
			color = static_cast<uint8_t>( rec_height*255/VGA_DISPLAY_HEIGHT );
			static_cast<volatile display_pixel*>(pix_empty_ptr)->get()[ 0 ] = color;

			/* Perform fill operations. */
			fill( framebuffs[ 0 ], *pix_empty_ptr, 0, col, VGA_FFT_REC_HEIGHT-rec_height,  VGA_FFT_REC_WIDTH );
			fill( framebuffs[ 0 ], *pix_fill_ptr, VGA_FFT_REC_HEIGHT-rec_height, col, rec_height,  VGA_FFT_REC_WIDTH );

			/* Prepare to fill next rectangle. */
			sample_ptr += VGA_FFT_SAMPLES_PER_REC_WIDTH;
			col += VGA_FFT_REC_WIDTH;
			prev_log_ptr++;
			pix_fill_ptr++;
			pix_empty_ptr++;
		}

		/* Prepare to grab data from next buffer. */
		incbufferset();
	}
}

int XAxiDma_CfgInitialize2(XAxiDma * InstancePtr, XAxiDma_Config *Config)
{
	UINTPTR BaseAddr;
	int Index;
	u32 MaxTransferLen;

	InstancePtr->Initialized = 0;

	if(!Config) {
		return XST_INVALID_PARAM;
	}

	BaseAddr = Config->BaseAddr;

	/* Setup the instance */
	memset(InstancePtr, 0, sizeof(XAxiDma));
	InstancePtr->RegBase = BaseAddr;

	/* Get hardware setting information from the configuration structure
	 */
	InstancePtr->HasMm2S = Config->HasMm2S;
	InstancePtr->HasS2Mm = Config->HasS2Mm;

	InstancePtr->HasSg = Config->HasSg;

	InstancePtr->MicroDmaMode = Config->MicroDmaMode;
	InstancePtr->AddrWidth = Config->AddrWidth;

	/* Get the number of channels */
	InstancePtr->TxNumChannels = Config->Mm2sNumChannels;
	InstancePtr->RxNumChannels = Config->S2MmNumChannels;

	/* This condition is for IP version < 6.00a */
	if (!InstancePtr->TxNumChannels)
		InstancePtr->TxNumChannels = 1;
	if (!InstancePtr->RxNumChannels)
		InstancePtr->RxNumChannels = 1;

	if ((InstancePtr->RxNumChannels > 1) ||
		(InstancePtr->TxNumChannels > 1)) {
		MaxTransferLen =
			XAXIDMA_MCHAN_MAX_TRANSFER_LEN;
	}
	else {
		MaxTransferLen =
			XAXIDMA_MAX_TRANSFER_LEN;
	}

	/* Initialize the ring structures */
	InstancePtr->TxBdRing.RunState = AXIDMA_CHANNEL_HALTED;
	InstancePtr->TxBdRing.IsRxChannel = 0;
	if (!InstancePtr->MicroDmaMode) {
		InstancePtr->TxBdRing.MaxTransferLen = MaxTransferLen;
	}
	else {
		/* In MicroDMA mode, Maximum length that can be transferred
		 * is '(Memory Data Width / 4) * Burst Size'
		 */
		InstancePtr->TxBdRing.MaxTransferLen =
				((Config->Mm2SDataWidth / 4) *
				 Config->Mm2SBurstSize);
	}
	InstancePtr->TxBdRing.RingIndex = 0;

	for (Index = 0; Index < InstancePtr->RxNumChannels; Index++) {
		InstancePtr->RxBdRing[Index].RunState
						 = AXIDMA_CHANNEL_HALTED;
		InstancePtr->RxBdRing[Index].IsRxChannel = 1;
		InstancePtr->RxBdRing[Index].RingIndex = Index;
	}

	if (InstancePtr->HasMm2S) {
		InstancePtr->TxBdRing.ChanBase =
				BaseAddr + XAXIDMA_TX_OFFSET;
		InstancePtr->TxBdRing.HasStsCntrlStrm =
					Config->HasStsCntrlStrm;
		if (InstancePtr->AddrWidth > 32)
			InstancePtr->TxBdRing.Addr_ext = 1;
		else
			InstancePtr->TxBdRing.Addr_ext = 0;

		InstancePtr->TxBdRing.HasDRE = Config->HasMm2SDRE;
		InstancePtr->TxBdRing.DataWidth =
			((unsigned int)Config->Mm2SDataWidth >> 3);
	}

	if (InstancePtr->HasS2Mm) {
		for (Index = 0;
			Index < InstancePtr->RxNumChannels; Index++) {
			InstancePtr->RxBdRing[Index].ChanBase =
					BaseAddr + XAXIDMA_RX_OFFSET;
			InstancePtr->RxBdRing[Index].HasStsCntrlStrm =
					Config->HasStsCntrlStrm;
			InstancePtr->RxBdRing[Index].HasDRE =
					Config->HasS2MmDRE;
			InstancePtr->RxBdRing[Index].DataWidth =
			((unsigned int)Config->S2MmDataWidth >> 3);

			if (!InstancePtr->MicroDmaMode) {
				InstancePtr->RxBdRing[Index].MaxTransferLen =
							MaxTransferLen;
			}
			else {
			/* In MicroDMA mode, Maximum length that can be transferred
			 * is '(Memory Data Width / 4) * Burst Size'
			 */
				InstancePtr->RxBdRing[Index].MaxTransferLen =
						((Config->S2MmDataWidth / 4) *
						Config->S2MmBurstSize);
			}
			if (InstancePtr->AddrWidth > 32)
				InstancePtr->RxBdRing[Index].Addr_ext = 1;
			else
				InstancePtr->RxBdRing[Index].Addr_ext = 0;
		}
	}

	/* The portion of code that resets the DMA is completely, removed. */

	/* Initialization is successful
	 */
	InstancePtr->Initialized = 1;

	return XST_SUCCESS;
}
