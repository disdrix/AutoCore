// =============================================================================
// FUN_0071dd00
// -----------------------------------------------------------------------------
// Stable ID: aa_0071dd00
// Address:   0x0071dd00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071dd00 @ 0x0071dd00
// Stable ID: aa_0071dd00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00718c50, FUN_0071dd00, block.
//  - Return sites: 3.

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

/* WARNING: Removing unreachable block (ram,0x0071dd48) */



void FUN_0071dd00(void)



{

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  *unaff_ESI = &PTR_FUN_00aa999c;

  if (unaff_ESI[5] != unaff_ESI[6]) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI[5] + 8));

  }

  if ((void *)unaff_ESI[5] == (void *)0x0) {

    unaff_ESI[5] = 0;

    unaff_ESI[6] = 0;

    unaff_ESI[7] = 0;

    unaff_ESI[5] = 0;

    unaff_ESI[6] = 0;

    unaff_ESI[7] = 0;

    FUN_00718c50();

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)unaff_ESI[5]);

}
