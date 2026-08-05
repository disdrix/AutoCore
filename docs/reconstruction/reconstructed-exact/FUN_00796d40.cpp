// =============================================================================
// FUN_00796d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00796d40
// Address:   0x00796d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00796d40 @ 0x00796d40
// Stable ID: aa_00796d40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00796cd0, FUN_00796d40, _atexit.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined * FUN_00796d40(void)



{

  if ((_DAT_00d20050 & 1) == 0) {

    _DAT_00d20050 = _DAT_00d20050 | 1;

    FUN_00796cd0();

    _atexit((_func_4879 *)&DAT_009c3110);

  }

  return &DAT_00d1fe78;

}
