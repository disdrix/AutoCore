// =============================================================================
// FUN_0056d600
// -----------------------------------------------------------------------------
// Stable ID: aa_0056d600
// Address:   0x0056d600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056d600 @ 0x0056d600
// Stable ID: aa_0056d600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~232 non-empty decompiler lines.
//  - Control keywords: if×23, return×4, goto×3, while×1.
//  - Notable callees: FUN_004e9aa0×2, FUN_00404c90, FUN_004ea350, FUN_0056ca70, FUN_0056d600.
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

uint __thiscall FUN_0056d600(int *param_1,int *param_2,int *param_3,int *param_4,int param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int iVar6;

  uint uVar7;

  void *pvVar8;

  int *piVar9;

  uint32_t /* width from decompiler */ *puVar10;

  float10 fVar11;

  uint32_t /* width from decompiler */ uVar12;

  int iVar13;

  uint8_t *puVar14;

  int iVar15;

  uint8_t local_6d;

  int *local_6c;

  uint uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  float fStack_60;

  uint local_5c;

  uint uStack_58;

  int iStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  int iStack_4c;

  int iStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint8_t auStack_40 [4];

  void *pvStack_3c;

  int iStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint8_t auStack_30 [8];

  void *pvStack_28;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a4dcd;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  *param_4 = 0;

  uVar7 = 1;

  local_6d = 0;

  if ((*(byte *)(param_1 + 0x31) & 1) == 0) {

    if ((*(byte *)(param_1 + 0x31) & 0x40) != 0) {

      uVar7 = 100;

    }

  }

  else {

    iVar3 = *(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1);

    if (iVar3 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x3c);

    }

    uVar7 = (uint)*(byte *)(iVar3 + 0x537);

    local_5c = 1;

    if (uVar7 == 0) goto LAB_0056d673;

  }

  local_5c = uVar7;

LAB_0056d673:

  piVar9 = *(int **)(*(int *)(param_1[1] + 4) + 0xb0 + (int)param_1);

  local_6c = piVar9;

  uStack_64 = (**(code **)(*piVar9 + 0x1a0))();

  FUN_0056ca70(auStack_30);

  uStack_68 = 0;

  if (((param_2 != (int *)0x0) && (cVar2 = (**(code **)(*param_2 + 0x198))(), cVar2 == '\0')) &&

     (cVar2 = (**(code **)(*piVar9 + 0x298))(param_2), cVar2 != '\0')) {

    uStack_58 = param_1[0x37];

    piVar9 = *(int **)(*(int *)(param_1[1] + 4) + 0xb0 + (int)param_1);

    fStack_60 = (float)param_1[0x3a];

    iVar3 = (**(code **)(*local_6c + 0x19c))();

    iStack_54 = *(int *)(iVar3 + 0x34);

    iVar3 = (**(code **)(*piVar9 + 0x210))(0);

    uVar4 = (**(code **)(*param_2 + 0x1c8))(&uStack_34,local_5c,iVar3 != 0);

    fVar11 = (float10)FUN_004e9aa0(uStack_64,iStack_54,fStack_60,uVar4);

    fStack_60 = (float)fVar11;

    piVar9 = local_6c;

    if (fStack_60 != g_flZero) {

      cVar2 = (**(code **)(*param_1 + 0x58))(local_6c,param_2,fStack_60,&local_6d);

      piVar9 = local_6c;

      if (cVar2 == '\0') {

        piVar5 = (int *)(*param_4 * 0x20 + param_5);

        *piVar5 = param_2[0x58];

        piVar5[1] = param_2[0x59];

        piVar5[2] = param_2[0x5a];

        piVar5[3] = param_2[0x5b];

        *(uint8_t *)(*param_4 * 0x20 + 0x14 + param_5) = 0;

        *(uint8_t *)(*param_4 * 0x20 + 0x15 + param_5) = 0;

        *(uint32_t /* width from decompiler */ *)(*param_4 * 0x20 + 0x10 + param_5) = 0;

        *(uint8_t *)(*param_4 * 0x20 + 0x1e + param_5) = 1;

        *param_4 = *param_4 + 1;

      }

      else {

        *param_3 = (int)param_2;

        uStack_68 = 1;

      }

    }

  }

  if (local_5c < 2) {

    if (*param_3 == 0) {

      iVar3 = *param_1;

      uVar4 = (**(code **)(*piVar9 + 0x1c8))(auStack_30,param_3);

      uVar7 = (**(code **)(iVar3 + 0x54))(uVar4);

      ExceptionList = pvStack_28;

      return uVar7;

    }

  }

  else {

    pvStack_3c = (void *)0x0;

    iStack_38 = 0;

    uStack_34 = 0;

    uStack_14 = 0;

    FUN_004ea350(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1),uStack_64,

                 (float)param_1[0x3a] + (float)param_1[0x38],auStack_40,0,1);

    uStack_58 = 0;

    pvVar8 = pvStack_3c;

    while (pvVar8 != (void *)0x0) {

      if ((uint)(iStack_38 - (int)pvVar8 >> 2) <= uStack_58) goto LAB_0056db05;

      iVar3 = *(int *)((int)pvVar8 + uStack_58 * 4);

      if (iVar3 == 0) {

        piVar5 = (int *)0x0;

      }

      else {

        piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

      }

      if (piVar5 != piVar9) {

        if (iVar3 == 0) {

          piVar5 = (int *)0x0;

        }

        else {

          piVar5 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

        }

        if (piVar5 != param_2) {

          if (iVar3 == 0) {

            iVar6 = 0;

          }

          else {

            iVar6 = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

          }

          cVar2 = (**(code **)(*piVar9 + 0x298))(iVar6);

          pvVar8 = pvStack_3c;

          if (((cVar2 != '\0') &&

              (cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x198)

                       )(), pvVar8 = pvStack_3c, cVar2 == '\0')) &&

             ((*(uint *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0x180 + iVar3) >> 10 & 1) == 0)) {

            iVar6 = *(int *)((int)param_1 + *(int *)(param_1[1] + 4) + 0xac);

            if (iVar6 == 0) {

              iVar6 = 0;

            }

            else {

              iVar6 = *(int *)(iVar6 + 0x3c);

            }

            iVar13 = iVar3;

            if (((*(byte *)(iVar6 + 0x536) & 0x40) == 0) || (uStack_68 == 0)) {

              iStack_4c = param_1[0x37];

              piVar9 = *(int **)((int)param_1 + *(int *)(param_1[1] + 4) + 0xb0);

              iStack_48 = param_1[0x3a];

              iVar6 = (**(code **)(*local_6c + 0x19c))();

              uStack_44 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x34);

              iVar6 = (**(code **)(*piVar9 + 0x210))(0);

              uVar7 = (uint)(iVar6 != 0);

              puVar14 = auStack_30;

              uVar4 = uStack_64;

              uVar12 = uStack_44;

              iVar6 = iStack_48;

              iVar15 = iStack_4c;

LAB_0056da23:

              fVar11 = (float10)FUN_004e9aa0(uVar4,uVar12,iVar6,iVar13,puVar14,iVar15,uVar7);

              fStack_60 = (float)fVar11;

              if (fStack_60 != g_flZero) {

                cVar2 = (**(code **)(*param_1 + 0x58))

                                  (local_6c,*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3,fStack_60,

                                   0);

                if (cVar2 == '\0') {

                  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0x164 + iVar3);

                  puVar10 = (uint32_t /* width from decompiler */ *)(*param_4 * 0x20 + param_5);

                  *puVar10 = *puVar1;

                  puVar10[1] = puVar1[1];

                  puVar10[2] = puVar1[2];

                  puVar10[3] = puVar1[3];

                  *(uint8_t *)(*param_4 * 0x20 + 0x14 + param_5) = 0;

                  *(uint8_t *)(*param_4 * 0x20 + 0x15 + param_5) = 0;

                  *(uint32_t /* width from decompiler */ *)(*param_4 * 0x20 + 0x10 + param_5) = 0;

                  *(uint8_t *)(*param_4 * 0x20 + 0x1e + param_5) = 1;

                  *param_4 = *param_4 + 1;

                }

                else {

                  param_3[uStack_68] = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

                  uStack_68 = uStack_68 + 1;

                }

              }

            }

            else {

              iVar6 = (**(code **)(*(int *)*param_3 + 0x1c8))();

              if (iVar6 != 0) {

                iStack_54 = param_1[0x38];

                uStack_50 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x34);

                iVar6 = (**(code **)(**(int **)(*(int *)(param_1[1] + 4) + 0xb0 + (int)param_1) +

                                    0x210))(0);

                uVar7 = (uint)(iVar6 != 0);

                puVar14 = auStack_30;

                iVar15 = -0x40800000;

                uVar12 = uStack_50;

                iVar6 = iStack_54;

                uVar4 = FUN_00404c90(uStack_50,iStack_54,iVar3,puVar14,0xbf800000,uVar7);

                goto LAB_0056da23;

              }

            }

            pvVar8 = pvStack_3c;

            piVar9 = local_6c;

            if (local_5c <= uStack_68) {

LAB_0056db05:

              if (pvVar8 == (void *)0x0) {

                ExceptionList = pvStack_1c;

                return uStack_68;

              }

                    /* WARNING: Subroutine does not return */

              operator_delete(pvVar8);

            }

          }

        }

      }

      uStack_58 = uStack_58 + 1;

    }

  }

  ExceptionList = pvStack_1c;

  return uStack_68;

}
