// =============================================================================
// FUN_006c32b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c32b0
// Address:   0x006c32b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c32b0 @ 0x006c32b0
// Stable ID: aa_006c32b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_006c32b0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_006c32b0(uint32_t /* width from decompiler */ *param_1,int *param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  float *pfVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  float *pfVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float *local_1c;

  int local_18;

  

  pfVar7 = (float *)*param_1;

  local_18 = param_1[3];

  if (-1 < local_18 + -1) {

    pfVar3 = (float *)*param_3;

    puVar5 = (uint32_t /* width from decompiler */ *)param_3[1];

    local_1c = (float *)(param_1[1] + 4);

    do {

      iVar1 = *param_2;

      iVar2 = param_2[1];

      fVar8 = *pfVar7;

      fVar11 = pfVar7[1];

      fVar14 = pfVar7[2];

      fVar17 = pfVar7[3];

      if (*(char *)(iVar1 + 0xc) == '\0') {

        fVar17 = *(float *)(iVar1 + 0x7c) * fVar14;

        fVar18 = *(float *)(iVar1 + 0x68) * fVar11;

        fVar19 = *(float *)(iVar1 + 0x6c) * fVar11;

        fVar10 = *(float *)(iVar1 + 0x54) * fVar8;

        fVar13 = *(float *)(iVar1 + 0x58) * fVar8;

        fVar16 = *(float *)(iVar1 + 0x5c) * fVar8;

        fVar8 = *(float *)(iVar1 + 0x50) * fVar8 + *(float *)(iVar1 + 0x60) * fVar11 +

                *(float *)(iVar1 + 0x70) * fVar14;

        fVar11 = fVar10 + *(float *)(iVar1 + 100) * fVar11 + *(float *)(iVar1 + 0x74) * fVar14;

        fVar14 = fVar13 + fVar18 + *(float *)(iVar1 + 0x78) * fVar14;

        fVar17 = fVar16 + fVar19 + fVar17;

      }

      *pfVar3 = fVar8;

      pfVar3[1] = fVar11;

      pfVar3[2] = fVar14;

      pfVar3[3] = fVar17;

      if (*(char *)(iVar2 + 0xc) == '\0') {

        fVar8 = *(float *)(iVar2 + 0x74);

        fVar11 = *(float *)(iVar2 + 0x78);

        fVar14 = *(float *)(iVar2 + 0x7c);

        fVar17 = *(float *)(iVar2 + 100);

        fVar10 = *(float *)(iVar2 + 0x68);

        fVar13 = *(float *)(iVar2 + 0x6c);

        fVar9 = (float)((uint)*pfVar7 ^ _DAT_00a0d140);

        fVar12 = (float)((uint)pfVar7[1] ^ _UNK_00a0d144);

        fVar15 = (float)((uint)pfVar7[2] ^ _UNK_00a0d148);

        fVar16 = *(float *)(iVar2 + 0x54);

        fVar18 = *(float *)(iVar2 + 0x58);

        fVar19 = *(float *)(iVar2 + 0x5c);

        pfVar3[4] = *(float *)(iVar2 + 0x50) * fVar9 + *(float *)(iVar2 + 0x60) * fVar12 +

                    *(float *)(iVar2 + 0x70) * fVar15;

        pfVar3[5] = fVar16 * fVar9 + fVar17 * fVar12 + fVar8 * fVar15;

        pfVar3[6] = fVar18 * fVar9 + fVar10 * fVar12 + fVar11 * fVar15;

        pfVar3[7] = fVar19 * fVar9 + fVar13 * fVar12 + fVar14 * fVar15;

      }

      else {

        fVar8 = (float)((uint)pfVar7[1] ^ _UNK_00a0d144);

        fVar11 = (float)((uint)pfVar7[2] ^ _UNK_00a0d148);

        fVar14 = (float)((uint)pfVar7[3] ^ _UNK_00a0d14c);

        pfVar3[4] = (float)((uint)*pfVar7 ^ _DAT_00a0d140);

        pfVar3[5] = fVar8;

        pfVar3[6] = fVar11;

        pfVar3[7] = fVar14;

      }

      puVar6 = puVar5 + 2;

      pfVar7 = pfVar7 + 4;

      pfVar4 = pfVar3 + 8;

      pfVar3[3] = g_flOne / (pfVar3[2] * pfVar3[2] * *(float *)(iVar1 + 0x38) +

                             pfVar3[6] * pfVar3[6] * *(float *)(iVar2 + 0x38) +

                             pfVar3[1] * pfVar3[1] * *(float *)(iVar1 + 0x34) +

                             pfVar3[5] * pfVar3[5] * *(float *)(iVar2 + 0x34) +

                             *pfVar3 * *pfVar3 * *(float *)(iVar1 + 0x30) +

                             pfVar3[4] * pfVar3[4] * *(float *)(iVar2 + 0x30) + _DAT_00a0d2ec);

      fVar8 = (float)param_2[2];

      fVar11 = (float)param_1[2];

      *puVar5 = 0x40809;

      puVar5[1] = fVar8 * fVar11;

      local_18 = local_18 + -1;

      pfVar3[7] = *local_1c * (float)param_2[3];

      pfVar3 = pfVar4;

      puVar5 = puVar6;

      local_1c = local_1c + 2;

    } while (local_18 != 0);

    *param_3 = pfVar4;

    param_3[1] = puVar6;

    return;

  }

  *param_3 = (float *)*param_3;

  param_3[1] = (uint32_t /* width from decompiler */ *)param_3[1];

  return;

}
