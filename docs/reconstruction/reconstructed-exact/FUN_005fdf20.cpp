// =============================================================================
// FUN_005fdf20  (twin of hkDefaultAnalogDriverInput_FilterSteer_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005fdf20
// Address:   0x005fdf20–0x005fdf97 inclusive (120 B / 0x78)
// Module:    autoassault.exe (image base 0x400000)
// System:    input-drive-control
// Agent:     MEGA-026 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving; Ghidra name retained as twin entry.
// Canonical named clean: hkDefaultAnalogDriverInput_FilterSteer_Inferred.cpp
// Runtime:   OPEN (Terminal false).
// =============================================================================

// PURPOSE (MEGA-026): Filtered steer leaf for hkDefaultAnalogDriverInput.
// Sole caller: hkDefaultAnalogDriverInput_calcStatus @ 0x005fe520 stores ST0 → +0x14.
// ABI: ECX=this; plain RET ×3; float on FPU ST0; leaf.
// Scaffold of 2026-07-23 replaced with sealed dual reconstruction.

extern float g_flZero;       // 0x00a0f518 = 0.0f
extern float g_flOne;        // 0x00a0f2a0 = 1.0f
extern float DAT_00aaa668;   // 0x00aaa668 = -1.0f

// Decompiler-shaped twin (param_1 == ECX this)
float __fastcall FUN_005fdf20(int param_1)
{
    float fVar1; /* abs(|+0x1c|) */
    float fVar2; /* sign +1 / -1 */

    fVar1 = (float)fabs((double)(*(float *)(param_1 + 0x1c)));
    if (fVar1 < *(float *)(param_1 + 0x38)) {
        return g_flZero;
    }
    fVar2 = g_flOne;
    if (*(float *)(param_1 + 0x1c) <= g_flZero) {
        fVar2 = DAT_00aaa668;
    }
    if (fVar1 < *(float *)(param_1 + 0x28)) {
        return (fVar1 - *(float *)(param_1 + 0x38))
             * *(float *)(param_1 + 0x2c)
             * fVar2;
    }
    return ((fVar1 - *(float *)(param_1 + 0x28))
          * *(float *)(param_1 + 0x30)
          + *(float *)(param_1 + 0x34))
          * fVar2;
}
