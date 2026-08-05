// =============================================================================
// FUN_0072ae90
// -----------------------------------------------------------------------------
// Stable ID: aa_0072ae90
// Address:   0x0072ae90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072ae90 @ 0x0072ae90
// Stable ID: aa_0072ae90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, return×6.
//  - Notable callees: FUN_0072af30×4, FUN_0072ae90.
//  - Return sites: 6.

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

void FUN_0072ae90(void)



{

  void *pvVar1;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x18) == 0) {

    pvVar1 = *(void **)(unaff_ESI + 0x1c);

    if (pvVar1 != (void *)0x0) {

      FUN_0072af30();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    pvVar1 = *(void **)(unaff_ESI + 0x20);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

    if (pvVar1 != (void *)0x0) {

      FUN_0072af30();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    pvVar1 = *(void **)(unaff_ESI + 0x24);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = 0;

    if (pvVar1 != (void *)0x0) {

      FUN_0072af30();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    pvVar1 = *(void **)(unaff_ESI + 0x28);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24) = 0;

    if (pvVar1 != (void *)0x0) {

      FUN_0072af30();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 1;

  }

  if (*(void **)(unaff_ESI + 0x30) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 0x30));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38) = 0;

  return;

}
