// =============================================================================
// FUN_006f1b10
// -----------------------------------------------------------------------------
// Stable ID: aa_006f1b10
// Address:   0x006f1b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f1b10 @ 0x006f1b10
// Stable ID: aa_006f1b10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006f1a80, FUN_006f1b10.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006f1b10(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = &PTR_LAB_009d27b0;

  param_1[3] = &PTR_LAB_009d2784;

  param_1[4] = &PTR_LAB_009d278c;

  param_1[5] = &PTR_LAB_009d27b0;

  *param_1 = &PTR_FUN_00a0ee70;

  param_1[2] = &PTR_FUN_00a0ee6c;

  param_1[3] = &PTR_FUN_00a0ee64;

  param_1[4] = &PTR_FUN_00a0ee5c;

  param_1[5] = &PTR_FUN_00a0ee58;

  param_1[6] = param_1 + 9;

  param_1[7] = 0;

  param_1[8] = 0x80000003;

  FUN_006f1a80(param_2);

  return param_1;

}
