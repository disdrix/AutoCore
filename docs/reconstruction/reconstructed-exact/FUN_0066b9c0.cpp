// =============================================================================
// FUN_0066b9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0066b9c0
// Address:   0x0066b9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066b9c0 @ 0x0066b9c0
// Stable ID: aa_0066b9c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~133 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c3160×2, FUN_0066b9c0, FUN_006c2fb0, FUN_006c3d90.
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

void __thiscall FUN_0066b9c0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  float *pfVar9;

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

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  uint32_t /* width from decompiler */ local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  uint32_t /* width from decompiler */ local_14;

  

  FUN_006c2fb0(param_2,param_3,param_1 + 0x70,8);

  iVar7 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c);

  fVar1 = *(float *)(param_1 + 0x24);

  fVar2 = *(float *)(param_1 + 0x28);

  fVar3 = *(float *)(param_1 + 0x20);

  pfVar9 = (float *)(iVar7 + 0x80);

  fVar4 = *(float *)(param_1 + 0x30);

  local_80 = *(float *)(iVar7 + 0xa0) * *(float *)(param_1 + 0x38) +

             *(float *)(iVar7 + 0x90) * *(float *)(param_1 + 0x34) + *pfVar9 * fVar4;

  local_7c = *(float *)(iVar7 + 0xa4) * *(float *)(param_1 + 0x38) +

             *(float *)(iVar7 + 0x94) * *(float *)(param_1 + 0x34) +

             fVar4 * *(float *)(iVar7 + 0x84);

  local_78 = *(float *)(iVar7 + 0xa8) * *(float *)(param_1 + 0x38) +

             *(float *)(iVar7 + 0x98) * *(float *)(param_1 + 0x34) +

             fVar4 * *(float *)(iVar7 + 0x88);

  fVar4 = *(float *)(param_1 + 0x40);

  local_74 = 0;

  local_70 = *(float *)(iVar7 + 0xa0) * *(float *)(param_1 + 0x48) +

             *(float *)(iVar7 + 0x90) * *(float *)(param_1 + 0x44) + *pfVar9 * fVar4;

  local_6c = *(float *)(iVar7 + 0xa4) * *(float *)(param_1 + 0x48) +

             *(float *)(iVar7 + 0x94) * *(float *)(param_1 + 0x44) +

             fVar4 * *(float *)(iVar7 + 0x84);

  local_64 = 0;

  fVar5 = *(float *)(param_1 + 0x58);

  local_68 = *(float *)(iVar7 + 0xa8) * *(float *)(param_1 + 0x48) +

             *(float *)(iVar7 + 0x98) * *(float *)(param_1 + 0x44) +

             fVar4 * *(float *)(iVar7 + 0x88);

  iVar8 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c);

  fVar4 = *(float *)(param_1 + 0x54);

  local_90 = *(float *)(iVar8 + 0xb0) +

             *(float *)(iVar7 + 0xa0) * fVar2 + *(float *)(iVar7 + 0x90) * fVar1 + *pfVar9 * fVar3;

  fVar6 = *(float *)(param_1 + 0x50);

  local_8c = *(float *)(iVar8 + 0xb4) +

             *(float *)(iVar7 + 0xa4) * fVar2 + *(float *)(iVar7 + 0x94) * fVar1 +

             fVar3 * *(float *)(iVar7 + 0x84);

  local_88 = *(float *)(iVar8 + 0xb8) +

             *(float *)(iVar7 + 0xa8) * fVar2 + *(float *)(iVar7 + 0x98) * fVar1 +

             fVar3 * *(float *)(iVar7 + 0x88);

  local_84 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0xbc);

  iVar7 = *(int *)(*(int *)(param_1 + 0x10) + 0x3c);

  fVar1 = *(float *)(param_1 + 0x68);

  fVar2 = *(float *)(param_1 + 100);

  fVar3 = *(float *)(param_1 + 0x60);

  local_50 = *(float *)(iVar7 + 0xa0) * fVar1 + *(float *)(iVar7 + 0x90) * fVar2 +

             *(float *)(iVar7 + 0x80) * fVar3;

  local_4c = *(float *)(iVar7 + 0x84) * fVar3 + *(float *)(iVar7 + 0xa4) * fVar1 +

             *(float *)(iVar7 + 0x94) * fVar2;

  local_48 = *(float *)(iVar7 + 0x88) * fVar3 + *(float *)(iVar7 + 0xa8) * fVar1 +

             *(float *)(iVar7 + 0x98) * fVar2;

  local_44 = 0.0;

  iVar8 = *(int *)(*(int *)(param_1 + 0x10) + 0x3c);

  local_60 = *(float *)(iVar8 + 0xb0) +

             *(float *)(iVar7 + 0xa0) * fVar5 + *(float *)(iVar7 + 0x90) * fVar4 +

             *(float *)(iVar7 + 0x80) * fVar6;

  local_5c = *(float *)(iVar8 + 0xb4) +

             *(float *)(iVar7 + 0x84) * fVar6 + *(float *)(iVar7 + 0xa4) * fVar5 +

             *(float *)(iVar7 + 0x94) * fVar4;

  local_58 = *(float *)(iVar8 + 0xb8) +

             *(float *)(iVar7 + 0x88) * fVar6 + *(float *)(iVar7 + 0xa8) * fVar5 +

             *(float *)(iVar7 + 0x98) * fVar4;

  local_54 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0xbc);

  local_14 = 0;

  local_34 = 0;

  local_24 = 0.0;

  local_40 = local_70;

  local_3c = local_6c;

  local_38 = local_68;

  local_30 = local_50;

  local_2c = local_4c;

  local_28 = local_48;

  local_20 = local_80;

  local_1c = local_7c;

  local_18 = local_78;

  FUN_006c3160(&local_40,param_2,param_3);

  local_20 = local_70;

  local_1c = local_6c;

  local_18 = local_68;

  local_14 = local_64;

  local_40 = local_80;

  local_3c = local_7c;

  local_38 = local_78;

  local_34 = local_74;

  local_30 = 0.0 - local_50;

  local_2c = 0.0 - local_4c;

  local_28 = 0.0 - local_48;

  local_24 = 0.0 - local_44;

  FUN_006c3160(&local_40,param_2,param_3);

  FUN_006c3d90(&local_90,&local_60,param_2,param_3);

  return;

}
