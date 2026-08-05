// =============================================================================
// FUN_004d5110
// -----------------------------------------------------------------------------
// Stable ID: aa_004d5110
// Address:   0x004d5110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d5110 @ 0x004d5110
// Stable ID: aa_004d5110
// Embedded strings (evidence for future rename):
//   - "Invalid transfer type in FindEntryPoint"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~228 non-empty decompiler lines.
//  - Control keywords: if×18, return×9, switch×1, goto×1, for×1, do×1, while×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, FUN_004e39d0×2, Object_GetRootRaceId×2, FUN_004d5110, FUN_004e54a0, FUN_005dab60, FUN_007a4480.
//  - Strings: "Invalid transfer type in FindEntryPoint".
//  - Return sites: 9.

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

uint32_t /* width from decompiler */ __thiscall

FUN_004d5110(int param_1,uint8_t param_2,int param_3,RACE_ID_INFERRED param_4,uint32_t /* width from decompiler */ *param_5

            ,uint32_t /* width from decompiler */ *param_6,int param_7)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  ushort uVar5;

  int iVar6;

  void **ppvVar7;

  int *piVar8;

  RACE_ID_INFERRED RVar9;

  int iVar10;

  uint uVar11;

  void *pvVar12;

  int local_54;

  int *local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint8_t local_44 [8];

  void *local_3c;

  int *local_38;

  int local_34;

  void *local_2c;

  int *local_28;

  int local_24;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a20f6;

  local_1c = ExceptionList;

  if (param_7 == 0) {

    local_50 = (int *)0xffffffff;

    local_4c = 0xffffffff;

  }

  else {

    iVar10 = *(int *)(*(int *)(param_7 + 4) + 4);

    local_50 = *(int **)(iVar10 + 0x164 + param_7);

    local_4c = *(uint32_t /* width from decompiler */ *)(iVar10 + 0x168 + param_7);

  }

  ppvVar7 = &local_1c;

  switch(param_2) {

  case 0:

  case 7:

  case 8:

    goto switchD_004d5177_caseD_0;

  default:

    ExceptionList = &local_1c;

    FUN_007a4480(1,"Invalid transfer type in FindEntryPoint");

    ExceptionList = local_1c;

    return 0;

  case 5:

    break;

  case 0xff:

    if (((((param_7 == 0) || (param_1 == -0x98)) || (*(char *)(param_1 + 0x100) == '\0')) ||

        ((*(float *)(param_7 + 0x624) == 0.0 || (*(float *)(param_7 + 0x62c) == 0.0)))) ||

       ((*(int *)(param_7 + 0x630) == -1 || (*(int *)(param_1 + 0xfc) != *(int *)(param_7 + 0x630)))

       )) {

      *param_5 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4c0);

      param_5[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4c4);

      param_5[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4c8);

      param_5[3] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4cc);

    }

    else {

      *param_5 = *(uint32_t /* width from decompiler */ *)(param_7 + 0x624);

      param_5[1] = *(uint32_t /* width from decompiler */ *)(param_7 + 0x628);

      param_5[2] = *(uint32_t /* width from decompiler */ *)(param_7 + 0x62c);

    }

    *param_6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4d0);

    param_6[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4d4);

    param_6[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4d8);

    param_6[3] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4dc);

    return 1;

  }

  ExceptionList = &local_1c;

  if ((((param_1 == -0xa0) || (ExceptionList = &local_1c, *(char *)(param_1 + 0x100) != '\0')) ||

      (ExceptionList = &local_1c, *(int *)(param_1 + 0xac) == 2)) ||

     (iVar10 = *(int *)(param_1 + 0xe740), ExceptionList = &local_1c,

     piVar8 = (int *)FUN_005dab60(local_44,&local_50), ppvVar7 = ExceptionList, *piVar8 != iVar10))

  {

    for (piVar8 = *(int **)(param_1 + 0xe7a8); ppvVar7 = ExceptionList,

        piVar8 != *(int **)(param_1 + 0xe7ac); piVar8 = piVar8 + 1) {

      iVar10 = *piVar8;

      if (*(int *)(iVar10 + 0xb4) == param_3) {

        iVar6 = *(int *)(*(int *)(iVar10 + 4) + 4);

        uVar2 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x88 + iVar10);

        uVar3 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x8c + iVar10);

        uVar4 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x90 + iVar10);

        *param_5 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x84 + iVar10);

        param_5[1] = uVar2;

        param_5[2] = uVar3;

        param_5[3] = uVar4;

        puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 0x94 + iVar10);

        *param_6 = *puVar1;

        param_6[1] = puVar1[1];

        param_6[2] = puVar1[2];

        param_6[3] = puVar1[3];

        ExceptionList = local_1c;

        return 1;

      }

    }

  }

switchD_004d5177_caseD_0:

  ExceptionList = ppvVar7;

  local_3c = (void *)0x0;

  local_38 = (int *)0x0;

  local_34 = 0;

  pvVar12 = (void *)0x0;

  local_2c = (void *)0x0;

  local_28 = (int *)0x0;

  local_24 = 0;

  local_50 = *(int **)(param_1 + 0xe788);

  local_14 = 1;

  if (local_50 != *(int **)(param_1 + 0xe78c)) {

    do {

      iVar10 = *local_50;

      local_54 = iVar10;

      RVar9 = Object_GetRootRaceId((void *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 4 + iVar10));

      if ((RVar9 == ~RACE_HUMAN_INFERRED) ||

         (RVar9 = Object_GetRootRaceId((void *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 4 + iVar10)),

         RVar9 == param_4)) {

        if (*(int *)(iVar10 + 0xb4) == -1) {

          if ((*(char *)(param_1 + 0xf6) == '\0') ||

             (RVar9 = Object_GetRootRaceId

                                ((void *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 4 + iVar10)),

             RVar9 != param_4)) {

            if ((local_3c == (void *)0x0) ||

               ((uint)(local_34 - (int)local_3c >> 2) <= (uint)((int)local_38 - (int)local_3c >> 2))

               ) {

              FUN_004e39d0(local_38,1,&local_54);

            }

            else {

              *local_38 = iVar10;

              local_38 = local_38 + 1;

            }

          }

          else {

            FUN_004e54a0(&local_54);

            pvVar12 = local_2c;

          }

        }

        else if (*(int *)(iVar10 + 0xb4) == param_3) {

          if ((pvVar12 == (void *)0x0) ||

             ((uint)(local_24 - (int)pvVar12 >> 2) <= (uint)((int)local_28 - (int)pvVar12 >> 2))) {

            FUN_004e39d0(local_28,1,&local_54);

            pvVar12 = local_2c;

          }

          else {

            *local_28 = iVar10;

            local_28 = local_28 + 1;

          }

        }

      }

      local_50 = local_50 + 1;

    } while (local_50 != *(int **)(param_1 + 0xe78c));

    if ((pvVar12 != (void *)0x0) && (uVar11 = (int)local_28 - (int)pvVar12 >> 2, uVar11 != 0)) {

      iVar10 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar10 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar10 + 0xc) = 0;

      }

      uVar5 = *(ushort *)(*(int *)(iVar10 + 8) + *(int *)(iVar10 + 0xc) * 2);

      *(int *)(iVar10 + 0xc) = *(int *)(iVar10 + 0xc) + 1;

      iVar10 = *(int *)((int)pvVar12 + ((uint)uVar5 % uVar11) * 4);

      iVar6 = *(int *)(*(int *)(iVar10 + 4) + 4);

      uVar2 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x88 + iVar10);

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x8c + iVar10);

      uVar4 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x90 + iVar10);

      *param_5 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x84 + iVar10);

      param_5[1] = uVar2;

      param_5[2] = uVar3;

      param_5[3] = uVar4;

      puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 0x94 + iVar10);

      *param_6 = *puVar1;

      param_6[1] = puVar1[1];

      param_6[2] = puVar1[2];

      param_6[3] = puVar1[3];

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar12);

    }

    if ((local_3c != (void *)0x0) && (uVar11 = (int)local_38 - (int)local_3c >> 2, uVar11 != 0)) {

      iVar10 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar10 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar10 + 0xc) = 0;

      }

      uVar5 = *(ushort *)(*(int *)(iVar10 + 8) + *(int *)(iVar10 + 0xc) * 2);

      *(int *)(iVar10 + 0xc) = *(int *)(iVar10 + 0xc) + 1;

      iVar10 = *(int *)((int)local_3c + ((uint)uVar5 % uVar11) * 4);

      iVar6 = *(int *)(*(int *)(iVar10 + 4) + 4);

      uVar2 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x88 + iVar10);

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x8c + iVar10);

      uVar4 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x90 + iVar10);

      *param_5 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x84 + iVar10);

      param_5[1] = uVar2;

      param_5[2] = uVar3;

      param_5[3] = uVar4;

      puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 0x94 + iVar10);

      *param_6 = *puVar1;

      param_6[1] = puVar1[1];

      param_6[2] = puVar1[2];

      param_6[3] = puVar1[3];

      if (pvVar12 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar12);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(local_3c);

    }

  }

  *param_5 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4c0);

  param_5[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4c4);

  param_5[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4c8);

  param_5[3] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4cc);

  *param_6 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4d0);

  param_6[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4d4);

  param_6[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4d8);

  param_6[3] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4dc);

  if (pvVar12 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar12);

  }

  if (local_3c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_3c);

  }

  ExceptionList = local_1c;

  return 1;

}
