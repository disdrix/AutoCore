// =============================================================================
// FUN_00706aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00706aa0
// Address:   0x00706aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00706aa0 @ 0x00706aa0
// Stable ID: aa_00706aa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×6, do×5, while×5, return×2.
//  - Notable callees: FUN_00706aa0.
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

int FUN_00706aa0(int param_1,int param_2,char *param_3,int param_4,int param_5)



{

  char cVar1;

  float fVar2;

  int iVar3;

  float fVar4;

  float *pfVar5;

  char *pcVar6;

  char *pcVar7;

  float *pfVar8;

  int iVar9;

  int iVar10;

  int local_10;

  int local_c;

  float local_8;

  

  local_8 = 0.0;

  local_10 = 0;

  local_c = 0;

  pcVar7 = param_3;

  if (0 < param_4) {

    do {

      iVar9 = 0;

      fVar4 = g_flZero;

      if (3 < param_5) {

        iVar10 = (param_5 - 4U >> 2) + 1;

        iVar9 = iVar10 * 4;

        pfVar5 = (float *)(param_2 + 4);

        pcVar6 = pcVar7;

        pfVar8 = (float *)(param_1 + 0xc);

        do {

          pcVar7 = pcVar6 + 4;

          iVar10 = iVar10 + -1;

          fVar2 = *(float *)((param_1 - param_2) + -0x10 + (int)(pfVar5 + 4)) -

                  (float)(int)pcVar6[1];

          fVar4 = (*pfVar8 - (float)(int)pcVar6[3]) * (*pfVar8 - (float)(int)pcVar6[3]) * pfVar5[2]

                  + (pfVar8[-1] - (float)(int)pcVar6[2]) * (pfVar8[-1] - (float)(int)pcVar6[2]) *

                    pfVar5[1] +

                    fVar2 * fVar2 * *pfVar5 +

                    (pfVar8[-3] - (float)(int)*pcVar6) * (pfVar8[-3] - (float)(int)*pcVar6) *

                    pfVar5[-1] + fVar4;

          pfVar5 = pfVar5 + 4;

          pcVar6 = pcVar7;

          pfVar8 = pfVar8 + 4;

        } while (iVar10 != 0);

      }

      if (iVar9 < param_5) {

        iVar10 = param_5 - iVar9;

        pfVar5 = (float *)(param_2 + iVar9 * 4);

        do {

          cVar1 = *pcVar7;

          pcVar7 = pcVar7 + 1;

          iVar10 = iVar10 + -1;

          fVar2 = *(float *)((int)pfVar5 + (param_1 - param_2)) - (float)(int)cVar1;

          fVar4 = fVar2 * fVar2 * *pfVar5 + fVar4;

          pfVar5 = pfVar5 + 1;

        } while (iVar10 != 0);

      }

      iVar9 = local_c;

      if ((local_8 <= fVar4) && (iVar9 = local_c, local_c != 0)) {

        iVar9 = local_10;

        fVar4 = local_8;

      }

      local_8 = fVar4;

      local_10 = iVar9;

      local_c = local_c + 1;

    } while (local_c < param_4);

  }

  iVar9 = 0;

  if (3 < param_5) {

    iVar10 = local_10 * param_5;

    pfVar5 = (float *)(param_1 + 8);

    do {

      iVar3 = iVar9 + iVar10;

      iVar9 = iVar9 + 4;

      pfVar5[-2] = pfVar5[-2] - (float)(int)param_3[iVar3];

      pfVar5[-1] = pfVar5[-1] - (float)(int)param_3[iVar9 + iVar10 + -3];

      *pfVar5 = *pfVar5 - (float)(int)param_3[iVar9 + iVar10 + -2];

      pfVar5[1] = pfVar5[1] - (float)(int)param_3[iVar9 + iVar10 + -1];

      pfVar5 = pfVar5 + 4;

    } while (iVar9 < param_5 + -3);

  }

  if (param_5 <= iVar9) {

    return local_10;

  }

  do {

    iVar10 = iVar9 + local_10 * param_5;

    iVar9 = iVar9 + 1;

    *(float *)(param_1 + -4 + iVar9 * 4) =

         *(float *)(param_1 + -4 + iVar9 * 4) - (float)(int)param_3[iVar10];

  } while (iVar9 < param_5);

  return local_10;

}
