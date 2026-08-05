// =============================================================================
// Math_QuatTransformPoint_Inferred  (Ghidra: FUN_004e8bf0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e8bf0
// Address:   0x004e8bf0  (autoassault.exe, image base 0x400000)
// Span:      004e8bf0 – 004e8db8 (457 B; cdecl leaf; ret)
// System:    pure math / transform
// Dual A/B:  2026-07-29 accept-with-gaps
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Contract (dual-sealed):
 *   out.xyz = pos.xyz + R(quat_xyzw) * vec.xyz
 *   out.w is NOT written.
 *
 * R columns (unit quat) match basis extractors:
 *   col0 right   = FUN_004e8ad0 @ 0x004e8ad0
 *   col1 up      = FUN_004e8b60 @ 0x004e8b60
 *   col2 forward = FUN_004e8a40 @ 0x004e8a40
 *
 * Pool constants (read_memory):
 *   g_flOne                    @ 0x00a0f2a0 = 1.0f
 *   g_flLevelUpUiBase_Inferred @ 0x00a10e74 = 2.0f  (misnomer; shared TWO factor)
 *
 * Not FUN_004e8590 (inverse delta R^T*(p3-p1)).
 * Prior scaffold name Named_CalleeOf_Named_SkyBoxParticles_004e8bf0 is too narrow.
 */

// SECTION: args — pos, quat(XYZW), local vec, out (XYZ only)
void FUN_004e8bf0(float *param_1, float *param_2, float *param_3, float *param_4)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;

  fVar6 = g_flLevelUpUiBase_Inferred; /* TWO = 2.0f */
  fVar5 = g_flOne;                    /* ONE = 1.0f */

  /* phase vx: out = pos + col0(q) * vx */
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar3 = param_2[3];
  fVar4 = *param_2;
  fVar7 = (fVar2 * fVar3 + *param_2 * fVar1) * g_flLevelUpUiBase_Inferred;
  *param_4 = *param_3 * (g_flOne - (fVar2 * fVar2 + fVar1 * fVar1) * g_flLevelUpUiBase_Inferred) +
             *param_1;
  param_4[1] = *param_3 * fVar7 + param_1[1];
  param_4[2] = *param_3 * (fVar2 * fVar4 - fVar3 * fVar1) * fVar6 + param_1[2];

  /* phase vy: out += col1(q) * vy */
  fVar1 = param_2[2];
  fVar2 = *param_2;
  fVar3 = param_2[1];
  fVar4 = param_2[3];
  *param_4 = (fVar3 * fVar2 - fVar1 * param_2[3]) * fVar6 * param_3[1] + *param_4;
  param_4[1] = (fVar5 - (fVar1 * fVar1 + fVar2 * fVar2) * fVar6) * param_3[1] + param_4[1];
  param_4[2] = (fVar1 * fVar3 + fVar2 * fVar4) * fVar6 * param_3[1] + param_4[2];

  /* phase vz: out += col2(q) * vz */
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar3 = *param_2;
  fVar4 = param_2[3];
  *param_4 = param_3[2] * (fVar2 * fVar3 + fVar1 * fVar4) * fVar6 + *param_4;
  param_4[1] = param_3[2] * (fVar2 * fVar1 - fVar3 * fVar4) * fVar6 + param_4[1];
  param_4[2] = param_3[2] * (fVar5 - (fVar1 * fVar1 + fVar3 * fVar3) * fVar6) + param_4[2];
  return;
}
