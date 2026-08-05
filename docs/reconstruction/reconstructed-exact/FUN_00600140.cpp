// =============================================================================
// FUN_00600140
// -----------------------------------------------------------------------------
// Stable ID: aa_00600140
// Address:   0x00600140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00600140 @ 0x00600140
// Stable ID: aa_00600140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00600140, FUN_00636370.
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

FUN_00600140(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6)



{

  FUN_00636370(param_2);

  *param_1 = &PTR_FUN_009de0cc;

  param_1[2] = &PTR_LAB_009de0b8;

  param_1[8] = *param_3;

  param_1[9] = param_3[1];

  param_1[10] = param_3[2];

  param_1[0xb] = param_3[3];

  param_1[0xc] = *param_4;

  param_1[0xd] = param_4[1];

  param_1[0xe] = param_4[2];

  param_1[0xf] = param_4[3];

  param_1[0x10] = param_5;

  param_1[0x11] = param_6;

  return param_1;

}
