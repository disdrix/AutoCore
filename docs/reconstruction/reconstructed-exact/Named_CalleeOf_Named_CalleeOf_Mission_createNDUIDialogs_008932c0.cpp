// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008932c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008932c0
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x008932c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_d_stances.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_stances.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_00892820, FUN_008932c0, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_stances.xml".
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

int * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008932c0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  float fVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5c1b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  fVar1 = g_flMultiKillCountBlend;

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a5132c;

  param_1[0x13f] = 0;

  param_1[0x140] = 2;

  param_1[0x143] = -1;

  param_1[0x145] = 0;

  param_1[0x144] = (int)fVar1;

  param_1[0x146] = 0;

  FUN_00892820();

  NDUIWindow_ReloadInterface("i_d_stances.xml");

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
