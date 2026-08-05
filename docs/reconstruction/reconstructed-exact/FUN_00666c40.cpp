// =============================================================================
// FUN_00666c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00666c40
// Address:   0x00666c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00666c40 @ 0x00666c40
// Stable ID: aa_00666c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006c3160×3, FUN_005d68f0×2, FUN_005d6ae0×2, FUN_006c35e0×2, FUN_006456f0, FUN_00666c40, FUN_006c2fb0, FUN_006c3440.
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

void __thiscall FUN_00666c40(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float local_f0;

  float local_ec;

  float local_e8;

  float local_e4;

  float local_e0;

  float local_dc;

  float local_d8;

  uint32_t /* width from decompiler */ local_d0;

  uint32_t /* width from decompiler */ local_cc;

  uint32_t /* width from decompiler */ local_c8;

  uint32_t /* width from decompiler */ local_c4;

  float local_c0;

  float local_bc;

  float local_b8;

  float local_b4;

  float local_b0;

  float local_ac;

  float local_a8;

  uint32_t /* width from decompiler */ local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  uint32_t /* width from decompiler */ local_94;

  uint32_t /* width from decompiler */ local_90;

  uint32_t /* width from decompiler */ local_8c;

  uint32_t /* width from decompiler */ local_88;

  uint32_t /* width from decompiler */ local_84;

  float local_80;

  uint32_t /* width from decompiler */ local_7c;

  uint32_t /* width from decompiler */ local_78;

  uint32_t /* width from decompiler */ local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  int local_14;

  

  FUN_006c2fb0(param_2,param_3,param_1 + 0xac,8);

  local_14 = *(int *)(param_1 + 0xc);

  iVar1 = *(int *)(param_1 + 0x10);

  iVar2 = *(int *)(iVar1 + 0x3c);

  FUN_006456f0(*(int *)(local_14 + 0x3c) + 0x80,param_1 + 0x70);

  local_d0 = local_60;

  local_cc = local_5c;

  local_c8 = local_58;

  local_c4 = local_54;

  local_c0 = *(float *)(iVar2 + 0x90);

  local_bc = *(float *)(iVar2 + 0x94);

  local_b8 = *(float *)(iVar2 + 0x98);

  local_b4 = *(float *)(iVar2 + 0x9c);

  local_b0 = local_40;

  local_ac = local_3c;

  local_a8 = local_38;

  local_a4 = local_34;

  FUN_006c3160(&local_d0,param_2,param_3);

  local_a0 = local_50;

  local_9c = local_4c;

  local_98 = local_48;

  local_94 = local_44;

  local_90 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xa0);

  local_8c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xa4);

  local_88 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xa8);

  local_84 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xac);

  local_80 = (float)local_d0;

  local_7c = local_cc;

  local_78 = local_c8;

  local_74 = local_c4;

  FUN_006c3160(&local_a0,param_2,param_3);

  local_80 = local_a0;

  local_7c = local_9c;

  local_78 = local_98;

  local_74 = local_94;

  local_a0 = local_b0;

  local_9c = local_ac;

  local_98 = local_a8;

  local_94 = local_a4;

  local_90 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x80);

  local_8c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x84);

  local_88 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x88);

  local_84 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x8c);

  FUN_006c3160(&local_a0,param_2,param_3);

  FUN_005d68f0(*(int *)(local_14 + 0x3c) + 0x80,param_1 + 0x20);

  FUN_005d68f0(*(int *)(iVar1 + 0x3c) + 0x80,param_1 + 0x30);

  FUN_005d6ae0(*(int *)(iVar1 + 0x3c) + 0x80,param_1 + 0x50);

  fVar3 = local_e8 * (local_d8 - local_68) + local_ec * (local_dc - local_6c) +

          (local_e0 - local_70) * local_f0;

  local_c0 = fVar3 * local_f0 + local_70;

  local_b8 = local_e8 * fVar3 + local_68;

  local_b4 = local_e4 * fVar3 + local_64;

  local_bc = local_ec * fVar3 + local_6c;

  FUN_005d6ae0(*(int *)(iVar1 + 0x3c) + 0x80,param_1 + 0x60);

  FUN_006c35e0(&local_d0,param_2,param_3);

  fVar5 = local_a8 * local_f0;

  fVar4 = local_e8 * local_b0;

  fVar3 = local_a8 * local_ec;

  local_a8 = local_ac * local_f0 - local_ec * local_b0;

  local_a4 = 0;

  local_b0 = fVar3 - local_ac * local_e8;

  local_ac = fVar4 - fVar5;

  FUN_006c35e0(&local_d0,param_2,param_3);

  local_50 = local_70;

  local_4c = local_6c;

  local_48 = local_68;

  local_44 = local_64;

  local_30 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0);

  local_2c = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4);

  FUN_006c37c0(&local_60,param_2,param_3);

  if (g_flZero < *(float *)(param_1 + 0xa8)) {

    local_40 = *(float *)(param_1 + 0xa8);

    local_3c = (float)(param_1 + 0xdc);

    FUN_006c3440(&local_60,param_2,param_3);

  }

  return;

}
