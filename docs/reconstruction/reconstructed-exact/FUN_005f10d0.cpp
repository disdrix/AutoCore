// =============================================================================
// FUN_005f10d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005f10d0
// Address:   0x005f10d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f10d0 @ 0x005f10d0
// Stable ID: aa_005f10d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~369 non-empty decompiler lines.
//  - Control keywords: if×23, do×2, while×2, return×2.
//  - Notable callees: ABS×16, FUN_005b3300×8, FUN_004f2d70×2, SQRT×2, FUN_004f34b0, FUN_005efe50, FUN_005f10d0.
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



uint32_t /* width from decompiler */

FUN_005f10d0(float *param_1,float *param_2,float *param_3,float param_4,float param_5,float *param_6

            )



{

  float *pfVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float local_130;

  float local_12c;

  float local_128;

  float local_124;

  float local_110;

  float local_10c;

  float local_108;

  int local_104;

  float local_100;

  float local_fc;

  float local_f8;

  float local_f0;

  float local_ec;

  float local_e8;

  float local_d4;

  float *local_d0;

  float local_cc;

  int local_c8;

  float local_c0;

  float local_bc;

  float local_b8;

  float local_b4;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  if ((0.0 < param_4) && (0.0 <= param_5)) {

    fVar11 = (param_1[2] - param_2[2]) * (param_3[1] - param_2[1]) -

             (param_1[1] - param_2[1]) * (param_3[2] - param_2[2]);

    fVar10 = (param_3[2] - param_2[2]) * (*param_1 - *param_2) -

             (param_1[2] - param_2[2]) * (*param_3 - *param_2);

    fVar7 = (param_1[1] - param_2[1]) * (*param_3 - *param_2) -

            (param_3[1] - param_2[1]) * (*param_1 - *param_2);

    fVar8 = fVar11 * fVar11 + fVar7 * fVar7 + fVar10 * fVar10;

    local_d4 = SQRT(fVar8);

    if (DAT_00aaa620 <= param_5) {

      if (DAT_00aaa620 <= local_d4) {

        if (fVar8 == 0.0) {

          fVar8 = 0.0;

        }

        else {

          fVar8 = g_flOne / SQRT(fVar8);

        }

        fVar9 = param_5 * DAT_00a0f298;

        fVar10 = fVar10 * fVar8;

        fVar11 = fVar8 * fVar11;

        local_c0 = fVar9 * fVar11 + *param_1;

        fVar7 = fVar7 * fVar8;

        local_bc = fVar10 * fVar9 + param_1[1];

        local_b8 = fVar7 * fVar9 + param_1[2];

        fVar8 = fVar8 * 0.0;

        local_b4 = fVar8 * fVar9 + param_1[3];

        fVar12 = param_5 * DAT_00aaa6cc;

        local_b0 = fVar12 * fVar11 + *param_1;

        local_ac = fVar10 * fVar12 + param_1[1];

        local_a8 = fVar7 * fVar12 + param_1[2];

        local_a4 = fVar8 * fVar12 + param_1[3];

        local_a0 = fVar9 * fVar11 + *param_2;

        local_9c = fVar10 * fVar9 + param_2[1];

        local_98 = fVar7 * fVar9 + param_2[2];

        local_94 = fVar8 * fVar9 + param_2[3];

        local_d0 = &local_c0;

        local_c8 = -0x7ffffffa;

        local_cc = 8.40779e-45;

        local_90 = fVar12 * fVar11 + *param_2;

        local_8c = fVar10 * fVar12 + param_2[1];

        local_88 = fVar7 * fVar12 + param_2[2];

        local_84 = fVar8 * fVar12 + param_2[3];

        local_80 = fVar9 * fVar11 + *param_3;

        local_7c = fVar10 * fVar9 + param_3[1];

        local_78 = fVar7 * fVar9 + param_3[2];

        local_74 = fVar8 * fVar9 + param_3[3];

        local_70 = fVar12 * fVar11 + *param_3;

        local_6c = fVar10 * fVar12 + param_3[1];

        local_68 = fVar7 * fVar12 + param_3[2];

        local_64 = fVar8 * fVar12 + param_3[3];

        local_60 = 0;

        local_5c = 0;

        local_44 = 0.0;

        local_48 = 0.0;

        local_4c = 0.0;

        local_50 = 0.0;

        local_34 = 0;

        local_38 = 0;

        local_3c = 0;

        local_40 = 0;

        local_24 = 0;

        local_28 = 0;

        local_2c = 0;

        local_30 = 0;

        local_14 = 0;

        local_18 = 0;

        local_1c = 0;

        local_20 = 0;

        iVar6 = 0;

        local_110 = 0.0;

        local_10c = 0.0;

        local_108 = -0.0;

        local_104 = 0;

        local_100 = 0.0;

        local_fc = -0.0;

        local_110 = (float)(**(code **)(*DAT_00b05060 + 0x10))(0x60,0x12);

        fVar7 = local_100;

        local_108 = local_cc;

        local_10c = local_cc;

        if (3 < (int)local_cc) {

          iVar5 = ((int)local_cc - 4U >> 2) + 1;

          pfVar4 = (float *)((int)local_110 + 0x18);

          pfVar1 = local_d0 + 6;

          iVar6 = iVar5 * 4;

          do {

            pfVar4[-6] = pfVar1[-6];

            pfVar4[-5] = pfVar1[-5];

            pfVar4[-4] = pfVar1[-4];

            pfVar4[-3] = pfVar1[-3];

            pfVar4[-2] = pfVar1[-2];

            pfVar4[-1] = pfVar1[-1];

            *pfVar4 = *pfVar1;

            pfVar4[1] = pfVar1[1];

            pfVar4[2] = pfVar1[2];

            pfVar4[3] = pfVar1[3];

            pfVar4[4] = pfVar1[4];

            pfVar4[5] = pfVar1[5];

            pfVar4[6] = pfVar1[6];

            pfVar4[7] = pfVar1[7];

            pfVar4[8] = pfVar1[8];

            pfVar4[9] = pfVar1[9];

            pfVar1 = pfVar1 + 0x10;

            pfVar4 = pfVar4 + 0x10;

            iVar5 = iVar5 + -1;

          } while (iVar5 != 0);

        }

        if (iVar6 < (int)local_cc) {

          pfVar4 = local_d0 + iVar6 * 4 + 3;

          puVar2 = (uint32_t /* width from decompiler */ *)(iVar6 * 0x10 + 4 + (int)local_110);

          iVar6 = (int)local_cc - iVar6;

          do {

            puVar2[-1] = pfVar4[-3];

            *puVar2 = *(uint32_t /* width from decompiler */ *)(((int)local_d0 - (int)local_110) + (int)puVar2);

            puVar2[1] = pfVar4[-1];

            puVar2[2] = *pfVar4;

            pfVar4 = pfVar4 + 4;

            puVar2 = puVar2 + 4;

            iVar6 = iVar6 + -1;

          } while (iVar6 != 0);

        }

        iVar6 = (int)local_100 + 1;

        if ((int)ABS(local_fc) < iVar6) {

          iVar5 = (int)ABS(local_fc) * 2;

          if (iVar5 <= iVar6) {

            iVar5 = iVar6;

          }

          FUN_005b3300(&local_104,iVar5,0xc);

        }

        puVar2 = (uint32_t /* width from decompiler */ *)(local_104 + (int)fVar7 * 0xc);

        *puVar2 = 0;

        puVar2[1] = 2;

        puVar2[2] = 4;

        iVar5 = (int)fVar7 + 2;

        if ((int)ABS(local_fc) < iVar5) {

          iVar3 = (int)ABS(local_fc) * 2;

          if (iVar3 <= iVar5) {

            iVar3 = iVar5;

          }

          local_100 = (float)iVar6;

          FUN_005b3300(&local_104,iVar3,0xc);

        }

        puVar2 = (uint32_t /* width from decompiler */ *)(local_104 + iVar6 * 0xc);

        *puVar2 = 1;

        puVar2[1] = 5;

        puVar2[2] = 3;

        iVar6 = (int)fVar7 + 3;

        if ((int)ABS(local_fc) < iVar6) {

          iVar3 = (int)ABS(local_fc) * 2;

          if (iVar3 <= iVar6) {

            iVar3 = iVar6;

          }

          local_100 = (float)iVar5;

          FUN_005b3300(&local_104,iVar3,0xc);

        }

        puVar2 = (uint32_t /* width from decompiler */ *)(local_104 + iVar5 * 0xc);

        *puVar2 = 0;

        puVar2[1] = 3;

        puVar2[2] = 2;

        iVar5 = (int)fVar7 + 4;

        if ((int)ABS(local_fc) < iVar5) {

          iVar3 = (int)ABS(local_fc) * 2;

          if (iVar3 <= iVar5) {

            iVar3 = iVar5;

          }

          local_100 = (float)iVar6;

          FUN_005b3300(&local_104,iVar3,0xc);

        }

        puVar2 = (uint32_t /* width from decompiler */ *)(local_104 + iVar6 * 0xc);

        *puVar2 = 0;

        puVar2[1] = 1;

        puVar2[2] = 3;

        iVar6 = (int)fVar7 + 5;

        if ((int)ABS(local_fc) < iVar6) {

          iVar3 = (int)ABS(local_fc) * 2;

          if (iVar3 <= iVar6) {

            iVar3 = iVar6;

          }

          local_100 = (float)iVar5;

          FUN_005b3300(&local_104,iVar3,0xc);

        }

        puVar2 = (uint32_t /* width from decompiler */ *)(local_104 + iVar5 * 0xc);

        *puVar2 = 1;

        puVar2[1] = 0;

        puVar2[2] = 4;

        iVar5 = (int)fVar7 + 6;

        if ((int)ABS(local_fc) < iVar5) {

          iVar3 = (int)ABS(local_fc) * 2;

          if (iVar3 <= iVar5) {

            iVar3 = iVar5;

          }

          local_100 = (float)iVar6;

          FUN_005b3300(&local_104,iVar3,0xc);

        }

        puVar2 = (uint32_t /* width from decompiler */ *)(local_104 + iVar6 * 0xc);

        *puVar2 = 1;

        puVar2[1] = 4;

        puVar2[2] = 5;

        iVar6 = (int)fVar7 + 7;

        if ((int)ABS(local_fc) < iVar6) {

          iVar3 = (int)ABS(local_fc) * 2;

          if (iVar3 <= iVar6) {

            iVar3 = iVar6;

          }

          local_100 = (float)iVar5;

          FUN_005b3300(&local_104,iVar3,0xc);

        }

        puVar2 = (uint32_t /* width from decompiler */ *)(local_104 + iVar5 * 0xc);

        *puVar2 = 2;

        puVar2[1] = 5;

        puVar2[2] = 4;

        fVar7 = (float)((int)fVar7 + 8);

        if ((int)ABS(local_fc) < (int)fVar7) {

          fVar8 = (float)((int)ABS(local_fc) * 2);

          if ((int)fVar8 <= (int)fVar7) {

            fVar8 = fVar7;

          }

          local_100 = (float)iVar6;

          FUN_005b3300(&local_104,fVar8,0xc);

        }

        puVar2 = (uint32_t /* width from decompiler */ *)(local_104 + iVar6 * 0xc);

        *puVar2 = 2;

        puVar2[1] = 3;

        puVar2[2] = 5;

        local_100 = fVar7;

        FUN_005efe50(&local_110,param_4,&local_60);

        FUN_004f34b0();

        local_130 = local_50;

        local_12c = local_4c;

        local_128 = local_48;

        local_124 = local_44;

        FUN_004f2d70(&local_40);

        if (-1 < local_c8) {

          (**(code **)(*DAT_00b05060 + 0x14))(local_d0,local_c8 << 4,0x12);

        }

      }

      else {

        local_124 = (param_3[3] + param_2[3] + param_1[3]) * g_flDisplayRateScaleOneThird;

        local_130 = (*param_3 + *param_2 + *param_1) * g_flDisplayRateScaleOneThird;

        local_12c = (param_3[1] + param_1[1] + param_2[1]) * g_flDisplayRateScaleOneThird;

        local_128 = (param_1[2] + param_2[2] + param_3[2]) * g_flDisplayRateScaleOneThird;

        local_110 = (local_128 * local_128 + local_12c * local_12c) * param_4;

        local_e8 = (local_12c * local_12c + local_130 * local_130) * param_4;

        local_fc = (local_128 * local_128 + local_130 * local_130) * param_4;

        local_10c = 0.0 - local_12c * local_130 * param_4;

        local_108 = 0.0 - local_128 * local_130 * param_4;

        local_f8 = 0.0 - local_128 * local_12c * param_4;

        local_100 = local_10c;

        local_f0 = local_108;

        local_ec = local_f8;

      }

    }

    else {

      local_130 = (*param_3 + *param_2 + *param_1) * g_flDisplayRateScaleOneThird;

      local_124 = (param_3[3] + param_2[3] + param_1[3]) * g_flDisplayRateScaleOneThird;

      local_12c = (param_3[1] + param_1[1] + param_2[1]) * g_flDisplayRateScaleOneThird;

      local_128 = (param_1[2] + param_2[2] + param_3[2]) * g_flDisplayRateScaleOneThird;

      fVar7 = local_130 * local_130;

      fVar9 = local_12c * local_12c;

      fVar12 = local_128 * local_128;

      fVar11 = (param_3[2] * param_3[2] + param_2[2] * param_2[2] + param_1[2] * param_1[2] +

               fVar12 * DAT_00aaa944) * param_4 * _DAT_00aaaa20;

      fVar10 = (*param_1 * *param_1 + *param_3 * *param_3 + *param_2 * *param_2 +

               fVar7 * DAT_00aaa944) * param_4 * _DAT_00aaaa20;

      fVar8 = (param_3[1] * param_3[1] + param_2[1] * param_2[1] + param_1[1] * param_1[1] +

              fVar9 * DAT_00aaa944) * param_4 * _DAT_00aaaa20;

      local_110 = (fVar11 + fVar8) - (fVar12 + fVar9) * param_4;

      local_fc = (fVar11 + fVar10) - (fVar12 + fVar7) * param_4;

      local_10c = local_12c * local_130 * param_4 +

                  (0.0 - (param_3[1] * *param_3 + *param_1 * param_1[1] + *param_2 * param_2[1] +

                         local_12c * local_130 * DAT_00aaa944) * param_4 * _DAT_00aaaa20);

      local_e8 = (fVar8 + fVar10) - (fVar9 + fVar7) * param_4;

      local_f8 = local_128 * local_12c * param_4 +

                 (0.0 - (param_3[1] * param_3[2] + param_2[1] * param_2[2] + param_1[2] * param_1[1]

                        + local_128 * local_12c * DAT_00aaa944) * param_4 * _DAT_00aaaa20);

      local_108 = local_128 * local_130 * param_4 +

                  (0.0 - (*param_1 * param_1[2] + param_3[2] * *param_3 + *param_2 * param_2[2] +

                         local_128 * local_130 * DAT_00aaa944) * param_4 * _DAT_00aaaa20);

      local_100 = local_10c;

      local_f0 = local_108;

      local_ec = local_f8;

    }

    param_6[1] = param_4;

    FUN_004f2d70(&local_110);

    param_6[4] = local_130;

    param_6[5] = local_12c;

    param_6[6] = local_128;

    param_6[7] = local_124;

    *param_6 = local_d4 * param_5 * DAT_00a0f298;

    return 0;

  }

  return 1;

}
