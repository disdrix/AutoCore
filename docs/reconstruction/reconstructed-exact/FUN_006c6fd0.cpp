// =============================================================================
// FUN_006c6fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c6fd0
// Address:   0x006c6fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c6fd0 @ 0x006c6fd0
// Stable ID: aa_006c6fd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c6fd0.
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

void __fastcall FUN_006c6fd0(uint32_t /* width from decompiler */ *param_1)



{

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = &PTR_LAB_009d27b0;

  param_1[3] = &PTR_LAB_009d2784;

  param_1[4] = &PTR_LAB_009d278c;

  param_1[5] = &PTR_LAB_009d27b0;

  *param_1 = &PTR_FUN_00a0d41c;

  param_1[2] = &PTR_LAB_00a0d418;

  param_1[3] = &PTR_FUN_00a0d410;

  param_1[4] = &PTR_LAB_00a0d408;

  param_1[5] = &PTR_LAB_00a0d404;

  param_1[7] = 0xffffffff;

  param_1[8] = 0xffffffff;

  param_1[9] = 0xffffffff;

  param_1[10] = 0xffffffff;

  param_1[0xb] = 0xffffffff;

  param_1[0xc] = 0xffffffff;

  param_1[0xd] = 0xffffffff;

  param_1[0xe] = 0xffffffff;

  param_1[0xf] = 0xffffffff;

  param_1[0x10] = 0xffffffff;

  param_1[0x11] = 0xffffffff;

  param_1[0x12] = 0xffffffff;

  param_1[0x13] = 0xffffffff;

  param_1[0x14] = 0xffffffff;

  param_1[0x15] = 0xffffffff;

  param_1[0x16] = 0xffffffff;

  param_1[0x17] = 0xffffffff;

  param_1[0x18] = 0xffffffff;

  param_1[0x19] = 0xffffffff;

  param_1[0x1a] = 0xffffffff;

  param_1[0x1b] = 0xffffffff;

  param_1[0x1c] = 0xffffffff;

  param_1[0x1d] = 0xffffffff;

  param_1[0x1e] = 0xffffffff;

  param_1[0x1f] = 0xffffffff;

  param_1[0x20] = 0xffffffff;

  param_1[0x21] = 0xffffffff;

  param_1[0x22] = 0xffffffff;

  param_1[0x23] = 0xffffffff;

  param_1[0x24] = 0xffffffff;

  param_1[0x25] = 0xffffffff;

  param_1[0x26] = 0xffffffff;

  param_1[6] = 0;

  return;

}
