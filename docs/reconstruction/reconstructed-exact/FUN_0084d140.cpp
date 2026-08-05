// =============================================================================
// FUN_0084d140
// -----------------------------------------------------------------------------
// Stable ID: aa_0084d140
// Address:   0x0084d140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084d140 @ 0x0084d140
// Stable ID: aa_0084d140
// Embedded strings (evidence for future rename):
//   - "i_d_item.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00844a50, FUN_0084b660, FUN_0084d140, FUN_0087b890.
//  - Strings: "i_d_item.xml".
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

uint32_t /* width from decompiler */ * FUN_0084d140(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8641;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a6939c;

  param_1[0xa9] = param_2;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)(param_1 + 0x14a) = 0;

  param_1[0x148] = 0xffffffff;

  param_1[0x149] = 0xffffffff;

  FUN_00844a50();

  param_1[0x145] = DAT_00a0f298;

  FUN_0084b660("i_d_item.xml");

  ExceptionList = local_c;

  return param_1;

}
