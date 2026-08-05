// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00560f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00560f70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00560f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~164 non-empty decompiler lines.
//  - Control keywords: if×20, do×5, while×5, return×1.
//  - Notable callees: FUN_005b3300×3, FUN_0055e760, FUN_0055fa40, FUN_00560f70, FUN_005b3370, FUN_00628f10, FUN_006292a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00560f70(int param_1,int param_2,int *param_3)



{

  uint8_t uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int *piVar7;

  int *piVar8;

  int *unaff_EBX;

  int iVar9;

  int iVar10;

  int local_2c;

  int iStack_28;

  uint8_t local_24 [16];

  int iStack_14;

  int iStack_10;

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  iVar4 = param_2;

  uVar1 = *(uint8_t *)(param_1 + 300);

  *(uint8_t *)(param_1 + 300) = 1;

  FUN_0055e760(param_2);

  FUN_0055fa40(param_2);

  *(uint8_t *)(param_1 + 300) = uVar1;

  iVar2 = *(int *)(param_2 + 0x44);

  local_2c = 0;

  if (0 < param_3[1]) {

    do {

      iVar5 = *param_3;

      iVar9 = local_2c * 4;

      if (*(uint *)(iVar2 + 0x5c) == (*(uint *)(iVar2 + 0x60) & 0x7fffffff)) {

        FUN_005b3370((int *)(iVar2 + 0x58),4);

      }

      *(uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 0x58) + *(int *)(iVar2 + 0x5c) * 4) =

           *(uint32_t /* width from decompiler */ *)(iVar5 + iVar9);

      *(int *)(iVar2 + 0x5c) = *(int *)(iVar2 + 0x5c) + 1;

      (**(code **)(**(int **)(iVar9 + *param_3) + 0x28))(local_24);

      (**(code **)(*unaff_EBX + 8))(*(uint32_t /* width from decompiler */ *)(iVar9 + *param_3),&iStack_28);

      *(int *)(*(int *)(iVar9 + *param_3) + 0x14) = iVar2;

      local_2c = local_2c + 1;

    } while (local_2c < param_3[1]);

  }

  piVar7 = (int *)(param_2 + 0x8c);

  param_2 = 0;

  if (0 < *piVar7) {

    do {

      iVar5 = (**(code **)(**(int **)(*(int *)(iVar4 + 0x88) + param_2 * 4) + 0x20))();

      if (iVar5 != 0xb) {

        iVar5 = *(int *)(*(int *)(iVar4 + 0x88) + param_2 * 4);

        iVar9 = *(int *)(iVar5 + 0xc);

        if ((iVar9 == iVar4) && (iVar5 = *(int *)(iVar5 + 0x10), *(char *)(iVar5 + 0x40) == '\0')) {

          piVar7 = (int *)(param_1 + 0x20);

          iVar9 = *(int *)(param_1 + 0x24) + 1;

          uVar6 = *(uint *)(param_1 + 0x28) & 0x7fffffff;

          if ((int)uVar6 < iVar9) {

            iVar10 = uVar6 * 2;

            if (iVar10 <= iVar9) {

              iVar10 = iVar9;

            }

            FUN_005b3300(piVar7,iVar10,8);

          }

          *(int *)(param_1 + 0x24) = iVar9;

          *(int *)(*piVar7 + -8 + *(int *)(param_1 + 0x24) * 8) = iVar4;

          *(int *)(*piVar7 + -4 + *(int *)(param_1 + 0x24) * 8) = iVar5;

        }

        else if (*(char *)(iVar9 + 0x40) == '\0') {

          piVar7 = (int *)(param_1 + 0x20);

          iVar5 = *(int *)(param_1 + 0x24) + 1;

          uVar6 = *(uint *)(param_1 + 0x28) & 0x7fffffff;

          if ((int)uVar6 < iVar5) {

            iVar10 = uVar6 * 2;

            if (iVar10 <= iVar5) {

              iVar10 = iVar5;

            }

            FUN_005b3300(piVar7,iVar10,8);

          }

          *(int *)(param_1 + 0x24) = iVar5;

          *(int *)(*piVar7 + -8 + *(int *)(param_1 + 0x24) * 8) = iVar4;

          *(int *)(*piVar7 + -4 + *(int *)(param_1 + 0x24) * 8) = iVar9;

        }

      }

      param_2 = param_2 + 1;

    } while (param_2 < *(int *)(iVar4 + 0x8c));

  }

  piVar8 = DAT_00b05060;

  iStack_14 = 0;

  iStack_10 = 0;

  iStack_c = 0x80000000;

  piVar7 = DAT_00b05060 + 3;

  if (*piVar7 < 0x40) {

    iStack_14 = (**(code **)(*DAT_00b05060 + 0x24))(0x40);

  }

  else {

    iStack_14 = DAT_00b05060[2];

    DAT_00b05060[2] = iStack_14 + 0x40;

    piVar8[3] = *piVar7 + -0x40;

  }

  iVar5 = *(int *)(param_1 + 0x2c);

  piVar7 = (int *)(iVar5 + 0x4c);

  iStack_c = -0x7ffffff0;

  iStack_4 = 0x10;

  local_2c = 0;

  iStack_8 = iStack_14;

  if (0 < *(int *)(iVar4 + 0x98)) {

    do {

      iVar9 = *(int *)(iVar5 + 0x50);

      iVar10 = 0;

      if (0 < iVar9) {

        iVar3 = *(int *)(*(int *)(iVar4 + 0x94) + local_2c * 4);

        piVar8 = (int *)*piVar7;

        do {

          if (iVar3 == *piVar8) {

            FUN_006292a0(iVar3);

            FUN_00628f10(*(uint32_t /* width from decompiler */ *)(*piVar7 + iVar10 * 4));

            *(int *)(*(int *)(*(int *)(iVar4 + 0x94) + local_2c * 4) + 0x10) = iVar2;

            break;

          }

          iVar10 = iVar10 + 1;

          piVar8 = piVar8 + 1;

        } while (iVar10 < iVar9);

      }

      (**(code **)(**(int **)(*(int *)(iVar4 + 0x94) + local_2c * 4) + 0x18))(&iStack_14);

      param_3 = (int *)0x0;

      if (0 < iStack_10) {

        do {

          iStack_28 = *(int *)(iStack_14 + (int)param_3 * 4);

          if ((*(char *)(iStack_28 + 0x40) == '\0') && (iStack_28 != iVar4)) {

            piVar8 = (int *)(param_1 + 0x20);

            iVar9 = *(int *)(param_1 + 0x24) + 1;

            uVar6 = *(uint *)(param_1 + 0x28) & 0x7fffffff;

            if ((int)uVar6 < iVar9) {

              iVar10 = uVar6 * 2;

              if (iVar10 <= iVar9) {

                iVar10 = iVar9;

              }

              FUN_005b3300(piVar8,iVar10,8);

            }

            *(int *)(param_1 + 0x24) = iVar9;

            *(int *)(*piVar8 + -8 + *(int *)(param_1 + 0x24) * 8) = iStack_28;

            *(int *)(*piVar8 + -4 + *(int *)(param_1 + 0x24) * 8) = iVar4;

          }

          param_3 = (int *)((int)param_3 + 1);

        } while ((int)param_3 < iStack_10);

      }

      local_2c = local_2c + 1;

    } while (local_2c < *(int *)(iVar4 + 0x98));

  }

  piVar7 = DAT_00b05060;

  uVar6 = iStack_4 * 4 + 0xfU & 0xfffffff0;

  if ((uVar6 == 0) || ((iStack_8 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    DAT_00b05060[2] = DAT_00b05060[2] - uVar6;

    piVar7[3] = piVar7[3] + uVar6;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(iStack_8,uVar6);

  }

  if (-1 < iStack_c) {

    (**(code **)(*DAT_00b05060 + 0x14))(iStack_14,iStack_c * 4,0x12);

  }

  return;

}
