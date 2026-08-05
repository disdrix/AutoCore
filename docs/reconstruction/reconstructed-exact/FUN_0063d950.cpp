// =============================================================================
// FUN_0063d950
// -----------------------------------------------------------------------------
// Stable ID: aa_0063d950
// Address:   0x0063d950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063d950 @ 0x0063d950
// Stable ID: aa_0063d950
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0063d950.
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

void __thiscall FUN_0063d950(int param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  *(float *)(param_1 + 0xf0) = *param_2 + *(float *)(param_1 + 0xf0);

  *(float *)(param_1 + 0xf4) = param_2[1] + *(float *)(param_1 + 0xf4);

  *(float *)(param_1 + 0xf8) = param_2[2] + *(float *)(param_1 + 0xf8);

  *(float *)(param_1 + 0xfc) = param_2[3] + *(float *)(param_1 + 0xfc);

  fVar6 = param_3[1] - *(float *)(param_1 + 0x74);

  fVar7 = param_3[2] - *(float *)(param_1 + 0x78);

  fVar5 = *param_3 - *(float *)(param_1 + 0x70);

  fVar1 = *param_2;

  fVar2 = param_2[2];

  fVar3 = param_2[1];

  fVar4 = *param_2;

  *(float *)(param_1 + 0x100) =

       *(float *)(param_1 + 0x100) + (param_2[2] * fVar6 - param_2[1] * fVar7);

  *(float *)(param_1 + 0x104) = *(float *)(param_1 + 0x104) + (fVar1 * fVar7 - fVar2 * fVar5);

  *(float *)(param_1 + 0x108) = *(float *)(param_1 + 0x108) + (fVar3 * fVar5 - fVar4 * fVar6);

  fVar1 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c);

  *(float *)(param_1 + 0x10c) = fVar1;

  return;

}
