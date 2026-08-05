// =============================================================================
// FUN_00835ef0
// -----------------------------------------------------------------------------
// Stable ID: aa_00835ef0
// Address:   0x00835ef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00835ef0 @ 0x00835ef0
// Stable ID: aa_00835ef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~163 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_00404d80×4, FUN_00757890×3, CONCAT13×2, FUN_006a3db0×2, FUN_008358c0×2, FUN_00835ef0, GetTickCount.
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



void FUN_00835ef0(void)



{

  uint32_t /* width from decompiler */ uVar1;

  uint8_t uVar2;

  int in_EAX;

  DWORD DVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  undefined *puVar7;

  uint32_t /* width from decompiler */ local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  float local_48;

  float local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  float local_38;

  uint32_t /* width from decompiler */ local_34;

  float local_30;

  float local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  float local_4;

  

  DVar3 = GetTickCount();

  iVar4 = DVar3 - *(int *)(in_EAX + 0x498);

  fVar5 = (float)iVar4;

  if (iVar4 < 0) {

    fVar5 = fVar5 + _DAT_00aaa5dc;

  }

  FUN_008358c0(DAT_00aaa68c - fVar5 * _DAT_00aaab5c,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x4b8));

  iVar4 = DVar3 - *(int *)(in_EAX + 0x49c);

  fVar5 = (float)iVar4;

  if (iVar4 < 0) {

    fVar5 = fVar5 + _DAT_00aaa5dc;

  }

  FUN_008358c0(DAT_00aaa68c - fVar5 * _DAT_00aaab5c,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x4b8));

  uVar1 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x4b8);

  iVar4 = DVar3 - *(int *)(in_EAX + 0x4a0);

  fVar5 = (float)iVar4;

  if (iVar4 < 0) {

    fVar5 = fVar5 + _DAT_00aaa5dc;

  }

  if (DAT_00aaa664 <= DAT_00aaa68c - fVar5 * _DAT_00aaab5c) {

    uVar2 = FUN_006a3db0();

    local_84._0_3_ = (undefined3)uVar1;

    local_84 = CONCAT13(uVar2,(undefined3)local_84);

    fVar5 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80) * DAT_00a0f298;

    fVar6 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * DAT_00a0f298;

    FUN_00404d80(&local_80,8,4,FUN_005edf20);

    FUN_00404d80(&local_60,0x18,4,&LAB_00413510);

    local_7c = fVar6 - (float)*(int *)(in_EAX + 0x4b4);

    local_80 = (float)(*(int *)(in_EAX + 0x4a8) / 2) + fVar5;

    local_78 = (float)-(*(int *)(in_EAX + 0x4a8) / 2) + fVar5;

    local_6c = local_7c - (float)*(int *)(in_EAX + 0x4ac);

    local_58 = 0;

    local_40 = 0;

    local_28 = 0;

    local_10 = 0;

    local_50 = 0;

    local_4c = 0;

    local_54 = local_84;

    local_38 = g_flOne;

    local_34 = 0;

    local_3c = local_84;

    local_20 = g_flOne;

    local_24 = local_84;

    local_c = local_84;

    puVar7 = *(undefined **)(in_EAX + 0x494);

    local_1c = g_flOne;

    local_8 = 0;

    local_4 = g_flOne;

    if (puVar7 == (undefined *)0x0) {

      puVar7 = &DAT_00d1ec78;

    }

    local_74 = local_7c;

    local_70 = local_78;

    local_68 = local_80;

    local_64 = local_6c;

    local_60 = local_80;

    local_5c = local_7c;

    local_48 = local_78;

    local_44 = local_7c;

    local_30 = local_78;

    local_2c = local_6c;

    local_18 = local_80;

    local_14 = local_6c;

    FUN_00757890(&local_60,4,puVar7,1,&DAT_00d1ecac);

  }

  iVar4 = DVar3 - *(int *)(in_EAX + 0x4a4);

  uVar1 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x4b8);

  fVar5 = (float)iVar4;

  if (iVar4 < 0) {

    fVar5 = fVar5 + _DAT_00aaa5dc;

  }

  if (DAT_00aaa664 <= DAT_00aaa68c - fVar5 * _DAT_00aaab5c) {

    uVar2 = FUN_006a3db0();

    local_84._0_3_ = (undefined3)uVar1;

    local_84 = CONCAT13(uVar2,(undefined3)local_84);

    fVar5 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80) * DAT_00a0f298;

    fVar6 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * DAT_00a0f298;

    FUN_00404d80(&local_80,8,4,FUN_005edf20);

    FUN_00404d80(&local_60,0x18,4,&LAB_00413510);

    local_7c = fVar6 + (float)*(int *)(in_EAX + 0x4b4);

    local_80 = (float)-(*(int *)(in_EAX + 0x4a8) / 2) + fVar5;

    local_78 = (float)(*(int *)(in_EAX + 0x4a8) / 2) + fVar5;

    local_6c = (float)*(int *)(in_EAX + 0x4ac) + fVar6 + (float)*(int *)(in_EAX + 0x4b4);

    local_58 = 0;

    local_40 = 0;

    local_28 = 0;

    local_10 = 0;

    local_50 = 0;

    local_4c = 0;

    local_54 = local_84;

    local_38 = g_flOne;

    local_34 = 0;

    local_3c = local_84;

    local_24 = local_84;

    local_c = local_84;

    local_20 = g_flOne;

    local_1c = g_flOne;

    local_8 = 0;

    local_4 = g_flOne;

    local_74 = local_7c;

    local_70 = local_78;

    local_68 = local_80;

    local_64 = local_6c;

    local_60 = local_80;

    local_5c = local_7c;

    local_48 = local_78;

    local_44 = local_7c;

    local_30 = local_78;

    local_2c = local_6c;

    local_18 = local_80;

    local_14 = local_6c;

    if (*(int *)(in_EAX + 0x494) != 0) {

      FUN_00757890(&local_60,4,*(int *)(in_EAX + 0x494),1,&DAT_00d1ecac);

      return;

    }

    FUN_00757890(&local_60,4,&DAT_00d1ec78,1,&DAT_00d1ecac);

  }

  return;

}
