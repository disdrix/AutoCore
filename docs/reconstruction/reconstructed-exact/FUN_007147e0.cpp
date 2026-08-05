// =============================================================================
// FUN_007147e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007147e0
// Address:   0x007147e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007147e0 @ 0x007147e0
// Stable ID: aa_007147e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_007147e0, fcos.
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

void FUN_007147e0(float *param_1,uint param_2,float param_3,float param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  float *pfVar5;

  float *pfVar6;

  float *pfVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  float10 fVar11;

  

  iVar9 = (int)param_2 >> 1;

  pfVar4 = param_1 + 2;

  pfVar7 = param_1 + (param_2 - 3);

  iVar10 = 2;

  fVar11 = (float10)fcos((float10)DAT_00a11098 / (float10)(int)(param_2 - 1));

  fVar1 = (float)(fVar11 * (float10)param_4);

  fVar2 = (float)(fVar11 + fVar11);

  *param_1 = (param_3 - param_4) * *param_1;

  param_1[param_2 - 1] = (param_3 - param_4) * param_1[param_2 - 1];

  param_1[1] = (param_3 - fVar1) * param_1[1];

  param_1[param_2 - 2] = (param_3 - fVar1) * param_1[param_2 - 2];

  fVar3 = param_4;

  param_1 = (float *)fVar1;

  if (4 < iVar9) {

    iVar8 = 4;

    pfVar5 = pfVar4;

    pfVar6 = pfVar7;

    do {

      fVar1 = (float)param_1 * fVar2 - fVar3;

      iVar8 = iVar8 + 3;

      pfVar4 = pfVar5 + 3;

      pfVar7 = pfVar6 + -3;

      iVar10 = iVar10 + 3;

      *pfVar5 = (param_3 - fVar1) * *pfVar5;

      *pfVar6 = (param_3 - fVar1) * *pfVar6;

      fVar3 = fVar1 * fVar2 - (float)param_1;

      pfVar5[1] = (param_3 - fVar3) * pfVar5[1];

      pfVar6[-1] = (param_3 - fVar3) * pfVar6[-1];

      param_1 = (float *)(fVar2 * fVar3 - fVar1);

      pfVar5[2] = (param_3 - (float)param_1) * pfVar5[2];

      pfVar6[-2] = (param_3 - (float)param_1) * pfVar6[-2];

      pfVar5 = pfVar4;

      pfVar6 = pfVar7;

    } while (iVar8 < iVar9);

  }

  pfVar5 = pfVar4;

  if (iVar10 < iVar9) {

    pfVar5 = pfVar4 + 1;

    fVar3 = (float)param_1 * fVar2 - fVar3;

    fVar1 = param_3 - fVar3;

    *pfVar4 = fVar1 * *pfVar4;

    *pfVar7 = fVar1 * *pfVar7;

    if (iVar10 + 1 < iVar9) {

      fVar1 = param_3 - (fVar3 * fVar2 - (float)param_1);

      pfVar4[1] = fVar1 * pfVar4[1];

      pfVar7[-1] = fVar1 * pfVar7[-1];

      pfVar5 = pfVar4 + 2;

    }

  }

  if ((param_2 & 1) != 0) {

    *pfVar5 = (param_3 + param_4) * *pfVar5;

  }

  return;

}
