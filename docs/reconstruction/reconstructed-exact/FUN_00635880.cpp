// =============================================================================
// FUN_00635880
// -----------------------------------------------------------------------------
// Stable ID: aa_00635880
// Address:   0x00635880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00635880 @ 0x00635880
// Stable ID: aa_00635880
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00635880.
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

void __thiscall FUN_00635880(int param_1,int *param_2)



{

  float *pfVar1;

  float fVar2;

  short sVar3;

  int iVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  

  iVar8 = 0;

  if (0 < *(int *)(param_1 + 0x10)) {

    iVar9 = 0;

    fVar16 = g_flLevelUpUiBase_Inferred;

    do {

      iVar4 = *param_2;

      sVar3 = *(short *)(*(int *)(*(int *)(param_1 + 8) + 8) + iVar8 * 2);

      pfVar5 = (float *)(*(int *)(param_1 + 0xc) + iVar9);

      if (sVar3 == -1) {

        *pfVar5 = *(float *)(iVar9 + iVar4);

        pfVar5[1] = *(float *)(iVar9 + 4 + iVar4);

        pfVar5[2] = *(float *)(iVar9 + 8 + iVar4);

        pfVar5[3] = *(float *)(iVar9 + 0xc + iVar4);

        pfVar1 = (float *)(iVar9 + 0x10 + iVar4);

        pfVar5[4] = *pfVar1;

        pfVar5[5] = pfVar1[1];

        pfVar5[6] = pfVar1[2];

        pfVar5[7] = pfVar1[3];

      }

      else {

        iVar6 = sVar3 * 0x20;

        *pfVar5 = *(float *)(iVar9 + iVar4) - *(float *)(iVar6 + iVar4);

        pfVar5[1] = *(float *)(iVar9 + 4 + iVar4) - *(float *)(iVar6 + 4 + iVar4);

        iVar7 = iVar6 + iVar4;

        pfVar5[2] = *(float *)(iVar9 + 8 + iVar4) - *(float *)(iVar6 + 8 + iVar4);

        pfVar5[3] = *(float *)(iVar9 + 0xc + iVar4) - *(float *)(iVar7 + 0xc);

        fVar2 = *(float *)(iVar7 + 0x1c);

        fVar12 = 0.0 - *(float *)(iVar7 + 0x18);

        fVar10 = 0.0 - *(float *)(iVar7 + 0x10);

        fVar11 = 0.0 - *(float *)(iVar7 + 0x14);

        fVar13 = fVar2 * fVar2 * fVar16 - g_flOne;

        fVar14 = (*pfVar5 * fVar10 + fVar12 * pfVar5[2] + pfVar5[1] * fVar11) * fVar16;

        fVar16 = fVar2 * fVar16;

        fVar17 = *pfVar5;

        fVar15 = *pfVar5;

        fVar18 = pfVar5[1];

        *pfVar5 = *pfVar5 * fVar13 + (fVar11 * pfVar5[2] - pfVar5[1] * fVar12) * fVar16 +

                  fVar14 * fVar10;

        pfVar5[1] = pfVar5[1] * fVar13 + (fVar17 * fVar12 - fVar10 * pfVar5[2]) * fVar16 +

                    fVar11 * fVar14;

        fVar17 = fVar16 * g_flZero;

        pfVar5[2] = (fVar18 * fVar10 - fVar15 * fVar11) * fVar16 + fVar12 * fVar14 +

                    fVar13 * pfVar5[2];

        pfVar1 = (float *)(iVar9 + 0x10 + iVar4);

        pfVar5[3] = pfVar5[3] * fVar13 + fVar2 * fVar14 + fVar17;

        fVar16 = pfVar1[1];

        fVar15 = fVar12 * *pfVar1 - pfVar1[2] * fVar10;

        fVar18 = pfVar1[1] * fVar10 - fVar11 * *pfVar1;

        fVar17 = pfVar1[2];

        pfVar5[6] = fVar18;

        pfVar5[5] = fVar15;

        pfVar5[4] = fVar17 * fVar11 - fVar16 * fVar12;

        pfVar5[7] = 0.0;

        pfVar5[4] = fVar2 * *pfVar1 + pfVar5[4];

        fVar15 = pfVar1[1] * fVar2 + fVar15;

        pfVar5[5] = fVar15;

        pfVar5[6] = pfVar1[2] * fVar2 + fVar18;

        pfVar5[7] = pfVar1[3] * fVar2;

        fVar17 = pfVar1[3];

        pfVar5[4] = fVar17 * fVar10 + pfVar5[4];

        fVar16 = g_flLevelUpUiBase_Inferred;

        pfVar5[5] = fVar11 * fVar17 + fVar15;

        pfVar5[6] = fVar12 * fVar17 + pfVar5[6];

        pfVar5[7] = fVar2 * fVar17 + pfVar5[7];

        pfVar5[7] = pfVar1[3] * fVar2 - (pfVar1[2] * fVar12 + pfVar1[1] * fVar11 + fVar10 * *pfVar1)

        ;

      }

      iVar8 = iVar8 + 1;

      iVar9 = iVar9 + 0x20;

    } while (iVar8 < *(int *)(param_1 + 0x10));

  }

  return;

}
