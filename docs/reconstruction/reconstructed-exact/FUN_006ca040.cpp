// =============================================================================
// FUN_006ca040
// -----------------------------------------------------------------------------
// Stable ID: aa_006ca040
// Address:   0x006ca040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ca040 @ 0x006ca040
// Stable ID: aa_006ca040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_006ca040.
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

void __thiscall FUN_006ca040(int param_1,float *param_2,float param_3,float *param_4)



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

  

  param_3 = param_3 + *(float *)(param_1 + 0xc);

  fVar1 = *(float *)(param_1 + 0x10);

  fVar2 = *(float *)(param_1 + 0x14);

  fVar3 = *(float *)(param_1 + 0x18);

  fVar7 = fVar2 * param_2[4] + fVar3 * param_2[8] + fVar1 * *param_2 + param_2[0xc];

  fVar6 = fVar1 * param_2[1] + fVar2 * param_2[5] + fVar3 * param_2[9] + param_2[0xd];

  fVar5 = fVar1 * param_2[2] + fVar2 * param_2[6] + fVar3 * param_2[10] + param_2[0xe];

  fVar1 = *(float *)(param_1 + 0x20);

  fVar2 = *(float *)(param_1 + 0x24);

  fVar3 = *(float *)(param_1 + 0x28);

  fVar9 = fVar2 * param_2[4] + fVar3 * param_2[8] + fVar1 * *param_2 + param_2[0xc];

  fVar8 = fVar1 * param_2[1] + fVar2 * param_2[5] + fVar3 * param_2[9] + param_2[0xd];

  fVar2 = fVar1 * param_2[2] + fVar2 * param_2[6] + fVar3 * param_2[10] + param_2[0xe];

  fVar1 = fVar9;

  if (fVar7 < fVar9) {

    fVar1 = fVar7;

  }

  *param_4 = fVar1;

  fVar3 = fVar8;

  if (fVar6 < fVar8) {

    fVar3 = fVar6;

  }

  param_4[1] = fVar3;

  fVar4 = fVar2;

  if (fVar5 < fVar2) {

    fVar4 = fVar5;

  }

  *param_4 = fVar1 - param_3;

  param_4[1] = fVar3 - param_3;

  param_4[2] = fVar4 - param_3;

  param_4[3] = -param_3;

  if (fVar9 < fVar7) {

    fVar9 = fVar7;

  }

  param_4[4] = fVar9;

  if (fVar8 < fVar6) {

    fVar8 = fVar6;

  }

  param_4[5] = fVar8;

  if (fVar5 <= fVar2) {

    fVar5 = fVar2;

  }

  param_4[6] = fVar5;

  param_4[7] = 0.0;

  param_4[4] = param_3 + param_4[4];

  param_4[5] = param_3 + param_4[5];

  param_4[6] = param_3 + param_4[6];

  param_4[7] = param_3 + param_4[7];

  return;

}
