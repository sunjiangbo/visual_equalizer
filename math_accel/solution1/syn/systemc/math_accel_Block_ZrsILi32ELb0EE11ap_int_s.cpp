// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.2
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "math_accel_Block_ZrsILi32ELb0EE11ap_int_s.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st1_fsm_0 = "1";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st2_fsm_1 = "10";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st3_fsm_2 = "100";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st4_fsm_3 = "1000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st5_fsm_4 = "10000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st6_fsm_5 = "100000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st7_fsm_6 = "1000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st8_fsm_7 = "10000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st9_fsm_8 = "100000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st10_fsm_9 = "1000000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st11_fsm_10 = "10000000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st12_fsm_11 = "100000000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st13_fsm_12 = "1000000000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st14_fsm_13 = "10000000000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st15_fsm_14 = "100000000000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st16_fsm_15 = "1000000000000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st17_fsm_16 = "10000000000000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st18_fsm_17 = "100000000000000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st19_fsm_18 = "1000000000000000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st20_fsm_19 = "10000000000000000000";
const sc_lv<21> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_ST_st21_fsm_20 = "100000000000000000000";
const sc_lv<32> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<1> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_const_lv1_1 = "1";
const sc_lv<32> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_const_lv32_3 = "11";
const sc_lv<32> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_const_lv32_1 = "1";
const sc_lv<32> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_const_lv32_4 = "100";
const sc_lv<32> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_const_lv32_10 = "10000";
const sc_lv<32> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_const_lv32_1F = "11111";
const sc_lv<32> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_const_lv32_14 = "10100";
const sc_lv<64> math_accel_Block_ZrsILi32ELb0EE11ap_int_s::ap_const_lv64_0 = "0000000000000000000000000000000000000000000000000000000000000000";

math_accel_Block_ZrsILi32ELb0EE11ap_int_s::math_accel_Block_ZrsILi32ELb0EE11ap_int_s(sc_module_name name) : sc_module(name), mVcdFile(0) {
    math_accel_uitodp_32s_64_3_U1 = new math_accel_uitodp_32s_64_3<1,3,32,64>("math_accel_uitodp_32s_64_3_U1");
    math_accel_uitodp_32s_64_3_U1->clk(ap_clk);
    math_accel_uitodp_32s_64_3_U1->reset(ap_rst);
    math_accel_uitodp_32s_64_3_U1->din0(squared_sum_reg_122);
    math_accel_uitodp_32s_64_3_U1->ce(ap_var_for_const0);
    math_accel_uitodp_32s_64_3_U1->dout(grp_fu_69_p1);
    math_accel_dsqrt_64ns_64ns_64_17_U2 = new math_accel_dsqrt_64ns_64ns_64_17<1,17,64,64,64>("math_accel_dsqrt_64ns_64ns_64_17_U2");
    math_accel_dsqrt_64ns_64ns_64_17_U2->clk(ap_clk);
    math_accel_dsqrt_64ns_64ns_64_17_U2->reset(ap_rst);
    math_accel_dsqrt_64ns_64ns_64_17_U2->din0(ap_var_for_const1);
    math_accel_dsqrt_64ns_64ns_64_17_U2->din1(tmp_3_i_reg_127);
    math_accel_dsqrt_64ns_64ns_64_17_U2->ce(ap_var_for_const0);
    math_accel_dsqrt_64ns_64ns_64_17_U2->dout(grp_fu_72_p2);
    math_accel_mac_muladd_16s_16s_32s_32_1_U3 = new math_accel_mac_muladd_16s_16s_32s_32_1<1,1,16,16,32,32>("math_accel_mac_muladd_16s_16s_32s_32_1_U3");
    math_accel_mac_muladd_16s_16s_32s_32_1_U3->din0(grp_fu_108_p0);
    math_accel_mac_muladd_16s_16s_32s_32_1_U3->din1(grp_fu_108_p1);
    math_accel_mac_muladd_16s_16s_32s_32_1_U3->din2(tmp_1_i_fu_115_p2);
    math_accel_mac_muladd_16s_16s_32s_32_1_U3->dout(grp_fu_108_p3);
    math_accel_mul_mul_16s_16s_32_1_U4 = new math_accel_mul_mul_16s_16s_32_1<1,1,16,16,32>("math_accel_mul_mul_16s_16s_32_1_U4");
    math_accel_mul_mul_16s_16s_32_1_U4->din0(tmp_1_i_fu_115_p0);
    math_accel_mul_mul_16s_16s_32_1_U4->din1(tmp_1_i_fu_115_p1);
    math_accel_mul_mul_16s_16s_32_1_U4->dout(tmp_1_i_fu_115_p2);

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_done_reg );
    sensitive << ( ap_sig_cseq_ST_st21_fsm_20 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_sig_cseq_ST_st21_fsm_20 );

    SC_METHOD(thread_ap_return);
    sensitive << ( grp_fu_72_p2 );
    sensitive << ( ap_sig_cseq_ST_st21_fsm_20 );

    SC_METHOD(thread_ap_sig_103);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_sig_111);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_sig_169);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_sig_39);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_sig_74);
    sensitive << ( ap_start );
    sensitive << ( ap_done_reg );
    sensitive << ( in_stream_TVALID );
    sensitive << ( tmp_last_V_2_out_out_full_n );

    SC_METHOD(thread_ap_sig_84);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_sig_cseq_ST_st1_fsm_0);
    sensitive << ( ap_sig_39 );

    SC_METHOD(thread_ap_sig_cseq_ST_st21_fsm_20);
    sensitive << ( ap_sig_169 );

    SC_METHOD(thread_ap_sig_cseq_ST_st2_fsm_1);
    sensitive << ( ap_sig_103 );

    SC_METHOD(thread_ap_sig_cseq_ST_st4_fsm_3);
    sensitive << ( ap_sig_84 );

    SC_METHOD(thread_ap_sig_cseq_ST_st5_fsm_4);
    sensitive << ( ap_sig_111 );

    SC_METHOD(thread_grp_fu_108_p0);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( img32_fu_104_p1 );

    SC_METHOD(thread_grp_fu_108_p1);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( img32_fu_104_p1 );

    SC_METHOD(thread_img32_fu_104_p1);
    sensitive << ( img_fu_94_p4 );

    SC_METHOD(thread_img_fu_94_p4);
    sensitive << ( in_stream_TDATA );

    SC_METHOD(thread_in_stream_TDATA_blk_n);
    sensitive << ( ap_start );
    sensitive << ( ap_done_reg );
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( in_stream_TVALID );

    SC_METHOD(thread_in_stream_TREADY);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( ap_sig_74 );

    SC_METHOD(thread_real32_fu_90_p1);
    sensitive << ( real_1_fu_86_p1 );

    SC_METHOD(thread_real_1_fu_86_p1);
    sensitive << ( in_stream_TDATA );

    SC_METHOD(thread_tmp_1_i_fu_115_p0);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( real32_fu_90_p1 );

    SC_METHOD(thread_tmp_1_i_fu_115_p1);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( real32_fu_90_p1 );

    SC_METHOD(thread_tmp_last_V_2_out_out_blk_n);
    sensitive << ( ap_start );
    sensitive << ( ap_done_reg );
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( tmp_last_V_2_out_out_full_n );

    SC_METHOD(thread_tmp_last_V_2_out_out_din);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( in_stream_TLAST );
    sensitive << ( ap_sig_74 );

    SC_METHOD(thread_tmp_last_V_2_out_out_write);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( ap_sig_74 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_sig_74 );

    SC_THREAD(thread_ap_var_for_const0);

    SC_THREAD(thread_ap_var_for_const1);

    ap_done_reg = SC_LOGIC_0;
    ap_CS_fsm = "000000000000000000001";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "math_accel_Block_ZrsILi32ELb0EE11ap_int_s_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT_HIER__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_continue, "(port)ap_continue");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, in_stream_TDATA, "(port)in_stream_TDATA");
    sc_trace(mVcdFile, in_stream_TVALID, "(port)in_stream_TVALID");
    sc_trace(mVcdFile, in_stream_TREADY, "(port)in_stream_TREADY");
    sc_trace(mVcdFile, in_stream_TKEEP, "(port)in_stream_TKEEP");
    sc_trace(mVcdFile, in_stream_TSTRB, "(port)in_stream_TSTRB");
    sc_trace(mVcdFile, in_stream_TUSER, "(port)in_stream_TUSER");
    sc_trace(mVcdFile, in_stream_TLAST, "(port)in_stream_TLAST");
    sc_trace(mVcdFile, in_stream_TID, "(port)in_stream_TID");
    sc_trace(mVcdFile, in_stream_TDEST, "(port)in_stream_TDEST");
    sc_trace(mVcdFile, tmp_last_V_2_out_out_din, "(port)tmp_last_V_2_out_out_din");
    sc_trace(mVcdFile, tmp_last_V_2_out_out_full_n, "(port)tmp_last_V_2_out_out_full_n");
    sc_trace(mVcdFile, tmp_last_V_2_out_out_write, "(port)tmp_last_V_2_out_out_write");
    sc_trace(mVcdFile, ap_return, "(port)ap_return");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_done_reg, "ap_done_reg");
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_sig_cseq_ST_st1_fsm_0, "ap_sig_cseq_ST_st1_fsm_0");
    sc_trace(mVcdFile, ap_sig_39, "ap_sig_39");
    sc_trace(mVcdFile, in_stream_TDATA_blk_n, "in_stream_TDATA_blk_n");
    sc_trace(mVcdFile, tmp_last_V_2_out_out_blk_n, "tmp_last_V_2_out_out_blk_n");
    sc_trace(mVcdFile, grp_fu_108_p3, "grp_fu_108_p3");
    sc_trace(mVcdFile, squared_sum_reg_122, "squared_sum_reg_122");
    sc_trace(mVcdFile, ap_sig_74, "ap_sig_74");
    sc_trace(mVcdFile, grp_fu_69_p1, "grp_fu_69_p1");
    sc_trace(mVcdFile, tmp_3_i_reg_127, "tmp_3_i_reg_127");
    sc_trace(mVcdFile, ap_sig_cseq_ST_st4_fsm_3, "ap_sig_cseq_ST_st4_fsm_3");
    sc_trace(mVcdFile, ap_sig_84, "ap_sig_84");
    sc_trace(mVcdFile, ap_sig_cseq_ST_st2_fsm_1, "ap_sig_cseq_ST_st2_fsm_1");
    sc_trace(mVcdFile, ap_sig_103, "ap_sig_103");
    sc_trace(mVcdFile, ap_sig_cseq_ST_st5_fsm_4, "ap_sig_cseq_ST_st5_fsm_4");
    sc_trace(mVcdFile, ap_sig_111, "ap_sig_111");
    sc_trace(mVcdFile, real_1_fu_86_p1, "real_1_fu_86_p1");
    sc_trace(mVcdFile, img_fu_94_p4, "img_fu_94_p4");
    sc_trace(mVcdFile, grp_fu_108_p0, "grp_fu_108_p0");
    sc_trace(mVcdFile, img32_fu_104_p1, "img32_fu_104_p1");
    sc_trace(mVcdFile, grp_fu_108_p1, "grp_fu_108_p1");
    sc_trace(mVcdFile, tmp_1_i_fu_115_p2, "tmp_1_i_fu_115_p2");
    sc_trace(mVcdFile, tmp_1_i_fu_115_p0, "tmp_1_i_fu_115_p0");
    sc_trace(mVcdFile, real32_fu_90_p1, "real32_fu_90_p1");
    sc_trace(mVcdFile, tmp_1_i_fu_115_p1, "tmp_1_i_fu_115_p1");
    sc_trace(mVcdFile, grp_fu_72_p2, "grp_fu_72_p2");
    sc_trace(mVcdFile, ap_sig_cseq_ST_st21_fsm_20, "ap_sig_cseq_ST_st21_fsm_20");
    sc_trace(mVcdFile, ap_sig_169, "ap_sig_169");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
}

math_accel_Block_ZrsILi32ELb0EE11ap_int_s::~math_accel_Block_ZrsILi32ELb0EE11ap_int_s() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    delete math_accel_uitodp_32s_64_3_U1;
    delete math_accel_dsqrt_64ns_64ns_64_17_U2;
    delete math_accel_mac_muladd_16s_16s_32s_32_1_U3;
    delete math_accel_mul_mul_16s_16s_32_1_U4;
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_var_for_const0() {
    ap_var_for_const0 = ap_const_logic_1;
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_var_for_const1() {
    ap_var_for_const1 = ap_const_lv64_0;
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_st1_fsm_0;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_done_reg = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_const_logic_1, ap_continue.read())) {
            ap_done_reg = ap_const_logic_0;
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st21_fsm_20.read())) {
            ap_done_reg = ap_const_logic_1;
        }
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && !ap_sig_74.read())) {
        squared_sum_reg_122 = grp_fu_108_p3.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st4_fsm_3.read())) {
        tmp_3_i_reg_127 = grp_fu_69_p1.read();
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_done() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_done_reg.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st21_fsm_20.read()))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_ready() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st21_fsm_20.read())) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_return() {
    ap_return = grp_fu_72_p2.read();
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_sig_103() {
    ap_sig_103 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(1, 1));
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_sig_111() {
    ap_sig_111 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(4, 4));
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_sig_169() {
    ap_sig_169 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(20, 20));
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_sig_39() {
    ap_sig_39 = esl_seteq<1,1,1>(ap_CS_fsm.read().range(0, 0), ap_const_lv1_1);
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_sig_74() {
    ap_sig_74 = (esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1) || esl_seteq<1,1,1>(in_stream_TVALID.read(), ap_const_logic_0) || esl_seteq<1,1,1>(tmp_last_V_2_out_out_full_n.read(), ap_const_logic_0));
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_sig_84() {
    ap_sig_84 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(3, 3));
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_sig_cseq_ST_st1_fsm_0() {
    if (ap_sig_39.read()) {
        ap_sig_cseq_ST_st1_fsm_0 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st1_fsm_0 = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_sig_cseq_ST_st21_fsm_20() {
    if (ap_sig_169.read()) {
        ap_sig_cseq_ST_st21_fsm_20 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st21_fsm_20 = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_sig_cseq_ST_st2_fsm_1() {
    if (ap_sig_103.read()) {
        ap_sig_cseq_ST_st2_fsm_1 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st2_fsm_1 = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_sig_cseq_ST_st4_fsm_3() {
    if (ap_sig_84.read()) {
        ap_sig_cseq_ST_st4_fsm_3 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st4_fsm_3 = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_sig_cseq_ST_st5_fsm_4() {
    if (ap_sig_111.read()) {
        ap_sig_cseq_ST_st5_fsm_4 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st5_fsm_4 = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_grp_fu_108_p0() {
    grp_fu_108_p0 =  (sc_lv<16>) (img32_fu_104_p1.read());
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_grp_fu_108_p1() {
    grp_fu_108_p1 =  (sc_lv<16>) (img32_fu_104_p1.read());
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_img32_fu_104_p1() {
    img32_fu_104_p1 = esl_sext<32,16>(img_fu_94_p4.read());
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_img_fu_94_p4() {
    img_fu_94_p4 = in_stream_TDATA.read().range(31, 16);
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_in_stream_TDATA_blk_n() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
         !(esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1)))) {
        in_stream_TDATA_blk_n = in_stream_TVALID.read();
    } else {
        in_stream_TDATA_blk_n = ap_const_logic_1;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_in_stream_TREADY() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
          !ap_sig_74.read()))) {
        in_stream_TREADY = ap_const_logic_1;
    } else {
        in_stream_TREADY = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_real32_fu_90_p1() {
    real32_fu_90_p1 = esl_sext<32,16>(real_1_fu_86_p1.read());
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_real_1_fu_86_p1() {
    real_1_fu_86_p1 = in_stream_TDATA.read().range(16-1, 0);
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_tmp_1_i_fu_115_p0() {
    tmp_1_i_fu_115_p0 =  (sc_lv<16>) (real32_fu_90_p1.read());
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_tmp_1_i_fu_115_p1() {
    tmp_1_i_fu_115_p1 =  (sc_lv<16>) (real32_fu_90_p1.read());
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_tmp_last_V_2_out_out_blk_n() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
         !(esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1)))) {
        tmp_last_V_2_out_out_blk_n = tmp_last_V_2_out_out_full_n.read();
    } else {
        tmp_last_V_2_out_out_blk_n = ap_const_logic_1;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_tmp_last_V_2_out_out_din() {
    tmp_last_V_2_out_out_din = in_stream_TLAST.read();
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_tmp_last_V_2_out_out_write() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
         !ap_sig_74.read())) {
        tmp_last_V_2_out_out_write = ap_const_logic_1;
    } else {
        tmp_last_V_2_out_out_write = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_s::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if (!ap_sig_74.read()) {
                ap_NS_fsm = ap_ST_st2_fsm_1;
            } else {
                ap_NS_fsm = ap_ST_st1_fsm_0;
            }
            break;
        case 2 : 
            ap_NS_fsm = ap_ST_st3_fsm_2;
            break;
        case 4 : 
            ap_NS_fsm = ap_ST_st4_fsm_3;
            break;
        case 8 : 
            ap_NS_fsm = ap_ST_st5_fsm_4;
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_st6_fsm_5;
            break;
        case 32 : 
            ap_NS_fsm = ap_ST_st7_fsm_6;
            break;
        case 64 : 
            ap_NS_fsm = ap_ST_st8_fsm_7;
            break;
        case 128 : 
            ap_NS_fsm = ap_ST_st9_fsm_8;
            break;
        case 256 : 
            ap_NS_fsm = ap_ST_st10_fsm_9;
            break;
        case 512 : 
            ap_NS_fsm = ap_ST_st11_fsm_10;
            break;
        case 1024 : 
            ap_NS_fsm = ap_ST_st12_fsm_11;
            break;
        case 2048 : 
            ap_NS_fsm = ap_ST_st13_fsm_12;
            break;
        case 4096 : 
            ap_NS_fsm = ap_ST_st14_fsm_13;
            break;
        case 8192 : 
            ap_NS_fsm = ap_ST_st15_fsm_14;
            break;
        case 16384 : 
            ap_NS_fsm = ap_ST_st16_fsm_15;
            break;
        case 32768 : 
            ap_NS_fsm = ap_ST_st17_fsm_16;
            break;
        case 65536 : 
            ap_NS_fsm = ap_ST_st18_fsm_17;
            break;
        case 131072 : 
            ap_NS_fsm = ap_ST_st19_fsm_18;
            break;
        case 262144 : 
            ap_NS_fsm = ap_ST_st20_fsm_19;
            break;
        case 524288 : 
            ap_NS_fsm = ap_ST_st21_fsm_20;
            break;
        case 1048576 : 
            ap_NS_fsm = ap_ST_st1_fsm_0;
            break;
        default : 
            ap_NS_fsm = "XXXXXXXXXXXXXXXXXXXXX";
            break;
    }
}

}

