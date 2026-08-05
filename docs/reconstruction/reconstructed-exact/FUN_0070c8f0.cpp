// =============================================================================
// FUN_0070c8f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0070c8f0
// Address:   0x0070c8f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070c8f0 @ 0x0070c8f0
// Stable ID: aa_0070c8f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~218 non-empty decompiler lines.
//  - Control keywords: if×20, while×11, do×10, goto×4, return×1.
//  - Notable callees: FUN_0070c8a0×3, SQRT×2, FUN_0070c8f0.
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



void FUN_0070c8f0(int param_1,int param_2,int param_3,int param_4,int param_5,float *param_6,

                 int param_7,float *param_8)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  int iVar7;

  float *pfVar8;

  float *pfVar9;

  uint32_t /* width from decompiler */ *puVar10;

  float *pfVar11;

  int iVar12;

  uint32_t /* width from decompiler */ *puVar13;

  float *pfVar14;

  int iVar15;

  int iVar16;

  float10 fVar17;

  float10 fVar18;

  int local_c;

  

  iVar6 = (int)param_8 + (-(int)param_8 & 3U) + param_7 * 4;

  iVar12 = iVar6 + param_7 * -4;

  iVar15 = param_3 - param_2;

  iVar6 = (-iVar6 & 3U) + iVar6 + 4 + iVar15 * 4;

  pfVar2 = (float *)(iVar6 + -4 + (param_2 - param_3) * 4);

  iVar6 = (-iVar6 & 3U) + iVar6 + 8 + iVar15 * 4;

  pfVar3 = (float *)(iVar6 + -8 + (param_2 - param_3) * 4);

  pfVar14 = (float *)((-iVar6 & 3U) + iVar6);

  if (0 < param_7) {

    pfVar9 = param_6;

    iVar6 = param_7;

    do {

      *(uint32_t /* width from decompiler */ *)((iVar12 - (int)param_6) + (int)pfVar9) = 0xbf800000;

      *pfVar9 = 0.0;

      *(int *)((param_5 - (int)param_6) + (int)pfVar9) = param_2;

      pfVar9 = pfVar9 + 1;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

  }

  fVar17 = (float10)FUN_0070c8a0();

  *pfVar3 = (float)fVar17;

  fVar17 = (float10)FUN_0070c8a0();

  iVar15 = iVar15 + 1;

  iVar6 = param_2;

  if (3 < iVar15) {

    iVar7 = ((param_3 - param_2) - 3U >> 2) + 1;

    iVar6 = param_2 + iVar7 * 4;

    pfVar9 = (float *)(param_1 - (param_2 * 4 + 8));

    pfVar11 = pfVar3 + 2;

    pfVar8 = (float *)(param_1 + -8 + (param_4 - param_2) * 4);

    do {

      iVar7 = iVar7 + -1;

      fVar4 = (pfVar9[1] * pfVar9[1] + pfVar11[-2]) - pfVar8[1] * pfVar8[1];

      pfVar11[-1] = fVar4;

      fVar4 = (*pfVar9 * *pfVar9 + fVar4) - *pfVar8 * *pfVar8;

      *pfVar11 = fVar4;

      fVar4 = (pfVar9[-1] * pfVar9[-1] + fVar4) - pfVar8[-1] * pfVar8[-1];

      pfVar11[1] = fVar4;

      pfVar11[2] = (pfVar9[-2] * pfVar9[-2] + fVar4) - pfVar8[-2] * pfVar8[-2];

      pfVar9 = pfVar9 + -4;

      pfVar11 = pfVar11 + 4;

      pfVar8 = pfVar8 + -4;

    } while (iVar7 != 0);

  }

  if (iVar6 <= param_3) {

    pfVar8 = (float *)(param_1 - (iVar6 * 4 + 4));

    pfVar9 = (float *)(param_1 + -4 + (param_4 - iVar6) * 4);

    iVar7 = (param_3 - iVar6) + 1;

    pfVar11 = pfVar3 + (iVar6 - param_2);

    do {

      fVar4 = *pfVar8;

      pfVar8 = pfVar8 + -1;

      fVar5 = *pfVar9;

      pfVar9 = pfVar9 + -1;

      iVar7 = iVar7 + -1;

      pfVar11[1] = (fVar4 * fVar4 + *pfVar11) - fVar5 * fVar5;

      pfVar11 = pfVar11 + 1;

    } while (iVar7 != 0);

  }

  if (param_2 <= param_3) {

    pfVar9 = pfVar14;

    iVar6 = iVar15;

    do {

      *(uint32_t /* width from decompiler */ *)(((int)pfVar2 - (int)pfVar14) + (int)pfVar9) = 0;

      *pfVar9 = 0.0;

      pfVar9 = pfVar9 + 1;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

  }

  param_8 = pfVar2;

  local_c = iVar15;

  if (param_2 <= param_3) {

    do {

      fVar18 = (float10)FUN_0070c8a0();

      *param_8 = (float)fVar18;

      local_c = local_c + -1;

      param_8 = param_8 + 1;

    } while (local_c != 0);

  }

  iVar6 = param_2;

  if (3 < iVar15) {

    pfVar9 = pfVar2 + 1;

    iVar15 = ((param_3 - param_2) - 3U >> 2) + 1;

    iVar6 = param_2 + iVar15 * 4;

    pfVar11 = pfVar3;

    pfVar8 = pfVar14 + 2;

    do {

      fVar4 = pfVar9[-1] / (*pfVar11 + g_flOne);

      fVar5 = DAT_00a0f6d0;

      if ((fVar4 <= DAT_00a0f6d0) && (fVar5 = fVar4, fVar4 < _DAT_00a0f260)) {

        fVar5 = _DAT_00a0f260;

      }

      pfVar8[-2] = fVar5 * pfVar9[-1];

      fVar4 = *pfVar9 / (*(float *)(((int)pfVar3 - (int)pfVar2) + (int)pfVar9) + g_flOne);

      fVar5 = DAT_00a0f6d0;

      if ((fVar4 <= DAT_00a0f6d0) && (fVar5 = fVar4, fVar4 < _DAT_00a0f260)) {

        fVar5 = _DAT_00a0f260;

      }

      *(float *)(((int)pfVar14 - (int)pfVar2) + (int)pfVar9) = fVar5 * *pfVar9;

      fVar4 = pfVar9[1] / (*(float *)(((int)pfVar3 - (int)pfVar14) + (int)pfVar8) + g_flOne);

      fVar5 = DAT_00a0f6d0;

      if ((fVar4 <= DAT_00a0f6d0) && (fVar5 = fVar4, fVar4 < _DAT_00a0f260)) {

        fVar5 = _DAT_00a0f260;

      }

      *pfVar8 = fVar5 * pfVar9[1];

      fVar4 = pfVar9[2] / (pfVar11[3] + g_flOne);

      fVar5 = DAT_00a0f6d0;

      if ((fVar4 <= DAT_00a0f6d0) && (fVar5 = fVar4, fVar4 < _DAT_00a0f260)) {

        fVar5 = _DAT_00a0f260;

      }

      pfVar1 = pfVar9 + 2;

      pfVar11 = pfVar11 + 4;

      pfVar9 = pfVar9 + 4;

      iVar15 = iVar15 + -1;

      pfVar8[1] = fVar5 * *pfVar1;

      pfVar8 = pfVar8 + 4;

    } while (iVar15 != 0);

  }

  iVar15 = param_2;

  if (iVar6 <= param_3) {

    iVar7 = (param_3 - iVar6) + 1;

    pfVar9 = pfVar2 + (iVar6 - param_2);

    do {

      fVar4 = *pfVar9 / (*(float *)((int)pfVar9 + ((int)pfVar3 - (int)pfVar2)) + g_flOne);

      fVar5 = DAT_00a0f6d0;

      if ((fVar4 <= DAT_00a0f6d0) && (fVar5 = fVar4, fVar4 < _DAT_00a0f260)) {

        fVar5 = _DAT_00a0f260;

      }

      iVar7 = iVar7 + -1;

      *(float *)((int)pfVar9 + ((int)pfVar14 - (int)pfVar2)) = fVar5 * *pfVar9;

      pfVar9 = pfVar9 + 1;

    } while (iVar7 != 0);

  }

  while( true ) {

    if (param_3 < iVar15) {

      if (0 < param_7) {

        param_5 = param_5 - (int)param_6;

        do {

          iVar15 = *(int *)((int)param_6 + param_5) - param_2;

          fVar4 = pfVar2[iVar15] /

                  (SQRT(pfVar3[iVar15]) * SQRT((float)fVar17) + (float)_DAT_00a0f6c8);

          if (fVar4 < g_flZero) {

            fVar4 = g_flZero;

          }

          *param_6 = fVar4;

          param_6 = param_6 + 1;

          param_7 = param_7 + -1;

        } while (param_7 != 0);

      }

      return;

    }

    if ((*(float *)(iVar12 + -4 + param_7 * 4) < *pfVar14) && (iVar6 = 0, 0 < param_7)) break;

LAB_0070ce1b:

    pfVar14 = pfVar14 + 1;

    iVar15 = iVar15 + 1;

  }

LAB_0070cd53:

  if (*pfVar14 <= *(float *)(iVar12 + iVar6 * 4)) goto code_r0x0070cd5f;

  iVar7 = param_7 + -1;

  if (3 < iVar7 - iVar6) {

    puVar10 = (uint32_t /* width from decompiler */ *)(param_5 + -4 + iVar7 * 4);

    puVar13 = (uint32_t /* width from decompiler */ *)(iVar12 + -8 + iVar7 * 4);

    iVar16 = ((iVar7 - iVar6) - 4U >> 2) + 1;

    iVar7 = iVar7 + iVar16 * -4;

    do {

      puVar13[2] = *(uint32_t /* width from decompiler */ *)((iVar12 - param_5) + (int)puVar10);

      puVar10[1] = *puVar10;

      *(uint32_t /* width from decompiler */ *)((iVar12 - param_5) + (int)puVar10) = *puVar13;

      *puVar10 = puVar10[-1];

      *puVar13 = puVar13[-1];

      puVar10[-1] = puVar10[-2];

      puVar13[-1] = puVar13[-2];

      puVar10[-2] = puVar10[-3];

      puVar10 = puVar10 + -4;

      puVar13 = puVar13 + -4;

      iVar16 = iVar16 + -1;

    } while (iVar16 != 0);

  }

  if (iVar6 < iVar7) {

    puVar10 = (uint32_t /* width from decompiler */ *)(param_5 + -4 + iVar7 * 4);

    do {

      *(uint32_t /* width from decompiler */ *)(iVar12 + iVar7 * 4) = *(uint32_t /* width from decompiler */ *)((int)puVar10 + (iVar12 - param_5));

      puVar10[1] = *puVar10;

      iVar7 = iVar7 + -1;

      puVar10 = puVar10 + -1;

    } while (iVar6 < iVar7);

  }

  *(float *)(iVar12 + iVar6 * 4) = *pfVar14;

  *(int *)(param_5 + iVar6 * 4) = iVar15;

  goto LAB_0070ce1b;

code_r0x0070cd5f:

  iVar6 = iVar6 + 1;

  if (param_7 <= iVar6) goto LAB_0070ce1b;

  goto LAB_0070cd53;

}
