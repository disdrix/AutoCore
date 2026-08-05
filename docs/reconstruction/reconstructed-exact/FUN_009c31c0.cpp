// =============================================================================
// FUN_009c31c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009c31c0
// Address:   0x009c31c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009c31c0 @ 0x009c31c0
// Stable ID: aa_009c31c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_009c31c0, free.
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

void FUN_009c31c0(void)



{

  PTR_PTR_00afdbf8 = (undefined *)&PTR_FUN_00a9b7a4;

  free(DAT_00afdc18);

  PTR_PTR_00afdbf8 = (undefined *)&PTR_LAB_009d7af4;

  return;

}
