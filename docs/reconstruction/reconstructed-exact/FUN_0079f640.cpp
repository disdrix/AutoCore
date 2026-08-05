// =============================================================================
// FUN_0079f640
// -----------------------------------------------------------------------------
// Stable ID: aa_0079f640
// Address:   0x0079f640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079f640 @ 0x0079f640
// Stable ID: aa_0079f640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~177 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, return×2.
//  - Notable callees: FUN_0076f5f0×2, CONCAT31, FUN_00567ce0, FUN_0079f640, SQRT.
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

uint __thiscall FUN_0079f640(int *param_1,float *param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  

  if ((int)(*unaff_EBX + 6U) < *param_1) {

    local_64 = param_2[0x19] + param_2[0x11];

    local_60 = param_2[0x1a] + param_2[0x12];

    local_5c = param_2[0x1b] + param_2[0x13];

    FUN_0076f5f0(&local_64,&local_64);

    fVar5 = param_2[0xb] * DAT_00a0f298;

    local_64 = fVar5 * local_64;

    local_5c = fVar5 * local_5c;

    local_60 = fVar5 * local_60;

    local_58 = param_2[0xd] + param_2[0x11];

    local_54 = param_2[0xe] + param_2[0x12];

    local_50 = param_2[0xf] + param_2[0x13];

    fVar5 = DAT_00a0f298;

    FUN_0076f5f0(&local_58,&local_58);

    local_40 = param_2[0x1d];

    fVar5 = param_2[0xc] * fVar5;

    local_38 = param_2[0x1f];

    local_58 = fVar5 * local_58;

    local_50 = fVar5 * local_50;

    local_54 = fVar5 * local_54;

    local_3c = param_2[0x1e];

    fVar5 = local_38 * local_38 + local_3c * local_3c + local_40 * local_40;

    if (fVar5 == 0.0) {

      local_34 = 0.0;

    }

    else {

      local_34 = g_flOne / SQRT(fVar5);

    }

    local_3c = local_3c * local_34;

    local_38 = local_38 * local_34;

    local_40 = local_34 * local_40;

    local_34 = local_34 * 0.0;

    FUN_00567ce0(&local_40,param_2[10]);

    fVar5 = g_flLevelUpUiBase_Inferred;

    local_3c = local_54 - local_60;

    local_38 = local_50 - local_5c;

    fVar12 = local_58 - local_64;

    if (param_2[10] != 0.0) {

      fVar8 = local_24 * g_flLevelUpUiBase_Inferred;

      fVar9 = local_28 * fVar12;

      fVar6 = (local_30 * fVar12 + local_28 * local_38 + local_2c * local_3c) *

              g_flLevelUpUiBase_Inferred;

      fVar10 = local_3c * local_30;

      fVar11 = local_2c * fVar12;

      fVar7 = local_24 * local_24 * g_flLevelUpUiBase_Inferred - g_flOne;

      fVar12 = (local_2c * local_38 - local_28 * local_3c) * fVar8 +

               local_30 * fVar6 + fVar7 * fVar12;

      local_3c = (fVar9 - local_38 * local_30) * fVar8 + local_2c * fVar6 + local_3c * fVar7;

      local_38 = (fVar10 - fVar11) * fVar8 + local_28 * fVar6 + local_38 * fVar7;

    }

    *(float *)(param_3 + *unaff_EBX * 0x1c) = *param_2 + fVar12;

    *(float *)(param_3 + 4 + *unaff_EBX * 0x1c) = param_2[1] + local_3c;

    *(float *)(param_3 + 8 + *unaff_EBX * 0x1c) = local_38 + param_2[2];

    *(float *)(param_3 + 0x10 + *unaff_EBX * 0x1c) = param_2[4];

    *(float *)(param_3 + 0x14 + *unaff_EBX * 0x1c) = param_2[5];

    local_3c = local_54 + local_60;

    *(float *)(param_3 + 0x18 + *unaff_EBX * 0x1c) = param_2[9];

    *(float *)(param_3 + 0xc + *unaff_EBX * 0x1c) = param_2[8];

    *unaff_EBX = *unaff_EBX + 1;

    local_38 = local_50 + local_5c;

    fVar12 = local_58 + local_64;

    if (param_2[10] != 0.0) {

      fVar10 = local_24 * fVar5;

      fVar11 = local_28 * local_3c;

      fVar8 = local_2c * local_38;

      fVar9 = local_3c * local_30;

      fVar7 = local_24 * local_24 * fVar5 - g_flOne;

      fVar6 = (local_30 * fVar12 + local_28 * local_38 + local_2c * local_3c) * fVar5;

      local_3c = (local_28 * fVar12 - local_38 * local_30) * fVar10 +

                 local_2c * fVar6 + local_3c * fVar7;

      local_38 = (fVar9 - local_2c * fVar12) * fVar10 + local_28 * fVar6 + local_38 * fVar7;

      fVar12 = (fVar8 - fVar11) * fVar10 + fVar6 * local_30 + fVar7 * fVar12;

    }

    *(float *)(param_3 + *unaff_EBX * 0x1c) = *param_2 + fVar12;

    *(float *)(param_3 + 4 + *unaff_EBX * 0x1c) = param_2[1] + local_3c;

    *(float *)(param_3 + 8 + *unaff_EBX * 0x1c) = local_38 + param_2[2];

    *(float *)(param_3 + 0x10 + *unaff_EBX * 0x1c) = param_2[6];

    *(float *)(param_3 + 0x14 + *unaff_EBX * 0x1c) = param_2[5];

    *(float *)(param_3 + 0x18 + *unaff_EBX * 0x1c) = param_2[9];

    *(float *)(param_3 + 0xc + *unaff_EBX * 0x1c) = param_2[8];

    *unaff_EBX = *unaff_EBX + 1;

    local_3c = (0.0 - local_60) - local_54;

    fVar12 = (0.0 - local_64) - local_58;

    local_38 = (0.0 - local_5c) - local_50;

    if (param_2[10] != 0.0) {

      fVar9 = local_28 * fVar12;

      fVar10 = local_3c * local_30;

      fVar11 = local_2c * fVar12;

      fVar6 = local_24 * local_24 * fVar5 - g_flOne;

      fVar7 = (local_30 * fVar12 + local_28 * local_38 + local_2c * local_3c) * fVar5;

      fVar8 = local_24 * fVar5;

      fVar12 = (local_2c * local_38 - local_28 * local_3c) * fVar8 +

               fVar7 * local_30 + fVar6 * fVar12;

      local_3c = (fVar9 - local_38 * local_30) * fVar8 + local_2c * fVar7 + local_3c * fVar6;

      local_38 = (fVar10 - fVar11) * fVar8 + local_28 * fVar7 + local_38 * fVar6;

    }

    *(float *)(param_3 + *unaff_EBX * 0x1c) = *param_2 + fVar12;

    *(float *)(param_3 + 4 + *unaff_EBX * 0x1c) = param_2[1] + local_3c;

    *(float *)(param_3 + 8 + *unaff_EBX * 0x1c) = local_38 + param_2[2];

    *(float *)(param_3 + 0x10 + *unaff_EBX * 0x1c) = param_2[4];

    *(float *)(param_3 + 0x14 + *unaff_EBX * 0x1c) = param_2[7];

    *(float *)(param_3 + 0x18 + *unaff_EBX * 0x1c) = param_2[9];

    local_64 = local_64 - local_58;

    local_38 = local_5c - local_50;

    *(float *)(param_3 + 0xc + *unaff_EBX * 0x1c) = param_2[8];

    *unaff_EBX = *unaff_EBX + 1;

    local_3c = local_60 - local_54;

    puVar3 = (uint32_t /* width from decompiler */ *)(param_3 + (*unaff_EBX + -2) * 0x1c);

    puVar4 = (uint32_t /* width from decompiler */ *)(param_3 + *unaff_EBX * 0x1c);

    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar4 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar4 = puVar4 + 1;

    }

    *unaff_EBX = *unaff_EBX + 1;

    if (param_2[10] != 0.0) {

      fVar7 = local_28 * local_3c;

      fVar6 = (local_30 * local_64 + local_28 * local_38 + local_2c * local_3c) * fVar5;

      fVar12 = local_24 * local_24 * fVar5 - g_flOne;

      local_24 = local_24 * fVar5;

      fVar5 = local_3c * local_30;

      fVar8 = local_2c * local_64;

      local_3c = (local_28 * local_64 - local_38 * local_30) * local_24 +

                 local_2c * fVar6 + fVar12 * local_3c;

      local_64 = (local_2c * local_38 - fVar7) * local_24 + fVar6 * local_30 + fVar12 * local_64;

      local_38 = (fVar5 - fVar8) * local_24 + local_28 * fVar6 + local_38 * fVar12;

    }

    *(float *)(param_3 + *unaff_EBX * 0x1c) = *param_2 + local_64;

    *(float *)(param_3 + 4 + *unaff_EBX * 0x1c) = param_2[1] + local_3c;

    *(float *)(param_3 + 8 + *unaff_EBX * 0x1c) = local_38 + param_2[2];

    *(float *)(param_3 + 0x10 + *unaff_EBX * 0x1c) = param_2[6];

    *(float *)(param_3 + 0x14 + *unaff_EBX * 0x1c) = param_2[7];

    *(float *)(param_3 + 0x18 + *unaff_EBX * 0x1c) = param_2[9];

    *(float *)(param_3 + 0xc + *unaff_EBX * 0x1c) = param_2[8];

    *unaff_EBX = *unaff_EBX + 1;

    iVar1 = *unaff_EBX;

    puVar3 = (uint32_t /* width from decompiler */ *)(param_3 + (iVar1 + -3) * 0x1c);

    puVar4 = (uint32_t /* width from decompiler */ *)(param_3 + iVar1 * 0x1c);

    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *puVar3;

      puVar3 = puVar3 + 1;

      puVar4 = puVar4 + 1;

    }

    *unaff_EBX = *unaff_EBX + 1;

    return CONCAT31((int3)((uint)iVar1 >> 8),1);

  }

  return *unaff_EBX + 6U & 0xffffff00;

}
