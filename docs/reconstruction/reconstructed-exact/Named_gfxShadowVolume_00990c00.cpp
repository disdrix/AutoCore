// READABILITY (auto CF):
//  - Body size: ~687 non-empty decompiler lines.
//  - Control keywords: if×44, return×8, for×6, do×4, while×4, goto×4.
//  - Notable callees: FUN_00443b40×9, CONCAT22×5, CONCAT31×5, FUN_00414a50×3, FUN_00414c20×2, FUN_00440110×2, FUN_0044ba80×2, FUN_004510e0×2.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp".
//  - Return sites: 8.

// =============================================================================
// Named_gfxShadowVolume_00990c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00990c00
// Address:   0x00990c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxShadowVolume"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_gfxShadowVolume_00990c00(int param_1,int param_2,int param_3)



{

  uint16_t uVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  float **ppfVar5;

  uint32_t /* width from decompiler */ uVar6;

  int extraout_EDX;

  int extraout_EDX_00;

  uint uVar7;

  uint extraout_EDX_01;

  int iVar8;

  float *pfVar9;

  uint uVar10;

  void *pvVar11;

  float *pfVar12;

  uint16_t uVar14;

  int *piVar13;

  int iVar15;

  float *pfVar16;

  uint16_t *puVar17;

  float10 fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float *local_220;

  uint local_21c;

  float *local_218 [2];

  void *local_210;

  uint16_t *local_20c;

  int local_208;

  int local_204;

  uint local_200;

  uint32_t /* width from decompiler */ *local_1fc;

  char local_1f8 [4];

  int local_1f4;

  uint8_t local_1f0 [4];

  float *local_1ec;

  uint32_t /* width from decompiler */ local_1e8;

  void *local_1e0;

  int local_1dc;

  uint32_t /* width from decompiler */ local_1d8;

  int local_1d4;

  float *local_1d0 [3];

  void *local_1c4 [2];

  float local_1bc;

  float *local_1b8 [2];

  int local_1b0;

  int local_1ac;

  uint32_t /* width from decompiler */ local_1a8;

  void *pvStack_1a4;

  void *pvStack_1a0;

  float fStack_19c;

  float *pfStack_198;

  float *pfStack_194;

  void *pvStack_18c;

  uint32_t /* width from decompiler */ uStack_188;

  uint32_t /* width from decompiler */ uStack_184;

  int local_180;

  float *local_17c;

  float *local_178;

  float local_174;

  float local_170;

  float local_16c;

  int local_168;

  uint32_t /* width from decompiler */ uStack_164;

  uint32_t /* width from decompiler */ uStack_160;

  uint32_t /* width from decompiler */ uStack_15c;

  void *pvStack_158;

  void *pvStack_154;

  float fStack_150;

  int local_148;

  int local_144;

  uint32_t /* width from decompiler */ local_140;

  float local_13c;

  float local_138;

  float local_134;

  float local_130;

  float local_12c;

  float local_128;

  void *local_124;

  void *local_120;

  float local_11c;

  int local_118;

  float *local_114;

  float local_110;

  float local_10c;

  float local_108;

  float afStack_104 [4];

  uint8_t local_f4 [4];

  uint32_t /* width from decompiler */ *local_f0;

  uint32_t /* width from decompiler */ local_ec;

  void *local_e8;

  uint32_t /* width from decompiler */ local_e4;

  uint32_t /* width from decompiler */ local_e0;

  int local_d8;

  uint32_t /* width from decompiler */ local_d4;

  uint32_t /* width from decompiler */ local_d0;

  float local_c4;

  float local_c0 [6];

  int aiStack_a8 [24];

  float local_48 [13];

  uint32_t /* width from decompiler */ uStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b21d4;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_1ec = (float *)FUN_00568f20();

  *(uint8_t *)((int)local_1ec + 0x49) = 1;

  local_1ec[1] = (float)local_1ec;

  *local_1ec = (float)local_1ec;

  local_1ec[2] = (float)local_1ec;

  local_1e8 = 0;

  local_148 = 0;

  local_144 = 0;

  local_140 = 0;

  local_210 = (void *)0x0;

  local_20c = (uint16_t *)0x0;

  local_208 = 0;

  local_4 = 2;

  iVar8 = *(int *)(param_1 + 4);

  if (*(int *)(iVar8 + 0x10) == 0) {

    iVar8 = 0;

  }

  else {

    iVar8 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar8 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar8 + 0x18),4);

  }

  iVar15 = *(int *)(param_2 + 4);

  local_168 = iVar8;

  if (*(int *)(iVar15 + 0x10) == 0) {

    local_1d4 = 0;

  }

  else {

    local_1d4 = FUN_00743be0(*(uint32_t /* width from decompiler */ *)(iVar15 + 0x18),*(uint32_t /* width from decompiler */ *)(iVar15 + 0x1c),0x810);

  }

  if ((iVar8 == 0) || (local_1d4 == 0)) {

    FUN_0044ba80();

    FUN_00414a50();

    local_4 = 0xffffffff;

    FUN_004549c0(&local_1f4,*local_1ec,local_1ec);

                    /* WARNING: Subroutine does not return */

    operator_delete(local_1ec);

  }

  local_d8 = 0;

  local_d4 = 0;

  local_d0 = 0;

  local_1b0 = 0;

  local_1ac = 0;

  local_1a8 = 0;

  pfVar9 = (float *)0x0;

  fVar18 = (float10)fcos((float10)*(float *)(DAT_00d1f048 + 0x18) * (float10)DAT_00a27c54);

  afStack_104[3] = (float)fVar18;

  for (; (local_220 = pfVar9, *(int *)(param_3 + 4) != 0 &&

         (pfVar9 < (float *)(*(int *)(param_3 + 8) - *(int *)(param_3 + 4) >> 3)));

      pfVar9 = (float *)((int)pfVar9 + 1)) {

    local_1e0 = (void *)0x0;

    local_1dc = 0;

    local_1d8 = 0;

    local_4 = CONCAT31(local_4._1_3_,5);

    FUN_00452050();

    iVar8 = *(int *)(*(int *)(param_3 + 4) + 4 + (int)pfVar9 * 8);

    piVar13 = *(int **)(iVar8 + 0x10);

    if (piVar13 == (int *)0x0) {

      pfVar12 = (float *)0x0;

    }

    else {

      piVar2 = (int *)*piVar13;

      if (piVar2 == (int *)0x0) {

        pfVar12 = (float *)0x0;

        pfVar9 = local_220;

      }

      else {

        iVar8 = (**(code **)(*piVar2 + 0x2c))

                          (piVar2,*(int *)(iVar8 + 0x14) * piVar13[2],

                           *(int *)(iVar8 + 0x18) * piVar13[2],local_1b8,0x800);

        pfVar9 = local_220;

        if (iVar8 < 0) {

          pfVar12 = (float *)0x0;

        }

        else {

          piVar13[4] = piVar13[4] + 1;

          pfVar12 = local_1b8[0];

        }

      }

    }

    if (pfVar12 != (float *)0x0) {

      local_220 = pfVar12;

      FUN_004406e0();

    }

    local_1e0 = (void *)0x0;

    local_1dc = 0;

    local_1d8 = 0;

  }

  if (*(int *)(param_2 + 4) == 0) {

    local_1b8[0] = (float *)0x0;

  }

  else {

    local_1b8[0] = *(float **)(*(int *)(param_2 + 4) + 0x1c);

  }

  local_200 = 0;

  if (0 < (int)local_1b8[0]) {

    local_118 = 1 - (int)&local_1fc;

    local_1f4 = 2 - (int)local_1f8;

    do {

      local_1e0 = (void *)0x0;

      local_1dc = 0;

      local_1d8 = 0;

      local_4._0_1_ = 6;

      local_218[0] = (float *)(local_1d4 + 2 + local_200 * 2);

      iVar15 = (uint)*(ushort *)(local_1d4 + 2 + local_200 * 2) * 0x10;

      pfVar16 = (float *)(iVar15 + local_168);

      iVar8 = (uint)*(ushort *)(local_1d4 + local_200 * 2) * 0x10;

      fVar23 = *(float *)(iVar15 + 8 + local_168) - *(float *)(iVar8 + 8 + local_168);

      fVar24 = *(float *)(iVar15 + 4 + local_168) - *(float *)(iVar8 + 4 + local_168);

      fVar19 = *(float *)(iVar15 + local_168) - *(float *)(iVar8 + local_168);

      pfVar12 = (float *)(iVar8 + local_168);

      iVar8 = (uint)*(ushort *)(local_1d4 + 4 + local_200 * 2) * 0x10;

      fVar21 = *(float *)(iVar8 + 8 + local_168) - pfVar12[2];

      fVar22 = *(float *)(iVar8 + 4 + local_168) - pfVar12[1];

      fVar20 = *(float *)(iVar8 + local_168) - *pfVar12;

      pfVar9 = (float *)(iVar8 + local_168);

      local_124 = (void *)(fVar24 * fVar21 - fVar23 * fVar22);

      local_120 = (void *)(fVar20 * fVar23 - fVar19 * fVar21);

      local_11c = fVar19 * fVar22 - fVar20 * fVar24;

      local_220 = (float *)SQRT((float)local_120 * (float)local_120 +

                                local_11c * local_11c + (float)local_124 * (float)local_124);

      if ((_DAT_00a240ec <= (float)local_220) ||

         (local_1c4[0] = local_124, local_1c4[1] = local_120, local_1bc = local_11c,

         (float)local_220 <= DAT_00aaa640)) {

        local_1bc = g_flOne / (float)local_220;

        local_1c4[0] = (void *)((float)local_124 * local_1bc);

        local_1c4[1] = (void *)(local_1bc * (float)local_120);

        local_1bc = local_1bc * local_11c;

      }

      local_1d0[0] = pfVar12;

      local_1d0[1] = pfVar16;

      local_1d0[2] = pfVar9;

      for (local_21c = 0; (local_1b0 != 0 && (local_21c < (uint)(local_1ac - local_1b0 >> 4)));

          local_21c = local_21c + 1) {

        iVar8 = *(int *)(local_d8 + local_21c * 4);

        local_180 = (uint)*(ushort *)(local_1d4 + local_200 * 2) * 0x10;

        fVar22 = *(float *)(local_180 + iVar8) + *pfVar12;

        fVar23 = *(float *)(local_180 + 4 + iVar8) + pfVar12[1];

        local_c4 = *(float *)(local_180 + 8 + iVar8) + pfVar12[2];

        local_180 = local_180 + iVar8;

        local_17c = (float *)((uint)*(ushort *)local_218[0] * 0x10 + iVar8);

        local_178 = (float *)((uint)*(ushort *)(local_1d4 + 4 + local_200 * 2) * 0x10 + iVar8);

        fVar19 = (*local_178 + *pfVar9) - fVar22;

        fVar21 = (local_178[2] + pfVar9[2]) - local_c4;

        fVar24 = (local_17c[2] + pfVar16[2]) - local_c4;

        fVar22 = (*local_17c + *pfVar16) - fVar22;

        fVar20 = (local_178[1] + pfVar9[1]) - fVar23;

        fVar23 = (local_17c[1] + pfVar16[1]) - fVar23;

        local_110 = fVar23 * fVar21 - fVar24 * fVar20;

        local_108 = fVar22 * fVar20 - fVar19 * fVar23;

        local_10c = fVar19 * fVar24 - fVar22 * fVar21;

        local_220 = (float *)SQRT(local_110 * local_110 +

                                  local_10c * local_10c + local_108 * local_108);

        if ((_DAT_00a240ec <= (float)local_220) ||

           (local_174 = local_110, local_170 = local_10c, local_16c = local_108,

           (float)local_220 <= DAT_00aaa640)) {

          local_16c = g_flOne / (float)local_220;

          local_174 = local_110 * local_16c;

          local_170 = local_16c * local_10c;

          local_16c = local_16c * local_108;

        }

        FUN_004520b0();

      }

      _eh_vector_constructor_iterator_

                (local_c0,0x24,3,(_func_void_void_ptr *)&LAB_00451040,FUN_00451050);

      local_4 = CONCAT31(local_4._1_3_,7);

      local_218[0] = local_48;

      local_21c = 0;

      local_204 = 0;

      pfVar9 = local_1ec;

      do {

        iVar8 = local_204;

        pfVar12 = local_1d0[local_204];

        local_218[0][-3] = *pfVar12;

        fVar19 = pfVar12[2];

        local_218[0][-2] = pfVar12[1];

        local_218[0][-1] = fVar19;

        pfVar16 = local_1d0[(int)(local_1f8 + local_118 + local_204 + -4) % 3];

        *local_218[0] = *pfVar16;

        fVar19 = pfVar16[2];

        local_218[0][1] = pfVar16[1];

        local_218[0][2] = fVar19;

        local_13c = *pfVar16;

        local_138 = pfVar16[1];

        local_134 = pfVar16[2];

        local_130 = *pfVar12;

        local_12c = pfVar12[1];

        local_128 = pfVar12[2];

        local_220 = (float *)FUN_00454c10();

        if (((local_220 == pfVar9) || (local_13c < local_220[3])) ||

           ((local_13c <= local_220[3] &&

            ((local_138 < local_220[4] ||

             ((local_138 <= local_220[4] &&

              ((local_134 < local_220[5] ||

               ((local_134 <= local_220[5] &&

                ((local_130 < local_220[6] ||

                 ((local_130 <= local_220[6] &&

                  ((local_12c < local_220[7] ||

                   ((local_12c <= local_220[7] && (local_128 < local_220[8])))))))))))))))))))) {

          local_114 = pfVar9;

          ppfVar5 = &local_114;

        }

        else {

          ppfVar5 = &local_220;

        }

        pfVar12 = *ppfVar5;

        if (pfVar12 == pfVar9) {

          local_1f8[iVar8] = '\0';

        }

        else {

          pfVar9 = (float *)((int)local_c0 + local_21c);

          *pfVar9 = pfVar12[9];

          *(float *)((int)local_c0 + local_21c + 4) = pfVar12[10];

          *(float *)((int)local_c0 + local_21c + 8) = pfVar12[0xb];

          *(float *)((int)local_c0 + local_21c + 0xc) = pfVar12[0xc];

          *(float *)((int)local_c0 + local_21c + 0x10) = pfVar12[0xd];

          FUN_004510e0();

          iVar8 = local_204;

          local_1f8[local_204] = '\x01';

          FUN_00451d10(local_1f0,&local_220,pfVar12);

          local_1f8[iVar8 + -4] = '\0';

          fVar19 = afStack_104[3];

          pvVar11 = local_1e0;

          if (afStack_104[3] <=

              *(float *)((int)local_c0 + local_21c + 8) * local_1bc +

              *(float *)((int)local_c0 + local_21c + 4) * (float)local_1c4[1] +

              *pfVar9 * (float)local_1c4[0]) {

            iVar8 = 0;

            pfVar12 = (float *)((int)local_1e0 + 0x10);

            for (uVar7 = 0;

                (pfVar9 = local_1ec, pvVar11 != (void *)0x0 &&

                (uVar7 < (uint)((local_1dc - (int)pvVar11) / 0x18))); uVar7 = uVar7 + 1) {

              iVar15 = *(int *)((int)local_c0 + local_21c + 0x18);

              if (pfVar12[1] * *(float *)(iVar15 + 8 + iVar8) +

                  pfVar12[-1] * *(float *)(iVar15 + iVar8) +

                  *(float *)(iVar15 + iVar8 + 4) * *pfVar12 < fVar19) {

                local_1f8[local_204 + -4] = '\x01';

              }

              iVar8 = iVar8 + 0xc;

              pfVar12 = pfVar12 + 6;

            }

          }

          else {

            local_1f8[iVar8 + -4] = '\x01';

            pfVar9 = local_1ec;

          }

        }

        local_204 = local_204 + 1;

        local_218[0] = local_218[0] + 6;

        local_21c = local_21c + 0x24;

      } while ((int)local_21c < 0x6c);

      local_21c = 0;

      local_204 = -0xc;

      local_220 = local_c0 + 4;

      pvVar11 = local_210;

      do {

        puVar17 = local_20c;

        iVar8 = (int)(local_1f8 + local_21c + local_1f4) % 3;

        if ((local_1f8[local_21c] == '\0') || (local_1f8[local_21c + -4] != '\0')) {

          if ((local_1f8[iVar8] == '\0') || (local_1f8[iVar8 + -4] != '\0')) {

            fVar19 = 0.0;

            if (local_148 != 0) {

              fVar19 = (float)((local_144 - local_148) / 0x18);

            }

            afStack_104[local_21c] = fVar19;

            puVar3 = *(uint32_t /* width from decompiler */ **)((int)local_1c4 + local_204);

            uStack_164 = *puVar3;

            uStack_160 = puVar3[1];

            uStack_15c = puVar3[2];

            pvStack_158 = local_1c4[0];

            fStack_150 = local_1bc;

            pvStack_154 = local_1c4[1];

            FUN_00451fd0();

            pfVar9 = (float *)((int)local_1e0 + 0xc);

            iVar15 = extraout_EDX;

            for (local_218[0] = (float *)0x0;

                (local_1b0 != 0 && (local_218[0] < (float *)(local_1ac - local_1b0 >> 4)));

                local_218[0] = (float *)((int)local_218[0] + 1)) {

              puVar3 = *(uint32_t /* width from decompiler */ **)(local_204 + (int)pfVar9);

              uStack_164 = *puVar3;

              uStack_160 = puVar3[1];

              uStack_15c = puVar3[2];

              pvStack_158 = (void *)*pfVar9;

              pvStack_154 = (void *)pfVar9[1];

              fStack_150 = pfVar9[2];

              FUN_00451fd0();

              pfVar9 = pfVar9 + 6;

              iVar15 = extraout_EDX_00;

            }

          }

          else {

            iVar15 = iVar8 * 9;

            afStack_104[local_21c] = local_c0[iVar8 * 9 + 3];

          }

        }

        else {

          afStack_104[local_21c] = *local_220;

          iVar15 = iVar8;

        }

        local_218[0] = (float *)CONCAT22((short)((uint)iVar15 >> 0x10),

                                         *(uint16_t *)(afStack_104 + local_21c));

        if ((pvVar11 == (void *)0x0) ||

           ((uint)(local_208 - (int)pvVar11 >> 1) <= (uint)((int)puVar17 - (int)pvVar11 >> 1))) {

          FUN_00443b40(puVar17,1,local_218);

          pvVar11 = local_210;

        }

        else {

          *puVar17 = *(uint16_t *)(afStack_104 + local_21c);

          local_20c = puVar17 + 1;

        }

        local_21c = local_21c + 1;

        local_220 = local_220 + 9;

        local_204 = local_204 + 4;

      } while (local_204 < 0);

      uVar7 = 0;

      puVar17 = local_20c;

      do {

        pvStack_18c = (void *)0x0;

        uStack_188 = 0;

        uStack_184 = 0;

        local_4 = CONCAT31(local_4._1_3_,8);

        pfStack_198 = (float *)afStack_104[uVar7];

        local_21c = uVar7 + 1;

        pvStack_1a4 = local_1c4[0];

        fStack_19c = local_1bc;

        pvStack_1a0 = local_1c4[1];

        local_220 = (float *)((int)local_1e0 + 0xc);

        pfStack_194 = (float *)afStack_104[(int)(uVar7 + 1) % 3];

        for (uVar10 = 0;

            (local_1e0 != (void *)0x0 && (uVar10 < (uint)((local_1dc - (int)local_1e0) / 0x18)));

            uVar10 = uVar10 + 1) {

          FUN_00451230(local_220);

          local_220 = local_220 + 6;

        }

        if (local_1f8[uVar7] == '\0') {

          pfVar9 = (float *)FUN_00451bf0(local_1f0);

          *pfVar9 = (float)pvStack_1a4;

          pfVar9[1] = (float)pvStack_1a0;

          pfVar9[2] = fStack_19c;

          pfVar9[3] = (float)pfStack_198;

          pfVar9[4] = (float)pfStack_194;

          FUN_004510e0();

        }

        else {

          pfVar9 = local_c0 + uVar7 * 9 + 4;

          local_220 = pfVar9;

          if ((float *)local_c0[uVar7 * 9 + 4] == pfStack_198) {

LAB_009919f5:

            pfVar9 = local_c0 + uVar7 * 9 + 3;

            if ((float *)local_c0[uVar7 * 9 + 3] != pfStack_194) {

LAB_00991a09:

              if ((pvVar11 == (void *)0x0) ||

                 ((uint)(local_208 - (int)pvVar11 >> 1) <= (uint)((int)puVar17 - (int)pvVar11 >> 1))

                 ) {

                local_220 = pfStack_194;

                FUN_00443b40(puVar17,1,&local_220);

                pvVar11 = local_210;

              }

              else {

                *puVar17 = (short)pfStack_194;

                local_20c = puVar17 + 1;

              }

              local_220 = pfStack_198;

              if ((pvVar11 == (void *)0x0) ||

                 (uVar7 = local_208 - (int)pvVar11 >> 1,

                 uVar7 <= (uint)((int)local_20c - (int)pvVar11 >> 1))) {

                FUN_00443b40(local_20c,1,&local_220);

                uVar7 = extraout_EDX_01;

                pvVar11 = local_210;

              }

              else {

                *local_20c = (short)pfStack_198;

                local_20c = local_20c + 1;

              }

              local_220 = (float *)CONCAT22((short)(uVar7 >> 0x10),*(uint16_t *)pfVar9);

              if ((pvVar11 == (void *)0x0) ||

                 ((uint)(local_208 - (int)pvVar11 >> 1) <=

                  (uint)((int)local_20c - (int)pvVar11 >> 1))) goto LAB_00991ab7;

              *local_20c = *(uint16_t *)pfVar9;

              puVar17 = local_20c + 1;

              local_20c = puVar17;

            }

          }

          else {

            if ((float *)local_c0[uVar7 * 9 + 3] == pfStack_194) {

              if ((float *)local_c0[uVar7 * 9 + 4] == pfStack_198) goto LAB_009919f5;

              goto LAB_00991a09;

            }

            if ((pvVar11 == (void *)0x0) ||

               ((uint)(local_208 - (int)pvVar11 >> 1) <= (uint)((int)puVar17 - (int)pvVar11 >> 1)))

            {

              local_218[0] = pfStack_194;

              FUN_00443b40(puVar17,1,local_218);

              pvVar11 = local_210;

            }

            else {

              *puVar17 = (short)pfStack_194;

              local_20c = puVar17 + 1;

            }

            pfVar9 = pfStack_198;

            local_218[0] = pfStack_198;

            if ((pvVar11 == (void *)0x0) ||

               ((uint)(local_208 - (int)pvVar11 >> 1) <= (uint)((int)local_20c - (int)pvVar11 >> 1))

               ) {

              FUN_00443b40(local_20c,1,local_218);

              pvVar11 = local_210;

            }

            else {

              *local_20c = (short)pfStack_198;

              local_20c = local_20c + 1;

            }

            uVar1 = *(uint16_t *)(local_c0 + uVar7 * 9 + 3);

            uVar14 = (uint16_t)((uint)pfVar9 >> 0x10);

            local_218[0] = (float *)CONCAT22(uVar14,uVar1);

            if ((pvVar11 == (void *)0x0) ||

               ((uint)(local_208 - (int)pvVar11 >> 1) <= (uint)((int)local_20c - (int)pvVar11 >> 1))

               ) {

              FUN_00443b40(local_20c,1,local_218);

              pvVar11 = local_210;

            }

            else {

              *local_20c = uVar1;

              local_20c = local_20c + 1;

            }

            uVar1 = *(uint16_t *)local_220;

            local_220 = (float *)CONCAT22(uVar14,uVar1);

            if ((pvVar11 == (void *)0x0) ||

               ((uint)(local_208 - (int)pvVar11 >> 1) <= (uint)((int)local_20c - (int)pvVar11 >> 1))

               ) {

              FUN_00443b40(local_20c,1,&local_220);

              pvVar11 = local_210;

            }

            else {

              *local_20c = uVar1;

              local_20c = local_20c + 1;

            }

            uVar1 = *(uint16_t *)(local_c0 + uVar7 * 9 + 3);

            local_220 = (float *)CONCAT22(uVar14,uVar1);

            if ((pvVar11 == (void *)0x0) ||

               ((uint)(local_208 - (int)pvVar11 >> 1) <= (uint)((int)local_20c - (int)pvVar11 >> 1))

               ) {

              FUN_00443b40(local_20c,1,&local_220);

              pvVar11 = local_210;

            }

            else {

              *local_20c = uVar1;

              local_20c = local_20c + 1;

            }

            local_220 = pfStack_198;

            if ((pvVar11 != (void *)0x0) &&

               ((uint)((int)local_20c - (int)pvVar11 >> 1) < (uint)(local_208 - (int)pvVar11 >> 1)))

            {

              *local_20c = pfStack_198._0_2_;

              local_20c = local_20c + 1;

              puVar17 = local_20c;

              goto LAB_00991ad0;

            }

LAB_00991ab7:

            FUN_00443b40(local_20c,1,&local_220);

            pvVar11 = local_210;

            puVar17 = local_20c;

          }

        }

LAB_00991ad0:

        if (pvStack_18c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvStack_18c);

        }

        pvStack_18c = (void *)0x0;

        uStack_188 = 0;

        uStack_184 = 0;

        uVar7 = local_21c;

      } while ((int)local_21c < 3);

      local_4 = CONCAT31(local_4._1_3_,6);

      _eh_vector_destructor_iterator_(local_c0,0x24,3,FUN_00451050);

      if (local_1e0 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(local_1e0);

      }

      local_200 = local_200 + 3;

      local_1e0 = (void *)0x0;

      local_1dc = 0;

      local_1d8 = 0;

    } while ((int)local_200 < (int)local_1b8[0]);

  }

  local_f0 = (uint32_t /* width from decompiler */ *)0x0;

  local_ec = 0;

  local_e8 = (void *)0x0;

  local_e4 = 0;

  local_e0 = 0;

  local_4 = CONCAT31(local_4._1_3_,9);

  FUN_0044c3c0(0,0);

  *local_f0 = DAT_00a242d0;

  local_f0[1] = DAT_00a242d4;

  local_f0[2] = DAT_00a242d8;

  local_f0[3] = DAT_00a242dc;

  local_f0[4] = DAT_00a242e0;

  local_f0[5] = DAT_00a242e4;

  FUN_00746d00();

  FUN_00414a50();

  iVar8 = local_148;

  if (local_148 == 0) {

    iVar15 = 0;

  }

  else {

    iVar15 = (local_144 - local_148) / 0x18;

  }

  FUN_00414c20(iVar15,local_f4,8,0);

  FUN_00440110(iVar8,0,0);

  piVar13 = (int *)(local_1b0 + 4);

  for (local_200 = 0;

      (*(int *)(param_3 + 4) != 0 &&

      (local_200 < (uint)(*(int *)(param_3 + 8) - *(int *)(param_3 + 4) >> 3)));

      local_200 = local_200 + 1) {

    FUN_00414a50();

    iVar8 = 0;

    if (*piVar13 != 0) {

      iVar8 = (piVar13[1] - *piVar13) / 0x18;

    }

    FUN_00414c20(iVar8,local_f4,8,0);

    FUN_00440110(*piVar13,0,0);

    piVar13 = piVar13 + 4;

  }

  FUN_0044ba80();

  pvVar11 = local_210;

  if (local_210 == (void *)0x0) {

    iVar8 = 0;

  }

  else {

    iVar8 = (int)local_20c - (int)local_210 >> 1;

  }

  FUN_0044b9c0(iVar8,8,0,0);

  FUN_0044bad0(pvVar11,0);

  if (*(int *)(param_2 + 4) == 0) {

    iVar8 = 0;

  }

  else {

    iVar8 = *(int *)(*(int *)(param_2 + 4) + 0x1c);

  }

  if (*(int *)(param_1 + 4) == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 0x18);

  }

  uVar6 = FUN_0076cec0(&local_204,"After adding degenerate quads at sharp edges: %d verts, %d faces"

                       ,uVar6,iVar8 / 3);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x6b5,1,uVar6)

  ;

  FUN_00414b60();

  pvVar4 = local_1c4[1];

  if (local_1c4[1] != (void *)0x0) {

    FUN_00426f20(local_204);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar4);

  }

  if (local_e8 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_e8);

  }

  if (pvVar11 == (void *)0x0) {

    if (pvStack_158 == (void *)0x0) {

      uStack_14 = 0xffffffff;

      FUN_004549c0(&local_204,*local_1fc,local_1fc);

                    /* WARNING: Subroutine does not return */

      operator_delete(local_1fc);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(pvStack_158);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar11);

}
