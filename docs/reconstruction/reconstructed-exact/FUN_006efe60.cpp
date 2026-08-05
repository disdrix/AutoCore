// =============================================================================
// FUN_006efe60
// -----------------------------------------------------------------------------
// Stable ID: aa_006efe60
// Address:   0x006efe60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006efe60 @ 0x006efe60
// Stable ID: aa_006efe60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_006efe60, SQRT.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006efe60(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *piVar1;

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

  int iVar12;

  float *pfVar13;

  int iVar14;

  int iVar15;

  

  *param_1 = &PTR_FUN_009e5fdc;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = *param_2;

  piVar1 = param_1 + 4;

  *param_1 = &PTR_FUN_00a0ed58;

  iVar15 = 0;

  *piVar1 = (int)(param_1 + 8);

  param_1[5] = 0;

  param_1[6] = 0x80000004;

  if (0 < (int)param_2[2]) {

    iVar14 = (param_2[2] - 1 >> 1) + 1;

    do {

      fVar2 = *(float *)(param_2[1] + iVar15);

      iVar12 = param_2[1] + iVar15;

      fVar3 = *(float *)(iVar12 + 4);

      fVar4 = *(float *)(iVar12 + 8);

      fVar5 = *(float *)(iVar12 + 0x10);

      fVar9 = fVar5 - fVar2;

      fVar6 = *(float *)(iVar12 + 0x14);

      fVar11 = fVar6 - fVar3;

      fVar7 = *(float *)(iVar12 + 0x18);

      fVar10 = fVar7 - fVar4;

      fVar8 = *(float *)(iVar12 + 0x1c);

      if (param_1[5] == (param_1[6] & 0x7fffffff)) {

        FUN_005b3370(piVar1,0x20);

      }

      pfVar13 = (float *)(param_1[5] * 0x20 + *piVar1);

      param_1[5] = param_1[5] + 1;

      *pfVar13 = fVar2;

      pfVar13[1] = fVar3;

      pfVar13[2] = fVar4;

      pfVar13[3] = SQRT(fVar9 * fVar9 + fVar11 * fVar11 + fVar10 * fVar10);

      pfVar13[4] = fVar5;

      pfVar13[5] = fVar6;

      pfVar13[6] = fVar7;

      iVar15 = iVar15 + 0x20;

      iVar14 = iVar14 + -1;

      pfVar13[7] = fVar8;

    } while (iVar14 != 0);

  }

  return param_1;

}
