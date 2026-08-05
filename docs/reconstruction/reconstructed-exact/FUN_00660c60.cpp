// =============================================================================
// FUN_00660c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00660c60
// Address:   0x00660c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00660c60 @ 0x00660c60
// Stable ID: aa_00660c60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00660c60.
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

FUN_00660c60(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6)



{

  float fVar1;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[0x14] = 0;

  param_1[0x15] = 8;

  param_1[7] = 0;

  param_1[6] = 0;

  param_1[5] = 0;

  param_1[4] = 0;

  fVar1 = g_flOne;

  param_1[0xb] = 0;

  param_1[10] = 0;

  param_1[9] = 0;

  param_1[8] = 0;

  param_1[0xf] = 0;

  param_1[0xe] = 0;

  param_1[0xd] = 0;

  param_1[0xc] = 0;

  param_1[4] = fVar1;

  param_1[9] = fVar1;

  param_1[0xe] = fVar1;

  param_1[0x13] = 0;

  param_1[0x12] = 0;

  param_1[0x11] = 0;

  param_1[0x10] = 0;

  param_1[0x21] = param_5;

  *param_1 = &PTR_FUN_009e755c;

  param_1[0x22] = param_6;

  param_1[0x18] = *param_2;

  param_1[0x19] = param_2[1];

  param_1[0x1a] = param_2[2];

  param_1[0x1b] = param_2[3];

  param_1[0x1c] = *param_3;

  param_1[0x1d] = param_3[1];

  param_1[0x1e] = param_3[2];

  param_1[0x1f] = param_3[3];

  param_1[0x20] = param_4;

  return;

}
