// =============================================================================
// FUN_0060ced0
// -----------------------------------------------------------------------------
// Stable ID: aa_0060ced0
// Address:   0x0060ced0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060ced0 @ 0x0060ced0
// Stable ID: aa_0060ced0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0060ced0, FUN_00637da0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0060ced0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  FUN_00637da0(param_2);

  *(uint8_t *)(param_1 + 7) = 0;

  *(uint8_t *)((int)param_1 + 0x1d) = 0;

  param_1[8] = 0;

  *(uint8_t *)(param_1 + 9) = 0;

  *(uint8_t *)((int)param_1 + 0x25) = 0;

  *(uint8_t *)((int)param_1 + 0x26) = 0;

  *(uint8_t *)(param_1 + 0xc) = 0;

  *(uint8_t *)((int)param_1 + 0x31) = 0;

  *(uint8_t *)((int)param_1 + 0x32) = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  *(uint8_t *)(param_1 + 0xf) = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  *param_1 = &PTR_FUN_009dfc1c;

  param_1[6] = 0xffffffff;

  param_1[4] = 0xffffffff;

  param_1[5] = 0xffffffff;

  param_1[10] = 0xffffffff;

  param_1[0xb] = 0xffffffff;

  param_1[0x12] = 0xffffffff;

  param_1[0x13] = 0xffffffff;

  param_1[0x14] = 1;

  param_1[0x15] = 0xffffffff;

  param_1[3] = 0xc;

  return param_1;

}
