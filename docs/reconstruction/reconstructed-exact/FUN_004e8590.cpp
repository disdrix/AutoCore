// =============================================================================
// Math_QuatInverseRotateDelta_Inferred  (Ghidra: FUN_004e8590)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e8590
// Address:   0x004e8590  (autoassault.exe, image base 0x400000)
// Span:      004e8590 – 004e87ce (575 B; cdecl leaf; ret)
// System:    pure math / transform
// Dual A/B:  2026-07-29 accept-with-gaps (W23-O)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Contract (dual-sealed):
 *   out.xyz = R(quat_xyzw)^T * (point.xyz - origin.xyz)
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
 * Not FUN_004e8bf0 (forward pos + R*v).
 * Prior scaffold alias Named_CalleeOf_Named_CalleeOf_..._004e8590 is too narrow.
 */

// SECTION: args — origin, quat(XYZW), world point, out (XYZ only)
void FUN_004e8590(float *param_1, float *param_2, float *param_3, float *param_4)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;

  fVar3 = (*param_2 * param_2[1] - param_2[3] * param_2[2]) * g_flLevelUpUiBase_Inferred;
  fVar4 = *param_2 * *param_2;
  fVar6 = g_flOne - (param_2[2] * param_2[2] + fVar4) * g_flLevelUpUiBase_Inferred;
  fVar7 = (*param_2 * param_2[3] + param_2[2] * param_2[1]) * g_flLevelUpUiBase_Inferred;
  fVar8 = (*param_2 * param_2[2] + param_2[3] * param_2[1]) * g_flLevelUpUiBase_Inferred;
  fVar9 = (param_2[2] * param_2[1] - *param_2 * param_2[3]) * g_flLevelUpUiBase_Inferred;
  fVar1 = g_flOne - (param_2[1] * param_2[1] + fVar4) * g_flLevelUpUiBase_Inferred;
  fVar2 = param_3[1] - param_1[1];
  fVar5 = param_3[2] - param_1[2];
  fVar4 = *param_3 - *param_1;
  *param_4 = (*param_2 * param_2[2] - param_2[3] * param_2[1]) * g_flLevelUpUiBase_Inferred * fVar5
           + (*param_2 * param_2[1] + param_2[3] * param_2[2]) * g_flLevelUpUiBase_Inferred * fVar2
           + (g_flOne - (param_2[1] * param_2[1] + param_2[2] * param_2[2]) * g_flLevelUpUiBase_Inferred) * fVar4;
  param_4[1] = fVar7 * fVar5 + fVar6 * fVar2 + fVar3 * fVar4;
  param_4[2] = fVar1 * fVar5 + fVar9 * fVar2 + fVar8 * fVar4;
  return;
}
