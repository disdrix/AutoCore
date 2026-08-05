// =============================================================================
// Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_0052e640
// -----------------------------------------------------------------------------
// Stable ID: aa_0052e640
// Callee of Skill_You_do_not_possess_the_Tinkering_skill_to_work_o
// Address:   0x0052e640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_You_do_not_possess_the_Tinkering_skill_to: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~285 non-empty decompiler lines.
//  - Control keywords: if×44, do×7, goto×7, while×7, return×5, switch×1.
//  - Notable callees: FUN_004f1e20×4, FUN_00599dd0×3, FUN_00520520×2, FUN_00404d70, FUN_004ce940, FUN_005097b0, FUN_00522950, FUN_0052e640.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Skill_You_do_not_possess_the_Tinkering_skill_to_work_o
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 __thiscall Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_0052e640(int param_1,int *param_2)



{

  float fVar1;

  uint uVar2;

  char cVar3;

  uint16_t uVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  int iVar8;

  int unaff_EBX;

  int iVar9;

  int *piVar10;

  float fVar11;

  double dVar12;

  int *unaff_retaddr;

  float local_a4;

  float local_94;

  float local_90 [10];

  uint auStack_68 [26];

  

  iVar9 = 0;

  if (((param_2 != (int *)0x0) && (local_90[0] = (float)FUN_004ce940(), local_90[0] != 0.0)) &&

     (iVar5 = FUN_00599dd0(), 0 < iVar5)) {

    if (0 < *(int *)(param_1 + 0x6b4)) {

      return (float10)g_flOne;

    }

    cVar3 = FUN_00522950(param_2);

    if (cVar3 != '\0') {

      local_90[1] = -NAN;

      local_90[2] = -NAN;

      local_90[3] = -NAN;

      local_90[4] = -NAN;

      local_90[5] = -NAN;

      local_a4 = 0.0;

      local_94 = 0.0;

      iVar5 = FUN_00599dd0();

      if (0 < iVar5) {

        do {

          fVar1 = *(float *)(*(int *)(param_2[0x2a] + 0x3c) + iVar9 * 4 + 0x498);

          if (fVar1 == -NAN) {

            uVar6 = 0;

          }

          else {

            iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                                     (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & (uint)fVar1) *

                                     4) + 4);

            if (iVar5 == 0) {

LAB_0052e764:

              iVar5 = 0;

            }

            else {

              do {

                if (fVar1 == *(float *)(iVar5 + 0x10)) {

                  if (iVar5 == 0) goto LAB_0052e764;

                  iVar5 = *(int *)(iVar5 + 8);

                  goto LAB_0052e76b;

                }

                iVar5 = *(int *)(iVar5 + 0xc);

              } while (iVar5 != 0);

              iVar5 = 0;

            }

LAB_0052e76b:

            if (iVar5 == 0) {

              uVar6 = 0;

            }

            else {

              if (*(int *)(iVar5 + 0x3c) == 0) {

                FUN_004f1e20(1,1);

              }

              if (*(int *)(iVar5 + 0x38) == 0x1a) {

                if (*(int *)(iVar5 + 0x3c) == 0) {

                  uVar6 = 0;

                }

                else {

                  uVar6 = (uint)*(byte *)(*(int *)(iVar5 + 0x3c) + 0x4c8);

                }

              }

              else {

                uVar6 = 0;

              }

            }

          }

          if (uVar6 == 1 || (int)(uVar6 - 1) < 0) {

            iVar5 = 0;

          }

          else if (fVar1 == -NAN) {

            iVar5 = -1;

          }

          else {

            iVar5 = FUN_00404d70();

            if (iVar5 == 0) {

              iVar5 = -1;

            }

            else {

              if (*(int *)(iVar5 + 0x3c) == 0) {

                FUN_004f1e20(1,1);

              }

              if (*(int *)(iVar5 + 0x38) == 0x1a) {

                if (*(int *)(iVar5 + 0x3c) == 0) {

                  iVar5 = -1;

                }

                else {

                  iVar5 = *(byte *)(*(int *)(iVar5 + 0x3c) + 0x4c8) - 1;

                }

              }

              else {

                iVar5 = -1;

              }

            }

          }

          local_94 = (float)((int)local_94 + iVar5);

          local_90[iVar9 + 6] = fVar1;

          iVar9 = iVar9 + 1;

          iVar5 = FUN_00599dd0();

        } while (iVar9 < iVar5);

      }

      dVar12 = floor((double)((float)*(byte *)(param_1 + 0x598) * _DAT_009da8a4));

      if ((int)local_94 <= (int)ROUND(dVar12)) {

        uVar6 = 0;

        iVar9 = (**(code **)(*param_2 + 0x60))();

        if (iVar9 != 0) {

          do {

            iVar9 = 0;

            (**(code **)(*param_2 + 0x5c))();

            piVar10 = param_2;

            do {

              uVar4 = (**(code **)(*piVar10 + 0x5c))(uVar6);

              iVar5 = FUN_005097b0(uVar4);

              if ((iVar5 != 0) && (uVar2 = *(uint *)(iVar5 + iVar9 * 4), uVar2 != 0xffffffff)) {

                iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                                         (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & uVar2) * 4

                                         ) + 4);

                if (iVar5 == 0) {

LAB_0052e924:

                  iVar5 = 0;

                }

                else {

                  do {

                    if (uVar2 == *(uint *)(iVar5 + 0x10)) {

                      if (iVar5 == 0) goto LAB_0052e924;

                      iVar5 = *(int *)(iVar5 + 8);

                      goto LAB_0052e92b;

                    }

                    iVar5 = *(int *)(iVar5 + 0xc);

                  } while (iVar5 != 0);

                  iVar5 = 0;

                }

LAB_0052e92b:

                if (iVar5 == 0) {

                  uVar7 = 0;

                }

                else {

                  if (*(int *)(iVar5 + 0x3c) == 0) {

                    FUN_004f1e20(1,1);

                  }

                  if (*(int *)(iVar5 + 0x38) == 0x1a) {

                    if (*(int *)(iVar5 + 0x3c) == 0) {

                      uVar7 = 0;

                    }

                    else {

                      uVar7 = (uint)*(byte *)(*(int *)(iVar5 + 0x3c) + 0x4c8);

                    }

                  }

                  else {

                    uVar7 = 0;

                  }

                }

                if (uVar7 == 1 || (int)(uVar7 - 1) < 0) {

                  iVar5 = 0;

                }

                else {

                  iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                                           (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & uVar2) *

                                           4) + 4);

                  if (iVar5 == 0) {

LAB_0052e9a4:

                    iVar5 = 0;

                  }

                  else {

                    do {

                      if (uVar2 == *(uint *)(iVar5 + 0x10)) {

                        if (iVar5 == 0) goto LAB_0052e9a4;

                        iVar5 = *(int *)(iVar5 + 8);

                        goto LAB_0052e9ab;

                      }

                      iVar5 = *(int *)(iVar5 + 0xc);

                    } while (iVar5 != 0);

                    iVar5 = 0;

                  }

LAB_0052e9ab:

                  if (iVar5 == 0) {

                    iVar5 = -1;

                  }

                  else {

                    if (*(int *)(iVar5 + 0x3c) == 0) {

                      FUN_004f1e20(1,1);

                    }

                    if (*(int *)(iVar5 + 0x38) == 0x1a) {

                      if (*(int *)(iVar5 + 0x3c) == 0) {

                        iVar5 = -1;

                      }

                      else {

                        iVar5 = *(byte *)(*(int *)(iVar5 + 0x3c) + 0x4c8) - 1;

                      }

                    }

                    else {

                      iVar5 = -1;

                    }

                  }

                }

                local_a4 = (float)((int)local_a4 + iVar5);

                auStack_68[unaff_EBX + iVar9] = uVar2;

                piVar10 = unaff_retaddr;

              }

              iVar9 = iVar9 + 1;

            } while (iVar9 < 5);

            uVar2 = uVar6 + 1;

            local_90[uVar6] = local_a4;

            iVar9 = FUN_00520520();

            if (iVar9 < (int)local_a4) goto LAB_0052e883;

            unaff_EBX = unaff_EBX + 5;

            uVar7 = (**(code **)(*unaff_retaddr + 0x60))();

            uVar6 = uVar2;

          } while (uVar2 < uVar7);

        }

        if (local_94 == 0.0) {

          return (float10)DAT_00aaa7ac;

        }

        iVar9 = 0;

        do {

          fVar1 = local_94;

          if (iVar9 != 0) {

            fVar1 = local_90[iVar9];

          }

          fVar11 = local_a4;

          if (fVar1 != -NAN) {

            iVar5 = FUN_00520520();

            iVar8 = 0;

            if (iVar5 - (int)fVar1 < 0) break;

            fVar11 = 0.0;

            switch(iVar9) {

            case 0:

            case 1:

              iVar8 = 0x32;

              fVar11 = DAT_00aaa6c4;

              break;

            case 2:

              iVar8 = 0x28;

              fVar11 = g_flLevelUpUiBase_Inferred;

              break;

            case 3:

              iVar8 = 0x1e;

              fVar11 = DAT_00aaa68c;

              break;

            case 4:

              iVar8 = 0x14;

              fVar11 = g_flOne;

              break;

            case 5:

              iVar8 = 10;

              fVar11 = DAT_00a0f298;

            }

            fVar11 = ((float)(iVar8 + (iVar5 - (int)fVar1) * 2) +

                     (float)*(byte *)(param_1 + 0x598) * fVar11) * DAT_00a0f718;

            if (local_a4 != 0.0) {

              fVar11 = fVar11 * local_a4;

            }

          }

          local_a4 = fVar11;

          iVar9 = iVar9 + 1;

          if (5 < iVar9) {

            if (g_flInferredThreatScale < local_a4) {

              local_a4 = g_flInferredThreatScale;

            }

            return (float10)local_a4;

          }

        } while( true );

      }

LAB_0052e883:

      return (float10)g_flZero;

    }

  }

  return (float10)g_flZero;

}
