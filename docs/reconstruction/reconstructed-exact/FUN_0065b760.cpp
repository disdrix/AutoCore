// =============================================================================
// FUN_0065b760
// -----------------------------------------------------------------------------
// Stable ID: aa_0065b760
// Address:   0x0065b760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065b760 @ 0x0065b760
// Stable ID: aa_0065b760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: FUN_0065b760.
//  - Return sites: 2.

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

int __thiscall FUN_0065b760(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,float *param_4)



{

  int iVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  

  iVar2 = (**(code **)(**(int **)(param_1 + 0x30) + 0x18))(param_2,param_3,param_4);

  if (*(int *)(param_1 + 0x34) == 0) {

    fVar3 = 0.0;

    fVar5 = 0.0;

    fVar4 = 0.0;

    fVar7 = 0.0;

  }

  else {

    iVar1 = *(int *)(*(int *)(param_1 + 0x34) + 0x3c);

    fVar5 = *(float *)(*(int *)(*(int *)(param_1 + 0x34) + 8) + 0x150);

    iVar2 = iVar1 + 0x40;

    fVar7 = *(float *)(iVar1 + 0x40) * fVar5;

    fVar3 = *(float *)(iVar1 + 0x44) * fVar5;

    fVar4 = *(float *)(iVar1 + 0x48) * fVar5;

    fVar5 = *(float *)(iVar1 + 0x4c) * fVar5;

  }

  fVar6 = param_4[4] + fVar7;

  fVar8 = param_4[5] + fVar3;

  fVar9 = param_4[6] + fVar4;

  fVar10 = param_4[7] + fVar5;

  if (fVar6 < param_4[4] || fVar6 == param_4[4]) {

    fVar6 = param_4[4];

  }

  param_4[4] = fVar6;

  if (fVar8 < param_4[5] || fVar8 == param_4[5]) {

    fVar8 = param_4[5];

  }

  param_4[5] = fVar8;

  if (fVar9 < param_4[6] || fVar9 == param_4[6]) {

    fVar9 = param_4[6];

  }

  param_4[6] = fVar9;

  if (fVar10 < param_4[7] || fVar10 == param_4[7]) {

    fVar10 = param_4[7];

  }

  param_4[7] = fVar10;

  fVar6 = *param_4 + fVar7;

  if (*param_4 <= *param_4 + fVar7) {

    fVar6 = *param_4;

  }

  *param_4 = fVar6;

  fVar7 = fVar3 + param_4[1];

  if (param_4[1] <= fVar3 + param_4[1]) {

    fVar7 = param_4[1];

  }

  param_4[1] = fVar7;

  fVar3 = fVar4 + param_4[2];

  if (param_4[2] <= fVar4 + param_4[2]) {

    fVar3 = param_4[2];

  }

  param_4[2] = fVar3;

  if (fVar5 + param_4[3] < param_4[3]) {

    param_4[3] = fVar5 + param_4[3];

    return iVar2;

  }

  param_4[3] = param_4[3];

  return iVar2;

}
