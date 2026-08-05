// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, FUN_0082a3a0, FUN_0082a8b0.
//  - Strings: "i_d_q_2d_btn_mission.xml".
//  - Return sites: 1.

// =============================================================================
// Mission_i_d_q_2d_btn_mission_xml
// -----------------------------------------------------------------------------
// Stable ID: aa_0082a8b0
// Address:   0x0082a8b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_q_2d_btn_mission.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Mission_i_d_q_2d_btn_mission_xml(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4388;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a73f24;

  param_1[0x149] = 0;

  param_1[0x14a] = 0;

  param_1[0x14b] = 0;

  param_1[0x14c] = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)((int)param_1 + 0x4ff) = 0;

  *(uint8_t *)((int)param_1 + 0x4fe) = 0;

  *(uint8_t *)(param_1 + 0x13f) = 0;

  *(uint8_t *)((int)param_1 + 0x4fd) = 1;

  param_1[0x140] = 0;

  param_1[0x141] = 0;

  param_1[0x142] = 0;

  FUN_0082a3a0("i_d_q_2d_btn_mission.xml");

  ExceptionList = local_c;

  return param_1;

}
