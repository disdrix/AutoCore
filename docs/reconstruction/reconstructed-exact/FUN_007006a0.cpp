// =============================================================================
// FUN_007006a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007006a0
// Address:   0x007006a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007006a0 @ 0x007006a0
// Stable ID: aa_007006a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007006a0.
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

void __thiscall

FUN_007006a0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6)



{

  *param_1 = *param_4;

  param_1[1] = param_4[1];

  param_1[2] = param_4[2];

  param_1[3] = param_4[3];

  param_1[4] = param_4[4];

  param_1[5] = param_4[5];

  param_1[6] = param_4[6];

  param_1[7] = param_4[7];

  param_1[8] = param_4[8];

  param_1[9] = param_4[9];

  param_1[10] = param_4[10];

  param_1[0xb] = param_4[0xb];

  param_1[0xc] = param_4[0xc];

  param_1[0xd] = param_4[0xd];

  param_1[0xe] = param_4[0xe];

  param_1[0xf] = param_4[0xf];

  param_1[0x10] = param_2;

  param_1[0x11] = param_3;

  param_1[0x12] = param_5;

  param_1[0x13] = 0;

  param_1[0x14] = param_6;

  return;

}
