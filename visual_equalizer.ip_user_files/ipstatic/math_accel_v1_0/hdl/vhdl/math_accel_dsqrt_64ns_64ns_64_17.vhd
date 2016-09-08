-- ==============================================================
-- File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2016.2
-- Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
-- 
-- ==============================================================

Library ieee;
use ieee.std_logic_1164.all;

entity math_accel_dsqrt_64ns_64ns_64_17 is
    generic (
        ID         : integer := 2;
        NUM_STAGE  : integer := 17;
        din0_WIDTH : integer := 64;
        din1_WIDTH : integer := 64;
        dout_WIDTH : integer := 64
    );
    port (
        clk   : in  std_logic;
        reset : in  std_logic;
        ce    : in  std_logic;
        din0  : in  std_logic_vector(din0_WIDTH-1 downto 0);
        din1  : in  std_logic_vector(din1_WIDTH-1 downto 0);
        dout  : out std_logic_vector(dout_WIDTH-1 downto 0)
    );
end entity;

architecture arch of math_accel_dsqrt_64ns_64ns_64_17 is
    --------------------- Component ---------------------
    component math_accel_ap_dsqrt_15_no_dsp_64 is
        port (
            aclk                 : in  std_logic;
            aclken               : in  std_logic;
            s_axis_a_tvalid      : in  std_logic;
            s_axis_a_tdata       : in  std_logic_vector(63 downto 0);
            m_axis_result_tvalid : out std_logic;
            m_axis_result_tdata  : out std_logic_vector(63 downto 0)
        );
    end component;
    --------------------- Local signal ------------------
    signal aclk      : std_logic;
    signal aclken    : std_logic;
    signal a_tvalid  : std_logic;
    signal a_tdata   : std_logic_vector(63 downto 0);
    signal r_tvalid  : std_logic;
    signal r_tdata   : std_logic_vector(63 downto 0);
    signal din1_buf1 : std_logic_vector(din1_WIDTH-1 downto 0);
begin
    --------------------- Instantiation -----------------
    math_accel_ap_dsqrt_15_no_dsp_64_u : component math_accel_ap_dsqrt_15_no_dsp_64
    port map (
        aclk                 => aclk,
        aclken               => aclken,
        s_axis_a_tvalid      => a_tvalid,
        s_axis_a_tdata       => a_tdata,
        m_axis_result_tvalid => r_tvalid,
        m_axis_result_tdata  => r_tdata
    );

    --------------------- Assignment --------------------
    aclk     <= clk;
    aclken   <= ce;
    a_tvalid <= '1';
    a_tdata  <= din1_buf1;
    dout     <= r_tdata;

    --------------------- Input buffer ------------------
    process (clk) begin
        if clk'event and clk = '1' then
            if ce = '1' then
                din1_buf1 <= din1;
            end if;
        end if;
    end process;

end architecture;
