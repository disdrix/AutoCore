// =============================================================================
// Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_0052e1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052e1d0
// Callee of Skill_You_do_not_possess_the_Tinkering_skill_to_work_o
// Address:   0x0052e1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_You_do_not_possess_the_Tinkering_skill_to: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~241 non-empty decompiler lines.
//  - Control keywords: if×37, do×7, while×7, goto×6, return×3.
//  - Notable callees: FUN_004f1e20×4, FUN_005206d0×4, FUN_00599dd0×3, ceil×3, ROUND×2, CONCAT22, FUN_00404d70, FUN_004ce940.
//  - Return sites: 3.

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



int __thiscall Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_0052e1d0(int param_1,int *param_2)



{

  float fVar1;

  uint16_t uVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  int unaff_EBX;

  int iVar7;

  uint uVar8;

  int *piVar9;

  uint16_t in_FPUControlWord;

  double dVar10;

  int *unaff_retaddr;

  int local_34;

  int local_30;

  int aiStack_18 [6];

  

  iVar7 = 0;

  if (((param_2 == (int *)0x0) || (iVar3 = FUN_00599dd0(), iVar3 < 1)) ||

     (0 < *(int *)(param_1 + 0x6b4))) {

    return 0;

  }

  FUN_004ce940();

  local_30 = 0;

  aiStack_18[1] = 0xffffffff;

  aiStack_18[2] = 0xffffffff;

  aiStack_18[3] = 0xffffffff;

  aiStack_18[4] = 0xffffffff;

  aiStack_18[5] = 0xffffffff;

  iVar3 = FUN_00599dd0();

  if (0 < iVar3) {

    iVar3 = 0x498;

    do {

      uVar8 = *(uint *)(*(int *)(param_2[0x2a] + 0x3c) + iVar3);

      if (uVar8 == 0xffffffff) {

        uVar4 = 0;

      }

      else {

        iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                                 (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & uVar8) * 4) + 4);

        if (iVar5 == 0) {

LAB_0052e297:

          iVar5 = 0;

        }

        else {

          do {

            if (uVar8 == *(uint *)(iVar5 + 0x10)) {

              if (iVar5 == 0) goto LAB_0052e297;

              iVar5 = *(int *)(iVar5 + 8);

              goto LAB_0052e29e;

            }

            iVar5 = *(int *)(iVar5 + 0xc);

          } while (iVar5 != 0);

          iVar5 = 0;

        }

LAB_0052e29e:

        if (iVar5 == 0) {

          uVar4 = 0;

        }

        else {

          if (*(int *)(iVar5 + 0x3c) == 0) {

            FUN_004f1e20(1,1);

          }

          if (*(int *)(iVar5 + 0x38) == 0x1a) {

            if (*(int *)(iVar5 + 0x3c) == 0) {

              uVar4 = 0;

            }

            else {

              uVar4 = (uint)*(byte *)(*(int *)(iVar5 + 0x3c) + 0x4c8);

            }

          }

          else {

            uVar4 = 0;

          }

        }

      }

      if (uVar4 == 1 || (int)(uVar4 - 1) < 0) {

        iVar5 = 0;

      }

      else if (uVar8 == 0xffffffff) {

        iVar5 = -1;

      }

      else {

        iVar5 = FUN_00404d70(uVar8);

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

      local_30 = local_30 + iVar5;

      iVar7 = iVar7 + 1;

      iVar3 = iVar3 + 4;

      iVar5 = FUN_00599dd0();

    } while (iVar7 < iVar5);

  }

  iVar7 = local_30;

  dVar10 = ceil((double)((float)local_30 * _DAT_009cdff4));

  uVar8 = 0;

  local_34 = (int)ROUND(dVar10);

  iVar3 = (**(code **)(*param_2 + 0x60))();

  if (iVar3 != 0) {

    do {

      iVar3 = 0;

      (**(code **)(*param_2 + 0x5c))(uVar8);

      do {

        uVar2 = (**(code **)(*param_2 + 0x5c))(uVar8);

        iVar5 = FUN_005097b0(uVar2);

        if ((iVar5 != 0) && (uVar4 = *(uint *)(iVar5 + iVar3), uVar4 != 0xffffffff)) {

          iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                                   (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & uVar4) * 4) + 4)

          ;

          if (iVar5 == 0) {

LAB_0052e42b:

            iVar5 = 0;

          }

          else {

            do {

              if (uVar4 == *(uint *)(iVar5 + 0x10)) {

                if (iVar5 == 0) goto LAB_0052e42b;

                iVar5 = *(int *)(iVar5 + 8);

                goto LAB_0052e432;

              }

              iVar5 = *(int *)(iVar5 + 0xc);

            } while (iVar5 != 0);

            iVar5 = 0;

          }

LAB_0052e432:

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

          if (uVar6 == 1 || (int)(uVar6 - 1) < 0) {

            iVar5 = 0;

          }

          else {

            iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                                     (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & uVar4) * 4) +

                            4);

            if (iVar5 == 0) {

LAB_0052e4a4:

              iVar5 = 0;

            }

            else {

              do {

                if (uVar4 == *(uint *)(iVar5 + 0x10)) {

                  if (iVar5 == 0) goto LAB_0052e4a4;

                  iVar5 = *(int *)(iVar5 + 8);

                  goto LAB_0052e4ab;

                }

                iVar5 = *(int *)(iVar5 + 0xc);

              } while (iVar5 != 0);

              iVar5 = 0;

            }

LAB_0052e4ab:

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

          unaff_EBX = unaff_EBX + iVar5;

          param_2 = unaff_retaddr;

        }

        iVar3 = iVar3 + 4;

      } while (iVar3 < 0x14);

      local_30 = local_30 + unaff_EBX;

      fVar1 = (float)unaff_EBX * _DAT_009cdff4;

      aiStack_18[uVar8] = unaff_EBX;

      dVar10 = ceil((double)fVar1);

      if (0 < (int)ROUND(dVar10)) {

        ceil((double)fVar1);

      }

      unaff_EBX = CONCAT22((short)((uint)unaff_EBX >> 0x10),in_FPUControlWord);

      uVar8 = uVar8 + 1;

      uVar4 = (**(code **)(*param_2 + 0x60))();

    } while (uVar8 < uVar4);

  }

  if (iVar7 != 0) {

    if ((local_30 != -1) && (iVar7 = FUN_005206d0(uVar8,local_30), local_34 < iVar7)) {

      local_34 = FUN_005206d0(uVar8,local_30);

    }

    iVar7 = 1;

    piVar9 = aiStack_18;

    do {

      piVar9 = piVar9 + 1;

      iVar3 = *piVar9;

      if ((iVar3 != -1) && (iVar5 = FUN_005206d0(iVar7,iVar3), local_34 < iVar5)) {

        local_34 = FUN_005206d0(iVar7,iVar3);

      }

      iVar7 = iVar7 + 1;

    } while (iVar7 < 6);

    return local_34;

  }

  return 0;

}
