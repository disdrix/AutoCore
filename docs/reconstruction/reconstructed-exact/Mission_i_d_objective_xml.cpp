// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00411260, FUN_0087b890, FUN_008a8570, FUN_008a9f40, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_objective.xml".
//  - Return sites: 1.

// =============================================================================
// Mission_i_d_objective_xml
// -----------------------------------------------------------------------------
// Stable ID: aa_008a9f40
// Address:   0x008a9f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_objective.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Mission_i_d_objective_xml(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b63e4;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a4b114;

  FUN_00411260(param_1 + 0x191);

  fVar1 = g_flOne;

  local_4 = CONCAT31(local_4._1_3_,1);

  param_1[0x1aa] = g_flOne;

  param_1[0x1a7] = 0;

  param_1[0x1a8] = 0;

  param_1[0x1a9] = 0;

  param_1[0x1ae] = fVar1;

  param_1[0x1ab] = 0;

  param_1[0x1ac] = 0;

  param_1[0x1ad] = 0;

  param_1[0x1b2] = fVar1;

  param_1[0x1af] = 0;

  param_1[0x1b0] = 0;

  param_1[0x1b1] = 0;

  param_1[0x14b] = fVar1;

  param_1[0x14c] = fVar1;

  param_1[0x14d] = fVar1;

  fVar1 = g_flLevelUpUiBase_Inferred;

  param_1[0x13f] = 0xe;

  param_1[0x140] = 2;

  param_1[0x14a] = 1;

  *(uint8_t *)(param_1 + 0x14e) = 0;

  param_1[400] = 0;

  param_1[399] = 0;

  param_1[0x146] = fVar1;

  param_1[0x147] = 0;

  FUN_008a8570();

  NDUIWindow_ReloadInterface("i_d_objective.xml");

  ExceptionList = local_c;

  return param_1;

}
