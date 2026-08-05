// =============================================================================
// FUN_00665580
// -----------------------------------------------------------------------------
// Stable ID: aa_00665580
// Address:   0x00665580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00665580 @ 0x00665580
// Stable ID: aa_00665580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~124 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005d6ae0×5, FUN_006c35e0×3, FUN_005d68f0×2, FUN_006c3160×2, FUN_00665580, FUN_006c2f60, FUN_006c2f90, FUN_006c2fb0.
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

void __thiscall FUN_00665580(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float local_b0;

  float local_ac;

  float local_a8;

  uint32_t /* width from decompiler */ local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  uint32_t /* width from decompiler */ local_80;

  uint32_t /* width from decompiler */ local_7c;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  uint32_t /* width from decompiler */ local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  int local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_34 = *(int *)(param_1 + 0xc);

  iVar1 = *(int *)(param_1 + 0x10);

  FUN_006c2fb0(param_2,param_3,param_1 + 0xb0,8);

  FUN_005d6ae0(*(int *)(iVar1 + 0x3c) + 0x80,param_1 + 0x50);

  FUN_005d6ae0(*(int *)(local_34 + 0x3c) + 0x80,param_1 + 0x70);

  local_90 = local_28 * local_1c - local_2c * local_18;

  local_8c = local_18 * local_30 - local_28 * local_20;

  local_88 = local_2c * local_20 - local_1c * local_30;

  local_ac = local_1c;

  local_98 = local_28;

  local_84 = 0.0;

  local_b0 = local_20;

  local_a8 = local_18;

  local_a4 = local_14;

  local_a0 = local_30;

  local_9c = local_2c;

  local_94 = local_24;

  FUN_006c3160(&local_b0,param_2,param_3);

  local_90 = 0.0 - local_30;

  local_8c = 0.0 - local_2c;

  local_84 = 0.0 - local_24;

  local_88 = 0.0 - local_28;

  local_b0 = local_20;

  local_ac = local_1c;

  local_a8 = local_18;

  local_a4 = local_14;

  FUN_005d6ae0(*(int *)(iVar1 + 0x3c) + 0x80,param_1 + 0x60);

  FUN_006c3160(&local_b0,param_2,param_3);

  FUN_005d6ae0(*(int *)(iVar1 + 0x3c) + 0x80,param_1 + 0x90);

  FUN_005d68f0(*(int *)(local_34 + 0x3c) + 0x80,param_1 + 0x30);

  FUN_005d68f0(*(int *)(iVar1 + 0x3c) + 0x80,param_1 + 0x40);

  local_b0 = local_60;

  local_a8 = local_58;

  local_a4 = local_54;

  local_ac = local_5c;

  fVar2 = local_68 * (local_58 - local_48) + local_6c * (local_5c - local_4c) +

          (local_60 - local_50) * local_70;

  local_a0 = fVar2 * local_70 + local_50;

  local_98 = local_68 * fVar2 + local_48;

  local_94 = local_64 * fVar2 + local_44;

  local_9c = local_6c * fVar2 + local_4c;

  FUN_005d6ae0(*(int *)(iVar1 + 0x3c) + 0x80,param_1 + 0xa0);

  FUN_006c35e0(&local_b0,param_2,param_3);

  fVar4 = local_88 * local_70;

  fVar3 = local_68 * local_90;

  fVar2 = local_88 * local_6c;

  local_88 = local_8c * local_70 - local_6c * local_90;

  local_84 = 0.0;

  local_90 = fVar2 - local_8c * local_68;

  local_8c = fVar3 - fVar4;

  FUN_006c35e0(&local_b0,param_2,param_3);

  local_b0 = local_60;

  local_ac = local_5c;

  local_a8 = local_58;

  local_a4 = local_54;

  local_a0 = local_50;

  local_9c = local_4c;

  local_98 = local_48;

  local_94 = local_44;

  local_80 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

  local_7c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

  local_90 = local_70;

  local_8c = local_6c;

  local_88 = local_68;

  local_84 = local_64;

  FUN_006c37c0(&local_b0,param_2,param_3);

  FUN_006c2f60(*(uint32_t /* width from decompiler */ *)(param_1 + 0x28),*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c),param_3);

  local_b0 = local_60;

  local_ac = local_5c;

  local_a8 = local_58;

  local_a4 = local_54;

  local_a0 = local_50;

  local_9c = local_4c;

  local_98 = local_48;

  local_94 = local_44;

  local_90 = local_70;

  local_8c = local_6c;

  local_88 = local_68;

  local_84 = local_64;

  FUN_006c35e0(&local_b0,param_2,param_3);

  FUN_006c2f90(param_3);

  return;

}
