// =============================================================================
// FUN_005fa6e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005fa6e0
// Address:   0x005fa6e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fa6e0 @ 0x005fa6e0
// Stable ID: aa_005fa6e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00567ce0, FUN_005fa6e0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_005fa6e0(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  float local_20 [7];

  

  local_20[0] = g_flOne;

  local_20[1] = 0.0;

  local_20[2] = 0.0;

  local_20[3] = 0.0;

  FUN_00567ce0(local_20,0);

  *(uint8_t *)(param_1 + 0x20) = 0;

  fVar1 = g_flOne;

  param_1[0x21] = g_flOne;

  param_1[0x22] = 0;

  param_1[0x23] = 0;

  param_1[0x24] = 0;

  param_1[0x25] = 0;

  param_1[0x26] = 0;

  param_1[0x27] = 0;

  param_1[0x28] = 0;

  param_1[0x29] = 0;

  *(uint8_t *)(param_1 + 0x2a) = 0;

  param_1[0x2b] = 0;

  param_1[0x2c] = 0;

  param_1[0x2d] = 0;

  param_1[3] = 0;

  param_1[2] = 0;

  param_1[1] = 0;

  *param_1 = 0;

  param_1[7] = 0;

  param_1[6] = 0;

  param_1[5] = 0;

  param_1[4] = 0;

  param_1[0xb] = 0;

  param_1[10] = 0;

  param_1[9] = 0;

  param_1[8] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = fVar1;

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = fVar1;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = fVar1;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  param_1[0x1a] = fVar1;

  param_1[0x1b] = 0;

  return param_1;

}
