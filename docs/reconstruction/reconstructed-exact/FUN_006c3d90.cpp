// =============================================================================
// FUN_006c3d90
// -----------------------------------------------------------------------------
// Stable ID: aa_006c3d90
// Address:   0x006c3d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c3d90 @ 0x006c3d90
// Stable ID: aa_006c3d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_006c3d90.
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



void FUN_006c3d90(float *param_1,float *param_2,int *param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  float *pfVar4;

  float *pfVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

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

  float fVar20;

  int local_1c;

  

  iVar1 = *param_3;

  iVar2 = param_3[1];

  local_1c = 3;

  pfVar3 = (float *)*param_4;

  pfVar5 = (float *)&DAT_00af4f90;

  puVar6 = (uint32_t /* width from decompiler */ *)param_4[1];

  do {

    fVar8 = pfVar5[1];

    fVar9 = pfVar5[2];

    fVar10 = pfVar5[3];

    *pfVar3 = *pfVar5;

    pfVar3[1] = fVar8;

    pfVar3[2] = fVar9;

    pfVar3[3] = fVar10;

    fVar8 = *param_1 - *(float *)(iVar1 + 0x40);

    fVar10 = param_1[1] - *(float *)(iVar1 + 0x44);

    fVar11 = param_1[2] - *(float *)(iVar1 + 0x48);

    fVar13 = param_1[3] - *(float *)(iVar1 + 0x4c);

    fVar15 = *param_2 - *(float *)(iVar2 + 0x40);

    fVar16 = param_2[1] - *(float *)(iVar2 + 0x44);

    fVar17 = param_2[2] - *(float *)(iVar2 + 0x48);

    fVar18 = param_2[3] - *(float *)(iVar2 + 0x4c);

    fVar9 = fVar10 * pfVar5[2] - fVar11 * pfVar5[1];

    fVar11 = fVar11 * *pfVar5 - fVar8 * pfVar5[2];

    fVar8 = fVar8 * pfVar5[1] - fVar10 * *pfVar5;

    fVar10 = fVar13 * pfVar5[3] - fVar13 * pfVar5[3];

    if (*(char *)(iVar1 + 0xc) == '\0') {

      fVar10 = *(float *)(iVar1 + 0x7c) * fVar8;

      fVar19 = *(float *)(iVar1 + 0x68) * fVar11;

      fVar20 = *(float *)(iVar1 + 0x6c) * fVar11;

      fVar13 = *(float *)(iVar1 + 0x54) * fVar9;

      fVar12 = *(float *)(iVar1 + 0x58) * fVar9;

      fVar14 = *(float *)(iVar1 + 0x5c) * fVar9;

      fVar9 = *(float *)(iVar1 + 0x50) * fVar9 + *(float *)(iVar1 + 0x60) * fVar11 +

              *(float *)(iVar1 + 0x70) * fVar8;

      fVar11 = fVar13 + *(float *)(iVar1 + 100) * fVar11 + *(float *)(iVar1 + 0x74) * fVar8;

      fVar8 = fVar12 + fVar19 + *(float *)(iVar1 + 0x78) * fVar8;

      fVar10 = fVar14 + fVar20 + fVar10;

    }

    pfVar3[4] = fVar9;

    pfVar3[5] = fVar11;

    pfVar3[6] = fVar8;

    pfVar3[7] = fVar10;

    fVar8 = pfVar5[1] * fVar17 - pfVar5[2] * fVar16;

    fVar9 = pfVar5[2] * fVar15 - *pfVar5 * fVar17;

    fVar10 = *pfVar5 * fVar16 - pfVar5[1] * fVar15;

    fVar11 = pfVar5[3] * fVar18 - pfVar5[3] * fVar18;

    if (*(char *)(iVar2 + 0xc) == '\0') {

      fVar11 = *(float *)(iVar2 + 0x7c) * fVar10;

      fVar17 = *(float *)(iVar2 + 0x68) * fVar9;

      fVar18 = *(float *)(iVar2 + 0x6c) * fVar9;

      fVar13 = *(float *)(iVar2 + 0x54) * fVar8;

      fVar15 = *(float *)(iVar2 + 0x58) * fVar8;

      fVar16 = *(float *)(iVar2 + 0x5c) * fVar8;

      fVar8 = *(float *)(iVar2 + 0x50) * fVar8 + *(float *)(iVar2 + 0x60) * fVar9 +

              *(float *)(iVar2 + 0x70) * fVar10;

      fVar9 = fVar13 + *(float *)(iVar2 + 100) * fVar9 + *(float *)(iVar2 + 0x74) * fVar10;

      fVar10 = fVar15 + fVar17 + *(float *)(iVar2 + 0x78) * fVar10;

      fVar11 = fVar16 + fVar18 + fVar11;

    }

    pfVar3[8] = fVar8;

    pfVar3[9] = fVar9;

    pfVar3[10] = fVar10;

    pfVar3[0xb] = fVar11;

    fVar8 = *(float *)(iVar2 + 0x3c) + *(float *)(iVar1 + 0x3c) + _DAT_00a0d2ec +

            pfVar3[6] * pfVar3[6] * *(float *)(iVar1 + 0x38) +

            pfVar3[10] * pfVar3[10] * *(float *)(iVar2 + 0x38) +

            pfVar3[5] * pfVar3[5] * *(float *)(iVar1 + 0x34) +

            pfVar3[9] * pfVar3[9] * *(float *)(iVar2 + 0x34) +

            pfVar3[4] * pfVar3[4] * *(float *)(iVar1 + 0x30) +

            pfVar3[8] * pfVar3[8] * *(float *)(iVar2 + 0x30);

    puVar7 = puVar6 + 1;

    pfVar3[0xb] = fVar8;

    pfVar4 = pfVar3 + 0xc;

    pfVar3[7] = g_flOne / fVar8;

    local_1c = local_1c + -1;

    pfVar3[3] = ((param_2[2] - param_1[2]) * pfVar5[2] +

                (param_2[1] - param_1[1]) * pfVar5[1] + (*param_2 - *param_1) * *pfVar5) *

                (float)param_3[3];

    *puVar6 = 0x3040d;

    pfVar3 = pfVar4;

    pfVar5 = pfVar5 + 4;

    puVar6 = puVar7;

  } while (local_1c != 0);

  param_4[1] = puVar7;

  *param_4 = pfVar4;

  return;

}
