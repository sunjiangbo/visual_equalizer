// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.2
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xmath_accel.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMath_accel_CfgInitialize(XMath_accel *InstancePtr, XMath_accel_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_intr_BaseAddress = ConfigPtr->Control_intr_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMath_accel_Start(XMath_accel *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMath_accel_ReadReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_AP_CTRL) & 0x80;
    XMath_accel_WriteReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMath_accel_IsDone(XMath_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMath_accel_ReadReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMath_accel_IsIdle(XMath_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMath_accel_ReadReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMath_accel_IsReady(XMath_accel *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMath_accel_ReadReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMath_accel_EnableAutoRestart(XMath_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMath_accel_WriteReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_AP_CTRL, 0x80);
}

void XMath_accel_DisableAutoRestart(XMath_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMath_accel_WriteReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_AP_CTRL, 0);
}

void XMath_accel_InterruptGlobalEnable(XMath_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMath_accel_WriteReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_GIE, 1);
}

void XMath_accel_InterruptGlobalDisable(XMath_accel *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMath_accel_WriteReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_GIE, 0);
}

void XMath_accel_InterruptEnable(XMath_accel *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMath_accel_ReadReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_IER);
    XMath_accel_WriteReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_IER, Register | Mask);
}

void XMath_accel_InterruptDisable(XMath_accel *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMath_accel_ReadReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_IER);
    XMath_accel_WriteReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_IER, Register & (~Mask));
}

void XMath_accel_InterruptClear(XMath_accel *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMath_accel_WriteReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_ISR, Mask);
}

u32 XMath_accel_InterruptGetEnabled(XMath_accel *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMath_accel_ReadReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_IER);
}

u32 XMath_accel_InterruptGetStatus(XMath_accel *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMath_accel_ReadReg(InstancePtr->Control_intr_BaseAddress, XMATH_ACCEL_CONTROL_INTR_ADDR_ISR);
}

