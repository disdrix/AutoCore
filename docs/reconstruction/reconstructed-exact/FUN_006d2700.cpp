// =============================================================================
// FUN_006d2700
// -----------------------------------------------------------------------------
// Stable ID: aa_006d2700
// Address:   0x006d2700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d2700 @ 0x006d2700
// Stable ID: aa_006d2700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~241 non-empty decompiler lines.
//  - Control keywords: if×19, do×8, while×8, return×1.
//  - Notable callees: ABS×7, FUN_005b3300, FUN_005b3370, FUN_006cb7d0, FUN_006d2480, FUN_006d2700, FUN_006d74d0, FUN_006ea6f0.
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

void __thiscall FUN_006d2700(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,int *param_4,int *param_5)



{

  float fVar1;

  short sVar2;

  float fVar3;

  uint16_t uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  float *pfVar9;

  int unaff_EBX;

  int *piVar10;

  uint32_t /* width from decompiler */ *puVar11;

  int iVar12;

  int *piVar13;

  int local_170;

  int local_16c;

  uint uStack_168;

  int local_164;

  int local_160;

  int local_15c;

  uint local_158;

  uint uStack_154;

  int iStack_150;

  int iStack_14c;

  int local_148;

  int local_144;

  int local_140;

  int local_13c;

  int *piStack_138;

  int iStack_134;

  uint8_t auStack_130 [8];

  int local_128;

  int *local_124;

  int local_120;

  int local_11c;

  int local_118;

  int *local_114;

  uint8_t local_110 [268];

  

  local_118 = param_3[2];

  local_114 = param_3;

  local_120 = *(int *)(*param_3 + 0xc);

  local_11c = param_3[1];

  local_148 = param_1;

  FUN_006ea6f0(param_2,&local_120,param_4,&LAB_006ea160);

  FUN_006d2480(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

  local_128 = param_3[2];

  local_13c = local_120;

  local_124 = param_3;

  local_16c = 0;

  if (0 < *(int *)(param_1 + 0x10)) {

    local_170 = 0;

    do {

      puVar11 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + local_170);

      iVar5 = FUN_006cb7d0();

      if (puVar11[2] != iVar5) {

        piStack_138 = (int *)(**(code **)(**(int **)(local_13c + 0xc) + 0x34))(*puVar11,local_110);

        iStack_134 = *puVar11;

        piVar10 = (int *)*param_2;

        local_16c = (**(code **)(*piStack_138 + 0x14))();

        iVar5 = (**(code **)(*piVar10 + 0x14))();

        if (*(undefined **)(*param_4 + 0x18c + (iVar5 * 0x20 + local_164) * 4) == &DAT_006d7420) {

          if (local_158 == (uStack_154 & 0x7fffffff)) {

            FUN_005b3370(&local_15c,0xa0);

          }

          iVar5 = puVar11[2];

          iVar6 = ((local_158 - 4) + (local_158 + 1) * 4) * 0x20;

          *(int *)(iVar6 + 0x90 + local_15c) = iVar5;

          *(uint8_t *)(iVar6 + 0x94 + local_15c) = 0;

          *(uint8_t *)(iVar6 + 0x95 + local_15c) = 0;

          *(uint8_t *)(iVar6 + 0x96 + local_15c) = 0;

          *(uint8_t *)(iVar6 + 0x97 + local_15c) = 0;

          *(uint8_t *)(iVar6 + 0x98 + local_15c) = 0;

          *(uint8_t *)(iVar6 + 0x99 + local_15c) = 0;

          *(uint32_t /* width from decompiler */ *)(iVar6 + 0x9c + local_15c) = *puVar11;

          local_158 = local_158 + 1;

          FUN_006d74d0(param_2,auStack_130,param_4,iVar5 + 0x14,1,iVar6 + local_15c);

          param_1 = local_148;

        }

        else {

          (**(code **)(*(int *)puVar11[2] + 0x10))(param_2,auStack_130,param_4,param_5);

          param_1 = local_148;

        }

      }

      local_16c = local_16c + 1;

      local_170 = local_170 + 0xc;

    } while (local_16c < *(int *)(param_1 + 0x10));

  }

  local_160 = 0;

  if (0 < (int)local_158) {

    local_164 = 0;

    do {

      local_140 = 0;

      local_170 = local_164;

      local_144 = local_164;

      do {

        if (*(char *)(local_170 + 0x94 + local_15c) != '\x01') {

          iVar12 = 0;

          fVar1 = ABS(*(float *)(local_144 + 0xc + local_15c));

          pfVar9 = (float *)(local_15c + 0xc);

          iVar5 = local_140;

          iVar6 = local_160;

          do {

            if ((*(char *)((int)pfVar9 + 0x8b) != '\x01') && (ABS(*pfVar9) < fVar1)) {

              iVar5 = 0;

              iVar6 = iVar12;

              fVar1 = ABS(*pfVar9);

            }

            if ((*(char *)(pfVar9 + 0x23) != '\x01') && (ABS(pfVar9[0xc]) < fVar1)) {

              iVar5 = 1;

              iVar6 = iVar12;

              fVar1 = ABS(pfVar9[0xc]);

            }

            if ((*(char *)((int)pfVar9 + 0x8d) != '\x01') && (ABS(pfVar9[0x18]) < fVar1)) {

              iVar5 = 2;

              iVar6 = iVar12;

              fVar1 = ABS(pfVar9[0x18]);

            }

            iVar12 = iVar12 + 1;

            pfVar9 = pfVar9 + 0x28;

          } while (iVar12 < (int)local_158);

          *(uint8_t *)(iVar6 * 0xa0 + iVar5 + 0x97 + local_15c) = 1;

          pfVar9 = (float *)(iVar5 * 0x30 + iVar6 * 0xa0 + local_15c);

          piStack_138 = (int *)0x0;

          uStack_168 = local_158;

          do {

            iStack_134 = 3;

            piVar10 = piStack_138;

            piVar13 = piStack_138;

            do {

              if ((((*(char *)((int)piVar10 + local_15c + 0x97) != '\x01') &&

                   (DAT_00aaa6d4 <= *(float *)((int)piVar13 + local_15c + 0xc))) &&

                  (*(float *)((int)piVar13 + local_15c + 0x10) * pfVar9[4] +

                   *(float *)((int)piVar13 + local_15c + 0x14) * pfVar9[5] +

                   *(float *)((int)piVar13 + local_15c + 0x18) * pfVar9[6] <

                   *(float *)(param_4[3] + 0x10))) &&

                 (fVar3 = (*(float *)((int)piVar13 + local_15c) - *pfVar9) * pfVar9[4] +

                          (*(float *)((int)piVar13 + local_15c + 4) - pfVar9[1]) * pfVar9[5] +

                          (*(float *)((int)piVar13 + local_15c + 8) - pfVar9[2]) * pfVar9[6],

                 fVar1 = *(float *)(param_4[3] + 4), fVar3 < fVar1 != (fVar3 == fVar1))) {

                *(uint8_t *)((int)piVar10 + local_15c + 0x94) = 1;

              }

              piVar13 = piVar13 + 0xc;

              piVar10 = (int *)((int)piVar10 + 1);

              iStack_134 = iStack_134 + -1;

            } while (iStack_134 != 0);

            piStack_138 = piStack_138 + 0x28;

            uStack_168 = uStack_168 - 1;

          } while (uStack_168 != 0);

          iStack_134 = 0;

        }

        local_140 = local_140 + 1;

        local_170 = local_170 + 1;

        local_144 = local_144 + 0x30;

      } while (local_140 < 3);

      local_160 = local_160 + 1;

      local_164 = local_164 + 0xa0;

    } while (local_160 < (int)local_158);

  }

  iVar6 = 0;

  local_164 = 0;

  iVar5 = local_15c;

  if (0 < (int)local_158) {

    do {

      iVar12 = 0xc;

      local_170 = iVar6;

      local_16c = iVar6;

      do {

        if ((*(char *)(local_16c + 0x94 + iVar5) != '\0') ||

           ((float)param_4[2] <= *(float *)(local_170 + 0xc + iVar5))) {

          sVar2 = *(short *)(iVar12 + *(int *)(iVar6 + 0x90 + iVar5));

          if (sVar2 != -1) {

            (**(code **)(**(int **)(local_148 + 8) + 8))(sVar2);

            *(uint16_t *)(iVar12 + *(int *)(iVar6 + 0x90 + local_15c)) = 0xffff;

            iVar5 = local_15c;

          }

        }

        else {

          if (*(short *)(iVar12 + *(int *)(iVar6 + 0x90 + iVar5)) == -1) {

            local_128 = param_3[2];

            local_124 = param_3;

            piStack_138 = (int *)(**(code **)(**(int **)(local_13c + 0xc) + 0x34))

                                           (*(uint32_t /* width from decompiler */ *)(iVar6 + 0x9c + iVar5),local_110);

            iStack_134 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x9c + local_164);

            uVar4 = (**(code **)(**(int **)(iStack_150 + 8) + 4))

                              (param_2,&piStack_138,param_4,unaff_EBX + local_164);

            *(uint16_t *)(iVar12 + *(int *)(local_160 + 0x90)) = uVar4;

            iVar5 = local_15c;

          }

          if (*(short *)(iVar12 + *(int *)(iVar6 + 0x90 + iVar5)) != -1) {

            piVar10 = (int *)*param_5;

            local_160 = piVar10[1];

            iVar5 = local_160 + 1;

            if ((int)(piVar10[2] & 0x7fffffffU) < iVar5) {

              iVar7 = (piVar10[2] & 0x7fffffffU) * 2;

              if (iVar7 <= iVar5) {

                iVar7 = iVar5;

              }

              FUN_005b3300(piVar10,iVar7,0x30);

            }

            piVar10[1] = local_160 + 1;

            puVar8 = (uint32_t /* width from decompiler */ *)(local_160 * 0x30 + *piVar10);

            iVar5 = local_15c + local_170;

            *puVar8 = *(uint32_t /* width from decompiler */ *)(local_15c + local_170);

            puVar8[1] = *(uint32_t /* width from decompiler */ *)(iVar5 + 4);

            puVar8[2] = *(uint32_t /* width from decompiler */ *)(iVar5 + 8);

            puVar8[3] = *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc);

            puVar11 = (uint32_t /* width from decompiler */ *)(local_170 + 0x10 + local_15c);

            puVar8[4] = *puVar11;

            puVar8[5] = puVar11[1];

            puVar8[6] = puVar11[2];

            puVar8[7] = puVar11[3];

            *(uint16_t *)(puVar8 + 8) =

                 *(uint16_t *)(iVar12 + *(int *)(iVar6 + 0x90 + local_15c));

            iVar5 = local_15c;

          }

        }

        iVar12 = iVar12 + 2;

        local_16c = local_16c + 1;

        local_170 = local_170 + 0x30;

      } while (iVar12 < 0x12);

      local_164 = local_164 + 1;

      iVar6 = iVar6 + 0xa0;

    } while (local_164 < (int)local_158);

  }

  piVar10 = DAT_00b05060;

  iVar5 = iStack_14c * 0xa0;

  if ((iVar5 == 0) || ((iStack_150 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    piVar13 = DAT_00b05060 + 3;

    DAT_00b05060[2] = DAT_00b05060[2] + iStack_14c * -0xa0;

    piVar10[3] = *piVar13 + iVar5;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(iStack_150,iVar5);

  }

  if (-1 < (int)uStack_154) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_15c,(uStack_154 & 0x7fffffff) * 0xa0,0x12);

  }

  return;

}
