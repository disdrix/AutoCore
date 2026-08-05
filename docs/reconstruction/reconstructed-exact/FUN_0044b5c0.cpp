// =============================================================================
// FUN_0044b5c0  (scaffold twin of Object_WriteComposedMatrix)
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b5c0
// Address:   0x0044b5c0 – 0x0044b60f
// System:    graphics / xform
// Dual:      2026-07-29 W22-C — see Object_WriteComposedMatrix.cpp
// =============================================================================

#include <cstdint>

struct ObjectLike;

extern "C" float* Object_WriteComposedMatrix(
    ObjectLike* primary, float* outMatrix, ObjectLike* companion);

extern "C" float* FUN_0044b5c0(ObjectLike* param_1, float* param_2, ObjectLike* companion_edi)
{
  return Object_WriteComposedMatrix(param_1, param_2, companion_edi);
}
