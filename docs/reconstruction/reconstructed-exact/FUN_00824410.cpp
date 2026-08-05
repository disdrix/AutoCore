// =============================================================================
// FUN_00824410
// -----------------------------------------------------------------------------
// Stable ID: aa_00824410
// Address:   0x00824410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00824410 @ 0x00824410
// Stable ID: aa_00824410
// Embedded strings (evidence for future rename):
//   - "i_d_s_2d_btn_skill.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, FUN_00824410, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_s_2d_btn_skill.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * FUN_00824410(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4248;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a75a0c;

  *(uint8_t *)((int)param_1 + 0x612) = 0xff;

  *(uint8_t *)((int)param_1 + 0x611) = 0xff;

  *(uint8_t *)(param_1 + 0x184) = 0xff;

  *(uint8_t *)((int)param_1 + 0x613) = 0xff;

  param_1[0x18a] = 0;

  param_1[0x183] = 0;

  param_1[0x182] = 0;

  param_1[0x18b] = 0;

  param_1[0x18c] = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)(param_1 + 0x13f) = 0;

  param_1[0x140] = 0;

  *(uint8_t *)((int)param_1 + 199) = 1;

  param_1[0x185] = 0xffffffff;

  param_1[0x186] = DAT_00a1e820;

  param_1[0x187] = DAT_00a1e824;

  param_1[0x188] = DAT_00a1e828;

  param_1[0x189] = DAT_00a1e82c;

  NDUIWindow_ReloadInterface("i_d_s_2d_btn_skill.xml");

  ExceptionList = local_c;

  return param_1;

}
