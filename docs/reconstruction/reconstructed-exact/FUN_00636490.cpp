// =============================================================================
// FUN_00636490
// -----------------------------------------------------------------------------
// Stable ID: aa_00636490
// Address:   0x00636490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00636490 @ 0x00636490
// Stable ID: aa_00636490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00636490, FUN_00636820.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_00636490(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4,

            uint32_t /* width from decompiler */ *param_5,uint32_t /* width from decompiler */ *param_6)



{

  FUN_00636820(param_2,param_3);

  *param_1 = &PTR_FUN_009e3b18;

  param_1[2] = &PTR_LAB_009e3b04;

  param_1[8] = *param_5;

  param_1[9] = param_5[1];

  param_1[10] = param_5[2];

  param_1[0xb] = param_5[3];

  param_1[0xc] = *param_6;

  param_1[0xd] = param_6[1];

  param_1[0xe] = param_6[2];

  param_1[0xf] = param_6[3];

  param_1[0x10] = *param_4;

  param_1[0x11] = param_4[1];

  param_1[0x12] = param_4[2];

  param_1[0x13] = param_4[3];

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  *(uint8_t *)(param_1 + 0x17) = 1;

  return param_1;

}
