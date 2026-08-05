// =============================================================================
// FUN_006fc000
// -----------------------------------------------------------------------------
// Stable ID: aa_006fc000
// Address:   0x006fc000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fc000 @ 0x006fc000
// Stable ID: aa_006fc000
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~203 non-empty decompiler lines.
//  - Control keywords: if×18, return×8, goto×4.
//  - Notable callees: FUN_006fb890×4, ABS×2, FUN_006f6ef0×2, FUN_006fc000.
//  - Return sites: 8.

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

FUN_006fc000(int param_1,float *param_2,float *param_3,int *param_4,int *param_5,char param_6,

            uint32_t /* width from decompiler */ param_7)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  float *pfVar6;

  uint uVar7;

  int extraout_ECX;

  int iVar8;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  uint8_t local_70 [32];

  float local_50;

  uint8_t local_40 [32];

  float local_20;

  

  if (param_6 != '\0') {

    pfVar6 = param_3 + 8;

    local_a0 = param_3[4] - *pfVar6;

    local_9c = param_3[5] - param_3[9];

    local_98 = param_3[6] - param_3[10];

    local_94 = param_3[7] - param_3[0xb];

    local_80 = *param_3 - *pfVar6;

    local_7c = param_3[1] - param_3[9];

    local_78 = param_3[2] - param_3[10];

    local_74 = param_3[3] - param_3[0xb];

    fVar1 = local_78 * local_9c - local_7c * local_98;

    fVar2 = local_98 * local_80 - local_78 * local_a0;

    fVar3 = local_7c * local_a0 - local_9c * local_80;

    local_b0 = param_2[4] - *param_3;

    local_ac = param_2[5] - param_3[1];

    local_a8 = param_2[6] - param_3[2];

    local_84 = (param_2[1] - param_3[1]) * fVar2 +

               (param_2[2] - param_3[2]) * fVar3 + fVar1 * (*param_2 - *param_3);

    fVar1 = local_ac * fVar2 + local_a8 * fVar3 + fVar1 * local_b0;

    if (g_flZero <= local_84) {

      iVar8 = 0;

    }

    else {

      iVar8 = 8;

    }

    if (g_flZero <= fVar1) {

      iVar5 = 0;

    }

    else {

      iVar5 = 8;

    }

    if (iVar8 == iVar5) {

      if (ABS(fVar1) < ABS(local_84)) {

        fVar3 = param_2[2];

        fVar1 = *param_2;

        fVar4 = param_2[3];

        fVar2 = param_2[1];

        *param_2 = param_2[4];

        param_2[1] = param_2[5];

        param_2[2] = param_2[6];

        param_2[3] = param_2[7];

        param_2[4] = fVar1;

        param_2[5] = fVar2;

        param_2[6] = fVar3;

        param_2[7] = fVar4;

        fVar1 = param_2[0x10];

        local_a8 = param_2[0x12];

        fVar2 = param_2[0x11];

        local_a4 = param_2[0x13];

        param_2[0x10] = param_2[0x14];

        param_2[0x11] = param_2[0x15];

        param_2[0x12] = param_2[0x16];

        param_2[0x13] = param_2[0x17];

        param_2[0x14] = fVar1;

        param_2[0x15] = fVar2;

        param_2[0x16] = local_a8;

        param_2[0x17] = local_a4;

      }

      iVar8 = FUN_006fb890(param_2,param_3,8);

      if (iVar8 == 0xe) {

        *param_4 = *param_4 + -1;

        return 0;

      }

    }

    else {

      fVar1 = local_84 / (local_84 - fVar1);

      fVar2 = g_flOne - fVar1;

      local_b0 = fVar1 * param_2[4] + fVar2 * *param_2;

      local_ac = fVar2 * param_2[1] + fVar1 * param_2[5];

      local_a8 = fVar2 * param_2[2] + fVar1 * param_2[6];

      local_a4 = fVar2 * param_2[3] + fVar1 * param_2[7];

      iVar8 = FUN_006fb890(&local_b0,param_3,0);

      if (iVar8 == 0xe) {

        return 1;

      }

    }

    local_b0 = param_2[4] - *param_2;

    local_ac = param_2[5] - param_2[1];

    local_a8 = param_2[6] - param_2[2];

    local_a4 = param_2[7] - param_2[3];

    FUN_006f6ef0(param_2,&local_b0,pfVar6,&local_a0,local_70);

    FUN_006f6ef0(param_2,&local_b0,pfVar6,&local_80,local_40);

    uVar7 = (uint)(local_20 < local_50);

    param_3[uVar7 * 4] = *pfVar6;

    param_3[uVar7 * 4 + 1] = param_3[9];

    param_3[uVar7 * 4 + 2] = param_3[10];

    param_3[uVar7 * 4 + 3] = param_3[0xb];

    pfVar6 = param_3 + (uVar7 + 4) * 4;

    *pfVar6 = param_3[0x18];

    pfVar6[1] = param_3[0x19];

    pfVar6[2] = param_3[0x1a];

    pfVar6[3] = param_3[0x1b];

    *param_5 = *param_5 + -1;

    return 2;

  }

  pfVar6 = param_2 + 4;

  local_a0 = *(float *)(param_1 + 0x160);

  local_9c = *(float *)(param_1 + 0x164);

  local_98 = *(float *)(param_1 + 0x168);

  fVar1 = (param_2[4] - *param_3) * *(float *)(param_1 + 0x120) +

          (param_2[5] - param_3[1]) * *(float *)(param_1 + 0x124) +

          (param_2[6] - param_3[2]) * *(float *)(param_1 + 0x128);

  fVar2 = (*param_2 - *param_3) * *(float *)(param_1 + 0x120) +

          (param_2[1] - param_3[1]) * *(float *)(param_1 + 0x124) +

          (param_2[2] - param_3[2]) * *(float *)(param_1 + 0x128);

  if (fVar2 * fVar1 < g_flZero) {

    fVar2 = fVar2 / (fVar2 - fVar1);

    fVar1 = g_flOne - fVar2;

    local_b0 = fVar2 * *pfVar6 + fVar1 * *param_2;

    local_ac = fVar1 * param_2[1] + fVar2 * param_2[5];

    local_a8 = fVar1 * param_2[2] + fVar2 * param_2[6];

    local_a4 = fVar1 * param_2[3] + fVar2 * param_2[7];

    iVar8 = FUN_006fb890(&local_b0,param_3,0);

    if (iVar8 == 0xe) {

      return 1;

    }

  }

  iVar8 = FUN_006fb890(pfVar6,param_3,0);

  if (iVar8 == 0xe) {

    *param_4 = *param_4 + -1;

    *param_2 = *pfVar6;

    param_2[1] = param_2[5];

    param_2[2] = param_2[6];

    param_2[3] = param_2[7];

    param_2[0x10] = param_2[0x14];

    param_2[0x11] = param_2[0x15];

    param_2[0x12] = param_2[0x16];

    param_2[0x13] = param_2[0x17];

    *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x10) = param_7;

    return 0;

  }

  if (iVar8 == 6) goto LAB_006fc56f;

  if (iVar8 == 10) {

LAB_006fc52c:

    *param_5 = *param_5 + -1;

    param_3[4] = param_3[8];

    param_3[5] = param_3[9];

    param_3[6] = param_3[10];

    param_3[7] = param_3[0xb];

    param_3[0x14] = param_3[0x18];

    param_3[0x15] = param_3[0x19];

    param_3[0x16] = param_3[0x1a];

    param_3[0x17] = param_3[0x1b];

    return 2;

  }

  if (iVar8 != 0xc) {

    if (iVar8 != 8) {

      if (iVar8 == 4) {

        if ((*(float *)(extraout_ECX + 0x168) - local_98) * local_a0 <=

            (*(float *)(extraout_ECX + 0x160) - local_a0) * local_98) goto LAB_006fc4ef;

      }

      else if ((iVar8 == 2) &&

              ((*(float *)(extraout_ECX + 0x164) - local_9c) * local_a0 <

               (*(float *)(extraout_ECX + 0x160) - local_a0) * local_9c)) goto LAB_006fc52c;

LAB_006fc56f:

      *param_5 = *param_5 + -1;

      *param_3 = param_3[8];

      param_3[1] = param_3[9];

      param_3[2] = param_3[10];

      param_3[3] = param_3[0xb];

      param_3[0x10] = param_3[0x18];

      param_3[0x11] = param_3[0x19];

      param_3[0x12] = param_3[0x1a];

      param_3[0x13] = param_3[0x1b];

      return 2;

    }

    if ((*(float *)(extraout_ECX + 0x164) - local_9c) * local_98 <=

        (*(float *)(extraout_ECX + 0x168) - local_98) * local_9c) goto LAB_006fc52c;

  }

LAB_006fc4ef:

  *param_5 = *param_5 + -1;

  return 2;

}
