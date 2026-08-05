// =============================================================================
// Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons_0053e510
// -----------------------------------------------------------------------------
// Legacy parent-seed alias for aa_0053e510.
// Prefer: Object_SurfaceDistance3D_Inferred (W25-H dual seal).
// Address: 0x0053e510
// =============================================================================

// Forwards to the sealed named reconstruction (behavior identity).
// See: Object_SurfaceDistance3D_Inferred.cpp / FUN_0053e510.cpp

float10 __thiscall Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons_0053e510(int param_1, int param_2)
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
