// =============================================================================
// UI_craft
// -----------------------------------------------------------------------------
// Stable ID: aa_008e6490
// Address:   0x008e6490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_craft @ 0x008e6490
// Stable ID: aa_008e6490
// Embedded strings (evidence for future rename):
//   - "i_d_craft.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040ecd0×2, CONCAT31, FUN_0087b890, FUN_008e39f0, UI_craft, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_craft.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_craft.xml"
 * Domain alias of FUN_008e6490 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * UI_craft(int *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7466;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a3a86c;

  FUN_0040ecd0();

  local_4._0_1_ = 1;

  FUN_0040ecd0();

  local_4 = CONCAT31(local_4._1_3_,2);

  param_1[0x200] = 0;

  param_1[0x201] = 0;

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  FUN_008e39f0();

  *(uint8_t *)(param_1 + 0x124) = 0;

  param_1[0x1e4] = 0;

  param_1[0x1e3] = 0;

  param_1[0x1e6] = 0;

  param_1[0x1e5] = 0;

  param_1[0x1e8] = 0;

  param_1[0x1e7] = 0;

  param_1[0x1ea] = 0;

  param_1[0x1e9] = 0;

  param_1[0x1ec] = 0;

  param_1[0x1eb] = 0;

  param_1[0x1ee] = 0;

  param_1[0x1ed] = 0;

  param_1[0x1f0] = 0x40;

  param_1[0x1ef] = 0x40;

  NDUIWindow_ReloadInterface("i_d_craft.xml");

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
