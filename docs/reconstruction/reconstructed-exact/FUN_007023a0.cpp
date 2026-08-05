// =============================================================================
// FUN_007023a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007023a0
// Address:   0x007023a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007023a0 @ 0x007023a0
// Stable ID: aa_007023a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007023a0, SQRT.
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

void __fastcall FUN_007023a0(float *param_1)



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

  float *pfVar13;

  float *pfVar14;

  float *pfVar15;

  float fVar16;

  

  pfVar13 = (float *)param_1[9];

  pfVar14 = (float *)param_1[5];

  fVar1 = *pfVar14;

  fVar2 = *pfVar13;

  pfVar15 = (float *)param_1[0xd];

  fVar3 = pfVar14[1];

  fVar4 = pfVar13[1];

  fVar5 = pfVar14[2];

  fVar6 = pfVar13[2];

  fVar7 = *pfVar13;

  fVar8 = *pfVar15;

  fVar9 = pfVar13[1];

  fVar10 = pfVar15[1];

  fVar11 = pfVar13[2];

  fVar12 = pfVar15[2];

  param_1[3] = 0.0;

  fVar16 = (fVar11 - fVar12) * (fVar3 - fVar4) - (fVar9 - fVar10) * (fVar5 - fVar6);

  *param_1 = fVar16;

  fVar5 = (fVar5 - fVar6) * (fVar7 - fVar8) - (fVar11 - fVar12) * (fVar1 - fVar2);

  param_1[1] = fVar5;

  fVar1 = (fVar9 - fVar10) * (fVar1 - fVar2) - (fVar7 - fVar8) * (fVar3 - fVar4);

  param_1[2] = fVar1;

  fVar2 = fVar16 * fVar16 + fVar5 * fVar5 + fVar1 * fVar1;

  fVar3 = g_flZero;

  if (fVar2 != g_flZero) {

    fVar3 = g_flOne / SQRT(fVar2);

  }

  *param_1 = fVar16 * fVar3;

  param_1[1] = fVar5 * fVar3;

  param_1[2] = fVar1 * fVar3;

  param_1[3] = fVar3 * g_flZero;

  param_1[4] = fVar16 * fVar3 * *pfVar14 + fVar5 * fVar3 * pfVar14[1] + fVar1 * fVar3 * pfVar14[2];

  return;

}
