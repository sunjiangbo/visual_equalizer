// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.2
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _math_accel_Block_ZrsILi32ELb0EE11ap_int_1_HH_
#define _math_accel_Block_ZrsILi32ELb0EE11ap_int_1_HH_

#include "systemc.h"
#include "AESL_pkg.h"


namespace ap_rtl {

struct math_accel_Block_ZrsILi32ELb0EE11ap_int_1 : public sc_module {
    // Port declarations 20
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_in< sc_logic > ap_continue;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_in< sc_lv<32> > sqrt_res;
    sc_in< sc_lv<1> > tmp_last_V_2_reload_dout;
    sc_in< sc_logic > tmp_last_V_2_reload_empty_n;
    sc_out< sc_logic > tmp_last_V_2_reload_read;
    sc_out< sc_lv<32> > out_stream_TDATA;
    sc_out< sc_logic > out_stream_TVALID;
    sc_in< sc_logic > out_stream_TREADY;
    sc_out< sc_lv<4> > out_stream_TKEEP;
    sc_out< sc_lv<4> > out_stream_TSTRB;
    sc_out< sc_lv<1> > out_stream_TUSER;
    sc_out< sc_lv<1> > out_stream_TLAST;
    sc_out< sc_lv<1> > out_stream_TID;
    sc_out< sc_lv<1> > out_stream_TDEST;


    // Module declarations
    math_accel_Block_ZrsILi32ELb0EE11ap_int_1(sc_module_name name);
    SC_HAS_PROCESS(math_accel_Block_ZrsILi32ELb0EE11ap_int_1);

    ~math_accel_Block_ZrsILi32ELb0EE11ap_int_1();

    sc_trace_file* mVcdFile;

    sc_signal< sc_logic > ap_done_reg;
    sc_signal< sc_lv<1> > ap_CS_fsm;
    sc_signal< sc_logic > ap_sig_cseq_ST_st1_fsm_0;
    sc_signal< bool > ap_sig_19;
    sc_signal< sc_logic > tmp_last_V_2_reload_blk_n;
    sc_signal< sc_logic > out_stream_TDATA_blk_n;
    sc_signal< bool > ap_sig_48;
    sc_signal< sc_logic > ap_sig_ioackin_out_stream_TREADY;
    sc_signal< sc_logic > ap_reg_ioackin_out_stream_TREADY;
    sc_signal< sc_lv<1> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<1> ap_ST_st1_fsm_0;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<4> ap_const_lv4_F;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<1> ap_const_lv1_0;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_ap_sig_19();
    void thread_ap_sig_48();
    void thread_ap_sig_cseq_ST_st1_fsm_0();
    void thread_ap_sig_ioackin_out_stream_TREADY();
    void thread_out_stream_TDATA();
    void thread_out_stream_TDATA_blk_n();
    void thread_out_stream_TDEST();
    void thread_out_stream_TID();
    void thread_out_stream_TKEEP();
    void thread_out_stream_TLAST();
    void thread_out_stream_TSTRB();
    void thread_out_stream_TUSER();
    void thread_out_stream_TVALID();
    void thread_tmp_last_V_2_reload_blk_n();
    void thread_tmp_last_V_2_reload_read();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
