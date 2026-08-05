// =============================================================================
// FUN_005ee970
// -----------------------------------------------------------------------------
// Stable ID: aa_005ee970
// Address:   0x005ee970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ee970 @ 0x005ee970
// Stable ID: aa_005ee970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_005ee970.
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



void __fastcall FUN_005ee970(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  float *pfVar6;

  float *pfVar7;

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

  int local_18;

  

  DAT_00d027f4 = 0.0;

  DAT_00d02810 = 0.0;

  DAT_00d027c4 = 0.0;

  DAT_00d027f8 = 0.0;

  DAT_00d02794 = 0.0;

  DAT_00d027d0 = 0.0;

  DAT_00d027e4 = 0.0;

  DAT_00d027bc = 0.0;

  DAT_00d0278c = 0.0;

  DAT_00d027a0 = 0.0;

  iVar5 = 1;

  pfVar7 = (float *)(param_1 + DAT_00d027f0 * 4);

  pfVar6 = (float *)(param_1 + DAT_00d027d4 * 4);

  local_18 = 3;

  do {

    fVar1 = *pfVar6;

    fVar13 = *pfVar7;

    fVar14 = fVar1 * fVar1;

    fVar22 = fVar14 * fVar1;

    iVar4 = (iVar5 % 3) * 4;

    fVar2 = *(float *)(param_1 + (DAT_00d027d4 + iVar4) * 4);

    fVar3 = *(float *)(param_1 + (iVar4 + DAT_00d027f0) * 4);

    fVar15 = fVar3 * fVar3 * fVar3;

    fVar16 = (fVar2 + fVar1) * fVar2 + fVar14;

    fVar17 = fVar16 * fVar2 + fVar22;

    fVar8 = fVar2 - fVar1;

    fVar9 = fVar3 - fVar13;

    fVar10 = fVar13 * fVar13;

    fVar18 = (fVar3 + fVar13) * fVar3 + fVar10;

    fVar11 = fVar10 * fVar13;

    fVar19 = fVar18 * fVar3 + fVar11;

    fVar20 = fVar2 * fVar1 * g_flLevelUpUiBase_Inferred;

    fVar12 = fVar2 * fVar2;

    fVar21 = fVar12 * g_flVehicleHpTechCoeff + fVar20 + fVar14;

    fVar14 = fVar14 * g_flVehicleHpTechCoeff + fVar20 + fVar12;

    DAT_00d027a0 = (fVar2 + fVar1) * fVar9 + DAT_00d027a0;

    DAT_00d0278c = fVar16 * fVar9 + DAT_00d0278c;

    DAT_00d027e4 = fVar17 * fVar9 + DAT_00d027e4;

    DAT_00d027f8 = (fVar22 * fVar1 + fVar17 * fVar2) * fVar9 + DAT_00d027f8;

    DAT_00d027bc = fVar18 * fVar8 + DAT_00d027bc;

    DAT_00d02794 = fVar19 * fVar8 + DAT_00d02794;

    DAT_00d027f4 = (fVar11 * fVar13 + fVar19 * fVar3) * fVar8 + DAT_00d027f4;

    DAT_00d027d0 = (fVar21 * fVar3 + fVar14 * fVar13) * fVar9 + DAT_00d027d0;

    DAT_00d027c4 = ((fVar12 * fVar2 * DAT_00aaa690 + fVar21 * fVar1) * fVar3 +

                   (fVar14 * fVar2 + fVar22 * DAT_00aaa690) * fVar13) * fVar9 + DAT_00d027c4;

    fVar13 = fVar3 * fVar3 * fVar13;

    DAT_00d02810 = ((fVar10 * fVar3 * g_flVehicleHpTechCoeff + fVar13 * g_flLevelUpUiBase_Inferred +

                     fVar11 * DAT_00aaa690 + fVar15) * fVar1 +

                   (fVar10 * fVar3 * g_flLevelUpUiBase_Inferred + fVar13 * g_flVehicleHpTechCoeff +

                    fVar15 * DAT_00aaa690 + fVar11) * fVar2) * fVar8 + DAT_00d02810;

    pfVar6 = pfVar6 + 4;

    pfVar7 = pfVar7 + 4;

    iVar5 = iVar5 + 1;

    local_18 = local_18 + -1;

  } while (local_18 != 0);

  DAT_00d027a0 = DAT_00d027a0 * DAT_00a0f298;

  DAT_00d0278c = DAT_00d0278c * DAT_00aaa9b0;

  DAT_00d027e4 = DAT_00d027e4 * _DAT_00aaaa20;

  DAT_00d027f8 = DAT_00d027f8 * DAT_00a10e78;

  DAT_00d027bc = DAT_00d027bc * _DAT_009dd02c;

  DAT_00d02794 = DAT_00d02794 * _DAT_009dd028;

  DAT_00d027f4 = DAT_00d027f4 * _DAT_009dd024;

  DAT_00d027d0 = DAT_00d027d0 * _DAT_00aaa860;

  DAT_00d027c4 = DAT_00d027c4 * DAT_00aaa9ec;

  DAT_00d02810 = DAT_00d02810 * _DAT_009dd030;

  return;

}
