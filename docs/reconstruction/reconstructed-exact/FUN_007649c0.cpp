// =============================================================================
// FUN_007649c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007649c0
// Address:   0x007649c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007649c0 @ 0x007649c0
// Stable ID: aa_007649c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~189 non-empty decompiler lines.
//  - Control keywords: if×23, do×4, while×4, return×4, goto×2, for×1.
//  - Notable callees: FUN_00456960×3, FUN_00436ef0, FUN_00438310, FUN_0043a420, FUN_00463e30, FUN_0074a2e0, FUN_00763460, FUN_007649c0.
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

void FUN_007649c0(int param_1,code *param_2,char param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  int **ppiVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int *piVar7;

  int *piVar8;

  int iVar9;

  int local_34;

  int local_30;

  int *local_28;

  int *local_24;

  uint32_t /* width from decompiler */ local_20;

  int *local_18;

  int *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b275c;

  pvStack_c = ExceptionList;

  ppiVar3 = (int **)(DAT_00d1f044 + 0xcc);

  local_28 = (int *)0xffff;

  if (0xfffe < *(uint *)(DAT_00d1f044 + 0xcc)) {

    ppiVar3 = &local_28;

  }

  local_24 = *ppiVar3;

  local_20 = *(uint32_t /* width from decompiler */ *)(DAT_00d1f044 + 0x78c);

  local_18 = (int *)0x0;

  local_14 = (int *)0x0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

LAB_00764a24:

  do {

    if (*(int *)(param_1 + 4) == 0) {

LAB_00764c89:

      if (local_18 != local_14) {

        piVar6 = local_18 + 1;

        do {

          puVar1 = (uint32_t /* width from decompiler */ *)*piVar6;

          piVar5 = (int *)*puVar1;

          if ((puVar1 != (uint32_t /* width from decompiler */ *)0x0) && (1 < (uint)(piVar6[1] - (int)puVar1 >> 2))) {

            FUN_0074a2e0();

          }

          if (param_3 != '\0') {

            (**(code **)(*piVar5 + 100))();

          }

          *(uint32_t /* width from decompiler */ *)*piVar6 = 0;

          iVar9 = *(int *)(param_1 + 4);

          if ((iVar9 == 0) ||

             ((uint)(*(int *)(param_1 + 0xc) - iVar9 >> 2) <=

              (uint)(*(int *)(param_1 + 8) - iVar9 >> 2))) {

            FUN_00456960();

          }

          else {

            puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

            *puVar1 = piVar5;

            *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar1 + 1;

          }

          piVar7 = (int *)piVar6[1];

          for (piVar5 = (int *)*piVar6; piVar5 != piVar7; piVar5 = piVar5 + 1) {

            if ((uint32_t /* width from decompiler */ *)*piVar5 != (uint32_t /* width from decompiler */ *)0x0) {

              (*(code *)**(uint32_t /* width from decompiler */ **)*piVar5)();

            }

          }

          piVar5 = piVar6 + 9;

          piVar6 = piVar6 + 10;

        } while (piVar5 != local_14);

      }

      if (local_18 == (int *)0x0) {

        ExceptionList = pvStack_c;

        return;

      }

      if (local_18 != local_14) {

        piVar6 = local_18 + 7;

        do {

          if ((void *)*piVar6 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete((void *)*piVar6);

          }

          *piVar6 = 0;

          piVar6[1] = 0;

          piVar6[2] = 0;

          if ((void *)piVar6[-6] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete((void *)piVar6[-6]);

          }

          piVar6[-6] = 0;

          piVar6[-5] = 0;

          piVar6[-4] = 0;

          piVar5 = piVar6 + 3;

          piVar6 = piVar6 + 10;

        } while (piVar5 != local_14);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(local_18);

    }

    iVar9 = *(int *)(param_1 + 8);

    iVar4 = iVar9 - *(int *)(param_1 + 4) >> 2;

    if (iVar4 == 0) goto LAB_00764c89;

    piVar6 = *(int **)(iVar9 + -4);

    if (iVar4 != 0) {

      *(int *)(param_1 + 8) = iVar9 + -4;

    }

    if (piVar6[5] == 0) {

      local_34 = 0;

    }

    else {

      local_34 = *(int *)(piVar6[5] + 0x18);

    }

    if (piVar6[3] == 0) {

      local_30 = 0;

    }

    else {

      local_30 = *(int *)(piVar6[3] + 0x1c);

    }

    piVar5 = local_14;

    piVar7 = local_18;

    piVar8 = local_18;

    local_28 = piVar6;

    if (local_18 != local_14) {

      do {

        if (((piVar7[4] + local_34 <= (int)local_24) && (cVar2 = (*param_2)(), cVar2 != '\0')) &&

           (cVar2 = FUN_00763460(), piVar5 = local_14, piVar8 = local_18, cVar2 != '\0')) {

          iVar9 = piVar7[1];

          if ((iVar9 == 0) || ((uint)(piVar7[3] - iVar9 >> 2) <= (uint)(piVar7[2] - iVar9 >> 2))) {

            FUN_00456960();

          }

          else {

            piVar5 = (int *)piVar7[2];

            *piVar5 = (int)piVar6;

            piVar7[2] = (int)(piVar5 + 1);

          }

          piVar7[4] = piVar7[4] + local_34;

          piVar7[5] = piVar7[5] + local_30;

          goto LAB_00764a24;

        }

        piVar7 = piVar7 + 10;

      } while (piVar7 != piVar5);

    }

    if (piVar8 == (int *)0x0) {

      iVar9 = 0;

    }

    else {

      iVar9 = ((int)piVar5 - (int)piVar8) / 0x28;

    }

    local_4 = local_4 & 0xffffff00;

    FUN_00438310();

    piVar5 = local_18;

    iVar4 = (**(code **)(*piVar6 + 4))();

    if (iVar4 == 0x47504345) {

      iVar4 = piVar5[iVar9 * 10 + 7];

      if ((iVar4 == 0) ||

         ((uint)(piVar5[iVar9 * 10 + 9] - iVar4 >> 2) <= (uint)(piVar5[iVar9 * 10 + 8] - iVar4 >> 2)

         )) {

        FUN_00463e30();

      }

      else {

        iVar4 = piVar5[iVar9 * 10 + 8];

        FUN_00436ef0();

        piVar5[iVar9 * 10 + 8] = iVar4 + 4;

      }

    }

    else {

      iVar4 = (**(code **)(*piVar6 + 4))();

      if (iVar4 == 0x47534b4e) {

        FUN_0043a420();

      }

    }

    iVar4 = piVar5[iVar9 * 10 + 1];

    if ((iVar4 == 0) ||

       ((uint)(piVar5[iVar9 * 10 + 3] - iVar4 >> 2) <= (uint)(piVar5[iVar9 * 10 + 2] - iVar4 >> 2)))

    {

      FUN_00456960();

    }

    else {

      piVar7 = (int *)piVar5[iVar9 * 10 + 2];

      *piVar7 = (int)piVar6;

      piVar5[iVar9 * 10 + 2] = (int)(piVar7 + 1);

    }

    piVar5[iVar9 * 10 + 4] = piVar5[iVar9 * 10 + 4] + local_34;

    piVar5[iVar9 * 10 + 5] = piVar5[iVar9 * 10 + 5] + local_30;

  } while( true );

}
