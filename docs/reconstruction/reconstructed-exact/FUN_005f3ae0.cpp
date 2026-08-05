// =============================================================================
// FUN_005f3ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_005f3ae0
// Address:   0x005f3ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f3ae0 @ 0x005f3ae0
// Stable ID: aa_005f3ae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: CONCAT31, FUN_005d4240, FUN_005e1c80, FUN_005ee750, FUN_005f3ae0, FUN_006c7970.
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

uint32_t /* width from decompiler */ FUN_005f3ae0(float *param_1,float param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uStack_148;

  uint32_t /* width from decompiler */ uStack_144;

  uint32_t /* width from decompiler */ uStack_138;

  uint32_t /* width from decompiler */ uStack_134;

  uint32_t /* width from decompiler */ uStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  uint32_t /* width from decompiler */ uStack_128;

  uint32_t /* width from decompiler */ uStack_124;

  uint32_t /* width from decompiler */ uStack_120;

  uint32_t /* width from decompiler */ uStack_11c;

  uint32_t /* width from decompiler */ uStack_118;

  uint32_t /* width from decompiler */ uStack_114;

  uint32_t /* width from decompiler */ uStack_110;

  uint32_t /* width from decompiler */ uStack_10c;

  uint32_t /* width from decompiler */ uStack_108;

  uint32_t /* width from decompiler */ uStack_104;

  uint32_t /* width from decompiler */ uStack_100;

  uint32_t /* width from decompiler */ uStack_fc;

  uint8_t auStack_f8 [8];

  float local_f0;

  float local_ec;

  float local_e8;

  uint32_t /* width from decompiler */ *local_e4;

  int iStack_dc;

  uint32_t /* width from decompiler */ uStack_c8;

  uint32_t /* width from decompiler */ uStack_c4;

  uint32_t /* width from decompiler */ uStack_c0;

  uint32_t /* width from decompiler */ uStack_bc;

  uint32_t /* width from decompiler */ uStack_b8;

  uint32_t /* width from decompiler */ uStack_b4;

  uint32_t /* width from decompiler */ uStack_b0;

  float fStack_ac;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  float fStack_48;

  uint8_t uStack_34;

  void *pvStack_2c;

  uint32_t /* width from decompiler */ uStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a7978;

  pvStack_1c = ExceptionList;

  local_e8 = param_1[2] * DAT_00a0f298;

  local_ec = param_1[1] * DAT_00a0f298;

  local_f0 = *param_1 * DAT_00a0f298;

  local_e4 = (uint32_t /* width from decompiler */ *)0x0;

  ExceptionList = &pvStack_1c;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x20,0x22);

  *(uint16_t *)(iVar1 + 4) = 0x20;

  pvStack_1c = (void *)0x0;

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_006c7970(auStack_f8,DAT_00af58a0);

  pvStack_1c = (void *)0xffffffff;

  FUN_005e1c80();

  pvStack_1c = (void *)0x1;

  if (param_2 == 0.0) {

    uStack_34 = 7;

  }

  else {

    fStack_48 = param_2;

    uStack_148 = 0;

    uStack_144 = 0;

    uStack_12c = 0;

    uStack_130 = 0;

    uStack_134 = 0;

    uStack_138 = 0;

    uStack_11c = 0;

    uStack_120 = 0;

    uStack_124 = 0;

    uStack_128 = 0;

    uStack_10c = 0;

    uStack_110 = 0;

    uStack_114 = 0;

    uStack_118 = 0;

    uStack_fc = 0;

    uStack_100 = 0;

    uStack_104 = 0;

    uStack_108 = 0;

    FUN_005ee750(auStack_f8,param_2,&uStack_148);

    uStack_88 = uStack_128;

    uStack_84 = uStack_124;

    uStack_80 = uStack_120;

    uStack_7c = uStack_11c;

    uStack_78 = uStack_118;

    uStack_74 = uStack_114;

    uStack_70 = uStack_110;

    uStack_6c = uStack_10c;

    uStack_68 = uStack_108;

    uStack_64 = uStack_104;

    uStack_60 = uStack_100;

    uStack_5c = uStack_fc;

    uStack_34 = 4;

  }

  uStack_b0 = 0;

  uStack_b4 = 0;

  uStack_b8 = 0;

  fStack_ac = g_flOne;

  uStack_c8 = *param_3;

  uStack_c4 = param_3[1];

  uStack_c0 = param_3[2];

  uStack_bc = param_3[3];

  local_e4 = puVar2;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

  *(uint16_t *)(iVar1 + 4) = 0xa0;

  uStack_24._0_1_ = 2;

  uVar3 = FUN_005d4240(&local_f0);

  *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

  uStack_24 = CONCAT31(uStack_24._1_3_,1);

  if (*(short *)((int)puVar2 + 6) == 0) {

    (**(code **)*puVar2)(1);

  }

  uStack_24 = 0xffffffff;

  if (-1 < iStack_dc) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_e4,iStack_dc * 8,0x12);

  }

  ExceptionList = pvStack_2c;

  return uVar3;

}
