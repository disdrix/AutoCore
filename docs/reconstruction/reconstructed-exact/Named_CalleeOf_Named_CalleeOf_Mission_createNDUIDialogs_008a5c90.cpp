// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008a5c90
// -----------------------------------------------------------------------------
// Stable ID: aa_008a5c90
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x008a5c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_d_q.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_q.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00402dd0, FUN_0040fb90, FUN_00418690, FUN_0087b890, FUN_008a2a30, FUN_008a2c50, FUN_008a5c90.
//  - Strings: "i_d_q.xml".
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

int * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008a5c90(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b6272;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  *param_1 = (int)&PTR_FUN_00a4c61c;

  param_1[0x169] = 0;

  param_1[0x16a] = 0;

  param_1[0x16b] = 0;

  param_1[0x16d] = 0;

  param_1[0x16e] = 0;

  param_1[0x16f] = 0;

  local_4._1_3_ = 0;

  local_4._0_1_ = 2;

  iVar1 = FUN_0040fb90();

  param_1[0x171] = iVar1;

  param_1[0x172] = 0;

  local_4._0_1_ = 3;

  _eh_vector_constructor_iterator_(param_1 + 0x173,0xc,4,FUN_004023f0,FUN_00402280);

  local_4 = CONCAT31(local_4._1_3_,4);

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  FUN_008a2c50();

  param_1[0x146] = 0x9c4a;

  *(uint8_t *)(param_1 + 0x14a) = 0;

  param_1[0x151] = 0;

  param_1[0x143] = 0;

  param_1[0x144] = -1;

  param_1[0x145] = -1;

  FUN_00418690(0);

  FUN_00402dd0(0);

  NDUIWindow_ReloadInterface("i_d_q.xml");

  FUN_008a2a30();

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  param_1[0x147] = 0;

  ExceptionList = local_c;

  return param_1;

}
