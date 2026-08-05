// =============================================================================
// FUN_0076c0b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c0b0
// Address:   0x0076c0b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076c0b0 @ 0x0076c0b0
// Stable ID: aa_0076c0b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076c0b0, realloc.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0076c0b0(uint32_t /* width from decompiler */ *param_1,size_t param_2)



{

  void *pvVar1;

  

  *param_1 = &PTR_FUN_00a9d184;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = param_2;

  *(uint8_t *)(param_1 + 5) = 1;

  *(uint8_t *)((int)param_1 + 0x15) = 1;

  pvVar1 = realloc((void *)0x0,param_2);

  param_1[1] = pvVar1;

  return param_1;

}
