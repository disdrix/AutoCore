// =============================================================================
// FUN_006c35e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c35e0
// Address:   0x006c35e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c35e0 @ 0x006c35e0
// Stable ID: aa_006c35e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006c35e0.
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



void FUN_006c35e0(float *param_1,int *param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  float *pfVar4;

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

  

  iVar1 = *param_2;

  iVar2 = param_2[1];

  puVar3 = (uint32_t /* width from decompiler */ *)param_3[1];

  pfVar4 = (float *)*param_3;

  fVar5 = param_1[9];

  fVar6 = param_1[10];

  fVar7 = param_1[0xb];

  *pfVar4 = param_1[8];

  pfVar4[1] = fVar5;

  pfVar4[2] = fVar6;

  pfVar4[3] = fVar7;

  fVar5 = *param_1 - *(float *)(iVar1 + 0x40);

  fVar7 = param_1[1] - *(float *)(iVar1 + 0x44);

  fVar8 = param_1[2] - *(float *)(iVar1 + 0x48);

  fVar10 = param_1[3] - *(float *)(iVar1 + 0x4c);

  fVar12 = param_1[4] - *(float *)(iVar2 + 0x40);

  fVar13 = param_1[5] - *(float *)(iVar2 + 0x44);

  fVar14 = param_1[6] - *(float *)(iVar2 + 0x48);

  fVar15 = param_1[7] - *(float *)(iVar2 + 0x4c);

  fVar6 = fVar7 * param_1[10] - fVar8 * param_1[9];

  fVar8 = fVar8 * param_1[8] - fVar5 * param_1[10];

  fVar5 = fVar5 * param_1[9] - fVar7 * param_1[8];

  fVar7 = fVar10 * param_1[0xb] - fVar10 * param_1[0xb];

  if (*(char *)(iVar1 + 0xc) == '\0') {

    fVar7 = *(float *)(iVar1 + 0x7c) * fVar5;

    fVar16 = *(float *)(iVar1 + 0x68) * fVar8;

    fVar17 = *(float *)(iVar1 + 0x6c) * fVar8;

    fVar10 = *(float *)(iVar1 + 0x54) * fVar6;

    fVar9 = *(float *)(iVar1 + 0x58) * fVar6;

    fVar11 = *(float *)(iVar1 + 0x5c) * fVar6;

    fVar6 = *(float *)(iVar1 + 0x50) * fVar6 + *(float *)(iVar1 + 0x60) * fVar8 +

            *(float *)(iVar1 + 0x70) * fVar5;

    fVar8 = fVar10 + *(float *)(iVar1 + 100) * fVar8 + *(float *)(iVar1 + 0x74) * fVar5;

    fVar5 = fVar9 + fVar16 + *(float *)(iVar1 + 0x78) * fVar5;

    fVar7 = fVar11 + fVar17 + fVar7;

  }

  pfVar4[4] = fVar6;

  pfVar4[5] = fVar8;

  pfVar4[6] = fVar5;

  pfVar4[7] = fVar7;

  fVar5 = param_1[9] * fVar14 - param_1[10] * fVar13;

  fVar6 = param_1[10] * fVar12 - param_1[8] * fVar14;

  fVar7 = param_1[8] * fVar13 - param_1[9] * fVar12;

  fVar8 = param_1[0xb] * fVar15 - param_1[0xb] * fVar15;

  if (*(char *)(iVar2 + 0xc) == '\0') {

    fVar8 = *(float *)(iVar2 + 0x7c) * fVar7;

    fVar14 = *(float *)(iVar2 + 0x68) * fVar6;

    fVar15 = *(float *)(iVar2 + 0x6c) * fVar6;

    fVar10 = *(float *)(iVar2 + 0x54) * fVar5;

    fVar12 = *(float *)(iVar2 + 0x58) * fVar5;

    fVar13 = *(float *)(iVar2 + 0x5c) * fVar5;

    fVar5 = *(float *)(iVar2 + 0x50) * fVar5 + *(float *)(iVar2 + 0x60) * fVar6 +

            *(float *)(iVar2 + 0x70) * fVar7;

    fVar6 = fVar10 + *(float *)(iVar2 + 100) * fVar6 + *(float *)(iVar2 + 0x74) * fVar7;

    fVar7 = fVar12 + fVar14 + *(float *)(iVar2 + 0x78) * fVar7;

    fVar8 = fVar13 + fVar15 + fVar8;

  }

  pfVar4[8] = fVar5;

  pfVar4[9] = fVar6;

  pfVar4[10] = fVar7;

  pfVar4[0xb] = fVar8;

  fVar5 = *(float *)(iVar2 + 0x3c) + *(float *)(iVar1 + 0x3c) + _DAT_00a0d2ec +

          pfVar4[6] * pfVar4[6] * *(float *)(iVar1 + 0x38) +

          pfVar4[10] * pfVar4[10] * *(float *)(iVar2 + 0x38) +

          pfVar4[5] * pfVar4[5] * *(float *)(iVar1 + 0x34) +

          pfVar4[9] * pfVar4[9] * *(float *)(iVar2 + 0x34) +

          pfVar4[4] * pfVar4[4] * *(float *)(iVar1 + 0x30) +

          pfVar4[8] * pfVar4[8] * *(float *)(iVar2 + 0x30);

  pfVar4[0xb] = fVar5;

  pfVar4[7] = g_flOne / fVar5;

  pfVar4[3] = ((param_1[6] - param_1[2]) * param_1[10] +

              (param_1[5] - param_1[1]) * param_1[9] + (param_1[4] - *param_1) * param_1[8]) *

              (float)param_2[3];

  *puVar3 = 0x3040d;

  *param_3 = (int)(pfVar4 + 0xc);

  param_3[1] = (int)(puVar3 + 1);

  return;

}
