// =============================================================================
// FUN_0053e510  (scaffold alias → Object_SurfaceDistance3D_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0053e510
// Address:   0x0053e510  (autoassault.exe, image base 0x400000)
// System:    shared-object-pose / AI-range
// Generated: 2026-07-29 W25-H dual seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Named clean: Object_SurfaceDistance3D_Inferred.cpp
// Dual A/B: accept-with-gaps
// =============================================================================

// Ghidra surface — keep FUN_* form for scaffold twin.

float10 __thiscall FUN_0053e510(int param_1, int param_2)
{
    float *pfVar1;
    float *pfVar2;

    if (*(int *)(param_1 + 8) == 0) {
        pfVar1 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);
    } else {
        pfVar1 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0);
    }
    if (*(int *)(param_2 + 8) == 0) {
        pfVar2 = (float *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0x84 + param_2);
    } else {
        pfVar2 = (float *)(*(int *)(*(int *)(param_2 + 8) + 0x3c) + 0xb0);
    }
    return (SQRT(((float10)*pfVar1 - (float10)*pfVar2) * ((float10)*pfVar1 - (float10)*pfVar2) +
                 ((float10)pfVar1[1] - (float10)pfVar2[1]) * ((float10)pfVar1[1] - (float10)pfVar2[1]) +
                 ((float10)pfVar1[2] - (float10)pfVar2[2]) *
                   ((float10)pfVar1[2] - (float10)pfVar2[2])) -
            (float10)*(float *)(param_1 + 0x34)) -
           (float10)*(float *)(param_2 + 0x34);
}
