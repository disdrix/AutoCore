// =============================================================================
// FUN_00713510
// -----------------------------------------------------------------------------
// Stable ID: aa_00713510
// Address:   0x00713510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713510 @ 0x00713510
// Stable ID: aa_00713510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007132e0, FUN_00713510.
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

void FUN_00713510(uint param_1,float param_2,float *param_3,float *param_4)



{

  float10 fVar1;

  

  fVar1 = (float10)FUN_007132e0(&DAT_00a10e10,8,param_1 - (param_1 & 8));

  *param_4 = (float)fVar1;

  if ((param_1 & 8) == 0) {

    *param_3 = param_2;

    return;

  }

  *param_3 = (float)fVar1;

  return;

}
