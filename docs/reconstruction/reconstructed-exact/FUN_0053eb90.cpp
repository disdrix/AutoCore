// =============================================================================
// FUN_0053eb90
// -----------------------------------------------------------------------------
// Stable ID: aa_0053eb90
// Address:   0x0053eb90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053eb90 @ 0x0053eb90
// Stable ID: aa_0053eb90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_0053e020×6, FUN_0053eb90, SQRT.
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

uint32_t /* width from decompiler */ __thiscall FUN_0053eb90(int param_1,float param_2,float param_3)



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

  int iVar11;

  float *pfVar12;

  uint32_t /* width from decompiler */ uVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  

  if ((param_3 == 0.0) && (0x18ff < g_dwClientTickMs - *(int *)(param_1 + 0x14))) {

    return 0;

  }

  if (*(int *)(param_1 + 0x28) == 0) {

    uVar13 = FUN_0053e020();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar13;

  }

  iVar11 = *(int *)(param_1 + 0x28);

  fVar17 = *(float *)(iVar11 + 0x30) * DAT_00a0f298;

  fVar19 = *(float *)(iVar11 + 0x34) * DAT_00a0f298;

  fVar14 = *(float *)(iVar11 + 0x38) * DAT_00a0f298;

  if (iVar11 == 0) {

    uVar13 = FUN_0053e020();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar13;

  }

  iVar11 = *(int *)(param_1 + 0x28);

  fVar1 = *(float *)(iVar11 + 0x10);

  fVar2 = *(float *)(iVar11 + 0x18);

  fVar3 = *(float *)(iVar11 + 0x14);

  fVar15 = *(float *)(iVar11 + 0x18);

  fVar16 = *(float *)(iVar11 + 0x14);

  fVar18 = *(float *)(iVar11 + 0x10);

  fVar4 = *(float *)(iVar11 + 0x14);

  fVar5 = *(float *)(iVar11 + 0x18);

  fVar6 = *(float *)(iVar11 + 0x10);

  fVar7 = *(float *)(iVar11 + 0x1c);

  fVar8 = *(float *)(iVar11 + 0x14);

  fVar9 = *(float *)(iVar11 + 0x18);

  fVar10 = *(float *)(iVar11 + 0x10);

  if (iVar11 == 0) {

    uVar13 = FUN_0053e020();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar13;

  }

  fVar20 = 0.0;

  iVar11 = *(int *)(param_1 + 0x28);

  fVar15 = (fVar19 * fVar7 + fVar4 * 0.0 + (fVar14 * fVar18 - fVar17 * fVar15)) * param_2 +

           *(float *)(iVar11 + 0x14);

  fVar16 = (fVar14 * fVar7 + fVar5 * 0.0 + (fVar17 * fVar16 - fVar19 * fVar6)) * param_2 +

           *(float *)(iVar11 + 0x18);

  fVar18 = (fVar7 * 0.0 - (fVar14 * fVar9 + fVar19 * fVar8 + fVar10 * fVar17)) * param_2 +

           *(float *)(iVar11 + 0x1c);

  fVar17 = param_2 * (fVar7 * fVar17 + fVar1 * 0.0 + (fVar19 * fVar2 - fVar14 * fVar3)) +

           *(float *)(iVar11 + 0x10);

  fVar14 = fVar18 * fVar18 + fVar16 * fVar16 + fVar15 * fVar15 + fVar17 * fVar17;

  if (fVar14 != 0.0) {

    fVar20 = g_flOne / SQRT(fVar14);

  }

  if (iVar11 == 0) {

    uVar13 = FUN_0053e020();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar13;

  }

  iVar11 = *(int *)(param_1 + 0x28);

  *(float *)(iVar11 + 0x10) = fVar20 * fVar17;

  *(float *)(iVar11 + 0x14) = fVar20 * fVar15;

  *(float *)(iVar11 + 0x18) = fVar20 * fVar16;

  *(float *)(iVar11 + 0x1c) = fVar20 * fVar18;

  if (*(int *)(param_1 + 0x28) == 0) {

    uVar13 = FUN_0053e020();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar13;

  }

  iVar11 = *(int *)(param_1 + 0x28);

  if (iVar11 == 0) {

    uVar13 = FUN_0053e020();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar13;

  }

  pfVar12 = *(float **)(param_1 + 0x28);

  *pfVar12 = *(float *)(iVar11 + 0x20) * param_2 + *pfVar12;

  pfVar12[1] = *(float *)(iVar11 + 0x24) * param_2 + pfVar12[1];

  pfVar12[2] = *(float *)(iVar11 + 0x28) * param_2 + pfVar12[2];

  pfVar12[3] = *(float *)(iVar11 + 0x2c) * param_2 + pfVar12[3];

  return 1;

}
