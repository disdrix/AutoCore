// =============================================================================
// FUN_004fc650
// -----------------------------------------------------------------------------
// Stable ID: aa_004fc650
// Address:   0x004fc650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004fc650 @ 0x004fc650
// Stable ID: aa_004fc650
// Embedded strings (evidence for future rename):
//   - "CVOGVehicle::MoveToTarget3DPoint"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~140 non-empty decompiler lines.
//  - Control keywords: if×17, return×2.
//  - Notable callees: ABS×3, SQRT×3, FUN_0076cef0×2, VehicleEntity_PushDriveAxesToController×2, VehicleEntity_SetSteerInput×2, FUN_004e8a40, FUN_004e8ad0, FUN_004fc650.
//  - Strings: "CVOGVehicle::MoveToTarget3DPoint".
//  - Return sites: 2.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall

FUN_004fc650(int param_1,float param_2,float param_3,uint32_t /* width from decompiler */ param_4,char param_5)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float local_68;

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a2d28;

  local_1c = ExceptionList;

  ExceptionList = &local_1c;

  FUN_0076cf00("CVOGVehicle::MoveToTarget3DPoint");

  iVar4 = *(int *)(param_1 + 8);

  local_14 = 0;

  if ((iVar4 != 0) && (*(char *)(param_1 + 0x101) == '\0')) {

    if (iVar4 == 0) {

      pfVar3 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

    }

    else {

      pfVar3 = (float *)(*(int *)(iVar4 + 0x3c) + 0xb0);

    }

    fVar10 = *(float *)(param_1 + 400) - *pfVar3;

    fVar5 = *(float *)(param_1 + 0x198) - pfVar3[2];

    fVar6 = *(float *)(param_1 + 0x194) - pfVar3[1];

    fVar2 = SQRT(fVar10 * fVar10 + fVar5 * fVar5);

    if ((param_2 < ABS(fVar2)) || (*(char *)(param_1 + 0x103) != '\0')) {

      fVar9 = fVar6 * fVar6 + fVar10 * fVar10 + fVar5 * fVar5;

      fVar8 = 0.0;

      if (fVar9 != 0.0) {

        fVar8 = g_flOne / SQRT(fVar9);

      }

      if (iVar4 == 0) {

        iVar4 = *(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1;

      }

      else {

        iVar4 = *(int *)(iVar4 + 0x3c) + 0x30;

      }

      FUN_004e8ad0(iVar4,&local_30);

      fVar9 = local_28 * fVar5 * fVar8 + local_2c * fVar6 * fVar8 + local_30 * fVar8 * fVar10;

      if (*(int *)(param_1 + 8) == 0) {

        iVar4 = *(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1;

      }

      else {

        iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x30;

      }

      FUN_004e8a40(iVar4,&local_40);

      fVar11 = DAT_00aaa668;

      iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x3c);

      fVar7 = *(float *)(iVar4 + 0x44);

      fVar1 = *(float *)(iVar4 + 0x40);

      fVar10 = local_38 * fVar5 * fVar8 + local_3c * fVar6 * fVar8 + local_40 * fVar8 * fVar10;

      fVar5 = *(float *)(iVar4 + 0x48);

      fVar6 = SQRT(fVar5 * fVar5 + fVar7 * fVar7 + fVar1 * fVar1);

      fVar5 = fVar5 * local_38 + fVar7 * local_3c + fVar1 * local_40;

      if ((param_5 == '\0') || (fVar8 = g_flOne, (float)_DAT_009cd238 <= fVar10)) {

        fVar8 = DAT_00aaa668;

      }

      if (DAT_00a0f718 <= ABS(fVar9)) {

        fVar10 = fVar8 * fVar9 * g_flLevelUpUiBase_Inferred;

        if (((fVar10 <= DAT_00aaa668) || (fVar7 = g_flOne, fVar10 < g_flOne)) &&

           (fVar7 = fVar10, fVar10 <= DAT_00aaa668)) {

          fVar7 = DAT_00aaa668;

        }

        iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);

        if ((iVar4 == 0) ||

           ((((*(byte *)(iVar4 + 0xb4) & 2) == 0 && ((*(byte *)(iVar4 + 0xb4) & 4) == 0)) &&

            (((*(byte *)(iVar4 + 0xb4) & 1) == 0 &&

             (((*(byte *)(iVar4 + 0xb4) & 0x80) == 0 && ((*(byte *)(iVar4 + 0xb4) & 0x40) == 0))))))

           )) {

          *(float *)(param_1 + 0x618) = fVar7;

        }

        fVar7 = 0.0;

      }

      else {

        fVar7 = 0.0;

        if (0.0 <= fVar10) {

          VehicleEntity_SetSteerInput(0);

        }

        else {

          local_68 = g_flOne;

          if (fVar9 <= 0.0) {

            local_68 = DAT_00aaa668;

          }

          VehicleEntity_SetSteerInput(local_68);

        }

      }

      fVar10 = DAT_00aaa7a4;

      if (DAT_00aaa688 < fVar6) {

        if ((fVar2 < DAT_00a0f694) && (fVar7 < fVar2)) {

          fVar8 = fVar8 * fVar2 * _DAT_00aaab14;

        }

        if (g_flMultiKillCountBlend < param_3) {

          if (fVar5 < fVar7) {

            param_3 = param_3 * fVar11;

          }

          fVar8 = param_3 * fVar8;

        }

      }

      *(uint8_t *)(param_1 + 0x101) = 0;

      *(uint8_t *)(param_1 + 0x109) = 0;

      *(float *)(param_1 + 0x614) = fVar8;

      if ((fVar6 <= fVar10) || (ABS(fVar9) <= DAT_00a0f710)) {

        *(uint8_t *)(param_1 + 0x61c) = 0;

      }

      else {

        *(uint8_t *)(param_1 + 0x61c) = 1;

      }

      VehicleEntity_PushDriveAxesToController();

      local_14 = 0xffffffff;

      FUN_0076cef0();

      ExceptionList = local_1c;

      return 1;

    }

    *(uint8_t *)(param_1 + 0x61c) = 1;

    VehicleEntity_SetLongitudinalInput(0);

    VehicleEntity_PushDriveAxesToController();

  }

  local_14 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_1c;

  return 0;

}
