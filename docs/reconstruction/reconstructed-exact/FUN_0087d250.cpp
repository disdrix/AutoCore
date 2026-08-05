// =============================================================================
// FUN_0087d250
// -----------------------------------------------------------------------------
// Stable ID: aa_0087d250
// Address:   0x0087d250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0087d250 @ 0x0087d250
// Stable ID: aa_0087d250
// Embedded strings (evidence for future rename):
//   - "i_d_way.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, FUN_0087d250, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_way.xml".
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

uint32_t /* width from decompiler */ * FUN_0087d250(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5341;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a58774;

  *(uint8_t *)(param_1 + 0x14a) = 1;

  *(uint8_t *)((int)param_1 + 0x529) = 0;

  param_1[0x14b] = 0;

  param_1[0x14d] = 0;

  param_1[0x14c] = 0;

  param_1[0x148] = 0;

  param_1[0x149] = 0;

  param_1[0x13f] = 0;

  param_1[0x140] = 0;

  NDUIWindow_ReloadInterface("i_d_way.xml");

  ExceptionList = local_c;

  return param_1;

}
