// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008ea770
// -----------------------------------------------------------------------------
// Stable ID: aa_008ea770
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x008ea770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_d_con.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_con.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_008e9090, FUN_008e9df0, FUN_008ea770, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_con.xml".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008ea770(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  float fVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b74e9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a39f94;

  param_1[0x13f] = 8;

  param_1[0x140] = 2;

  FUN_008e9090();

  *(uint8_t *)(param_1 + 0x14f) = 0;

  param_1[0x150] = 1;

  param_1[0x15a] = 0;

  param_1[0x15b] = 0;

  param_1[0x155] = 0;

  param_1[0x156] = DAT_00a0f298;

  fVar1 = (float)DAT_00d1e81c * _DAT_00aaa7d4;

  param_1[0x153] = 2;

  param_1[0x152] = (int)fVar1;

  param_1[0x14b] = 0;

  param_1[0x14c] = 0;

  param_1[0x14d] = 0;

  param_1[0x14e] = 0;

  NDUIWindow_ReloadInterface("i_d_con.xml");

  FUN_008e9df0();

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
