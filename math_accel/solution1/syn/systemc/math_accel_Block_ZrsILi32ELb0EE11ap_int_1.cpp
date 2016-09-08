// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.2
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "math_accel_Block_ZrsILi32ELb0EE11ap_int_1.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic math_accel_Block_ZrsILi32ELb0EE11ap_int_1::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic math_accel_Block_ZrsILi32ELb0EE11ap_int_1::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<1> math_accel_Block_ZrsILi32ELb0EE11ap_int_1::ap_ST_st1_fsm_0 = "1";
const sc_lv<32> math_accel_Block_ZrsILi32ELb0EE11ap_int_1::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<1> math_accel_Block_ZrsILi32ELb0EE11ap_int_1::ap_const_lv1_1 = "1";
const sc_lv<4> math_accel_Block_ZrsILi32ELb0EE11ap_int_1::ap_const_lv4_F = "1111";
const sc_lv<4> math_accel_Block_ZrsILi32ELb0EE11ap_int_1::ap_const_lv4_0 = "0000";
const sc_lv<1> math_accel_Block_ZrsILi32ELb0EE11ap_int_1::ap_const_lv1_0 = "0";

math_accel_Block_ZrsILi32ELb0EE11ap_int_1::math_accel_Block_ZrsILi32ELb0EE11ap_int_1(sc_module_name name) : sc_module(name), mVcdFile(0) {

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_done_reg );
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( ap_sig_48 );
    sensitive << ( ap_sig_ioackin_out_stream_TREADY );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( ap_sig_48 );
    sensitive << ( ap_sig_ioackin_out_stream_TREADY );

    SC_METHOD(thread_ap_sig_19);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_sig_48);
    sensitive << ( ap_start );
    sensitive << ( ap_done_reg );
    sensitive << ( tmp_last_V_2_reload_empty_n );

    SC_METHOD(thread_ap_sig_cseq_ST_st1_fsm_0);
    sensitive << ( ap_sig_19 );

    SC_METHOD(thread_ap_sig_ioackin_out_stream_TREADY);
    sensitive << ( out_stream_TREADY );
    sensitive << ( ap_reg_ioackin_out_stream_TREADY );

    SC_METHOD(thread_out_stream_TDATA);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( sqrt_res );
    sensitive << ( ap_sig_48 );

    SC_METHOD(thread_out_stream_TDATA_blk_n);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( out_stream_TREADY );

    SC_METHOD(thread_out_stream_TDEST);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( ap_sig_48 );

    SC_METHOD(thread_out_stream_TID);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( ap_sig_48 );

    SC_METHOD(thread_out_stream_TKEEP);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( ap_sig_48 );

    SC_METHOD(thread_out_stream_TLAST);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( tmp_last_V_2_reload_dout );
    sensitive << ( ap_sig_48 );

    SC_METHOD(thread_out_stream_TSTRB);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( ap_sig_48 );

    SC_METHOD(thread_out_stream_TUSER);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( ap_sig_48 );

    SC_METHOD(thread_out_stream_TVALID);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( ap_sig_48 );
    sensitive << ( ap_reg_ioackin_out_stream_TREADY );

    SC_METHOD(thread_tmp_last_V_2_reload_blk_n);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( tmp_last_V_2_reload_empty_n );

    SC_METHOD(thread_tmp_last_V_2_reload_read);
    sensitive << ( ap_sig_cseq_ST_st1_fsm_0 );
    sensitive << ( ap_sig_48 );
    sensitive << ( ap_sig_ioackin_out_stream_TREADY );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_sig_48 );
    sensitive << ( ap_sig_ioackin_out_stream_TREADY );

    ap_done_reg = SC_LOGIC_0;
    ap_CS_fsm = "1";
    ap_reg_ioackin_out_stream_TREADY = SC_LOGIC_0;
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "math_accel_Block_ZrsILi32ELb0EE11ap_int_1_sc_trace_" << apTFileNum ++;
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
    sc_trace(mVcdFile, sqrt_res, "(port)sqrt_res");
    sc_trace(mVcdFile, tmp_last_V_2_reload_dout, "(port)tmp_last_V_2_reload_dout");
    sc_trace(mVcdFile, tmp_last_V_2_reload_empty_n, "(port)tmp_last_V_2_reload_empty_n");
    sc_trace(mVcdFile, tmp_last_V_2_reload_read, "(port)tmp_last_V_2_reload_read");
    sc_trace(mVcdFile, out_stream_TDATA, "(port)out_stream_TDATA");
    sc_trace(mVcdFile, out_stream_TVALID, "(port)out_stream_TVALID");
    sc_trace(mVcdFile, out_stream_TREADY, "(port)out_stream_TREADY");
    sc_trace(mVcdFile, out_stream_TKEEP, "(port)out_stream_TKEEP");
    sc_trace(mVcdFile, out_stream_TSTRB, "(port)out_stream_TSTRB");
    sc_trace(mVcdFile, out_stream_TUSER, "(port)out_stream_TUSER");
    sc_trace(mVcdFile, out_stream_TLAST, "(port)out_stream_TLAST");
    sc_trace(mVcdFile, out_stream_TID, "(port)out_stream_TID");
    sc_trace(mVcdFile, out_stream_TDEST, "(port)out_stream_TDEST");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_done_reg, "ap_done_reg");
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_sig_cseq_ST_st1_fsm_0, "ap_sig_cseq_ST_st1_fsm_0");
    sc_trace(mVcdFile, ap_sig_19, "ap_sig_19");
    sc_trace(mVcdFile, tmp_last_V_2_reload_blk_n, "tmp_last_V_2_reload_blk_n");
    sc_trace(mVcdFile, out_stream_TDATA_blk_n, "out_stream_TDATA_blk_n");
    sc_trace(mVcdFile, ap_sig_48, "ap_sig_48");
    sc_trace(mVcdFile, ap_sig_ioackin_out_stream_TREADY, "ap_sig_ioackin_out_stream_TREADY");
    sc_trace(mVcdFile, ap_reg_ioackin_out_stream_TREADY, "ap_reg_ioackin_out_stream_TREADY");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
}

math_accel_Block_ZrsILi32ELb0EE11ap_int_1::~math_accel_Block_ZrsILi32ELb0EE11ap_int_1() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_ap_clk_no_reset_() {
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
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                    !(ap_sig_48.read() || esl_seteq<1,1,1>(ap_const_logic_0, ap_sig_ioackin_out_stream_TREADY.read())))) {
            ap_done_reg = ap_const_logic_1;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_reg_ioackin_out_stream_TREADY = ap_const_logic_0;
    } else {
        if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
              !(ap_sig_48.read() || esl_seteq<1,1,1>(ap_const_logic_0, ap_sig_ioackin_out_stream_TREADY.read()))))) {
            ap_reg_ioackin_out_stream_TREADY = ap_const_logic_0;
        } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
                     !ap_sig_48.read() && 
                     esl_seteq<1,1,1>(ap_const_logic_1, out_stream_TREADY.read())))) {
            ap_reg_ioackin_out_stream_TREADY = ap_const_logic_1;
        }
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_ap_done() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_done_reg.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
          !(ap_sig_48.read() || esl_seteq<1,1,1>(ap_const_logic_0, ap_sig_ioackin_out_stream_TREADY.read()))))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
         !(ap_sig_48.read() || esl_seteq<1,1,1>(ap_const_logic_0, ap_sig_ioackin_out_stream_TREADY.read())))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_ap_sig_19() {
    ap_sig_19 = esl_seteq<1,1,1>(ap_CS_fsm.read().range(0, 0), ap_const_lv1_1);
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_ap_sig_48() {
    ap_sig_48 = (esl_seteq<1,1,1>(tmp_last_V_2_reload_empty_n.read(), ap_const_logic_0) || esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_0) || esl_seteq<1,1,1>(ap_done_reg.read(), ap_const_logic_1));
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_ap_sig_cseq_ST_st1_fsm_0() {
    if (ap_sig_19.read()) {
        ap_sig_cseq_ST_st1_fsm_0 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st1_fsm_0 = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_ap_sig_ioackin_out_stream_TREADY() {
    if (esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_out_stream_TREADY.read())) {
        ap_sig_ioackin_out_stream_TREADY = out_stream_TREADY.read();
    } else {
        ap_sig_ioackin_out_stream_TREADY = ap_const_logic_1;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_out_stream_TDATA() {
    out_stream_TDATA = sqrt_res.read();
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_out_stream_TDATA_blk_n() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read())) {
        out_stream_TDATA_blk_n = out_stream_TREADY.read();
    } else {
        out_stream_TDATA_blk_n = ap_const_logic_1;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_out_stream_TDEST() {
    out_stream_TDEST = ap_const_lv1_0;
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_out_stream_TID() {
    out_stream_TID = ap_const_lv1_0;
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_out_stream_TKEEP() {
    out_stream_TKEEP = ap_const_lv4_F;
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_out_stream_TLAST() {
    out_stream_TLAST = tmp_last_V_2_reload_dout.read();
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_out_stream_TSTRB() {
    out_stream_TSTRB = ap_const_lv4_0;
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_out_stream_TUSER() {
    out_stream_TUSER = ap_const_lv1_0;
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_out_stream_TVALID() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
          !ap_sig_48.read() && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_out_stream_TREADY.read())))) {
        out_stream_TVALID = ap_const_logic_1;
    } else {
        out_stream_TVALID = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_tmp_last_V_2_reload_blk_n() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read())) {
        tmp_last_V_2_reload_blk_n = tmp_last_V_2_reload_empty_n.read();
    } else {
        tmp_last_V_2_reload_blk_n = ap_const_logic_1;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_tmp_last_V_2_reload_read() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()) && 
         !(ap_sig_48.read() || esl_seteq<1,1,1>(ap_const_logic_0, ap_sig_ioackin_out_stream_TREADY.read())))) {
        tmp_last_V_2_reload_read = ap_const_logic_1;
    } else {
        tmp_last_V_2_reload_read = ap_const_logic_0;
    }
}

void math_accel_Block_ZrsILi32ELb0EE11ap_int_1::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            ap_NS_fsm = ap_ST_st1_fsm_0;
break;
        default : 
            ap_NS_fsm = "X";
            break;
    }
}

}
