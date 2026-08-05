// =============================================================================
// FUN_009c54f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009c54f0
// Address:   0x009c54f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009c54f0 @ 0x009c54f0
// Stable ID: aa_009c54f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_009c54f0.
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

void FUN_009c54f0(void)



{

  if (DAT_00d08ef0 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(DAT_00d08ef0);

  }

  DAT_00d08ef0 = (void *)0x0;

  DAT_00d08ef4 = 0;

  DAT_00d08ef8 = 0;

  return;

}
