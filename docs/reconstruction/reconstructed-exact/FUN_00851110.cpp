// =============================================================================
// FUN_00851110
// -----------------------------------------------------------------------------
// Stable ID: aa_00851110
// Address:   0x00851110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00851110 @ 0x00851110
// Stable ID: aa_00851110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0084f610×4, CONCAT11, CONCAT12, CONCAT13, CONCAT21, FUN_00757890, FUN_00851110.
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

void FUN_00851110(void)



{

  byte *pbVar1;

  uint8_t uVar2;

  uint3 uVar3;

  int *in_EAX;

  int *piVar4;

  int iVar5;

  undefined *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ local_b8;

  uint32_t /* width from decompiler */ local_b0;

  uint32_t /* width from decompiler */ local_a8;

  int local_98;

  int local_94;

  int local_90;

  int local_8c;

  int local_88;

  int local_84;

  uint8_t local_80 [4];

  int local_7c;

  float local_78;

  float local_74;

  uint local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  float local_60;

  float local_5c;

  uint local_54;

  float local_50;

  uint32_t /* width from decompiler */ local_4c;

  float local_48;

  float local_44;

  uint local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  uint local_24;

  uint32_t /* width from decompiler */ local_20;

  float local_1c;

  uint8_t local_18 [20];

  

  local_b0 = 0;

  local_a8 = DAT_00af932c;

  piVar4 = (int *)FUN_0084f610(local_80);

  iVar5 = *piVar4;

  local_7c = piVar4[1];

  local_b0 = DAT_00af9328;

  local_a8 = DAT_00af932c;

  piVar4 = (int *)FUN_0084f610(&local_98);

  local_88 = *piVar4;

  local_84 = piVar4[1];

  local_b0 = DAT_00af9328;

  local_a8 = 0;

  piVar4 = (int *)FUN_0084f610(&local_b8);

  local_90 = *piVar4;

  local_8c = piVar4[1];

  local_b0 = 0;

  local_a8 = 0;

  piVar4 = (int *)FUN_0084f610(local_18);

  local_98 = *piVar4;

  local_94 = piVar4[1];

  pbVar1 = (byte *)in_EAX[0x89];

  local_b8 = DAT_00afdf0c;

  if (pbVar1 != (byte *)0x0) {

    uVar2 = (uint8_t)(((uint)pbVar1[2] * (DAT_00afdf0c >> 0x10 & 0xff)) / 0xff);

    local_b8._0_3_ = CONCAT12(uVar2,(short)DAT_00afdf0c);

    uVar3 = (uint3)local_b8;

    local_b8 = (uint)(uint3)local_b8;

    local_b8 = CONCAT13((char)(((uint)pbVar1[3] * (uint)*(byte *)((int)in_EAX + 0x22b)) / 0xff),

                        CONCAT21(CONCAT11(uVar2,(char)(((uint)pbVar1[1] * (uVar3 >> 8 & 0xff)) /

                                                      0xff)),

                                 (char)(((uint)*pbVar1 * (local_b8 & 0xff)) / 0xff)));

  }

  local_48 = (float)local_90;

  local_78 = (float)iVar5;

  local_74 = (float)local_7c;

  local_60 = (float)local_88;

  local_44 = (float)local_8c;

  local_5c = (float)local_84;

  local_30 = (float)local_98;

  local_2c = (float)local_94;

  local_68 = 0;

  local_64 = 0;

  local_50 = g_flOne;

  local_4c = 0;

  local_38 = g_flOne;

  local_34 = g_flOne;

  local_20 = 0;

  local_1c = g_flOne;

  local_6c = local_b8;

  local_54 = local_b8;

  local_3c = local_b8;

  local_24 = local_b8;

  iVar5 = (**(code **)(*in_EAX + 700))();

  puVar8 = &DAT_00d1ecac;

  uVar7 = 1;

  if (iVar5 == 0) {

    puVar6 = &DAT_00d1ec78;

  }

  else {

    puVar6 = (undefined *)(**(code **)(*in_EAX + 700))(1,&DAT_00d1ecac);

  }

  FUN_00757890(&local_78,4,puVar6,uVar7,puVar8);

  in_EAX[0x1a] = in_EAX[0x1a] + 1;

  iVar5 = in_EAX[0x1a];

  in_EAX[0x1d] = (int)(float)-iVar5;

  if (in_EAX[0x1c] < iVar5) {

    in_EAX[0x1c] = iVar5;

  }

  return;

}
