// =============================================================================
// FUN_006bb4b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006bb4b0
// Address:   0x006bb4b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bb4b0 @ 0x006bb4b0
// Stable ID: aa_006bb4b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~205 non-empty decompiler lines.
//  - Control keywords: if×16, return×5, goto×2.
//  - Notable callees: FUN_006c0080×4, rsqrtss×4, FUN_006bac60, FUN_006bb4b0.
//  - Return sites: 5.

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

void FUN_006bb4b0(uint8_t *param_1,float param_2,int *param_3,int param_4)



{

  float *pfVar1;

  float *pfVar2;

  int iVar3;

  ushort *puVar4;

  uint8_t auVar5 [16];

  uint8_t auVar6 [16];

  uint8_t auVar7 [16];

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float *pfVar17;

  int iVar18;

  uint uVar19;

  uint uVar20;

  uint uVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  uint8_t auVar25 [16];

  uint8_t auVar26 [16];

  uint8_t auVar27 [16];

  uint8_t auVar28 [16];

  float fVar29;

  float fVar30;

  float fVar31;

  float fVar32;

  uint8_t auVar33 [16];

  uint8_t auVar34 [16];

  uint8_t auVar35 [16];

  uint local_70;

  uint local_6c;

  float local_64;

  int local_5c;

  

  iVar3 = *param_3;

  if ((param_3[2] < 3) && (*(int *)(param_4 + 8) < 3)) {

    local_6c = 0;

    local_5c = 3;

    if (param_3[2] == 2) {

      puVar4 = (ushort *)param_3[1];

      uVar21 = (uint)*puVar4;

      uVar19 = (uint)puVar4[(uint)puVar4[1] * 4];

      uVar20 = uVar19;

      if (uVar19 < uVar21) {

        uVar20 = uVar21;

        uVar21 = uVar19;

      }

      uVar19 = (uint)**(ushort **)(param_4 + 4);

      local_70 = uVar19;

      if (*(int *)(param_4 + 8) == 2) {

        local_6c = (uint)*(ushort *)

                          (*(int *)(param_4 + 4) + (uint)*(ushort *)(*(int *)(param_4 + 4) + 2) * 8)

        ;

        if (local_6c < uVar19) {

          local_70 = local_6c;

          local_6c = uVar19;

        }

        local_5c = 4;

      }

    }

    else {

      if (*(int *)(param_4 + 8) != 2) {

        FUN_006c0080(*(uint16_t *)param_3[1],**(uint16_t **)(param_4 + 4));

        goto LAB_006bba31;

      }

      puVar4 = *(ushort **)(param_4 + 4);

      uVar21 = (uint)*(ushort *)param_3[1];

      uVar19 = (uint)puVar4[(uint)puVar4[1] * 4];

      local_70 = (uint)*puVar4;

      uVar20 = uVar19;

      if (uVar19 < uVar21) {

        uVar20 = uVar21;

        uVar21 = uVar19;

      }

    }

    pfVar1 = (float *)(uVar21 * 0x10 + iVar3);

    pfVar2 = (float *)(uVar20 * 0x10 + iVar3);

    fVar8 = *(float *)(uVar20 * 0x10 + iVar3) - *pfVar1;

    fVar9 = pfVar2[1] - pfVar1[1];

    fVar10 = pfVar2[2] - pfVar1[2];

    fVar23 = fVar9 * fVar9;

    fVar24 = fVar10 * fVar10;

    fVar29 = fVar24 + fVar23 + fVar8 * fVar8;

    pfVar17 = (float *)(local_70 * 0x10 + iVar3);

    fVar11 = *(float *)(local_70 * 0x10 + iVar3) - *pfVar2;

    fVar12 = pfVar17[1] - pfVar2[1];

    fVar13 = pfVar17[2] - pfVar2[2];

    auVar25._0_4_ = fVar11 * fVar11;

    auVar25._4_4_ = fVar12 * fVar12;

    auVar25._8_4_ = fVar13 * fVar13;

    auVar25._12_4_ = (pfVar17[3] - pfVar2[3]) * (pfVar17[3] - pfVar2[3]);

    fVar14 = *pfVar1 - *pfVar17;

    fVar15 = pfVar1[1] - pfVar17[1];

    fVar32 = auVar25._8_4_ + auVar25._4_4_ + auVar25._0_4_;

    fVar16 = pfVar1[2] - pfVar17[2];

    fVar30 = fVar15 * fVar15;

    fVar31 = fVar16 * fVar16;

    local_64 = fVar31 + fVar30 + fVar14 * fVar14;

    auVar33._4_4_ = fVar23;

    auVar33._0_4_ = fVar23;

    auVar33._8_4_ = fVar23;

    auVar33._12_4_ = fVar23;

    auVar34._4_12_ = auVar33._4_12_;

    auVar34._0_4_ = fVar23 + fVar8 * fVar8;

    auVar35._4_4_ = fVar24;

    auVar35._0_4_ = fVar24 + auVar34._0_4_;

    auVar35._8_4_ = fVar24;

    auVar35._12_4_ = fVar24;

    auVar35 = rsqrtss(auVar34,auVar35);

    fVar23 = auVar35._0_4_;

    fVar23 = fVar23 * 0.5 * (3.0 - (fVar24 + auVar34._0_4_) * fVar23 * fVar23);

    fVar24 = auVar25._8_4_ + auVar25._4_4_ + auVar25._0_4_;

    auVar5._4_4_ = auVar25._8_4_;

    auVar5._0_4_ = fVar24;

    auVar5._8_4_ = auVar25._8_4_;

    auVar5._12_4_ = auVar25._8_4_;

    auVar35 = rsqrtss(auVar25,auVar5);

    fVar22 = auVar35._0_4_;

    fVar24 = fVar22 * 0.5 * (3.0 - fVar24 * fVar22 * fVar22);

    fVar8 = fVar24 * fVar11 - fVar23 * fVar8;

    fVar22 = fVar30 + fVar14 * fVar14;

    auVar26._4_4_ = fVar30;

    auVar26._0_4_ = fVar22;

    auVar26._8_4_ = fVar30;

    auVar26._12_4_ = fVar30;

    fVar22 = fVar31 + fVar22;

    auVar6._4_4_ = fVar31;

    auVar6._0_4_ = fVar22;

    auVar6._8_4_ = fVar31;

    auVar6._12_4_ = fVar31;

    auVar35 = rsqrtss(auVar26,auVar6);

    fVar30 = auVar35._0_4_;

    fVar9 = fVar24 * fVar12 - fVar23 * fVar9;

    fVar10 = fVar24 * fVar13 - fVar23 * fVar10;

    fVar23 = fVar30 * 0.5 * (3.0 - fVar22 * fVar30 * fVar30);

    if (fVar10 * fVar10 + fVar9 * fVar9 + fVar8 * fVar8 < param_2) {

      if (local_5c == 4) {

        iVar18 = local_6c * 0x10 + iVar3;

        fVar8 = *(float *)(local_6c * 0x10 + iVar3) - *pfVar2;

        fVar9 = *(float *)(iVar18 + 4) - pfVar2[1];

        fVar10 = *(float *)(iVar18 + 8) - pfVar2[2];

        fVar22 = fVar9 * fVar9;

        fVar30 = fVar10 * fVar10;

        auVar27._4_4_ = fVar22;

        auVar27._0_4_ = fVar22;

        auVar27._8_4_ = fVar22;

        auVar27._12_4_ = fVar22;

        auVar28._4_12_ = auVar27._4_12_;

        auVar28._0_4_ = fVar22 + fVar8 * fVar8;

        auVar7._4_4_ = fVar30;

        auVar7._0_4_ = fVar30 + auVar28._0_4_;

        auVar7._8_4_ = fVar30;

        auVar7._12_4_ = fVar30;

        auVar35 = rsqrtss(auVar28,auVar7);

        fVar31 = auVar35._0_4_;

        fVar31 = fVar31 * 0.5 * (3.0 - (fVar30 + auVar28._0_4_) * fVar31 * fVar31);

        fVar11 = fVar24 * fVar11 - fVar31 * fVar8;

        fVar9 = fVar24 * fVar12 - fVar31 * fVar9;

        fVar10 = fVar24 * fVar13 - fVar31 * fVar10;

        if (param_2 <= fVar10 * fVar10 + fVar9 * fVar9 + fVar11 * fVar11) goto LAB_006bba3e;

        if (fVar32 < fVar30 + fVar22 + fVar8 * fVar8) {

          local_70 = local_6c;

          FUN_006bac60(pfVar1);

          local_64 = fVar23 * fVar16 * fVar23 * fVar16 +

                     fVar23 * fVar15 * fVar23 * fVar15 + fVar23 * fVar14 * fVar23 * fVar14;

        }

      }

      fVar8 = local_64;

      if (local_64 < fVar32) {

        fVar8 = fVar32;

      }

      if (fVar8 < fVar29) {

        fVar8 = fVar29;

      }

      if (fVar29 == fVar8) {

        FUN_006c0080(uVar21,uVar20);

        *param_1 = 1;

        return;

      }

      if (fVar32 == fVar8) {

        FUN_006c0080(uVar20,local_70);

        *param_1 = 1;

        return;

      }

      if (local_64 == fVar8) {

        FUN_006c0080(local_70,uVar21);

        *param_1 = 1;

        return;

      }

LAB_006bba31:

      *param_1 = 1;

      return;

    }

  }

LAB_006bba3e:

  *param_1 = 0;

  return;

}
