// =============================================================================
// FUN_006289b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006289b0
// Address:   0x006289b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006289b0 @ 0x006289b0
// Stable ID: aa_006289b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~209 non-empty decompiler lines.
//  - Control keywords: if×30, while×7, return×7, do×6, goto×4.
//  - Notable callees: ABS, FUN_006289b0.
//  - Return sites: 7.

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

void __thiscall FUN_006289b0(int param_1,int param_2,int *param_3,int *param_4,float param_5)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *piVar7;

  int *piVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int *piVar12;

  float *pfVar13;

  float fVar14;

  uint32_t /* width from decompiler */ unaff_retaddr;

  int *local_1c;

  int iStack_c;

  

  piVar8 = param_4;

  piVar7 = param_3;

  piVar3 = *(int **)(*(int *)(*param_3 + 0x10) + 0x3c);

  piVar4 = *(int **)(*(int *)(param_3[1] + 0x10) + 0x3c);

  piVar1 = (int *)piVar3[0x1f];

  piVar2 = (int *)piVar4[0x1f];

  local_1c = piVar1;

  if ((float)piVar2 <= (float)piVar1) {

    local_1c = piVar2;

  }

  if ((float)piVar1 != (float)piVar2) {

    piVar12 = piVar4;

    if ((float)piVar2 < (float)piVar1) {

      piVar12 = piVar3;

    }

    (**(code **)(*piVar12 + 0x74))(local_1c,*(uint32_t /* width from decompiler */ *)(param_2 + 0x10));

    *(uint32_t /* width from decompiler */ *)(*param_4 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0xc) = 2;

    *(int **)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0x10) = param_3;

    (**(code **)(*(int *)param_3[2] + 0x10))(*param_3 + -0x10,param_3[1] + -0x10,param_2,param_4);

    if (*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0xc) == 0) {

LAB_00628a84:

      param_4 = (int *)0x0;

    }

    else {

      piVar5 = (int *)*param_4;

      iVar11 = piVar5[1];

      iVar10 = 0;

      param_4 = (int *)0x2;

      if (0 < iVar11) {

        pfVar13 = (float *)(*piVar5 + 0xc);

        do {

          if (*pfVar13 <= param_5 && param_5 != *pfVar13) goto LAB_00628a84;

          iVar10 = iVar10 + 1;

          pfVar13 = pfVar13 + 0xc;

          param_4 = (int *)0x1;

        } while (iVar10 < iVar11);

      }

    }

    if (param_4 == (int *)0x1) {

      return;

    }

    if (param_4 == (int *)0x2) {

      param_3 = (int *)(ABS((float)piVar1 - (float)piVar2) * DAT_00a0f298);

      param_4 = (int *)((float)param_3 + (float)local_1c);

      if (*(float *)(*(int *)(param_1 + 0x20) + 0x24c) < (float)param_3) {

        do {

          (**(code **)(*piVar12 + 0x74))(param_4,*(uint32_t /* width from decompiler */ *)(param_2 + 0x10));

          *(uint32_t /* width from decompiler */ *)(*piVar8 + 4) = 0;

          *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0xc) = 2;

          *(int **)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0x10) = param_3;

          (**(code **)(*(int *)piVar7[2] + 0x10))(*piVar7 + -0x10,piVar7[1] + -0x10,param_2,piVar8);

          if (*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0xc) == 0) {

LAB_00628b77:

            iVar10 = 0;

          }

          else {

            iVar11 = ((int *)*piVar8)[1];

            iVar9 = 0;

            iStack_c = 2;

            iVar10 = iStack_c;

            if (0 < iVar11) {

              pfVar13 = (float *)(*(int *)*piVar8 + 0xc);

              do {

                if (*pfVar13 <= param_5 && param_5 != *pfVar13) goto LAB_00628b77;

                iVar9 = iVar9 + 1;

                pfVar13 = pfVar13 + 0xc;

                iStack_c = 1;

                iVar10 = iStack_c;

              } while (iVar9 < iVar11);

            }

          }

          if (iVar10 == 0) {

            param_4 = (int *)((float)param_4 - (float)param_3 * DAT_00a0f298);

LAB_00628c0e:

            param_3 = (int *)((float)param_3 * DAT_00a0f298);

          }

          else {

            if (iVar10 == 1) {

              return;

            }

            if (iVar10 == 2) {

              param_4 = (int *)((float)param_4 + (float)param_3 * DAT_00a0f298);

              goto LAB_00628c0e;

            }

          }

          pfVar13 = (float *)(*(int *)(param_1 + 0x20) + 0x24c);

        } while (*pfVar13 <= (float)param_3 && (float)param_3 != *pfVar13);

      }

      if (*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0xc) == 0) {

LAB_00628c7e:

        (**(code **)(*piVar12 + 0x74))(local_1c,*(uint32_t /* width from decompiler */ *)(param_2 + 0x10));

        uVar6 = DAT_00aaaaa0;

        piVar7[3] = -3;

        *(uint32_t /* width from decompiler */ *)(*piVar8 + 4) = 0;

        *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0xc) = 2;

        *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0x10) = uVar6;

        (**(code **)(*(int *)piVar7[2] + 0x10))(*piVar7 + -0x10,piVar7[1] + -0x10,param_2,piVar8);

        return;

      }

      iVar11 = ((int *)*piVar8)[1];

      iVar10 = 0;

      if (0 < iVar11) {

        pfVar13 = (float *)(*(int *)*piVar8 + 0xc);

        do {

          if (*pfVar13 <= param_5 && param_5 != *pfVar13) goto LAB_00628c7e;

          iVar10 = iVar10 + 1;

          pfVar13 = pfVar13 + 0xc;

        } while (iVar10 < iVar11);

      }

    }

  }

  if ((float)piVar4[0x1f] < (float)piVar3[0x1f] || (float)piVar4[0x1f] == (float)piVar3[0x1f]) {

    fVar14 = (float)piVar4[0x1f];

  }

  else {

    fVar14 = (float)piVar3[0x1f];

  }

  param_3 = (int *)(fVar14 * DAT_00a0f298);

  pfVar13 = (float *)(*(int *)(param_1 + 0x20) + 0x24c);

  param_4 = param_3;

  if (*pfVar13 <= (float)param_3 && (float)param_3 != *pfVar13) {

    do {

      (**(code **)(*piVar3 + 0x74))(param_3,*(uint32_t /* width from decompiler */ *)(param_2 + 0x10));

      (**(code **)(*local_1c + 0x74))(unaff_retaddr,*(uint32_t /* width from decompiler */ *)(param_2 + 0x10));

      *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0xc) = 2;

      *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0x10) = unaff_retaddr;

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 4) = 0;

      (**(code **)(*(int *)piVar7[2] + 0x10))(*piVar7 + -0x10,piVar7[1] + -0x10,param_2,piVar8);

      iVar10 = 0;

      iVar11 = iVar10;

      if (*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0xc) != 0) {

        iVar9 = ((int *)*piVar8)[1];

        iStack_c = 2;

        iVar11 = iStack_c;

        if (0 < iVar9) {

          pfVar13 = (float *)(*(int *)*piVar8 + 0xc);

          do {

            if (*pfVar13 <= param_5 && param_5 != *pfVar13) {

              iVar11 = 0;

              break;

            }

            iVar10 = iVar10 + 1;

            pfVar13 = pfVar13 + 0xc;

            iStack_c = 1;

            iVar11 = iStack_c;

          } while (iVar10 < iVar9);

        }

      }

      if (iVar11 == 0) {

        param_4 = (int *)((float)param_4 * DAT_00a0f298);

        param_3 = (int *)((float)param_3 - (float)param_4);

      }

      else {

        if (iVar11 == 1) {

          return;

        }

        if (iVar11 == 2) {

          param_4 = (int *)((float)param_4 * DAT_00a0f298);

          param_3 = (int *)((float)param_4 + (float)param_3);

        }

      }

      pfVar13 = (float *)(*(int *)(param_1 + 0x20) + 0x24c);

    } while (*pfVar13 <= (float)param_4 && (float)param_4 != *pfVar13);

  }

  if ((float)param_4 <= *(float *)(*(int *)(param_1 + 0x20) + 0x24c)) {

    if (*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0xc) != 0) {

      iVar11 = ((int *)*piVar8)[1];

      param_3 = (int *)0x0;

      if (iVar11 < 1) {

        return;

      }

      pfVar13 = (float *)(*(int *)*piVar8 + 0xc);

      while (param_5 < *pfVar13 || param_5 == *pfVar13) {

        param_3 = (int *)((int)param_3 + 1);

        pfVar13 = pfVar13 + 0xc;

        if (iVar11 <= (int)param_3) {

          return;

        }

      }

    }

    piVar7[3] = -3;

    (**(code **)(*piVar3 + 0x74))(piVar1,*(uint32_t /* width from decompiler */ *)(param_2 + 0x10));

    (**(code **)(*local_1c + 0x74))(iStack_c,*(uint32_t /* width from decompiler */ *)(param_2 + 0x10));

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0x10) = DAT_00aaaaa0;

    *(uint32_t /* width from decompiler */ *)(*piVar8 + 4) = 0;

    (**(code **)(*(int *)piVar7[2] + 0x10))(*piVar7 + -0x10,piVar7[1] + -0x10,param_2,piVar8);

  }

  return;

}
