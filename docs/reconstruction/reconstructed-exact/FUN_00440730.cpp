// =============================================================================
// FUN_00440730
// -----------------------------------------------------------------------------
// Stable ID: aa_00440740
// Address:   0x00440740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00440730 @ 0x00440730
// Stable ID: aa_00440730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00440730.
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

void FUN_00440730(void)



{

  int *piVar1;

  int *piVar2;

  int unaff_ESI;

  

  if (*(void **)(unaff_ESI + 0x14) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 0x14));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

  piVar2 = *(int **)(unaff_ESI + 8);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

                    /* WARNING: Could not recover jumptable at 0x00440764. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*piVar2 + 8))();

      return;

    }

  }

  return;

}
