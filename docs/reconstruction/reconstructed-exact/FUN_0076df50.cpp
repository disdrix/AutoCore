// =============================================================================
// FUN_0076df50
// -----------------------------------------------------------------------------
// Stable ID: aa_0076df50
// Address:   0x0076df50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076df50 @ 0x0076df50
// Stable ID: aa_0076df50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0076df50.
//  - Return sites: 3.

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

void FUN_0076df50(float *param_1,float *param_2,float *param_3)



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

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  

  if ((((*param_2 == 0.0) && (param_2[1] == 0.0)) && (param_2[2] == 0.0)) && (param_2[3] == g_flOne)

     ) {

    *param_1 = *param_3;

    param_1[1] = param_3[1];

    param_1[2] = param_3[2];

    param_1[3] = param_3[3];

    return;

  }

  if (((*param_3 == 0.0) && (param_3[1] == 0.0)) && ((param_3[2] == 0.0 && (param_3[3] == g_flOne)))

     ) {

    *param_1 = *param_2;

    param_1[1] = param_2[1];

    param_1[2] = param_2[2];

    param_1[3] = param_2[3];

    return;

  }

  fVar1 = param_3[2];

  fVar2 = *param_2;

  fVar3 = param_2[1];

  fVar4 = param_3[3];

  fVar5 = param_2[3];

  fVar6 = param_3[2];

  fVar7 = *param_2;

  fVar8 = *param_3;

  fVar9 = param_2[3];

  fVar10 = param_3[1];

  fVar11 = param_2[2];

  fVar12 = *param_3;

  fVar13 = param_2[2];

  fVar14 = param_3[3];

  fVar15 = param_2[1];

  fVar16 = *param_3;

  fVar17 = param_3[1];

  fVar18 = *param_2;

  fVar19 = param_2[3];

  fVar20 = param_3[3];

  fVar21 = param_2[1];

  fVar22 = param_3[1];

  fVar23 = param_2[2];

  fVar24 = param_3[2];

  *param_1 = (param_3[3] * *param_2 + param_2[2] * param_3[1] + param_2[3] * *param_3) -

             param_2[1] * param_3[2];

  param_1[1] = (fVar1 * fVar2 + fVar3 * fVar4 + fVar9 * fVar10) - fVar11 * fVar12;

  param_1[2] = (fVar13 * fVar14 + fVar5 * fVar6 + fVar15 * fVar16) - fVar17 * fVar18;

  param_1[3] = ((fVar19 * fVar20 - fVar7 * fVar8) - fVar21 * fVar22) - fVar23 * fVar24;

  return;

}
