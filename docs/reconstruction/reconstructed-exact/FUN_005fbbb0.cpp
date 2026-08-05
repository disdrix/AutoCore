// =============================================================================
// FUN_005fbbb0
// -----------------------------------------------------------------------------
// Stable ID: aa_005fbbb0
// Address:   0x005fbbb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fbbb0 @ 0x005fbbb0
// Stable ID: aa_005fbbb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005fa9b0, FUN_005fbbb0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_005fbbb0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009dd2b8;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0x80000000;

  param_1[9] = 0x80000000;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[0xc] = 0x80000000;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xf] = 0x80000000;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0x12] = 0x80000000;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  param_1[0x15] = 0x80000000;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x18] = 0x80000000;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[0x1c] = 0x80000000;

  param_1[0x1a] = 0;

  param_1[0x1b] = 0;

  param_1[0x20] = param_1 + 0x24;

  param_1[0x21] = 0;

  param_1[0x22] = 0x80000004;

  FUN_005fa9b0(param_2);

  return param_1;

}
