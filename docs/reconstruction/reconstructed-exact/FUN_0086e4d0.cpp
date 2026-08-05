// =============================================================================
// FUN_0086e4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0086e4d0
// Address:   0x0086e4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0086e4d0 @ 0x0086e4d0
// Stable ID: aa_0086e4d0
// Embedded strings (evidence for future rename):
//   - "i_d_arena/i_d_arena_tournament_rewards.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0086cea0, FUN_0086e4d0, FUN_0087b890, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_arena/i_d_arena_tournament_rewards.xml".
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

uint32_t /* width from decompiler */ * FUN_0086e4d0(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8afb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  fVar1 = g_flOne;

  local_4 = 0;

  *param_1 = &PTR_FUN_00a5de64;

  param_1[0x14c] = 0;

  param_1[0x14d] = 0;

  param_1[0x14e] = 0;

  param_1[0x14f] = fVar1;

  param_1[0x150] = 0;

  param_1[0x151] = 0;

  param_1[0x152] = 0;

  param_1[0x153] = fVar1;

  param_1[0x154] = 0;

  param_1[0x155] = 0;

  param_1[0x156] = 0;

  param_1[0x157] = fVar1;

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  FUN_0086cea0();

  *(uint8_t *)((int)param_1 + 0xc5) = 0;

  NDUIWindow_ReloadInterface("i_d_arena/i_d_arena_tournament_rewards.xml");

  ExceptionList = local_c;

  return param_1;

}
