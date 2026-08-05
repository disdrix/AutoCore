// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_0052d450
// -----------------------------------------------------------------------------
// Stable ID: aa_0052d450
// Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
// Address:   0x0052d450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RefreshOpenMissionUiWindows: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~219 non-empty decompiler lines.
//  - Control keywords: if×25, while×8, do×6, return×5, goto×5.
//  - Notable callees: FUN_005190c0×10, FUN_0040ed60×2, FUN_005711c0×2, Map_LowerBoundFindByIntKey×2, FUN_0040f0c0, FUN_00418b80, FUN_004ce940, FUN_004f1e20.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_0052d450(int param_1,int *param_2,uint32_t /* width from decompiler */ *param_3)



{

  char cVar1;

  uint uVar2;

  int *piVar3;

  uint16_t uVar4;

  int iVar5;

  int iVar6;

  void *pvVar7;

  int *extraout_EAX;

  int iVar8;

  int iVar9;

  int *extraout_EAX_00;

  int *piVar10;

  int *unaff_EDI;

  int *piVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint32_t /* width from decompiler */ local_20 [2];

  int local_18;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  piVar10 = param_2;

  if ((*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) == 0) ||

     (param_2 == (int *)0x0)) {

    return 0;

  }

  iVar5 = FUN_00599dd0();

  local_18 = iVar5;

  iVar6 = FUN_005190c0();

  FUN_0040f0c0(*(uint32_t /* width from decompiler */ *)(*(int *)(iVar6 + 4) + 4));

  *(int *)(*(int *)(iVar6 + 4) + 4) = *(int *)(iVar6 + 4);

  *(uint32_t /* width from decompiler */ *)(iVar6 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(iVar6 + 4) = *(uint32_t /* width from decompiler */ *)(iVar6 + 4);

  *(int *)(*(int *)(iVar6 + 4) + 8) = *(int *)(iVar6 + 4);

  param_2 = (int *)0x0;

  if (0 < iVar5) {

    iVar5 = 0x498;

    do {

      uVar2 = *(uint *)(iVar5 + *(int *)(piVar10[0x2a] + 0x3c));

      iVar6 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                               (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & uVar2) * 4) + 4);

      if (iVar6 == 0) {

LAB_0052d514:

        iVar6 = 0;

      }

      else {

        do {

          if (uVar2 == *(uint *)(iVar6 + 0x10)) {

            if (iVar6 == 0) goto LAB_0052d514;

            iVar6 = *(int *)(iVar6 + 8);

            goto LAB_0052d51b;

          }

          iVar6 = *(int *)(iVar6 + 0xc);

        } while (iVar6 != 0);

        iVar6 = 0;

      }

LAB_0052d51b:

      if ((iVar6 == 0) || (0x4ab < iVar5)) {

        *param_3 = 2;

        return 0;

      }

      local_20[0] = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x34);

      puVar13 = local_20;

      piVar11 = &local_14;

      pvVar7 = (void *)FUN_005190c0();

      Map_LowerBoundFindByIntKey(pvVar7,piVar11,puVar13,unaff_EDI);

      iVar9 = *extraout_EAX;

      iVar8 = FUN_005190c0();

      if (iVar9 == *(int *)(iVar8 + 4)) {

        local_10 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x34);

        puVar13 = &local_10;

        puVar12 = &local_8;

        local_c = 1;

        FUN_005190c0(puVar12,puVar13);

        FUN_0040ed60(puVar12,puVar13);

      }

      else {

        piVar11 = (int *)(iVar9 + 0x10);

        *piVar11 = *piVar11 + 1;

      }

      param_2 = (int *)((int)param_2 + 1);

      iVar5 = iVar5 + 4;

    } while ((int)param_2 < local_18);

  }

  local_18 = FUN_004ce940();

  local_14 = (**(code **)(*piVar10 + 0x60))();

  param_2 = (int *)0x0;

  if (0 < local_14) {

    do {

      iVar6 = 0;

      iVar5 = (int)param_2;

      do {

        uVar4 = (**(code **)(*piVar10 + 0x5c))(iVar5);

        iVar9 = FUN_005097b0(uVar4);

        if ((iVar9 != 0) && (uVar2 = *(uint *)(iVar6 + iVar9), uVar2 != 0xffffffff)) {

          iVar9 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                                   (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & uVar2) * 4) + 4)

          ;

          if (iVar9 == 0) {

LAB_0052d63a:

            iVar9 = 0;

          }

          else {

            do {

              if (uVar2 == *(uint *)(iVar9 + 0x10)) {

                if (iVar9 == 0) goto LAB_0052d63a;

                iVar9 = *(int *)(iVar9 + 8);

                goto LAB_0052d641;

              }

              iVar9 = *(int *)(iVar9 + 0xc);

            } while (iVar9 != 0);

            iVar9 = 0;

          }

LAB_0052d641:

          if ((iVar9 != 0) && (iVar5 < 5)) {

            if (*(int *)(iVar9 + 0x3c) == 0) {

              FUN_004f1e20(1,1);

            }

            local_20[0] = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x34);

            puVar13 = local_20;

            puVar12 = &local_10;

            pvVar7 = (void *)FUN_005190c0();

            Map_LowerBoundFindByIntKey(pvVar7,puVar12,puVar13,unaff_EDI);

            iVar5 = *extraout_EAX_00;

            iVar8 = FUN_005190c0();

            if (iVar5 == *(int *)(iVar8 + 4)) {

              local_8 = *(uint32_t /* width from decompiler */ *)(iVar9 + 0x34);

              puVar13 = &local_8;

              puVar12 = local_20;

              uStack_4 = 1;

              FUN_005190c0(puVar12,puVar13);

              FUN_0040ed60(puVar12,puVar13);

              iVar5 = (int)param_2;

            }

            else {

              piVar11 = (int *)(iVar5 + 0x10);

              *piVar11 = *piVar11 + 1;

              iVar5 = (int)param_2;

            }

          }

        }

        iVar6 = iVar6 + 4;

      } while (iVar6 < 0x14);

      param_2 = (int *)(iVar5 + 1);

    } while ((int)param_2 < local_14);

  }

  iVar5 = *(int *)(piVar10[0x2a] + 0x3c);

  iVar6 = *(int *)(iVar5 + 0x4ac);

  if (iVar6 < 0) {

LAB_0052d761:

    iVar5 = FUN_005190c0();

    piVar10 = (int *)**(int **)(iVar5 + 4);

    iVar5 = FUN_005190c0();

    if (piVar10 != *(int **)(iVar5 + 4)) {

      do {

        iVar5 = 0;

        if ((*(int *)(param_1 + 0x250) != 0) && (*(int *)(*(int *)(param_1 + 0x250) + 0x2b0) != 0))

        {

          iVar5 = FUN_005711c0(piVar10[3],0);

        }

        if ((*(char *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xf5) !=

             '\0') && (*(int *)(param_1 + 0xcbc) != 0)) {

          iVar6 = FUN_005711c0(piVar10[3],0);

          iVar5 = iVar5 + iVar6;

        }

        if (iVar5 < piVar10[4]) {

          *param_3 = 2;

          return 0;

        }

        if (*(char *)((int)piVar10 + 0x15) == '\0') {

          piVar11 = (int *)piVar10[2];

          if (*(char *)((int)piVar11 + 0x15) == '\0') {

            cVar1 = *(char *)(*piVar11 + 0x15);

            piVar10 = piVar11;

            piVar11 = (int *)*piVar11;

            while (cVar1 == '\0') {

              cVar1 = *(char *)(*piVar11 + 0x15);

              piVar10 = piVar11;

              piVar11 = (int *)*piVar11;

            }

          }

          else {

            cVar1 = *(char *)(piVar10[1] + 0x15);

            piVar3 = (int *)piVar10[1];

            piVar11 = piVar10;

            while ((piVar10 = piVar3, cVar1 == '\0' && (piVar11 == (int *)piVar10[2]))) {

              cVar1 = *(char *)(piVar10[1] + 0x15);

              piVar3 = (int *)piVar10[1];

              piVar11 = piVar10;

            }

          }

        }

        iVar5 = FUN_005190c0();

      } while (piVar10 != *(int **)(iVar5 + 4));

    }

    *param_3 = 0;

    return 1;

  }

  param_2 = (int *)iVar6;

  piVar10 = (int *)FUN_00538ab0(&local_10,&param_2);

  if (*piVar10 != DAT_00b045b4) {

    iVar5 = *(int *)(iVar5 + 0x4b0);

    param_2 = (int *)iVar6;

    FUN_00418b80(&local_14,&param_2);

    if (local_14 == *(int *)(param_1 + 0x588)) {

      iVar6 = -1;

    }

    else {

      iVar6 = *(int *)(local_14 + 0x10);

    }

    if (iVar5 <= iVar6) goto LAB_0052d761;

  }

  *param_3 = 4;

  return 0;

}
