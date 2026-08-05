// =============================================================================
// FUN_008358c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008358c0
// Address:   0x008358c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008358c0 @ 0x008358c0
// Stable ID: aa_008358c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: return×3, if×2, goto×2, switch×1.
//  - Notable callees: FUN_00404d80×2, FUN_00757890×2, CONCAT13, FUN_006a3db0, FUN_008358c0.
//  - Return sites: 3.

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

void FUN_008358c0(float param_1,undefined3 param_2)



{

  uint8_t uVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ unaff_ESI;

  float fVar4;

  float fVar5;

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

  

  if (param_1 < DAT_00aaa664) {

    return;

  }

  uVar1 = FUN_006a3db0();

  _param_2 = CONCAT13(uVar1,param_2);

  fVar4 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80) * DAT_00a0f298;

  fVar5 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * DAT_00a0f298;

  FUN_00404d80(&local_80,8,4,FUN_005edf20);

  FUN_00404d80(&local_60,0x18,4,&LAB_00413510);

  local_58 = 0;

  local_40 = 0;

  local_28 = 0;

  local_10 = 0;

  switch(unaff_ESI) {

  case 0:

    iVar2 = -(*(int *)(in_EAX + 0x4a8) / 2);

    local_78 = fVar4 - (float)*(int *)(in_EAX + 0x4b0);

    iVar3 = *(int *)(in_EAX + 0x4a8) / 2;

    local_70 = local_78 - (float)*(int *)(in_EAX + 0x4ac);

    break;

  case 1:

    iVar2 = *(int *)(in_EAX + 0x4a8) / 2;

    local_78 = (float)*(int *)(in_EAX + 0x4b0) + fVar4;

    iVar3 = -(*(int *)(in_EAX + 0x4a8) / 2);

    local_70 = (float)*(int *)(in_EAX + 0x4ac) + (float)*(int *)(in_EAX + 0x4b0) + fVar4;

    break;

  case 2:

    iVar2 = *(int *)(in_EAX + 0x4a8) / 2;

    local_74 = fVar5 - (float)*(int *)(in_EAX + 0x4b4);

    iVar3 = -(*(int *)(in_EAX + 0x4a8) / 2);

    local_6c = local_74 - (float)*(int *)(in_EAX + 0x4ac);

    goto LAB_00835b4c;

  case 3:

    iVar2 = -(*(int *)(in_EAX + 0x4a8) / 2);

    local_74 = (float)*(int *)(in_EAX + 0x4b4) + fVar5;

    iVar3 = *(int *)(in_EAX + 0x4a8) / 2;

    local_6c = (float)*(int *)(in_EAX + 0x4ac) + (float)*(int *)(in_EAX + 0x4b4) + fVar5;

LAB_00835b4c:

    local_70 = (float)iVar3 + fVar4;

    local_80 = (float)iVar2 + fVar4;

    local_7c = local_74;

    local_78 = local_70;

    local_68 = local_80;

    local_64 = local_6c;

  default:

    goto switchD_0083599a_default;

  }

  local_74 = (float)iVar3 + fVar5;

  local_7c = (float)iVar2 + fVar5;

  local_80 = local_78;

  local_6c = local_74;

  local_68 = local_70;

  local_64 = local_7c;

switchD_0083599a_default:

  local_60 = local_80;

  local_5c = local_7c;

  local_30 = local_70;

  local_48 = local_78;

  local_2c = local_6c;

  local_54 = _param_2;

  local_3c = _param_2;

  local_24 = _param_2;

  local_c = _param_2;

  local_44 = local_74;

  local_18 = local_68;

  local_50 = 0;

  local_4c = 0;

  local_38 = g_flOne;

  local_34 = 0;

  local_20 = g_flOne;

  local_1c = g_flOne;

  local_14 = local_64;

  local_8 = 0;

  local_4 = g_flOne;

  if (*(int *)(in_EAX + 0x494) == 0) {

    FUN_00757890(&local_60,4,&DAT_00d1ec78,1,&DAT_00d1ecac);

    return;

  }

  FUN_00757890(&local_60,4,*(int *)(in_EAX + 0x494),1,&DAT_00d1ecac);

  return;

}
