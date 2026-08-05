// =============================================================================
// FUN_006d3ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_006d3ca0
// Address:   0x006d3ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d3ca0 @ 0x006d3ca0
// Stable ID: aa_006d3ca0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_006d3ca0, FUN_006d3e80.
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

int __fastcall FUN_006d3ca0(int *param_1)



{

  uint8_t local_90 [124];

  uint8_t local_14;

  uint8_t local_13;

  

  local_13 = 0;

  local_14 = 0;

  if (param_1[1] == (param_1[2] & 0x7fffffffU)) {

    FUN_005b3370(param_1,0x80);

  }

  param_1[1] = param_1[1] + 1;

  FUN_006d3e80(local_90);

  return param_1[1] * 0x80 + -0x80 + *param_1;

}
