// =============================================================================
// FUN_005a66e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a66e0
// Address:   0x005a66e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a66e0 @ 0x005a66e0
// Stable ID: aa_005a66e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005a66e0.
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

void __thiscall FUN_005a66e0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  *param_1 = &PTR_FUN_009d8244;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  param_1[0x57] = 0;

  param_1[0x4e] = param_2;

  param_1[0xc] = s_road_default_009d82e4._0_4_;

  param_1[0xd] = s_road_default_009d82e4._4_4_;

  param_1[0xe] = s_road_default_009d82e4._8_4_;

  *(char *)(param_1 + 0xf) = s_road_default_009d82e4[0xc];

  param_1[0x4d] = DAT_00af3d0c;

  param_1[1] = 0;

  param_1[2] = 0;

  *(uint8_t *)(param_1 + 0x4f) = 0;

  param_1[3] = 0;

  param_1[0x53] = 0;

  DAT_00af3d0c = DAT_00af3d0c + 1;

  return;

}
