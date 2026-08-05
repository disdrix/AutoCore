// =============================================================================
// FUN_0070e9f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0070e9f0
// Address:   0x0070e9f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070e9f0 @ 0x0070e9f0
// Stable ID: aa_0070e9f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~154 non-empty decompiler lines.
//  - Control keywords: if×10, do×10, while×10, return×1.
//  - Notable callees: FUN_0070e9f0.
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

void FUN_0070e9f0(int param_1,int param_2,int param_3,float *param_4,int param_5,int param_6,

                 int param_7,int param_8)



{

  short sVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  float *pfVar6;

  float *pfVar7;

  short *psVar8;

  int iVar9;

  int iVar10;

  uint32_t /* width from decompiler */ *puVar11;

  float *pfVar12;

  int iVar13;

  

  iVar10 = param_6;

  param_8 = param_8 + (-param_8 & 3U) + param_6 * 4;

  iVar9 = (-param_8 & 3U) + param_8;

  pfVar7 = (float *)(param_6 * 4 + -4 + iVar9);

  iVar2 = param_6 >> 1;

  param_8 = param_8 + param_6 * -4;

  iVar3 = 0;

  if (3 < param_6) {

    puVar11 = (uint32_t /* width from decompiler */ *)(param_2 + 8);

    iVar4 = (param_6 - 4U >> 2) + 1;

    puVar5 = (uint32_t /* width from decompiler */ *)(param_8 + -8 + param_6 * 4);

    iVar3 = iVar4 * 4;

    param_6 = iVar4;

    do {

      puVar5[1] = puVar11[-2];

      *puVar5 = puVar11[-1];

      puVar5[-1] = *puVar11;

      puVar5[-2] = puVar11[1];

      puVar11 = puVar11 + 4;

      puVar5 = puVar5 + -4;

      param_6 = param_6 + -1;

    } while (param_6 != 0);

  }

  if (iVar3 < iVar10) {

    puVar5 = (uint32_t /* width from decompiler */ *)(param_8 + -4 + (iVar10 - iVar3) * 4);

    do {

      *puVar5 = *(uint32_t /* width from decompiler */ *)(param_2 + iVar3 * 4);

      iVar3 = iVar3 + 1;

      puVar5 = puVar5 + -1;

    } while (iVar3 < iVar10);

  }

  iVar3 = iVar10 + -1;

  iVar4 = 0;

  if (3 < iVar3) {

    iVar13 = (iVar10 - 5U >> 2) + 1;

    iVar4 = iVar13 * 4;

    puVar5 = (uint32_t /* width from decompiler */ *)(iVar9 + 8);

    puVar11 = (uint32_t /* width from decompiler */ *)(param_7 + -0xc + iVar10 * 4);

    do {

      puVar5[-2] = puVar11[1];

      puVar5[-1] = *puVar11;

      *puVar5 = puVar11[-1];

      puVar5[1] = puVar11[-2];

      puVar5 = puVar5 + 4;

      puVar11 = puVar11 + -4;

      iVar13 = iVar13 + -1;

    } while (iVar13 != 0);

  }

  if (iVar4 < iVar3) {

    puVar5 = (uint32_t /* width from decompiler */ *)(param_7 + -8 + (iVar10 - iVar4) * 4);

    do {

      *(uint32_t /* width from decompiler */ *)(iVar9 + iVar4 * 4) = *puVar5;

      iVar4 = iVar4 + 1;

      puVar5 = puVar5 + -1;

    } while (iVar4 < iVar3);

  }

  iVar4 = 0;

  if (3 < param_5) {

    iVar13 = (param_5 - 4U >> 2) + 1;

    iVar4 = iVar13 * 4;

    pfVar6 = (float *)(iVar9 + 4 + iVar10 * 4);

    psVar8 = (short *)(param_1 + 4);

    do {

      iVar13 = iVar13 + -1;

      pfVar6[-2] = (float)(int)psVar8[-2];

      pfVar6[-1] = (float)(int)psVar8[-1];

      *pfVar6 = (float)(int)*psVar8;

      pfVar6[1] = (float)(int)psVar8[1];

      pfVar6 = pfVar6 + 4;

      psVar8 = psVar8 + 4;

    } while (iVar13 != 0);

  }

  if (iVar4 < param_5) {

    pfVar6 = (float *)(iVar9 + -4 + (iVar10 + iVar4) * 4);

    do {

      iVar13 = iVar4 * 2;

      iVar4 = iVar4 + 1;

      *pfVar6 = (float)(int)*(short *)(param_1 + iVar13);

      pfVar6 = pfVar6 + 1;

    } while (iVar4 < param_5);

  }

  if (0 < param_5) {

    param_3 = param_3 - (int)param_4;

    iVar9 = iVar9 - (int)pfVar7;

    iVar4 = (param_5 - 1U >> 1) + 1;

    do {

      iVar13 = 0;

      *(uint32_t /* width from decompiler */ *)(param_3 + (int)param_4) = 0;

      *param_4 = 0.0;

      if (0 < iVar2) {

        pfVar6 = pfVar7;

        pfVar12 = (float *)(iVar9 + (int)pfVar7);

        do {

          iVar13 = iVar13 + 2;

          *(float *)(param_3 + (int)param_4) =

               (*pfVar6 + *pfVar12) * *(float *)(param_8 + -8 + iVar13 * 4) +

               *(float *)(param_3 + (int)param_4);

          *param_4 = *param_4 - (*pfVar12 - *pfVar6) * *(float *)(param_8 + -8 + iVar13 * 4);

          *(float *)(param_3 + (int)param_4) =

               (pfVar6[-1] + pfVar12[1]) * *(float *)(param_8 + -4 + iVar13 * 4) +

               *(float *)(param_3 + (int)param_4);

          *param_4 = (pfVar12[1] - pfVar6[-1]) * *(float *)(param_8 + -4 + iVar13 * 4) + *param_4;

          pfVar6 = pfVar6 + -2;

          pfVar12 = pfVar12 + 2;

        } while (iVar13 < iVar2);

      }

      pfVar7 = pfVar7 + 2;

      param_4 = param_4 + 1;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  iVar2 = 0;

  if (3 < iVar3) {

    iVar10 = (iVar10 - 5U >> 2) + 1;

    iVar2 = iVar10 * 4;

    pfVar7 = (float *)(param_7 + 8);

    psVar8 = (short *)(param_1 + -4 + param_5 * 2);

    do {

      iVar10 = iVar10 + -1;

      pfVar7[-2] = (float)(int)psVar8[1];

      pfVar7[-1] = (float)(int)*psVar8;

      *pfVar7 = (float)(int)psVar8[-1];

      pfVar7[1] = (float)(int)psVar8[-2];

      pfVar7 = pfVar7 + 4;

      psVar8 = psVar8 + -4;

    } while (iVar10 != 0);

  }

  if (iVar2 < iVar3) {

    psVar8 = (short *)(param_1 + -2 + (param_5 - iVar2) * 2);

    do {

      sVar1 = *psVar8;

      iVar2 = iVar2 + 1;

      psVar8 = psVar8 + -1;

      *(float *)(param_7 + -4 + iVar2 * 4) = (float)(int)sVar1;

    } while (iVar2 < iVar3);

  }

  return;

}
