// READABILITY (auto CF):
//  - Body size: ~190 non-empty decompiler lines.
//  - Control keywords: if×14, while×8, do×4, return×3, for×2, goto×1.
//  - Notable callees: CVOGReaction_FailMissionNotify×2, FUN_00402130×2, FUN_004073a0×2, FUN_0053cd30×2, CoTaskMemFree, FUN_00536150, FUN_0053afa0, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 3.

// =============================================================================
// Named_VOG_DEBUG_STOP_00536150
// -----------------------------------------------------------------------------
// Stable ID: aa_00536150
// Address:   0x00536150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_VOG_DEBUG_STOP_00536150(void)



{

  char cVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  uint32_t /* width from decompiler */ *puVar9;

  undefined *puVar10;

  int *piVar11;

  int local_240;

  LPVOID local_23c;

  int *local_238;

  int local_234;

  int *local_230;

  uint32_t /* width from decompiler */ local_22c [2];

  void *local_224;

  uint32_t /* width from decompiler */ local_220;

  uint32_t /* width from decompiler */ local_21c;

  int local_218 [4];

  int local_208;

  int local_204;

  int local_200;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  puStack_10 = &LAB_009a3cfa;

  local_14 = ExceptionList;

  iVar7 = 0;

  local_234 = 0;

  local_23c = (LPVOID)0x0;

  local_224 = (void *)0x0;

  local_220 = 0;

  local_21c = 0;

  local_c = 0;

  ExceptionList = &local_14;

  iVar3 = FUN_007c53d0(&local_234,&local_23c);

  if (iVar3 < 0) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    ExceptionList = local_14;

    return;

  }

  if (0 < local_234) {

    iVar3 = 0;

    do {

      puVar9 = (uint32_t /* width from decompiler */ *)((int)local_23c + iVar3);

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_0053afa0(puVar9);

      for (iVar6 = 0x7f; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar4 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar4 = puVar4 + 1;

      }

      if (*(int *)((int)local_23c + iVar3 + 4) == -1) {

        puVar10 = &DAT_00b045bc;

        do {

          local_22c[0] = *(uint32_t /* width from decompiler */ *)((int)local_23c + iVar3);

          FUN_00402130(3);

          FUN_0053cd30(local_22c);

          puVar10 = puVar10 + 0x10;

        } while ((int)puVar10 < 0xb045ec);

      }

      else {

        local_22c[0] = *(uint32_t /* width from decompiler */ *)((int)local_23c + iVar3);

        FUN_00402130(3);

        FUN_0053cd30(local_22c);

      }

      iVar7 = iVar7 + 1;

      iVar3 = iVar3 + 0x1fc;

    } while (iVar7 < local_234);

    local_238 = (int *)*DAT_00b045b4;

    if (local_238 != DAT_00b045b4) {

      do {

        piVar5 = local_238 + 4;

        piVar11 = local_218;

        for (iVar3 = 0x7f; iVar6 = local_218[1], iVar7 = local_218[0], iVar3 != 0;

            iVar3 = iVar3 + -1) {

          *piVar11 = *piVar5;

          piVar5 = piVar5 + 1;

          piVar11 = piVar11 + 1;

        }

        if (local_218[1] == -1) {

          local_230 = &DAT_00b045c0;

          do {

            local_240 = 0;

            uVar8 = 0;

            while ((DAT_00b045b0 != 0 && (uVar8 < (uint)(((int)DAT_00b045b4 - DAT_00b045b0) / 0x14))

                   )) {

              iVar3 = *(int *)(local_240 + *local_230);

              iVar6 = local_240 + *local_230;

              if ((iVar3 == local_218[2]) ||

                 ((((iVar3 == local_218[3] || (iVar3 == local_208)) || (iVar3 == local_204)) ||

                  (iVar3 == local_200)))) {

                iVar3 = *(int *)(iVar6 + 8);

                if ((iVar3 == 0) ||

                   ((uint)(*(int *)(iVar6 + 0x10) - iVar3 >> 2) <=

                    (uint)(*(int *)(iVar6 + 0xc) - iVar3 >> 2))) {

                  FUN_004073a0(*(uint32_t /* width from decompiler */ *)(iVar6 + 0xc),1,local_218);

                  goto LAB_00536376;

                }

                piVar5 = *(int **)(iVar6 + 0xc);

                *piVar5 = iVar7;

                uVar8 = uVar8 + 1;

                local_240 = local_240 + 0x14;

                *(int **)(iVar6 + 0xc) = piVar5 + 1;

              }

              else {

LAB_00536376:

                uVar8 = uVar8 + 1;

                local_240 = local_240 + 0x14;

              }

            }

            local_230 = local_230 + 4;

          } while ((int)local_230 < 0xb045f0);

        }

        else {

          uVar8 = 0;

          iVar3 = local_218[1] * 0x10;

          local_240 = 0;

          while (((&DAT_00b045c0)[iVar6 * 4] != 0 &&

                 (uVar8 < (uint)((*(int *)(&DAT_00b045c4 + iVar3) - (&DAT_00b045c0)[iVar6 * 4]) /

                                0x14)))) {

            piVar5 = (int *)((&DAT_00b045c0)[iVar6 * 4] + local_240);

            iVar2 = *piVar5;

            if ((iVar2 == local_218[2]) || ((iVar2 == local_218[3] || (iVar2 == local_208)))) {

              iVar2 = piVar5[2];

              if ((iVar2 == 0) || ((uint)(piVar5[4] - iVar2 >> 2) <= (uint)(piVar5[3] - iVar2 >> 2))

                 ) {

                FUN_004073a0(piVar5[3],1,local_218);

                uVar8 = uVar8 + 1;

                local_240 = local_240 + 0x14;

              }

              else {

                piVar11 = (int *)piVar5[3];

                *piVar11 = iVar7;

                uVar8 = uVar8 + 1;

                local_240 = local_240 + 0x14;

                piVar5[3] = (int)(piVar11 + 1);

              }

            }

            else if (iVar2 == local_204) {

              CVOGReaction_FailMissionNotify(local_218);

              uVar8 = uVar8 + 1;

              local_240 = local_240 + 0x14;

            }

            else {

              if (iVar2 == local_200) {

                CVOGReaction_FailMissionNotify(local_218);

              }

              uVar8 = uVar8 + 1;

              local_240 = local_240 + 0x14;

            }

          }

        }

        if (*(char *)((int)local_238 + 0x20d) == '\0') {

          piVar5 = (int *)local_238[2];

          if (*(char *)((int)piVar5 + 0x20d) == '\0') {

            cVar1 = *(char *)(*piVar5 + 0x20d);

            local_238 = piVar5;

            piVar5 = (int *)*piVar5;

            while (cVar1 == '\0') {

              cVar1 = *(char *)(*piVar5 + 0x20d);

              local_238 = piVar5;

              piVar5 = (int *)*piVar5;

            }

          }

          else {

            cVar1 = *(char *)(local_238[1] + 0x20d);

            piVar11 = (int *)local_238[1];

            piVar5 = local_238;

            while ((local_238 = piVar11, cVar1 == '\0' && (piVar5 == (int *)local_238[2]))) {

              cVar1 = *(char *)(local_238[1] + 0x20d);

              piVar11 = (int *)local_238[1];

              piVar5 = local_238;

            }

          }

        }

      } while (local_238 != DAT_00b045b4);

    }

    CoTaskMemFree(local_23c);

    if (local_224 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_224);

    }

  }

  ExceptionList = local_14;

  return;

}
