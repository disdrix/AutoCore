// =============================================================================
// FUN_007822a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007822a0
// Address:   0x007822a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007822a0 @ 0x007822a0
// Stable ID: aa_007822a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: block×5, FUN_007822a0, FUN_00975ec0.
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

/* WARNING: Removing unreachable block (ram,0x007822be) */

/* WARNING: Removing unreachable block (ram,0x007822d3) */

/* WARNING: Removing unreachable block (ram,0x007822c8) */

/* WARNING: Removing unreachable block (ram,0x007822dc) */

/* WARNING: Removing unreachable block (ram,0x007822e6) */



uint32_t /* width from decompiler */ * __fastcall FUN_007822a0(uint32_t /* width from decompiler */ *param_1)



{

  FUN_00975ec0();

  *param_1 = &PTR_LAB_00a9b834;

  param_1[0x8a] = 0;

  param_1[0x8a] = 0;

  param_1[0x86] = 0;

  *(uint8_t *)(param_1 + 0x85) = 0;

  *(uint8_t *)((int)param_1 + 0x215) = 0;

  param_1[0x82] = 0;

  param_1[0x88] = 0;

  param_1[0x89] = 0;

  param_1[0x87] = 0;

  param_1[0x83] = 0;

  return param_1;

}
