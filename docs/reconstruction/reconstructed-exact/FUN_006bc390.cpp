// =============================================================================
// FUN_006bc390
// -----------------------------------------------------------------------------
// Stable ID: aa_006bc390
// Address:   0x006bc390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bc390 @ 0x006bc390
// Stable ID: aa_006bc390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_005b3300×2, FUN_006bc390, rsqrtss.
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



void FUN_006bc390(float *param_1,float *param_2,float *param_3,float *param_4,int *param_5)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  float fVar10;

  float fVar11;

  float fVar12;

  uint8_t auVar7 [16];

  uint8_t auVar8 [16];

  uint8_t auVar9 [16];

  

  iVar2 = param_5[1];

  iVar4 = iVar2 + 1;

  if ((int)(param_5[2] & 0x7fffffffU) < iVar4) {

    iVar1 = (param_5[2] & 0x7fffffffU) * 2;

    if (iVar1 <= iVar4) {

      iVar1 = iVar4;

    }

    FUN_005b3300(param_5,iVar1,0x10);

  }

  param_5[1] = iVar4;

  pfVar3 = (float *)(iVar2 * 0x10 + *param_5);

  fVar5 = param_1[1] * (param_2[2] - param_3[2]) - param_1[2] * (param_2[1] - param_3[1]);

  fVar10 = param_1[2] * (*param_2 - *param_3) - *param_1 * (param_2[2] - param_3[2]);

  fVar11 = *param_1 * (param_2[1] - param_3[1]) - param_1[1] * (*param_2 - *param_3);

  fVar12 = param_1[3] * (param_2[3] - param_3[3]) - param_1[3] * (param_2[3] - param_3[3]);

  *pfVar3 = fVar5;

  pfVar3[1] = fVar10;

  pfVar3[2] = fVar11;

  pfVar3[3] = fVar12;

  if (_DAT_00a110e4 <

      fVar11 * (param_4[2] - param_3[2]) +

      fVar10 * (param_4[1] - param_3[1]) + fVar5 * (*param_4 - *param_3)) {

    fVar10 = (float)((uint)fVar10 ^ _UNK_00a0d144);

    fVar11 = (float)((uint)fVar11 ^ _UNK_00a0d148);

    fVar12 = (float)((uint)fVar12 ^ _UNK_00a0d14c);

    *pfVar3 = (float)((uint)fVar5 ^ _DAT_00a0d140);

    pfVar3[1] = fVar10;

    pfVar3[2] = fVar11;

    pfVar3[3] = fVar12;

  }

  fVar5 = *pfVar3 * *pfVar3;

  fVar10 = pfVar3[1] * pfVar3[1];

  fVar11 = pfVar3[2] * pfVar3[2];

  if (DAT_00aaa664 < fVar11 + fVar10 + fVar5) {

    auVar7._4_4_ = fVar10;

    auVar7._0_4_ = fVar10;

    auVar7._8_4_ = fVar10;

    auVar7._12_4_ = fVar10;

    auVar8._4_12_ = auVar7._4_12_;

    auVar8._0_4_ = fVar10 + fVar5;

    auVar9._4_4_ = fVar11;

    auVar9._0_4_ = fVar11 + auVar8._0_4_;

    auVar9._8_4_ = fVar11;

    auVar9._12_4_ = fVar11;

    auVar9 = rsqrtss(auVar8,auVar9);

    fVar6 = auVar9._0_4_;

    fVar5 = *pfVar3;

    fVar10 = pfVar3[1];

    fVar12 = pfVar3[2];

    fVar11 = fVar6 * 0.5 * (3.0 - (fVar11 + auVar8._0_4_) * fVar6 * fVar6);

    *pfVar3 = fVar11 * fVar5;

    pfVar3[1] = fVar11 * fVar10;

    pfVar3[2] = fVar11 * fVar12;

    pfVar3[3] = fVar11 * pfVar3[3];

    pfVar3[3] = -(fVar11 * fVar12 * param_2[2] +

                 fVar11 * fVar10 * param_2[1] + fVar11 * fVar5 * *param_2);

    return;

  }

  iVar4 = param_5[1] + -1;

  if ((int)(param_5[2] & 0x7fffffffU) < iVar4) {

    iVar2 = (param_5[2] & 0x7fffffffU) * 2;

    if (iVar2 <= iVar4) {

      iVar2 = iVar4;

    }

    FUN_005b3300(param_5,iVar2,0x10);

  }

  param_5[1] = iVar4;

  return;

}
