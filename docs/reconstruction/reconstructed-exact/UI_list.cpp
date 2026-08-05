// =============================================================================
// UI_list
// -----------------------------------------------------------------------------
// Stable ID: aa_008b7240
// Address:   0x008b7240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_list @ 0x008b7240
// Stable ID: aa_008b7240
// Embedded strings (evidence for future rename):
//   - "i_d_m_list.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, UI_list, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_m_list.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_m_list.xml"
 * Domain alias of FUN_008b7240 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * UI_list(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b664a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a47b4c;

  param_1[0x13f] = 0;

  param_1[0x140] = 2;

  *(uint8_t *)((int)param_1 + 0xc5) = 0;

  *(uint8_t *)(param_1 + 0x31) = 0;

  param_1[0x146] = 0;

  param_1[0x147] = 0;

  param_1[0x14b] = 0;

  param_1[0x148] = 10;

  param_1[0x14f] = 0;

  param_1[0x150] = 0;

  param_1[0x151] = 0;

  param_1[0x152] = 0;

  param_1[0x153] = 0;

  param_1[0x154] = 0;

  param_1[0x155] = 0;

  param_1[0x157] = 0;

  param_1[0x156] = 0;

  param_1[0x149] = 0;

  param_1[0x14e] = 0;

  param_1[0x145] = 0;

  NDUIWindow_ReloadInterface("i_d_m_list.xml");

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
