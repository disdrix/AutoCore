// =============================================================================
// FUN_0070f900
// -----------------------------------------------------------------------------
// Stable ID: aa_0070f900
// Address:   0x0070f900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070f900 @ 0x0070f900
// Stable ID: aa_0070f900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, for×1, return×1.
//  - Notable callees: fcos×2, FUN_0070f900.
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



void FUN_0070f900(float *param_1,int param_2,int param_3,float param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  int iVar5;

  float *pfVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  float *pfVar9;

  uint32_t /* width from decompiler */ *puVar10;

  float10 fVar11;

  float10 fVar12;

  float10 fVar13;

  int local_c;

  

  iVar8 = param_3 / 2;

  puVar7 = (uint32_t /* width from decompiler */ *)((-(int)param_4 & 3U) + (int)param_4);

  pfVar9 = (float *)0x0;

  if (-1 < iVar8 * 4 + 1) {

    puVar10 = puVar7;

    for (iVar5 = iVar8 * 4 + 2; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar10 = 0;

      puVar10 = puVar10 + 1;

    }

  }

  param_4 = 1.0;

  local_c = 0;

  fVar1 = g_flOne;

  if (-1 < param_3) {

    do {

      fVar11 = (float10)fVar1;

      if (0 < iVar8) {

        pfVar4 = (float *)(puVar7 + 2);

        pfVar6 = param_1;

        iVar5 = iVar8;

        do {

          pfVar9 = pfVar4 + 1;

          fVar12 = (float10)fcos((float10)*pfVar6);

          iVar5 = iVar5 + -1;

          fVar1 = pfVar4[-2];

          fVar2 = pfVar4[-1];

          fVar13 = (float10)fcos((float10)pfVar6[1]);

          fVar3 = *pfVar9;

          pfVar4[-1] = pfVar4[-2];

          *pfVar9 = *pfVar4;

          fVar3 = (float)(((float10)param_4 -

                          (fVar13 * (float10)*pfVar4 + fVar13 * (float10)*pfVar4)) + (float10)fVar3)

          ;

          pfVar4[-2] = (float)fVar11;

          *pfVar4 = param_4;

          fVar11 = (float10)(float)((fVar11 - (fVar12 * (float10)fVar1 + fVar12 * (float10)fVar1)) +

                                   (float10)fVar2);

          pfVar4 = pfVar4 + 4;

          pfVar6 = pfVar6 + 2;

          param_4 = fVar3;

        } while (iVar5 != 0);

      }

      fVar1 = param_4;

      fVar12 = (float10)param_4;

      local_c = local_c + 1;

      param_4 = 0.0;

      *(float *)(param_2 + -4 + local_c * 4) =

           (float)((fVar11 + (float10)pfVar9[1] + (fVar12 - (float10)pfVar9[2])) *

                  (float10)_DAT_00aaa5e0);

      pfVar9[1] = (float)fVar11;

      pfVar9[2] = fVar1;

      fVar1 = g_flZero;

    } while (local_c <= param_3);

  }

  return;

}
