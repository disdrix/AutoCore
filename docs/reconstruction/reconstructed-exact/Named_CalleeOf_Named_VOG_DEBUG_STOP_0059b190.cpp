// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0059b190
// -----------------------------------------------------------------------------
// Stable ID: aa_0059b190
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0059b190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_0059cd10×6, FUN_0059cbd0×2, CONCAT31, FUN_0059b110, FUN_0059b190.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_0059b190(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5c16;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0059b110();

  local_4 = 0;

  *param_1 = &PTR_FUN_009d572c;

  pvVar1 = operator_new(0x34);

  local_4._0_1_ = 1;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0059cbd0(1);

  }

  local_4._0_1_ = 0;

  param_1[0x14d] = uVar2;

  pvVar1 = operator_new(0x34);

  local_4._0_1_ = 2;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0059cbd0(1);

  }

  local_4._0_1_ = 0;

  param_1[0x14e] = uVar2;

  pvVar1 = operator_new(0x34);

  local_4._0_1_ = 3;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0059cd10(1);

  }

  local_4._0_1_ = 0;

  param_1[0x14f] = uVar2;

  pvVar1 = operator_new(0x34);

  local_4._0_1_ = 4;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0059cd10(1);

  }

  local_4._0_1_ = 0;

  param_1[0x150] = uVar2;

  pvVar1 = operator_new(0x34);

  local_4._0_1_ = 5;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0059cd10(1);

  }

  local_4._0_1_ = 0;

  param_1[0x151] = uVar2;

  pvVar1 = operator_new(0x34);

  local_4._0_1_ = 6;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0059cd10(1);

  }

  local_4._0_1_ = 0;

  param_1[0x152] = uVar2;

  pvVar1 = operator_new(0x34);

  local_4._0_1_ = 7;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0059cd10(1);

  }

  local_4._0_1_ = 0;

  param_1[0x153] = uVar2;

  pvVar1 = operator_new(0x34);

  local_4 = CONCAT31(local_4._1_3_,8);

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0059cd10(1);

  }

  param_1[0x155] = 1;

  param_1[0x156] = 1;

  param_1[0x157] = 1;

  param_1[0x158] = 1;

  param_1[0x159] = 1;

  param_1[0x15a] = 1;

  param_1[0x15b] = 1;

  param_1[0x154] = uVar2;

  ExceptionList = local_c;

  return param_1;

}
