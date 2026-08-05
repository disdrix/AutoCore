// =============================================================================
// FUN_00761210
// -----------------------------------------------------------------------------
// Stable ID: aa_00761210
// Address:   0x00761210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00761210 @ 0x00761210
// Stable ID: aa_00761210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×15, return×7, while×3, do×2.
//  - Notable callees: FUN_00761210, FUN_00972fa0, SQRT.
//  - Return sites: 7.

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

void FUN_00761210(int param_1)



{

  float fVar1;

  float fVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  float *pfVar9;

  float *pfVar10;

  int unaff_ESI;

  float fVar11;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  if ((*(int *)(unaff_ESI + 0xc) != 0) &&

     (iVar7 = *(int *)(unaff_ESI + 0x10) - *(int *)(unaff_ESI + 0xc), iVar4 = iVar7 >> 0x1f,

     iVar7 / 0x28 + iVar4 != iVar4)) {

    uVar3 = (**(code **)(**(int **)(unaff_ESI + 4) + 0x48))();

    (**(code **)(**(int **)(unaff_ESI + 4) + 0xc))(uVar3);

    FUN_00972fa0(uVar3);

    iVar4 = *(int *)(param_1 + 8);

    fVar11 = fStack_c - *(float *)(iVar4 + 0x90);

    fVar1 = fStack_8 - *(float *)(iVar4 + 0x94);

    fVar2 = fStack_4 - *(float *)(iVar4 + 0x98);

    iVar4 = (**(code **)(**(int **)(unaff_ESI + 4) + 0x48))();

    fVar11 = (SQRT(fVar11 * fVar11 + fVar1 * fVar1 + fVar2 * fVar2) - *(float *)(iVar4 + 0xc)) -

             DAT_00d1a540;

    iVar4 = (**(code **)(**(int **)(unaff_ESI + 4) + 0xc))();

    if (g_flZero < *(float *)(iVar4 + 0x9c)) {

      iVar4 = (**(code **)(**(int **)(unaff_ESI + 4) + 0xc))();

      fVar11 = fVar11 / *(float *)(iVar4 + 0x9c);

    }

    iVar4 = *(int *)(unaff_ESI + 0x18);

    fVar11 = fVar11 / DAT_00afa2ec;

    iVar7 = *(int *)(unaff_ESI + 0xc);

    if (fVar11 < *(float *)(iVar7 + 0x20 + iVar4 * 0x28) - *(float *)(unaff_ESI + 0x1c)) {

      iVar6 = iVar4 + -1;

      if (3 < iVar4) {

        iVar7 = iVar7 + iVar6 * 0x28;

        pfVar10 = (float *)(iVar7 + 0x24);

        iVar4 = iVar4 + -3;

        pfVar9 = (float *)(iVar7 + -4);

        do {

          *(int *)(unaff_ESI + 0x18) = iVar6;

          if ((pfVar10[-1] <= fVar11) && (fVar11 <= *pfVar10)) {

            return;

          }

          *(int *)(unaff_ESI + 0x18) = iVar4 + 1;

          if ((pfVar9[-1] <= fVar11) && (fVar11 <= *pfVar9)) {

            return;

          }

          *(int *)(unaff_ESI + 0x18) = iVar4;

          if ((pfVar9[-0xb] <= fVar11) && (fVar11 <= pfVar9[-10])) {

            return;

          }

          *(int *)(unaff_ESI + 0x18) = iVar4 + -1;

          if ((pfVar9[-0x15] <= fVar11) && (fVar11 <= pfVar9[-0x14])) {

            return;

          }

          iVar6 = iVar6 + -4;

          pfVar10 = pfVar10 + -0x28;

          pfVar9 = pfVar9 + -0x28;

          iVar4 = iVar4 + -4;

        } while (2 < iVar6);

      }

      if (-1 < iVar6) {

        pfVar10 = (float *)(*(int *)(unaff_ESI + 0xc) + 0x24 + iVar6 * 0x28);

        do {

          *(int *)(unaff_ESI + 0x18) = iVar6;

          if ((pfVar10[-1] <= fVar11) && (fVar11 <= *pfVar10)) {

            return;

          }

          iVar6 = iVar6 + -1;

          pfVar10 = pfVar10 + -10;

        } while (-1 < iVar6);

      }

    }

    else if (*(float *)(iVar7 + iVar4 * 0x28 + 0x24) + *(float *)(unaff_ESI + 0x1c) < fVar11) {

      if (iVar7 == 0) {

        uVar8 = 0;

      }

      else {

        uVar8 = (*(int *)(unaff_ESI + 0x10) - iVar7) / 0x28;

      }

      if (DAT_00afa2f0 != '\0') {

        uVar8 = uVar8 - 1;

      }

      uVar5 = iVar4 + 1;

      if (uVar5 < uVar8) {

        pfVar10 = (float *)(iVar7 + 0x24 + uVar5 * 0x28);

        while ((*(uint *)(unaff_ESI + 0x18) = uVar5, fVar11 < pfVar10[-1] || (*pfVar10 < fVar11))) {

          uVar5 = uVar5 + 1;

          pfVar10 = pfVar10 + 10;

          if (uVar8 <= uVar5) {

            return;

          }

        }

      }

    }

  }

  return;

}
