// =============================================================================
// FUN_004e8a40
// -----------------------------------------------------------------------------
// Stable ID: aa_004e8a40
// Address:   0x004e8a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_004e8a40(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = g_flLevelUpUiBase_Inferred;
  fVar1 = *param_1;
  fVar2 = param_1[1];
  fVar3 = param_1[2];
  fVar4 = param_1[3];
  *param_2 = (fVar3 * fVar1 + fVar2 * fVar4) * g_flLevelUpUiBase_Inferred;
  param_2[1] = (fVar3 * fVar2 - fVar1 * fVar4) * fVar5;
  param_2[2] = g_flOne - (fVar1 * fVar1 + fVar2 * fVar2) * fVar5;
  param_2[3] = 0.0;
  return;
}
