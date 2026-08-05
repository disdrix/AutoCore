// =============================================================================
// FUN_00578390
// -----------------------------------------------------------------------------
// Stable ID: aa_00578390
// Address:   0x00578390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00578390 @ 0x00578390
// Stable ID: aa_00578390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00578390.
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

uint32_t /* width from decompiler */ __thiscall FUN_00578390(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  *param_2 = 0x2014;

  *(uint16_t *)((int)param_2 + 0x22) = *(uint16_t *)(param_1 + 0x10);

  param_2[1] = g_dwClientTickMs - *(int *)(param_1 + 0x14);

  *(uint8_t *)(param_2 + 8) = *(uint8_t *)(param_1 + 0x20);

  param_2[4] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x678);

  param_2[5] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x67c);

  param_2[6] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x680);

  param_2[7] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x684);

  param_2[10] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x658);

  param_2[0xb] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x65c);

  param_2[0xc] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x660);

  param_2[0xd] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x664);

  param_2[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6a8);

  *(uint16_t *)(param_2 + 3) = *(uint16_t *)(param_1 + 0x620);

  *(short *)((int)param_2 + 0xe) = *(short *)(param_1 + 0x61a) + *(short *)(param_1 + 0x198);

  return 0x38;

}
