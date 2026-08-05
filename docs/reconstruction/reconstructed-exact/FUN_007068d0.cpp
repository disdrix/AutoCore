// =============================================================================
// FUN_007068d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007068d0
// Address:   0x007068d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007068d0 @ 0x007068d0
// Stable ID: aa_007068d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×5, while×5, do×4, return×1.
//  - Notable callees: FUN_007068d0.
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

int FUN_007068d0(char *param_1,int param_2)



{

  char cVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  char *pcVar5;

  char *pcVar6;

  int unaff_EBX;

  int iVar7;

  int iVar8;

  int iVar9;

  int unaff_EDI;

  int local_10;

  float local_c;

  int local_8;

  

  iVar7 = 0;

  local_c = 0.0;

  local_10 = 0;

  local_8 = 0;

  pcVar6 = param_1;

  if (0 < param_2) {

    do {

      iVar9 = 0;

      fVar3 = g_flZero;

      iVar8 = iVar7;

      if (3 < unaff_EDI) {

        iVar7 = (unaff_EDI - 4U >> 2) + 1;

        iVar9 = iVar7 * 4;

        pfVar4 = (float *)(unaff_EBX + 8);

        pcVar5 = pcVar6;

        do {

          pcVar6 = pcVar5 + 4;

          iVar7 = iVar7 + -1;

          fVar3 = (pfVar4[1] - (float)(int)pcVar5[3]) * (pfVar4[1] - (float)(int)pcVar5[3]) +

                  (*pfVar4 - (float)(int)pcVar5[2]) * (*pfVar4 - (float)(int)pcVar5[2]) +

                  (pfVar4[-1] - (float)(int)pcVar5[1]) * (pfVar4[-1] - (float)(int)pcVar5[1]) +

                  (pfVar4[-2] - (float)(int)*pcVar5) * (pfVar4[-2] - (float)(int)*pcVar5) + fVar3;

          pfVar4 = pfVar4 + 4;

          pcVar5 = pcVar6;

          iVar8 = local_10;

        } while (iVar7 != 0);

      }

      while (iVar9 < unaff_EDI) {

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

        iVar9 = iVar9 + 1;

        fVar2 = *(float *)(unaff_EBX + -4 + iVar9 * 4) - (float)(int)cVar1;

        fVar3 = fVar2 * fVar2 + fVar3;

      }

      iVar7 = local_8;

      iVar9 = local_8;

      if ((local_c <= fVar3) && (iVar9 = local_8, local_8 != 0)) {

        iVar7 = iVar8;

        iVar9 = local_10;

        fVar3 = local_c;

      }

      local_c = fVar3;

      local_10 = iVar9;

      local_8 = local_8 + 1;

    } while (local_8 < param_2);

  }

  iVar9 = 0;

  if (3 < unaff_EDI) {

    iVar8 = iVar7 * unaff_EDI;

    pfVar4 = (float *)(unaff_EBX + 8);

    do {

      iVar7 = iVar9 + iVar8;

      iVar9 = iVar9 + 4;

      pfVar4[-2] = pfVar4[-2] - (float)(int)param_1[iVar7];

      pfVar4[-1] = pfVar4[-1] - (float)(int)param_1[iVar9 + iVar8 + -3];

      *pfVar4 = *pfVar4 - (float)(int)param_1[iVar9 + iVar8 + -2];

      pfVar4[1] = pfVar4[1] - (float)(int)param_1[iVar9 + iVar8 + -1];

      pfVar4 = pfVar4 + 4;

      iVar7 = local_10;

    } while (iVar9 < unaff_EDI + -3);

  }

  if (iVar9 < unaff_EDI) {

    do {

      iVar8 = iVar9 + iVar7 * unaff_EDI;

      iVar9 = iVar9 + 1;

      *(float *)(unaff_EBX + -4 + iVar9 * 4) =

           *(float *)(unaff_EBX + -4 + iVar9 * 4) - (float)(int)param_1[iVar8];

    } while (iVar9 < unaff_EDI);

  }

  return iVar7;

}
