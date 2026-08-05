// READABILITY (auto CF):
//  - Body size: ~305 non-empty decompiler lines.
//  - Control keywords: if×9, return×1.
//  - Notable callees: FUN_00631dc0×3, CONCAT31×2, FUN_0055e680, FUN_0055ea20, FUN_00560ec0, FUN_00561e20, FUN_005d4240, FUN_005e1c80.
//  - Strings: "]. **"; "], used with code built with ["; "** Havok libs built with version ["; "C:\\vog\\1_code\\havok230\\include\\hkdynamics2\\world\\hkWorld.cpp".
//  - Return sites: 1.

// =============================================================================
// Named_hkWorld_00561e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00561e20
// Address:   0x00561e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "hkWorld"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __thiscall Named_hkWorld_00561e20(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  float fVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t *puVar5;

  code *pcStack_320;

  uint32_t /* width from decompiler */ *puStack_31c;

  uint32_t /* width from decompiler */ uStack_318;

  uint32_t /* width from decompiler */ *puStack_314;

  uint32_t /* width from decompiler */ uStack_310;

  int iStack_30c;

  uint32_t /* width from decompiler */ *puStack_308;

  char *pcStack_304;

  uint32_t /* width from decompiler */ *puStack_300;

  char *pcStack_2fc;

  char *pcStack_2f8;

  char *local_2f4;

  uint8_t local_210 [524];

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009d2974;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0x80000000;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0x80000000;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0x80000000;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0x80000000;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0x80000000;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0x80000000;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  param_1[0x1a] = 0x80000000;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0;

  param_1[0x1d] = 0x80000000;

  param_1[0x1e] = 0;

  param_1[0x1f] = 0;

  param_1[0x20] = 0x80000000;

  param_1[0x21] = 0;

  param_1[0x22] = 0;

  param_1[0x23] = 0x80000000;

  param_1[0x24] = 0;

  param_1[0x25] = 0;

  param_1[0x26] = 0x80000000;

  param_1[0x27] = 0;

  param_1[0x28] = 0;

  param_1[0x29] = 0x80000000;

  param_1[0x2a] = 0;

  param_1[0x2b] = 0;

  param_1[0x2c] = 0x80000000;

  param_1[0x2d] = 0;

  param_1[0x2e] = 0;

  param_1[0x2f] = 0x80000000;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0x80000000;

  param_1[0x3f] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0x80000000;

  param_1[0x42] = 0;

  param_1[0x43] = 0;

  param_1[0x44] = 0x80000000;

  param_1[0x45] = 0;

  param_1[0x46] = 0;

  param_1[0x47] = 0x80000000;

  param_1[0x48] = 0;

  param_1[0x49] = 0;

  param_1[0x4a] = 0x80000000;

  if (param_3 != 0x4f4c) {

    local_2f4 = (char *)CONCAT31((int3)((uint)param_1 >> 8),1);

    pcStack_2f8 = (char *)0x200;

    pcStack_2fc = local_210;

    puStack_300 = (uint32_t /* width from decompiler */ *)0x561f77;

    FUN_00631ff0();

    local_2f4 = "]. **";

    pcStack_2f8 = (char *)param_3;

    pcStack_2fc = "], used with code built with [";

    puStack_300 = (uint32_t /* width from decompiler */ *)0x4f4c;

    pcStack_304 = "** Havok libs built with version [";

    puStack_308 = (uint32_t /* width from decompiler */ *)0x561f95;

    FUN_00631dc0();

    pcStack_304 = (char *)0x561f9c;

    FUN_00631e10();

    puStack_300 = (uint32_t /* width from decompiler */ *)0x561fa3;

    FUN_00631dc0();

    pcStack_2fc = (char *)0x561faa;

    FUN_00631e60();

    pcStack_2f8 = (char *)0x561fb1;

    FUN_00631dc0();

    local_2f4 = (char *)0xa66;

    pcStack_2f8 = "C:\\vog\\1_code\\havok230\\include\\hkdynamics2\\world\\hkWorld.cpp";

    pcStack_2fc = local_210;

    puStack_300 = (uint32_t /* width from decompiler */ *)0x53c94b42;

    pcStack_304 = "Error";

    puStack_308 = (uint32_t /* width from decompiler */ *)0x561fd8;

    (**(code **)(*DAT_00bc56d0 + 8))();

    local_2f4 = (char *)0x561fe1;

    FUN_00632030();

  }

  param_1[0x4c] = 1;

  param_1[0x4d] = 0xfffffff;

  param_1[0x38] = *param_2;

  param_1[0x39] = param_2[1];

  param_1[0x3a] = param_2[2];

  param_1[0x3b] = param_2[3];

  *(uint8_t *)(param_1 + 0x8f) = *(uint8_t *)(param_2 + 4);

  *(uint8_t *)((int)param_1 + 0x23d) = *(uint8_t *)(param_2 + 0x21);

  param_1[0xc] = param_2[0x22];

  param_1[0xd] = param_2[0x23];

  param_1[0x84] = param_2[8];

  param_1[0x85] = param_2[9];

  param_1[0x86] = param_2[10];

  param_1[0x87] = param_2[0xb];

  param_1[0x88] = param_2[0xc];

  param_1[0x89] = param_2[0xd];

  param_1[0x8a] = param_2[0xe];

  param_1[0x8b] = param_2[0xf];

  param_1[0x8c] = param_2[0x10];

  local_2f4 = (char *)0x1c;

  pcStack_2f8 = (char *)0x80;

  pcStack_2fc = (char *)0x5620a5;

  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))();

  *(uint16_t *)(iVar2 + 4) = 0x80;

  pcStack_2fc = (char *)param_2[0x10];

  puStack_300 = param_1 + 0x88;

  pcStack_304 = (char *)(param_1 + 0x84);

  puStack_308 = (uint32_t /* width from decompiler */ *)0x5620c4;

  uVar3 = FUN_0062da40();

  param_1[0x31] = uVar3;

  iVar2 = param_2[5];

  param_1[0x8d] = iVar2;

  param_1[0x8e] = iVar2 / 2;

  pcStack_2fc = (char *)0x22;

  puStack_300 = (uint32_t /* width from decompiler */ *)0x104;

  pcStack_304 = (char *)0x5620f0;

  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))();

  if (iVar2 == 0) {

    uVar3 = 0;

  }

  else {

    pcStack_304 = (char *)0x5620fb;

    uVar3 = FUN_006cac20();

  }

  param_1[0x4e] = uVar3;

  pcStack_304 = (char *)0x1c;

  puStack_308 = (uint32_t /* width from decompiler */ *)0x4;

  iStack_30c = 0x562114;

  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))();

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar4 = &PTR_LAB_009d27b4;

  }

  param_1[0x4f] = puVar4;

  *(uint32_t /* width from decompiler */ **)(param_1[0x4e] + 0x28) = puVar4;

  *(uint32_t /* width from decompiler */ *)(param_1[0x4e] + 0x44) = param_1[0x4f];

  *(uint32_t /* width from decompiler */ *)(param_1[0x4e] + 0x48) = param_1[0x4f];

  iStack_30c = 0x1d;

  uStack_310 = 0xc;

  puStack_314 = (uint32_t /* width from decompiler */ *)0x56215e;

  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))();

  *(uint16_t *)(iVar2 + 4) = 0xc;

  uStack_318 = 0x56216c;

  puStack_314 = param_1;

  puStack_300 = (uint32_t /* width from decompiler */ *)FUN_0062b380();

  puStack_314 = (uint32_t /* width from decompiler */ *)0x22;

  uStack_318 = 0x4da8;

  puStack_31c = (uint32_t /* width from decompiler */ *)0x562182;

  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))();

  puStack_31c = puStack_308;

  pcStack_320 = FUN_006cb7d0;

  *(uint16_t *)(iVar2 + 4) = 0x4da8;

  uVar3 = FUN_006cb5e0();

  param_1[0x32] = uVar3;

  *(short *)((int)puStack_308 + 6) = *(short *)((int)puStack_308 + 6) + -1;

  if (*(short *)((int)puStack_308 + 6) == 0) {

    puStack_31c = (uint32_t /* width from decompiler */ *)0x1;

    pcStack_320 = (code *)0x5621b4;

    (**(code **)*puStack_308)();

  }

  puStack_31c = (uint32_t /* width from decompiler */ *)0x22;

  pcStack_320 = (code *)0x18;

  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))();

  *(uint16_t *)(puVar4 + 1) = 0x18;

  *(uint16_t *)((int)puVar4 + 6) = 1;

  puVar4[2] = &PTR_LAB_009d27b0;

  puVar4[3] = &PTR_LAB_009d2784;

  puVar4[4] = &PTR_LAB_009d278c;

  puVar4[5] = &PTR_LAB_009d27b0;

  *puVar4 = &PTR_FUN_009d280c;

  puVar4[2] = &PTR_LAB_009e7ae8;

  puVar4[3] = &PTR_LAB_009d2804;

  puVar4[4] = &PTR_LAB_009d27fc;

  puVar4[5] = &PTR_LAB_009e7ae8;

  param_1[0x34] = puVar4;

  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))(0x10,0x1a);

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar4 = 0;

    puVar4[1] = 0;

    puVar4[2] = 0;

    puVar4[3] = 0;

  }

  param_1[0x33] = puVar4;

  *puVar4 = param_1[0x32];

  *(uint32_t /* width from decompiler */ *)(param_1[0x33] + 8) = param_2[0x18];

  puVar5 = (uint8_t *)(**(code **)(*DAT_00b05060 + 0x10))(0x20,0x1a);

  fVar1 = g_flMultiKillCountBlend;

  if (puVar5 == (uint8_t *)0x0) {

    puVar5 = (uint8_t *)0x0;

  }

  else {

    *(float *)(puVar5 + 4) = g_flMultiKillCountBlend;

    *(float *)(puVar5 + 8) = fVar1;

    *(uint32_t /* width from decompiler */ *)(puVar5 + 0xc) = 0;

    uVar3 = DAT_00a0f718;

    *puVar5 = 1;

    puVar5[0x14] = 1;

    *(uint32_t /* width from decompiler */ *)(puVar5 + 0x18) = uVar3;

    *(uint32_t /* width from decompiler */ *)(puVar5 + 0x1c) = 0x14;

  }

  *(uint8_t **)(param_1[0x33] + 0xc) = puVar5;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1[0x33] + 0xc) + 4) = param_2[0x1a];

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1[0x33] + 0xc) + 8) = param_2[0x1b];

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1[0x33] + 0xc) + 0xc) = param_2[0x1c];

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1[0x33] + 0xc) + 0x10) = param_2[0x1d];

  **(uint8_t **)(param_1[0x33] + 0xc) = *(uint8_t *)(param_2 + 0x19);

  *(uint8_t *)(*(int *)(param_1[0x33] + 0xc) + 0x14) = *(uint8_t *)(param_2 + 0x1e);

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1[0x33] + 0xc) + 0x18) = param_2[0x1f];

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1[0x33] + 0xc) + 0x1c) = param_2[0x20];

  if (param_1[0x34] == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = param_1[0x34] + 0xc;

  }

  *(int *)(param_1[0x33] + 4) = iVar2;

  FUN_0055e680();

  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0xa8,0x2d);

  *(uint16_t *)(iVar2 + 4) = 0xa8;

  iVar2 = FUN_006295f0(param_1);

  param_1[0xb] = iVar2;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x24) = 0xffffffff;

  *(uint8_t *)(param_1[0xb] + 0x29) = 0;

  *(uint8_t *)(param_1[0xb] + 0x30) = 1;

  FUN_005e1c80();

  iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

  *(uint16_t *)(iVar2 + 4) = 0xa0;

  uVar3 = FUN_005d4240(&pcStack_320);

  param_1[0xe] = uVar3;

  FUN_00560ec0(uVar3);

  if (-1 < iStack_30c) {

    (**(code **)(*DAT_00b05060 + 0x14))(puStack_314,iStack_30c * 8,0x12);

  }

  fVar1 = g_flOne;

  puVar4 = (uint32_t /* width from decompiler */ *)param_1[0x33];

  param_1[0x50] = *puVar4;

  param_1[0x51] = puVar4[1];

  param_1[0x52] = puVar4[2];

  param_1[0x53] = puVar4[3];

  param_1[0x58] = fVar1;

  param_1[0x59] = param_2[0x11];

  param_1[0x5a] = param_2[0x12];

  param_1[0x5b] = (float)param_2[0x11] * DAT_00a0f298;

  uVar3 = param_2[0x13];

  param_1[0x5f] = uVar3;

  param_1[0x60] = fVar1 / (float)(int)param_2[0x13];

  param_1[0x5e] = DAT_009c8354;

  param_1[0x6b] = param_1[0x60];

  param_1[0x6a] = param_1[0x5e];

  param_1[0x54] = 0;

  param_1[0x95] = 0;

  *(uint8_t *)((int)param_1 + 0x23e) = 0;

  *(uint8_t *)(param_1 + 0x90) = 0;

  if (*(char *)(param_2 + 0x14) != '\0') {

    FUN_0055ea20(CONCAT31((int3)((uint)uVar3 >> 8),*(uint8_t *)((int)param_2 + 0x51)));

  }

  fVar1 = (float)param_2[0x15];

  param_1[0x91] = fVar1;

  param_1[0x92] = (float)param_2[0x16] * fVar1;

  param_1[0x93] = param_2[0x17];

  puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))(8,4);

  *(uint16_t *)(puVar4 + 1) = 8;

  *(uint16_t *)((int)puVar4 + 6) = 1;

  *puVar4 = &PTR_LAB_009d27f4;

  *(uint8_t *)(param_1 + 0x4b) = 0;

  param_1[0x94] = puVar4;

  param_1[0x30] = 0;

  *(uint8_t *)((int)param_1 + 0x12d) = 0;

  return param_1;

}
