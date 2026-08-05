// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_00542aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00542aa0
// Callee of Named_Client_InitInstance
// Address:   0x00542aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT31, FUN_0040f400, FUN_0041c420, FUN_00541e70, FUN_00542aa0, FUN_00543800, FUN_00543840, FUN_007b8770.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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



uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_Client_InitInstance_00542aa0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            char param_5)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4142;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009d057c;

  iVar1 = FUN_0040f400();

  param_1[2] = iVar1;

  *(uint8_t *)(iVar1 + 0x15) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[2] + 4) = param_1[2];

  *(uint32_t /* width from decompiler */ *)param_1[2] = param_1[2];

  *(uint32_t /* width from decompiler */ *)(param_1[2] + 8) = param_1[2];

  param_1[3] = 0;

  local_4 = 0;

  _eh_vector_constructor_iterator_(param_1 + 4,0x10,0xee,FUN_004565f0,FUN_00691630);

  local_4._0_1_ = 1;

  param_1[0x3bc] = 0;

  iVar1 = FUN_00543800();

  param_1[0x3be] = iVar1;

  *(uint8_t *)(iVar1 + 0x7d) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x3be] + 4) = param_1[0x3be];

  *(uint32_t /* width from decompiler */ *)param_1[0x3be] = param_1[0x3be];

  *(uint32_t /* width from decompiler */ *)(param_1[0x3be] + 8) = param_1[0x3be];

  param_1[0x3bf] = 0;

  local_4._0_1_ = 2;

  iVar1 = FUN_00543840();

  param_1[0x3c1] = iVar1;

  *(uint8_t *)(iVar1 + 0x65) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x3c1] + 4) = param_1[0x3c1];

  *(uint32_t /* width from decompiler */ *)param_1[0x3c1] = param_1[0x3c1];

  *(uint32_t /* width from decompiler */ *)(param_1[0x3c1] + 8) = param_1[0x3c1];

  param_1[0x3c2] = 0;

  local_4._0_1_ = 3;

  param_1[0x3c3] = 0;

  param_1[0x3c4] = 0;

  param_1[0x3c5] = 0;

  param_1[0x3c6] = 0;

  param_1[0x3c7] = 0;

  param_1[0x3c8] = 0;

  uVar2 = FUN_0041c420();

  param_1[0x3ca] = uVar2;

  param_1[0x3cb] = 0;

  local_4._0_1_ = 4;

  _DAT_00b046a0 = param_1;

  pvVar3 = operator_new(0x560);

  local_4._0_1_ = 5;

  if (pvVar3 == (void *)0x0) {

    DAT_00b0469c = 0;

  }

  else {

    DAT_00b0469c = FUN_007b8770();

  }

  local_4 = CONCAT31(local_4._1_3_,4);

  if (param_5 == '\0') {

    FUN_00541e70(param_2,param_3,param_4);

  }

  ExceptionList = local_c;

  return param_1;

}
