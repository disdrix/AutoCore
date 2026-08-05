// =============================================================================
// UI_macro_btn_macro
// -----------------------------------------------------------------------------
// Stable ID: aa_0082b4c0
// Address:   0x0082b4c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_macro_btn_macro @ 0x0082b4c0
// Stable ID: aa_0082b4c0
// Embedded strings (evidence for future rename):
//   - "i_d_macro_2d_btn_macro.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, UI_macro_btn_macro, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_macro_2d_btn_macro.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_macro_2d_btn_macro.xml"
 * Domain alias of FUN_0082b4c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * UI_macro_btn_macro(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b43ac;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a73a3c;

  *(uint8_t *)((int)param_1 + 0x51e) = 0xff;

  *(uint8_t *)((int)param_1 + 0x51d) = 0xff;

  *(uint8_t *)(param_1 + 0x147) = 0xff;

  *(uint8_t *)((int)param_1 + 0x51f) = 0xff;

  param_1[0x149] = 0;

  param_1[0x14a] = 0;

  param_1[0x14b] = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  param_1[0x140] = 0;

  *(uint8_t *)((int)param_1 + 199) = 1;

  param_1[0x148] = 0xffffffff;

  NDUIWindow_ReloadInterface("i_d_macro_2d_btn_macro.xml");

  param_1[0x146] = 0;

  param_1[0x141] = 0;

  param_1[0x142] = 0;

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x145] = 0;

  ExceptionList = local_c;

  return param_1;

}
