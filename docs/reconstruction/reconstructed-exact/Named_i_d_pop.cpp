// =============================================================================
// Named_i_d_pop
// -----------------------------------------------------------------------------
// Stable ID: aa_008a7640
// Address:   0x008a7640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_d_pop @ 0x008a7640
// Stable ID: aa_008a7640
// Embedded strings (evidence for future rename):
//   - "i_d_pop.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, Named_i_d_pop, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_pop.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_pop.xml"
 * Domain alias of FUN_008a7640 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Named_i_d_pop(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b6303;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a4c0c4;

  param_1[0x14c] = 0;

  param_1[0x14d] = 0;

  param_1[0x14e] = 0;

  param_1[0x14f] = 0;

  param_1[0x150] = 0;

  param_1[0x151] = 0;

  param_1[0x152] = 0;

  param_1[0x153] = 0;

  param_1[0x154] = 0;

  param_1[0x155] = 0;

  *(uint8_t *)(param_1 + 0x13f) = 1;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)((int)param_1 + 0x4fd) = 0;

  NDUIWindow_ReloadInterface("i_d_pop.xml");

  ExceptionList = local_c;

  return param_1;

}
