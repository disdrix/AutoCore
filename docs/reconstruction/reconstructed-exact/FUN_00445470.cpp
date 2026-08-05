// =============================================================================
// FUN_00445470
// -----------------------------------------------------------------------------
// Stable ID: aa_00445470
// Address:   0x00445470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00445470 @ 0x00445470
// Stable ID: aa_00445470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00445470.
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

void FUN_00445470(void)



{

  int unaff_ESI;

  

  if (*(void **)(unaff_ESI + 0xc) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 0xc));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  return;

}
