// =============================================================================
// FUN_006c3440
// -----------------------------------------------------------------------------
// Stable ID: aa_006c3440
// Address:   0x006c3440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c3440 @ 0x006c3440
// Stable ID: aa_006c3440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006c3440.
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



void FUN_006c3440(float *param_1,int *param_2,int *param_3)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  float fVar5;

  float fVar6;

  float fVar7;

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

  

  pfVar1 = (float *)*param_3;

  fVar5 = param_1[5];

  fVar6 = param_1[6];

  fVar7 = param_1[7];

  iVar2 = *param_2;

  iVar3 = param_2[1];

  *pfVar1 = param_1[4];

  pfVar1[1] = fVar5;

  pfVar1[2] = fVar6;

  pfVar1[3] = fVar7;

  fVar5 = *param_1 - *(float *)(iVar2 + 0x40);

  fVar7 = param_1[1] - *(float *)(iVar2 + 0x44);

  fVar8 = param_1[2] - *(float *)(iVar2 + 0x48);

  fVar10 = param_1[3] - *(float *)(iVar2 + 0x4c);

  fVar12 = *param_1 - *(float *)(iVar3 + 0x40);

  fVar13 = param_1[1] - *(float *)(iVar3 + 0x44);

  fVar14 = param_1[2] - *(float *)(iVar3 + 0x48);

  fVar15 = param_1[3] - *(float *)(iVar3 + 0x4c);

  fVar6 = fVar7 * param_1[6] - fVar8 * param_1[5];

  fVar8 = fVar8 * param_1[4] - fVar5 * param_1[6];

  fVar5 = fVar5 * param_1[5] - fVar7 * param_1[4];

  fVar7 = fVar10 * param_1[7] - fVar10 * param_1[7];

  if (*(char *)(iVar2 + 0xc) == '\0') {

    fVar7 = *(float *)(iVar2 + 0x7c) * fVar5;

    fVar16 = *(float *)(iVar2 + 0x68) * fVar8;

    fVar17 = *(float *)(iVar2 + 0x6c) * fVar8;

    fVar10 = *(float *)(iVar2 + 0x54) * fVar6;

    fVar9 = *(float *)(iVar2 + 0x58) * fVar6;

    fVar11 = *(float *)(iVar2 + 0x5c) * fVar6;

    fVar6 = *(float *)(iVar2 + 0x50) * fVar6 + *(float *)(iVar2 + 0x60) * fVar8 +

            *(float *)(iVar2 + 0x70) * fVar5;

    fVar8 = fVar10 + *(float *)(iVar2 + 100) * fVar8 + *(float *)(iVar2 + 0x74) * fVar5;

    fVar5 = fVar9 + fVar16 + *(float *)(iVar2 + 0x78) * fVar5;

    fVar7 = fVar11 + fVar17 + fVar7;

  }

  pfVar1[4] = fVar6;

  pfVar1[5] = fVar8;

  pfVar1[6] = fVar5;

  pfVar1[7] = fVar7;

  fVar5 = param_1[5] * fVar14 - param_1[6] * fVar13;

  fVar6 = param_1[6] * fVar12 - param_1[4] * fVar14;

  fVar7 = param_1[4] * fVar13 - param_1[5] * fVar12;

  fVar8 = param_1[7] * fVar15 - param_1[7] * fVar15;

  if (*(char *)(iVar3 + 0xc) == '\0') {

    fVar8 = *(float *)(iVar3 + 0x7c) * fVar7;

    fVar14 = *(float *)(iVar3 + 0x68) * fVar6;

    fVar15 = *(float *)(iVar3 + 0x6c) * fVar6;

    fVar10 = *(float *)(iVar3 + 0x54) * fVar5;

    fVar12 = *(float *)(iVar3 + 0x58) * fVar5;

    fVar13 = *(float *)(iVar3 + 0x5c) * fVar5;

    fVar5 = *(float *)(iVar3 + 0x50) * fVar5 + *(float *)(iVar3 + 0x60) * fVar6 +

            *(float *)(iVar3 + 0x70) * fVar7;

    fVar6 = fVar10 + *(float *)(iVar3 + 100) * fVar6 + *(float *)(iVar3 + 0x74) * fVar7;

    fVar7 = fVar12 + fVar14 + *(float *)(iVar3 + 0x78) * fVar7;

    fVar8 = fVar13 + fVar15 + fVar8;

  }

  pfVar1[8] = fVar5;

  pfVar1[9] = fVar6;

  pfVar1[10] = fVar7;

  pfVar1[0xb] = fVar8;

  fVar5 = *(float *)(iVar3 + 0x3c) + *(float *)(iVar2 + 0x3c) + _DAT_00a0d2ec +

          pfVar1[6] * pfVar1[6] * *(float *)(iVar2 + 0x38) +

          pfVar1[10] * pfVar1[10] * *(float *)(iVar3 + 0x38) +

          pfVar1[5] * pfVar1[5] * *(float *)(iVar2 + 0x34) +

          pfVar1[9] * pfVar1[9] * *(float *)(iVar3 + 0x34) +

          pfVar1[4] * pfVar1[4] * *(float *)(iVar2 + 0x30) +

          pfVar1[8] * pfVar1[8] * *(float *)(iVar3 + 0x30);

  pfVar1[0xb] = fVar5;

  pfVar1[7] = g_flOne / fVar5;

  fVar5 = *(float *)((int)param_1[9] + 4);

  puVar4 = (uint32_t /* width from decompiler */ *)param_3[1];

  fVar6 = (float)param_2[3];

  fVar7 = param_1[8];

  fVar8 = (float)param_2[2];

  *puVar4 = 0x30806;

  puVar4[1] = fVar7 * fVar8;

  *param_3 = (int)(pfVar1 + 0xc);

  param_3[1] = (int)(puVar4 + 2);

  pfVar1[3] = fVar5 * fVar6;

  return;

}
