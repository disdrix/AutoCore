// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004d8270
// -----------------------------------------------------------------------------
// Stable ID: aa_004d8270
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs
// Address:   0x004d8270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~294 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: FUN_00560ec0×4, FUN_005d4240×4, FUN_006c7970×4, FUN_004d8270, FUN_005e1c80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004d8270(int param_1)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puStack_1cc;

  float *pfStack_1c8;

  float fStack_1c4;

  uint32_t /* width from decompiler */ *puStack_1c0;

  float *pfStack_1bc;

  uint32_t /* width from decompiler */ uStack_1b8;

  uint32_t /* width from decompiler */ uStack_1b4;

  uint32_t /* width from decompiler */ *puStack_1b0;

  float *pfStack_1ac;

  float fStack_1a8;

  uint8_t *puStack_1a4;

  float *pfStack_1a0;

  uint32_t /* width from decompiler */ uStack_19c;

  uint32_t /* width from decompiler */ uStack_198;

  uint32_t /* width from decompiler */ uStack_194;

  float fStack_17c;

  int local_178;

  float local_174;

  float local_170;

  uint32_t /* width from decompiler */ local_16c;

  float local_168;

  float local_164;

  float fStack_160;

  float fStack_15c;

  int *piStack_158;

  float local_154;

  float local_150;

  uint32_t /* width from decompiler */ local_14c;

  uint32_t /* width from decompiler */ local_148;

  int local_144;

  uint32_t /* width from decompiler */ local_140;

  int *local_13c;

  int local_138;

  uint32_t /* width from decompiler */ local_134;

  uint32_t /* width from decompiler */ local_130;

  uint32_t /* width from decompiler */ local_12c;

  float local_128;

  float local_124;

  int *local_120;

  int local_11c;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ local_114;

  uint8_t auStack_110 [4];

  uint32_t /* width from decompiler */ uStack_10c;

  float local_108;

  int *local_104;

  uint32_t /* width from decompiler */ local_100;

  float fStack_fc;

  uint32_t /* width from decompiler */ uStack_f8;

  uint32_t /* width from decompiler */ uStack_f0;

  uint32_t /* width from decompiler */ uStack_ec;

  float fStack_e8;

  float fStack_e4;

  float fStack_e0;

  uint32_t /* width from decompiler */ uStack_dc;

  uint32_t /* width from decompiler */ uStack_d8;

  uint32_t /* width from decompiler */ uStack_d4;

  uint32_t /* width from decompiler */ uStack_d0;

  uint32_t /* width from decompiler */ uStack_cc;

  uint8_t auStack_a4 [24];

  void *pvStack_8c;

  uint8_t auStack_88 [4];

  uint32_t /* width from decompiler */ uStack_84;

  uint8_t uStack_78;

  uint8_t uStack_70;

  uint8_t auStack_6c [8];

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint8_t uStack_5c;

  uint8_t uStack_54;

  uint8_t auStack_50 [16];

  uint8_t uStack_40;

  uint8_t uStack_38;

  uint8_t uStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a2220;

  pvStack_1c = ExceptionList;

  iVar1 = *(int *)(param_1 + 0xe4f8);

  local_108 = (float)*(int *)(iVar1 + 0x10) * *(float *)(iVar1 + 0x18);

  local_104 = (int *)((float)*(int *)(iVar1 + 0x14) * *(float *)(iVar1 + 0x18));

  local_170 = (local_108 + g_flOne) * DAT_00a0f298;

  local_16c = DAT_00a0f520;

  local_168 = DAT_00a110d8;

  local_174 = ((float)local_104 + g_flOne) * DAT_00a0f298;

  local_164 = 0.0;

  uStack_194 = 0x4d832e;

  ExceptionList = &pvStack_1c;

  local_178 = param_1;

  local_154 = local_170;

  FUN_005e1c80();

  uStack_194 = 0x22;

  local_144 = 0;

  local_148 = 0;

  local_14c = 0;

  local_134 = 0;

  local_138 = 0;

  local_140 = 0;

  local_124 = 0.0;

  local_12c = 0;

  local_130 = 0;

  local_150 = g_flOne;

  local_13c = (int *)g_flOne;

  local_128 = g_flOne;

  local_114 = 0;

  local_118 = 0;

  local_11c = 0;

  local_120 = (int *)0x0;

  uStack_198 = 0x20;

  local_14 = 0;

  uStack_19c = 0x4d83b4;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))();

  *(uint16_t *)(iVar1 + 4) = 0x20;

  uStack_19c = DAT_00af58a0;

  pfStack_1a0 = (float *)&local_178;

  pvStack_1c._0_1_ = 1;

  puStack_1a4 = (uint8_t *)0x4d83d9;

  piVar2 = (int *)FUN_006c7970();

  fStack_e8 = fStack_15c;

  fStack_e4 = 0.0;

  uStack_dc = 0;

  uStack_60 = 0;

  uStack_64 = 0;

  pvStack_1c = (void *)((uint)pvStack_1c._1_3_ << 8);

  fStack_e0 = DAT_00a110d8;

  uStack_d8 = DAT_00b03810;

  uStack_d4 = DAT_00b03814;

  uStack_d0 = DAT_00b03818;

  uStack_19c = 0x28;

  uStack_cc = DAT_00b0381c;

  local_108 = 2.8026e-45;

  uStack_54 = 7;

  pfStack_1a0 = (float *)0xa0;

  puStack_1a4 = (uint8_t *)0x4d8499;

  local_104 = piVar2;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))();

  *(uint16_t *)(iVar1 + 4) = 0xa0;

  puStack_1a4 = auStack_110;

  uStack_24 = 2;

  fStack_1a8 = 7.118947e-39;

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_005d4240();

  local_130 = uStack_f0;

  local_12c = uStack_ec;

  puStack_1a4 = auStack_50;

  local_128 = fStack_e8;

  fStack_1a8 = 0.1;

  pfStack_1ac = &fStack_160;

  local_124 = fStack_e4;

  uStack_24 = 0;

  puStack_1b0 = (uint32_t /* width from decompiler */ *)0x4d851b;

  (**(code **)(*piVar2 + 0x18))();

  *(short *)((int)piVar2 + 6) = *(short *)((int)piVar2 + 6) + -1;

  if (*(short *)((int)piVar2 + 6) == 0) {

    puStack_1b0 = (uint32_t /* width from decompiler */ *)0x1;

    uStack_1b4 = 0x4d852e;

    (**(code **)*piVar2)();

  }

  uStack_1b4 = 0x4d853e;

  puStack_1b0 = puVar3;

  FUN_00560ec0();

  *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

  if (*(short *)((int)puVar3 + 6) == 0) {

    puStack_1b0 = (uint32_t /* width from decompiler */ *)0x1;

    uStack_1b4 = 0x4d8551;

    (**(code **)*puVar3)();

  }

  puStack_1b0 = (uint32_t /* width from decompiler */ *)0x22;

  uStack_1b4 = 0x20;

  uStack_1b8 = 0x4d8591;

  pfStack_1a0 = (float *)(**(code **)(*DAT_00b05060 + 0x10))();

  *(uint16_t *)((int)pfStack_1a0 + 4) = 0x20;

  uStack_1b8 = DAT_00af58a0;

  pfStack_1bc = (float *)&uStack_194;

  uStack_38 = 3;

  puStack_1c0 = (uint32_t /* width from decompiler */ *)0x4d85b6;

  piVar2 = (int *)FUN_006c7970();

  local_104 = (int *)local_178;

  fStack_fc = local_128 - DAT_00a110d8;

  uStack_1b8 = 0x28;

  local_100 = 0;

  uStack_f8 = 0;

  pfStack_1bc = (float *)0xa0;

  uStack_38 = 0;

  puStack_1c0 = (uint32_t /* width from decompiler */ *)0x4d8616;

  local_120 = piVar2;

  fStack_1a8 = (float)(**(code **)(*DAT_00b05060 + 0x10))();

  *(uint16_t *)((int)fStack_1a8 + 4) = 0xa0;

  puStack_1c0 = &local_12c;

  uStack_40 = 4;

  fStack_1c4 = 7.11948e-39;

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_005d4240();

  local_14c = uStack_10c;

  local_148 = local_108;

  puStack_1c0 = (uint32_t /* width from decompiler */ *)auStack_6c;

  local_144 = (int)local_104;

  fStack_1c4 = 0.1;

  pfStack_1c8 = &fStack_17c;

  local_140 = local_100;

  uStack_40 = 0;

  puStack_1cc = (uint32_t /* width from decompiler */ *)0x4d8698;

  (**(code **)(*piVar2 + 0x18))();

  *(short *)((int)piVar2 + 6) = *(short *)((int)piVar2 + 6) + -1;

  if (*(short *)((int)piVar2 + 6) == 0) {

    puStack_1cc = (uint32_t /* width from decompiler */ *)0x1;

    (**(code **)*piVar2)();

  }

  puStack_1cc = puVar3;

  FUN_00560ec0();

  *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

  if (*(short *)((int)puVar3 + 6) == 0) {

    puStack_1cc = (uint32_t /* width from decompiler */ *)0x1;

    (**(code **)*puVar3)();

  }

  fStack_1a8 = DAT_00a110d8;

  puStack_1a4 = (uint8_t *)DAT_00a0f520;

  pfStack_1a0 = pfStack_1ac;

  puStack_1cc = (uint32_t /* width from decompiler */ *)0x22;

  uStack_19c = 0;

  uVar4 = 0x20;

  pfStack_1bc = (float *)(**(code **)(*DAT_00b05060 + 0x10))(0x20);

  *(uint16_t *)((int)pfStack_1bc + 4) = 0x20;

  uStack_54 = 5;

  piVar2 = (int *)FUN_006c7970(&puStack_1b0,DAT_00af58a0);

  local_120 = (int *)DAT_00a110d8;

  local_11c = 0;

  local_118 = uStack_1b4;

  local_114 = 0;

  uStack_54 = 0;

  local_13c = piVar2;

  fStack_1c4 = (float)(**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

  *(uint16_t *)((int)fStack_1c4 + 4) = 0xa0;

  uStack_5c = 6;

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_005d4240(&local_148);

  local_168 = local_128;

  local_164 = local_124;

  fStack_160 = (float)local_120;

  fStack_15c = (float)local_11c;

  uStack_5c = 0;

  (**(code **)(*piVar2 + 0x18))(&uStack_198,0x3dcccccd,auStack_88);

  *(short *)((int)piVar2 + 6) = *(short *)((int)piVar2 + 6) + -1;

  if (*(short *)((int)piVar2 + 6) == 0) {

    (**(code **)*piVar2)(1);

  }

  FUN_00560ec0(puVar3);

  *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

  if (*(short *)((int)puVar3 + 6) == 0) {

    (**(code **)*puVar3)(1);

  }

  fStack_1c4 = DAT_00a110d8;

  puStack_1c0 = (uint32_t /* width from decompiler */ *)DAT_00a0f520;

  pfStack_1bc = pfStack_1c8;

  uStack_1b8 = 0;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x20,0x22);

  *(uint16_t *)(iVar1 + 4) = 0x20;

  uStack_70 = 7;

  piVar2 = (int *)FUN_006c7970(&puStack_1cc,DAT_00af58a0);

  local_13c = (int *)(local_164 - DAT_00a110d8);

  local_138 = 0;

  local_130 = 0;

  uStack_70 = 0;

  piStack_158 = piVar2;

  local_134 = uVar4;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

  *(uint16_t *)(iVar1 + 4) = 0xa0;

  uStack_78 = 8;

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_005d4240(&local_164);

  fStack_17c = (float)local_13c;

  local_178 = local_138;

  uStack_78 = 0;

  (**(code **)(*piVar2 + 0x18))(&uStack_1b4,0x3dcccccd,auStack_a4);

  *(short *)((int)piVar2 + 6) = *(short *)((int)piVar2 + 6) + -1;

  if (*(short *)((int)piVar2 + 6) == 0) {

    (**(code **)*piVar2)(1);

  }

  FUN_00560ec0(puVar3);

  *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

  if (*(short *)((int)puVar3 + 6) == 0) {

    (**(code **)*puVar3)(1);

  }

  uStack_84 = 0xffffffff;

  if (-1 < (int)fStack_15c) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_164,(int)fStack_15c * 8,0x12);

  }

  ExceptionList = pvStack_8c;

  return;

}
