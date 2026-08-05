// =============================================================================
// FUN_0070ed00
// -----------------------------------------------------------------------------
// Stable ID: aa_0070ed00
// Address:   0x0070ed00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070ed00 @ 0x0070ed00
// Stable ID: aa_0070ed00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×6, do×6, while×6, return×1.
//  - Notable callees: FUN_0070ed00.
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

void FUN_0070ed00(int param_1,int param_2,int param_3,float param_4,int param_5,int param_6,

                 uint32_t /* width from decompiler */ *param_7)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  float *pfVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  float *pfVar10;

  float *pfVar11;

  int iVar12;

  float *pfVar13;

  int iVar14;

  float local_18;

  float local_14;

  uint32_t /* width from decompiler */ *local_10;

  uint32_t /* width from decompiler */ *local_c;

  

  iVar14 = (-(int)param_7 & 3U) + (int)param_7;

  iVar5 = (int)param_4 / 2;

  iVar12 = 0;

  if (3 < iVar5) {

    local_10 = (uint32_t /* width from decompiler */ *)(param_1 + -0x10 + iVar5 * 4);

    local_c = (uint32_t /* width from decompiler */ *)(param_1 + -0xc + iVar5 * 4);

    param_7 = (uint32_t /* width from decompiler */ *)(param_1 + -8 + iVar5 * 4);

    iVar8 = (iVar5 - 4U >> 2) + 1;

    puVar7 = (uint32_t /* width from decompiler */ *)(iVar14 + 0x10);

    puVar9 = (uint32_t /* width from decompiler */ *)(param_1 + -4 + iVar5 * 4);

    iVar12 = iVar8 * 4;

    do {

      puVar7[-4] = *puVar9;

      puVar7[-2] = *param_7;

      *puVar7 = *local_c;

      puVar7[2] = *local_10;

      param_7 = param_7 + -4;

      local_c = local_c + -4;

      local_10 = local_10 + -4;

      puVar7 = puVar7 + 8;

      puVar9 = puVar9 + -4;

      iVar8 = iVar8 + -1;

    } while (iVar8 != 0);

  }

  if (iVar12 < iVar5) {

    puVar7 = (uint32_t /* width from decompiler */ *)(param_1 + -4 + (iVar5 - iVar12) * 4);

    do {

      *(uint32_t /* width from decompiler */ *)(iVar14 + iVar12 * 8) = *puVar7;

      iVar12 = iVar12 + 1;

      puVar7 = puVar7 + -1;

    } while (iVar12 < iVar5);

  }

  iVar12 = param_5 + -1;

  if (0 < iVar12) {

    puVar9 = (uint32_t /* width from decompiler */ *)(param_6 + 4);

    puVar7 = (uint32_t /* width from decompiler */ *)(iVar14 + (int)param_4 * 4);

    iVar5 = (param_5 - 2U >> 1) + 1;

    do {

      *puVar7 = *puVar9;

      puVar9 = puVar9 + 2;

      puVar7 = puVar7 + 2;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

  }

  if (0 < (int)param_4) {

    pfVar11 = (float *)(param_3 + 8);

    iVar5 = ((int)param_4 - 1U >> 2) + 1;

    pfVar13 = (float *)(iVar14 + (int)param_4 * 4);

    do {

      param_4 = pfVar13[-4];

      local_10 = (uint32_t /* width from decompiler */ *)0x0;

      local_14 = 0.0;

      local_18 = 0.0;

      fVar4 = g_flZero;

      if (0 < param_5) {

        iVar8 = (param_5 - 1U >> 2) + 1;

        pfVar6 = (float *)(param_2 + 8);

        pfVar10 = pfVar13;

        do {

          fVar1 = pfVar10[-2];

          iVar8 = iVar8 + -1;

          fVar2 = pfVar6[-2] * param_4;

          fVar3 = pfVar6[-1] * param_4;

          param_4 = *pfVar10;

          fVar4 = *pfVar6 * param_4 + fVar1 * pfVar6[-2] + fVar4;

          local_18 = pfVar6[1] * param_4 + fVar1 * pfVar6[-1] + local_18;

          local_14 = fVar1 * *pfVar6 + fVar2 + local_14;

          local_10 = (uint32_t /* width from decompiler */ *)(fVar1 * pfVar6[1] + fVar3 + (float)local_10);

          pfVar6 = pfVar6 + 4;

          pfVar10 = pfVar10 + 4;

        } while (iVar8 != 0);

      }

      pfVar11[-2] = fVar4;

      pfVar11[-1] = local_18;

      *pfVar11 = local_14;

      pfVar11[1] = (float)local_10;

      pfVar13 = pfVar13 + -4;

      pfVar11 = pfVar11 + 4;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

  }

  iVar5 = 0;

  if (0 < iVar12) {

    puVar7 = (uint32_t /* width from decompiler */ *)(param_6 + 4);

    do {

      *puVar7 = *(uint32_t /* width from decompiler */ *)(iVar14 + iVar5 * 4);

      iVar5 = iVar5 + 2;

      puVar7 = puVar7 + 2;

    } while (iVar5 < iVar12);

  }

  return;

}
