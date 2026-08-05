// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_0074ba50
// -----------------------------------------------------------------------------
// Stable ID: aa_0074ba50
// Callee of Named_gfxDeviceVB
// Address:   0x0074ba50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~124 non-empty decompiler lines.
//  - Control keywords: if×15, do×3, while×3, return×2.
//  - Notable callees: SQRT×3, ABS, FUN_0074ba50.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_gfxDeviceVB_0074ba50(float *param_1,float *param_2,float param_3,uint param_4)



{

  float *pfVar1;

  int iVar2;

  float *pfVar3;

  int iVar4;

  float *pfVar5;

  float *pfVar6;

  float *pfVar7;

  uint uVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  uint local_10;

  

  iVar2 = (int)param_3;

  if (param_4 != 0) {

    pfVar1 = param_1 + 10;

    pfVar3 = param_2 + 2;

    local_10 = param_4;

    do {

      pfVar7 = pfVar3 + -2;

      pfVar6 = param_1 + 5;

      if (pfVar3[-2] < param_1[5] || pfVar3[-2] == param_1[5]) {

        pfVar6 = pfVar7;

      }

      param_1[5] = *pfVar6;

      pfVar6 = pfVar3 + -1;

      pfVar5 = param_1 + 6;

      if (pfVar3[-1] < param_1[6] || pfVar3[-1] == param_1[6]) {

        pfVar5 = pfVar6;

      }

      param_1[6] = *pfVar5;

      pfVar5 = param_1 + 7;

      if (*pfVar3 < param_1[7] || *pfVar3 == param_1[7]) {

        pfVar5 = pfVar3;

      }

      param_1[7] = *pfVar5;

      if (*pfVar7 <= param_1[8] && param_1[8] != *pfVar7) {

        pfVar7 = param_1 + 8;

      }

      param_1[8] = *pfVar7;

      if (*pfVar6 <= param_1[9] && param_1[9] != *pfVar6) {

        pfVar6 = param_1 + 9;

      }

      param_1[9] = *pfVar6;

      pfVar7 = pfVar1;

      if (*pfVar1 < *pfVar3 || *pfVar1 == *pfVar3) {

        pfVar7 = pfVar3;

      }

      pfVar3 = (float *)((int)pfVar3 + (int)param_3);

      local_10 = local_10 - 1;

      *pfVar1 = *pfVar7;

      fVar9 = DAT_00a0f298;

    } while (local_10 != 0);

    fVar10 = (param_1[6] + param_1[9]) * DAT_00a0f298;

    *param_1 = (param_1[8] + param_1[5]) * DAT_00a0f298;

    param_1[1] = fVar10;

    param_1[2] = (param_1[7] + param_1[10]) * fVar9;

    param_1[4] = ABS(SQRT((param_1[10] - param_1[2]) * (param_1[10] - param_1[2]) +

                          (param_1[8] - *param_1) * (param_1[8] - *param_1)));

    if (*(char *)(param_1 + 0xb) != '\0') {

      fVar9 = 0.0;

      uVar8 = 0;

      param_3 = 0.0;

      if (3 < (int)param_4) {

        iVar4 = (param_4 - 4 >> 2) + 1;

        uVar8 = iVar4 * 4;

        do {

          fVar10 = (param_1[2] - param_2[2]) * (param_1[2] - param_2[2]) +

                   (param_1[1] - param_2[1]) * (param_1[1] - param_2[1]) +

                   (*param_1 - *param_2) * (*param_1 - *param_2);

          if (fVar9 < fVar10) {

            fVar9 = fVar10;

          }

          fVar12 = param_1[1] - *(float *)((int)param_2 + iVar2 + 4);

          fVar11 = *param_1 - *(float *)((int)param_2 + iVar2);

          fVar10 = param_1[2] - *(float *)((int)param_2 + iVar2 + 8);

          fVar10 = fVar10 * fVar10 + fVar12 * fVar12 + fVar11 * fVar11;

          if (fVar9 < fVar10) {

            fVar9 = fVar10;

          }

          fVar12 = param_1[1] - *(float *)((int)param_2 + iVar2 * 2 + 4);

          fVar11 = *param_1 - *(float *)((int)param_2 + iVar2 * 2);

          fVar10 = param_1[2] - *(float *)((int)param_2 + iVar2 * 2 + 8);

          fVar10 = fVar10 * fVar10 + fVar12 * fVar12 + fVar11 * fVar11;

          if (fVar9 < fVar10) {

            fVar9 = fVar10;

          }

          fVar12 = param_1[1] - *(float *)((int)param_2 + iVar2 * 3 + 4);

          fVar11 = *param_1 - *(float *)((int)param_2 + iVar2 * 3);

          fVar10 = param_1[2] - *(float *)((int)param_2 + iVar2 * 3 + 8);

          param_2 = param_2 + iVar2;

          fVar10 = fVar10 * fVar10 + fVar12 * fVar12 + fVar11 * fVar11;

          if (fVar9 < fVar10) {

            fVar9 = fVar10;

          }

          iVar4 = iVar4 + -1;

          param_3 = fVar9;

        } while (iVar4 != 0);

      }

      if (uVar8 < param_4) {

        iVar4 = param_4 - uVar8;

        do {

          fVar9 = (param_1[2] - param_2[2]) * (param_1[2] - param_2[2]) +

                  (param_1[1] - param_2[1]) * (param_1[1] - param_2[1]) +

                  (*param_1 - *param_2) * (*param_1 - *param_2);

          if (param_3 < fVar9) {

            param_3 = fVar9;

          }

          param_2 = (float *)((int)param_2 + iVar2);

          iVar4 = iVar4 + -1;

        } while (iVar4 != 0);

      }

      *(uint8_t *)(param_1 + 0xb) = 0;

      param_1[3] = SQRT(param_3);

      return;

    }

    param_1[3] = SQRT((param_1[8] - *param_1) * (param_1[8] - *param_1) +

                      (param_1[9] - param_1[1]) * (param_1[9] - param_1[1]) +

                      (param_1[10] - param_1[2]) * (param_1[10] - param_1[2]));

  }

  return;

}
