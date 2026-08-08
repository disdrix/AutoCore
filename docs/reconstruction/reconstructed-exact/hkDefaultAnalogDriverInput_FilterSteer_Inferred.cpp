// =============================================================================
// hkDefaultAnalogDriverInput_FilterSteer_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005fdf20
// Address:   0x005fdf20–0x005fdf97 inclusive (120 B / 0x78)
// Module:    autoassault.exe (image base 0x400000)
// System:    input-drive-control
// Ghidra:    FUN_005fdf20
// Agent:     MEGA-026 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + sealed assembly CF.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Runtime:   OPEN (Terminal false — no Launcher / no Confirmed).
// =============================================================================

// PURPOSE
// Piecewise-linear filtered steering for hkDefaultAnalogDriverInput.
// Sole caller calcStatus (0x005fe520) stores the float return at this+0x14
// (status steer). Leaf: no callees. ECX=this; plain RET; return on FPU ST0.
//
// Formula:
//   abs = |raw_steer(+0x1c)|
//   if abs < deadzone(+0x38): return 0
//   sign = (raw > 0) ? +1 : -1
//   if abs < inner(+0x28): return (abs - deadzone) * slope_inner(+0x2c) * sign
//   else: return ((abs - inner) * slope_outer(+0x30) + base(+0x34)) * sign
//
// Globals:
//   g_flZero @ 0x00a0f518 = 0.0f
//   g_flOne  @ 0x00a0f2a0 = 1.0f
//   DAT_00aaa668           = -1.0f

// Prior scaffold FUN_005fdf20.cpp retired by this named clean (MEGA-026).

#include <cmath>

// External float constants (image)
extern float g_flZero;       // 0x00a0f518
extern float g_flOne;        // 0x00a0f2a0
extern float DAT_00aaa668;   // 0x00aaa668 = -1.0f

struct hkDefaultAnalogDriverInput {
    // ... leading fields used by calcStatus ...
    // +0x0c status.accel, +0x10 status.brake, +0x14 status.steer (written by caller)
    // +0x18 handbrake, +0x19 reverse
    // +0x1c raw signed steer (this helper's input)
    // +0x20 raw pedal
    // +0x24 handbrake control byte
    // +0x28..+0x38 steer filter knobs (see below)
    char _pad_to_0x1c[0x1c];
    float raw_steer_0x1c;
    float raw_pedal_0x20;
    unsigned char handbrake_ctrl_0x24;
    char _pad_0x25[3];
    float steer_inner_thresh_0x28;
    float steer_inner_slope_0x2c;
    float steer_outer_slope_0x30;
    float steer_outer_base_0x34;
    float steer_deadzone_0x38;
    // ...
};

// __thiscall: ECX = this; no stack args; plain RET; float return on ST0
float __thiscall hkDefaultAnalogDriverInput_FilterSteer_Inferred(
    hkDefaultAnalogDriverInput *self)
{
    float abs_steer;
    float sign;

    abs_steer = fabsf(self->raw_steer_0x1c);
    if (abs_steer < self->steer_deadzone_0x38) {
        return g_flZero;
    }

    sign = g_flOne;
    if (self->raw_steer_0x1c <= g_flZero) {
        sign = DAT_00aaa668; /* -1.0f */
    }

    if (abs_steer < self->steer_inner_thresh_0x28) {
        return (abs_steer - self->steer_deadzone_0x38)
             * self->steer_inner_slope_0x2c
             * sign;
    }

    return ((abs_steer - self->steer_inner_thresh_0x28)
          * self->steer_outer_slope_0x30
          + self->steer_outer_base_0x34)
          * sign;
}
