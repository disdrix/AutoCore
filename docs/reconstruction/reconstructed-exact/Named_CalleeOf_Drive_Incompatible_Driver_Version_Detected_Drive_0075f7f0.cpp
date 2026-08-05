// =============================================================================
// Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive_0075f7f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075f7f0
// Callee of Drive_Incompatible_Driver_Version_Detected_Driver_must
// Address:   0x0075f7f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Incompatible_Driver_Version_Detected_Drive: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~224 non-empty decompiler lines.
//  - Control keywords: if×14, for×4, return×1.
//  - Notable callees: CONCAT31×3, FUN_00463bd0, FUN_0073bfd0, FUN_0073c150, FUN_0073e3a0, FUN_0075f7f0, FUN_00966690, FUN_00966f70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_Incompatible_Driver_Version_Detected_Driver_must
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive_0075f7f0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b271b;

  pvStack_c = ExceptionList;

  DAT_00d1f044 = param_2;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  *param_2 = param_3;

  param_2[1] = param_1;

  param_2[2] = 0;

  param_2[3] = 0;

  param_2[4] = 0;

  FUN_00966690();

  local_4 = CONCAT31(local_4._1_3_,1);

  param_2[0x1cf] = 0;

  param_2[0x1d0] = 0;

  param_2[0x1d1] = 0;

  param_2[0x1d2] = 0;

  param_2[0x1d3] = 0;

  param_2[0x1d4] = 0;

  param_2[0x1d5] = 0;

  param_2[0x1d6] = 0;

  param_2[0x1d7] = 0;

  param_2[0x1d8] = 0;

  param_2[0x1d9] = 0;

  param_2[0x1da] = 0;

  param_2[0x1db] = 0;

  param_2[0x1e7] = 0;

  param_2[0x1e8] = 0;

  param_2[0x1e9] = 0;

  *(uint8_t *)(param_2 + 0x1ea) = 0;

  param_2[0x1eb] = 0;

  (**(code **)(*(int *)param_2[1] + 4))((int *)param_2[1]);

  puVar5 = param_2 + 5;

  for (iVar4 = 0x4c; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  puVar5 = param_2 + 0x51;

  for (iVar4 = 0x4c; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  puVar5 = param_2 + 0xae;

  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  param_2[0x1dd] = 0;

  param_2[0x1de] = 0;

  param_2[0x1df] = 0;

  param_2[0x1e0] = 0;

  param_2[0x1e1] = 0;

  param_2[0x1e2] = 0;

  param_2[0x1e3] = 0;

  param_2[0x1e4] = 0;

  param_2[0x1e5] = 0;

  param_2[0x1e6] = 0;

  puVar5 = param_2 + 0xbc;

  for (iVar4 = 0x113; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  pvVar1 = operator_new(0x20);

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    DAT_00d1f624 = pvVar1;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x14) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x1c) = 0;

  }

  puStack_8._0_1_ = 1;

  param_2[0x1cf] = pvVar1;

  pvVar1 = operator_new(0xc4);

  puStack_8._0_1_ = 5;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0073bfd0();

  }

  puStack_8._0_1_ = 1;

  param_2[0x1d0] = uVar2;

  pvVar1 = operator_new(0x5c);

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    DAT_00d1f630 = pvVar1;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x14) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x38) = 0;

  }

  puStack_8._0_1_ = 1;

  param_2[0x1d1] = pvVar1;

  pvVar3 = operator_new(1);

  pvVar1 = pvVar3;

  if (pvVar3 == (void *)0x0) {

    pvVar3 = (void *)0x0;

    pvVar1 = _DAT_00d1f654;

  }

  _DAT_00d1f654 = pvVar1;

  param_2[0x1d2] = pvVar3;

  pvVar1 = operator_new(0x20);

  puStack_8._0_1_ = 8;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_00986d40(pvVar1);

  }

  puStack_8._0_1_ = 1;

  param_2[0x1d3] = uVar2;

  pvVar1 = operator_new(0x20);

  puStack_8._0_1_ = 9;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_00985df0(pvVar1);

  }

  puStack_8._0_1_ = 1;

  param_2[0x1d4] = uVar2;

  pvVar1 = operator_new(0x34);

  puStack_8._0_1_ = 10;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0096eec0(pvVar1);

  }

  puStack_8._0_1_ = 1;

  param_2[0x1d5] = uVar2;

  pvVar1 = operator_new(0x28);

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    puStack_8._0_1_ = 0xc;

    DAT_00d1f628 = pvVar1;

    FUN_00463bd0(pvVar1);

  }

  puStack_8._0_1_ = 1;

  param_2[0x1d6] = pvVar1;

  pvVar1 = operator_new(0x20);

  puStack_8._0_1_ = 0xd;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_00966f70(pvVar1);

  }

  puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

  param_2[0x1d7] = uVar2;

  pvVar1 = operator_new(0x150);

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_00969df0();

  }

  param_2[0x1d8] = uVar2;

  pvVar1 = operator_new(0x48);

  puStack_8._0_1_ = 0xe;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0073e3a0(pvVar1);

  }

  puStack_8._0_1_ = 1;

  param_2[0x1d9] = uVar2;

  pvVar1 = operator_new(0x5c);

  puStack_8._0_1_ = 0xf;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0073c150(pvVar1);

  }

  puStack_8._0_1_ = 1;

  param_2[0x1da] = uVar2;

  pvVar1 = operator_new(0x10);

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    DAT_00d1f620 = pvVar1;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0xc) = 0;

  }

  puStack_8._0_1_ = 1;

  param_2[0x1db] = pvVar1;

  pvVar1 = operator_new(0x1c);

  puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,0x12);

  if (pvVar1 == (void *)0x0) {

    param_2[0x1dc] = 0;

  }

  else {

    uVar2 = FUN_00987260(pvVar1);

    param_2[0x1dc] = uVar2;

  }

  ExceptionList = pvStack_10;

  return param_2;

}
