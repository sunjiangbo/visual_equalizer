-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2016.2
-- Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity math_accel_Block_ZrsILi32ELb0EE11ap_int_1 is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_continue : IN STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    sqrt_res : IN STD_LOGIC_VECTOR (31 downto 0);
    tmp_last_V_2_reload_dout : IN STD_LOGIC_VECTOR (0 downto 0);
    tmp_last_V_2_reload_empty_n : IN STD_LOGIC;
    tmp_last_V_2_reload_read : OUT STD_LOGIC;
    out_stream_TDATA : OUT STD_LOGIC_VECTOR (31 downto 0);
    out_stream_TVALID : OUT STD_LOGIC;
    out_stream_TREADY : IN STD_LOGIC;
    out_stream_TKEEP : OUT STD_LOGIC_VECTOR (3 downto 0);
    out_stream_TSTRB : OUT STD_LOGIC_VECTOR (3 downto 0);
    out_stream_TUSER : OUT STD_LOGIC_VECTOR (0 downto 0);
    out_stream_TLAST : OUT STD_LOGIC_VECTOR (0 downto 0);
    out_stream_TID : OUT STD_LOGIC_VECTOR (0 downto 0);
    out_stream_TDEST : OUT STD_LOGIC_VECTOR (0 downto 0) );
end;


architecture behav of math_accel_Block_ZrsILi32ELb0EE11ap_int_1 is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_st1_fsm_0 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv4_F : STD_LOGIC_VECTOR (3 downto 0) := "1111";
    constant ap_const_lv4_0 : STD_LOGIC_VECTOR (3 downto 0) := "0000";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";

    signal ap_done_reg : STD_LOGIC := '0';
    signal ap_CS_fsm : STD_LOGIC_VECTOR (0 downto 0) := "1";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_sig_cseq_ST_st1_fsm_0 : STD_LOGIC;
    signal ap_sig_19 : BOOLEAN;
    signal tmp_last_V_2_reload_blk_n : STD_LOGIC;
    signal out_stream_TDATA_blk_n : STD_LOGIC;
    signal ap_sig_48 : BOOLEAN;
    signal ap_sig_ioackin_out_stream_TREADY : STD_LOGIC;
    signal ap_reg_ioackin_out_stream_TREADY : STD_LOGIC := '0';
    signal ap_NS_fsm : STD_LOGIC_VECTOR (0 downto 0);


begin




    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_st1_fsm_0;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    ap_done_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_done_reg <= ap_const_logic_0;
            else
                if ((ap_const_logic_1 = ap_continue)) then 
                    ap_done_reg <= ap_const_logic_0;
                elsif (((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_sig_48 or (ap_const_logic_0 = ap_sig_ioackin_out_stream_TREADY))))) then 
                    ap_done_reg <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    ap_reg_ioackin_out_stream_TREADY_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_reg_ioackin_out_stream_TREADY <= ap_const_logic_0;
            else
                if ((((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_sig_48 or (ap_const_logic_0 = ap_sig_ioackin_out_stream_TREADY)))))) then 
                    ap_reg_ioackin_out_stream_TREADY <= ap_const_logic_0;
                elsif ((((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not(ap_sig_48) and (ap_const_logic_1 = out_stream_TREADY)))) then 
                    ap_reg_ioackin_out_stream_TREADY <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    ap_NS_fsm_assign_proc : process (ap_CS_fsm, ap_sig_48, ap_sig_ioackin_out_stream_TREADY)
    begin
        case ap_CS_fsm is
            when ap_ST_st1_fsm_0 => 
                ap_NS_fsm <= ap_ST_st1_fsm_0;
            when others =>  
                ap_NS_fsm <= "X";
        end case;
    end process;

    ap_done_assign_proc : process(ap_done_reg, ap_sig_cseq_ST_st1_fsm_0, ap_sig_48, ap_sig_ioackin_out_stream_TREADY)
    begin
        if (((ap_const_logic_1 = ap_done_reg) or ((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_sig_48 or (ap_const_logic_0 = ap_sig_ioackin_out_stream_TREADY)))))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_sig_cseq_ST_st1_fsm_0)
    begin
        if (((ap_const_logic_0 = ap_start) and (ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(ap_sig_cseq_ST_st1_fsm_0, ap_sig_48, ap_sig_ioackin_out_stream_TREADY)
    begin
        if (((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_sig_48 or (ap_const_logic_0 = ap_sig_ioackin_out_stream_TREADY))))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;


    ap_sig_19_assign_proc : process(ap_CS_fsm)
    begin
                ap_sig_19 <= (ap_CS_fsm(0 downto 0) = ap_const_lv1_1);
    end process;


    ap_sig_48_assign_proc : process(ap_start, ap_done_reg, tmp_last_V_2_reload_empty_n)
    begin
                ap_sig_48 <= ((tmp_last_V_2_reload_empty_n = ap_const_logic_0) or (ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1));
    end process;


    ap_sig_cseq_ST_st1_fsm_0_assign_proc : process(ap_sig_19)
    begin
        if (ap_sig_19) then 
            ap_sig_cseq_ST_st1_fsm_0 <= ap_const_logic_1;
        else 
            ap_sig_cseq_ST_st1_fsm_0 <= ap_const_logic_0;
        end if; 
    end process;


    ap_sig_ioackin_out_stream_TREADY_assign_proc : process(out_stream_TREADY, ap_reg_ioackin_out_stream_TREADY)
    begin
        if ((ap_const_logic_0 = ap_reg_ioackin_out_stream_TREADY)) then 
            ap_sig_ioackin_out_stream_TREADY <= out_stream_TREADY;
        else 
            ap_sig_ioackin_out_stream_TREADY <= ap_const_logic_1;
        end if; 
    end process;

    out_stream_TDATA <= sqrt_res;

    out_stream_TDATA_blk_n_assign_proc : process(ap_sig_cseq_ST_st1_fsm_0, out_stream_TREADY)
    begin
        if ((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0)) then 
            out_stream_TDATA_blk_n <= out_stream_TREADY;
        else 
            out_stream_TDATA_blk_n <= ap_const_logic_1;
        end if; 
    end process;

    out_stream_TDEST <= ap_const_lv1_0;
    out_stream_TID <= ap_const_lv1_0;
    out_stream_TKEEP <= ap_const_lv4_F;
    out_stream_TLAST <= tmp_last_V_2_reload_dout;
    out_stream_TSTRB <= ap_const_lv4_0;
    out_stream_TUSER <= ap_const_lv1_0;

    out_stream_TVALID_assign_proc : process(ap_sig_cseq_ST_st1_fsm_0, ap_sig_48, ap_reg_ioackin_out_stream_TREADY)
    begin
        if ((((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not(ap_sig_48) and (ap_const_logic_0 = ap_reg_ioackin_out_stream_TREADY)))) then 
            out_stream_TVALID <= ap_const_logic_1;
        else 
            out_stream_TVALID <= ap_const_logic_0;
        end if; 
    end process;


    tmp_last_V_2_reload_blk_n_assign_proc : process(ap_sig_cseq_ST_st1_fsm_0, tmp_last_V_2_reload_empty_n)
    begin
        if ((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0)) then 
            tmp_last_V_2_reload_blk_n <= tmp_last_V_2_reload_empty_n;
        else 
            tmp_last_V_2_reload_blk_n <= ap_const_logic_1;
        end if; 
    end process;


    tmp_last_V_2_reload_read_assign_proc : process(ap_sig_cseq_ST_st1_fsm_0, ap_sig_48, ap_sig_ioackin_out_stream_TREADY)
    begin
        if (((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_sig_48 or (ap_const_logic_0 = ap_sig_ioackin_out_stream_TREADY))))) then 
            tmp_last_V_2_reload_read <= ap_const_logic_1;
        else 
            tmp_last_V_2_reload_read <= ap_const_logic_0;
        end if; 
    end process;

end behav;
