// =============================================================================
// FUN_00695c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00695c60
// Address:   0x00695c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00695c60 @ 0x00695c60
// Stable ID: aa_00695c60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, do×1, while×1.
//  - Notable callees: FUN_00695ad0, FUN_00695c60.
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

int FUN_00695c60(int param_1,int param_2,int param_3)



{

  if (param_1 == param_2) {

    return param_3;

  }

  do {

    param_2 = param_2 + -0x10;

    param_3 = param_3 + -0x10;

    FUN_00695ad0(param_2);

  } while (param_2 != param_1);

  return param_3;

}
