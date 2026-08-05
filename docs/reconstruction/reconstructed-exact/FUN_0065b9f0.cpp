// =============================================================================
// FUN_0065b9f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0065b9f0
// Address:   0x0065b9f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065b9f0 @ 0x0065b9f0
// Stable ID: aa_0065b9f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0065b9f0.
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

void __thiscall FUN_0065b9f0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  float fVar1;

  

  *param_1 = &PTR_FUN_009e5fdc;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = *param_2;

  *param_1 = &PTR_FUN_009e6008;

  param_1[3] = param_2[1];

  *param_1 = &PTR_FUN_009e5f98;

  param_1[0xc] = param_2[2];

  param_1[7] = 0;

  param_1[6] = 0;

  param_1[5] = 0;

  param_1[4] = 0;

  *(short *)(param_1[0xc] + 6) = *(short *)(param_1[0xc] + 6) + 1;

  param_1[0xd] = 0;

  param_1[8] = (float)param_2[3] * (float)param_2[3];

  param_1[9] = param_2[3];

  fVar1 = (float)param_2[4];

  param_1[10] = fVar1;

  fVar1 = (float)param_1[9] - fVar1;

  param_1[0xb] = fVar1 * fVar1;

  param_1[3] = *(uint32_t /* width from decompiler */ *)(param_1[0xc] + 0xc);

  return;

}
