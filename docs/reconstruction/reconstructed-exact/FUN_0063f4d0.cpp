// =============================================================================
// FUN_0063f4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0063f4d0
// Address:   0x0063f4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063f4d0 @ 0x0063f4d0
// Stable ID: aa_0063f4d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0063f4d0.
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

void __thiscall FUN_0063f4d0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  float fVar2;

  

  uVar1 = DAT_009e3ebc;

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009e3ec0;

  param_1[0x14] = param_2[1];

  fVar2 = g_flOne;

  param_1[0x15] = param_2[2];

  param_1[0x16] = param_2[3];

  param_1[0x17] = param_2[4];

  param_1[4] = uVar1;

  param_1[5] = uVar1;

  param_1[6] = uVar1;

  param_1[7] = uVar1;

  param_1[0xc] = uVar1;

  param_1[0xd] = uVar1;

  param_1[0xe] = uVar1;

  param_1[0xf] = uVar1;

  param_1[0xb] = 0;

  param_1[10] = 0;

  param_1[9] = 0;

  param_1[8] = 0;

  param_1[0xb] = fVar2;

  param_1[0x13] = 0;

  param_1[0x12] = 0;

  param_1[0x11] = 0;

  param_1[0x10] = 0;

  param_1[0x13] = fVar2;

  param_1[2] = *param_2;

  return;

}
