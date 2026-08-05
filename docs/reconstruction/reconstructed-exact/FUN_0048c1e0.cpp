// =============================================================================
// FUN_0048c1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048c1e0
// Address:   0x0048c1e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048c1e0 @ 0x0048c1e0
// Stable ID: aa_0048c1e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0048c1e0.
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

void __fastcall FUN_0048c1e0(uint32_t /* width from decompiler */ *param_1)



{

  param_1[2] = 0xffffffff;

  param_1[1] = 0xffffffff;

  param_1[3] = 0;

  param_1[8] = &DAT_00b03504;

  param_1[4] = 0;

  param_1[5] = 5;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  *param_1 = &PTR_FUN_009c6ee8;

  param_1[0xb] = &DAT_00b03504;

  param_1[0xc] = &DAT_00b03504;

  param_1[0xd] = &DAT_00b03504;

  return;

}
