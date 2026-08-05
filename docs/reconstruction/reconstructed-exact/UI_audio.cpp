// =============================================================================
// UI_audio
// -----------------------------------------------------------------------------
// Stable ID: aa_00820830
// Address:   0x00820830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_audio @ 0x00820830
// Stable ID: aa_00820830
// Embedded strings (evidence for future rename):
//   - "i_o_audio.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00818790, FUN_0081fbe0, UI_audio, NDUIWindow_ReloadInterface, _eh_vector_constructor_iterator_.
//  - Strings: "i_o_audio.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_o_audio.xml"
 * Domain alias of FUN_00820830 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * UI_audio(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8485;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00818790(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a768c4;

  _eh_vector_constructor_iterator_(param_1 + 0x3b9,0x14,9,FUN_00416590,FUN_00417ee0);

  local_4 = CONCAT31(local_4._1_3_,1);

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  *(uint8_t *)(param_1 + 0x3a3) = 0;

  *(uint8_t *)((int)param_1 + 0xe8d) = 0;

  *(uint8_t *)((int)param_1 + 0xe8e) = 1;

  param_1[0x3a4] = 0;

  param_1[0x3a6] = 0;

  param_1[0x3a7] = 0;

  param_1[0x3a8] = 0;

  param_1[0x3a9] = 0;

  param_1[0x3aa] = 0;

  param_1[0x3ab] = 0;

  FUN_0081fbe0();

  NDUIWindow_ReloadInterface("i_o_audio.xml");

  ExceptionList = local_c;

  return param_1;

}
