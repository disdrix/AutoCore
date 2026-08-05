// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068a690
// -----------------------------------------------------------------------------
// Stable ID: aa_0068a690
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
// Address:   0x0068a690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~167 non-empty decompiler lines.
//  - Control keywords: if×10, for×2, return×1.
//  - Notable callees: FUN_0068d960×2, FUN_006890c0, FUN_0068a690, FUN_0068e8b0, FUN_006962e0, FUN_00698150, FUN_006997c0, FUN_0069dca0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068a690(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *local_18;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  int local_8;

  

  puStack_c = &LAB_009aa215;

  local_10 = ExceptionList;

  local_14 = &stack0xffffff98;

  ExceptionList = &local_10;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 1;

  param_1[7] = 0x3d8f5c29;

  param_1[8] = 0x3f333333;

  param_1[9] = 0x3f000000;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xf] = 0xffffffff;

  param_1[0x10] = 0;

  *(uint8_t *)(param_1 + 0x11) = 0x54;

  *(uint8_t *)((int)param_1 + 0x45) = 0;

  param_1[0x12] = 0xffffffff;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  *(uint16_t *)(param_1 + 0x18) = 0;

  param_1[0x19] = 0;

  *(uint8_t *)(param_1 + 0x1a) = 0;

  *(uint8_t *)((int)param_1 + 0x69) = 0;

  local_8 = 0;

  local_18 = operator_new(0x30);

  local_8._0_1_ = 1;

  if (local_18 == (uint32_t /* width from decompiler */ *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_006997c0();

  }

  local_8._0_1_ = 0;

  param_1[4] = uVar1;

  local_18 = operator_new(0x110);

  local_8._0_1_ = 2;

  if (local_18 == (uint32_t /* width from decompiler */ *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_0068d960(param_1[4],0);

  }

  local_8._0_1_ = 0;

  param_1[1] = uVar1;

  local_18 = operator_new(0x104);

  local_8._0_1_ = 3;

  if (local_18 == (uint32_t /* width from decompiler */ *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_00698150(param_1[1]);

  }

  local_8._0_1_ = 0;

  *param_1 = uVar1;

  local_18 = operator_new(0xb0);

  local_8._0_1_ = 4;

  if (local_18 == (uint32_t /* width from decompiler */ *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_0069dca0();

  }

  local_8._0_1_ = 0;

  param_1[3] = uVar1;

  local_18 = operator_new(0x30);

  local_8._0_1_ = 5;

  if (local_18 == (uint32_t /* width from decompiler */ *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_0068e8b0(param_1[4]);

  }

  local_8._0_1_ = 0;

  param_1[2] = uVar1;

  local_18 = operator_new(0x34);

  local_8._0_1_ = 6;

  if (local_18 == (uint32_t /* width from decompiler */ *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_0069f440();

  }

  local_8._0_1_ = 0;

  param_1[5] = uVar1;

  pvVar2 = operator_new__(0x1c);

  param_1[0x10] = pvVar2;

  puVar3 = operator_new(4);

  param_1[0xc] = puVar3;

  *puVar3 = 1;

  pvVar2 = operator_new(0x10);

  if (pvVar2 == (void *)0x0) {

    pvVar2 = (void *)0x0;

  }

  else {

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0xc) = 0;

  }

  local_8._0_1_ = 0;

  param_1[0xe] = pvVar2;

  local_18 = operator_new(0x6c);

  local_8._0_1_ = 8;

  if (local_18 == (uint32_t /* width from decompiler */ *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_006962e0();

  }

  local_8._0_1_ = 0;

  param_1[0x16] = uVar1;

  local_18 = operator_new(0x110);

  local_8._0_1_ = 9;

  if (local_18 == (uint32_t /* width from decompiler */ *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_0068d960(param_1[4],1);

  }

  param_1[0x17] = uVar1;

  local_8 = (uint)local_8._1_3_ << 8;

  if ((DAT_00d08e98 == 0) ||

     ((uint)(DAT_00d08ea0 - DAT_00d08e98 >> 2) <= (uint)((int)DAT_00d08e9c - DAT_00d08e98 >> 2))) {

    local_18 = param_1;

    FUN_006890c0(DAT_00d08e9c,1,&local_18);

  }

  else {

    puVar3 = DAT_00d08e9c;

    for (iVar4 = 1; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar3 = param_1;

      puVar3 = puVar3 + 1;

    }

    DAT_00d08e9c = DAT_00d08e9c + 1;

  }

  DAT_00d08e58 = DAT_00d08e58 + 1;

  DAT_00d08ec0 = param_1[3];

  *(uint32_t /* width from decompiler */ *)param_1[0x10] = 0;

  *(uint32_t /* width from decompiler */ *)(param_1[0x10] + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1[0x10] + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1[0x10] + 0xc) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1[0x10] + 0x10) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1[0x10] + 0x14) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1[0x10] + 0x18) = 0x3f800000;

  for (iVar4 = 0; iVar4 < 0xc; iVar4 = iVar4 + 1) {

    param_1[iVar4 + 0x1b] = 0;

  }

  ExceptionList = local_10;

  return param_1;

}
