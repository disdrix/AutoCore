// =============================================================================
// FUN_00713930
// -----------------------------------------------------------------------------
// Stable ID: aa_00713930
// Address:   0x00713930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713930 @ 0x00713930
// Stable ID: aa_00713930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: ROUND×2, ABS, FUN_00713880, FUN_00713930.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_00713930(float param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4,float *param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  uint uVar10;

  int local_c;

  float local_8;

  

  iVar7 = (int)param_1;

  iVar9 = *(int *)((int)param_1 + 0x2c);

  uVar10 = *(uint *)((int)param_1 + 0x28);

  fVar3 = *(float *)((int)param_1 + 0x24);

  fVar1 = *(float *)((int)param_1 + uVar10 * 4);

  fVar4 = *(float *)((int)param_1 + 0x20);

  fVar2 = *(float *)((int)param_1 + 0x10 + uVar10 * 4);

  local_c = 0;

  param_1 = 1.0;

  local_8 = 0.16;

  FUN_00713880(param_2,param_3,0xa1,param_5);

  iVar8 = 0;

  do {

    uVar10 = uVar10 + 1 & 0x80000003;

    if ((int)uVar10 < 0) {

      uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;

    }

    fVar1 = fVar1 * _DAT_00a10e3c + *param_5 * _DAT_00a10e40 * *param_5;

    fVar2 = fVar2 * _DAT_00a10e3c + *param_5 * _DAT_00a10e40 * param_5[1];

    fVar5 = ABS(fVar4 * fVar2 - fVar3 * fVar1);

    fVar6 = fVar4 * fVar1;

    fVar4 = (fVar4 + fVar1) - *(float *)(iVar7 + uVar10 * 4);

    fVar3 = (fVar3 + fVar2) - *(float *)(iVar7 + 0x10 + uVar10 * 4);

    *(float *)(iVar7 + uVar10 * 4) = fVar1;

    *(float *)(iVar7 + 0x10 + uVar10 * 4) = fVar2;

    if ((iVar9 + -0x96 <= iVar8) && ((int)(fVar6 * local_8) < (int)(fVar5 * param_1))) {

      param_1 = fVar6;

      local_c = iVar8;

      local_8 = fVar5;

    }

    iVar8 = iVar8 + 2;

    param_5 = param_5 + 2;

  } while (iVar8 < 0xa0);

  *(float *)(iVar7 + 0x20) = fVar4;

  *(int *)(iVar7 + 0x2c) = local_c;

  *(float *)(iVar7 + 0x24) = fVar3;

  *(uint *)(iVar7 + 0x28) = uVar10;

  if (local_c < 0x51) {

    iVar9 = -(int)ROUND((float)((param_3 - (param_4 >> 1)) * local_c) * _DAT_00a10e38);

    if (iVar9 < -0x28) {

      iVar9 = -0x28;

    }

  }

  else {

    iVar9 = (int)ROUND((float)(param_3 - (param_4 >> 1)) * (float)(0xa0 - local_c) * _DAT_00a10e38);

    if (0x28 < iVar9) {

      return 0x28;

    }

  }

  return iVar9;

}
