// =============================================================================
// FUN_00737860
// -----------------------------------------------------------------------------
// Stable ID: aa_00737860
// Address:   0x00737860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00737860 @ 0x00737860
// Stable ID: aa_00737860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00737860, FUN_00748960.
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

uint32_t /* width from decompiler */ * FUN_00737860(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009af909;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00748960();

  *param_1 = &PTR_FUN_00aa479c;

  param_1[1] = &PTR_LAB_00aa4790;

  param_1[0x32] = 0;

  param_1[0x31] = &PTR_FUN_00a9da78;

  *(uint8_t *)((int)param_1 + 0xcd) = 0;

  *(uint8_t *)(param_1 + 0x33) = 1;

  *(uint8_t *)((int)param_1 + 0xce) = 1;

  param_1[0x35] = 0;

  param_1[0x36] = 0;

  param_1[0x37] = 0;

  param_1[0x39] = 0;

  param_1[0x38] = &PTR_FUN_00a9db18;

  param_1[0x2f] = param_1[0x2f] | 4;

  ExceptionList = local_c;

  return param_1;

}
