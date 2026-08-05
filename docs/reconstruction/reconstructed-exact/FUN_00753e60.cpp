// =============================================================================
// FUN_00753e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00753e60
// Address:   0x00753e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00753e60 @ 0x00753e60
// Stable ID: aa_00753e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00753e60, FUN_00759860, FUN_0076c4d0, FUN_0076c500.
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

uint32_t /* width from decompiler */ * FUN_00753e60(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &DAT_009b3fb2;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00759860();

  *param_1 = &PTR_FUN_00a9f974;

  FUN_0076c500(1000);

  param_1[0x3a] = 0;

  param_1[0x3b] = 0;

  *(uint8_t *)(param_1 + 0x3c) = 0;

  *(uint8_t *)((int)param_1 + 0xf1) = 0;

  *(uint8_t *)((int)param_1 + 0xf2) = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  param_1[0x40] = 1;

  param_1[0x42] = 0;

  param_1[0x43] = 0;

  param_1[0x44] = 0;

  param_1[0x45] = 0;

  FUN_0076c4d0();

  *(uint8_t *)((int)param_1 + 0xf2) = 0;

  ExceptionList = local_c;

  return param_1;

}
