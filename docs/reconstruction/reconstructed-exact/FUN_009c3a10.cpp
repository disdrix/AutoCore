// =============================================================================
// FUN_009c3a10
// -----------------------------------------------------------------------------
// Stable ID: aa_009c3a10
// Address:   0x009c3a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009c3a10 @ 0x009c3a10
// Stable ID: aa_009c3a10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_009c3a10.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_009c3a10(void)



{

  if (DAT_00b046a8 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(DAT_00b046a8);

  }

  DAT_00b046a8 = (void *)0x0;

  DAT_00b046ac = 0;

  _DAT_00b046b0 = 0;

  return;

}
