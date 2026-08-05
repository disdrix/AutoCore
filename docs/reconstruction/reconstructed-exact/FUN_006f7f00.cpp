// =============================================================================
// FUN_006f7f00
// -----------------------------------------------------------------------------
// Stable ID: aa_006f7f00
// Address:   0x006f7f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f7f00 @ 0x006f7f00
// Stable ID: aa_006f7f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: ABS×4, FUN_006f7f00.
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

void __thiscall FUN_006f7f00(int param_1,float *param_2,int param_3,int param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  

  fVar1 = *(float *)(param_1 + 0x80 + param_3 * 4);

  fVar2 = *(float *)(param_1 + 0x90 + param_3 * 4);

  fVar3 = *(float *)(param_1 + 0xb0 + param_4 * 4);

  fVar7 = fVar3 * g_flZero;

  fVar4 = *(float *)(param_1 + 0x80 + param_4 * 4);

  fVar5 = *(float *)(param_1 + 0x90 + param_4 * 4);

  fVar6 = *(float *)(param_1 + 0xb0 + param_3 * 4);

  fVar8 = fVar6 * g_flZero;

  *param_2 = ABS(*(float *)(param_1 + 0x70 + param_3 * 4) * fVar3 -

                 *(float *)(param_1 + 0x70 + param_4 * 4) * fVar6);

  param_2[1] = ABS(fVar1 * fVar3 - fVar4 * fVar6);

  param_2[2] = ABS(fVar2 * fVar3 - fVar5 * fVar6);

  param_2[3] = ABS(fVar7 - fVar8);

  return;

}
