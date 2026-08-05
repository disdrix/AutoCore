// =============================================================================
// FUN_00610bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00610bc0
// Address:   0x00610bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00610bc0 @ 0x00610bc0
// Stable ID: aa_00610bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00610bc0, FUN_00637da0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00610bc0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  FUN_00637da0(param_2);

  *(uint8_t *)(param_1 + 8) = 1;

  *(uint8_t *)((int)param_1 + 0x21) = 1;

  *(uint8_t *)((int)param_1 + 0x22) = 1;

  *(uint8_t *)((int)param_1 + 0x23) = 1;

  *param_1 = &PTR_FUN_009e0f24;

  param_1[3] = 3;

  param_1[4] = 0xffffffff;

  param_1[5] = 0;

  param_1[6] = 0xffffffff;

  param_1[7] = 0xffffffff;

  return param_1;

}
