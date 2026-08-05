// =============================================================================
// FUN_0046b550
// -----------------------------------------------------------------------------
// Stable ID: aa_0046b550
// Address:   0x0046b550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046b550 @ 0x0046b550
// Stable ID: aa_0046b550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_0040f5b0, FUN_0046b550.
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

int __fastcall FUN_0046b550(int param_1)



{

  int in_EAX;

  int unaff_EBX;

  

  while (unaff_EBX != in_EAX) {

    in_EAX = in_EAX + -0x10;

    param_1 = param_1 + -0x10;

    FUN_0040f5b0(in_EAX);

  }

  return param_1;

}
