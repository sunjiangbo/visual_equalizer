-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2016.2
-- Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity math_accel_Block_proc18 is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_continue : IN STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    log10_res : IN STD_LOGIC_VECTOR (31 downto 0);
    out_data_TDATA : OUT STD_LOGIC_VECTOR (31 downto 0);
    out_data_TVALID : OUT STD_LOGIC;
    out_data_TREADY : IN STD_LOGIC );
end;


architecture behav of math_accel_Block_proc18 is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_st1_fsm_0 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";

    signal ap_done_reg : STD_LOGIC := '0';
    signal ap_CS_fsm : STD_LOGIC_VECTOR (0 downto 0) := "1";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_sig_cseq_ST_st1_fsm_0 : STD_LOGIC;
    signal ap_sig_19 : BOOLEAN;
    signal out_data_TDATA_blk_n : STD_LOGIC;
    signal ap_sig_35 : BOOLEAN;
    signal ap_sig_ioackin_out_data_TREADY : STD_LOGIC;
    signal ap_reg_ioackin_out_data_TREADY : STD_LOGIC := '0';
    signal ap_NS_fsm : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_sig_61 : BOOLEAN;


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
                elsif (((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_sig_35 or (ap_const_logic_0 = ap_sig_ioackin_out_data_TREADY))))) then 
                    ap_done_reg <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    ap_reg_ioackin_out_data_TREADY_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_reg_ioackin_out_data_TREADY <= ap_const_logic_0;
            else
                if ((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0)) then
                    if (not((ap_sig_35 or (ap_const_logic_0 = ap_sig_ioackin_out_data_TREADY)))) then 
                        ap_reg_ioackin_out_data_TREADY <= ap_const_logic_0;
                    elsif (ap_sig_61) then 
                        ap_reg_ioackin_out_data_TREADY <= ap_const_logic_1;
                    end if;
                end if; 
            end if;
        end if;
    end process;


    ap_NS_fsm_assign_proc : process (ap_CS_fsm, ap_sig_35, ap_sig_ioackin_out_data_TREADY)
    begin
        case ap_CS_fsm is
            when ap_ST_st1_fsm_0 => 
                ap_NS_fsm <= ap_ST_st1_fsm_0;
            when others =>  
                ap_NS_fsm <= "X";
        end case;
    end process;

    ap_done_assign_proc : process(ap_done_reg, ap_sig_cseq_ST_st1_fsm_0, ap_sig_35, ap_sig_ioackin_out_data_TREADY)
    begin
        if (((ap_const_logic_1 = ap_done_reg) or ((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_sig_35 or (ap_const_logic_0 = ap_sig_ioackin_out_data_TREADY)))))) then 
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


    ap_ready_assign_proc : process(ap_sig_cseq_ST_st1_fsm_0, ap_sig_35, ap_sig_ioackin_out_data_TREADY)
    begin
        if (((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_sig_35 or (ap_const_logic_0 = ap_sig_ioackin_out_data_TREADY))))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;


    ap_sig_19_assign_proc : process(ap_CS_fsm)
    begin
                ap_sig_19 <= (ap_CS_fsm(0 downto 0) = ap_const_lv1_1);
    end process;


    ap_sig_35_assign_proc : process(ap_start, ap_done_reg)
    begin
                ap_sig_35 <= ((ap_start = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1));
    end process;


    ap_sig_61_assign_proc : process(out_data_TREADY, ap_sig_35)
    begin
                ap_sig_61 <= (not(ap_sig_35) and (ap_const_logic_1 = out_data_TREADY));
    end process;


    ap_sig_cseq_ST_st1_fsm_0_assign_proc : process(ap_sig_19)
    begin
        if (ap_sig_19) then 
            ap_sig_cseq_ST_st1_fsm_0 <= ap_const_logic_1;
        else 
            ap_sig_cseq_ST_st1_fsm_0 <= ap_const_logic_0;
        end if; 
    end process;


    ap_sig_ioackin_out_data_TREADY_assign_proc : process(out_data_TREADY, ap_reg_ioackin_out_data_TREADY)
    begin
        if ((ap_const_logic_0 = ap_reg_ioackin_out_data_TREADY)) then 
            ap_sig_ioackin_out_data_TREADY <= out_data_TREADY;
        else 
            ap_sig_ioackin_out_data_TREADY <= ap_const_logic_1;
        end if; 
    end process;

    out_data_TDATA <= log10_res;

    out_data_TDATA_blk_n_assign_proc : process(ap_sig_cseq_ST_st1_fsm_0, out_data_TREADY)
    begin
        if ((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0)) then 
            out_data_TDATA_blk_n <= out_data_TREADY;
        else 
            out_data_TDATA_blk_n <= ap_const_logic_1;
        end if; 
    end process;


    out_data_TVALID_assign_proc : process(ap_sig_cseq_ST_st1_fsm_0, ap_sig_35, ap_reg_ioackin_out_data_TREADY)
    begin
        if (((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not(ap_sig_35) and (ap_const_logic_0 = ap_reg_ioackin_out_data_TREADY))) then 
            out_data_TVALID <= ap_const_logic_1;
        else 
            out_data_TVALID <= ap_const_logic_0;
        end if; 
    end process;

end behav;
