// =============================================================================
// FUN_00559c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00559c70
// Address:   0x00559c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00559c70 @ 0x00559c70
// Stable ID: aa_00559c70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: SQRT×3, FUN_00559c70.
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

void FUN_00559c70(float *param_1,float *param_2,float *param_3,float param_4,float param_5,

                 float param_6,float *param_7,float *param_8,float *param_9,float *param_10,

                 float *param_11,float *param_12,float *param_13)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  

  if (((param_4 < param_5) && (param_4 < param_6)) || ((param_5 < param_4 && (param_6 < param_4))))

  {

    if (((param_5 < param_4) && (param_5 < param_6)) || ((param_4 < param_5 && (param_6 < param_5)))

       ) {

      pfVar3 = &param_4;

      pfVar1 = param_3;

      pfVar2 = param_2;

    }

    else {

      pfVar3 = &param_6;

      pfVar1 = param_1;

      pfVar2 = param_3;

      param_1 = param_2;

    }

  }

  else {

    pfVar3 = &param_5;

    pfVar1 = param_2;

    pfVar2 = param_1;

    param_1 = param_3;

  }

  *param_13 = *pfVar2;

  param_13[1] = pfVar2[1];

  param_13[2] = pfVar2[2];

  fVar4 = pfVar1[1];

  fVar8 = pfVar1[2];

  fVar5 = pfVar2[1];

  fVar6 = pfVar2[2];

  *param_7 = *pfVar1 - *pfVar2;

  param_7[1] = fVar4 - fVar5;

  param_7[2] = fVar8 - fVar6;

  fVar4 = param_1[1];

  fVar8 = pfVar2[1];

  fVar5 = param_1[2];

  fVar6 = pfVar2[2];

  *param_8 = *param_1 - *pfVar2;

  param_8[1] = fVar4 - fVar8;

  param_8[2] = fVar5 - fVar6;

  fVar4 = param_1[1];

  fVar8 = pfVar1[1];

  fVar5 = param_1[2];

  fVar6 = pfVar1[2];

  *param_9 = *param_1 - *pfVar1;

  param_9[1] = fVar4 - fVar8;

  param_9[2] = fVar5 - fVar6;

  *param_11 = *param_7;

  param_11[1] = param_7[1];

  fVar8 = g_flOne;

  fVar4 = param_7[2];

  param_11[2] = fVar4;

  fVar4 = SQRT(fVar4 * fVar4 + param_11[1] * param_11[1] + *param_11 * *param_11);

  if (fVar4 != g_flZero) {

    fVar4 = fVar8 / fVar4;

    *param_11 = *param_11 * fVar4;

    param_11[1] = param_11[1] * fVar4;

    param_11[2] = param_11[2] * fVar4;

  }

  *param_12 = *param_8;

  param_12[1] = param_8[1];

  fVar4 = param_8[2];

  param_12[2] = fVar4;

  fVar4 = SQRT(fVar4 * fVar4 + param_12[1] * param_12[1] + *param_12 * *param_12);

  if (fVar4 != g_flZero) {

    fVar4 = fVar8 / fVar4;

    *param_12 = *param_12 * fVar4;

    param_12[1] = param_12[1] * fVar4;

    param_12[2] = fVar4 * param_12[2];

  }

  fVar4 = (param_11[2] * param_12[2] + param_11[1] * param_12[1] + *param_11 * *param_12) * *pfVar3;

  fVar7 = param_1[2] - (param_11[2] * fVar4 + pfVar2[2]);

  fVar6 = param_1[1] - (pfVar2[1] + param_11[1] * fVar4);

  fVar5 = *param_1 - (*pfVar2 + *param_11 * fVar4);

  *param_10 = fVar5;

  param_10[1] = fVar6;

  param_10[2] = fVar7;

  fVar4 = SQRT(fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7);

  if (fVar4 != g_flZero) {

    fVar8 = fVar8 / fVar4;

    *param_10 = fVar5 * fVar8;

    param_10[1] = fVar6 * fVar8;

    param_10[2] = fVar7 * fVar8;

  }

  return;

}
