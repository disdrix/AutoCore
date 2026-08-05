// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, FUN_00828980, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_qb_2d_btn_quickbar.xml".
//  - Return sites: 1.

// =============================================================================
// Skill_i_d_qb_2d_btn_quickbar_xml
// -----------------------------------------------------------------------------
// Stable ID: aa_00828980
// Address:   0x00828980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_qb_2d_btn_quickbar.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Skill_i_d_qb_2d_btn_quickbar_xml(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b42d4;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  uVar2 = DAT_00aaabc4;

  local_4 = 0;

  *param_1 = &PTR_FUN_00a7499c;

  param_1[0x152] = 0;

  param_1[0x154] = 0;

  param_1[0x155] = 0;

  param_1[0x156] = 0;

  param_1[0x157] = 0xffffffff;

  param_1[0x143] = uVar2;

  param_1[0x145] = 0;

  param_1[0x144] = 0;

  fVar1 = g_flMultiKillCountBlend;

  *(uint8_t *)((int)param_1 + 0x4fd) = 0;

  *(uint8_t *)((int)param_1 + 0x4fe) = 0;

  param_1[0x158] = 0;

  param_1[0x159] = 0;

  param_1[0x15a] = 0;

  param_1[0x15b] = 0;

  param_1[0x15f] = 0;

  param_1[0x15c] = 0;

  param_1[0x15d] = 0;

  param_1[0x15e] = 0;

  *(uint8_t *)(param_1 + 0x160) = 0;

  *(uint8_t *)(param_1 + 0x13f) = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)((int)param_1 + 0x4ff) = 0;

  *(uint8_t *)((int)param_1 + 199) = 1;

  param_1[0x140] = 0xffffffff;

  param_1[0x141] = 0xffffffff;

  param_1[0x146] = fVar1;

  NDUIWindow_ReloadInterface("i_d_qb_2d_btn_quickbar.xml");

  ExceptionList = local_c;

  return param_1;

}
