// =============================================================================
// FUN_0086cd10
// -----------------------------------------------------------------------------
// Stable ID: aa_0086cd10
// Address:   0x0086cd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0086cd10 @ 0x0086cd10
// Stable ID: aa_0086cd10
// Embedded strings (evidence for future rename):
//   - "i_d_arena/i_d_arena_tournament_schedule.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_0040fb90, FUN_00869bf0, FUN_0086a8a0, FUN_0086cd10, FUN_0087b890.
//  - Strings: "i_d_arena/i_d_arena_tournament_schedule.xml".
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

uint32_t /* width from decompiler */ * FUN_0086cd10(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8acf;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a5e8e4;

  uVar1 = FUN_0040fb90();

  param_1[0x159] = uVar1;

  param_1[0x15a] = 0;

  local_4 = CONCAT31(local_4._1_3_,1);

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  FUN_00869bf0();

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x145] = 0;

  param_1[0x146] = 0;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  param_1[0x149] = 0;

  uVar1 = DAT_00aaa6b0;

  param_1[0x152] = 0xffffffff;

  param_1[0x153] = 0xffffffff;

  *(uint8_t *)((int)param_1 + 0x529) = 0;

  *(uint8_t *)((int)param_1 + 0xc5) = 0;

  *(uint8_t *)(param_1 + 0x14a) = 0;

  param_1[0x14e] = uVar1;

  param_1[0x14d] = uVar1;

  FUN_0086a8a0("i_d_arena/i_d_arena_tournament_schedule.xml");

  param_1[0x156] = 0;

  *(uint16_t *)(param_1 + 0x157) = 0;

  *(uint16_t *)((int)param_1 + 0x55e) = 0;

  param_1[0x154] = 0;

  param_1[0x155] = 0xffffffff;

  ExceptionList = local_c;

  return param_1;

}
