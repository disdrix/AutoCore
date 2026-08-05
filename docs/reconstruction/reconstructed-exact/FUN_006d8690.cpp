// =============================================================================
// FUN_006d8690
// -----------------------------------------------------------------------------
// Stable ID: aa_006d8690
// Address:   0x006d8690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d8690 @ 0x006d8690
// Stable ID: aa_006d8690
// Embedded strings (evidence for future rename):
//   - "TtCapsuleTri"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~471 non-empty decompiler lines.
//  - Control keywords: if×27, do×6, while×6, goto×3, return×1.
//  - Notable callees: SQRT×3, rdtsc×2, ABS, FUN_00404d80, FUN_005b3370, FUN_006d8690, FUN_006df0b0, FUN_006f6ef0.
//  - Strings: "TtCapsuleTri".
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



void __thiscall FUN_006d8690(int param_1,int *param_2,int *param_3,int param_4,int *param_5)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int *piVar5;

  uint64_t uVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  short sVar12;

  float *pfVar13;

  uint32_t /* width from decompiler */ *puVar14;

  int iVar15;

  int iVar16;

  int iVar17;

  float fVar18;

  uint *puVar19;

  uint32_t /* width from decompiler */ *puVar20;

  uint uVar21;

  short *psVar22;

  uint uVar23;

  uint3 uStack_200;

  int local_1fc;

  float local_1f8;

  int local_1f4;

  float local_1ec;

  float local_1e8;

  float local_1e4;

  float local_1e0 [7];

  float local_1c4;

  float local_1b4;

  float local_1b0;

  float local_1ac;

  float local_1a8;

  float local_1a4;

  float local_1a0 [4];

  float local_190 [6];

  float local_178;

  float local_174;

  float local_170;

  float local_16c;

  float local_168;

  float local_164;

  int local_154;

  float local_150 [4];

  float local_140 [4];

  float local_130 [4];

  float local_120;

  float local_11c;

  float local_118;

  float local_114;

  uint local_110;

  float local_10c;

  float local_108;

  float local_100 [5];

  float local_ec;

  float local_e8;

  uint32_t /* width from decompiler */ local_e4;

  float local_e0;

  float local_dc;

  float local_d8;

  uint32_t /* width from decompiler */ local_d4;

  float local_d0;

  float local_cc;

  float local_c8;

  float local_c4;

  float local_c0;

  float local_bc;

  float local_b8;

  float local_b4;

  float local_b0;

  uint8_t local_a0 [8];

  uint32_t /* width from decompiler */ local_98;

  float local_94;

  float local_88 [6];

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_34;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtCapsuleTri";

    uVar6 = rdtsc();

    DAT_00bc5644[1] = (int)uVar6;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar17 = *param_2;

  fVar18 = *(float *)(iVar17 + 0x10);

  iVar15 = param_2[2];

  fVar2 = *(float *)(iVar17 + 0x14);

  fVar3 = *(float *)(iVar17 + 0x18);

  iVar4 = *param_3;

  local_190[0] = fVar18 * *(float *)(iVar15 + 0x20) +

                 fVar2 * *(float *)(iVar15 + 0x30) + fVar3 * *(float *)(iVar15 + 0x40) +

                 *(float *)(iVar15 + 0x50);

  local_190[1] = fVar18 * *(float *)(iVar15 + 0x24) +

                 fVar2 * *(float *)(iVar15 + 0x34) + fVar3 * *(float *)(iVar15 + 0x44) +

                 *(float *)(iVar15 + 0x54);

  local_190[2] = fVar18 * *(float *)(iVar15 + 0x28) +

                 fVar2 * *(float *)(iVar15 + 0x38) + fVar3 * *(float *)(iVar15 + 0x48) +

                 *(float *)(iVar15 + 0x58);

  local_190[3] = 0.0;

  fVar18 = *(float *)(iVar17 + 0x20);

  fVar2 = *(float *)(iVar17 + 0x24);

  fVar3 = *(float *)(iVar17 + 0x28);

  local_190[4] = fVar18 * *(float *)(iVar15 + 0x20) +

                 fVar2 * *(float *)(iVar15 + 0x30) + fVar3 * *(float *)(iVar15 + 0x40) +

                 *(float *)(iVar15 + 0x50);

  local_190[5] = fVar18 * *(float *)(iVar15 + 0x24) +

                 fVar2 * *(float *)(iVar15 + 0x34) + fVar3 * *(float *)(iVar15 + 0x44) +

                 *(float *)(iVar15 + 0x54);

  local_178 = fVar18 * *(float *)(iVar15 + 0x28) +

              fVar2 * *(float *)(iVar15 + 0x38) + fVar3 * *(float *)(iVar15 + 0x48) +

              *(float *)(iVar15 + 0x58);

  iVar15 = param_3[2];

  local_174 = 0.0;

  pfVar13 = (float *)(iVar15 + 0x20);

  fVar18 = *(float *)(iVar4 + 0x10);

  fVar2 = *(float *)(iVar4 + 0x14);

  fVar3 = *(float *)(iVar4 + 0x18);

  local_100[0] = fVar18 * *pfVar13 +

                 fVar2 * *(float *)(iVar15 + 0x30) + fVar3 * *(float *)(iVar15 + 0x40) +

                 *(float *)(iVar15 + 0x50);

  local_100[1] = fVar2 * *(float *)(iVar15 + 0x34) +

                 fVar3 * *(float *)(iVar15 + 0x44) + fVar18 * *(float *)(iVar15 + 0x24) +

                 *(float *)(iVar15 + 0x54);

  local_100[2] = fVar2 * *(float *)(iVar15 + 0x38) +

                 fVar3 * *(float *)(iVar15 + 0x48) + fVar18 * *(float *)(iVar15 + 0x28) +

                 *(float *)(iVar15 + 0x58);

  local_100[3] = 0.0;

  fVar18 = *(float *)(iVar4 + 0x20);

  fVar2 = *(float *)(iVar4 + 0x24);

  fVar3 = *(float *)(iVar4 + 0x28);

  local_100[4] = fVar18 * *pfVar13 +

                 fVar2 * *(float *)(iVar15 + 0x30) + fVar3 * *(float *)(iVar15 + 0x40) +

                 *(float *)(iVar15 + 0x50);

  local_ec = fVar2 * *(float *)(iVar15 + 0x34) +

             fVar3 * *(float *)(iVar15 + 0x44) + fVar18 * *(float *)(iVar15 + 0x24) +

             *(float *)(iVar15 + 0x54);

  local_e8 = fVar2 * *(float *)(iVar15 + 0x38) +

             fVar3 * *(float *)(iVar15 + 0x48) + fVar18 * *(float *)(iVar15 + 0x28) +

             *(float *)(iVar15 + 0x58);

  local_e4 = 0;

  fVar18 = *(float *)(iVar4 + 0x30);

  fVar2 = *(float *)(iVar4 + 0x34);

  fVar3 = *(float *)(iVar4 + 0x38);

  local_e0 = fVar18 * *pfVar13 +

             fVar2 * *(float *)(iVar15 + 0x30) + fVar3 * *(float *)(iVar15 + 0x40) +

             *(float *)(iVar15 + 0x50);

  local_dc = fVar2 * *(float *)(iVar15 + 0x34) +

             fVar3 * *(float *)(iVar15 + 0x44) + fVar18 * *(float *)(iVar15 + 0x24) +

             *(float *)(iVar15 + 0x54);

  local_d8 = fVar2 * *(float *)(iVar15 + 0x38) +

             fVar3 * *(float *)(iVar15 + 0x48) + fVar18 * *(float *)(iVar15 + 0x28) +

             *(float *)(iVar15 + 0x58);

  local_d4 = 0;

  local_154 = param_1;

  FUN_006f75d0(local_100,param_1 + 0x14,local_150,&local_1b0);

  fVar18 = local_190[0] - local_100[0];

  fVar2 = local_190[1] - local_100[1];

  fVar3 = local_190[2] - local_100[2];

  fVar7 = local_190[4] - local_100[0];

  fVar8 = local_190[5] - local_100[1];

  fVar9 = local_178 - local_100[2];

  local_1e0[0] = local_130[0] * fVar3 + fVar18 * local_150[0] + local_140[0] * fVar2 + local_120;

  local_1e0[1] = local_130[1] * fVar3 + fVar18 * local_150[1] + fVar2 * local_140[1] + local_11c;

  local_1e0[2] = local_130[2] * fVar3 + fVar2 * local_140[2] + fVar18 * local_150[2] + local_118;

  local_1e0[3] = fVar3 * local_130[3] + fVar2 * local_140[3] + fVar18 * local_150[3] + local_114;

  local_1e0[4] = local_140[0] * fVar8 + local_130[0] * fVar9 + fVar7 * local_150[0] + local_120;

  local_1e0[5] = local_140[1] * fVar8 + local_130[1] * fVar9 + fVar7 * local_150[1] + local_11c;

  local_1e0[6] = local_130[2] * fVar9 + fVar8 * local_140[2] + fVar7 * local_150[2] + local_118;

  local_1c4 = fVar9 * local_130[3] + fVar8 * local_140[3] + fVar7 * local_150[3] + local_114;

  local_1b4 = *(float *)(iVar17 + 0xc) + *(float *)(iVar4 + 0xc);

  local_94 = 3.4028235e+38;

  local_64 = 3.4028235e+38;

  local_34 = 3.4028235e+38;

  fVar18 = local_1b4 + *(float *)(param_4 + 8);

  if (((byte)(((fVar18 < local_1e0[0]) << 3 | (fVar18 < local_1e0[2]) << 1 |

               (fVar18 < local_1e0[1]) << 2 | fVar18 < local_1e0[3]) &

             ((fVar18 < local_1e0[6]) << 1 | (fVar18 < local_1e0[5]) << 2 |

              (fVar18 < local_1e0[4]) << 3 | fVar18 < local_1c4)) == 0) &&

     ((-fVar18 <= local_1e0[3] || (-fVar18 <= local_1c4)))) {

    uVar21 = (uint)(local_1e0[2] < g_flZero) << 1 | (uint)(local_1e0[1] < g_flZero) << 2 |

             (uint)(local_1e0[0] < g_flZero) << 3 | (uint)(local_1e0[3] < g_flZero);

    local_110 = uVar21;

    fVar18 = (float)((uint)(local_1e0[6] < g_flZero) << 1 | (uint)(local_1e0[5] < g_flZero) << 2 |

                     (uint)(local_1e0[4] < g_flZero) << 3 | (uint)(local_1c4 < g_flZero));

    local_10c = fVar18;

    if ((((uint)fVar18 ^ uVar21) & 1) != 0) {

      fVar2 = local_1e0[3] / (local_1e0[3] - local_1c4);

      fVar3 = g_flOne - fVar2;

      local_1a0[1] = fVar2 * local_1e0[5] + local_1e0[1] * fVar3;

      local_1a0[2] = fVar3 * local_1e0[2] + fVar2 * local_1e0[6];

      local_1a0[3] = fVar3 * local_1e0[3] + fVar2 * local_1c4;

      if ((byte)((local_1a0[2] < g_flZero) << 1 | (local_1a0[1] < g_flZero) << 2 |

                (fVar3 * local_1e0[0] + fVar2 * local_1e0[4] < g_flZero) * -8 & 0xeU) == 0xe) {

        local_64 = -3.4028235e+38;

        puVar19 = &local_110;

        iVar17 = 0;

        do {

          if ((((byte)*puVar19 & 0xe) == 0xe) &&

             (fVar18 = -ABS(*(float *)((int)local_1e0 + iVar17 + 0xc)) - local_1b4,

             local_64 < fVar18)) {

            if ((*puVar19 & 1) == 0) {

              local_60 = -local_1b0;

              local_5c = -local_1ac;

              local_58 = -local_1a8;

              local_54 = -local_1a4;

              local_68 = *(float *)((int)local_190 + iVar17 + 8);

              fVar2 = -*(float *)(iVar4 + 0xc);

            }

            else {

              local_60 = local_1b0;

              local_5c = local_1ac;

              local_58 = local_1a8;

              local_54 = local_1a4;

              fVar2 = *(float *)(iVar4 + 0xc);

              local_68 = *(float *)((int)local_190 + iVar17 + 8);

            }

            fVar2 = fVar2 - *(float *)((int)local_1e0 + iVar17 + 0xc);

            local_70 = fVar2 * local_1b0 + *(float *)((int)local_190 + iVar17);

            local_6c = fVar2 * local_1ac + *(float *)((int)local_190 + iVar17 + 4);

            local_68 = fVar2 * local_1a8 + local_68;

            local_64 = fVar18;

          }

          iVar17 = iVar17 + 0x10;

          puVar19 = puVar19 + 1;

        } while (iVar17 < 0x20);

        iVar17 = 0;

        local_1a0[0] = local_1e0[4] - local_1e0[0];

        local_1a0[1] = local_1e0[5] - local_1e0[1];

        local_1a0[2] = local_1e0[6] - local_1e0[2];

        local_1a0[3] = local_1c4 - local_1e0[3];

        do {

          fVar18 = *(float *)((int)local_1a0 + iVar17);

          fVar2 = g_flOne / (fVar18 * fVar18 + local_1a0[3] * local_1a0[3]);

          fVar3 = fVar18 * local_1e0[3] - local_1a0[3] * *(float *)((int)local_1e0 + iVar17);

          fVar3 = fVar3 * fVar3 * fVar2;

          if (((fVar3 < (local_1b4 + local_64) * (local_1b4 + local_64)) &&

              (fVar2 = -((local_1a0[3] * local_1e0[3] + fVar18 * *(float *)((int)local_1e0 + iVar17)

                         ) * fVar2), DAT_00aaa6b4 < fVar2)) && (fVar2 < _DAT_00aaac14)) {

            local_1f8 = local_1a0[3];

            if (local_1a0[3] < g_flZero) {

              local_1f8 = -local_1a0[3];

              fVar18 = -fVar18;

            }

            fVar18 = -fVar18;

            fVar8 = fVar18 * local_1b0 + *(float *)((int)local_150 + iVar17) * local_1f8;

            fVar9 = fVar18 * local_1ac + local_1f8 * *(float *)((int)local_140 + iVar17);

            fVar7 = fVar18 * local_1a8 + local_1f8 * *(float *)((int)local_130 + iVar17);

            fVar11 = fVar8 * fVar8 + fVar9 * fVar9 + fVar7 * fVar7;

            fVar10 = g_flZero;

            if (fVar11 != g_flZero) {

              fVar10 = g_flOne / SQRT(fVar11);

            }

            local_60 = fVar8 * fVar10;

            local_5c = fVar9 * fVar10;

            local_58 = fVar7 * fVar10;

            local_54 = (fVar18 * local_1a4 + local_1f8 * g_flZero) * fVar10;

            fVar11 = g_flOne - fVar2;

            local_10c = fVar2 * local_190[5] + fVar11 * local_190[1];

            local_108 = fVar2 * local_178 + fVar11 * local_190[2];

            fVar18 = -SQRT(fVar3);

            fVar3 = *(float *)(iVar4 + 0xc) - fVar18;

            local_70 = fVar8 * fVar10 * fVar3 + fVar2 * local_190[4] + local_190[0] * fVar11;

            local_6c = fVar9 * fVar10 * fVar3 + local_10c;

            local_68 = fVar7 * fVar10 * fVar3 + local_108;

            local_64 = fVar18 - local_1b4;

          }

          iVar17 = iVar17 + 4;

        } while (iVar17 < 0xc);

        goto LAB_006d9217;

      }

    }

    local_170 = local_190[4] - local_190[0];

    local_1f4 = 0;

    local_16c = local_190[5] - local_190[1];

    local_168 = local_178 - local_190[2];

    local_164 = local_174 - local_190[3];

    if (((byte)((uint)fVar18 | uVar21) & 0xe) == 0xe) {

      pfVar13 = local_88;

      do {

        if (((byte)(&local_110)[local_1f4] & 0xe) == 0xe) {

          pfVar1 = local_1e0 + local_1f4 * 4 + 3;

          if (((&local_110)[local_1f4] & 1) == 0) {

            fVar18 = *(float *)(iVar4 + 0xc) - *pfVar1;

            pfVar13[-6] = local_1b0 * fVar18 + local_190[local_1f4 * 4];

            pfVar13[-5] = local_1ac * fVar18 + local_190[local_1f4 * 4 + 1];

            pfVar13[-4] = local_1a8 * fVar18 + local_190[local_1f4 * 4 + 2];

            pfVar13[-3] = fVar18 * local_1a4 + local_190[local_1f4 * 4 + 3];

            pfVar13[-3] = *pfVar1 - local_1b4;

            pfVar13[-2] = local_1b0;

            pfVar13[-1] = local_1ac;

            *pfVar13 = local_1a8;

            pfVar13[1] = local_1a4;

          }

          else {

            fVar18 = -*(float *)(iVar4 + 0xc) - *pfVar1;

            pfVar13[-6] = local_1b0 * fVar18 + local_190[local_1f4 * 4];

            pfVar13[-5] = local_1ac * fVar18 + local_190[local_1f4 * 4 + 1];

            pfVar13[-4] = local_1a8 * fVar18 + local_190[local_1f4 * 4 + 2];

            pfVar13[-3] = fVar18 * local_1a4 + local_190[local_1f4 * 4 + 3];

            pfVar13[-3] = -*pfVar1 - local_1b4;

            pfVar13[-2] = -local_1b0;

            pfVar13[-1] = -local_1ac;

            *pfVar13 = -local_1a8;

            pfVar13[1] = -local_1a4;

          }

        }

        else {

          uStack_200 = 8;

          iVar17 = 0;

          do {

            if (((&local_110)[local_1f4] & (uint)uStack_200) == 0) {

              iVar16 = (int)(char)(&DAT_00a0eefc)[iVar17];

              iVar15 = (int)(char)(&DAT_00a0eefe)[iVar17];

              local_1a0[0] = local_100[iVar16 * 4] - local_100[iVar15 * 4];

              local_1a0[1] = local_100[iVar16 * 4 + 1] - local_100[iVar15 * 4 + 1];

              local_1a0[2] = local_100[iVar16 * 4 + 2] - local_100[iVar15 * 4 + 2];

              local_1a0[3] = local_100[iVar16 * 4 + 3] - local_100[iVar15 * 4 + 3];

              uVar21 = FUN_006f6ef0(local_190,&local_170,local_100 + iVar15 * 4,local_1a0,&local_d0)

              ;

              if ((local_b0 < (local_1b4 + pfVar13[-3]) * (local_1b4 + pfVar13[-3])) &&

                 ((uVar21 & 1 << ((byte)local_1f4 & 0x1f)) == 0)) {

                if (uVar21 == 0) {

                  local_1ec = local_1a0[0] * local_168 - local_170 * local_1a0[2];

                  local_1e8 = local_170 * local_1a0[1] - local_1a0[0] * local_16c;

                  local_1e4 = 0.0;

                  fVar18 = local_1a0[2] * local_16c - local_1a0[1] * local_168;

                }

                else {

                  if (local_b0 < _DAT_00a0e520 != (local_b0 == _DAT_00a0e520)) {

                    local_b4 = 0.0;

                    local_c0 = local_150[iVar17];

                    local_1e4 = 0.0;

                    local_bc = local_140[iVar17];

                    local_b8 = local_130[iVar17];

                    fVar18 = local_1a0[2] * local_16c - local_1a0[1] * local_168;

                    local_1ec = local_1a0[0] * local_168 - local_170 * local_1a0[2];

                    local_1e8 = local_170 * local_1a0[1] - local_1a0[0] * local_16c;

                    fVar2 = local_1ec * local_1ec + local_1e8 * local_1e8 + fVar18 * fVar18;

                    if (fVar2 < _DAT_00a0e520 == (fVar2 == _DAT_00a0e520)) goto LAB_006d975d;

                  }

                  local_1ec = local_bc;

                  local_1e8 = local_b8;

                  local_1e4 = local_b4;

                  fVar18 = local_c0;

                }

LAB_006d975d:

                fVar2 = local_1ec * local_1ec + local_1e8 * local_1e8 + fVar18 * fVar18;

                if (fVar2 == g_flZero) {

                  local_1f8 = 0.0;

                }

                else {

                  local_1f8 = g_flOne / SQRT(fVar2);

                }

                fVar18 = fVar18 * local_1f8;

                local_1ec = local_1f8 * local_1ec;

                local_1e8 = local_1f8 * local_1e8;

                local_1e4 = local_1f8 * local_1e4;

                fVar2 = local_bc * local_1ec + local_b8 * local_1e8 + local_c0 * fVar18;

                if (fVar2 < g_flZero) {

                  fVar2 = -fVar2;

                  fVar18 = -fVar18;

                  local_1ec = -local_1ec;

                  local_1e8 = -local_1e8;

                  local_1e4 = -local_1e4;

                }

                fVar3 = *(float *)(iVar4 + 0xc) - fVar2;

                pfVar13[-6] = fVar18 * fVar3 + local_d0;

                pfVar13[-5] = local_1ec * fVar3 + local_cc;

                pfVar13[-4] = local_1e8 * fVar3 + local_c8;

                pfVar13[-3] = local_1e4 * fVar3 + local_c4;

                pfVar13[-3] = fVar2 - local_1b4;

                *pfVar13 = local_1e8;

                pfVar13[1] = local_1e4;

                pfVar13[-2] = fVar18;

                pfVar13[-1] = local_1ec;

              }

            }

            iVar17 = iVar17 + 1;

            uStack_200 = (uint3)((int)(uint)uStack_200 >> 1);

          } while (iVar17 < 3);

        }

        pfVar13 = pfVar13 + 0xc;

        local_1f4 = local_1f4 + 1;

      } while (local_1f4 < 2);

    }

    else {

      local_94 = *(float *)(param_4 + 8);

      local_64 = local_94;

      local_34 = local_94;

      FUN_00404d80(local_1e0,0x10,2,FUN_005edf20);

      uVar23 = 8;

      iVar17 = 0;

      do {

        if ((((uint)fVar18 | uVar21) & uVar23) == 0) {

          iVar15 = (int)(char)(&DAT_00a0eefe)[iVar17];

          local_1e0[0] = local_100[iVar15 * 4];

          local_1e0[1] = local_100[iVar15 * 4 + 1];

          iVar16 = (int)(char)(&DAT_00a0eefc)[iVar17];

          local_1e0[2] = local_100[iVar15 * 4 + 2];

          local_1e0[3] = local_100[iVar15 * 4 + 3];

          local_1e0[4] = local_100[iVar16 * 4];

          local_1e0[6] = local_100[iVar16 * 4 + 2];

          local_1e0[5] = local_100[iVar16 * 4 + 1];

          local_1c4 = local_100[iVar16 * 4 + 3];

          FUN_006df0b0(param_2,local_1e0,*(uint32_t /* width from decompiler */ *)(iVar4 + 0xc),local_a0);

        }

        uVar23 = (int)uVar23 >> 1;

        iVar17 = iVar17 + 1;

      } while (iVar17 < 3);

    }

  }

LAB_006d9217:

  psVar22 = (short *)(local_154 + 0xc);

  puVar20 = &local_98;

  local_1fc = 3;

  do {

    if (*(float *)(param_4 + 8) <= (float)puVar20[1]) {

      if (*psVar22 != -1) {

        (**(code **)(**(int **)(local_154 + 8) + 8))(*psVar22);

        *psVar22 = -1;

      }

    }

    else {

      if (*psVar22 == -1) {

        sVar12 = (**(code **)(**(int **)(local_154 + 8) + 4))(param_2,param_3,param_4,puVar20 + -2);

        *psVar22 = sVar12;

        if (sVar12 == -1) goto LAB_006d98bf;

      }

      piVar5 = (int *)*param_5;

      if (piVar5[1] == (piVar5[2] & 0x7fffffffU)) {

        FUN_005b3370(piVar5,0x30);

      }

      puVar14 = (uint32_t /* width from decompiler */ *)(piVar5[1] * 0x30 + *piVar5);

      piVar5[1] = piVar5[1] + 1;

      *puVar14 = puVar20[-2];

      puVar14[1] = puVar20[-1];

      puVar14[2] = *puVar20;

      puVar14[3] = puVar20[1];

      puVar14[4] = puVar20[2];

      puVar14[5] = puVar20[3];

      puVar14[6] = puVar20[4];

      puVar14[7] = puVar20[5];

      *(short *)(puVar14 + 8) = *psVar22;

    }

LAB_006d98bf:

    psVar22 = psVar22 + 1;

    puVar20 = puVar20 + 0xc;

    local_1fc = local_1fc + -1;

    if (local_1fc == 0) {

      if (DAT_00bc5644 < DAT_00bc5648) {

        *DAT_00bc5644 = &DAT_009d2878;

        uVar6 = rdtsc();

        DAT_00bc5644[1] = (int)uVar6;

        DAT_00bc5644 = DAT_00bc5644 + 3;

      }

      return;

    }

  } while( true );

}
