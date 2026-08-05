// =============================================================================
// FUN_006351b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006351b0
// Address:   0x006351b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006351b0 @ 0x006351b0
// Stable ID: aa_006351b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006351b0, FUN_00651b10, FUN_00651b60, FUN_00651dd0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006351b0(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  uint8_t local_14;

  uint32_t /* width from decompiler */ local_10;

  uint8_t local_c;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = &PTR_LAB_009e3a68;

  param_1[5] = 0;

  param_1[4] = 0;

  param_1[3] = 0;

  param_1[6] = 0;

  param_1[8] = param_2;

  *param_1 = &PTR_FUN_009e38d0;

  param_1[2] = &PTR_LAB_009e38c0;

  *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

  param_1[0xc] = 0;

  param_1[9] = param_3;

  FUN_00651b10(*(uint32_t /* width from decompiler */ *)(param_1[8] + 0xc));

  FUN_00651b60(*(uint32_t /* width from decompiler */ *)(param_1[8] + 0x10));

  FUN_00651dd0();

  *(uint8_t *)((int)param_1 + 0x2d) = local_c;

  *(uint8_t *)(param_1 + 0xb) = local_14;

  param_1[10] = local_10;

  return param_1;

}
