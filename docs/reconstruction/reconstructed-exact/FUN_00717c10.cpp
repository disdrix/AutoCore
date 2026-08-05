// =============================================================================
// FUN_00717c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00717c10
// Address:   0x00717c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00717c10 @ 0x00717c10
// Stable ID: aa_00717c10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: while×2, if×2, for×1, do×1, return×1.
//  - Notable callees: ftol×2, FUN_00717c10.
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



float10 FUN_00717c10(uint32_t /* width from decompiler */ param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int param_4,int param_5,

                    float param_6)



{

  int *piVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float fVar9;

  int *piVar10;

  int iVar11;

  float10 fVar12;

  float10 fVar13;

  float10 fVar14;

  

  iVar3 = ftol();

  iVar4 = ftol();

  fVar12 = (float10)_DAT_00a132f4;

  iVar5 = (int)(0x10000000 / (longlong)iVar4);

  fVar13 = (float10)_DAT_00a132f4;

  iVar11 = 0;

  iVar6 = 0x4000;

  iVar4 = *param_2;

  piVar10 = param_2;

  while (iVar4 = iVar4 * iVar3, iVar4 < 0x4000) {

    piVar1 = piVar10 + 1;

    piVar10 = piVar10 + 1;

    iVar11 = iVar11 + 1;

    iVar4 = *piVar1;

  }

  for (iVar8 = iVar5 + 0x800; iVar8 >> 0xc < param_5; iVar8 = iVar8 + iVar5) {

    iVar6 = iVar6 + 0x8000;

    param_1 = 1e-16;

    if (iVar4 < iVar6) {

      fVar9 = 1e-16;

      piVar10 = param_2 + iVar11;

      iVar7 = param_2[iVar11];

      do {

        fVar2 = (*(float *)(PTR_DAT_00af8b14 + (iVar4 >> 7 & 0xffU) * 4) + g_flOne) *

                *(float *)(param_4 + iVar7 * 4);

        if ((int)fVar9 < (int)fVar2) {

          fVar9 = fVar2;

          param_1 = fVar2;

        }

        iVar7 = piVar10[1];

        piVar10 = piVar10 + 1;

        iVar4 = iVar7 * iVar3;

        iVar11 = iVar11 + 1;

      } while (iVar4 < iVar6);

    }

    fVar14 = (float10)*(float *)(param_4 + (iVar8 >> 0xc) * 4);

    fVar12 = fVar14 * (float10)param_1 + fVar12;

    fVar13 = fVar14 * fVar14 + fVar13;

  }

  return (fVar12 * (float10)DAT_00a0f298 - fVar13 * (float10)_DAT_009dd038) * (float10)param_6;

}
