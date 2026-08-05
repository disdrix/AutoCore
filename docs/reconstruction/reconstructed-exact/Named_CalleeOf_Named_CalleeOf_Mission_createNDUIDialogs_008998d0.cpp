// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008998d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008998d0
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x008998d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_d_reg.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_reg.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008525b0, FUN_0087b890, FUN_00898f40, FUN_008998d0, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_reg.xml".
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

int * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008998d0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  int *piVar2;

  void *local_14 [2];

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5f17;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a4e8f4;

  param_1[0x13f] = 0xc;

  param_1[0x140] = 1;

  FUN_00898f40();

  param_1[0x14f] = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  NDUIWindow_ReloadInterface("i_d_reg.xml");

  (**(code **)(*param_1 + 0x34c))();

  pvVar1 = operator_new(0x66c);

  local_4._0_1_ = 1;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_008525b0(pvVar1);

  }

  local_4 = (uint)local_4._1_3_ << 8;

  param_1[0x14d] = (int)piVar2;

  piVar2 = (int *)(**(code **)(*piVar2 + 0x140))(local_14,0);

  param_1[0x151] = *piVar2;

  param_1[0x152] = piVar2[1];

  ExceptionList = local_14[0];

  return param_1;

}
