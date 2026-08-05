// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, FUN_00829ec0, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_npc_2d_btn_mselect.xml".
//  - Return sites: 1.

// =============================================================================
// Mission_i_d_npc_2d_btn_mselect_xml_00829ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_00829ec0
// Address:   0x00829ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_npc_2d_btn_mselect.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Mission_i_d_npc_2d_btn_mselect_xml_00829ec0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b432e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a74484;

  *(uint8_t *)((int)param_1 + 0x4fd) = 0;

  *(uint8_t *)(param_1 + 0x13f) = 0;

  param_1[0x140] = 0xffffffff;

  param_1[0x141] = 0;

  param_1[0x142] = 0;

  param_1[0x143] = 0;

  NDUIWindow_ReloadInterface("i_d_npc_2d_btn_mselect.xml");

  ExceptionList = local_c;

  return param_1;

}
