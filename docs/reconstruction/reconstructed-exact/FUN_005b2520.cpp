// =============================================================================
// FUN_005b2520
// -----------------------------------------------------------------------------
// Stable ID: aa_005b2520
// Address:   0x005b2520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b2520 @ 0x005b2520
// Stable ID: aa_005b2520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005b2520, FUN_007870c0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_005b2520(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  

  FUN_007870c0();

  fVar1 = g_flMultiKillCountBlend;

  *param_1 = &PTR_LAB_009d953c;

  param_1[0x10] = DAT_009d93e0;

  param_1[0x11] = DAT_009d93e4;

  param_1[0x12] = DAT_009d93e8;

  param_1[0x13] = DAT_009d93ec;

  param_1[0x14] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  *(uint8_t *)(param_1 + 0x15) = 1;

  param_1[0x1a] = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0;

  param_1[0x1d] = 0;

  param_1[0xe] = param_1[0xe] | 8;

  param_1[0x16] = fVar1;

  return param_1;

}
