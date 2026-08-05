// =============================================================================
// FUN_009c4410
// -----------------------------------------------------------------------------
// Stable ID: aa_009c4410
// Address:   0x009c4410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009c4410 @ 0x009c4410
// Stable ID: aa_009c4410
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005ffdb0, FUN_009c4410.
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

void FUN_009c4410(void)



{

  PTR_PTR_00af4f88 = (undefined *)&PTR_FUN_009d81e8;

  if ((DAT_00af4f8d & 0x80) != 0) {

    DAT_00af4f8d = DAT_00af4f8d & 0x7f;

    FUN_005ffdb0(0);

  }

  PTR_PTR_00af4f88 = (undefined *)&PTR_LAB_009cc290;

  return;

}
