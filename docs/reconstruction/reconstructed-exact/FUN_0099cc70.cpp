// =============================================================================
// FUN_0099cc70
// -----------------------------------------------------------------------------
// Stable ID: aa_0099cc70
// Address:   0x0099cc70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099cc70 @ 0x0099cc70
// Stable ID: aa_0099cc70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×9, while×2, do×1, return×1, goto×1.
//  - Notable callees: FUN_00755890, FUN_0099cc70.
//  - Return sites: 1.

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

void FUN_0099cc70(int param_1,int *param_2,ushort *param_3)



{

  int *piVar1;

  ushort uVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  void **ppvVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b19ec;

  iVar3 = *(int *)(param_1 + 0x10);

  uVar2 = *param_3;

  iVar8 = 0;

  piVar9 = (int *)0x0;

  ppvVar6 = &local_c;

  local_c = ExceptionList;

  do {

    ExceptionList = ppvVar6;

    if (uVar2 == 0) {

      *param_2 = iVar8;

      param_2[1] = iVar3;

      ExceptionList = local_c;

      return;

    }

    param_3 = param_3 + 1;

    if (((piVar9 == (int *)0x0) || (uVar2 < *(ushort *)(piVar9 + 1))) ||

       (*(ushort *)((int)piVar9 + 6) < uVar2)) {

      piVar9 = *(int **)(param_1 + 4);

      iVar7 = (int)*(int **)(param_1 + 8) - (int)piVar9 >> 3;

      while (iVar5 = iVar7, 0 < iVar5) {

        iVar7 = iVar5 / 2;

        if (*(ushort *)((int)piVar9 + iVar7 * 8 + 6) < uVar2) {

          piVar9 = piVar9 + iVar7 * 2 + 2;

          iVar7 = iVar5 + (-1 - iVar7);

        }

      }

      if (((piVar9 != *(int **)(param_1 + 8)) && (*(ushort *)(piVar9 + 1) <= uVar2)) &&

         (uVar2 <= *(ushort *)((int)piVar9 + 6))) goto LAB_0099cd0c;

      piVar9 = (int *)0x0;

    }

    else {

LAB_0099cd0c:

      if (piVar9 != (int *)0x0) {

        piVar4 = (int *)*piVar9;

        if ((piVar4 != (int *)0x0) && (piVar4[1] = piVar4[1] + 1, piVar4[1] == 1)) {

          (**(code **)(*piVar4 + 4))();

        }

        piVar4 = (int *)*piVar9;

        local_4 = 0;

        if ((uVar2 < *(ushort *)(piVar4 + 0x22)) || (*(ushort *)((int)piVar4 + 0x8a) < uVar2)) {

          local_4 = 0xffffffff;

          piVar1 = piVar4 + 1;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 == 0) {

            (**(code **)(*piVar4 + 8))();

          }

        }

        else {

          iVar7 = FUN_00755890(uVar2);

          iVar8 = iVar8 + *(int *)(iVar7 + 0x18);

          local_4 = 0xffffffff;

          piVar1 = piVar4 + 1;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 == 0) {

            (**(code **)(*piVar4 + 8))();

          }

        }

      }

    }

    uVar2 = *param_3;

    ppvVar6 = ExceptionList;

  } while( true );

}
