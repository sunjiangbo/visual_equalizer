// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.2
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _math_accel_HH_
#define _math_accel_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "math_accel_Block_ZrsILi32ELb0EE11ap_int_s.h"
#include "math_accel_hls_fptoui_double_i321.h"
#include "math_accel_Block_ZrsILi32ELb0EE11ap_int_1.h"
#include "FIFO_math_accel_tmp_last_V_2_loc_channel.h"
#include "FIFO_math_accel_tmp_4_loc_channel.h"
#include "FIFO_math_accel_p_channel.h"
#include "math_accel_control_intr_s_axi.h"

namespace ap_rtl {

template<unsigned int C_S_AXI_CONTROL_INTR_ADDR_WIDTH = 4,
         unsigned int C_S_AXI_CONTROL_INTR_DATA_WIDTH = 32>
struct math_accel : public sc_module {
    // Port declarations 38
    sc_in< sc_logic > s_axi_control_intr_AWVALID;
    sc_out< sc_logic > s_axi_control_intr_AWREADY;
    sc_in< sc_uint<C_S_AXI_CONTROL_INTR_ADDR_WIDTH> > s_axi_control_intr_AWADDR;
    sc_in< sc_logic > s_axi_control_intr_WVALID;
    sc_out< sc_logic > s_axi_control_intr_WREADY;
    sc_in< sc_uint<C_S_AXI_CONTROL_INTR_DATA_WIDTH> > s_axi_control_intr_WDATA;
    sc_in< sc_uint<C_S_AXI_CONTROL_INTR_DATA_WIDTH/8> > s_axi_control_intr_WSTRB;
    sc_in< sc_logic > s_axi_control_intr_ARVALID;
    sc_out< sc_logic > s_axi_control_intr_ARREADY;
    sc_in< sc_uint<C_S_AXI_CONTROL_INTR_ADDR_WIDTH> > s_axi_control_intr_ARADDR;
    sc_out< sc_logic > s_axi_control_intr_RVALID;
    sc_in< sc_logic > s_axi_control_intr_RREADY;
    sc_out< sc_uint<C_S_AXI_CONTROL_INTR_DATA_WIDTH> > s_axi_control_intr_RDATA;
    sc_out< sc_lv<2> > s_axi_control_intr_RRESP;
    sc_out< sc_logic > s_axi_control_intr_BVALID;
    sc_in< sc_logic > s_axi_control_intr_BREADY;
    sc_out< sc_lv<2> > s_axi_control_intr_BRESP;
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst_n;
    sc_out< sc_logic > interrupt;
    sc_in< sc_lv<32> > in_stream_TDATA;
    sc_in< sc_lv<4> > in_stream_TKEEP;
    sc_in< sc_lv<4> > in_stream_TSTRB;
    sc_in< sc_lv<1> > in_stream_TUSER;
    sc_in< sc_lv<1> > in_stream_TLAST;
    sc_in< sc_lv<1> > in_stream_TID;
    sc_in< sc_lv<1> > in_stream_TDEST;
    sc_out< sc_lv<32> > out_stream_TDATA;
    sc_out< sc_lv<4> > out_stream_TKEEP;
    sc_out< sc_lv<4> > out_stream_TSTRB;
    sc_out< sc_lv<1> > out_stream_TUSER;
    sc_out< sc_lv<1> > out_stream_TLAST;
    sc_out< sc_lv<1> > out_stream_TID;
    sc_out< sc_lv<1> > out_stream_TDEST;
    sc_in< sc_logic > in_stream_TVALID;
    sc_out< sc_logic > in_stream_TREADY;
    sc_out< sc_logic > out_stream_TVALID;
    sc_in< sc_logic > out_stream_TREADY;
    sc_signal< sc_logic > ap_var_for_const0;


    // Module declarations
    math_accel(sc_module_name name);
    SC_HAS_PROCESS(math_accel);

    ~math_accel();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    math_accel_control_intr_s_axi<C_S_AXI_CONTROL_INTR_ADDR_WIDTH,C_S_AXI_CONTROL_INTR_DATA_WIDTH>* math_accel_control_intr_s_axi_U;
    math_accel_Block_ZrsILi32ELb0EE11ap_int_s* math_accel_Block_ZrsILi32ELb0EE11ap_int_U0;
    math_accel_hls_fptoui_double_i321* math_accel_hls_fptoui_double_i321_U0;
    math_accel_Block_ZrsILi32ELb0EE11ap_int_1* math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0;
    FIFO_math_accel_tmp_last_V_2_loc_channel* tmp_last_V_2_loc_channel_U;
    FIFO_math_accel_tmp_4_loc_channel* tmp_4_loc_channel_U;
    FIFO_math_accel_p_channel* p_channel_U;
    sc_signal< sc_logic > ap_rst_n_inv;
    sc_signal< sc_logic > ap_start;
    sc_signal< sc_logic > ap_ready;
    sc_signal< sc_logic > ap_done;
    sc_signal< sc_logic > ap_idle;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_ap_start;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_ap_done;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_ap_continue;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_ap_idle;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_ap_ready;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_in_stream_TREADY;
    sc_signal< sc_lv<1> > math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_tmp_last_V_2_out_out_din;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_tmp_last_V_2_out_out_write;
    sc_signal< sc_lv<64> > math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_ap_return;
    sc_signal< sc_logic > ap_chn_write_math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_tmp_4_loc_channel;
    sc_signal< sc_logic > tmp_4_loc_channel_full_n;
    sc_signal< sc_logic > math_accel_hls_fptoui_double_i321_U0_ap_start;
    sc_signal< sc_logic > math_accel_hls_fptoui_double_i321_U0_ap_done;
    sc_signal< sc_logic > math_accel_hls_fptoui_double_i321_U0_ap_continue;
    sc_signal< sc_logic > math_accel_hls_fptoui_double_i321_U0_ap_idle;
    sc_signal< sc_logic > math_accel_hls_fptoui_double_i321_U0_ap_ready;
    sc_signal< sc_lv<32> > math_accel_hls_fptoui_double_i321_U0_return_r;
    sc_signal< sc_logic > math_accel_hls_fptoui_double_i321_U0_return_r_ap_vld;
    sc_signal< sc_logic > ap_chn_write_math_accel_hls_fptoui_double_i321_U0_p_channel;
    sc_signal< sc_logic > p_channel_full_n;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_ap_start;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_ap_done;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_ap_continue;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_ap_idle;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_ap_ready;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_tmp_last_V_2_reload_read;
    sc_signal< sc_lv<32> > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_out_stream_TDATA;
    sc_signal< sc_logic > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_out_stream_TVALID;
    sc_signal< sc_lv<4> > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_out_stream_TKEEP;
    sc_signal< sc_lv<4> > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_out_stream_TSTRB;
    sc_signal< sc_lv<1> > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_out_stream_TUSER;
    sc_signal< sc_lv<1> > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_out_stream_TLAST;
    sc_signal< sc_lv<1> > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_out_stream_TID;
    sc_signal< sc_lv<1> > math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_out_stream_TDEST;
    sc_signal< sc_logic > ap_sig_hs_continue;
    sc_signal< sc_logic > tmp_last_V_2_loc_channel_full_n;
    sc_signal< sc_lv<1> > tmp_last_V_2_loc_channel_dout;
    sc_signal< sc_logic > tmp_last_V_2_loc_channel_empty_n;
    sc_signal< sc_lv<64> > tmp_4_loc_channel_dout;
    sc_signal< sc_logic > tmp_4_loc_channel_empty_n;
    sc_signal< sc_lv<32> > p_channel_dout;
    sc_signal< sc_logic > p_channel_empty_n;
    sc_signal< sc_logic > ap_sig_hs_done;
    sc_signal< sc_logic > ap_sig_hs_ready;
    static const int C_S_AXI_DATA_WIDTH;
    static const int C_S_AXI_WSTRB_WIDTH;
    static const int C_S_AXI_ADDR_WIDTH;
    static const sc_logic ap_const_logic_1;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_logic ap_const_logic_0;
    static const bool ap_true;
    // Thread declarations
    void thread_ap_var_for_const0();
    void thread_ap_chn_write_math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_tmp_4_loc_channel();
    void thread_ap_chn_write_math_accel_hls_fptoui_double_i321_U0_p_channel();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_ap_rst_n_inv();
    void thread_ap_sig_hs_continue();
    void thread_ap_sig_hs_done();
    void thread_ap_sig_hs_ready();
    void thread_in_stream_TREADY();
    void thread_math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_ap_continue();
    void thread_math_accel_Block_ZrsILi32ELb0EE11ap_int_1_U0_ap_start();
    void thread_math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_ap_continue();
    void thread_math_accel_Block_ZrsILi32ELb0EE11ap_int_U0_ap_start();
    void thread_math_accel_hls_fptoui_double_i321_U0_ap_continue();
    void thread_math_accel_hls_fptoui_double_i321_U0_ap_start();
    void thread_out_stream_TDATA();
    void thread_out_stream_TDEST();
    void thread_out_stream_TID();
    void thread_out_stream_TKEEP();
    void thread_out_stream_TLAST();
    void thread_out_stream_TSTRB();
    void thread_out_stream_TUSER();
    void thread_out_stream_TVALID();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif
