// =============================================================================
// Combat_target
// -----------------------------------------------------------------------------
// Stable ID: aa_00839d30
// Address:   0x00839d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Combat_target @ 0x00839d30
// Stable ID: aa_00839d30
// Embedded strings (evidence for future rename):
//   - "i_d_target.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, FUN_00837e10, Combat_target, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_target.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_target.xml"
 * Domain alias of FUN_00839d30 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Combat_target(int *param_1)



{

  uint8_t uVar1;

  int extraout_EDX;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b45c8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a6dfc4;

  FUN_00837e10();

  param_1[0x140] = (int)g_flMultiKillCountBlend;

  uVar1 = (uint8_t)extraout_EDX;

  *(uint8_t *)(param_1 + 0x124) = uVar1;

  *(uint8_t *)((int)param_1 + 0xbf) = uVar1;

  *(uint8_t *)(param_1 + 0x13f) = uVar1;

  param_1[0x141] = 0;

  param_1[0x152] = extraout_EDX;

  param_1[0x142] = extraout_EDX;

  param_1[0x143] = extraout_EDX;

  param_1[0x144] = 0x20;

  param_1[0x145] = 0x20;

  NDUIWindow_ReloadInterface("i_d_target.xml");

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
