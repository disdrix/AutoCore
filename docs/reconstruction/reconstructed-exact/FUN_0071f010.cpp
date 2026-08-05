// =============================================================================
// FUN_0071f010
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f010
// Address:   0x0071f010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071f010 @ 0x0071f010
// Stable ID: aa_0071f010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0071f010, ov_clear.
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

void FUN_0071f010(void)



{

  int unaff_ESI;

  

  if ((*(char *)(unaff_ESI + 2) != '\0') && (*(void **)(unaff_ESI + 0x28) != (void *)0x0)) {

    operator_delete__(*(void **)(unaff_ESI + 0x28));

    DAT_00d1a608 = DAT_00d1a608 - *(int *)(unaff_ESI + 0x30);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28) = 0;

  }

  if (*(int *)(unaff_ESI + 0x40) != 0) {

    ov_clear(*(int *)(unaff_ESI + 0x40));

    if (*(void **)(unaff_ESI + 0x40) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(unaff_ESI + 0x40));

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40) = 0;

  }

  return;

}
