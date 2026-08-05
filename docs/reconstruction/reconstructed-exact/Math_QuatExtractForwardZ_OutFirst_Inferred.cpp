// =============================================================================
// Math_QuatExtractForwardZ_OutFirst_Inferred  (Ghidra: FUN_005d1d20)
// -----------------------------------------------------------------------------
// Stable ID: aa_005d1d20
// Address:   0x005d1d20
// Twin:      docs/reconstruction/reconstructed-exact/FUN_005d1d20.cpp
// Sibling:   Math_QuatExtractForwardZ @ 0x004e8a40 — identical algebra; (quat, out)
// =============================================================================

// Port contract (cdecl):
//   void Math_QuatExtractForwardZ_OutFirst_Inferred(float out[4], const float q[4]);
//   q is XYZW. out is local +Z in world space; out[3]=0.
//   TWO = 2.0f (DAT_00a10e74); ONE = 1.0f (DAT_00a0f2a0 / g_flOne).

extern float g_flLevelUpUiBase_Inferred; // 2.0f
extern float g_flOne;                    // 1.0f

void Math_QuatExtractForwardZ_OutFirst_Inferred(float *out, const float *q)
{
  const float two = g_flLevelUpUiBase_Inferred;
  const float x = q[0];
  const float y = q[1];
  const float z = q[2];
  const float w = q[3];

  // Store order follows decompile (Y then X then Z then W) — values match closed form
  out[1] = (z * y - w * x) * two;              // 2(yz - xw)
  out[0] = (w * y + z * x) * two;              // 2(xz + yw)
  out[2] = g_flOne - (x * x + y * y) * two;    // 1 - 2(x² + y²)
  out[3] = 0.0f;
}
