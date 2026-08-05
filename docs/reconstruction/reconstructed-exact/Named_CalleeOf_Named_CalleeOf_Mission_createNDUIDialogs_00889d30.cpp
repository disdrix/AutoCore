// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_00889d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00889d30
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x00889d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_d_tabs_c.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_tabs_c.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: CONCAT31, FUN_0087b890, FUN_00889d30, FUN_008c3b80, FUN_008fa9f0, FUN_0090d040, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_tabs_c.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_createNDUIDialogs
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_00889d30(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b93f0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,unaff_EDI);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a546f4;

  param_1[0x13f] = 5;

  param_1[0x140] = 1;

  param_1[0x14c] = 0;

  param_1[0x146] = 0;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  param_1[0x149] = 0;

  param_1[0x14a] = 0;

  param_1[0x14b] = 0;

  param_1[0x12e] = 0;

  param_1[0x12f] = 0;

  param_1[0x12d] = 0;

  param_1[0x141] = 0;

  param_1[0x142] = 0;

  NDUIWindow_ReloadInterface("i_d_tabs_c.xml");

  pvVar1 = operator_new(0x14e0);

  local_4._0_1_ = 1;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_008fa9f0(pvVar1,unaff_EDI);

  }

  local_4._0_1_ = 0;

  param_1[0x143] = uVar2;

  pvVar1 = operator_new(0x588);

  local_4._0_1_ = 2;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_008c3b80(pvVar1);

  }

  local_4._0_1_ = 0;

  param_1[0x144] = uVar2;

  pvVar1 = operator_new(0x5a8);

  local_4 = CONCAT31(local_4._1_3_,3);

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0090d040(pvVar1);

  }

  param_1[0x145] = uVar2;

  ExceptionList = local_c;

  return param_1;

}
