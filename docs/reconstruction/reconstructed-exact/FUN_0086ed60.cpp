// =============================================================================
// FUN_0086ed60
// -----------------------------------------------------------------------------
// Stable ID: aa_0086ed60
// Address:   0x0086ed60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0086ed60 @ 0x0086ed60
// Stable ID: aa_0086ed60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, do×1, while×1.
//  - Notable callees: FUN_004133c0, FUN_007fbe50, FUN_0086ed60.
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

void FUN_0086ed60(void)



{

  int *piVar1;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0x568) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x568) + 0x458))();

  }

  if (*(int *)(unaff_EDI + 0x56c) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x56c) + 0x458))();

  }

  if (*(int *)(unaff_EDI + 0x570) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x570) + 0x458))();

  }

  if (*(int *)(unaff_EDI + 0x574) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x574) + 0x458))();

  }

  if (*(int *)(unaff_EDI + 0x578) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x578) + 0x458))();

  }

  if (*(int *)(unaff_EDI + 0x57c) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x57c) + 0x458))();

  }

  if (*(int *)(unaff_EDI + 0x580) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x580) + 0x458))();

  }

  if (*(int *)(unaff_EDI + 0x584) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x584) + 0x458))();

  }

  piVar1 = (int *)**(int **)(unaff_EDI + 0x518);

  if (piVar1 != *(int **)(unaff_EDI + 0x518)) {

    do {

      if ((void *)piVar1[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)piVar1[2]);

      }

      piVar1[2] = 0;

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(unaff_EDI + 0x518));

  }

  FUN_004133c0(0);

  FUN_007fbe50();

  return;

}
