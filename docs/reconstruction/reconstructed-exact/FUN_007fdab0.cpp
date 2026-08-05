// =============================================================================
// FUN_007fdab0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fdab0
// Address:   0x007fdab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fdab0 @ 0x007fdab0
// Stable ID: aa_007fdab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_007fdab0.
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

void FUN_007fdab0(int param_1)



{

  void *pvVar1;

  int *piVar2;

  int *piVar3;

  int unaff_EDI;

  

  piVar2 = (int *)**(int **)(unaff_EDI + 0x3124);

  if (piVar2 != *(int **)(unaff_EDI + 0x3124)) {

    do {

      pvVar1 = (void *)piVar2[2];

      if (*(int *)((int)pvVar1 + 0x20) == param_1) {

        if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        piVar2[2] = 0;

        piVar3 = (int *)*piVar2;

        if (piVar2 != *(int **)(unaff_EDI + 0x3124)) {

          *(int **)piVar2[1] = piVar3;

          *(int *)(*piVar2 + 4) = piVar2[1];

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar2);

        }

      }

      else {

        piVar3 = (int *)*piVar2;

      }

      piVar2 = piVar3;

    } while (piVar3 != *(int **)(unaff_EDI + 0x3124));

  }

  return;

}
