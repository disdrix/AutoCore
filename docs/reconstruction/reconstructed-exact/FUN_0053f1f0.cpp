// =============================================================================
// FUN_0053f1f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0053f1f0
// Address:   0x0053f1f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053f1f0 @ 0x0053f1f0
// Stable ID: aa_0053f1f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~227 non-empty decompiler lines.
//  - Control keywords: if×22, return×2.
//  - Notable callees: FUN_0053e020×7, SQRT×5, FUN_004e8a40×2, FUN_004e8ad0×2, FUN_0053eb90, FUN_0053f1f0, FUN_00567e90.
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



uint8_t __thiscall

FUN_0053f1f0(int param_1,float param_2,float *param_3,float *param_4,float *param_5,

            uint32_t /* width from decompiler */ *param_6,uint32_t /* width from decompiler */ param_7,float param_8,char param_9)



{

  float *pfVar1;

  int iVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  uint8_t local_6d;

  float local_68;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_20;

  float local_1c;

  float local_18;

  

  local_6d = 0;

  if (*(int *)(param_1 + 0x28) == 0) {

    uVar4 = FUN_0053e020();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar4;

  }

  pfVar1 = *(float **)(param_1 + 0x28);

  if (_DAT_009d0010 < SQRT(pfVar1[2] * pfVar1[2] + pfVar1[1] * pfVar1[1] + *pfVar1 * *pfVar1)) {

    if (pfVar1 == (float *)0x0) {

      uVar4 = FUN_0053e020();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar4;

    }

    fVar7 = DAT_00af2458;

    fVar6 = g_flOne;

    pfVar1 = *(float **)(param_1 + 0x28);

    fVar15 = pfVar1[2] - param_3[2];

    fVar13 = pfVar1[1] - param_3[1];

    fVar5 = *pfVar1 - *param_3;

    fVar12 = pfVar1[3] - param_3[3];

    fVar10 = SQRT(fVar5 * fVar5 + fVar13 * fVar13 + fVar15 * fVar15);

    if (fVar10 <= param_8) {

      if (param_4[2] * param_4[2] + param_4[1] * param_4[1] + *param_4 * *param_4 != g_flZero) {

        *param_4 = DAT_00b04610;

        param_4[1] = DAT_00b04614;

        param_4[2] = DAT_00b04618;

        param_4[3] = DAT_00b0461c;

      }

    }

    else if (DAT_00b04606 == '\0') {

      fVar14 = param_2 * g_flVehicleHpTechCoeff;

      fVar8 = fVar14 * fVar5;

      fVar11 = fVar15 * fVar14;

      fVar9 = fVar13 * fVar14;

      fVar14 = fVar12 * fVar14;

      fVar7 = SQRT(fVar9 * fVar9 + fVar11 * fVar11 + fVar8 * fVar8);

      if (fVar7 < param_2 * g_flLevelUpUiBase_Inferred) {

        fVar7 = (param_2 * g_flLevelUpUiBase_Inferred) / fVar7;

        fVar8 = fVar7 * fVar8;

        fVar9 = fVar9 * fVar7;

        fVar11 = fVar11 * fVar7;

        fVar14 = fVar14 * fVar7;

      }

      fVar16 = (DAT_009d000c - DAT_00af244c) - g_flMultiKillCountBlend;

      fVar7 = SQRT(fVar9 * fVar9 + fVar11 * fVar11 + fVar8 * fVar8);

      fVar17 = fVar10;

      if (fVar16 <= fVar10) {

        fVar17 = fVar16;

      }

      fVar17 = DAT_00af244c - (fVar17 / fVar16) * DAT_00a0f298;

      if ((fVar10 < fVar7) ||

         (fVar13 = fVar9, fVar15 = fVar11, fVar12 = fVar14, fVar5 = fVar8, fVar10 < fVar7 / fVar17))

      {

        fVar9 = fVar13;

        fVar11 = fVar15;

        fVar14 = fVar12;

        fVar17 = g_flOne;

        fVar8 = fVar5;

      }

      fVar10 = g_flOne / (fVar17 * param_2);

      *param_4 = fVar10 * fVar8;

      param_4[1] = fVar9 * fVar10;

      param_4[2] = fVar11 * fVar10;

      param_4[3] = fVar14 * fVar10;

      fVar6 = fVar6 / fVar17;

      *param_3 = fVar6 * fVar8 + *param_3;

      param_3[1] = fVar9 * fVar6 + param_3[1];

      param_3[2] = fVar11 * fVar6 + param_3[2];

      param_3[3] = fVar14 * fVar6 + param_3[3];

      local_6d = 1;

    }

    else {

      *param_4 = *param_3;

      param_4[1] = param_3[1];

      param_4[2] = param_3[2];

      param_4[3] = param_3[3];

      fVar6 = fVar10;

      if (fVar7 < fVar10) {

        fVar6 = fVar7;

      }

      fVar6 = (g_flOne / param_2) * (g_flOne - (fVar7 - fVar6) / fVar7);

      if (fVar6 <= g_flOne) {

        fVar6 = g_flOne;

      }

      fVar7 = (fVar6 / _DAT_00af2454) * param_2;

      fVar11 = fVar13 * fVar7;

      fVar9 = fVar5 * fVar7;

      fVar14 = fVar15 * fVar7;

      fVar6 = SQRT(fVar14 * fVar14 + fVar9 * fVar9 + fVar11 * fVar11);

      if (fVar6 <= fVar10) {

        fVar8 = param_2 * g_flMultiKillCountBlend;

        if ((fVar8 <= fVar6) || (fVar10 <= g_flMultiKillCountBlend)) {

          param_3[1] = fVar11 + param_3[1];

          param_3[2] = fVar14 + param_3[2];

          param_3[3] = fVar12 * fVar7 + param_3[3];

        }

        else {

          fVar9 = fVar8 * fVar5;

          param_3[1] = fVar13 * fVar8 + param_3[1];

          param_3[2] = fVar15 * fVar8 + param_3[2];

          param_3[3] = fVar12 * fVar8 + param_3[3];

        }

        *param_3 = fVar9 + *param_3;

      }

      else {

        *param_3 = fVar5 + *param_3;

        param_3[1] = fVar13 + param_3[1];

        param_3[2] = fVar15 + param_3[2];

        param_3[3] = fVar12 + param_3[3];

      }

      fVar10 = DAT_00af2450 * param_2;

      *param_4 = *param_3 - *param_4;

      param_4[1] = param_3[1] - param_4[1];

      param_4[2] = param_3[2] - param_4[2];

      param_4[3] = param_3[3] - param_4[3];

      fVar10 = g_flOne / fVar10;

      *param_4 = *param_4 * fVar10;

      param_4[1] = fVar10 * param_4[1];

      param_4[2] = param_4[2] * fVar10;

      param_4[3] = fVar10 * param_4[3];

      local_6d = 1;

    }

    local_40 = *param_6;

    local_3c = param_6[1];

    local_38 = param_6[2];

    local_34 = param_6[3];

    FUN_004e8a40(&local_40,&local_30);

    if (*(int *)(param_1 + 0x28) == 0) {

      uVar4 = FUN_0053e020();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar4;

    }

    FUN_004e8a40(*(int *)(param_1 + 0x28) + 0x10,&local_20);

    fVar10 = local_30 * local_20 + local_28 * local_18 + local_2c * local_1c;

    FUN_004e8ad0(&local_40,&local_30);

    if (*(int *)(param_1 + 0x28) == 0) {

      uVar4 = FUN_0053e020();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar4;

    }

    FUN_004e8ad0(*(int *)(param_1 + 0x28) + 0x10,&local_20);

    fVar6 = local_30 * local_20 + local_28 * local_18 + local_2c * local_1c;

    if ((fVar10 < DAT_00aaa660) || (fVar6 < DAT_00aaa660)) {

      if (fVar6 <= fVar10) {

        fVar10 = fVar6;

      }

      local_68 = ((g_flOne - fVar10) * _DAT_00af2448 + DAT_00aaa688) * param_2;

      if (g_flOne <= local_68) {

        local_68 = g_flOne;

      }

      if (*(int *)(param_1 + 0x28) == 0) {

        uVar4 = FUN_0053e020();

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar4;

      }

      FUN_00567e90(param_6,*(int *)(param_1 + 0x28) + 0x10,local_68);

      *param_6 = local_40;

      param_6[1] = local_3c;

      param_6[2] = local_38;

      param_6[3] = local_34;

      *param_5 = DAT_00b04610;

      param_5[1] = DAT_00b04614;

      param_5[2] = DAT_00b04618;

      param_5[3] = DAT_00b0461c;

      local_6d = 1;

    }

    if ((param_9 != '\0') && (cVar3 = FUN_0053eb90(param_2,0), cVar3 == '\0')) {

      *param_4 = DAT_00b04610;

      param_4[1] = DAT_00b04614;

      param_4[2] = DAT_00b04618;

      param_4[3] = DAT_00b0461c;

      *param_5 = DAT_00b04610;

      param_5[1] = DAT_00b04614;

      param_5[2] = DAT_00b04618;

      param_5[3] = DAT_00b0461c;

      if (*(int *)(param_1 + 0x28) == 0) {

        uVar4 = FUN_0053e020();

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar4;

      }

      iVar2 = *(int *)(param_1 + 0x28);

      *(float *)(iVar2 + 0x30) = DAT_00b04610;

      *(float *)(iVar2 + 0x34) = DAT_00b04614;

      *(float *)(iVar2 + 0x38) = DAT_00b04618;

      *(float *)(iVar2 + 0x3c) = DAT_00b0461c;

      if (*(int *)(param_1 + 0x28) == 0) {

        uVar4 = FUN_0053e020();

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar4;

      }

      iVar2 = *(int *)(param_1 + 0x28);

      *(float *)(iVar2 + 0x20) = DAT_00b04610;

      *(float *)(iVar2 + 0x24) = DAT_00b04614;

      *(float *)(iVar2 + 0x28) = DAT_00b04618;

      *(float *)(iVar2 + 0x2c) = DAT_00b0461c;

    }

    return local_6d;

  }

  return 0;

}
