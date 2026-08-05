// =============================================================================
// FUN_00692090
// -----------------------------------------------------------------------------
// Stable ID: aa_00692090
// Address:   0x00692090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00692090 @ 0x00692090
// Stable ID: aa_00692090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~497 non-empty decompiler lines.
//  - Control keywords: if×28, return×4, do×3, while×3, for×2, goto×1.
//  - Notable callees: FUN_0068bac0×4, FUN_0068c910×4, SQRT×3, FUN_004490a0×2, FUN_0068bad0×2, FUN_0068c650×2, FUN_0068c6f0×2, FUN_0068c830×2.
//  - Return sites: 4.

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



void __thiscall FUN_00692090(int *param_1,int param_2)



{

  int iVar1;

  float fVar2;

  int *piVar3;

  int iVar4;

  uint uVar5;

  float *pfVar6;

  float *pfVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  uint uVar10;

  float *local_244;

  int local_240;

  float local_23c;

  float local_238;

  float local_234;

  float local_230;

  float local_22c;

  float local_228;

  float local_224;

  float local_220;

  float local_21c;

  float local_218;

  float local_214;

  float local_210;

  float local_20c;

  float local_208;

  float local_204;

  float local_200;

  float local_1fc;

  float local_1f8;

  float local_1f4;

  uint local_1f0;

  void *local_1e8;

  float *local_1e4;

  int local_1e0;

  float local_1dc;

  float local_1d8;

  float local_1d4;

  float local_1d0;

  float local_1cc;

  float local_1c8;

  float *local_1c0;

  float *local_1bc;

  int local_1b8;

  int *local_1b4;

  uint32_t /* width from decompiler */ local_1b0;

  float local_1ac;

  void *local_1a4;

  uint32_t /* width from decompiler */ local_1a0;

  uint32_t /* width from decompiler */ local_19c;

  float local_198;

  float local_194;

  float local_190;

  float local_18c;

  float local_188;

  float local_184;

  float local_180;

  float local_17c;

  float local_178;

  float local_174;

  float local_170;

  float local_16c;

  float local_168;

  float local_164;

  float local_160;

  float local_15c;

  float local_158;

  float local_154;

  float local_150;

  float local_14c;

  float local_148;

  float local_144;

  float local_140;

  float local_13c;

  float local_138;

  float local_134;

  float local_130;

  float local_12c;

  float local_128;

  float local_124;

  float local_120;

  float local_11c;

  float local_118;

  float local_114;

  float local_110;

  float local_10c;

  float local_108;

  float local_104;

  float local_100;

  uint32_t /* width from decompiler */ local_fc;

  float local_f8;

  uint32_t /* width from decompiler */ local_f4;

  float local_f0;

  float local_e8;

  float local_e4;

  float local_e0;

  float local_d4;

  float local_c4;

  float local_c0;

  float local_b8;

  float local_b4;

  float local_ac;

  float local_a8;

  float local_a0;

  float local_9c;

  float local_94;

  float local_90;

  float local_88;

  float local_84;

  float local_80 [4];

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_58;

  float local_54;

  float local_48;

  float local_3c;

  uint8_t local_38 [16];

  uint8_t local_28 [20];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  puStack_10 = &LAB_009aa781;

  local_14 = ExceptionList;

  if ((*param_1 != 0) && (param_1[1] != 0)) {

    local_12c = (float)param_1[0xb];

    if (param_1[0xb] < 0) {

      local_12c = local_12c + _DAT_00aaa5dc;

    }

    local_12c = _DAT_009eb1bc / local_12c;

    ExceptionList = &local_14;

    *(uint *)(param_2 + 0x28) = (uint)*(ushort *)(*param_1 + 0x1a);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c) = 2;

    local_1f0 = 0;

    local_1b4 = param_1;

    if (param_1[0xb] != 0) {

      do {

        local_200 = (float)(uint)*(ushort *)(*param_1 + 0x1a);

        local_1a4 = (void *)0x0;

        local_1a0 = 0;

        local_19c = 0;

        local_c = 0;

        for (local_244 = (float *)0x0;

            (iVar4 = *(int *)(param_2 + 4), iVar4 != 0 &&

            (uVar5 = (*(int *)(param_2 + 8) - iVar4) / 0x38, local_244 < uVar5));

            local_244 = (float *)((int)local_244 + 1)) {

          if (local_244 < uVar5 - 1) {

            iVar1 = (int)local_244 * 0x38 + 0xc;

          }

          else {

            iVar1 = (int)local_244 * 0x38 + -0x2c;

          }

          fVar2 = (float)(int)local_1f0;

          pfVar6 = (float *)(iVar1 + iVar4);

          pfVar7 = local_80;

          for (iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {

            *pfVar7 = *pfVar6;

            pfVar6 = pfVar6 + 1;

            pfVar7 = pfVar7 + 1;

          }

          if ((int)local_1f0 < 0) {

            fVar2 = fVar2 + _DAT_00aaa5dc;

          }

          FUN_0068eba0(fVar2 * local_12c + *(float *)(param_2 + 0x1c));

          local_230 = (local_68 + local_80[0]) * g_flZero + local_80[3];

          local_22c = (local_64 + local_80[1]) * g_flZero + local_70;

          local_228 = (local_60 + local_80[2]) * g_flZero + local_6c;

          FUN_00691940(&local_230);

          piVar3 = local_1b4;

          pfVar6 = *(float **)(param_2 + 4);

          if (local_244 == (float *)0x0) {

            local_23c = pfVar6[0xe] - *pfVar6;

            local_238 = pfVar6[0xf] - pfVar6[1];

            local_234 = pfVar6[0x10] - pfVar6[2];

            local_174 = local_23c;

            local_170 = local_238;

            local_16c = local_234;

          }

          else {

            local_23c = pfVar6[(int)local_244 * 0xe] - *pfVar6;

            local_238 = pfVar6[(int)local_244 * 0xe + 1] - pfVar6[1];

            local_234 = pfVar6[(int)local_244 * 0xe + 2] - pfVar6[2];

            local_114 = local_23c;

            local_110 = local_238;

            local_10c = local_234;

          }

          fVar2 = g_flOne / SQRT(local_234 * local_234 +

                                 local_238 * local_238 + local_23c * local_23c);

          local_23c = local_23c * fVar2;

          local_238 = local_238 * fVar2;

          local_234 = local_234 * fVar2;

          if (pfVar6 == (float *)0x0) {

            iVar4 = 0;

          }

          else {

            iVar4 = (*(int *)(param_2 + 8) - (int)pfVar6) / 0x38;

          }

          if (((local_244 == (float *)(iVar4 - 1U)) && (pfVar6 != (float *)0x0)) &&

             (local_224 = (float)((*(int *)(param_2 + 8) - (int)pfVar6) / 0x38), local_224 != 0.0))

          {

            fVar2 = *(float *)(param_2 + 0x14);

            pfVar7 = (float *)((int)local_1a4 + (int)local_244 * 0xc + -0xc);

            local_88 = fVar2 * pfVar7[1];

            local_84 = fVar2 * pfVar7[2];

            local_220 = fVar2 * *(float *)((int)local_1a4 + (int)local_244 * 0xc + -0xc) +

                        pfVar6[(int)local_244 * 0xe];

            local_21c = local_88 + pfVar6[(int)local_244 * 0xe + 1];

            local_218 = local_84 + pfVar6[(int)local_244 * 0xe + 2];

            fVar2 = *(float *)(param_2 + 0x14);

            local_a0 = fVar2 * pfVar7[1];

            local_9c = fVar2 * pfVar7[2];

            local_214 = pfVar6[(int)local_244 * 0xe] - fVar2 * *pfVar7;

            local_210 = pfVar6[(int)local_244 * 0xe + 1] - local_a0;

            local_20c = pfVar6[(int)local_244 * 0xe + 2] - local_9c;

            local_198 = local_214;

            local_194 = local_210;

            local_190 = local_20c;

            local_15c = local_220;

            local_158 = local_21c;

            local_154 = local_218;

          }

          else {

            if (local_244 != (float *)0x0) {

              if (pfVar6 == (float *)0x0) {

                iVar4 = 0;

              }

              else {

                iVar4 = (*(int *)(param_2 + 8) - (int)pfVar6) / 0x38;

              }

              if (local_244 < iVar4 - 1U) {

                fVar2 = *(float *)(param_2 + 0x14);

                pfVar7 = (float *)((int)local_1a4 + (int)local_244 * 0xc + -0xc);

                local_e8 = fVar2 * pfVar7[1];

                local_e4 = fVar2 * pfVar7[2];

                local_144 = fVar2 * *(float *)((int)local_1a4 + (int)local_244 * 0xc + -0xc) +

                            pfVar6[(int)local_244 * 0xe];

                local_140 = local_e8 + pfVar6[(int)local_244 * 0xe + 1];

                local_13c = local_e4 + pfVar6[(int)local_244 * 0xe + 2];

                fVar2 = *(float *)(param_2 + 0x14);

                local_58 = local_22c * fVar2;

                local_54 = local_228 * fVar2;

                local_108 = local_230 * fVar2 + pfVar6[(int)local_244 * 0xe];

                local_104 = local_58 + pfVar6[(int)local_244 * 0xe + 1];

                local_100 = local_54 + pfVar6[(int)local_244 * 0xe + 2];

                local_48 = local_13c + local_100;

                local_220 = (local_144 + local_108) * DAT_00a0f298;

                local_21c = (local_140 + local_104) * DAT_00a0f298;

                local_218 = local_48 * DAT_00a0f298;

                fVar2 = *(float *)(param_2 + 0x14);

                local_b8 = fVar2 * pfVar7[1];

                local_b4 = fVar2 * pfVar7[2];

                local_1fc = pfVar6[(int)local_244 * 0xe] - fVar2 * *pfVar7;

                local_1f8 = pfVar6[(int)local_244 * 0xe + 1] - local_b8;

                local_1f4 = pfVar6[(int)local_244 * 0xe + 2] - local_b4;

                fVar2 = *(float *)(param_2 + 0x14);

                local_c4 = local_22c * fVar2;

                local_c0 = local_228 * fVar2;

                local_168 = pfVar6[(int)local_244 * 0xe] - local_230 * fVar2;

                local_164 = pfVar6[(int)local_244 * 0xe + 1] - local_c4;

                local_160 = pfVar6[(int)local_244 * 0xe + 2] - local_c0;

                local_3c = local_1f4 + local_160;

                local_214 = (local_1fc + local_168) * DAT_00a0f298;

                local_210 = (local_1f8 + local_164) * DAT_00a0f298;

                local_20c = local_3c * DAT_00a0f298;

                local_18c = local_220;

                local_188 = local_21c;

                local_184 = local_218;

                local_180 = local_1fc;

                local_17c = local_1f8;

                local_178 = local_1f4;

                local_150 = local_214;

                local_14c = local_210;

                local_148 = local_20c;

                goto LAB_00692877;

              }

            }

            fVar2 = *(float *)(param_2 + 0x14);

            local_94 = local_22c * fVar2;

            local_90 = local_228 * fVar2;

            local_220 = local_230 * fVar2 + pfVar6[(int)local_244 * 0xe];

            local_21c = local_94 + pfVar6[(int)local_244 * 0xe + 1];

            local_218 = local_90 + pfVar6[(int)local_244 * 0xe + 2];

            fVar2 = *(float *)(param_2 + 0x14);

            local_ac = local_22c * fVar2;

            local_a8 = local_228 * fVar2;

            local_214 = pfVar6[(int)local_244 * 0xe] - local_230 * fVar2;

            local_210 = pfVar6[(int)local_244 * 0xe + 1] - local_ac;

            local_20c = pfVar6[(int)local_244 * 0xe + 2] - local_a8;

            local_138 = local_220;

            local_134 = local_21c;

            local_130 = local_218;

            local_128 = local_214;

            local_124 = local_210;

            local_120 = local_20c;

          }

LAB_00692877:

          if (pfVar6 == (float *)0x0) {

            local_240 = 0;

          }

          else {

            local_240 = (*(int *)(param_2 + 8) - (int)pfVar6) / 0x38;

          }

          FUN_0068c6f0(&local_220);

          local_1ac = (float)(int)local_244;

          local_1b0 = 0x3f800000;

          if ((int)local_244 < 0) {

            local_1ac = local_1ac + _DAT_00aaa5dc;

          }

          fVar2 = (float)local_240;

          if (local_240 < 0) {

            fVar2 = fVar2 + _DAT_00aaa5dc;

          }

          local_1ac = local_1ac / (fVar2 - g_flOne);

          FUN_0068c910(&local_1b0,*(uint8_t *)(param_2 + 0x18));

          if (*(int *)(piVar3[1] + 0x78) == 1) {

            FUN_0069ddf0(&local_23c,&local_220,local_28,2);

            FUN_0068c650(local_28);

          }

          else {

            FUN_0068c830(&local_23c);

            FUN_0068cb80(&local_230);

            local_1dc = local_234 * local_22c - local_238 * local_228;

            local_1d8 = local_228 * local_23c - local_234 * local_230;

            local_1d4 = local_238 * local_230 - local_22c * local_23c;

            if (_DAT_009eb1b8 <=

                (float)(((int)(local_1dc * local_1dc + local_1d8 * local_1d8 + local_1d4 * local_1d4

                              ) >> 1) + 0x1fc00000)) {

              fVar2 = g_flOne / SQRT(local_1dc * local_1dc + local_1d8 * local_1d8 +

                                     local_1d4 * local_1d4);

              local_1dc = fVar2 * local_1dc;

              local_1d8 = local_1d8 * fVar2;

              local_1d4 = local_1d4 * fVar2;

            }

            else {

              local_1dc = local_23c;

              local_1d8 = local_238;

              local_1d4 = local_234;

            }

            FUN_0068cc90(&local_1dc);

          }

          if (*(char *)(*piVar3 + 8) != '\0') {

            iVar4 = *(int *)(param_2 + 4) + (int)local_244 * 0x38;

            FUN_0068cac0(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x30),*(uint8_t *)(iVar4 + 0x34));

          }

          *(short *)(*piVar3 + 0x1a) = *(short *)(*piVar3 + 0x1a) + 1;

          FUN_0068c6f0(&local_214);

          local_1b0 = 0;

          FUN_0068c910(&local_1b0,*(uint8_t *)(param_2 + 0x18));

          if (*(int *)(piVar3[1] + 0x78) == 1) {

            FUN_0069ddf0(&local_23c,&local_214,local_38,2);

            FUN_0068c650(local_38);

          }

          else {

            FUN_0068c830(&local_23c);

            FUN_0068cb80(&local_230);

            local_1d0 = local_234 * local_22c - local_238 * local_228;

            local_1cc = local_228 * local_23c - local_234 * local_230;

            local_1c8 = local_238 * local_230 - local_22c * local_23c;

            if (_DAT_009eb1b8 <=

                (float)(((int)(local_1cc * local_1cc + local_1c8 * local_1c8 + local_1d0 * local_1d0

                              ) >> 1) + 0x1fc00000)) {

              fVar2 = g_flOne / SQRT(local_1cc * local_1cc + local_1c8 * local_1c8 +

                                     local_1d0 * local_1d0);

              local_1d0 = fVar2 * local_1d0;

              local_1cc = local_1cc * fVar2;

              local_1c8 = local_1c8 * fVar2;

            }

            else {

              local_1d0 = local_23c;

              local_1cc = local_238;

              local_1c8 = local_234;

            }

            FUN_0068cc90(&local_1d0);

          }

          if (*(char *)(*piVar3 + 8) != '\0') {

            iVar4 = (int)local_244 * 0x38 + *(int *)(param_2 + 4);

            FUN_0068cac0(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x30),*(uint8_t *)(iVar4 + 0x34));

          }

          *(short *)(*piVar3 + 0x1a) = *(short *)(*piVar3 + 0x1a) + 1;

          param_1 = local_1b4;

        }

        local_204 = 0.0;

        local_208 = 0.0;

        local_1e8 = (void *)0x0;

        local_1e4 = (float *)0x0;

        local_1e0 = 0;

        local_1c0 = (float *)0x0;

        local_1bc = (float *)0x0;

        local_1b8 = 0;

        local_c = CONCAT31(local_c._1_3_,2);

        if (*(int *)(param_2 + 4) == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x38;

        }

        uVar5 = iVar4 - 1;

        local_244 = (float *)0x0;

        if (iVar4 != 1) {

          do {

            iVar4 = (int)local_244 * 2;

            pfVar6 = (float *)FUN_0068bac0(*(int *)(param_2 + 0x28) + iVar4);

            pfVar7 = (float *)FUN_0068bac0(iVar4 + 2 + *(int *)(param_2 + 0x28));

            local_118 = pfVar7[1];

            local_d4 = *pfVar6;

            local_e0 = *pfVar7;

            local_204 = (float)(((int)((local_e0 - local_d4) * (local_e0 - local_d4) +

                                      (pfVar7[2] - pfVar6[2]) * (pfVar7[2] - pfVar6[2]) +

                                      (local_118 - pfVar6[1]) * (local_118 - pfVar6[1])) >> 1) +

                               0x1fc00000) + local_204;

            if ((local_1e8 == (void *)0x0) ||

               ((uint)(local_1e0 - (int)local_1e8 >> 2) <=

                (uint)((int)local_1e4 - (int)local_1e8 >> 2))) {

              FUN_004490a0(local_1e4,1,&local_204);

            }

            else {

              *local_1e4 = local_204;

              local_1e4 = local_1e4 + 1;

            }

            pfVar6 = (float *)FUN_0068bac0(iVar4 + 1 + *(int *)(param_2 + 0x28));

            pfVar7 = (float *)FUN_0068bac0(iVar4 + 3 + *(int *)(param_2 + 0x28));

            local_11c = pfVar7[1];

            local_d4 = *pfVar6;

            local_e0 = *pfVar7;

            local_208 = (float)(((int)((local_e0 - local_d4) * (local_e0 - local_d4) +

                                      (pfVar7[2] - pfVar6[2]) * (pfVar7[2] - pfVar6[2]) +

                                      (local_11c - pfVar6[1]) * (local_11c - pfVar6[1])) >> 1) +

                               0x1fc00000) + local_208;

            if ((local_1c0 == (float *)0x0) ||

               ((uint)(local_1b8 - (int)local_1c0 >> 2) <=

                (uint)((int)local_1bc - (int)local_1c0 >> 2))) {

              FUN_004490a0(local_1bc,1,&local_208);

            }

            else {

              *local_1bc = local_208;

              local_1bc = local_1bc + 1;

            }

            local_244 = (float *)((int)local_244 + 1);

          } while (local_244 < uVar5);

        }

        uVar10 = 1;

        *(short *)(*param_1 + 0x1a) = SUB42(local_200,0) + 2;

        if (1 < uVar5) {

          local_200 = g_flOne / local_204;

          iVar4 = (int)local_1e8 - (int)local_1c0;

          local_244 = local_1c0;

          local_224 = g_flOne / local_208;

          do {

            puVar8 = (uint32_t /* width from decompiler */ *)FUN_0068bad0(*(int *)(param_2 + 0x28) + uVar10 * 2);

            local_fc = *puVar8;

            local_f8 = local_200 * *(float *)(iVar4 + (int)local_244) * _DAT_009eb1b4;

            FUN_0068c910(&local_fc,

                         CONCAT22((short)((uint)local_fc >> 0x10),(ushort)*(byte *)(param_2 + 0x18))

                        );

            *(short *)(*param_1 + 0x1a) = *(short *)(*param_1 + 0x1a) + 1;

            puVar8 = (uint32_t /* width from decompiler */ *)FUN_0068bad0(*(int *)(param_2 + 0x28) + 1 + uVar10 * 2);

            local_f4 = *puVar8;

            local_f0 = local_224 * *local_244 * _DAT_009eb1b4;

            FUN_0068c910(&local_f4,*(uint8_t *)(param_2 + 0x18));

            *(short *)(*param_1 + 0x1a) = *(short *)(*param_1 + 0x1a) + 1;

            uVar10 = uVar10 + 1;

            local_244 = local_244 + 1;

          } while (uVar10 < uVar5);

        }

        *(short *)(*param_1 + 0x1a) = *(short *)(*param_1 + 0x1a) + 1;

        *(short *)(*param_1 + 0x1a) = *(short *)(*param_1 + 0x1a) + 1;

        if (local_1c0 != (float *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_1c0);

        }

        local_1c0 = (float *)0x0;

        local_1bc = (float *)0x0;

        local_1b8 = 0;

        if (local_1e8 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_1e8);

        }

        local_1e8 = (void *)0x0;

        local_1e4 = (float *)0x0;

        local_1e0 = 0;

        local_c = 0xffffffff;

        if (local_1a4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(local_1a4);

        }

        local_1f0 = local_1f0 + 1;

      } while (local_1f0 < (uint)param_1[0xb]);

    }

  }

  ExceptionList = local_14;

  return;

}
