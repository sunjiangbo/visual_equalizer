#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /opt/Xilinx/Projects/visual_equalizer/math_accel/solution1/.autopilot/db/a.g.bc ${1+"$@"}