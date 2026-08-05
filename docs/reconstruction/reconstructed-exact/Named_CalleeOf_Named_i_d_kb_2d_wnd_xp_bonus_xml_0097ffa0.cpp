// =============================================================================
// Named_CalleeOf_Named_i_d_kb_2d_wnd_xp_bonus_xml_0097ffa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0097ffa0
// Callee of Named_i_d_kb_2d_wnd_xp_bonus_xml (+1 other named callers)
// Address:   0x0097ffa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_i_d_kb_2d_wnd_xp_bonus_xml: progression/economy helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_i_d_kb_2d_wnd_xp_bonus_xml (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00863f10, FUN_0097ffa0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_i_d_kb_2d_wnd_xp_bonus_xml (+1 other named callers)
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_i_d_kb_2d_wnd_xp_bonus_xml_0097ffa0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4ab6;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00863f10(param_1);

  *param_1 = &PTR_FUN_00a61e44;

  *(uint8_t *)((int)param_1 + 0x4a9) = 0;

  param_1[299] = 0;

  param_1[0x12d] = 0;

  param_1[0x12e] = 0;

  param_1[0x12f] = 0;

  *(uint8_t *)(param_1 + 0x12a) = 1;

  *(uint8_t *)((int)param_1 + 0x4aa) = 1;

  *(uint8_t *)((int)param_1 + 0x4ab) = 1;

  param_1[300] = 1;

  param_1[0x130] = 0;

  param_1[0x131] = 0;

  param_1[0x136] = 0;

  param_1[0x137] = 0;

  param_1[0x132] = 0;

  param_1[0x133] = 0;

  param_1[0x138] = 0;

  param_1[0x139] = 0;

  param_1[0x134] = 0;

  param_1[0x135] = 0;

  param_1[0x13a] = 0;

  param_1[0x13b] = 0;

  param_1[0x13c] = 0;

  param_1[0x13d] = 0;

  ExceptionList = local_c;

  return param_1;

}
