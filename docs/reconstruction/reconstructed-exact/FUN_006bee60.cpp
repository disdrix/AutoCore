// =============================================================================
// FUN_006bee60
// -----------------------------------------------------------------------------
// Stable ID: aa_006bee60
// Address:   0x006bee60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bee60 @ 0x006bee60
// Stable ID: aa_006bee60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~408 non-empty decompiler lines.
//  - Control keywords: if×26, while×3, return×2, do×1.
//  - Notable callees: rsqrtss×6, FUN_006bebe0×2, FUN_005b3370, FUN_006bae10, FUN_006bb4b0, FUN_006bbc60, FUN_006bc6d0, FUN_006bdf50.
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



uint32_t /* width from decompiler */ FUN_006bee60(int param_1,int *param_2,int param_3,int *param_4)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint8_t auVar4 [16];

  uint8_t auVar5 [16];

  uint8_t auVar6 [16];

  uint8_t auVar7 [16];

  uint uVar8;

  int *piVar9;

  char *pcVar10;

  uint8_t **ppuVar11;

  float *pfVar12;

  float *pfVar13;

  float *pfVar14;

  float *pfVar15;

  uint32_t /* width from decompiler */ *puVar16;

  int iVar17;

  float *pfVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float fVar26;

  uint8_t auVar27 [16];

  uint8_t auVar28 [16];

  uint8_t auVar29 [16];

  uint8_t auVar30 [16];

  uint8_t auVar31 [16];

  uint8_t auVar32 [16];

  uint8_t auVar33 [16];

  uint8_t auVar34 [16];

  uint8_t auVar35 [16];

  uint8_t auVar36 [16];

  uint8_t auVar37 [16];

  uint8_t auVar38 [16];

  uint8_t auVar39 [16];

  uint8_t auVar40 [16];

  uint8_t **local_e34;

  int iStack_e0c;

  uint8_t local_e05;

  int local_e04;

  float fStack_e00;

  float fStack_dfc;

  float fStack_df8;

  float fStack_df4;

  int local_df0;

  int local_dec;

  int iStack_de8;

  float fStack_de4;

  float fStack_de0;

  uint32_t /* width from decompiler */ uStack_ddc;

  float fStack_dd8;

  uint32_t /* width from decompiler */ uStack_dd4;

  float fStack_dd0;

  float local_dcc [2];

  int local_dc4;

  float fStack_dc0;

  float fStack_dbc;

  float fStack_db8;

  float fStack_db4;

  float fStack_db0;

  float fStack_dac;

  float fStack_da8;

  float fStack_da4;

  uint8_t *local_da0;

  uint32_t /* width from decompiler */ local_d9c;

  uint local_d98;

  uint8_t local_d94 [20];

  float fStack_d80;

  float fStack_d7c;

  float fStack_d78;

  float fStack_d74;

  float local_d70;

  float fStack_d6c;

  float fStack_d68;

  float fStack_d64;

  float local_d60;

  float fStack_d5c;

  float fStack_d58;

  float fStack_d54;

  uint8_t *local_d50;

  uint local_d4c;

  uint local_d48;

  uint8_t local_d44 [260];

  uint8_t *puStack_c40;

  uint32_t /* width from decompiler */ uStack_c3c;

  int iStack_c38;

  uint8_t auStack_c34 [516];

  uint8_t *puStack_a30;

  uint32_t /* width from decompiler */ uStack_a2c;

  int iStack_a28;

  uint8_t auStack_a24 [516];

  uint8_t *local_820;

  int local_81c;

  int local_818;

  uint8_t local_814 [2064];

  

  *param_4 = *param_2;

  pcVar10 = (char *)FUN_006bb4b0(&local_e05,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2,param_3,param_4);

  if (*pcVar10 == '\0') {

    local_df0 = *param_2;

    local_da0 = local_d94;

    local_d98 = 0x80000001;

    local_d9c = 1;

    FUN_006bbc60(param_2,param_3,local_da0,&local_d60);

    iVar17 = param_2[2] + 2 + *(int *)(param_3 + 8);

    local_dcc[0] = *(float *)(param_1 + 0x20);

    local_d50 = local_d44;

    local_820 = local_814;

    local_dc4 = iVar17 * 3;

    local_d4c = 0;

    local_81c = 0;

    local_e34 = &local_da0;

    local_d70 = local_d60;

    fStack_d6c = fStack_d5c;

    fStack_d68 = fStack_d58;

    fStack_d64 = fStack_d54;

    local_d48 = 0x80000040;

    local_818 = -0x7fffff80;

    local_e04 = 0;

    local_dec = iVar17;

    uVar8 = local_d4c;

    if (0 < local_dc4) {

      while( true ) {

        piVar9 = DAT_00b05060;

        if ((iVar17 < local_e04) &&

           (local_dcc[0] = local_dcc[0] * DAT_00aaaa10, g_flOne < local_dcc[0])) {

          iVar17 = iVar17 + 1;

          local_dec = iVar17;

        }

        piVar1 = DAT_00b05060 + 3;

        if (*piVar1 < 0x150) {

          ppuVar11 = (uint8_t **)(**(code **)(*DAT_00b05060 + 0x24))(0x150);

        }

        else {

          ppuVar11 = (uint8_t **)DAT_00b05060[2];

          DAT_00b05060[2] = (int)(ppuVar11 + 0x54);

          piVar9[3] = *piVar1 + -0x150;

        }

        if (ppuVar11 != (uint8_t **)0x0) {

          *ppuVar11 = (uint8_t *)(ppuVar11 + 3);

          ppuVar11[1] = (uint8_t *)0x0;

          ppuVar11[2] = (uint8_t *)0x80000010;

        }

        if (local_d4c == (local_d48 & 0x7fffffff)) {

          FUN_005b3370(&local_d50,4);

        }

        *(uint8_t ***)(local_d50 + local_d4c * 4) = ppuVar11;

        local_d4c = local_d4c + 1;

        iStack_de8 = 0;

        if (0 < (int)local_e34[1]) {

          iStack_e0c = 0;

          do {

            puVar16 = (uint32_t /* width from decompiler */ *)(*local_e34 + iStack_e0c);

            puStack_c40 = auStack_c34;

            uStack_c3c = 0;

            iStack_c38 = -0x7fffffc0;

            uStack_a2c = 0;

            iStack_a28 = -0x7fffffc0;

            puStack_a30 = auStack_a24;

            pfVar18 = (float *)((uint)*(ushort *)*puVar16 * 0x10 + local_df0);

            puVar2 = (uint32_t /* width from decompiler */ *)puVar16[2];

            pfVar15 = (float *)((uint)*(ushort *)puVar16[1] * 0x10 + local_df0);

            fStack_d80 = local_d60;

            fStack_d7c = fStack_d5c;

            fStack_d78 = fStack_d58;

            fStack_d74 = fStack_d54;

            if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

              pfVar12 = (float *)((uint)*(ushort *)*puVar2 * 0x10 + local_df0);

              pfVar13 = (float *)((uint)*(ushort *)puVar2[1] * 0x10 + local_df0);

              pfVar14 = pfVar15;

              if (pfVar12 != pfVar18) {

                pfVar14 = pfVar18;

              }

              uStack_ddc = 0x40400000;

              fStack_e00 = *pfVar13 - *pfVar12;

              fStack_dfc = pfVar13[1] - pfVar12[1];

              fStack_df8 = pfVar13[2] - pfVar12[2];

              fVar24 = *pfVar14 - *pfVar12;

              fVar20 = fStack_dfc * fStack_dfc;

              fVar22 = fStack_df8 * fStack_df8;

              auVar27._4_4_ = fVar20;

              auVar27._0_4_ = fVar20;

              auVar27._8_4_ = fVar20;

              auVar27._12_4_ = fVar20;

              auVar28._4_12_ = auVar27._4_12_;

              auVar28._0_4_ = fVar20 + fStack_e00 * fStack_e00;

              fVar20 = pfVar14[1] - pfVar12[1];

              fVar21 = pfVar14[2] - pfVar12[2];

              auVar29._4_4_ = fVar22;

              auVar29._0_4_ = fVar22 + auVar28._0_4_;

              auVar29._8_4_ = fVar22;

              auVar29._12_4_ = fVar22;

              auVar29 = rsqrtss(auVar28,auVar29);

              fVar23 = auVar29._0_4_;

              uStack_dd4 = 0x3f000000;

              fStack_df4 = fVar23 * 0.5 * (3.0 - (fVar22 + auVar28._0_4_) * fVar23 * fVar23);

              fStack_e00 = fStack_df4 * fStack_e00;

              fStack_dfc = fStack_df4 * fStack_dfc;

              fStack_df8 = fStack_df4 * fStack_df8;

              fStack_df4 = fStack_df4 * (pfVar13[3] - pfVar12[3]);

              fVar22 = fVar20 * fVar20;

              fVar23 = fVar21 * fVar21;

              auVar36._4_4_ = fVar22;

              auVar36._0_4_ = fVar22;

              auVar36._8_4_ = fVar22;

              auVar36._12_4_ = fVar22;

              auVar37._4_12_ = auVar36._4_12_;

              auVar37._0_4_ = fVar22 + fVar24 * fVar24;

              auVar4._4_4_ = fVar23;

              auVar4._0_4_ = fVar23 + auVar37._0_4_;

              auVar4._8_4_ = fVar23;

              auVar4._12_4_ = fVar23;

              auVar29 = rsqrtss(auVar37,auVar4);

              fVar22 = auVar29._0_4_;

              fVar23 = fVar22 * 0.5 * (3.0 - (fVar23 + auVar37._0_4_) * fVar22 * fVar22);

              fVar26 = fVar23 * (pfVar14[3] - pfVar12[3]);

              fVar22 = fStack_dfc * fVar23 * fVar21 - fStack_df8 * fVar23 * fVar20;

              fVar21 = fStack_df8 * fVar23 * fVar24 - fStack_e00 * fVar23 * fVar21;

              fVar24 = fStack_e00 * fVar23 * fVar20 - fStack_dfc * fVar23 * fVar24;

              fStack_de0 = fVar24 * fVar24 + fVar21 * fVar21 + fVar22 * fVar22;

              fVar20 = fStack_df4 * fVar26 - fStack_df4 * fVar26;

              if (fStack_de0 < _DAT_00a110e4) {

                fVar23 = *pfVar14 - *pfVar13;

                fVar26 = pfVar14[1] - pfVar13[1];

                fVar25 = pfVar14[2] - pfVar13[2];

                fVar24 = fVar26 * fVar26;

                fVar20 = fVar25 * fVar25;

                auVar30._4_4_ = fVar24;

                auVar30._0_4_ = fVar24;

                auVar30._8_4_ = fVar24;

                auVar30._12_4_ = fVar24;

                auVar31._4_12_ = auVar30._4_12_;

                auVar31._0_4_ = fVar24 + fVar23 * fVar23;

                auVar5._4_4_ = fVar20;

                auVar5._0_4_ = fVar20 + auVar31._0_4_;

                auVar5._8_4_ = fVar20;

                auVar5._12_4_ = fVar20;

                auVar29 = rsqrtss(auVar31,auVar5);

                fVar24 = auVar29._0_4_;

                fVar19 = fVar24 * 0.5 * (3.0 - (fVar20 + auVar31._0_4_) * fVar24 * fVar24);

                fVar23 = fVar19 * fVar23;

                fVar26 = fVar19 * fVar26;

                fVar25 = fVar19 * fVar25;

                fVar19 = fVar19 * (pfVar14[3] - pfVar13[3]);

                fVar22 = fStack_dfc * fVar25 - fStack_df8 * fVar26;

                fVar21 = fStack_df8 * fVar23 - fStack_e00 * fVar25;

                fVar24 = fStack_e00 * fVar26 - fStack_dfc * fVar23;

                fStack_dd8 = fVar24 * fVar24 + fVar21 * fVar21 + fVar22 * fVar22;

                fVar20 = fStack_df4 * fVar19 - fStack_df4 * fVar19;

                if (fStack_dd8 < _DAT_00a110e4) {

                  fStack_dc0 = fVar23 + fStack_e00;

                  fStack_dbc = fVar26 + fStack_dfc;

                  fStack_db8 = fVar25 + fStack_df8;

                  fStack_db4 = fVar19 + fStack_df4;

                  fStack_db0 = fStack_e00 - fVar23;

                  fStack_dac = fStack_dfc - fVar26;

                  fStack_da8 = fStack_df8 - fVar25;

                  fStack_da4 = fStack_df4 - fVar19;

                  auVar38._0_4_ = fStack_db0 * fStack_db0;

                  auVar38._4_4_ = fStack_dac * fStack_dac;

                  auVar38._8_4_ = fStack_da8 * fStack_da8;

                  auVar38._12_4_ = fStack_da4 * fStack_da4;

                  fStack_dd0 = auVar38._8_4_ + auVar38._4_4_ + auVar38._0_4_;

                  fVar22 = local_d70;

                  fVar21 = fStack_d6c;

                  fVar24 = fStack_d68;

                  fVar20 = fStack_d64;

                  if (_DAT_00a110e4 <= fStack_dd0) {

                    fVar23 = fStack_dbc * fStack_dbc;

                    fVar26 = fStack_db8 * fStack_db8;

                    fStack_de4 = fVar26 + fVar23 + fStack_dc0 * fStack_dc0;

                    if (_DAT_00a110e4 <= fStack_de4) {

                      auVar32._4_4_ = fVar23;

                      auVar32._0_4_ = fVar23;

                      auVar32._8_4_ = fVar23;

                      auVar32._12_4_ = fVar23;

                      auVar33._4_12_ = auVar32._4_12_;

                      auVar33._0_4_ = fVar23 + fStack_dc0 * fStack_dc0;

                      auVar6._4_4_ = fVar26;

                      auVar6._0_4_ = fVar26 + auVar33._0_4_;

                      auVar6._8_4_ = fVar26;

                      auVar6._12_4_ = fVar26;

                      auVar29 = rsqrtss(auVar33,auVar6);

                      fVar24 = auVar29._0_4_;

                      fVar24 = fVar24 * 0.5 * (3.0 - (fVar26 + auVar33._0_4_) * fVar24 * fVar24);

                      fStack_dc0 = fVar24 * fStack_dc0;

                      fStack_dbc = fVar24 * fStack_dbc;

                      fStack_db8 = fVar24 * fStack_db8;

                      fStack_db4 = fVar24 * fStack_db4;

                      fVar24 = auVar38._8_4_ + auVar38._4_4_ + auVar38._0_4_;

                      auVar7._4_4_ = auVar38._8_4_;

                      auVar7._0_4_ = fVar24;

                      auVar7._8_4_ = auVar38._8_4_;

                      auVar7._12_4_ = auVar38._8_4_;

                      auVar29 = rsqrtss(auVar38,auVar7);

                      fVar20 = auVar29._0_4_;

                      fVar24 = fVar20 * 0.5 * (3.0 - fVar24 * fVar20 * fVar20);

                      fStack_db0 = fVar24 * fStack_db0;

                      fStack_dac = fVar24 * fStack_dac;

                      fStack_da8 = fVar24 * fStack_da8;

                      fStack_da4 = fVar24 * fStack_da4;

                      fVar22 = fStack_dac * fStack_db8 - fStack_da8 * fStack_dbc;

                      fVar21 = fStack_da8 * fStack_dc0 - fStack_db0 * fStack_db8;

                      fVar24 = fStack_db0 * fStack_dbc - fStack_dac * fStack_dc0;

                      fVar20 = fStack_da4 * fStack_db4 - fStack_da4 * fStack_db4;

                    }

                  }

                }

              }

              fVar23 = fVar21 * fVar21;

              auVar34._8_4_ = fVar24 * fVar24;

              auVar39._4_4_ = fVar23;

              auVar39._0_4_ = fVar23;

              auVar39._8_4_ = fVar23;

              auVar39._12_4_ = fVar23;

              auVar40._4_12_ = auVar39._4_12_;

              auVar40._0_4_ = fVar23 + fVar22 * fVar22;

              auVar34._4_4_ = auVar34._8_4_;

              auVar34._0_4_ = auVar34._8_4_;

              auVar34._12_4_ = auVar34._8_4_;

              auVar35._4_12_ = auVar34._4_12_;

              auVar35._0_4_ = auVar34._8_4_ + auVar40._0_4_;

              auVar29 = rsqrtss(auVar40,auVar35);

              fVar23 = auVar29._0_4_;

              fVar23 = fVar23 * 0.5 * (3.0 - auVar35._0_4_ * fVar23 * fVar23);

              fStack_d80 = fVar23 * fVar22;

              fStack_d7c = fVar23 * fVar21;

              fStack_d78 = fVar23 * fVar24;

              fStack_d74 = fVar23 * fVar20;

            }

            local_d70 = fStack_d80;

            fStack_d6c = fStack_d7c;

            fStack_d68 = fStack_d78;

            fStack_d64 = fStack_d74;

            FUN_006bebe0(param_1,param_2,&fStack_d80,*(uint16_t *)(puVar16 + 3),*puVar16,pfVar18,

                         pfVar15,&puStack_c40);

            FUN_006bebe0(param_1,param_3,&fStack_d80,*(uint16_t *)(puVar16 + 3),puVar16[1],pfVar18

                         ,pfVar15,&puStack_a30);

            FUN_006bc6d0(local_dcc,puVar16,&puStack_c40,&puStack_a30,ppuVar11);

            if (-1 < iStack_a28) {

              (**(code **)(*DAT_00b05060 + 0x14))(puStack_a30,iStack_a28 << 3,0x12);

            }

            if (-1 < iStack_c38) {

              (**(code **)(*DAT_00b05060 + 0x14))(puStack_c40,iStack_c38 << 3,0x12);

            }

            iStack_de8 = iStack_de8 + 1;

            iStack_e0c = iStack_e0c + 0x14;

            iVar17 = local_dec;

          } while (iStack_de8 < (int)local_e34[1]);

        }

        if (1 < (int)ppuVar11[1]) {

          FUN_006bae10(*ppuVar11,0,ppuVar11[1] + -1,&LAB_006bacc0);

        }

        FUN_006bed00(param_2,param_3,ppuVar11,&local_820);

        uVar8 = local_d4c;

        if (local_81c != 0) break;

        local_e04 = local_e04 + 1;

        local_e34 = ppuVar11;

      }

    }

    while (uVar8 = uVar8 - 1, -1 < (int)uVar8) {

      uVar3 = (*(uint32_t /* width from decompiler */ **)(local_d50 + uVar8 * 4))[2];

      if (-1 < (int)uVar3) {

        (**(code **)(*DAT_00b05060 + 0x14))

                  (**(uint32_t /* width from decompiler */ **)(local_d50 + uVar8 * 4),(uVar3 & 0x7fffffff) * 0x14,0x12);

      }

      piVar9 = DAT_00b05060;

      if ((*(int *)(local_d50 + uVar8 * 4) == DAT_00b05060[5]) || (DAT_00b05060[5] == 0)) {

        (**(code **)(*DAT_00b05060 + 0x28))(*(int *)(local_d50 + uVar8 * 4),0x150);

      }

      else {

        piVar1 = DAT_00b05060 + 3;

        DAT_00b05060[2] = DAT_00b05060[2] + -0x150;

        piVar9[3] = *piVar1 + 0x150;

      }

    }

    local_d4c = 0;

    if (local_81c == 0) {

      if (-1 < local_818) {

        (**(code **)(*DAT_00b05060 + 0x14))(local_820,local_818 << 4,0x12);

      }

      if (-1 < (int)local_d48) {

        (**(code **)(*DAT_00b05060 + 0x14))(local_d50,local_d48 << 2,0x12);

      }

      if (-1 < (int)local_d98) {

        (**(code **)(*DAT_00b05060 + 0x14))(local_da0,(local_d98 & 0x7fffffff) * 0x14,0x12);

      }

      return 1;

    }

    FUN_006bdf50(param_2,param_3,&local_820,param_4);

    if (-1 < local_818) {

      (**(code **)(*DAT_00b05060 + 0x14))(local_820,local_818 << 4,0x12);

    }

    if (-1 < (int)local_d48) {

      (**(code **)(*DAT_00b05060 + 0x14))(local_d50,local_d48 << 2,0x12);

    }

    if (-1 < (int)local_d98) {

      (**(code **)(*DAT_00b05060 + 0x14))(local_da0,(local_d98 & 0x7fffffff) * 0x14,0x12);

    }

  }

  return 0;

}
