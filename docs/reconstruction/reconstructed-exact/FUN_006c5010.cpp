// =============================================================================
// FUN_006c5010
// -----------------------------------------------------------------------------
// Stable ID: aa_006c5010
// Address:   0x006c5010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c5010 @ 0x006c5010
// Stable ID: aa_006c5010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~566 non-empty decompiler lines.
//  - Control keywords: if×25, while×3, return×3, do×2.
//  - Notable callees: ABS×6, rsqrtss×2, FUN_006c5010, SQRT.
//  - Return sites: 3.

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



void FUN_006c5010(float *param_1,int param_2,int param_3,uint *param_4,int *param_5,int *param_6)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  bool bVar6;

  uint8_t auVar7 [16];

  float *pfVar8;

  float *pfVar9;

  float fVar10;

  float *pfVar11;

  float *pfVar12;

  float *pfVar13;

  uint uVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar26;

  float fVar27;

  float fVar28;

  uint8_t auVar24 [16];

  uint8_t auVar25 [16];

  float fVar29;

  float fVar30;

  float fVar31;

  float fVar32;

  uint8_t auVar33 [16];

  uint8_t auVar34 [16];

  uint8_t auVar35 [16];

  float fVar36;

  float fVar37;

  float fVar38;

  float fVar39;

  float fVar40;

  float fVar41;

  float *local_54;

  float *local_50;

  float local_48;

  float local_44;

  uint local_40;

  uint local_38;

  float local_20 [7];

  

  fVar1 = g_flZero;

  iVar2 = *param_6;

  fVar10 = g_flOne / (float)param_2;

  iVar3 = *param_5;

  iVar4 = param_5[1];

  puVar5 = (uint32_t /* width from decompiler */ *)param_6[1];

  puVar5[2] = param_3;

  *puVar5 = 0x11801;

  puVar5[3] = iVar3;

  puVar5[4] = iVar4;

  puVar5[5] = 0x1c;

  puVar5[1] = iVar2;

  pfVar12 = (float *)*param_6;

  local_54 = (float *)(puVar5 + 6);

  fVar29 = 0.0;

  fVar30 = 0.0;

  fVar38 = 0.0;

  fVar39 = 0.0;

  fVar31 = 0.0;

  fVar32 = 0.0;

  fVar36 = fVar29;

  fVar37 = fVar30;

  fVar18 = g_flZero;

  if (-1 < param_2 + -1) {

    local_50 = (float *)(param_3 + 0x14);

    pfVar13 = param_1 + 4;

    pfVar11 = pfVar12 + -1;

    local_38 = param_2;

    do {

      fVar15 = pfVar13[1];

      fVar16 = pfVar13[2];

      fVar17 = pfVar13[3];

      *pfVar12 = *pfVar13;

      pfVar12[1] = fVar15;

      pfVar12[2] = fVar16;

      pfVar12[3] = fVar17;

      fVar15 = pfVar13[-4] - *(float *)(iVar3 + 0x40);

      fVar17 = pfVar13[-3] - *(float *)(iVar3 + 0x44);

      fVar19 = pfVar13[-2] - *(float *)(iVar3 + 0x48);

      fVar21 = pfVar13[-1] - *(float *)(iVar3 + 0x4c);

      fVar23 = pfVar13[-4] - *(float *)(iVar4 + 0x40);

      fVar26 = pfVar13[-3] - *(float *)(iVar4 + 0x44);

      fVar27 = pfVar13[-2] - *(float *)(iVar4 + 0x48);

      fVar28 = pfVar13[-1] - *(float *)(iVar4 + 0x4c);

      fVar16 = fVar17 * pfVar13[2] - fVar19 * pfVar13[1];

      fVar19 = fVar19 * *pfVar13 - fVar15 * pfVar13[2];

      fVar15 = fVar15 * pfVar13[1] - fVar17 * *pfVar13;

      fVar17 = fVar21 * pfVar13[3] - fVar21 * pfVar13[3];

      if (*(char *)(iVar3 + 0xc) == '\0') {

        fVar17 = *(float *)(iVar3 + 0x7c) * fVar15;

        fVar40 = *(float *)(iVar3 + 0x68) * fVar19;

        fVar41 = *(float *)(iVar3 + 0x6c) * fVar19;

        fVar21 = *(float *)(iVar3 + 0x54) * fVar16;

        fVar20 = *(float *)(iVar3 + 0x58) * fVar16;

        fVar22 = *(float *)(iVar3 + 0x5c) * fVar16;

        fVar16 = *(float *)(iVar3 + 0x50) * fVar16 + *(float *)(iVar3 + 0x60) * fVar19 +

                 *(float *)(iVar3 + 0x70) * fVar15;

        fVar19 = fVar21 + *(float *)(iVar3 + 100) * fVar19 + *(float *)(iVar3 + 0x74) * fVar15;

        fVar15 = fVar20 + fVar40 + *(float *)(iVar3 + 0x78) * fVar15;

        fVar17 = fVar22 + fVar41 + fVar17;

      }

      pfVar11[5] = fVar16;

      pfVar11[6] = fVar19;

      pfVar11[7] = fVar15;

      pfVar11[8] = fVar17;

      fVar15 = pfVar13[1] * fVar27 - pfVar13[2] * fVar26;

      fVar16 = pfVar13[2] * fVar23 - *pfVar13 * fVar27;

      fVar17 = *pfVar13 * fVar26 - pfVar13[1] * fVar23;

      fVar19 = pfVar13[3] * fVar28 - pfVar13[3] * fVar28;

      if (*(char *)(iVar4 + 0xc) == '\0') {

        fVar19 = *(float *)(iVar4 + 0x7c) * fVar17;

        fVar27 = *(float *)(iVar4 + 0x68) * fVar16;

        fVar28 = *(float *)(iVar4 + 0x6c) * fVar16;

        fVar21 = *(float *)(iVar4 + 0x54) * fVar15;

        fVar23 = *(float *)(iVar4 + 0x58) * fVar15;

        fVar26 = *(float *)(iVar4 + 0x5c) * fVar15;

        fVar15 = *(float *)(iVar4 + 0x50) * fVar15 + *(float *)(iVar4 + 0x60) * fVar16 +

                 *(float *)(iVar4 + 0x70) * fVar17;

        fVar16 = fVar21 + *(float *)(iVar4 + 100) * fVar16 + *(float *)(iVar4 + 0x74) * fVar17;

        fVar17 = fVar23 + fVar27 + *(float *)(iVar4 + 0x78) * fVar17;

        fVar19 = fVar26 + fVar28 + fVar19;

      }

      pfVar11[9] = fVar15;

      pfVar11[10] = fVar16;

      pfVar11[0xb] = fVar17;

      pfVar11[0xc] = fVar19;

      fVar15 = *(float *)(iVar3 + 0x3c) + *(float *)(iVar4 + 0x3c) + _DAT_00a0d308 +

               pfVar11[7] * pfVar11[7] * *(float *)(iVar3 + 0x38) +

               pfVar11[0xb] * pfVar11[0xb] * *(float *)(iVar4 + 0x38) +

               pfVar11[6] * pfVar11[6] * *(float *)(iVar3 + 0x34) +

               pfVar11[10] * pfVar11[10] * *(float *)(iVar4 + 0x34) +

               pfVar11[5] * pfVar11[5] * *(float *)(iVar3 + 0x30) +

               pfVar11[9] * pfVar11[9] * *(float *)(iVar4 + 0x30);

      pfVar11[0xc] = fVar15;

      pfVar11[8] = g_flOne / fVar15;

      fVar18 = fVar18 + local_50[-3];

      fVar1 = fVar1 + local_50[-5];

      fVar15 = *local_50;

      fVar16 = -local_50[-4] - (pfVar13[-1] - fVar15);

      local_48 = (float)param_5[4];

      if (fVar15 * _DAT_00a0d310 < local_48) {

        local_48 = fVar15 * _DAT_00a0d310;

      }

      local_44 = local_48 + fVar15;

      fVar15 = (pfVar13[-1] - fVar15) - local_48;

      if (local_48 + local_48 + g_flMsToSeconds_Inferred < fVar16) {

        local_44 = local_44 - fVar16;

        fVar15 = fVar15 + fVar16;

      }

      if (ABS(fVar15) < _DAT_00a13fe4) {

        fVar15 = g_flZero;

      }

      fVar16 = g_flZero;

      if (local_44 < g_flZero) {

        fVar16 = local_44;

      }

      *local_50 = fVar16;

      fVar36 = fVar36 + pfVar13[-4];

      fVar37 = fVar37 + pfVar13[-3];

      fVar38 = fVar38 + pfVar13[-2];

      fVar39 = fVar39 + pfVar13[-1];

      fVar29 = fVar29 + *pfVar13;

      fVar30 = fVar30 + pfVar13[1];

      fVar31 = fVar31 + pfVar13[2];

      fVar32 = fVar32 + pfVar13[3];

      pfVar11[4] = -(fVar15 * (float)param_5[3]);

      if (*(short *)(local_50 + 1) == 0) {

        *local_54 = 2.76944e-40;

      }

      else {

        fVar15 = *(float *)(iVar3 + 0x3c);

        fVar16 = *(float *)(iVar4 + 0x3c);

        fVar16 = (pfVar11[7] * pfVar11[-5] * *(float *)(iVar3 + 0x38) +

                  pfVar11[0xb] * pfVar11[-1] * *(float *)(iVar4 + 0x38) +

                  fVar15 * pfVar12[2] * pfVar11[-9] + fVar16 * pfVar12[2] * pfVar11[-9] +

                 pfVar11[6] * pfVar11[-6] * *(float *)(iVar3 + 0x34) +

                 pfVar11[10] * pfVar11[-2] * *(float *)(iVar4 + 0x34) +

                 fVar15 * pfVar12[1] * pfVar11[-10] + fVar16 * pfVar12[1] * pfVar11[-10] +

                 pfVar11[5] * pfVar11[-7] * *(float *)(iVar3 + 0x30) +

                 pfVar11[9] * pfVar11[-3] * *(float *)(iVar4 + 0x30) +

                 fVar15 * *pfVar12 * pfVar11[-0xb] + fVar16 * *pfVar12 * pfVar11[-0xb]) *

                 (float)param_5[6];

        local_54[-1] = 4.62052e-40;

        fVar15 = *pfVar11;

        fVar17 = g_flOne / (fVar15 * pfVar11[0xc] - fVar16 * fVar16);

        *pfVar11 = fVar17 * pfVar11[0xc];

        pfVar11[0xc] = fVar17 * fVar15;

        *local_54 = -(fVar17 * fVar16);

      }

      local_54 = local_54 + 1;

      local_50 = local_50 + 7;

      pfVar13 = pfVar13 + 8;

      pfVar12 = pfVar12 + 0xc;

      pfVar11 = pfVar11 + 0xc;

      local_38 = local_38 + -1;

    } while (local_38 != 0);

  }

  fVar1 = fVar18 * fVar10 * fVar1;

  if (g_flZero < fVar1) {

    fVar18 = fVar30 * fVar30;

    fVar15 = fVar31 * fVar31;

    fVar16 = fVar15 + fVar18 + fVar29 * fVar29;

    if (fVar10 * fVar10 * fVar16 <= DAT_00aaa660) {

      if (fVar16 <= g_flMultiKillCountBlend) {

        local_20[0] = param_1[4];

        local_20[1] = param_1[5];

        local_20[2] = param_1[6];

        fVar32 = param_1[7];

        if (local_20[2] * local_20[2] + local_20[1] * local_20[1] + local_20[0] * local_20[0] <

            DAT_00a0f734) {

          local_20[0] = 0.0;

          local_20[2] = 0.0;

          local_20[1] = 1.0;

          fVar32 = 0.0;

          fVar1 = g_flZero;

        }

      }

      else {

        auVar24._4_4_ = fVar18;

        auVar24._0_4_ = fVar18;

        auVar24._8_4_ = fVar18;

        auVar24._12_4_ = fVar18;

        auVar25._4_12_ = auVar24._4_12_;

        auVar25._0_4_ = fVar18 + fVar29 * fVar29;

        auVar35._4_4_ = fVar15;

        auVar35._0_4_ = fVar15 + auVar25._0_4_;

        auVar35._8_4_ = fVar15;

        auVar35._12_4_ = fVar15;

        auVar35 = rsqrtss(auVar25,auVar35);

        fVar18 = auVar35._0_4_;

        fVar18 = fVar18 * 0.5 * (3.0 - (fVar15 + auVar25._0_4_) * fVar18 * fVar18);

        fVar32 = fVar18 * fVar32;

        local_20[0] = fVar18 * fVar29;

        local_20[1] = fVar18 * fVar30;

        local_20[2] = fVar18 * fVar31;

      }

    }

    else {

      fVar32 = param_1[7];

      local_20[0] = param_1[4];

      local_20[1] = param_1[5];

      local_20[2] = param_1[6];

    }

    while( true ) {

      fVar18 = (float)param_4[9] * local_20[2] - (float)param_4[10] * local_20[1];

      fVar29 = (float)param_4[10] * local_20[0] - (float)param_4[8] * local_20[2];

      fVar30 = (float)param_4[8] * local_20[1] - (float)param_4[9] * local_20[0];

      param_4[0xc] = (uint)fVar18;

      param_4[0xd] = (uint)fVar29;

      param_4[0xe] = (uint)fVar30;

      param_4[0xf] = (uint)((float)param_4[0xb] * fVar32 - (float)param_4[0xb] * fVar32);

      if (g_flMsToSeconds_Inferred < fVar30 * fVar30 + fVar29 * fVar29 + fVar18 * fVar18) break;

      local_40 = 2;

      bVar6 = ABS(local_20[1]) < ABS(local_20[0]);

      fVar1 = ABS(local_20[0]);

      if (bVar6) {

        fVar1 = ABS(local_20[1]);

      }

      local_38 = (uint)!bVar6;

      uVar14 = (uint)bVar6;

      if (ABS(local_20[2]) < fVar1) {

        uVar14 = 2;

        local_40 = (uint)bVar6;

      }

      param_4[uVar14 + 8] = 0;

      fVar1 = local_20[local_38];

      param_4[local_38 + 8] = (uint)local_20[local_40];

      param_4[local_40 + 8] = (uint)-fVar1;

      fVar1 = g_flZero;

    }

    fVar18 = (float)param_4[0xc];

    fVar29 = (float)param_4[0xd];

    fVar30 = (float)param_4[0xe];

    fVar31 = fVar29 * fVar29;

    fVar15 = fVar30 * fVar30;

    auVar33._4_4_ = fVar31;

    auVar33._0_4_ = fVar31;

    auVar33._8_4_ = fVar31;

    auVar33._12_4_ = fVar31;

    auVar34._4_12_ = auVar33._4_12_;

    auVar34._0_4_ = fVar31 + fVar18 * fVar18;

    auVar7._4_4_ = fVar15;

    auVar7._0_4_ = fVar15 + auVar34._0_4_;

    auVar7._8_4_ = fVar15;

    auVar7._12_4_ = fVar15;

    auVar35 = rsqrtss(auVar34,auVar7);

    fVar31 = auVar35._0_4_;

    fVar31 = fVar31 * 0.5 * (3.0 - (fVar15 + auVar34._0_4_) * fVar31 * fVar31);

    param_4[0xc] = (uint)(fVar31 * fVar18);

    param_4[0xd] = (uint)(fVar31 * fVar29);

    param_4[0xe] = (uint)(fVar31 * fVar30);

    param_4[0xf] = (uint)(fVar31 * (float)param_4[0xf]);

    param_4[8] = (uint)(local_20[1] * (float)param_4[0xe] - local_20[2] * (float)param_4[0xd]);

    param_4[9] = (uint)(local_20[2] * (float)param_4[0xc] - local_20[0] * (float)param_4[0xe]);

    param_4[10] = (uint)(local_20[0] * (float)param_4[0xd] - local_20[1] * (float)param_4[0xc]);

    param_4[0xb] = (uint)(fVar32 * (float)param_4[0xf] - fVar32 * (float)param_4[0xf]);

    fVar18 = (float)param_4[9];

    fVar29 = (float)param_4[10];

    fVar30 = (float)param_4[0xb];

    *pfVar12 = (float)param_4[8];

    pfVar12[1] = fVar18;

    pfVar12[2] = fVar29;

    pfVar12[3] = fVar30;

    fVar36 = fVar10 * fVar36;

    fVar37 = fVar10 * fVar37;

    fVar38 = fVar10 * fVar38;

    fVar39 = fVar10 * fVar39;

    fVar18 = fVar36 - *(float *)(iVar3 + 0x40);

    fVar30 = fVar37 - *(float *)(iVar3 + 0x44);

    fVar31 = fVar38 - *(float *)(iVar3 + 0x48);

    fVar15 = fVar39 - *(float *)(iVar3 + 0x4c);

    fVar16 = fVar36 - *(float *)(iVar4 + 0x40);

    fVar17 = fVar37 - *(float *)(iVar4 + 0x44);

    fVar19 = fVar38 - *(float *)(iVar4 + 0x48);

    fVar21 = fVar39 - *(float *)(iVar4 + 0x4c);

    fVar29 = fVar30 * (float)param_4[10] - fVar31 * (float)param_4[9];

    fVar31 = fVar31 * (float)param_4[8] - fVar18 * (float)param_4[10];

    fVar18 = fVar18 * (float)param_4[9] - fVar30 * (float)param_4[8];

    fVar30 = fVar15 * (float)param_4[0xb] - fVar15 * (float)param_4[0xb];

    if (*(char *)(iVar3 + 0xc) == '\0') {

      fVar30 = *(float *)(iVar3 + 0x7c) * fVar18;

      fVar27 = *(float *)(iVar3 + 0x68) * fVar31;

      fVar28 = *(float *)(iVar3 + 0x6c) * fVar31;

      fVar15 = *(float *)(iVar3 + 0x54) * fVar29;

      fVar23 = *(float *)(iVar3 + 0x58) * fVar29;

      fVar26 = *(float *)(iVar3 + 0x5c) * fVar29;

      fVar29 = *(float *)(iVar3 + 0x50) * fVar29 + *(float *)(iVar3 + 0x60) * fVar31 +

               *(float *)(iVar3 + 0x70) * fVar18;

      fVar31 = fVar15 + *(float *)(iVar3 + 100) * fVar31 + *(float *)(iVar3 + 0x74) * fVar18;

      fVar18 = fVar23 + fVar27 + *(float *)(iVar3 + 0x78) * fVar18;

      fVar30 = fVar26 + fVar28 + fVar30;

    }

    pfVar12[4] = fVar29;

    pfVar12[5] = fVar31;

    pfVar12[6] = fVar18;

    pfVar12[7] = fVar30;

    fVar18 = (float)param_4[9] * fVar19 - (float)param_4[10] * fVar17;

    fVar29 = (float)param_4[10] * fVar16 - (float)param_4[8] * fVar19;

    fVar30 = (float)param_4[8] * fVar17 - (float)param_4[9] * fVar16;

    fVar31 = (float)param_4[0xb] * fVar21 - (float)param_4[0xb] * fVar21;

    if (*(char *)(iVar4 + 0xc) == '\0') {

      fVar31 = *(float *)(iVar4 + 0x7c) * fVar30;

      fVar19 = *(float *)(iVar4 + 0x68) * fVar29;

      fVar21 = *(float *)(iVar4 + 0x6c) * fVar29;

      fVar15 = *(float *)(iVar4 + 0x54) * fVar18;

      fVar16 = *(float *)(iVar4 + 0x58) * fVar18;

      fVar17 = *(float *)(iVar4 + 0x5c) * fVar18;

      fVar18 = *(float *)(iVar4 + 0x50) * fVar18 + *(float *)(iVar4 + 0x60) * fVar29 +

               *(float *)(iVar4 + 0x70) * fVar30;

      fVar29 = fVar15 + *(float *)(iVar4 + 100) * fVar29 + *(float *)(iVar4 + 0x74) * fVar30;

      fVar30 = fVar16 + fVar19 + *(float *)(iVar4 + 0x78) * fVar30;

      fVar31 = fVar17 + fVar21 + fVar31;

    }

    pfVar12[8] = fVar18;

    pfVar12[9] = fVar29;

    pfVar12[10] = fVar30;

    pfVar12[0xb] = fVar31;

    fVar18 = *(float *)(iVar3 + 0x3c) + *(float *)(iVar4 + 0x3c) + _DAT_00a0d308 +

             pfVar12[6] * pfVar12[6] * *(float *)(iVar3 + 0x38) +

             pfVar12[10] * pfVar12[10] * *(float *)(iVar4 + 0x38) +

             pfVar12[5] * pfVar12[5] * *(float *)(iVar3 + 0x34) +

             pfVar12[9] * pfVar12[9] * *(float *)(iVar4 + 0x34) +

             pfVar12[4] * pfVar12[4] * *(float *)(iVar3 + 0x30) +

             pfVar12[8] * pfVar12[8] * *(float *)(iVar4 + 0x30);

    pfVar12[0xb] = fVar18;

    pfVar12[7] = g_flOne / fVar18;

    pfVar12[3] = (float)param_4[2] * (float)param_5[3];

    fVar18 = (float)param_4[0xd];

    fVar29 = (float)param_4[0xe];

    fVar30 = (float)param_4[0xf];

    pfVar12[0xc] = (float)param_4[0xc];

    pfVar12[0xd] = fVar18;

    pfVar12[0xe] = fVar29;

    pfVar12[0xf] = fVar30;

    fVar18 = fVar36 - *(float *)(iVar3 + 0x40);

    fVar30 = fVar37 - *(float *)(iVar3 + 0x44);

    fVar31 = fVar38 - *(float *)(iVar3 + 0x48);

    fVar15 = fVar39 - *(float *)(iVar3 + 0x4c);

    fVar16 = fVar36 - *(float *)(iVar4 + 0x40);

    fVar17 = fVar37 - *(float *)(iVar4 + 0x44);

    fVar19 = fVar38 - *(float *)(iVar4 + 0x48);

    fVar39 = fVar39 - *(float *)(iVar4 + 0x4c);

    fVar29 = fVar30 * (float)param_4[0xe] - fVar31 * (float)param_4[0xd];

    fVar31 = fVar31 * (float)param_4[0xc] - fVar18 * (float)param_4[0xe];

    fVar18 = fVar18 * (float)param_4[0xd] - fVar30 * (float)param_4[0xc];

    fVar30 = fVar15 * (float)param_4[0xf] - fVar15 * (float)param_4[0xf];

    if (*(char *)(iVar3 + 0xc) == '\0') {

      fVar30 = *(float *)(iVar3 + 0x7c) * fVar18;

      fVar26 = *(float *)(iVar3 + 0x68) * fVar31;

      fVar27 = *(float *)(iVar3 + 0x6c) * fVar31;

      fVar15 = *(float *)(iVar3 + 0x54) * fVar29;

      fVar21 = *(float *)(iVar3 + 0x58) * fVar29;

      fVar23 = *(float *)(iVar3 + 0x5c) * fVar29;

      fVar29 = *(float *)(iVar3 + 0x50) * fVar29 + *(float *)(iVar3 + 0x60) * fVar31 +

               *(float *)(iVar3 + 0x70) * fVar18;

      fVar31 = fVar15 + *(float *)(iVar3 + 100) * fVar31 + *(float *)(iVar3 + 0x74) * fVar18;

      fVar18 = fVar21 + fVar26 + *(float *)(iVar3 + 0x78) * fVar18;

      fVar30 = fVar23 + fVar27 + fVar30;

    }

    pfVar12[0x10] = fVar29;

    pfVar12[0x11] = fVar31;

    pfVar12[0x12] = fVar18;

    pfVar12[0x13] = fVar30;

    fVar18 = (float)param_4[0xd] * fVar19 - (float)param_4[0xe] * fVar17;

    fVar29 = (float)param_4[0xe] * fVar16 - (float)param_4[0xc] * fVar19;

    fVar30 = (float)param_4[0xc] * fVar17 - (float)param_4[0xd] * fVar16;

    fVar39 = (float)param_4[0xf] * fVar39 - (float)param_4[0xf] * fVar39;

    if (*(char *)(iVar4 + 0xc) == '\0') {

      fVar39 = *(float *)(iVar4 + 0x7c) * fVar30;

      fVar17 = *(float *)(iVar4 + 0x68) * fVar29;

      fVar19 = *(float *)(iVar4 + 0x6c) * fVar29;

      fVar31 = *(float *)(iVar4 + 0x54) * fVar18;

      fVar15 = *(float *)(iVar4 + 0x58) * fVar18;

      fVar16 = *(float *)(iVar4 + 0x5c) * fVar18;

      fVar18 = *(float *)(iVar4 + 0x50) * fVar18 + *(float *)(iVar4 + 0x60) * fVar29 +

               *(float *)(iVar4 + 0x70) * fVar30;

      fVar29 = fVar31 + *(float *)(iVar4 + 100) * fVar29 + *(float *)(iVar4 + 0x74) * fVar30;

      fVar30 = fVar15 + fVar17 + *(float *)(iVar4 + 0x78) * fVar30;

      fVar39 = fVar16 + fVar19 + fVar39;

    }

    pfVar12[0x14] = fVar18;

    pfVar12[0x15] = fVar29;

    pfVar12[0x16] = fVar30;

    pfVar12[0x17] = fVar39;

    fVar18 = *(float *)(iVar3 + 0x3c) + *(float *)(iVar4 + 0x3c) + _DAT_00a0d308 +

             pfVar12[0x12] * pfVar12[0x12] * *(float *)(iVar3 + 0x38) +

             pfVar12[0x16] * pfVar12[0x16] * *(float *)(iVar4 + 0x38) +

             pfVar12[0x11] * pfVar12[0x11] * *(float *)(iVar3 + 0x34) +

             pfVar12[0x15] * pfVar12[0x15] * *(float *)(iVar4 + 0x34) +

             pfVar12[0x10] * pfVar12[0x10] * *(float *)(iVar3 + 0x30) +

             pfVar12[0x14] * pfVar12[0x14] * *(float *)(iVar4 + 0x30);

    pfVar13 = pfVar12 + 0x18;

    pfVar12[0x17] = fVar18;

    pfVar12[0x13] = g_flOne / fVar18;

    pfVar12[0xf] = (float)param_4[4] * (float)param_5[3];

    fVar18 = *(float *)(iVar3 + 0x3c);

    fVar39 = *(float *)(iVar4 + 0x3c);

    fVar30 = pfVar12[0x12] * pfVar12[6] * *(float *)(iVar3 + 0x38) +

             pfVar12[0x16] * pfVar12[10] * *(float *)(iVar4 + 0x38) +

             fVar18 * pfVar12[0xe] * pfVar12[2] + fVar39 * pfVar12[0xe] * pfVar12[2] +

             pfVar12[0x11] * pfVar12[5] * *(float *)(iVar3 + 0x34) +

             pfVar12[0x15] * pfVar12[9] * *(float *)(iVar4 + 0x34) +

             fVar18 * pfVar12[0xd] * pfVar12[1] + fVar39 * pfVar12[0xd] * pfVar12[1] +

             pfVar12[0x10] * pfVar12[4] * *(float *)(iVar3 + 0x30) +

             pfVar12[0x14] * pfVar12[8] * *(float *)(iVar4 + 0x30) +

             fVar18 * pfVar12[0xc] * *pfVar12 + fVar39 * pfVar12[0xc] * *pfVar12;

    fVar18 = (float)param_5[7];

    *local_54 = 4.66362e-40;

    fVar39 = pfVar12[0xb];

    fVar29 = g_flOne / (pfVar12[0x17] * fVar39 - fVar30 * fVar30);

    pfVar12[0xb] = fVar29 * pfVar12[0x17];

    pfVar12[0x17] = fVar29 * fVar39;

    local_54[1] = (float)(param_4 + 1);

    pfVar11 = local_54 + 5;

    local_54[4] = 1.12104e-44;

    local_54[2] = -(fVar29 * fVar30);

    local_54[3] = fVar1 * fVar18;

    if (1 < param_2) {

      if ((*param_4 & 4) != 0) {

        param_4[7] = 0;

        if (-1 < param_2 + -1) {

          local_38 = param_2;

          do {

            fVar1 = *param_1;

            pfVar8 = param_1 + 1;

            pfVar9 = param_1 + 2;

            param_1 = param_1 + 8;

            local_38 = local_38 + -1;

            param_4[7] = (uint)(SQRT((*pfVar9 - fVar38) * (*pfVar9 - fVar38) +

                                     (*pfVar8 - fVar37) * (*pfVar8 - fVar37) +

                                     (fVar1 - fVar36) * (fVar1 - fVar36)) + (float)param_4[7]);

          } while (local_38 != 0);

        }

        fVar1 = (float)param_4[7];

        param_4[7] = (uint)(fVar10 * fVar1);

        if (fVar10 * fVar1 < _DAT_00a110e4) {

          *param_6 = (int)pfVar13;

          param_6[1] = (int)pfVar11;

          return;

        }

        *param_4 = *param_4 & 0xfffffffb;

      }

      if (*(char *)(iVar3 + 0xc) == '\0') {

        fVar1 = *(float *)(iVar3 + 0x74);

        fVar18 = *(float *)(iVar3 + 0x78);

        fVar10 = *(float *)(iVar3 + 0x7c);

        fVar36 = *(float *)(iVar3 + 100);

        fVar37 = *(float *)(iVar3 + 0x68);

        fVar38 = *(float *)(iVar3 + 0x6c);

        fVar39 = *(float *)(iVar3 + 0x54);

        fVar29 = *(float *)(iVar3 + 0x58);

        fVar30 = *(float *)(iVar3 + 0x5c);

        *pfVar13 = *(float *)(iVar3 + 0x50) * local_20[0] + *(float *)(iVar3 + 0x60) * local_20[1] +

                   *(float *)(iVar3 + 0x70) * local_20[2];

        pfVar12[0x19] = fVar39 * local_20[0] + fVar36 * local_20[1] + fVar1 * local_20[2];

        pfVar12[0x1a] = fVar29 * local_20[0] + fVar37 * local_20[1] + fVar18 * local_20[2];

        pfVar12[0x1b] = fVar30 * local_20[0] + fVar38 * local_20[1] + fVar10 * local_20[2];

      }

      else {

        *pfVar13 = local_20[0];

        pfVar12[0x19] = local_20[1];

        pfVar12[0x1a] = local_20[2];

        pfVar12[0x1b] = fVar32;

      }

      local_20[0] = (float)((uint)local_20[0] ^ _DAT_00a0d140);

      local_20[1] = (float)((uint)local_20[1] ^ _UNK_00a0d144);

      local_20[2] = (float)((uint)local_20[2] ^ _UNK_00a0d148);

      fVar32 = (float)((uint)fVar32 ^ _UNK_00a0d14c);

      if (*(char *)(iVar4 + 0xc) == '\0') {

        fVar32 = *(float *)(iVar4 + 0x74);

        fVar1 = *(float *)(iVar4 + 0x78);

        fVar18 = *(float *)(iVar4 + 0x7c);

        fVar10 = *(float *)(iVar4 + 100);

        fVar36 = *(float *)(iVar4 + 0x68);

        fVar37 = *(float *)(iVar4 + 0x6c);

        fVar38 = *(float *)(iVar4 + 0x54);

        fVar39 = *(float *)(iVar4 + 0x58);

        fVar29 = *(float *)(iVar4 + 0x5c);

        pfVar12[0x1c] =

             *(float *)(iVar4 + 0x50) * local_20[0] + *(float *)(iVar4 + 0x60) * local_20[1] +

             *(float *)(iVar4 + 0x70) * local_20[2];

        pfVar12[0x1d] = fVar38 * local_20[0] + fVar10 * local_20[1] + fVar32 * local_20[2];

        pfVar12[0x1e] = fVar39 * local_20[0] + fVar36 * local_20[1] + fVar1 * local_20[2];

        pfVar12[0x1f] = fVar29 * local_20[0] + fVar37 * local_20[1] + fVar18 * local_20[2];

      }

      else {

        pfVar12[0x1c] = local_20[0];

        pfVar12[0x1d] = local_20[1];

        pfVar12[0x1e] = local_20[2];

        pfVar12[0x1f] = fVar32;

      }

      fVar32 = *pfVar13;

      pfVar13 = pfVar12 + 0x20;

      pfVar12[0x1b] =

           g_flOne / (pfVar12[0x1a] * pfVar12[0x1a] * *(float *)(iVar3 + 0x38) +

                      pfVar12[0x1e] * pfVar12[0x1e] * *(float *)(iVar4 + 0x38) +

                      pfVar12[0x19] * pfVar12[0x19] * *(float *)(iVar3 + 0x34) +

                      pfVar12[0x1d] * pfVar12[0x1d] * *(float *)(iVar4 + 0x34) +

                      fVar32 * fVar32 * *(float *)(iVar3 + 0x30) +

                      pfVar12[0x1c] * pfVar12[0x1c] * *(float *)(iVar4 + 0x30) + _DAT_00a0d308);

      fVar32 = g_flOne / (float)param_4[7];

      *pfVar11 = (float)param_4[7];

      *local_54 = 5.59634e-40;

      pfVar11 = local_54 + 6;

      pfVar12[0x1b] = fVar32 * pfVar12[0x1b];

      pfVar12[0x1f] = (float)param_4[6] * (float)param_5[3];

    }

    param_6[1] = (int)pfVar11;

    *param_6 = (int)pfVar13;

    return;

  }

  param_6[1] = (int)local_54;

  *param_6 = (int)pfVar12;

  return;

}
