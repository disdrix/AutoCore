// =============================================================================
// FUN_006c3160
// -----------------------------------------------------------------------------
// Stable ID: aa_006c3160
// Address:   0x006c3160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c3160 @ 0x006c3160
// Stable ID: aa_006c3160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006c3160.
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



void FUN_006c3160(float *param_1,int *param_2,int *param_3)



{

  int iVar1;

  float *pfVar2;

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

  

  fVar5 = param_1[8];

  fVar8 = param_1[9];

  fVar11 = param_1[10];

  fVar14 = param_1[0xb];

  iVar1 = *param_2;

  pfVar2 = (float *)*param_3;

  iVar3 = param_2[1];

  if (*(char *)(iVar1 + 0xc) == '\0') {

    fVar14 = *(float *)(iVar1 + 0x7c) * fVar11;

    fVar15 = *(float *)(iVar1 + 0x68) * fVar8;

    fVar16 = *(float *)(iVar1 + 0x6c) * fVar8;

    fVar7 = *(float *)(iVar1 + 0x54) * fVar5;

    fVar10 = *(float *)(iVar1 + 0x58) * fVar5;

    fVar13 = *(float *)(iVar1 + 0x5c) * fVar5;

    fVar5 = *(float *)(iVar1 + 0x50) * fVar5 + *(float *)(iVar1 + 0x60) * fVar8 +

            *(float *)(iVar1 + 0x70) * fVar11;

    fVar8 = fVar7 + *(float *)(iVar1 + 100) * fVar8 + *(float *)(iVar1 + 0x74) * fVar11;

    fVar11 = fVar10 + fVar15 + *(float *)(iVar1 + 0x78) * fVar11;

    fVar14 = fVar13 + fVar16 + fVar14;

  }

  *pfVar2 = fVar5;

  pfVar2[1] = fVar8;

  pfVar2[2] = fVar11;

  pfVar2[3] = fVar14;

  if (*(char *)(iVar3 + 0xc) == '\0') {

    fVar5 = *(float *)(iVar3 + 0x74);

    fVar8 = *(float *)(iVar3 + 0x78);

    fVar11 = *(float *)(iVar3 + 0x7c);

    fVar14 = *(float *)(iVar3 + 100);

    fVar7 = *(float *)(iVar3 + 0x68);

    fVar10 = *(float *)(iVar3 + 0x6c);

    fVar6 = (float)((uint)param_1[8] ^ _DAT_00a0d140);

    fVar9 = (float)((uint)param_1[9] ^ _UNK_00a0d144);

    fVar12 = (float)((uint)param_1[10] ^ _UNK_00a0d148);

    fVar13 = *(float *)(iVar3 + 0x54);

    fVar15 = *(float *)(iVar3 + 0x58);

    fVar16 = *(float *)(iVar3 + 0x5c);

    pfVar2[4] = *(float *)(iVar3 + 0x50) * fVar6 + *(float *)(iVar3 + 0x60) * fVar9 +

                *(float *)(iVar3 + 0x70) * fVar12;

    pfVar2[5] = fVar13 * fVar6 + fVar14 * fVar9 + fVar5 * fVar12;

    pfVar2[6] = fVar15 * fVar6 + fVar7 * fVar9 + fVar8 * fVar12;

    pfVar2[7] = fVar16 * fVar6 + fVar10 * fVar9 + fVar11 * fVar12;

  }

  else {

    fVar5 = (float)((uint)param_1[9] ^ _UNK_00a0d144);

    fVar8 = (float)((uint)param_1[10] ^ _UNK_00a0d148);

    fVar11 = (float)((uint)param_1[0xb] ^ _UNK_00a0d14c);

    pfVar2[4] = (float)((uint)param_1[8] ^ _DAT_00a0d140);

    pfVar2[5] = fVar5;

    pfVar2[6] = fVar8;

    pfVar2[7] = fVar11;

  }

  pfVar2[3] = g_flOne / (pfVar2[2] * pfVar2[2] * *(float *)(iVar1 + 0x38) +

                         pfVar2[6] * pfVar2[6] * *(float *)(iVar3 + 0x38) +

                         pfVar2[1] * pfVar2[1] * *(float *)(iVar1 + 0x34) +

                         pfVar2[5] * pfVar2[5] * *(float *)(iVar3 + 0x34) +

                         *pfVar2 * *pfVar2 * *(float *)(iVar1 + 0x30) +

                         pfVar2[4] * pfVar2[4] * *(float *)(iVar3 + 0x30) + _DAT_00a0d2ec);

  fVar5 = param_1[6];

  fVar8 = param_1[2];

  fVar11 = param_1[5];

  fVar14 = param_1[1];

  fVar7 = param_1[4];

  fVar10 = *param_1;

  puVar4 = (uint32_t /* width from decompiler */ *)param_3[1];

  fVar13 = (float)param_2[3];

  *puVar4 = 0x4040c;

  *param_3 = (int)(pfVar2 + 8);

  param_3[1] = (int)(puVar4 + 1);

  pfVar2[7] = -((fVar7 * fVar10 + fVar11 * fVar14 + fVar5 * fVar8) * fVar13);

  return;

}
