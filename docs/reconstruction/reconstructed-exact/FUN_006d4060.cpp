// =============================================================================
// FUN_006d4060
// -----------------------------------------------------------------------------
// Stable ID: aa_006d4060
// Address:   0x006d4060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d4060 @ 0x006d4060
// Stable ID: aa_006d4060
// Embedded strings (evidence for future rename):
//   - "TtConvexWelder"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~371 non-empty decompiler lines.
//  - Control keywords: if×23, do×7, while×7, return×1.
//  - Notable callees: FUN_005d6a40×2, FUN_006d3f90×2, rdtsc×2, FUN_006cb7d0, FUN_006d3bb0, FUN_006d3c20, FUN_006d3ca0, FUN_006d4060.
//  - Strings: "TtConvexWelder".
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

void __thiscall

FUN_006d4060(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,uint32_t /* width from decompiler */ *param_4,uint32_t /* width from decompiler */ param_5)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint64_t uVar5;

  int iVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ uVar8;

  char *pcVar9;

  int *piVar10;

  uint8_t *puVar11;

  int iVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint32_t /* width from decompiler */ *puVar14;

  int *piVar15;

  float *pfVar16;

  int local_31c;

  int local_318;

  int local_310;

  uint32_t /* width from decompiler */ local_30c;

  int *piStack_308;

  uint32_t /* width from decompiler */ uStack_304;

  int iStack_300;

  int iStack_2fc;

  int local_2f8;

  int *local_2f4;

  uint32_t /* width from decompiler */ uStack_2f0;

  uint32_t /* width from decompiler */ uStack_2ec;

  uint32_t /* width from decompiler */ uStack_2e8;

  uint32_t /* width from decompiler */ uStack_2e4;

  int local_2e0;

  int local_2dc;

  int local_2d8;

  int *local_2d4;

  uint32_t /* width from decompiler */ uStack_2d0;

  uint32_t /* width from decompiler */ uStack_2cc;

  uint32_t /* width from decompiler */ uStack_2c8;

  uint32_t /* width from decompiler */ uStack_2c4;

  uint8_t auStack_2c0 [8];

  uint32_t /* width from decompiler */ uStack_2b8;

  uint32_t /* width from decompiler */ uStack_2b4;

  uint32_t /* width from decompiler */ uStack_2b0;

  uint32_t /* width from decompiler */ uStack_2ac;

  uint32_t /* width from decompiler */ uStack_2a8;

  uint32_t /* width from decompiler */ uStack_2a4;

  uint32_t /* width from decompiler */ uStack_2a0;

  uint32_t /* width from decompiler */ uStack_29c;

  uint32_t /* width from decompiler */ uStack_290;

  uint32_t /* width from decompiler */ uStack_28c;

  uint32_t /* width from decompiler */ uStack_288;

  uint32_t /* width from decompiler */ uStack_284;

  uint32_t /* width from decompiler */ uStack_280;

  uint32_t /* width from decompiler */ uStack_27c;

  uint32_t /* width from decompiler */ uStack_278;

  uint32_t /* width from decompiler */ uStack_274;

  uint32_t /* width from decompiler */ uStack_270;

  uint32_t /* width from decompiler */ uStack_26c;

  uint32_t /* width from decompiler */ uStack_268;

  uint32_t /* width from decompiler */ uStack_264;

  uint32_t /* width from decompiler */ uStack_260;

  uint32_t /* width from decompiler */ uStack_25c;

  uint32_t /* width from decompiler */ uStack_258;

  uint32_t /* width from decompiler */ uStack_254;

  uint32_t /* width from decompiler */ uStack_248;

  uint8_t uStack_244;

  uint8_t uStack_243;

  int local_234;

  int iStack_22c;

  int iStack_228;

  int iStack_224;

  uint8_t *local_220;

  int *local_21c;

  int local_218;

  uint8_t local_210 [524];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtConvexWelder";

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_2d8 = param_3[2];

  local_2d4 = param_3;

  local_2e0 = *(int *)(*param_3 + 0xc);

  local_2dc = param_3[1];

  local_310 = param_1;

  FUN_006ea6f0(param_2,&local_2e0,param_4,&LAB_006ea160);

  local_220 = local_210;

  local_21c = (int *)0x0;

  local_218 = -0x7ffffffc;

  FUN_006d3bb0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

  iVar12 = local_2e0;

  local_2f8 = param_3[2];

  local_2f4 = param_3;

  local_30c = 0;

  if (0 < *(int *)(param_1 + 0x10)) {

    local_31c = 0;

    local_318 = local_234;

    do {

      puVar13 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + local_31c);

      iVar6 = FUN_006cb7d0();

      if (puVar13[2] != iVar6) {

        piVar7 = (int *)(**(code **)(**(int **)(iVar12 + 0xc) + 0x34))(*puVar13,local_318);

        piVar10 = (int *)*param_2;

        uStack_304 = *puVar13;

        piStack_308 = piVar7;

        uVar8 = (**(code **)(*piVar7 + 0x14))();

        uVar8 = (**(code **)(*piVar10 + 0x14))(uVar8);

        pcVar9 = (char *)(*(code *)PTR_FUN_00af58b4)((int)&local_30c + 3,*param_4,uVar8);

        if (*pcVar9 == '\0') {

          (**(code **)(*(int *)puVar13[2] + 0x10))(param_2,&piStack_308,param_4,param_5);

        }

        else {

          piVar10 = (int *)puVar13[2];

          (**(code **)(*piVar10 + 0x20))(&local_310,param_2,&piStack_308,param_4,&uStack_2c8);

          FUN_006d3ca0();

          *(int **)(local_220 + (int)local_21c * 0x80 + -0x10) = piVar10;

          uVar8 = *puVar13;

          *(int **)(local_220 + (int)local_21c * 0x80 + -0xc) = piVar7;

          *(uint32_t /* width from decompiler */ *)(local_220 + (int)local_21c * 0x80 + -8) = uVar8;

          local_220[(int)local_21c * 0x80 + -3] = (char)piStack_308;

          if ((char)piStack_308 != '\0') {

            FUN_006d3c20(auStack_2c0);

            FUN_005d6a40(local_2f8 + 0x20,&uStack_280);

            puVar13 = (uint32_t /* width from decompiler */ *)(local_220 + (int)local_21c * 0x80 + -0x30);

            *puVar13 = uStack_290;

            puVar13[1] = uStack_28c;

            puVar13[2] = uStack_288;

            puVar13[3] = uStack_284;

            puVar13[4] = uStack_2d0;

            puVar13[5] = uStack_2cc;

            puVar13[6] = uStack_2c8;

            puVar13[7] = uStack_2c4;

            puVar13[3] = uStack_2a0;

            if ((*(char *)((int)piVar10 + 0x15) == '\x01') ||

               (*(char *)((int)piVar10 + 0x15) == '\x02')) {

              local_220[(int)local_21c * 0x80 + -4] = 1;

            }

            else {

              local_220[(int)local_21c * 0x80 + -4] = 0;

            }

          }

        }

      }

      local_318 = local_318 + 0x100;

      local_30c = local_30c + 1;

      local_31c = local_31c + 0xc;

      param_1 = local_310;

    } while (local_30c < *(int *)(local_310 + 0x10));

  }

  local_318 = 0;

  piVar10 = local_21c;

  if (0 < (int)local_21c) {

    local_31c = 0;

    do {

      fVar1 = *(float *)(local_220 + local_31c + 0x20);

      puVar13 = (uint32_t /* width from decompiler */ *)(local_220 + local_31c);

      iVar6 = local_318;

      iVar12 = local_318;

      if (3 < (int)piVar10 - local_318) {

        pfVar16 = (float *)(puVar13 + 0x28);

        do {

          if (pfVar16[-0x20] < fVar1) {

            fVar1 = pfVar16[-0x20];

            iVar12 = iVar6;

          }

          if (*pfVar16 < fVar1) {

            iVar12 = iVar6 + 1;

            fVar1 = *pfVar16;

          }

          if (pfVar16[0x20] < fVar1) {

            iVar12 = iVar6 + 2;

            fVar1 = pfVar16[0x20];

          }

          if (pfVar16[0x40] < fVar1) {

            iVar12 = iVar6 + 3;

            fVar1 = pfVar16[0x40];

          }

          iVar6 = iVar6 + 4;

          pfVar16 = pfVar16 + 0x80;

        } while (iVar6 < (int)piVar10 + -3);

      }

      if (iVar6 < (int)piVar10) {

        pfVar16 = (float *)(local_220 + iVar6 * 0x80 + 0x20);

        do {

          if (*pfVar16 < fVar1) {

            fVar1 = *pfVar16;

            iVar12 = iVar6;

          }

          iVar6 = iVar6 + 1;

          pfVar16 = pfVar16 + 0x20;

        } while (iVar6 < (int)piVar10);

      }

      puVar14 = (uint32_t /* width from decompiler */ *)(local_220 + iVar12 * 0x80);

      uStack_2b8 = puVar14[2];

      uVar8 = *puVar14;

      uVar2 = puVar14[1];

      uStack_2b4 = puVar14[3];

      uStack_2b0 = puVar14[4];

      uStack_2ac = puVar14[5];

      uStack_2a8 = puVar14[6];

      uStack_2a4 = puVar14[7];

      uStack_2a0 = puVar14[8];

      uStack_29c = puVar14[9];

      uStack_290 = puVar14[0xc];

      uStack_28c = puVar14[0xd];

      uStack_288 = puVar14[0xe];

      uStack_284 = puVar14[0xf];

      uStack_280 = puVar14[0x10];

      uStack_27c = puVar14[0x11];

      uStack_278 = puVar14[0x12];

      uStack_274 = puVar14[0x13];

      uStack_270 = puVar14[0x14];

      uStack_26c = puVar14[0x15];

      uStack_268 = puVar14[0x16];

      uStack_264 = puVar14[0x17];

      uStack_260 = puVar14[0x18];

      uStack_25c = puVar14[0x19];

      uStack_258 = puVar14[0x1a];

      uStack_254 = puVar14[0x1b];

      uVar3 = puVar14[0x1c];

      uVar4 = puVar14[0x1d];

      uStack_248 = puVar14[0x1e];

      uStack_244 = *(uint8_t *)(puVar14 + 0x1f);

      uStack_243 = *(uint8_t *)((int)puVar14 + 0x7d);

      *puVar14 = *puVar13;

      puVar14[1] = puVar13[1];

      puVar14[2] = puVar13[2];

      puVar14[3] = puVar13[3];

      puVar14[4] = puVar13[4];

      puVar14[5] = puVar13[5];

      puVar14[6] = puVar13[6];

      puVar14[7] = puVar13[7];

      puVar14[8] = puVar13[8];

      puVar14[9] = puVar13[9];

      puVar14[0xc] = puVar13[0xc];

      puVar14[0xd] = puVar13[0xd];

      puVar14[0xe] = puVar13[0xe];

      puVar14[0xf] = puVar13[0xf];

      puVar14[0x10] = puVar13[0x10];

      puVar14[0x11] = puVar13[0x11];

      puVar14[0x12] = puVar13[0x12];

      puVar14[0x13] = puVar13[0x13];

      puVar14[0x14] = puVar13[0x14];

      puVar14[0x15] = puVar13[0x15];

      puVar14[0x16] = puVar13[0x16];

      puVar14[0x17] = puVar13[0x17];

      puVar14[0x18] = puVar13[0x18];

      puVar14[0x19] = puVar13[0x19];

      puVar14[0x1a] = puVar13[0x1a];

      puVar14[0x1b] = puVar13[0x1b];

      puVar14[0x1c] = puVar13[0x1c];

      puVar14[0x1d] = puVar13[0x1d];

      puVar14[0x1e] = puVar13[0x1e];

      *(uint8_t *)(puVar14 + 0x1f) = *(uint8_t *)(puVar13 + 0x1f);

      *(uint8_t *)((int)puVar14 + 0x7d) = *(uint8_t *)((int)puVar13 + 0x7d);

      *puVar13 = uVar8;

      puVar13[1] = uVar2;

      puVar13[2] = uStack_2b8;

      puVar13[3] = uStack_2b4;

      puVar13[4] = uStack_2b0;

      puVar13[5] = uStack_2ac;

      puVar13[6] = uStack_2a8;

      puVar13[7] = uStack_2a4;

      puVar13[8] = uStack_2a0;

      puVar13[9] = uStack_29c;

      puVar13[0xc] = uStack_290;

      puVar13[0xd] = uStack_28c;

      puVar13[0xe] = uStack_288;

      puVar13[0xf] = uStack_284;

      puVar13[0x10] = uStack_280;

      puVar13[0x11] = uStack_27c;

      puVar13[0x12] = uStack_278;

      puVar13[0x13] = uStack_274;

      puVar13[0x14] = uStack_270;

      puVar13[0x15] = uStack_26c;

      puVar13[0x16] = uStack_268;

      puVar13[0x17] = uStack_264;

      puVar13[0x18] = uStack_260;

      puVar13[0x19] = uStack_25c;

      puVar13[0x1a] = uStack_258;

      puVar13[0x1b] = uStack_254;

      puVar13[0x1e] = uStack_248;

      puVar13[0x1c] = uVar3;

      puVar13[0x1d] = uVar4;

      *(uint8_t *)(puVar13 + 0x1f) = uStack_244;

      *(uint8_t *)((int)puVar13 + 0x7d) = uStack_243;

      if (local_220[local_31c + 0x7d] != '\0') {

        piVar10 = (int *)FUN_006d3f90(local_220 + local_31c + 0x50,&local_220,local_318 + 1,piVar10,

                                      param_4[3]);

      }

      local_318 = local_318 + 1;

      local_31c = local_31c + 0x80;

    } while (local_318 < (int)piVar10);

  }

  piVar7 = local_21c;

  if (0 < (int)local_21c) {

    local_31c = 0;

    piStack_308 = local_21c;

    do {

      iVar12 = *(int *)(*(int *)(local_220 + local_31c + 0x70) + 0x18);

      if (0 < iVar12) {

        piVar15 = (int *)(*(int *)(local_220 + local_31c + 0x70) + 0x48);

        local_30c = iVar12;

        do {

          iStack_2fc = piVar15[-1];

          local_2f8 = *piVar15;

          iStack_300 = piVar15[-2];

          local_2f4 = (int *)piVar15[5];

          FUN_005d6a40(param_3[2] + 0x20,piVar15 + 2);

          uStack_2ec = uStack_2cc;

          uStack_2e8 = uStack_2c8;

          uStack_2f0 = uStack_2d0;

          uStack_2e4 = uStack_2c4;

          piVar10 = (int *)FUN_006d3f90(&iStack_300,&local_220,0,piVar10,param_4[3]);

          piVar15 = piVar15 + 0xc;

          local_30c = local_30c + -1;

        } while (local_30c != 0);

      }

      local_31c = local_31c + 0x80;

      piStack_308 = (int *)((int)piStack_308 + -1);

    } while (piStack_308 != (int *)0x0);

    piStack_308 = (int *)0x0;

  }

  local_318 = 0;

  if (0 < (int)piVar7) {

    local_31c = 0;

    do {

      local_2f8 = param_3[2];

      puVar11 = local_220 + local_31c;

      local_2f4 = param_3;

      iStack_2fc = *(int *)(puVar11 + 0x78);

      iStack_300 = *(int *)(puVar11 + 0x74);

      iVar12 = *(int *)(puVar11 + 0x70);

      if ((local_318 < (int)piVar10) && (puVar11[0x7d] != '\0')) {

        FUN_006f5de0(param_2,&iStack_300,param_4,puVar11,*(uint32_t /* width from decompiler */ *)(local_310 + 8),

                     iVar12 + 0x30,iVar12 + 0x18);

      }

      FUN_006f60b0(param_2,&iStack_300,param_4,

                   *(float *)(local_220 + local_31c + 0x20) - g_flMsToSeconds_Inferred,iVar12 + 0x30

                   ,iVar12 + 0x18,param_5,*(uint32_t /* width from decompiler */ *)(local_310 + 8));

      local_318 = local_318 + 1;

      local_31c = local_31c + 0x80;

    } while (local_318 < (int)piVar7);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  piVar10 = DAT_00b05060;

  iVar12 = iStack_224 * 0x100;

  if ((iVar12 == 0) || ((iStack_228 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    piVar7 = DAT_00b05060 + 3;

    DAT_00b05060[2] = DAT_00b05060[2] + iStack_224 * -0x100;

    piVar10[3] = *piVar7 + iVar12;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(iStack_228,iVar12);

  }

  if (-1 < iStack_22c) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_234,iStack_22c << 8,0x12);

  }

  if (-1 < local_218) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_220,local_218 << 7,0x12);

  }

  return;

}
