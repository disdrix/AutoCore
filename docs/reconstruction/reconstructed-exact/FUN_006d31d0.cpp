// =============================================================================
// FUN_006d31d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006d31d0
// Address:   0x006d31d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d31d0 @ 0x006d31d0
// Stable ID: aa_006d31d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~328 non-empty decompiler lines.
//  - Control keywords: if×22, do×6, while×6, return×1.
//  - Notable callees: FUN_005b3370×2, FUN_006cb7d0, FUN_006d3040, FUN_006d31d0, FUN_006e1ae0, FUN_006ea6f0.
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

void __thiscall FUN_006d31d0(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,int *param_4,int *param_5)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  short sVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint16_t uVar7;

  int iVar8;

  int *piVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ *puVar12;

  int iVar13;

  int *piVar14;

  float *pfVar15;

  int local_1dc;

  int iStack_1d8;

  int local_1d4;

  int local_1d0;

  int *local_1cc;

  uint uStack_1c8;

  int iStack_1c4;

  int iStack_1c0;

  int local_1bc;

  int *local_1b8;

  int local_1b4;

  uint8_t auStack_1b0 [8];

  int local_1a8;

  int *local_1a4;

  uint32_t /* width from decompiler */ *puStack_1a0;

  float *pfStack_19c;

  int iStack_198;

  uint32_t /* width from decompiler */ *puStack_194;

  uint32_t /* width from decompiler */ *puStack_190;

  uint32_t /* width from decompiler */ *puStack_18c;

  uint32_t /* width from decompiler */ *puStack_188;

  uint32_t /* width from decompiler */ *puStack_184;

  uint32_t /* width from decompiler */ uStack_178;

  uint32_t /* width from decompiler */ uStack_174;

  uint32_t /* width from decompiler */ uStack_170;

  uint32_t /* width from decompiler */ uStack_16c;

  uint32_t /* width from decompiler */ uStack_168;

  uint32_t /* width from decompiler */ uStack_164;

  uint32_t /* width from decompiler */ uStack_160;

  uint32_t /* width from decompiler */ uStack_15c;

  uint32_t /* width from decompiler */ uStack_158;

  uint32_t /* width from decompiler */ uStack_154;

  int local_150;

  int local_14c;

  int local_148;

  int *local_144;

  uint32_t /* width from decompiler */ uStack_138;

  uint32_t /* width from decompiler */ uStack_134;

  uint32_t /* width from decompiler */ uStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  uint32_t /* width from decompiler */ uStack_128;

  uint32_t /* width from decompiler */ uStack_124;

  uint32_t /* width from decompiler */ uStack_118;

  uint32_t /* width from decompiler */ uStack_114;

  uint8_t local_110 [268];

  

  local_148 = param_3[2];

  local_144 = param_3;

  local_150 = *(int *)(*param_3 + 0xc);

  local_14c = param_3[1];

  local_1bc = param_1;

  FUN_006ea6f0(param_2,&local_150,param_4,&LAB_006ea160);

  FUN_006d3040(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

  local_1a8 = param_3[2];

  local_1b4 = local_150;

  local_1a4 = param_3;

  local_1d4 = 0;

  if (0 < *(int *)(param_1 + 0x10)) {

    local_1dc = 0;

    do {

      piVar14 = (int *)(*(int *)(param_1 + 0xc) + local_1dc);

      iVar8 = FUN_006cb7d0();

      if (piVar14[2] != iVar8) {

        piVar9 = (int *)(**(code **)(**(int **)(local_1b4 + 0xc) + 0x34))(*piVar14,local_110);

        piVar4 = (int *)*param_2;

        local_1b4 = *piVar14;

        local_1b8 = piVar9;

        (**(code **)(*piVar9 + 0x14))();

        iVar8 = (**(code **)(*piVar4 + 0x14))();

        if (*(undefined **)(*param_4 + 0x18c + (iVar8 * 0x20 + iStack_1d8) * 4) == &DAT_006e1a40) {

          if (local_1cc == (int *)(uStack_1c8 & 0x7fffffff)) {

            FUN_005b3370(&local_1d0,0x30);

          }

          iVar13 = piVar14[2];

          iVar8 = ((int)local_1cc + (int)((int)local_1cc + 1U) * 2 + -2) * 0x10;

          *(int *)(iVar8 + 0x20 + local_1d0) = iVar13;

          *(int **)(iVar8 + 0x24 + local_1d0) = piVar9;

          *(int *)(iVar8 + 0x28 + local_1d0) = *piVar14;

          *(uint32_t /* width from decompiler */ *)(iVar8 + 0xc + local_1d0) = 0x7f7fffff;

          iVar8 = iVar8 + local_1d0;

          local_1cc = (int *)((int)local_1cc + 1U);

          uVar10 = FUN_006e1ae0(param_2,auStack_1b0,param_4,iVar13 + 0x10,iVar8);

          *(uint32_t /* width from decompiler */ *)(iVar8 + 0x2c) = uVar10;

        }

        else {

          (**(code **)(*(int *)piVar14[2] + 0x10))(param_2,auStack_1b0,param_4,param_5);

        }

      }

      local_1d4 = local_1d4 + 1;

      local_1dc = local_1dc + 0xc;

      param_1 = local_1bc;

    } while (local_1d4 < *(int *)(local_1bc + 0x10));

  }

  local_1b8 = local_1cc;

  local_1dc = 0;

  if (0 < (int)local_1cc) {

    local_1d4 = 0;

    piVar14 = local_1cc;

    do {

      fVar1 = *(float *)(local_1d4 + 0xc + local_1d0);

      puVar12 = (uint32_t /* width from decompiler */ *)(local_1d4 + local_1d0);

      iVar13 = local_1dc;

      iVar8 = local_1dc;

      if (3 < (int)piVar14 - local_1dc) {

        pfVar15 = (float *)(puVar12 + 0xf);

        do {

          if (pfVar15[-0xc] < fVar1) {

            fVar1 = pfVar15[-0xc];

            iVar8 = iVar13;

          }

          if (*pfVar15 < fVar1) {

            iVar8 = iVar13 + 1;

            fVar1 = *pfVar15;

          }

          if (pfVar15[0xc] < fVar1) {

            iVar8 = iVar13 + 2;

            fVar1 = pfVar15[0xc];

          }

          if (pfVar15[0x18] < fVar1) {

            iVar8 = iVar13 + 3;

            fVar1 = pfVar15[0x18];

          }

          iVar13 = iVar13 + 4;

          pfVar15 = pfVar15 + 0x30;

        } while (iVar13 < (int)((int)piVar14 - 3U));

      }

      if (iVar13 < (int)piVar14) {

        pfVar15 = (float *)(iVar13 * 0x30 + 0xc + local_1d0);

        do {

          if (*pfVar15 < fVar1) {

            fVar1 = *pfVar15;

            iVar8 = iVar13;

          }

          iVar13 = iVar13 + 1;

          pfVar15 = pfVar15 + 0xc;

        } while (iVar13 < (int)piVar14);

      }

      iVar8 = iVar8 * 0x30;

      uStack_138 = *(uint32_t /* width from decompiler */ *)(iVar8 + 8 + local_1d0);

      uVar10 = *(uint32_t /* width from decompiler */ *)(iVar8 + local_1d0);

      uStack_118 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0x28 + local_1d0);

      uVar2 = *(uint32_t /* width from decompiler */ *)(iVar8 + 4 + local_1d0);

      puVar11 = (uint32_t /* width from decompiler */ *)(iVar8 + local_1d0);

      uVar5 = puVar11[9];

      uStack_134 = puVar11[3];

      uStack_114 = puVar11[0xb];

      uStack_130 = puVar11[4];

      uStack_12c = puVar11[5];

      uStack_128 = puVar11[6];

      uStack_124 = puVar11[7];

      *puVar11 = *puVar12;

      puVar11[1] = puVar12[1];

      puVar11[2] = puVar12[2];

      puVar11[3] = puVar12[3];

      uVar6 = puVar11[8];

      puVar11[4] = puVar12[4];

      puVar11[5] = puVar12[5];

      puVar11[6] = puVar12[6];

      puVar11[7] = puVar12[7];

      puVar11[8] = puVar12[8];

      puVar11[9] = puVar12[9];

      puVar11[10] = puVar12[10];

      puVar11[0xb] = puVar12[0xb];

      *puVar12 = uVar10;

      puVar12[2] = uStack_138;

      puVar12[1] = uVar2;

      puVar12[3] = uStack_134;

      puVar12[4] = uStack_130;

      puVar12[5] = uStack_12c;

      puVar12[6] = uStack_128;

      puVar12[7] = uStack_124;

      puVar12[8] = uVar6;

      puVar12[0xb] = uStack_114;

      puVar12[9] = uVar5;

      puVar12[10] = uStack_118;

      iStack_198 = local_1dc + 1;

      pfStack_19c = (float *)(local_1d4 + local_1d0);

      if (iStack_198 < (int)piVar14) {

        iVar8 = local_1d4 + 0x30;

        iVar13 = (int)piVar14 * 0x30;

        local_1dc = iStack_198;

        iStack_1d8 = iVar13;

        do {

          if (((*(int *)(local_1d0 + 0x2c + iVar8) != 2) ||

              (*(float *)(local_1d0 + 0xc + iVar8) < DAT_00aaa6d4)) ||

             (fVar1 = (*(float *)(local_1d0 + iVar8) - *pfStack_19c) * pfStack_19c[4] +

                      (*(float *)(local_1d0 + 4 + iVar8) - pfStack_19c[1]) * pfStack_19c[5] +

                      (*(float *)(local_1d0 + 8 + iVar8) - pfStack_19c[2]) * pfStack_19c[6],

             fVar1 < *(float *)(param_4[3] + 0xc) == (fVar1 == *(float *)(param_4[3] + 0xc)))) {

            local_1dc = local_1dc + 1;

            iVar8 = iVar8 + 0x30;

          }

          else {

            *(uint32_t /* width from decompiler */ *)(local_1d0 + 0x2c + iVar8) = 0;

            puVar12 = (uint32_t /* width from decompiler */ *)(iVar13 + -0x30 + local_1d0);

            uVar10 = *(uint32_t /* width from decompiler */ *)(local_1d0 + iVar8);

            uStack_170 = *(uint32_t /* width from decompiler */ *)(local_1d0 + 0x10 + iVar8);

            uVar2 = *(uint32_t /* width from decompiler */ *)(local_1d0 + 4 + iVar8);

            puStack_190 = (uint32_t /* width from decompiler */ *)(local_1d0 + 8 + iVar8);

            uStack_178 = *puStack_190;

            puStack_184 = (uint32_t /* width from decompiler */ *)(local_1d0 + 0xc + iVar8);

            uStack_174 = *puStack_184;

            uStack_16c = *(uint32_t /* width from decompiler */ *)(local_1d0 + 0x14 + iVar8);

            puVar11 = (uint32_t /* width from decompiler */ *)(local_1d0 + 0x10 + iVar8);

            uStack_168 = puVar11[2];

            uStack_164 = puVar11[3];

            puStack_188 = (uint32_t /* width from decompiler */ *)(local_1d0 + 0x20 + iVar8);

            uStack_160 = *puStack_188;

            puStack_1a0 = (uint32_t /* width from decompiler */ *)(local_1d0 + 0x24 + iVar8);

            uStack_15c = *puStack_1a0;

            puStack_194 = (uint32_t /* width from decompiler */ *)(local_1d0 + 0x28 + iVar8);

            uStack_158 = *puStack_194;

            puStack_18c = (uint32_t /* width from decompiler */ *)(local_1d0 + 0x2c + iVar8);

            uStack_154 = *puStack_18c;

            *(uint32_t /* width from decompiler */ *)(local_1d0 + iVar8) = *puVar12;

            *(uint32_t /* width from decompiler */ *)(local_1d0 + 4 + iVar8) = puVar12[1];

            *puStack_190 = puVar12[2];

            *puStack_184 = puVar12[3];

            *puVar11 = puVar12[4];

            puVar11[1] = puVar12[5];

            puVar11[2] = puVar12[6];

            puVar11[3] = puVar12[7];

            *puStack_188 = puVar12[8];

            *puStack_1a0 = puVar12[9];

            *puStack_194 = puVar12[10];

            *puStack_18c = puVar12[0xb];

            *puVar12 = uVar10;

            puVar12[2] = uStack_178;

            puVar12[1] = uVar2;

            puVar12[3] = uStack_174;

            puVar12[4] = uStack_170;

            puVar12[5] = uStack_16c;

            puVar12[6] = uStack_168;

            puVar12[7] = uStack_164;

            puVar12[8] = uStack_160;

            puVar12[9] = uStack_15c;

            piVar14 = (int *)((int)local_1b8 - 1);

            puVar12[10] = uStack_158;

            iVar13 = iStack_1d8 + -0x30;

            puVar12[0xb] = uStack_154;

            iStack_1d8 = iVar13;

            local_1b8 = piVar14;

          }

        } while (local_1dc < (int)piVar14);

      }

      local_1d4 = local_1d4 + 0x30;

      local_1dc = iStack_198;

    } while (iStack_198 < (int)piVar14);

  }

  iVar8 = 0;

  iStack_1d8 = 0;

  if (0 < (int)local_1cc) {

    do {

      if (*(int *)(iVar8 + 0x2c + local_1d0) == 0) {

        sVar3 = *(short *)(*(int *)(iVar8 + 0x20 + local_1d0) + 0xc);

        if (sVar3 != -1) {

          (**(code **)(**(int **)(local_1bc + 8) + 8))(sVar3);

          *(uint16_t *)(*(int *)(iVar8 + 0x20 + local_1d0) + 0xc) = 0xffff;

        }

      }

      else {

        piVar14 = (int *)*param_5;

        if (piVar14[1] == (piVar14[2] & 0x7fffffffU)) {

          FUN_005b3370(piVar14,0x30);

        }

        puVar12 = (uint32_t /* width from decompiler */ *)(piVar14[1] * 0x30 + *piVar14);

        piVar14[1] = piVar14[1] + 1;

        iVar13 = iVar8 + local_1d0;

        *puVar12 = *(uint32_t /* width from decompiler */ *)(iVar8 + local_1d0);

        puVar12[1] = *(uint32_t /* width from decompiler */ *)(iVar13 + 4);

        puVar12[2] = *(uint32_t /* width from decompiler */ *)(iVar13 + 8);

        puVar12[3] = *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc);

        puVar12[4] = *(uint32_t /* width from decompiler */ *)(iVar13 + 0x10);

        puVar12[5] = *(uint32_t /* width from decompiler */ *)(iVar13 + 0x14);

        puVar12[6] = *(uint32_t /* width from decompiler */ *)(iVar13 + 0x18);

        puVar12[7] = *(uint32_t /* width from decompiler */ *)(iVar13 + 0x1c);

        if (*(short *)(*(int *)(iVar8 + 0x20 + local_1d0) + 0xc) == -1) {

          local_1a8 = param_3[2];

          local_1a4 = param_3;

          local_1b8 = (int *)(**(code **)(**(int **)(local_1b4 + 0xc) + 0x34))

                                       (*(uint32_t /* width from decompiler */ *)(iVar8 + 0x28 + local_1d0),local_110);

          local_1b4 = *(int *)(iVar8 + iStack_1d8 + 0x28);

          uVar7 = (**(code **)(**(int **)(iStack_1c4 + 8) + 4))(param_2,&local_1b8,param_4,puVar12);

          *(uint16_t *)(*(int *)(iVar8 + iStack_1d8 + 0x20) + 0xc) = uVar7;

        }

        sVar3 = *(short *)(*(int *)(iVar8 + 0x20 + local_1d0) + 0xc);

        if (sVar3 == -1) {

          *(int *)(*param_5 + 4) = *(int *)(*param_5 + 4) + -1;

        }

        else {

          *(short *)(puVar12 + 8) = sVar3;

        }

      }

      iStack_1d8 = iStack_1d8 + 1;

      iVar8 = iVar8 + 0x30;

    } while (iStack_1d8 < (int)local_1cc);

  }

  piVar14 = DAT_00b05060;

  iVar8 = iStack_1c0 * 0x30;

  if ((iVar8 == 0) || ((iStack_1c4 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    piVar4 = DAT_00b05060 + 3;

    DAT_00b05060[2] = DAT_00b05060[2] + iStack_1c0 * -0x30;

    piVar14[3] = *piVar4 + iVar8;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(iStack_1c4,iVar8);

  }

  if (-1 < (int)uStack_1c8) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_1d0,(uStack_1c8 & 0x7fffffff) * 0x30,0x12);

  }

  return;

}
