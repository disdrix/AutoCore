// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_004b8ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b8ed0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions
// Address:   0x004b8ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper. Evidence string: "Destroy". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Destroy"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~166 non-empty decompiler lines.
//  - Control keywords: if×19, return×7, do×4, while×4, goto×2, switch×1.
//  - Notable callees: CONCAT31, FUN_00498a50, FUN_00498ab0, FUN_004b6910, FUN_004b6a80, FUN_004b7150, FUN_004b7330, FUN_004b75d0.
//  - Strings: "Destroy".
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_004b8ed0(byte *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint uVar4;

  char cVar5;

  byte bVar6;

  int *piVar7;

  int *piVar8;

  float10 fVar9;

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a155d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(int *)(DAT_00d17958 + 0x154) = *(int *)(DAT_00d17958 + 0x154) + 1;

  uVar4 = g_dwClientTickMs;

  if (g_dwClientTickMs - *(int *)(param_1 + 0xd0) < 0x1389) {

switchD_004b8f1f_caseD_7:

    *(uint *)(param_1 + 0xd0) = uVar4;

    cVar5 = FUN_004b7330();

    if (cVar5 == '\0') {

      FUN_004b75d0();

      iVar1 = *(int *)(*(int *)(DAT_00b04c70 + 0x2e4) + 8);

      if ((DAT_00b03e64 != '\0') ||

         (DAT_009cb2b0 <=

          *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x90) +

          *(float *)(iVar1 + 0x94) * *(float *)(iVar1 + 0x94) +

          *(float *)(iVar1 + 0x98) * *(float *)(iVar1 + 0x98))) {

        piVar7 = (int *)**(int **)(param_1 + 0x204);

        if (piVar7 != *(int **)(param_1 + 0x204)) {

          do {

            iVar2 = piVar7[2];

            if ((*(byte *)(iVar2 + 0x90e) & 1) == 0) {

              local_10 = CONCAT31(local_10._1_3_,*(byte *)(iVar2 + 0x90e) >> 3) & 0xffffff01;

              fVar9 = (float10)FUN_0079a110();

              FUN_00595230(*param_2,(float)fVar9);

              if ((*param_1 & 2) == 0) {

                bVar6 = FUN_0058e1a0(param_1 + 0xa0,local_10);

                param_1[0xd4] = param_1[0xd4] | bVar6;

              }

              piVar8 = (int *)*piVar7;

            }

            else {

              FUN_0076cf00("Destroy");

              piVar8 = (int *)*piVar7;

              local_4 = 0;

              if (piVar7 != *(int **)(param_1 + 0x204)) {

                *(int **)piVar7[1] = piVar8;

                *(int *)(*piVar7 + 4) = piVar7[1];

                    /* WARNING: Subroutine does not return */

                operator_delete(piVar7);

              }

              if (g_flZero < *(float *)(iVar2 + 0x798)) {

                FUN_00590c20(iVar2);

                *(uint32_t /* width from decompiler */ *)(iVar2 + 0x914) = 0;

              }

              FUN_005be2f0(iVar2);

              local_4 = 0xffffffff;

              FUN_0076cef0();

            }

            piVar7 = piVar8;

          } while (piVar8 != *(int **)(param_1 + 0x204));

        }

        piVar7 = (int *)**(int **)(param_1 + 0x1e0);

        if (piVar7 != *(int **)(param_1 + 0x1e0)) {

          do {

            iVar2 = piVar7[2];

            cVar5 = FUN_005bc3c0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c),iVar1);

            if (cVar5 == '\0') {

              piVar8 = (int *)*piVar7;

              if (piVar7 != *(int **)(param_1 + 0x1e0)) {

                *(int **)piVar7[1] = piVar8;

                *(int *)(*piVar7 + 4) = piVar7[1];

                    /* WARNING: Subroutine does not return */

                operator_delete(piVar7);

              }

              FUN_005be310(iVar2);

            }

            else {

              FUN_005bb5e0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c));

              piVar8 = (int *)*piVar7;

            }

            piVar7 = piVar8;

          } while (piVar8 != *(int **)(param_1 + 0x1e0));

        }

        piVar7 = (int *)**(int **)(param_1 + 0x210);

        if (piVar7 != *(int **)(param_1 + 0x210)) {

          do {

            pvVar3 = (void *)piVar7[2];

            cVar5 = FUN_005ba440(*param_2);

            if (cVar5 == '\0') {

              piVar8 = (int *)*piVar7;

              if (piVar7 != *(int **)(param_1 + 0x210)) {

                *(int **)piVar7[1] = piVar8;

                *(int *)(*piVar7 + 4) = piVar7[1];

                    /* WARNING: Subroutine does not return */

                operator_delete(piVar7);

              }

              if (pvVar3 != (void *)0x0) {

                FUN_005b85e0();

                    /* WARNING: Subroutine does not return */

                operator_delete(pvVar3);

              }

            }

            else {

              piVar8 = (int *)*piVar7;

            }

            piVar7 = piVar8;

          } while (piVar8 != *(int **)(param_1 + 0x210));

        }

        piVar7 = (int *)**(int **)(param_1 + 0x21c);

        if (piVar7 != *(int **)(param_1 + 0x21c)) {

          do {

            cVar5 = FUN_00498a50(*param_2);

            if (cVar5 == '\0') {

              piVar8 = (int *)*piVar7;

            }

            else {

              FUN_00498ab0(0);

              piVar8 = (int *)*piVar7;

              if (piVar7 != *(int **)(param_1 + 0x21c)) {

                *(int **)piVar7[1] = piVar8;

                *(int *)(*piVar7 + 4) = piVar7[1];

                    /* WARNING: Subroutine does not return */

                operator_delete(piVar7);

              }

            }

            piVar7 = piVar8;

          } while (piVar8 != *(int **)(param_1 + 0x21c));

        }

        FUN_004b6910();

      }

      ExceptionList = local_c;

      return 0;

    }

  }

  else {

    switch(*(uint32_t /* width from decompiler */ *)(param_1 + 0x28)) {

    case 4:

      cVar5 = FUN_004b6a80();

      if (cVar5 != '\0') goto switchD_004b8f1f_caseD_7;

    case 2:

    case 3:

    case 5:

    case 6:

    case 0xc:

    case 0xd:

    case 0xe:

    case 0x13:

    case 0x14:

    case 0x15:

    case 0x17:

      break;

    default:

      goto switchD_004b8f1f_caseD_7;

    }

  }

  FUN_004b7150();

  ExceptionList = local_c;

  return 1;

}
