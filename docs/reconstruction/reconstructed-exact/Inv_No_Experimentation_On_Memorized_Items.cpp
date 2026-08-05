// READABILITY (auto CF):
//  - Body size: ~131 non-empty decompiler lines.
//  - Control keywords: if×14, do×4, while×4, return×2, goto×1.
//  - Notable callees: FUN_007a69d0×3, FUN_007a6de0×3, sprintf×2, FUN_005202d0, FUN_008e3f20, FUN_008e4b40.
//  - Strings: "Enhancement"; "%s %d:"; "Requires Experimention Rank"; "(%s %d)".
//  - Return sites: 2.

// =============================================================================
// Inv_No_Experimentation_On_Memorized_Items
// -----------------------------------------------------------------------------
// Stable ID: aa_008e4b40
// Address:   0x008e4b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "(No Experimentation On Memorized Items)"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Inv_No_Experimentation_On_Memorized_Items(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ uVar8;

  char *local_118;

  int iStack_114;

  int iStack_110;

  uint32_t /* width from decompiler */ *puStack_10c;

  char acStack_100 [128];

  char acStack_80 [128];

  

  if (*(int *)(param_1 + 0x7cc) == 0) {

    puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5b8);

    puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x550);

    local_118 = (char *)0x5;

    do {

      (**(code **)(*(int *)puVar2[-7] + 4))(0);

      (**(code **)(*(int *)*puVar2 + 4))(0);

      iVar5 = 5;

      do {

        (**(code **)(*(int *)*puVar3 + 4))(0);

        puVar3 = puVar3 + 1;

        iVar5 = iVar5 + -1;

      } while (iVar5 != 0);

      puVar2 = puVar2 + 1;

      local_118 = (char *)((int)local_118 + -1);

    } while (local_118 != (char *)0x0);

    if (*(int *)(param_1 + 0x768) != 0) {

      (**(code **)(**(int **)(param_1 + 0x768) + 4))(0);

    }

    if (*(int *)(param_1 + 0x76c) != 0) {

      (**(code **)(**(int **)(param_1 + 0x76c) + 4))(0);

      return;

    }

  }

  else {

    uVar4 = (uint)*(byte *)(*(int *)((*(int **)(param_1 + 0x7cc))[0x2a] + 0x3c) + 0x409);

    iVar5 = (**(code **)(**(int **)(param_1 + 0x7cc) + 0x60))();

    local_118 = (char *)(param_1 + 0x7db);

    puStack_10c = (uint32_t /* width from decompiler */ *)(param_1 + 0x5b8);

    iStack_114 = 0;

    iStack_110 = 0;

    puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x550);

    do {

      if (iStack_114 < (int)uVar4) {

        if (iStack_114 < iVar5) {

LAB_008e4d4d:

          iVar6 = 0;

          puVar2 = puStack_10c;

          do {

            if ((*(char *)(param_1 + 0x7e2) == '\0') ||

               (((*(int *)(param_1 + 0x61c + (iStack_110 + iVar6) * 4) == 0 && (iVar6 != 0)) &&

                (*(int *)(param_1 + 0x618 + (iStack_110 + iVar6) * 4) == 0)))) {

              (**(code **)(*(int *)*puVar2 + 4))(0);

            }

            else {

              (**(code **)(*(int *)*puVar2 + 4))(1);

              if (*(int *)(param_1 + 0x61c + (iStack_110 + iVar6) * 4) == 0) {

                if (*local_118 == '\0') {

                  FUN_008e3f20(param_1,*puVar2);

                  (**(code **)(*(int *)*puVar2 + 0x34c))();

                }

                else {

                  (**(code **)(*(int *)*puVar2 + 4))(0);

                }

              }

            }

            iVar6 = iVar6 + 1;

            puVar2 = puVar2 + 1;

          } while (iVar6 < 5);

        }

        else {

          iVar6 = *(int *)(param_1 + 0x7cc);

          if ((iVar6 == 0) ||

             (cVar1 = FUN_005202d0(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x160),*(uint32_t /* width from decompiler */ *)(iVar6 + 0x164)),

             cVar1 == '\0')) {

            if (iStack_114 < (int)(uint)*(byte *)(DAT_00d1b6d8 + 0x599)) {

              uVar8 = 0xffffffff;

              pcVar7 = "Enhancement";

              FUN_007a69d0("Enhancement",0xffffffff,iStack_114 + 1);

              uVar8 = FUN_007a6de0(pcVar7,uVar8);

              sprintf(acStack_80,"%s %d:",uVar8);

              (**(code **)(*(int *)*puVar3 + 0x1d8))(acStack_80,1,1);

              (**(code **)(*(int *)*puVar3 + 0x34c))();

              goto LAB_008e4d4d;

            }

            uVar8 = 0xffffffff;

            pcVar7 = "Requires Experimention Rank";

            FUN_007a69d0("Requires Experimention Rank",0xffffffff,iStack_114 + 1);

            uVar8 = FUN_007a6de0(pcVar7,uVar8);

            sprintf(acStack_100,"(%s %d)",uVar8);

            (**(code **)(*(int *)*puVar3 + 0x1d8))(acStack_100,1,1);

            (**(code **)(*(int *)*puVar3 + 0x34c))();

          }

          else {

            iVar6 = *(int *)*puVar3;

            uVar8 = 0xffffffff;

            pcVar7 = "(No Experimentation On Memorized Items)";

            FUN_007a69d0("(No Experimentation On Memorized Items)",0xffffffff,1,1);

            uVar8 = FUN_007a6de0(pcVar7,uVar8);

            (**(code **)(iVar6 + 0x1d8))(uVar8);

            (**(code **)(*(int *)*puVar3 + 0x34c))();

          }

        }

        if (*(char *)(param_1 + 0x7e2) != '\0') {

          (**(code **)(*(int *)puVar3[-7] + 4))(1);

          (**(code **)(*(int *)*puVar3 + 4))(1);

        }

      }

      puStack_10c = puStack_10c + 5;

      local_118 = local_118 + 1;

      iStack_110 = iStack_110 + 5;

      iStack_114 = iStack_114 + 1;

      puVar3 = puVar3 + 1;

    } while (iStack_110 < 0x19);

    if ((*(char *)(param_1 + 0x7e2) != '\0') && (uVar4 != 0)) {

      if (*(int *)(param_1 + 0x768) != 0) {

        (**(code **)(**(int **)(param_1 + 0x768) + 4))(1);

      }

      if (*(int *)(param_1 + 0x76c) != 0) {

        (**(code **)(**(int **)(param_1 + 0x76c) + 4))(1);

      }

    }

  }

  return;

}
