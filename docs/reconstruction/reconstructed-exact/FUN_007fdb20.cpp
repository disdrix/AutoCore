// =============================================================================
// FUN_007fdb20
// -----------------------------------------------------------------------------
// Stable ID: aa_007fdb20
// Address:   0x007fdb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fdb20 @ 0x007fdb20
// Stable ID: aa_007fdb20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×4, while×1.
//  - Notable callees: FUN_007fdb20.
//  - Return sites: 4.

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

void FUN_007fdb20(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int unaff_EDI;

  

  piVar1 = *(int **)(unaff_EDI + 0x3124);

  piVar2 = (int *)*piVar1;

  if (piVar2 != piVar1) {

    while ((*(int *)piVar2[2] != param_1 || (((int *)piVar2[2])[1] != param_2))) {

      piVar2 = (int *)*piVar2;

      if (piVar2 == piVar1) {

        return;

      }

    }

    if ((void *)piVar2[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)piVar2[2]);

    }

    piVar2[2] = 0;

    if (piVar2 != *(int **)(unaff_EDI + 0x3124)) {

      *(int *)piVar2[1] = *piVar2;

      *(int *)(*piVar2 + 4) = piVar2[1];

                    /* WARNING: Subroutine does not return */

      operator_delete(piVar2);

    }

  }

  return;

}
