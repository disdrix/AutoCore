// =============================================================================
// FUN_00902980
// -----------------------------------------------------------------------------
// Stable ID: aa_00902980
// Address:   0x00902980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00902980 @ 0x00902980
// Stable ID: aa_00902980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×16, do×2, while×2, goto×1, return×1.
//  - Notable callees: FUN_00907910×2, FUN_007906a0, FUN_007a4e70, FUN_00902980, FUN_009071b0, GetTickCount, __alldiv, block.
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

/* WARNING: Removing unreachable block (ram,0x00902b65) */



void __thiscall FUN_00902980(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  longlong *plVar1;

  int iVar2;

  longlong lVar3;

  char cVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  DWORD DVar8;

  int iVar9;

  longlong lVar10;

  int local_44;

  int iStack_40;

  uint8_t local_38 [4];

  uint8_t auStack_34 [4];

  uint8_t auStack_30 [16];

  uint8_t auStack_20 [4];

  uint8_t auStack_1c [4];

  uint8_t auStack_18 [20];

  

  iVar9 = 0;

  local_44 = -1;

  if (0 < *(int *)(param_1 + 0x524)) {

    do {

      if ((*(int *)(*(int *)(param_1 + 0x56c) + iVar9 * 4) != 0) &&

         (iVar5 = (**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar9 * 4) + 0x120))

                            (local_38,1,1), *(int *)(iVar5 + 4) < DAT_00d1d870)) {

        piVar6 = *(int **)(*(int *)(param_1 + 0x56c) + iVar9 * 4);

        (**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar9 * 4) + 0x120))(auStack_30,1,1);

        iVar5 = (**(code **)(*piVar6 + 0x140))(auStack_34,1);

        if ((DAT_00d1d870 < *(int *)(iStack_40 + 4) + *(int *)(iVar5 + 4)) &&

           (piVar6 = (int *)(**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar9 * 4) + 0x120))

                                      (auStack_20,1,1), *piVar6 < DAT_00d1d86c)) {

          piVar6 = (int *)(**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar9 * 4) + 0x120))

                                    (auStack_18,1,1);

          piVar7 = (int *)(**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar9 * 4) + 0x140))

                                    (auStack_1c,1);

          if (DAT_00d1d86c < *piVar7 + *piVar6) {

            local_44 = iVar9;

          }

        }

      }

      iVar9 = iVar9 + 1;

    } while (iVar9 < *(int *)(param_1 + 0x524));

  }

  iVar9 = 0;

  if (0 < *(int *)(param_1 + 0x524)) {

    do {

      if (*(int *)(*(int *)(param_1 + 0x56c) + iVar9 * 4) != 0) {

        cVar4 = (**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar9 * 4) + 0x3bc))();

        if (iVar9 == local_44) {

          if (cVar4 == '\0') {

            (**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar9 * 4) + 0x3c8))(1,1);

            (**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar9 * 4) + 0x34c))();

            if ((*(int *)(param_1 + 0x50c) != 0) && (iVar5 = *(int *)(param_1 + 0x570), iVar5 != 0))

            {

              iVar2 = *(int *)(iVar5 + iVar9 * 8);

              iVar5 = *(int *)(iVar5 + 4 + iVar9 * 8);

              if ((iVar2 != 0 || iVar5 != 0) && (iVar5 = FUN_007a4e70(iVar2,iVar5), iVar5 != 0)) {

                iVar2 = *(int *)(iVar5 + 0x1e8);

                lVar3 = *(longlong *)(iVar5 + 0x1e8);

                if (iVar2 == 0 && *(int *)(iVar5 + 0x1ec) == 0) {

                  plVar1 = (longlong *)(iVar5 + 0x230);

                  if ((*(int *)(iVar5 + 0x234) < 0) ||

                     ((lVar3 = *plVar1, *(int *)(iVar5 + 0x234) < 1 &&

                      (lVar3 = *plVar1, *(int *)plVar1 == 0)))) goto LAB_00902ba0;

                }

                else {

                  lVar10 = __alldiv(iVar2,*(int *)(iVar5 + 0x1ec),10,0);

                  if (lVar10 < 2) {

                    lVar10 = 1;

                  }

                  lVar3 = lVar10 + lVar3;

                }

                FUN_009071b0(lVar3);

              }

            }

          }

LAB_00902ba0:

          *(int *)(param_1 + 0x534) = iVar9;

        }

        else if ((cVar4 == '\x01') && (local_44 != -1)) {

          (**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar9 * 4) + 0x3c8))(0,1);

          (**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar9 * 4) + 0x34c))();

        }

      }

      iVar9 = iVar9 + 1;

    } while (iVar9 < *(int *)(param_1 + 0x524));

  }

  if (local_44 == -1) {

    FUN_00907910(1);

  }

  iVar9 = *(int *)(param_1 + 0x50c);

  DVar8 = GetTickCount();

  if (3999 < DVar8 - *(int *)(iVar9 + 0x510)) {

    FUN_00907910(0);

  }

  FUN_007906a0(param_2,param_3);

  return;

}
