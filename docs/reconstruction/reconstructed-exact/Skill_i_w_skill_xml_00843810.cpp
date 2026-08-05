// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, FUN_008434e0, FUN_00843810.
//  - Strings: "i_w_skill.xml".
//  - Return sites: 1.

// =============================================================================
// Skill_i_w_skill_xml_00843810
// -----------------------------------------------------------------------------
// Stable ID: aa_00843810
// Address:   0x00843810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_w_skill.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Skill_i_w_skill_xml_00843810(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b479a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  param_1[0x142] = 1;

  param_1[0x143] = 1;

  param_1[0x13f] = 0;

  uVar1 = DAT_00a0f298;

  param_1[0xa9] = param_2;

  *param_1 = &PTR_FUN_00a6aa2c;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  param_1[0x144] = 0;

  param_1[0x140] = uVar1;

  param_1[0x141] = 4;

  param_1[0x145] = 0;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  param_1[0x149] = 0;

  param_1[0x14a] = 0;

  param_1[0x14b] = 0;

  param_1[0x14c] = 0;

  param_1[0x146] = 0;

  FUN_008434e0("i_w_skill.xml");

  ExceptionList = local_c;

  return param_1;

}
