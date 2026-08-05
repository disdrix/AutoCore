// =============================================================================
// FUN_00645640
// -----------------------------------------------------------------------------
// Stable ID: aa_00645640
// Address:   0x00645640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00645640 @ 0x00645640
// Stable ID: aa_00645640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00645640.
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

void __thiscall FUN_00645640(float *param_1,float param_2)



{

  *param_1 = *param_1 * param_2;

  param_1[1] = param_2 * param_1[1];

  param_1[2] = param_2 * param_1[2];

  param_1[3] = param_2 * param_1[3];

  param_1[4] = param_1[4] * param_2;

  param_1[5] = param_1[5] * param_2;

  param_1[6] = param_1[6] * param_2;

  param_1[7] = param_1[7] * param_2;

  param_1[8] = param_1[8] * param_2;

  param_1[9] = param_1[9] * param_2;

  param_1[10] = param_1[10] * param_2;

  param_1[0xb] = param_1[0xb] * param_2;

  return;

}
