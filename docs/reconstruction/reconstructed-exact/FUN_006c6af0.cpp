// =============================================================================
// FUN_006c6af0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c6af0
// Address:   0x006c6af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c6af0 @ 0x006c6af0
// Stable ID: aa_006c6af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c6af0.
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

void __fastcall FUN_006c6af0(uint32_t /* width from decompiler */ *param_1)



{

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = 0;

  *param_1 = &PTR_FUN_00a0d3c8;

  param_1[3] = 0x3d4ccccd;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0x80000000;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0x80000000;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0x80000000;

  return;

}
