// =============================================================================
// FUN_0074b700
// -----------------------------------------------------------------------------
// Stable ID: aa_0074b700
// Address:   0x0074b700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074b700 @ 0x0074b700
// Stable ID: aa_0074b700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, for×1.
//  - Notable callees: SQRT×2, ABS, FUN_0074b700.
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

void __thiscall FUN_0074b700(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  float *pfVar5;

  float *pfVar6;

  float *pfVar7;

  float fVar8;

  float fVar9;

  

  if (*(char *)(param_2 + 0xb) == '\0') {

    if (*(char *)(param_1 + 0xb) != '\0') {

      for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {

        *param_1 = *param_2;

        param_2 = param_2 + 1;

        param_1 = param_1 + 1;

      }

      return;

    }

    pfVar5 = param_1 + 5;

    if (param_2[5] < param_1[5] || param_2[5] == param_1[5]) {

      pfVar5 = param_2 + 5;

    }

    param_1[5] = *pfVar5;

    pfVar5 = param_2 + 6;

    if (param_1[6] <= param_2[6] && param_2[6] != param_1[6]) {

      pfVar5 = param_1 + 6;

    }

    param_1[6] = *pfVar5;

    pfVar5 = param_2 + 7;

    if (param_1[7] <= param_2[7] && param_2[7] != param_1[7]) {

      pfVar5 = param_1 + 7;

    }

    param_1[7] = *pfVar5;

    pfVar5 = param_1 + 8;

    pfVar6 = pfVar5;

    if (param_1[8] < param_2[8] || param_1[8] == param_2[8]) {

      pfVar6 = param_2 + 8;

    }

    *pfVar5 = *pfVar6;

    pfVar6 = param_2 + 9;

    if (param_2[9] <= param_1[9] && param_1[9] != param_2[9]) {

      pfVar6 = param_1 + 9;

    }

    param_1[9] = *pfVar6;

    pfVar6 = param_1 + 10;

    pfVar7 = param_2 + 10;

    if (param_2[10] <= param_1[10] && param_1[10] != param_2[10]) {

      pfVar7 = pfVar6;

    }

    *pfVar6 = *pfVar7;

    fVar1 = *param_2 - *param_1;

    fVar2 = param_2[1] - param_1[1];

    fVar3 = param_2[2] - param_1[2];

    fVar8 = SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);

    fVar9 = (param_2[3] + param_1[3] + fVar8) * DAT_00a0f298;

    if (param_1[3] < fVar9) {

      if (param_2[3] < fVar9) {

        if (g_flZero < fVar8) {

          fVar8 = (fVar9 - param_1[3]) / fVar8;

          *param_1 = *param_1 + fVar1 * fVar8;

          param_1[1] = param_1[1] + fVar2 * fVar8;

          param_1[2] = param_1[2] + fVar3 * fVar8;

        }

        param_1[3] = fVar9;

      }

      else {

        param_1[3] = param_2[3];

        *param_1 = *param_2;

        param_1[1] = param_2[1];

        param_1[2] = param_2[2];

      }

    }

    *(uint8_t *)(param_1 + 0xb) = 0;

    param_1[4] = ABS(SQRT((*pfVar6 - param_1[2]) * (*pfVar6 - param_1[2]) +

                          (*pfVar5 - *param_1) * (*pfVar5 - *param_1)));

  }

  return;

}
