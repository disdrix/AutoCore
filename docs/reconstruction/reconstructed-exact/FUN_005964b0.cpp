// =============================================================================
// FUN_005964b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005964b0
// Address:   0x005964b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005964b0 @ 0x005964b0
// Stable ID: aa_005964b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0049baa0, FUN_005964b0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_005964b0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  float fVar3;

  

  FUN_0049baa0(1);

  fVar3 = g_flOne;

  param_1[0x1e] = 0;

  param_1[0x1f] = 0;

  param_1[0x20] = 0;

  param_1[0x21] = 0;

  param_1[0x22] = 0;

  param_1[0x23] = 0;

  param_1[0x24] = 0;

  param_1[0x25] = 0;

  param_1[0x26] = 0;

  param_1[0x27] = 0;

  param_1[0x28] = 0;

  param_1[0x29] = 0;

  param_1[0x2a] = 0;

  param_1[0x2b] = 0;

  param_1[0x2c] = 0;

  param_1[0x2d] = 0;

  *param_1 = 0;

  param_1[1] = fVar3;

  param_1[5] = fVar3;

  param_1[9] = fVar3;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[0xc] = 0;

  param_1[0xb] = 0;

  param_1[10] = 0;

  uVar2 = DAT_00a0f718;

  param_1[0xe] = fVar3;

  param_1[0xf] = fVar3;

  param_1[0x10] = fVar3;

  param_1[0x13] = fVar3;

  uVar1 = DAT_00aaa68c;

  param_1[0x14] = DAT_00aaa68c;

  param_1[0x17] = uVar1;

  uVar1 = DAT_00a0f70c;

  param_1[0xd] = uVar2;

  uVar2 = DAT_00a0f298;

  param_1[0x16] = uVar1;

  param_1[0x15] = uVar1;

  uVar1 = DAT_009c7b84;

  param_1[0x11] = uVar2;

  param_1[0x12] = uVar2;

  param_1[0x33] = 0x20;

  param_1[0x18] = 5;

  param_1[0x1c] = uVar1;

  param_1[0x1d] = 0;

  *(uint16_t *)(param_1 + 0x2e) = 0;

  param_1[0x19] = 0;

  param_1[0x1a] = 0;

  param_1[0x1b] = 0;

  param_1[0x2f] = 0;

  param_1[0x30] = 0;

  param_1[0x31] = 0;

  param_1[0x32] = 0;

  param_1[0x1e] = 0;

  param_1[0x1f] = 0;

  param_1[0x20] = 0;

  param_1[0x21] = 0;

  param_1[0x22] = 0;

  param_1[0x23] = 0;

  param_1[0x24] = 0;

  param_1[0x25] = 0;

  param_1[0x26] = 0;

  param_1[0x27] = 0;

  param_1[0x28] = 0;

  param_1[0x29] = 0;

  param_1[0x2a] = 0;

  param_1[0x2b] = 0;

  param_1[0x2c] = 0;

  param_1[0x2d] = 0;

  param_1[0x34] = 0;

  param_1[0x35] = 0;

  param_1[0x36] = 0;

  return param_1;

}
