// =============================================================================
// FUN_008218b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008218b0
// Address:   0x008218b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008218b0 @ 0x008218b0
// Stable ID: aa_008218b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: InitializeCriticalSection×2, FUN_0066e7d0, FUN_008218b0.
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

uint32_t /* width from decompiler */ * FUN_008218b0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac4c0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0066e7d0();

  local_4 = 0;

  *param_1 = &PTR_FUN_00a76588;

  param_1[5] = &PTR_FUN_00a76580;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[0x15] = 0xffffffff;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 9));

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf));

  *(uint8_t *)(param_1 + 2) = 0;

  param_1[0x16] = 0;

  param_1[3] = 1;

  ExceptionList = local_c;

  return param_1;

}
