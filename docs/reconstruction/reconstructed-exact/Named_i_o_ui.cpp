// =============================================================================
// Named_i_o_ui
// -----------------------------------------------------------------------------
// Stable ID: aa_0081c460
// Address:   0x0081c460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_o_ui @ 0x0081c460
// Stable ID: aa_0081c460
// Embedded strings (evidence for future rename):
//   - "i_o_ui.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00818790, FUN_0081bc50, Named_i_o_ui, NDUIWindow_ReloadInterface.
//  - Strings: "i_o_ui.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_o_ui.xml"
 * Domain alias of FUN_0081c460 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Named_i_o_ui(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b83e9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00818790(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a789dc;

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  FUN_0081bc50();

  NDUIWindow_ReloadInterface("i_o_ui.xml");

  ExceptionList = local_c;

  return param_1;

}
