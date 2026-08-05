// =============================================================================
// FUN_00862380
// -----------------------------------------------------------------------------
// Stable ID: aa_00862380
// Address:   0x00862380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00862380 @ 0x00862380
// Stable ID: aa_00862380
// Embedded strings (evidence for future rename):
//   - "i_d_gm.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, FUN_00862380, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_gm.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * FUN_00862380(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4a5e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a62ca4;

  *(uint8_t *)((int)param_1 + 0x512) = 0xff;

  *(uint8_t *)((int)param_1 + 0x511) = 0xff;

  *(uint8_t *)(param_1 + 0x144) = 0xff;

  *(uint8_t *)((int)param_1 + 0x513) = 0xff;

  param_1[0x13f] = 0;

  param_1[0x140] = 0;

  param_1[0x141] = 0;

  param_1[0x142] = 0;

  *(uint8_t *)(param_1 + 0x143) = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  param_1[0x144] = DAT_00afdf0c;

  param_1[0x146] = 0xffffffff;

  param_1[0x147] = 0xffffffff;

  NDUIWindow_ReloadInterface("i_d_gm.xml");

  param_1[0x148] = DAT_00aaa8dc;

  param_1[0x149] = g_flLevelUpUiBase_Inferred;

  ExceptionList = local_c;

  return param_1;

}
