// =============================================================================
// FUN_00707430
// -----------------------------------------------------------------------------
// Stable ID: aa_00707430
// Address:   0x00707430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00707430 @ 0x00707430
// Stable ID: aa_00707430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~155 non-empty decompiler lines.
//  - Control keywords: while×12, if×8, do×8, return×1.
//  - Notable callees: FUN_00702bb0×3, FUN_00706aa0×2, FUN_007066f0, FUN_007068d0, FUN_00707430.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00707430(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  float fVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  float *pfVar6;

  int iVar7;

  int iVar8;

  float *pfVar9;

  int iVar10;

  uint8_t local_28 [20];

  uint8_t local_14 [20];

  

  iVar10 = param_3;

  iVar2 = param_2;

  iVar8 = 0;

  if (3 < param_3) {

    iVar7 = (param_3 - 4U >> 2) + 1;

    puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 0xc);

    iVar8 = iVar7 * 4;

    puVar3 = (uint32_t /* width from decompiler */ *)(param_2 + 4);

    do {

      puVar3[-1] = puVar4[-3];

      *puVar3 = *(uint32_t /* width from decompiler */ *)((int)puVar3 + (param_1 - param_2));

      puVar3[1] = puVar4[-1];

      puVar3[2] = *puVar4;

      puVar3 = puVar3 + 4;

      puVar4 = puVar4 + 4;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  if (iVar8 < param_3) {

    puVar4 = (uint32_t /* width from decompiler */ *)(param_2 + iVar8 * 4);

    iVar8 = param_3 - iVar8;

    do {

      *puVar4 = *(uint32_t /* width from decompiler */ *)((int)puVar4 + (param_1 - param_2));

      puVar4 = puVar4 + 1;

      iVar8 = iVar8 + -1;

    } while (iVar8 != 0);

  }

  FUN_007066f0(local_28,param_3);

  param_3 = 0;

  if (3 < iVar10) {

    param_2 = 2;

    pfVar6 = (float *)(iVar2 + 8);

    do {

      fVar1 = (float)param_3;

      param_3 = param_3 + 4;

      pfVar6[-2] = pfVar6[-2] - (fVar1 + (float)_DAT_00aaa5f8) * (float)_DAT_00a0f1e8;

      pfVar6[-1] = pfVar6[-1] -

                   ((float)(param_2 + -1) + (float)_DAT_00aaa5f8) * (float)_DAT_00a0f1e8;

      *pfVar6 = *pfVar6 - ((float)param_2 + (float)_DAT_00aaa5f8) * (float)_DAT_00a0f1e8;

      pfVar6[1] = pfVar6[1] - ((float)(param_2 + 1) + (float)_DAT_00aaa5f8) * (float)_DAT_00a0f1e8;

      pfVar6 = pfVar6 + 4;

      param_2 = param_2 + 4;

    } while (param_3 < iVar10 + -3);

  }

  while (param_3 < iVar10) {

    *(float *)(iVar2 + -4 + (param_3 + 1) * 4) =

         *(float *)(iVar2 + param_3 * 4) -

         ((float)param_3 + (float)_DAT_00aaa5f8) * (float)_DAT_00a0f1e8;

    param_3 = param_3 + 1;

  }

  iVar8 = 0;

  if (3 < iVar10) {

    iVar7 = (iVar10 - 4U >> 2) + 1;

    iVar8 = iVar7 * 4;

    pfVar6 = (float *)(iVar2 + 8);

    do {

      iVar7 = iVar7 + -1;

      pfVar6[-2] = pfVar6[-2] * (float)_DAT_00aaa790;

      pfVar6[-1] = pfVar6[-1] * (float)_DAT_00aaa790;

      *pfVar6 = *pfVar6 * (float)_DAT_00aaa790;

      pfVar6[1] = pfVar6[1] * (float)_DAT_00aaa790;

      pfVar6 = pfVar6 + 4;

    } while (iVar7 != 0);

  }

  while (iVar8 < iVar10) {

    iVar7 = iVar8 * 4;

    iVar8 = iVar8 + 1;

    *(float *)(iVar2 + -4 + iVar8 * 4) = *(float *)(iVar2 + iVar7) * (float)_DAT_00aaa790;

  }

  uVar5 = FUN_007068d0(&DAT_00af7e38,0x40);

  FUN_00702bb0(param_4,uVar5,6);

  iVar8 = 0;

  if (3 < iVar10) {

    iVar7 = (iVar10 - 4U >> 2) + 1;

    iVar8 = iVar7 * 4;

    pfVar6 = (float *)(iVar2 + 8);

    do {

      iVar7 = iVar7 + -1;

      pfVar6[-2] = pfVar6[-2] + pfVar6[-2];

      pfVar6[-1] = pfVar6[-1] + pfVar6[-1];

      *pfVar6 = *pfVar6 + *pfVar6;

      pfVar6[1] = pfVar6[1] + pfVar6[1];

      pfVar6 = pfVar6 + 4;

    } while (iVar7 != 0);

  }

  while (iVar8 < iVar10) {

    fVar1 = *(float *)(iVar2 + iVar8 * 4);

    iVar8 = iVar8 + 1;

    *(float *)(iVar2 + -4 + iVar8 * 4) = fVar1 + fVar1;

  }

  uVar5 = FUN_00706aa0(iVar2,local_28,&DAT_00af80b8,0x40,5);

  FUN_00702bb0(param_4,uVar5,6);

  uVar5 = FUN_00706aa0(iVar2 + 0x14,local_14,&DAT_00af8338,0x40,5);

  FUN_00702bb0(param_4,uVar5,6);

  iVar8 = 0;

  if (3 < iVar10) {

    iVar7 = (iVar10 - 4U >> 2) + 1;

    iVar8 = iVar7 * 4;

    pfVar6 = (float *)(iVar2 + 8);

    do {

      iVar7 = iVar7 + -1;

      pfVar6[-2] = pfVar6[-2] * (float)_DAT_00a0f1f0;

      pfVar6[-1] = pfVar6[-1] * (float)_DAT_00a0f1f0;

      *pfVar6 = *pfVar6 * (float)_DAT_00a0f1f0;

      pfVar6[1] = pfVar6[1] * (float)_DAT_00a0f1f0;

      pfVar6 = pfVar6 + 4;

    } while (iVar7 != 0);

  }

  while (iVar8 < iVar10) {

    iVar7 = iVar8 * 4;

    iVar8 = iVar8 + 1;

    *(float *)(iVar2 + -4 + iVar8 * 4) = *(float *)(iVar2 + iVar7) * (float)_DAT_00a0f1f0;

  }

  iVar8 = 0;

  if (3 < iVar10) {

    iVar7 = (iVar10 - 4U >> 2) + 1;

    iVar8 = iVar7 * 4;

    pfVar6 = (float *)(iVar2 + 4);

    pfVar9 = (float *)(param_1 + 0xc);

    do {

      iVar7 = iVar7 + -1;

      pfVar6[-1] = pfVar9[-3] - pfVar6[-1];

      *pfVar6 = *(float *)((int)pfVar6 + (param_1 - iVar2)) - *pfVar6;

      pfVar6[1] = pfVar9[-1] - pfVar6[1];

      pfVar6[2] = *pfVar9 - pfVar6[2];

      pfVar6 = pfVar6 + 4;

      pfVar9 = pfVar9 + 4;

    } while (iVar7 != 0);

  }

  if (iVar8 < iVar10) {

    iVar10 = iVar10 - iVar8;

    pfVar6 = (float *)(iVar2 + iVar8 * 4);

    do {

      iVar10 = iVar10 + -1;

      *pfVar6 = *(float *)((param_1 - iVar2) + (int)pfVar6) - *pfVar6;

      pfVar6 = pfVar6 + 1;

    } while (iVar10 != 0);

  }

  return;

}
