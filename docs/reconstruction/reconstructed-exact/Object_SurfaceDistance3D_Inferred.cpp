// =============================================================================
// Object_SurfaceDistance3D_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Surface-to-surface 3D Euclidean distance between two objects.
//           Resolve each world position (phys rb+0xb0 or entity+0x84 path —
//           same dual as Object_GetWorldPositionPtr / FUN_00404c90), then
//           sqrt(dx^2+dy^2+dz^2) - radiusA(+0x34) - radiusB(+0x34).
//
// Address:  0x0053e510  (autoassault.exe, image base 0x400000)
// Body:     0x0053e510–0x0053e5ad (158 B / 0x9E), ret 4
// Stable:   aa_0053e510
// System:   shared-object-pose / AI-range
// Ghidra:   FUN_0053e510
//
// ABI:      __thiscall  float10 (objectA* this, objectB* other)  — ret 4
//
// Exactness: CF mirrors raw + read_memory. Inline fsqrt; no CALL callees.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W25-H seal).
//
// Prior scaffold alias: Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons_0053e510
// =============================================================================

#include <cmath>

// float10 approximated as long double for plate readability
using float10 = long double;

static inline float *Object_WorldPosPtr(int obj)
{
    if (*(int *)(obj + 8) == 0) {
        return (float *)(*(int *)(*(int *)(obj + 4) + 4) + 0x84 + obj);
    }
    return (float *)(*(int *)(*(int *)(obj + 8) + 0x3c) + 0xb0);
}

float10 __thiscall Object_SurfaceDistance3D_Inferred(int objA, int objB)
{
    float *posA = Object_WorldPosPtr(objA);
    float *posB = Object_WorldPosPtr(objB);

    float10 dx = (float10)posA[0] - (float10)posB[0];
    float10 dy = (float10)posA[1] - (float10)posB[1];
    float10 dz = (float10)posA[2] - (float10)posB[2];

    float10 center = (float10)std::sqrt((double)(dx * dx + dy * dy + dz * dz));
    return center
         - (float10)*(float *)(objA + 0x34)
         - (float10)*(float *)(objB + 0x34);
}
