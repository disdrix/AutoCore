// =============================================================================
// FUN_00423a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00423a50
// Address:   0x00423a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00423a50 @ 0x00423a50
// Stable ID: aa_00423a50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00423a50, InterlockedDecrement.
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

LONG FUN_00423a50(int param_1)



{

  LONG LVar1;

  

  LVar1 = InterlockedDecrement((LONG *)(param_1 + 8));

  if (LVar1 == 0) {

    return 0;

  }

  return *(LONG *)(param_1 + 8);

}
