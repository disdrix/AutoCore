// =============================================================================
// Named_CalleeOf_Mission_i_d_tabs_car_2d_tab_mission_xml_008230b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008230b0
// Callee of Mission_i_d_tabs_car_2d_tab_mission_xml
// Address:   0x008230b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_i_d_tabs_car_2d_tab_mission_xml: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, FUN_008230b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_i_d_tabs_car_2d_tab_mission_xml
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Mission_i_d_tabs_car_2d_tab_mission_xml_008230b0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b41f9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  *param_1 = &PTR_FUN_00a75e5c;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x4fe) = s_i_g_tab_btn_xml_00a7632c._0_4_;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x502) = s_i_g_tab_btn_xml_00a7632c._4_4_;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x506) = s_i_g_tab_btn_xml_00a7632c._8_4_;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x50a) = s_i_g_tab_btn_xml_00a7632c._12_4_;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x602) = s_i_g_tab_wnd_name_xml_00a76314._0_4_;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x606) = s_i_g_tab_wnd_name_xml_00a76314._4_4_;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x60a) = s_i_g_tab_wnd_name_xml_00a76314._8_4_;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x60e) = s_i_g_tab_wnd_name_xml_00a76314._12_4_;

  *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x612) = s_i_g_tab_wnd_name_xml_00a76314._16_4_;

  *(char *)((int)param_1 + 0x616) = s_i_g_tab_wnd_name_xml_00a76314[0x14];

  *(uint8_t *)((int)param_1 + 0x706) = 0;

  *(uint8_t *)(param_1 + 0x13f) = 1;

  param_1[0x205] = 0;

  param_1[0x206] = 0;

  param_1[0x12e] = 0;

  param_1[0x12f] = 0;

  param_1[0x12d] = 0;

  ExceptionList = local_c;

  return param_1;

}
