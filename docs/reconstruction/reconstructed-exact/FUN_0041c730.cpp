// =============================================================================
// FUN_0041c730
// -----------------------------------------------------------------------------
// Stable ID: aa_0041c730
// Address:   0x0041c730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041c730 @ 0x0041c730
// Stable ID: aa_0041c730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0041c730, FUN_0041f640.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0041c730(byte param_1,uint32_t /* width from decompiler */ *param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009be20b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_2 = &PTR_FUN_00a86184;

  param_2[1] = 0;

  param_2[2] = 1 << (param_1 & 0x1f);

  param_2[3] = 0;

  param_2[4] = 0;

  param_2[5] = 0;

  param_2[6] = 0;

  *(byte *)(param_2 + 7) = param_1;

  *(uint8_t *)((int)param_2 + 0x1d) = 0;

  param_2[8] = 0;

  param_2[10] = 0;

  param_2[0xb] = 0;

  param_2[0xc] = 0;

  local_4 = 0;

  FUN_0041f640();

  ExceptionList = local_c;

  return param_2;

}
