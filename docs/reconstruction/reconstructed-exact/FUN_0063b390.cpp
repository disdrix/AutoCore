// =============================================================================
// FUN_0063b390
// -----------------------------------------------------------------------------
// Stable ID: aa_0063b390
// Address:   0x0063b390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063b390 @ 0x0063b390
// Stable ID: aa_0063b390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0063b390.
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

void __thiscall FUN_0063b390(int param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  *(float *)(param_1 + 0xc0) = *param_2 + *(float *)(param_1 + 0xc0);

  *(float *)(param_1 + 0xc4) = param_2[1] + *(float *)(param_1 + 0xc4);

  *(float *)(param_1 + 200) = param_2[2] + *(float *)(param_1 + 200);

  *(float *)(param_1 + 0xcc) = param_2[3] + *(float *)(param_1 + 0xcc);

  fVar6 = param_3[1] - *(float *)(param_1 + 0x74);

  fVar7 = param_3[2] - *(float *)(param_1 + 0x78);

  fVar5 = *param_3 - *(float *)(param_1 + 0x70);

  fVar1 = *param_2;

  fVar2 = param_2[2];

  fVar3 = param_2[1];

  fVar4 = *param_2;

  *(float *)(param_1 + 0xd0) =

       *(float *)(param_1 + 0xd0) + (param_2[2] * fVar6 - param_2[1] * fVar7);

  *(float *)(param_1 + 0xd4) = *(float *)(param_1 + 0xd4) + (fVar1 * fVar7 - fVar2 * fVar5);

  *(float *)(param_1 + 0xd8) = *(float *)(param_1 + 0xd8) + (fVar3 * fVar5 - fVar4 * fVar6);

  fVar1 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc);

  *(float *)(param_1 + 0xdc) = fVar1;

  return;

}
