// =============================================================================
// FUN_0076f5f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076f5f0
// Address:   0x0076f5f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076f5f0 @ 0x0076f5f0
// Stable ID: aa_0076f5f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0076f5f0, SQRT.
//  - Return sites: 2.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float * FUN_0076f5f0(float *param_1,float *param_2)



{

  float fVar1;

  

  fVar1 = SQRT(param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2);

  if ((fVar1 < _DAT_00a240ec) && (DAT_00aaa640 < fVar1)) {

    return param_1;

  }

  fVar1 = g_flOne / fVar1;

  *param_1 = *param_2 * fVar1;

  param_1[1] = param_2[1] * fVar1;

  param_1[2] = fVar1 * param_2[2];

  return param_1;

}
