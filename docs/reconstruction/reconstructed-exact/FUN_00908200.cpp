// =============================================================================
// FUN_00908200
// -----------------------------------------------------------------------------
// Stable ID: aa_00908200
// Address:   0x00908200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00908200 @ 0x00908200
// Stable ID: aa_00908200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00977a30×2, FUN_00908200.
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

void FUN_00908200(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int unaff_EDI;

  uint8_t auStack_10 [16];

  

  if ((DAT_00d1b6d8 != 0) && (*(int *)(unaff_EDI + 0x6d8) != 0)) {

    (**(code **)(**(int **)(unaff_EDI + 0x6d8) + 0x34c))();

    (**(code **)(**(int **)(unaff_EDI + 0x6d8) + 0x268))();

    FUN_00977a30(DAT_00d1ad30,*(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728),

                 (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                 (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728)));

    piVar1 = *(int **)(unaff_EDI + 0x6d8);

    iVar2 = (**(code **)(*piVar1 + 0x140))(auStack_10,1);

    iVar3 = (**(code **)(*piVar1 + 0x204))(auStack_10);

    if (*(int *)(iVar2 + 4) < *(int *)(iVar3 + 4)) {

      (**(code **)(**(int **)(unaff_EDI + 0x6d8) + 0x268))();

      (**(code **)(**(int **)(unaff_EDI + 0x6d8) + 4))(0);

      if (*(int *)(unaff_EDI + 0x6dc) != 0) {

        (**(code **)(**(int **)(unaff_EDI + 0x6dc) + 0xcc))(1);

        (**(code **)(**(int **)(unaff_EDI + 0x6dc) + 0x268))();

        FUN_00977a30(DAT_00d1ad30,*(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728),

                     (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                     (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728)));

        (**(code **)(**(int **)(unaff_EDI + 0x6dc) + 0x34c))();

        return;

      }

    }

    else {

      (**(code **)(**(int **)(unaff_EDI + 0x6d8) + 4))(1);

      if (*(int *)(unaff_EDI + 0x6dc) != 0) {

        (**(code **)(**(int **)(unaff_EDI + 0x6dc) + 4))(0);

      }

    }

  }

  return;

}
