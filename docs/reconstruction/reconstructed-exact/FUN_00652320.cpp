// =============================================================================
// FUN_00652320
// -----------------------------------------------------------------------------
// Stable ID: aa_00652320
// Address:   0x00652320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00652320 @ 0x00652320
// Stable ID: aa_00652320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0055e410, FUN_0055e9f0, FUN_00652320.
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

void __thiscall FUN_00652320(int param_1,int param_2)



{

  if (*(int *)(param_1 + 0xc) != 0) {

    FUN_0055e410(param_1 + 8);

  }

  *(int *)(param_1 + 0xc) = param_2;

  if (param_2 != 0) {

    FUN_0055e9f0(param_1 + 8);

  }

  return;

}
