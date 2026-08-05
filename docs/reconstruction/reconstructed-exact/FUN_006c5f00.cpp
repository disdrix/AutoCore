// =============================================================================
// FUN_006c5f00
// -----------------------------------------------------------------------------
// Stable ID: aa_006c5f00
// Address:   0x006c5f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c5f00 @ 0x006c5f00
// Stable ID: aa_006c5f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c5c80, FUN_006c5f00.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006c5f00(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  *param_1 = &PTR_FUN_00a0d314;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = 0;

  param_1[3] = param_2;

  *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

  *param_1 = &PTR_FUN_00a0d348;

  param_1[4] = param_3;

  FUN_006c5c80();

  return param_1;

}
