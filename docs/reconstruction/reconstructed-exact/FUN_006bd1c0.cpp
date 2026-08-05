// =============================================================================
// FUN_006bd1c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006bd1c0
// Address:   0x006bd1c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bd1c0 @ 0x006bd1c0
// Stable ID: aa_006bd1c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~338 non-empty decompiler lines.
//  - Control keywords: if×16, do×3, while×3, return×1.
//  - Notable callees: FUN_006ba9d0×7, FUN_005b3300×3, FUN_006bc390×3, rsqrtss×3, FUN_006bacf0, FUN_006bc1b0, FUN_006bc200, FUN_006bd1c0.
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

void FUN_006bd1c0(uint8_t *param_1,int param_2,int *param_3,uint32_t /* width from decompiler */ param_4,int *param_5,

                 int *param_6,uint8_t *param_7)



{

  ushort *puVar1;

  ushort *puVar2;

  int iVar3;

  ushort *puVar4;

  bool bVar5;

  uint8_t auVar6 [16];

  uint8_t auVar7 [16];

  int iVar8;

  int iVar9;

  char *pcVar10;

  uint uVar11;

  uint uVar12;

  float *pfVar13;

  int iVar14;

  float *pfVar15;

  float fVar16;

  float fVar17;

  float fVar21;

  float fVar22;

  uint8_t auVar18 [16];

  uint8_t auVar19 [16];

  uint8_t auVar20 [16];

  float fVar23;

  uint8_t auVar24 [16];

  uint8_t auVar25 [16];

  uint8_t auVar26 [16];

  uint8_t auVar27 [16];

  int local_fc;

  int local_f8;

  int local_f4;

  float local_f0;

  float fStack_ec;

  float fStack_e8;

  float fStack_e4;

  uint32_t /* width from decompiler */ local_e0;

  uint32_t /* width from decompiler */ local_dc;

  uint32_t /* width from decompiler */ local_d8;

  int local_c4;

  float local_c0;

  uint8_t local_bb;

  uint8_t local_ba;

  uint8_t local_b9;

  int local_b8;

  uint8_t local_b4;

  uint8_t local_b3;

  uint8_t local_b2;

  uint8_t local_b1;

  float local_b0;

  float fStack_ac;

  float fStack_a8;

  float fStack_a4;

  ushort *local_a0;

  ushort *local_9c;

  ushort *local_98;

  uint16_t local_94;

  float local_90;

  float fStack_8c;

  float fStack_88;

  float fStack_84;

  float local_80;

  float fStack_7c;

  float fStack_78;

  float fStack_74;

  float local_70;

  float fStack_6c;

  float fStack_68;

  float fStack_64;

  float local_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  float local_48;

  uint32_t /* width from decompiler */ local_44;

  float local_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float local_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  uint local_18;

  

  local_b8 = *param_3;

  iVar3 = param_3[1];

  local_fc = 0;

  if (0 < param_3[2]) {

    do {

      local_18 = *(uint *)(param_3[1] + local_fc * 8);

      uVar12 = (uint)*(ushort *)(param_3[1] + 4 + local_fc * 8);

      uVar11 = (uint)*(ushort *)(iVar3 + 4 + uVar12 * 8);

      if ((local_fc < (int)uVar12) && (local_fc < (int)uVar11)) {

        iVar8 = param_5[1];

        iVar14 = iVar8 + 1;

        if ((int)(param_5[2] & 0x7fffffffU) < iVar14) {

          iVar9 = (param_5[2] & 0x7fffffffU) * 2;

          if (iVar14 < iVar9) {

            iVar14 = iVar9;

          }

          FUN_005b3300(param_5,iVar14,0x10);

        }

        param_5[1] = iVar8 + 1;

        pfVar13 = (float *)(iVar8 * 0x10 + *param_5);

        iVar14 = *param_3;

        pfVar15 = (float *)((local_18 & 0xffff) * 0x10 + iVar14);

        local_80 = *pfVar15;

        fStack_7c = pfVar15[1];

        fStack_78 = pfVar15[2];

        fStack_74 = pfVar15[3];

        puVar1 = (ushort *)(iVar3 + uVar12 * 8);

        pfVar15 = (float *)((uint)*puVar1 * 0x10 + iVar14);

        local_90 = *pfVar15;

        fStack_8c = pfVar15[1];

        fStack_88 = pfVar15[2];

        fStack_84 = pfVar15[3];

        local_30 = local_80 - local_90;

        puVar2 = (ushort *)(iVar3 + uVar11 * 8);

        fStack_2c = fStack_7c - fStack_8c;

        pfVar15 = (float *)((uint)*puVar2 * 0x10 + iVar14);

        local_60 = *pfVar15;

        fStack_5c = pfVar15[1];

        fStack_58 = pfVar15[2];

        fStack_54 = pfVar15[3];

        local_c4 = 0x40400000;

        fStack_28 = fStack_78 - fStack_88;

        local_44 = 0x3f000000;

        local_40 = local_60 - local_90;

        fVar16 = fStack_2c * fStack_2c;

        fVar17 = fStack_28 * fStack_28;

        auVar18._4_4_ = fVar16;

        auVar18._0_4_ = fVar16;

        auVar18._8_4_ = fVar16;

        auVar18._12_4_ = fVar16;

        auVar19._4_12_ = auVar18._4_12_;

        auVar19._0_4_ = fVar16 + local_30 * local_30;

        fStack_3c = fStack_5c - fStack_8c;

        fStack_38 = fStack_58 - fStack_88;

        auVar20._4_4_ = fVar17;

        auVar20._0_4_ = fVar17 + auVar19._0_4_;

        auVar20._8_4_ = fVar17;

        auVar20._12_4_ = fVar17;

        auVar20 = rsqrtss(auVar19,auVar20);

        fVar16 = auVar20._0_4_;

        fStack_24 = fVar16 * 0.5 * (3.0 - (fVar17 + auVar19._0_4_) * fVar16 * fVar16);

        local_30 = fStack_24 * local_30;

        fStack_2c = fStack_24 * fStack_2c;

        fStack_28 = fStack_24 * fStack_28;

        fStack_24 = fStack_24 * (fStack_74 - fStack_84);

        fVar16 = fStack_3c * fStack_3c;

        fStack_e8 = fStack_38 * fStack_38;

        auVar24._4_4_ = fVar16;

        auVar24._0_4_ = fVar16;

        auVar24._8_4_ = fVar16;

        auVar24._12_4_ = fVar16;

        auVar25._4_12_ = auVar24._4_12_;

        auVar25._0_4_ = fVar16 + local_40 * local_40;

        auVar6._4_4_ = fStack_e8;

        auVar6._0_4_ = fStack_e8 + auVar25._0_4_;

        auVar6._8_4_ = fStack_e8;

        auVar6._12_4_ = fStack_e8;

        auVar20 = rsqrtss(auVar25,auVar6);

        local_f0 = auVar20._0_4_;

        fStack_34 = local_f0 * 0.5 * (3.0 - (fStack_e8 + auVar25._0_4_) * local_f0 * local_f0);

        local_40 = fStack_34 * local_40;

        fStack_3c = fStack_34 * fStack_3c;

        fStack_38 = fStack_34 * fStack_38;

        fStack_34 = fStack_34 * (fStack_54 - fStack_84);

        fVar17 = fStack_2c * fStack_38 - fStack_28 * fStack_3c;

        fVar21 = fStack_28 * local_40 - local_30 * fStack_38;

        fVar22 = local_30 * fStack_3c - fStack_2c * local_40;

        fVar23 = fStack_24 * fStack_34 - fStack_24 * fStack_34;

        fVar16 = fVar21 * fVar21;

        fStack_ec = fVar22 * fVar22;

        local_48 = fStack_ec + fVar16 + fVar17 * fVar17;

        *pfVar13 = fVar17;

        pfVar13[1] = fVar21;

        pfVar13[2] = fVar22;

        pfVar13[3] = fVar23;

        if (*(float *)(param_2 + 8) <= local_48) {

          auVar26._4_4_ = fVar16;

          auVar26._0_4_ = fVar16;

          auVar26._8_4_ = fVar16;

          auVar26._12_4_ = fVar16;

          auVar27._4_12_ = auVar26._4_12_;

          auVar27._0_4_ = fVar16 + fVar17 * fVar17;

          auVar7._4_4_ = fStack_ec;

          auVar7._0_4_ = fStack_ec + auVar27._0_4_;

          auVar7._8_4_ = fStack_ec;

          auVar7._12_4_ = fStack_ec;

          auVar20 = rsqrtss(auVar27,auVar7);

          local_f0 = auVar20._0_4_;

          fVar16 = local_f0 * 0.5 * (3.0 - (fStack_ec + auVar27._0_4_) * local_f0 * local_f0);

          *pfVar13 = fVar16 * fVar17;

          pfVar13[1] = fVar16 * fVar21;

          pfVar13[2] = fVar16 * fVar22;

          pfVar13[3] = fVar16 * fVar23;

          local_c0 = fVar16 * fVar22 * fStack_78 +

                     fVar16 * fVar21 * fStack_7c + fVar16 * fVar17 * local_80;

          pfVar13[3] = -local_c0;

          iVar8 = param_6[1];

          iVar14 = iVar8 + 1;

          local_b0 = (local_90 - local_80) * 0.5;

          fStack_ac = (fStack_8c - fStack_7c) * 0.5;

          fStack_a8 = (fStack_88 - fStack_78) * 0.5;

          fStack_a4 = (fStack_84 - fStack_74) * 0.5;

          local_70 = (local_60 - local_80) * 0.5;

          fStack_6c = (fStack_5c - fStack_7c) * 0.5;

          fStack_68 = (fStack_58 - fStack_78) * 0.5;

          fStack_64 = (fStack_54 - fStack_74) * 0.5;

          fStack_e8 = fStack_ec;

          fStack_e4 = fStack_ec;

          if ((int)(param_6[2] & 0x7fffffffU) < iVar14) {

            iVar9 = (param_6[2] & 0x7fffffffU) * 2;

            if (iVar9 <= iVar14) {

              iVar9 = iVar14;

            }

            FUN_005b3300(param_6,iVar9,0x20);

          }

          param_6[1] = iVar8 + 1;

          fVar16 = pfVar13[1];

          fVar17 = pfVar13[2];

          fVar21 = pfVar13[3];

          pfVar15 = (float *)(iVar8 * 0x20 + *param_6);

          *pfVar15 = *pfVar13;

          pfVar15[1] = fVar16;

          pfVar15[2] = fVar17;

          pfVar15[3] = fVar21;

          iVar14 = param_3[1];

          pfVar15[5] = (float)puVar1;

          pfVar15[4] = (float)(iVar14 + local_fc * 8);

          pfVar15[6] = (float)puVar2;

          FUN_006bc1b0();

        }

        else {

          iVar14 = param_5[1] + -1;

          fStack_ec = fStack_e8;

          fStack_e4 = fStack_e8;

          if ((int)(param_5[2] & 0x7fffffffU) < iVar14) {

            iVar8 = (param_5[2] & 0x7fffffffU) * 2;

            if (iVar8 <= iVar14) {

              iVar8 = iVar14;

            }

            FUN_005b3300(param_5,iVar8,0x10);

          }

          param_5[1] = iVar14;

        }

      }

      local_fc = local_fc + 1;

    } while (local_fc < param_3[2]);

  }

  *param_7 = param_5[1] == 0;

  if (0 < param_6[1]) {

    local_f8 = 0;

    local_f4 = 1;

    do {

      local_c4 = local_f4;

      iVar14 = local_f8;

      if (local_f4 < param_6[1]) {

        do {

          local_fc = iVar14 + 0x20;

          iVar8 = *param_6;

          local_94 = *(uint16_t *)(local_f8 + 0x1c + iVar8);

          pfVar15 = (float *)(local_f8 + iVar8);

          local_b0 = *pfVar15;

          fStack_ac = pfVar15[1];

          fStack_a8 = pfVar15[2];

          fStack_a4 = pfVar15[3];

          puVar1 = *(ushort **)(local_f8 + 0x10 + iVar8);

          puVar2 = *(ushort **)(local_f8 + 0x14 + iVar8);

          puVar4 = *(ushort **)(local_f8 + 0x18 + iVar8);

          pfVar15 = (float *)(local_fc + iVar8);

          local_f0 = *pfVar15;

          fStack_ec = pfVar15[1];

          fStack_e8 = pfVar15[2];

          fStack_e4 = pfVar15[3];

          local_e0 = *(uint32_t /* width from decompiler */ *)(iVar14 + 0x30 + iVar8);

          local_70 = local_f0 + local_b0;

          local_dc = *(uint32_t /* width from decompiler */ *)(iVar14 + 0x34 + iVar8);

          fStack_6c = fStack_ec + fStack_ac;

          local_d8 = *(uint32_t /* width from decompiler */ *)(iVar14 + 0x38 + iVar8);

          fStack_68 = fStack_e8 + fStack_a8;

          fStack_64 = fStack_e4 + fStack_a4;

          local_c0 = fStack_68 * fStack_68 + fStack_6c * fStack_6c + local_70 * local_70;

          local_a0 = puVar1;

          local_9c = puVar2;

          local_98 = puVar4;

          if (local_c0 < *(float *)(param_2 + 0x18) * *(float *)(param_2 + 0x18)) {

            local_b0 = -local_f0;

            fStack_ac = -fStack_ec;

            fStack_a8 = -fStack_e8;

            pcVar10 = (char *)FUN_006ba9d0(&local_bb,iVar3,puVar1,local_e0,puVar2,local_dc,&local_b0

                                           ,&local_f0);

            if ((*pcVar10 != '\0') ||

               (pcVar10 = (char *)FUN_006ba9d0(&local_b9,iVar3,puVar1,local_e0,puVar2,local_d8,

                                               &local_b0,&local_f0), *pcVar10 != '\0')) {

              *param_7 = 1;

              FUN_006bc390(&local_b0,(uint)*puVar1 * 0x10 + local_b8,(uint)*puVar2 * 0x10 + local_b8

                           ,(uint)*puVar4 * 0x10 + local_b8,param_5);

            }

            pcVar10 = (char *)FUN_006ba9d0(&local_b4,iVar3,puVar1,local_e0,puVar4,local_dc,&local_b0

                                           ,&local_f0);

            if ((*pcVar10 != '\0') ||

               (pcVar10 = (char *)FUN_006ba9d0(&local_b1,iVar3,puVar1,local_e0,puVar4,local_d8,

                                               &local_b0,&local_f0), *pcVar10 != '\0')) {

              *param_7 = 1;

              FUN_006bc390(&local_b0,(uint)*puVar1 * 0x10 + local_b8,(uint)*puVar4 * 0x10 + local_b8

                           ,(uint)*puVar2 * 0x10 + local_b8,param_5);

            }

            pcVar10 = (char *)FUN_006ba9d0(&local_ba,iVar3,puVar2,local_e0,puVar4,local_dc,&local_b0

                                           ,&local_f0);

            if (((*pcVar10 != '\0') ||

                (pcVar10 = (char *)FUN_006ba9d0(&local_b2,iVar3,puVar2,local_e0,puVar4,local_d8,

                                                &local_b0,&local_f0), *pcVar10 != '\0')) ||

               (pcVar10 = (char *)FUN_006ba9d0(&local_b3,iVar3,puVar2,local_dc,puVar4,local_d8,

                                               &local_b0,&local_f0), *pcVar10 != '\0')) {

              *param_7 = 1;

              FUN_006bc390(&local_b0,(uint)*puVar2 * 0x10 + local_b8,(uint)*puVar4 * 0x10 + local_b8

                           ,(uint)*puVar1 * 0x10 + local_b8,param_5);

            }

          }

          local_c4 = local_c4 + 1;

          iVar14 = local_fc;

        } while (local_c4 < param_6[1]);

      }

      local_f8 = local_f8 + 0x20;

      bVar5 = local_f4 < param_6[1];

      local_f4 = local_f4 + 1;

    } while (bVar5);

  }

  if (1 < param_5[1]) {

    FUN_006bacf0(*param_5,0,param_5[1] + -1,&LAB_006babf0);

  }

  FUN_006bc200(*(uint32_t /* width from decompiler */ *)(param_2 + 0x10),param_5,&local_c0);

  *param_1 = 1;

  return;

}
