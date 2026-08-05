// =============================================================================
// FUN_0088de40
// -----------------------------------------------------------------------------
// Stable ID: aa_0088de40
// Address:   0x0088de40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088de40 @ 0x0088de40
// Stable ID: aa_0088de40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×13, return×4, goto×3.
//  - Notable callees: FUN_00977a30×3, FUN_0088de40.
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

void __fastcall FUN_0088de40(int param_1)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  

  if ((*(int *)(param_1 + 0x5a4) == 0) ||

     (iVar1 = (**(code **)(**(int **)(param_1 + 0x5a4) + 0x1d4))(), iVar1 == 0)) {

    if (*(int *)(param_1 + 0x5f8) != 0) {

      (**(code **)(**(int **)(param_1 + 0x5f8) + 0x268))();

      FUN_00977a30(DAT_00d1ad30,0,0);

    }

    if (*(int *)(param_1 + 0x5fc) == 0) goto LAB_0088df4f;

  }

  else {

    if (*(int *)(param_1 + 0x5f8) != 0) {

      (**(code **)(**(int **)(param_1 + 0x5f8) + 0x268))();

      iVar1 = (**(code **)(**(int **)(param_1 + 0x5a4) + 0x168))();

      FUN_00977a30(DAT_00d1ad30,iVar1,iVar1 >> 0x1f);

    }

    if (*(int *)(param_1 + 0x5fc) == 0) goto LAB_0088df4f;

    if (DAT_00d1b6d8 != 0) {

      uVar2 = (**(code **)(**(int **)(param_1 + 0x5a4) + 0x168))();

      iVar1 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

              (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

      if (((int)uVar2 >> 0x1f <= iVar1) &&

         (((int)uVar2 >> 0x1f < iVar1 ||

          (uVar2 <= *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728))))) {

        (**(code **)(**(int **)(param_1 + 0x5fc) + 0xd4))(1);

        goto LAB_0088df4f;

      }

    }

  }

  (**(code **)(**(int **)(param_1 + 0x5fc) + 0xd4))(0);

LAB_0088df4f:

  if (*(int *)(param_1 + 0x5f8) != 0) {

    (**(code **)(**(int **)(param_1 + 0x5f8) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x5fc) != 0) {

    (**(code **)(**(int **)(param_1 + 0x5fc) + 0x34c))();

  }

  if (DAT_00d1b6d8 == 0) {

    if (*(int *)(param_1 + 0x604) == 0) {

      return;

    }

    (**(code **)(**(int **)(param_1 + 0x604) + 0x268))();

    iVar3 = 0;

    iVar1 = 0;

  }

  else {

    if (*(int *)(param_1 + 0x604) == 0) {

      return;

    }

    (**(code **)(**(int **)(param_1 + 0x604) + 0x268))();

    iVar1 = *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728);

    iVar3 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

            (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

  }

  FUN_00977a30(DAT_00d1ad30,iVar1,iVar3);

  if (*(int *)(param_1 + 0x604) == 0) {

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x0088e007. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(**(int **)(param_1 + 0x604) + 0x34c))();

  return;

}
