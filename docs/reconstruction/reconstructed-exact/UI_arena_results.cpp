// =============================================================================
// UI_arena_results
// -----------------------------------------------------------------------------
// Stable ID: aa_00872e00
// Address:   0x00872e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_arena_results @ 0x00872e00
// Stable ID: aa_00872e00
// Embedded strings (evidence for future rename):
//   - "i_d_arena/i_d_arena_results.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00413170, FUN_00870680, FUN_00870920, UI_arena_results, FUN_0087b890, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_arena/i_d_arena_results.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_arena/i_d_arena_results.xml"
 * Domain alias of FUN_00872e00 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * UI_arena_results(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8f1d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a5c66c;

  FUN_00413170(param_1 + 0x18a);

  local_4 = CONCAT31(local_4._1_3_,1);

  param_1[0x13f] = 0;

  param_1[0x140] = 1;

  FUN_00870920();

  param_1[0x143] = 0xffffffff;

  *(uint16_t *)(param_1 + 0x144) = 0;

  param_1[0x195] = 0;

  *(uint8_t *)(param_1 + 0x152) = 0;

  param_1[0x158] = 0;

  param_1[0x159] = 0;

  param_1[0x15a] = 0;

  param_1[0x153] = 0x9c44;

  *(uint8_t *)(param_1 + 0x154) = 0;

  param_1[0x155] = 0;

  param_1[0x156] = 10000;

  *(uint8_t *)(param_1 + 0x157) = 0;

  FUN_00870680(0xffffffff);

  param_1[0x146] = 0xffffffff;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  param_1[0x149] = 0xffffffff;

  param_1[0x14a] = 0;

  param_1[0x14b] = 0;

  param_1[0x14c] = 0xffffffff;

  param_1[0x14d] = 0;

  param_1[0x14e] = 0;

  param_1[0x14f] = 0xffffffff;

  param_1[0x150] = 0;

  param_1[0x151] = 0;

  NDUIWindow_ReloadInterface("i_d_arena/i_d_arena_results.xml");

  ExceptionList = local_c;

  return param_1;

}
