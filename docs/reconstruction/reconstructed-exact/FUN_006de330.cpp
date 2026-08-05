// =============================================================================
// FUN_006de330
// -----------------------------------------------------------------------------
// Stable ID: aa_006de330
// Address:   0x006de330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006de330 @ 0x006de330
// Stable ID: aa_006de330
// Embedded strings (evidence for future rename):
//   - "TtCapsCaps"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~195 non-empty decompiler lines.
//  - Control keywords: if×10, goto×2, return×1.
//  - Notable callees: ABS×4, SQRT×3, rdtsc×2, FUN_006de330, FUN_006f6ef0.
//  - Strings: "TtCapsCaps".
//  - Return sites: 1.

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



void FUN_006de330(int *param_1,int *param_2,int param_3,int *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  bool bVar6;

  uint64_t uVar7;

  int iVar8;

  uint uVar9;

  uint uVar10;

  float local_f0 [6];

  float local_d8;

  float local_d4;

  float local_cc;

  float local_c8;

  float local_c0;

  float local_bc;

  float local_b8;

  float local_b4;

  float local_b0 [4];

  int *local_a0;

  int *local_9c;

  float local_90;

  float local_8c;

  float local_88;

  uint32_t /* width from decompiler */ local_84;

  float local_80;

  float local_7c;

  float local_78;

  uint32_t /* width from decompiler */ local_74;

  float local_70;

  float local_6c;

  float local_68;

  uint32_t /* width from decompiler */ local_64;

  float local_60;

  float local_5c;

  float local_58;

  uint32_t /* width from decompiler */ local_54;

  float local_50;

  float local_4c;

  float local_48;

  uint32_t /* width from decompiler */ local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtCapsCaps";

    uVar7 = rdtsc();

    local_d4 = (float)uVar7;

    DAT_00bc5644[1] = local_d4;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar4 = *param_1;

  local_a0 = param_1;

  local_9c = param_2;

  fVar1 = *(float *)(iVar4 + 0x10);

  fVar2 = *(float *)(iVar4 + 0x14);

  iVar8 = param_1[2];

  fVar3 = *(float *)(iVar4 + 0x18);

  iVar5 = *param_2;

  local_60 = fVar1 * *(float *)(iVar8 + 0x20) +

             fVar2 * *(float *)(iVar8 + 0x30) + fVar3 * *(float *)(iVar8 + 0x40) +

             *(float *)(iVar8 + 0x50);

  local_5c = fVar2 * *(float *)(iVar8 + 0x34) +

             fVar3 * *(float *)(iVar8 + 0x44) + fVar1 * *(float *)(iVar8 + 0x24) +

             *(float *)(iVar8 + 0x54);

  local_58 = fVar2 * *(float *)(iVar8 + 0x38) +

             fVar3 * *(float *)(iVar8 + 0x48) + fVar1 * *(float *)(iVar8 + 0x28) +

             *(float *)(iVar8 + 0x58);

  local_54 = 0;

  fVar1 = *(float *)(iVar4 + 0x20);

  fVar2 = *(float *)(iVar4 + 0x24);

  fVar3 = *(float *)(iVar4 + 0x28);

  local_50 = fVar1 * *(float *)(iVar8 + 0x20) +

             fVar2 * *(float *)(iVar8 + 0x30) + fVar3 * *(float *)(iVar8 + 0x40) +

             *(float *)(iVar8 + 0x50);

  local_4c = fVar2 * *(float *)(iVar8 + 0x34) +

             fVar3 * *(float *)(iVar8 + 0x44) + fVar1 * *(float *)(iVar8 + 0x24) +

             *(float *)(iVar8 + 0x54);

  local_48 = fVar2 * *(float *)(iVar8 + 0x38) +

             fVar3 * *(float *)(iVar8 + 0x48) + fVar1 * *(float *)(iVar8 + 0x28) +

             *(float *)(iVar8 + 0x58);

  iVar8 = param_2[2];

  local_44 = 0;

  fVar1 = *(float *)(iVar5 + 0x10);

  fVar2 = *(float *)(iVar5 + 0x14);

  fVar3 = *(float *)(iVar5 + 0x18);

  local_80 = fVar1 * *(float *)(iVar8 + 0x20) +

             fVar2 * *(float *)(iVar8 + 0x30) + fVar3 * *(float *)(iVar8 + 0x40) +

             *(float *)(iVar8 + 0x50);

  local_7c = fVar2 * *(float *)(iVar8 + 0x34) +

             fVar3 * *(float *)(iVar8 + 0x44) + fVar1 * *(float *)(iVar8 + 0x24) +

             *(float *)(iVar8 + 0x54);

  local_78 = fVar2 * *(float *)(iVar8 + 0x38) +

             fVar3 * *(float *)(iVar8 + 0x48) + fVar1 * *(float *)(iVar8 + 0x28) +

             *(float *)(iVar8 + 0x58);

  local_74 = 0;

  fVar1 = *(float *)(iVar5 + 0x20);

  fVar2 = *(float *)(iVar5 + 0x24);

  fVar3 = *(float *)(iVar5 + 0x28);

  local_70 = fVar1 * *(float *)(iVar8 + 0x20) +

             fVar2 * *(float *)(iVar8 + 0x30) + fVar3 * *(float *)(iVar8 + 0x40) +

             *(float *)(iVar8 + 0x50);

  local_6c = fVar2 * *(float *)(iVar8 + 0x34) +

             fVar3 * *(float *)(iVar8 + 0x44) + fVar1 * *(float *)(iVar8 + 0x24) +

             *(float *)(iVar8 + 0x54);

  local_68 = fVar2 * *(float *)(iVar8 + 0x38) +

             fVar3 * *(float *)(iVar8 + 0x48) + fVar1 * *(float *)(iVar8 + 0x28) +

             *(float *)(iVar8 + 0x58);

  local_64 = 0;

  local_f0[3] = 0.0;

  local_84 = 0;

  local_f0[0] = local_50 - local_60;

  local_f0[1] = local_4c - local_5c;

  local_f0[2] = local_48 - local_58;

  local_90 = local_70 - local_80;

  local_8c = local_6c - local_7c;

  local_88 = local_68 - local_78;

  iVar8 = FUN_006f6ef0(&local_60,local_f0,&local_80,&local_90,&local_40);

  local_b4 = *(float *)(iVar4 + 0xc) + *(float *)(iVar5 + 0xc);

  fVar1 = local_b4 + *(float *)(param_3 + 8);

  if (fVar1 * fVar1 < local_20) goto LAB_006de839;

  if (iVar8 == 0) {

    fVar1 = local_88 * local_f0[1] - local_8c * local_f0[2];

    local_cc = local_f0[2] * local_90 - local_88 * local_f0[0];

    local_c8 = local_8c * local_f0[0] - local_f0[1] * local_90;

    if (local_cc * local_cc + local_c8 * local_c8 + fVar1 * fVar1 <= _DAT_00a0e548)

    goto LAB_006de70f;

    local_b0[0] = fVar1;

    if (local_cc * local_2c + local_c8 * local_28 + local_30 * fVar1 < g_flZero) {

      local_b0[0] = -fVar1;

      local_cc = -local_cc;

      local_c8 = -local_c8;

    }

    local_b0[1] = local_cc;

    local_b0[2] = local_c8;

    local_24 = g_flZero;

  }

  else if (local_20 <= g_flZero) {

LAB_006de70f:

    local_d4 = ABS(local_f0[1]);

    local_d8 = ABS(local_f0[2]);

    bVar6 = ABS(local_f0[0]) <= local_d4;

    fVar1 = ABS(local_f0[0]);

    if (!bVar6) {

      fVar1 = local_d4;

    }

    uVar9 = (uint)!bVar6;

    uVar10 = 2;

    if (local_d8 < fVar1) {

      uVar9 = 2;

      uVar10 = (uint)!bVar6;

    }

    local_b0[uVar9] = 0.0;

    local_b0[bVar6] = local_f0[uVar10];

    local_b0[uVar10] = -local_f0[bVar6];

    local_24 = local_b0[3];

  }

  else {

    local_b0[0] = local_30;

    local_b0[1] = local_2c;

    local_b0[2] = local_28;

  }

  fVar1 = local_b0[0] * local_b0[0] + local_b0[1] * local_b0[1] + local_b0[2] * local_b0[2];

  local_b0[3] = g_flZero;

  if (fVar1 != g_flZero) {

    local_b0[3] = g_flOne / SQRT(fVar1);

  }

  local_b0[0] = local_b0[0] * local_b0[3];

  local_b0[1] = local_b0[1] * local_b0[3];

  local_b0[2] = local_b0[2] * local_b0[3];

  local_b0[3] = local_24 * local_b0[3];

  fVar1 = *(float *)(iVar5 + 0xc) - SQRT(local_20);

  local_c0 = local_b0[0] * fVar1 + local_40;

  local_bc = local_b0[1] * fVar1 + local_3c;

  local_b8 = local_b0[2] * fVar1 + local_38;

  local_b4 = SQRT(local_20) - local_b4;

  (**(code **)(*param_4 + 4))(&local_c0);

LAB_006de839:

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar7 = rdtsc();

    DAT_00bc5644[1] = (int)uVar7;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
