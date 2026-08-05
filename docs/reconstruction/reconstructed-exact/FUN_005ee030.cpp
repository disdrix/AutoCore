// =============================================================================
// FUN_005ee030
// -----------------------------------------------------------------------------
// Stable ID: aa_005ee030
// Address:   0x005ee030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ee030 @ 0x005ee030
// Stable ID: aa_005ee030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005ee030, SQRT.
//  - Return sites: 1.

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

float * __thiscall FUN_005ee030(float *param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  fVar2 = (param_4[1] - param_2[1]) * (*param_3 - *param_2) -

          (param_3[1] - param_2[1]) * (*param_4 - *param_2);

  fVar1 = (param_3[2] - param_2[2]) * (*param_4 - *param_2) -

          (param_4[2] - param_2[2]) * (*param_3 - *param_2);

  fVar4 = (param_4[2] - param_2[2]) * (param_3[1] - param_2[1]) -

          (param_4[1] - param_2[1]) * (param_3[2] - param_2[2]);

  *param_1 = fVar4;

  param_1[1] = fVar1;

  param_1[2] = fVar2;

  fVar3 = SQRT(fVar4 * fVar4 + fVar1 * fVar1 + fVar2 * fVar2);

  if (fVar3 != g_flZero) {

    fVar3 = g_flOne / fVar3;

    *param_1 = fVar4 * fVar3;

    param_1[1] = fVar1 * fVar3;

    param_1[2] = fVar2 * fVar3;

  }

  param_1[3] = 0.0 - (param_2[2] * param_1[2] + *param_2 * *param_1 + param_1[1] * param_2[1]);

  return param_1;

}
