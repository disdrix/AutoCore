// =============================================================================
// FUN_00521130
// -----------------------------------------------------------------------------
// Stable ID: aa_00521130
// Address:   0x00521130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00521130 @ 0x00521130
// Stable ID: aa_00521130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00762b40×7, FUN_00521130.
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

void FUN_00521130(void)



{

  FUN_00762b40(3,1,1);

  FUN_00762b40(4,1,1);

  FUN_00762b40(0x22,1,1);

  FUN_00762b40(0x21,1,1);

  FUN_00762b40(0x29,1,1);

  FUN_00762b40(0x28,1,1);

  FUN_00762b40(0x2a,1,1);

  return;

}
