// =============================================================================
// FUN_00567e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00567e90
// Address:   0x00567e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00567e90 @ 0x00567e90
// Stable ID: aa_00567e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: SQRT×2, fsin×2, ABS, FUN_00567e90, _CIacos.
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



void __thiscall FUN_00567e90(float *param_1,float *param_2,float *param_3,float param_4)



{

  float *pfVar1;

  float10 fVar2;

  float10 fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  pfVar1 = param_3;

  fVar4 = param_3[3] * param_2[3] + param_3[2] * param_2[2] + *param_2 * *param_3 +

          param_3[1] * param_2[1];

  fVar5 = g_flOne;

  if (fVar4 < 0.0) {

    fVar4 = 0.0 - fVar4;

    fVar5 = DAT_00aaa668;

  }

  if (DAT_00a111a8 <= fVar4) {

    fVar6 = g_flOne - param_4;

    *param_1 = *param_2 * fVar6;

    fVar5 = fVar5 * param_4;

    param_1[1] = param_2[1] * fVar6;

    fVar4 = param_2[2];

    param_1[2] = fVar6 * fVar4;

    param_1[3] = fVar6 * param_2[3];

    *param_1 = *param_3 * fVar5 + *param_1;

    param_1[1] = param_3[1] * fVar5 + param_1[1];

    param_1[2] = param_3[2] * fVar5 + fVar6 * fVar4;

    param_1[3] = param_3[3] * fVar5 + param_1[3];

  }

  else {

    if (ABS(fVar4) < g_flOne) {

      fVar2 = (float10)_CIacos();

      param_3 = (float *)(float)fVar2;

    }

    else {

      param_3 = (float *)0x0;

      if (fVar4 <= 0.0) {

        param_3 = (float *)_DAT_009d2f20;

      }

    }

    fVar2 = (float10)g_flOne / SQRT((float10)g_flOne - (float10)fVar4 * (float10)fVar4);

    fVar3 = (float10)fsin((float10)(float)param_3 - (float10)(float)param_3 * (float10)param_4);

    fVar3 = fVar3 * fVar2;

    *param_1 = (float)(fVar3 * (float10)*param_2);

    param_1[1] = (float)(fVar3 * (float10)param_2[1]);

    param_1[2] = (float)(fVar3 * (float10)param_2[2]);

    param_1[3] = (float)(fVar3 * (float10)param_2[3]);

    fVar3 = (float10)fsin((float10)(float)param_3 * (float10)param_4);

    fVar2 = fVar3 * fVar2 * (float10)fVar5;

    *param_1 = (float)(fVar2 * (float10)*pfVar1 + (float10)*param_1);

    param_1[1] = (float)(fVar2 * (float10)pfVar1[1] + (float10)param_1[1]);

    param_1[2] = (float)(fVar2 * (float10)pfVar1[2] + (float10)param_1[2]);

    param_1[3] = (float)(fVar2 * (float10)pfVar1[3] + (float10)param_1[3]);

  }

  fVar5 = 0.0;

  fVar4 = param_1[3] * param_1[3] + param_1[2] * param_1[2] + param_1[1] * param_1[1] +

          *param_1 * *param_1;

  if (fVar4 != 0.0) {

    fVar5 = g_flOne / SQRT(fVar4);

  }

  *param_1 = *param_1 * fVar5;

  param_1[1] = param_1[1] * fVar5;

  param_1[2] = param_1[2] * fVar5;

  param_1[3] = fVar5 * param_1[3];

  return;

}
