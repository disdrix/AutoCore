// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_i_d_kb_2d_wnd_xp_bonus_xml_00863f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00863f10
// Callee of Named_CalleeOf_Named_i_d_kb_2d_wnd_xp_bonus_xml
// Address:   0x00863f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_i_d_kb_2d_wnd_xp_bonus_xml: progression/economy helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007b5dd0, FUN_00863f10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_i_d_kb_2d_wnd_xp_bonus_xml
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_i_d_kb_2d_wnd_xp_bonus_xml_00863f10(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b383d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007b5dd0(param_1,0);

  uVar2 = DAT_00aaa8fc;

  param_1[0x122] = 0;

  param_1[0x123] = uVar2;

  uVar2 = DAT_00aaa688;

  param_1[0x125] = 0;

  param_1[0x126] = 0;

  fVar1 = g_flOne;

  *param_1 = &PTR_FUN_00a61a1c;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)(param_1 + 0x129) = 1;

  param_1[0x124] = uVar2;

  param_1[0x127] = fVar1;

  param_1[0x128] = fVar1;

  ExceptionList = local_c;

  return param_1;

}
