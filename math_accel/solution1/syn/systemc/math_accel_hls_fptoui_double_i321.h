// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.2
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _math_accel_hls_fptoui_double_i321_HH_
#define _math_accel_hls_fptoui_double_i321_HH_

#include "systemc.h"
#include "AESL_pkg.h"


namespace ap_rtl {

struct math_accel_hls_fptoui_double_i321 : public sc_module {
    // Port declarations 10
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_in< sc_logic > ap_continue;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<32> > return_r;
    sc_out< sc_logic > return_r_ap_vld;
    sc_in< sc_lv<64> > p_read;


    // Module declarations
    math_accel_hls_fptoui_double_i321(sc_module_name name);
    SC_HAS_PROCESS(math_accel_hls_fptoui_double_i321);

    ~math_accel_hls_fptoui_double_i321();

    sc_trace_file* mVcdFile;

    sc_signal< sc_logic > ap_done_reg;
    sc_signal< sc_lv<1> > ap_CS_fsm;
    sc_signal< sc_logic > ap_sig_cseq_ST_st1_fsm_0;
    sc_signal< bool > ap_sig_19;
    sc_signal< bool > ap_sig_33;
    sc_signal< sc_lv<32> > result_V_fu_157_p3;
    sc_signal< sc_lv<32> > return_r_preg;
    sc_signal< sc_lv<64> > p_Val2_s_fu_45_p1;
    sc_signal< sc_lv<52> > loc_V_1_fu_59_p1;
    sc_signal< sc_lv<53> > p_Result_s_fu_63_p3;
    sc_signal< sc_lv<11> > loc_V_fu_49_p4;
    sc_signal< sc_lv<12> > tmp_i_i_cast_fu_75_p1;
    sc_signal< sc_lv<12> > sh_assign_fu_79_p2;
    sc_signal< sc_lv<11> > tmp_8_i_fu_93_p2;
    sc_signal< sc_lv<1> > isNeg_fu_85_p3;
    sc_signal< sc_lv<12> > tmp_8_i_cast_fu_99_p1;
    sc_signal< sc_lv<12> > sh_assign_1_fu_103_p3;
    sc_signal< sc_lv<32> > sh_assign_1_i_cast_fu_111_p1;
    sc_signal< sc_lv<53> > tmp_i_cast_27_fu_115_p1;
    sc_signal< sc_lv<84> > tmp_i_cast_fu_71_p1;
    sc_signal< sc_lv<84> > tmp_2_i_cast_fu_125_p1;
    sc_signal< sc_lv<53> > tmp_1_i_fu_119_p2;
    sc_signal< sc_lv<1> > tmp_fu_135_p3;
    sc_signal< sc_lv<84> > tmp_3_i_fu_129_p2;
    sc_signal< sc_lv<32> > tmp_1_fu_143_p1;
    sc_signal< sc_lv<32> > tmp_2_fu_147_p4;
    sc_signal< sc_lv<1> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<1> ap_ST_st1_fsm_0;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_34;
    static const sc_lv<32> ap_const_lv32_3E;
    static const sc_lv<12> ap_const_lv12_C01;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<11> ap_const_lv11_3FF;
    static const sc_lv<32> ap_const_lv32_53;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_ap_sig_19();
    void thread_ap_sig_33();
    void thread_ap_sig_cseq_ST_st1_fsm_0();
    void thread_isNeg_fu_85_p3();
    void thread_loc_V_1_fu_59_p1();
    void thread_loc_V_fu_49_p4();
    void thread_p_Result_s_fu_63_p3();
    void thread_p_Val2_s_fu_45_p1();
    void thread_result_V_fu_157_p3();
    void thread_return_r();
    void thread_return_r_ap_vld();
    void thread_sh_assign_1_fu_103_p3();
    void thread_sh_assign_1_i_cast_fu_111_p1();
    void thread_sh_assign_fu_79_p2();
    void thread_tmp_1_fu_143_p1();
    void thread_tmp_1_i_fu_119_p2();
    void thread_tmp_2_fu_147_p4();
    void thread_tmp_2_i_cast_fu_125_p1();
    void thread_tmp_3_i_fu_129_p2();
    void thread_tmp_8_i_cast_fu_99_p1();
    void thread_tmp_8_i_fu_93_p2();
    void thread_tmp_fu_135_p3();
    void thread_tmp_i_cast_27_fu_115_p1();
    void thread_tmp_i_cast_fu_71_p1();
    void thread_tmp_i_i_cast_fu_75_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
