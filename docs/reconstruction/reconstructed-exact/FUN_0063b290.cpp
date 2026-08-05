// =============================================================================
// FUN_0063b290
// -----------------------------------------------------------------------------
// Stable ID: aa_0063b290
// Address:   0x0063b290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063b290 @ 0x0063b290
// Stable ID: aa_0063b290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0063b290.
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

void __thiscall FUN_0063b290(int param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  

  fVar1 = *(float *)(param_1 + 0x2c);

  *(float *)(param_1 + 0x40) = *param_2 * fVar1 + *(float *)(param_1 + 0x40);

  *(float *)(param_1 + 0x44) = param_2[1] * fVar1 + *(float *)(param_1 + 0x44);

  *(float *)(param_1 + 0x48) = param_2[2] * fVar1 + *(float *)(param_1 + 0x48);

  *(float *)(param_1 + 0x4c) = param_2[3] * fVar1 + *(float *)(param_1 + 0x4c);

  fVar9 = param_3[1] - *(float *)(param_1 + 0x74);

  fVar6 = param_3[2] - *(float *)(param_1 + 0x78);

  fVar7 = *param_3 - *(float *)(param_1 + 0x70);

  fVar1 = *param_2;

  fVar2 = param_2[2];

  fVar3 = param_2[1];

  fVar4 = *param_2;

  fVar5 = *(float *)(param_1 + 0x10);

  fVar8 = fVar5 * g_flZero;

  *(float *)(param_1 + 0x50) =

       (param_2[2] * fVar9 - param_2[1] * fVar6) * fVar5 + *(float *)(param_1 + 0x50);

  *(float *)(param_1 + 0x54) = (fVar1 * fVar6 - fVar2 * fVar7) * fVar5 + *(float *)(param_1 + 0x54);

  *(float *)(param_1 + 0x58) = (fVar3 * fVar7 - fVar4 * fVar9) * fVar5 + *(float *)(param_1 + 0x58);

  *(float *)(param_1 + 0x5c) = fVar8 + *(float *)(param_1 + 0x5c);

  return;

}
