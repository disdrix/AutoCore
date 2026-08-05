// =============================================================================
// FUN_00412d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00412d80
// Address:   0x00412d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00412d80 @ 0x00412d80
// Stable ID: aa_00412d80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00412d80.
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

void FUN_00412d80(float *param_1,float *param_2,float *param_3)



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

  

  if ((((uint)param_2 & 0xf) == 0) && (((uint)param_3 & 0xf) == 0)) {

    fVar9 = param_3[4];

    fVar10 = param_3[5];

    fVar11 = param_3[6];

    fVar12 = param_3[7];

    fVar13 = param_3[0xc];

    fVar14 = param_3[0xd];

    fVar15 = param_3[0xe];

    fVar16 = param_3[0xf];

    fVar1 = param_2[7];

    fVar17 = param_3[8];

    fVar18 = param_3[9];

    fVar19 = param_3[10];

    fVar20 = param_3[0xb];

    fVar2 = param_2[5];

    fVar3 = param_2[6];

    fVar21 = *param_3;

    fVar22 = param_3[1];

    fVar23 = param_3[2];

    fVar24 = param_3[3];

    fVar4 = param_2[4];

    fVar5 = param_2[3];

    fVar6 = param_2[2];

    fVar7 = param_2[1];

    fVar8 = *param_2;

    *param_1 = fVar8 * fVar21 + fVar7 * fVar9 + fVar6 * fVar17 + fVar5 * fVar13;

    param_1[1] = fVar8 * fVar22 + fVar7 * fVar10 + fVar6 * fVar18 + fVar5 * fVar14;

    param_1[2] = fVar8 * fVar23 + fVar7 * fVar11 + fVar6 * fVar19 + fVar5 * fVar15;

    param_1[3] = fVar8 * fVar24 + fVar7 * fVar12 + fVar6 * fVar20 + fVar5 * fVar16;

    param_1[4] = fVar4 * fVar21 + fVar2 * fVar9 + fVar3 * fVar17 + fVar1 * fVar13;

    param_1[5] = fVar4 * fVar22 + fVar2 * fVar10 + fVar3 * fVar18 + fVar1 * fVar14;

    param_1[6] = fVar4 * fVar23 + fVar2 * fVar11 + fVar3 * fVar19 + fVar1 * fVar15;

    param_1[7] = fVar4 * fVar24 + fVar2 * fVar12 + fVar3 * fVar20 + fVar1 * fVar16;

    fVar1 = param_2[0xf];

    fVar2 = param_2[0xb];

    fVar3 = param_2[0xe];

    fVar4 = param_2[0xd];

    fVar5 = param_2[0xc];

    fVar6 = param_2[10];

    fVar7 = param_2[9];

    fVar8 = param_2[8];

    param_1[8] = fVar8 * fVar21 + fVar7 * fVar9 + fVar6 * fVar17 + fVar2 * fVar13;

    param_1[9] = fVar8 * fVar22 + fVar7 * fVar10 + fVar6 * fVar18 + fVar2 * fVar14;

    param_1[10] = fVar8 * fVar23 + fVar7 * fVar11 + fVar6 * fVar19 + fVar2 * fVar15;

    param_1[0xb] = fVar8 * fVar24 + fVar7 * fVar12 + fVar6 * fVar20 + fVar2 * fVar16;

    param_1[0xc] = fVar5 * fVar21 + fVar4 * fVar9 + fVar3 * fVar17 + fVar1 * fVar13;

    param_1[0xd] = fVar5 * fVar22 + fVar4 * fVar10 + fVar3 * fVar18 + fVar1 * fVar14;

    param_1[0xe] = fVar5 * fVar23 + fVar4 * fVar11 + fVar3 * fVar19 + fVar1 * fVar15;

    param_1[0xf] = fVar5 * fVar24 + fVar4 * fVar12 + fVar3 * fVar20 + fVar1 * fVar16;

    return;

  }

  fVar1 = *param_3;

  fVar2 = param_3[1];

  fVar3 = param_3[2];

  fVar4 = param_3[3];

  fVar5 = param_3[4];

  fVar6 = param_3[5];

  fVar7 = param_3[6];

  fVar8 = param_3[7];

  fVar9 = param_3[8];

  fVar10 = param_3[9];

  fVar11 = param_2[5];

  fVar12 = param_2[7];

  fVar13 = param_3[10];

  fVar14 = param_3[0xb];

  fVar15 = param_2[6];

  fVar16 = param_3[0xc];

  fVar17 = param_3[0xd];

  fVar18 = param_3[0xe];

  fVar19 = param_3[0xf];

  fVar20 = param_2[4];

  fVar21 = param_2[3];

  fVar22 = param_2[2];

  fVar23 = param_2[1];

  fVar24 = *param_2;

  *param_1 = fVar24 * fVar1 + fVar23 * fVar5 + fVar22 * fVar9 + fVar21 * fVar16;

  param_1[1] = fVar24 * fVar2 + fVar23 * fVar6 + fVar22 * fVar10 + fVar21 * fVar17;

  param_1[2] = fVar24 * fVar3 + fVar23 * fVar7 + fVar22 * fVar13 + fVar21 * fVar18;

  param_1[3] = fVar24 * fVar4 + fVar23 * fVar8 + fVar22 * fVar14 + fVar21 * fVar19;

  param_1[4] = fVar20 * fVar1 + fVar11 * fVar5 + fVar15 * fVar9 + fVar12 * fVar16;

  param_1[5] = fVar20 * fVar2 + fVar11 * fVar6 + fVar15 * fVar10 + fVar12 * fVar17;

  param_1[6] = fVar20 * fVar3 + fVar11 * fVar7 + fVar15 * fVar13 + fVar12 * fVar18;

  param_1[7] = fVar20 * fVar4 + fVar11 * fVar8 + fVar15 * fVar14 + fVar12 * fVar19;

  fVar11 = param_2[0xd];

  fVar12 = param_2[0xc];

  fVar15 = param_2[0xe];

  fVar20 = param_2[0xf];

  fVar21 = param_2[0xb];

  fVar22 = param_2[10];

  fVar23 = param_2[9];

  fVar24 = param_2[8];

  param_1[8] = fVar24 * fVar1 + fVar23 * fVar5 + fVar22 * fVar9 + fVar21 * fVar16;

  param_1[9] = fVar24 * fVar2 + fVar23 * fVar6 + fVar22 * fVar10 + fVar21 * fVar17;

  param_1[10] = fVar24 * fVar3 + fVar23 * fVar7 + fVar22 * fVar13 + fVar21 * fVar18;

  param_1[0xb] = fVar24 * fVar4 + fVar23 * fVar8 + fVar22 * fVar14 + fVar21 * fVar19;

  param_1[0xc] = fVar12 * fVar1 + fVar11 * fVar5 + fVar15 * fVar9 + fVar20 * fVar16;

  param_1[0xd] = fVar12 * fVar2 + fVar11 * fVar6 + fVar15 * fVar10 + fVar20 * fVar17;

  param_1[0xe] = fVar12 * fVar3 + fVar11 * fVar7 + fVar15 * fVar13 + fVar20 * fVar18;

  param_1[0xf] = fVar12 * fVar4 + fVar11 * fVar8 + fVar15 * fVar14 + fVar20 * fVar19;

  return;

}
