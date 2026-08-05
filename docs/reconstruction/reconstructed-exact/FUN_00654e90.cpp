// =============================================================================
// FUN_00654e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00654e90
// Address:   0x00654e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00654e90 @ 0x00654e90
// Stable ID: aa_00654e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006523b0, FUN_00654e90.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00654e90(uint32_t /* width from decompiler */ *param_1)



{

  FUN_006523b0();

  param_1[5] = &PTR_LAB_009e3a68;

  param_1[6] = &PTR_LAB_009db1d0;

  *param_1 = &PTR_FUN_009e5da0;

  param_1[2] = &PTR_LAB_009e5d98;

  param_1[5] = &PTR_LAB_009e5d88;

  param_1[6] = &PTR_LAB_009e5d80;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0x80000000;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0x80000000;

  return param_1;

}
