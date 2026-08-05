// =============================================================================
// FUN_004e88e0  (alias of Vec3_Copy)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e88e0
// Address:   0x004e88e0  (autoassault.exe, image base 0x400000)
// System:    math / vector
// Canonical: Vec3_Copy  (see Vec3_Copy.cpp)
// Dual A/B:  accept (2026-07-29 W17-B)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

void __cdecl FUN_004e88e0(float *param_1 /* dst */, float const *param_2 /* src */)
{
  float uVar1;
  float uVar2;

  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  return;
}
