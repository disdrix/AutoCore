// =============================================================================
// FUN_00991e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00991e60
// Address:   0x00991e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00991e60 @ 0x00991e60
// Stable ID: aa_00991e60
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp"
//   - "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo..."
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp"
//   - "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo..."
//   - "After adding degenerate quads at sharp edges: %d verts, %d faces"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~683 non-empty decompiler lines.
//  - Control keywords: if×43, do×10, while×10, goto×4, return×4, for×3.
//  - Notable callees: FUN_00443b40×9, CONCAT22×4, vog_LogMessage×3, FUN_00454290×2, SQRT×2, CONCAT31, FUN_00414a50, FUN_00414b60.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp"; "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp"; "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp".
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



void FUN_00991e60(int param_1,int param_2,float *param_3)



{

  int *piVar1;

  char cVar2;

  int *piVar3;

  int **ppiVar4;

  uint32_t /* width from decompiler */ *puVar5;

  float *pfVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  float *pfVar9;

  int iVar10;

  int extraout_EDX;

  int extraout_EDX_00;

  uint16_t uVar11;

  uint16_t extraout_var;

  uint16_t *puVar12;

  uint16_t uVar13;

  float *pfVar14;

  char *pcVar15;

  void *pvVar16;

  int *piVar17;

  uint32_t /* width from decompiler */ *puVar18;

  float10 fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  float fVar25;

  float afStackY_97c [345];

  int local_3d8;

  float *local_3d4;

  void *local_3cc;

  uint16_t *local_3c8;

  int local_3c4;

  float *local_3c0;

  int *local_3bc;

  char local_3b8 [4];

  char local_3b4 [4];

  uint8_t local_3b0 [4];

  int *local_3ac;

  uint32_t /* width from decompiler */ local_3a8;

  void *local_3a4;

  int local_3a0;

  int local_39c;

  int local_394;

  int local_390;

  uint32_t /* width from decompiler */ local_38c;

  float *local_388 [3];

  float local_37c [4];

  uint32_t /* width from decompiler */ local_36c;

  float local_368;

  uint32_t /* width from decompiler */ uStack_364;

  uint32_t /* width from decompiler */ uStack_360;

  uint32_t /* width from decompiler */ uStack_35c;

  uint32_t /* width from decompiler */ uStack_358;

  uint32_t /* width from decompiler */ uStack_354;

  uint32_t /* width from decompiler */ uStack_350;

  uint32_t /* width from decompiler */ uStack_34c;

  uint32_t /* width from decompiler */ uStack_348;

  uint32_t /* width from decompiler */ uStack_344;

  uint32_t /* width from decompiler */ uStack_340;

  uint32_t /* width from decompiler */ uStack_33c;

  uint32_t /* width from decompiler */ uStack_338;

  uint32_t /* width from decompiler */ uStack_334;

  uint32_t /* width from decompiler */ uStack_330;

  uint32_t /* width from decompiler */ uStack_32c;

  float local_328;

  float local_324;

  float local_320;

  float local_31c;

  float local_318;

  float local_314;

  int aiStack_310 [3];

  float local_304;

  int local_300;

  int local_2fc;

  uint32_t /* width from decompiler */ local_2f8;

  uint32_t /* width from decompiler */ local_2f4;

  uint32_t /* width from decompiler */ local_2f0;

  float local_2ec;

  float local_2e8;

  float local_2e4;

  float local_2e0;

  float local_2dc;

  float local_2d8;

  float local_2d4;

  int *local_2d0;

  int local_2cc;

  uint8_t local_2c8 [4];

  uint32_t /* width from decompiler */ *local_2c4;

  uint32_t /* width from decompiler */ local_2c0;

  uint32_t /* width from decompiler */ local_2bc;

  uint32_t /* width from decompiler */ local_2b8;

  uint32_t /* width from decompiler */ local_2b4;

  int local_2b0 [3];

  float local_2a4;

  float local_2a0;

  float local_29c;

  float local_298;

  float local_294;

  float local_290;

  float local_28c;

  float local_288;

  float local_284;

  float afStack_280 [4];

  uint32_t /* width from decompiler */ uStack_270;

  uint32_t /* width from decompiler */ uStack_26c;

  uint32_t /* width from decompiler */ uStack_268;

  uint32_t /* width from decompiler */ uStack_264;

  uint32_t /* width from decompiler */ uStack_260;

  uint32_t /* width from decompiler */ uStack_25c;

  uint32_t /* width from decompiler */ uStack_258;

  uint32_t /* width from decompiler */ uStack_254;

  uint32_t /* width from decompiler */ uStack_250;

  uint32_t /* width from decompiler */ uStack_24c;

  uint32_t /* width from decompiler */ uStack_248;

  uint32_t /* width from decompiler */ uStack_244;

  uint32_t /* width from decompiler */ uStack_240;

  uint32_t /* width from decompiler */ uStack_23c;

  uint32_t /* width from decompiler */ uStack_238;

  uint32_t /* width from decompiler */ uStack_234;

  uint32_t /* width from decompiler */ uStack_230;

  int iStack_22c;

  int iStack_228;

  float local_224;

  uint32_t /* width from decompiler */ auStack_218 [21];

  char acStack_1c4 [8];

  float fStack_1bc;

  float fStack_1b8;

  float fStack_1b4;

  float local_15c [16];

  float local_11c [20];

  int aiStack_cc [46];

  uint32_t /* width from decompiler */ uStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b220a;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_3ac = (int *)FUN_00455530();

  *(uint8_t *)((int)local_3ac + 0x81) = 1;

  local_3ac[1] = (int)local_3ac;

  *local_3ac = (int)local_3ac;

  local_3ac[2] = (int)local_3ac;

  local_3a8 = 0;

  local_394 = 0;

  local_390 = 0;

  local_38c = 0;

  puVar12 = (uint16_t *)0x0;

  local_3cc = (void *)0x0;

  local_3c8 = (uint16_t *)0x0;

  local_3c4 = 0;

  local_4 = 2;

  iVar8 = *(int *)(param_1 + 4);

  if (*(int *)(iVar8 + 0x10) == 0) {

    local_3a4 = (void *)0x0;

  }

  else {

    local_3a4 = (void *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar8 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar8 + 0x18),4);

  }

  iVar8 = *(int *)(param_2 + 4);

  fVar19 = (float10)fcos((float10)*(float *)(DAT_00d1f048 + 0x18) * (float10)DAT_00a27c54);

  local_304 = (float)fVar19;

  if (*(int *)(iVar8 + 0x10) != 0) {

    local_2cc = FUN_00743be0(*(uint32_t /* width from decompiler */ *)(iVar8 + 0x18),*(uint32_t /* width from decompiler */ *)(iVar8 + 0x1c),0x810);

    if ((local_2cc != 0) && (local_3a4 != (void *)0x0)) {

      if (*(int *)(param_2 + 4) == 0) {

        local_39c = 0;

      }

      else {

        local_39c = *(int *)(*(int *)(param_2 + 4) + 0x1c);

      }

      local_3a0 = 0;

      if (0 < local_39c) {

        local_300 = 1 - (int)local_3b4;

        local_2fc = 2 - (int)local_3b8;

        do {

          iVar8 = (uint)*(ushort *)(local_2cc + 2 + local_3a0 * 2) * 0x60;

          local_388[1] = (float *)(iVar8 + (int)local_3a4);

          iVar10 = (uint)*(ushort *)(local_2cc + local_3a0 * 2) * 0x60;

          fVar24 = *(float *)(iVar8 + 8 + (int)local_3a4) - *(float *)(iVar10 + 8 + (int)local_3a4);

          fVar25 = *(float *)(iVar8 + 4 + (int)local_3a4) - *(float *)(iVar10 + 4 + (int)local_3a4);

          fVar20 = *(float *)(iVar8 + (int)local_3a4) - *(float *)(iVar10 + (int)local_3a4);

          local_388[0] = (float *)(iVar10 + (int)local_3a4);

          iVar8 = (uint)*(ushort *)(local_2cc + 4 + local_3a0 * 2) * 0x60;

          fVar22 = *(float *)(iVar8 + 8 + (int)local_3a4) - local_388[0][2];

          fVar23 = *(float *)(iVar8 + 4 + (int)local_3a4) - local_388[0][1];

          fVar21 = *(float *)(iVar8 + (int)local_3a4) - *local_388[0];

          local_2ec = fVar25 * fVar22 - fVar24 * fVar23;

          local_2e4 = fVar20 * fVar23 - fVar21 * fVar25;

          local_37c[0] = local_2ec;

          local_2e8 = fVar21 * fVar24 - fVar20 * fVar22;

          local_37c[2] = local_2e4;

          local_37c[1] = local_2e8;

          local_388[2] = (float *)(iVar8 + (int)local_3a4);

          fVar20 = SQRT(local_2ec * local_2ec + local_2e8 * local_2e8 + local_2e4 * local_2e4);

          if ((_DAT_00a240ec <= fVar20) || (fVar20 <= DAT_00aaa640)) {

            fVar20 = g_flOne / fVar20;

            local_37c[0] = local_2ec * fVar20;

            local_37c[1] = fVar20 * local_2e8;

            local_37c[2] = fVar20 * local_2e4;

          }

          local_3c0 = (float *)0x1;

          local_3d4 = local_37c + 5;

          pfVar9 = local_388[0];

          pfVar6 = (float *)(iVar8 + (int)local_3a4);

          do {

            iVar8 = 0;

            local_2b0[0] = -1;

            local_2b0[1] = 0xffffffff;

            local_2b0[2] = 0xffffffff;

            if (0 < (int)param_3) {

              do {

                iVar10 = 0;

                do {

                  if ((float *)(int)*(char *)(*(int *)((int)local_388 + iVar10) + 0x58 + iVar8) ==

                      local_3c0) {

                    *(int *)((int)local_2b0 + iVar10) = iVar8;

                  }

                  iVar10 = iVar10 + 4;

                } while (iVar10 < 0xc);

                iVar8 = iVar8 + 1;

              } while (iVar8 < (int)param_3);

            }

            pfVar14 = &local_2a4;

            iVar8 = 0;

            do {

              if (*(int *)((int)local_2b0 + iVar8) == -1) {

                local_2f8 = 0;

                *pfVar14 = 0.0;

                local_2f4 = 0;

                pfVar14[1] = 0.0;

                local_2f0 = 0;

                pfVar14[2] = 0.0;

              }

              else {

                pfVar6 = (float *)(*(int *)((int)local_388 + iVar8) +

                                  (*(int *)((int)local_2b0 + iVar8) * 3 + 3) * 4);

                *pfVar14 = *pfVar6;

                fVar20 = pfVar6[2];

                pfVar14[1] = pfVar6[1];

                pfVar14[2] = fVar20;

                pfVar6 = local_388[2];

              }

              iVar8 = iVar8 + 4;

              pfVar14 = pfVar14 + 3;

            } while (iVar8 < 0xc);

            local_224 = local_2a4 + *pfVar9;

            fVar20 = (pfVar6[2] + local_284) - (pfVar9[2] + local_29c);

            fVar21 = (pfVar6[1] + local_288) - (pfVar9[1] + local_2a0);

            fVar23 = (local_388[1][2] + local_290) - (pfVar9[2] + local_29c);

            fVar22 = (*pfVar6 + local_28c) - local_224;

            fVar25 = (*local_388[1] + local_298) - local_224;

            fVar24 = (local_388[1][1] + local_294) - (pfVar9[1] + local_2a0);

            local_2dc = fVar24 * fVar20 - fVar23 * fVar21;

            pfVar9 = local_3d4 + -2;

            local_2d8 = fVar23 * fVar22 - fVar25 * fVar20;

            *pfVar9 = local_2dc;

            local_3d4[-1] = local_2d8;

            local_2d4 = fVar25 * fVar21 - fVar24 * fVar22;

            *local_3d4 = local_2d4;

            local_2e0 = *pfVar9 * *pfVar9 + local_3d4[-1] * local_3d4[-1] + *local_3d4 * *local_3d4;

            fVar20 = SQRT(local_2e0);

            if ((_DAT_00a240ec <= fVar20) || (fVar20 <= DAT_00aaa640)) {

              fVar20 = g_flOne / fVar20;

              *pfVar9 = *pfVar9 * fVar20;

              local_3d4[-1] = fVar20 * local_3d4[-1];

              *local_3d4 = fVar20 * *local_3d4;

            }

            local_3c0 = (float *)((int)local_3c0 + 1);

            local_3d4 = local_3d4 + 3;

            pfVar9 = local_388[0];

            pfVar6 = local_388[2];

          } while ((int)local_3c0 < 7);

          iVar8 = 0;

          local_3c0 = local_11c;

          local_3d4 = local_15c;

          do {

            pfVar9 = local_388[iVar8];

            local_3d4[-3] = *pfVar9;

            fVar20 = pfVar9[2];

            local_3d4[-2] = pfVar9[1];

            local_3d4[-1] = fVar20;

            pfVar6 = local_388[(int)(local_3b4 + local_300 + iVar8) % 3];

            *local_3d4 = *pfVar6;

            fVar20 = pfVar6[2];

            local_3d4[1] = pfVar6[1];

            local_3d4[2] = fVar20;

            local_328 = *pfVar6;

            local_324 = pfVar6[1];

            local_320 = pfVar6[2];

            local_31c = *pfVar9;

            local_318 = pfVar9[1];

            local_314 = pfVar9[2];

            local_3bc = (int *)FUN_004544c0();

            if (((local_3bc == local_3ac) || (local_328 < (float)local_3bc[3])) ||

               ((local_328 <= (float)local_3bc[3] &&

                ((local_324 < (float)local_3bc[4] ||

                 ((local_324 <= (float)local_3bc[4] &&

                  ((local_320 < (float)local_3bc[5] ||

                   ((local_320 <= (float)local_3bc[5] &&

                    ((local_31c < (float)local_3bc[6] ||

                     ((local_31c <= (float)local_3bc[6] &&

                      ((local_318 < (float)local_3bc[7] ||

                       ((local_318 <= (float)local_3bc[7] && (local_314 < (float)local_3bc[8])))))))

                     ))))))))))))) {

              local_2d0 = local_3ac;

              ppiVar4 = &local_2d0;

            }

            else {

              ppiVar4 = &local_3bc;

            }

            piVar17 = *ppiVar4;

            if (piVar17 == local_3ac) {

              local_3b8[iVar8] = '\0';

            }

            else {

              pfVar9 = (float *)(piVar17 + 9);

              pfVar6 = local_3c0 + -1;

              for (iVar10 = 0x17; iVar10 != 0; iVar10 = iVar10 + -1) {

                *pfVar6 = *pfVar9;

                pfVar9 = pfVar9 + 1;

                pfVar6 = pfVar6 + 1;

              }

              local_3b8[iVar8] = '\x01';

              FUN_00451830(local_3b0,&local_3d8,piVar17);

              local_3b4[iVar8] = '\0';

              pfVar9 = local_37c + 1;

              iVar10 = 7;

              pfVar6 = local_3c0;

              do {

                if (pfVar6[-1] * pfVar9[-1] + pfVar6[1] * pfVar9[1] + *pfVar9 * *pfVar6 < local_304)

                {

                  local_3b4[iVar8] = '\x01';

                }

                pfVar6 = pfVar6 + 3;

                pfVar9 = pfVar9 + 3;

                iVar10 = iVar10 + -1;

              } while (iVar10 != 0);

            }

            local_3d4 = local_3d4 + 6;

            local_3c0 = local_3c0 + 0x17;

            iVar8 = iVar8 + 1;

          } while (iVar8 < 3);

          local_3bc = (int *)0x0;

          local_3d4 = (float *)(aiStack_cc + 1);

          pvVar16 = local_3cc;

          do {

            piVar17 = local_3bc;

            iVar8 = (int)(local_3b8 + (int)local_3bc + local_2fc) % 3;

            if ((local_3b8[(int)local_3bc] == '\0') || (local_3b4[(int)local_3bc] != '\0')) {

              if ((local_3b8[iVar8] == '\0') || (local_3b4[iVar8] != '\0')) {

                if (local_394 == 0) {

                  iVar8 = 0;

                }

                else {

                  iVar8 = (local_390 - local_394) / 0xb0;

                }

                aiStack_310[(int)local_3bc] = iVar8;

                fStack_1bc = local_37c[0];

                fStack_1b8 = local_37c[1];

                fStack_1b4 = local_37c[2];

                if (0 < (int)param_3) {

                  pfVar6 = local_388[(int)local_3bc];

                  puVar5 = auStack_218;

                  iVar8 = (int)pfVar6 - (int)puVar5;

                  pfVar9 = pfVar6 + 0x16;

                  pcVar15 = acStack_1c4;

                  local_3d8 = -0x57 - (int)pfVar6;

                  local_3c0 = param_3;

                  do {

                    puVar18 = (uint32_t /* width from decompiler */ *)(iVar8 + (int)puVar5);

                    *puVar5 = *puVar18;

                    uVar7 = puVar18[2];

                    puVar5[1] = puVar18[1];

                    puVar5[2] = uVar7;

                    cVar2 = *(char *)pfVar9;

                    *pcVar15 = cVar2;

                    if ((int)((int)pfVar9 + (-0x57 - (int)pfVar6)) < (int)param_3) {

                      iVar10 = (int)cVar2;

                      puVar5[0x1a] = local_37c[iVar10 * 3];

                      fVar20 = local_37c[iVar10 * 3 + 2];

                      puVar5[0x1b] = local_37c[iVar10 * 3 + 1];

                      puVar5[0x1c] = fVar20;

                    }

                    pcVar15 = pcVar15 + 1;

                    pfVar9 = (float *)((int)pfVar9 + 1);

                    puVar5 = puVar5 + 3;

                    local_3c0 = (float *)((int)local_3c0 + -1);

                    puVar12 = local_3c8;

                  } while (local_3c0 != (float *)0x0);

                }

                FUN_00451b70();

                iVar8 = extraout_EDX;

                pvVar16 = local_3cc;

              }

              else {

                aiStack_310[(int)local_3bc] = aiStack_cc[iVar8 * 0x17];

              }

            }

            else {

              aiStack_310[(int)local_3bc] = (int)*local_3d4;

            }

            local_3d8 = CONCAT22((short)((uint)iVar8 >> 0x10),(short)aiStack_310[(int)piVar17]);

            if ((pvVar16 == (void *)0x0) ||

               ((uint)(local_3c4 - (int)pvVar16 >> 1) <= (uint)((int)puVar12 - (int)pvVar16 >> 1)))

            {

              FUN_00443b40(puVar12,1,&local_3d8);

              pvVar16 = local_3cc;

            }

            else {

              *puVar12 = (short)aiStack_310[(int)piVar17];

              local_3c8 = puVar12 + 1;

            }

            local_3d4 = local_3d4 + 0x17;

            local_3bc = (int *)((int)piVar17 + 1);

            puVar12 = local_3c8;

          } while ((int)local_3bc < 3);

          pfVar9 = (float *)0;

          do {

            local_3d4 = (float *)((int)pfVar9 + 1);

            afStack_280[0] = local_37c[0];

            afStack_280[1] = local_37c[1];

            afStack_280[2] = local_37c[2];

            afStack_280[3] = local_37c[3];

            uStack_270 = local_36c;

            uStack_26c = local_368;

            uStack_268 = uStack_364;

            uStack_264 = uStack_360;

            uStack_260 = uStack_35c;

            uStack_25c = uStack_358;

            uStack_258 = uStack_354;

            uStack_254 = uStack_350;

            iVar8 = aiStack_310[(int)pfVar9];

            iVar10 = aiStack_310[((int)pfVar9 + 1) % 3];

            uStack_250 = uStack_34c;

            uStack_24c = uStack_348;

            uStack_248 = uStack_344;

            uStack_244 = uStack_340;

            uStack_240 = uStack_33c;

            uStack_23c = uStack_338;

            uStack_238 = uStack_334;

            uStack_234 = uStack_330;

            iStack_22c = iVar8;

            iStack_228 = iVar10;

            uStack_230 = uStack_32c;

            if (local_3b8[(int)pfVar9] == '\0') {

              pfVar6 = (float *)FUN_00451710(local_3b0);

              pfVar9 = afStack_280;

              for (iVar8 = 0x17; pvVar16 = local_3cc, iVar8 != 0; iVar8 = iVar8 + -1) {

                *pfVar6 = *pfVar9;

                pfVar9 = pfVar9 + 1;

                pfVar6 = pfVar6 + 1;

              }

            }

            else {

              piVar17 = aiStack_cc + (int)pfVar9 * 0x17 + 1;

              local_3bc = piVar17;

              uVar13 = (uint16_t)iVar8;

              if (aiStack_cc[(int)pfVar9 * 0x17 + 1] == iVar8) {

LAB_00992ac1:

                piVar17 = aiStack_cc + (int)pfVar9 * 0x17;

                if (aiStack_cc[(int)pfVar9 * 0x17] != iVar10) {

LAB_00992ad5:

                  if ((pvVar16 == (void *)0x0) ||

                     ((uint)(local_3c4 - (int)pvVar16 >> 1) <=

                      (uint)((int)puVar12 - (int)pvVar16 >> 1))) {

                    local_3d8 = iVar10;

                    FUN_00443b40(puVar12,1,&local_3d8);

                    iVar10 = extraout_EDX_00;

                    pvVar16 = local_3cc;

                  }

                  else {

                    *puVar12 = (short)iVar10;

                    local_3c8 = puVar12 + 1;

                  }

                  uVar11 = (uint16_t)((uint)iVar10 >> 0x10);

                  local_3d8 = iVar8;

                  if ((pvVar16 == (void *)0x0) ||

                     ((uint)(local_3c4 - (int)pvVar16 >> 1) <=

                      (uint)((int)local_3c8 - (int)pvVar16 >> 1))) {

                    FUN_00443b40(local_3c8,1,&local_3d8);

                    pvVar16 = local_3cc;

                    uVar11 = extraout_var;

                  }

                  else {

                    *local_3c8 = uVar13;

                    local_3c8 = local_3c8 + 1;

                  }

                  local_3d8 = CONCAT22(uVar11,(short)*piVar17);

                  if ((pvVar16 == (void *)0x0) ||

                     ((uint)(local_3c4 - (int)pvVar16 >> 1) <=

                      (uint)((int)local_3c8 - (int)pvVar16 >> 1))) goto LAB_00992b7c;

                  *local_3c8 = (short)*piVar17;

                  local_3c8 = local_3c8 + 1;

                  puVar12 = local_3c8;

                }

              }

              else {

                if (aiStack_cc[(int)pfVar9 * 0x17] == iVar10) {

                  if (aiStack_cc[(int)pfVar9 * 0x17 + 1] == iVar8) goto LAB_00992ac1;

                  goto LAB_00992ad5;

                }

                if ((pvVar16 == (void *)0x0) ||

                   ((uint)(local_3c4 - (int)pvVar16 >> 1) <=

                    (uint)((int)puVar12 - (int)pvVar16 >> 1))) {

                  local_3d8 = iVar10;

                  FUN_00443b40(puVar12,1,&local_3d8);

                  pvVar16 = local_3cc;

                }

                else {

                  *puVar12 = (short)iVar10;

                  local_3c8 = puVar12 + 1;

                }

                local_3d8 = iVar8;

                if ((pvVar16 == (void *)0x0) ||

                   ((uint)(local_3c4 - (int)pvVar16 >> 1) <=

                    (uint)((int)local_3c8 - (int)pvVar16 >> 1))) {

                  FUN_00443b40(local_3c8,1,&local_3d8);

                  pvVar16 = local_3cc;

                }

                else {

                  *local_3c8 = uVar13;

                  local_3c8 = local_3c8 + 1;

                }

                uVar11 = (uint16_t)aiStack_cc[(int)pfVar9 * 0x17];

                iVar10 = CONCAT22((short)((uint)(aiStack_cc + (int)pfVar9 * 0x17) >> 0x10),uVar11);

                if ((pvVar16 == (void *)0x0) ||

                   ((uint)(local_3c4 - (int)pvVar16 >> 1) <=

                    (uint)((int)local_3c8 - (int)pvVar16 >> 1))) {

                  local_3d8 = iVar10;

                  FUN_00443b40(local_3c8,1,&local_3d8);

                  pvVar16 = local_3cc;

                }

                else {

                  *local_3c8 = uVar11;

                  local_3c8 = local_3c8 + 1;

                }

                local_3d8 = CONCAT22((short)((uint)local_3bc >> 0x10),(short)*local_3bc);

                if ((pvVar16 == (void *)0x0) ||

                   ((uint)(local_3c4 - (int)pvVar16 >> 1) <=

                    (uint)((int)local_3c8 - (int)pvVar16 >> 1))) {

                  FUN_00443b40(local_3c8,1,&local_3d8);

                  pvVar16 = local_3cc;

                }

                else {

                  *local_3c8 = (short)*local_3bc;

                  local_3c8 = local_3c8 + 1;

                }

                if ((pvVar16 == (void *)0x0) ||

                   ((uint)(local_3c4 - (int)pvVar16 >> 1) <=

                    (uint)((int)local_3c8 - (int)pvVar16 >> 1))) {

                  local_3d8 = iVar10;

                  FUN_00443b40(local_3c8,1,&local_3d8);

                  pvVar16 = local_3cc;

                }

                else {

                  *local_3c8 = uVar11;

                  local_3c8 = local_3c8 + 1;

                }

                local_3d8 = iVar8;

                if ((pvVar16 != (void *)0x0) &&

                   ((uint)((int)local_3c8 - (int)pvVar16 >> 1) <

                    (uint)(local_3c4 - (int)pvVar16 >> 1))) {

                  *local_3c8 = uVar13;

                  local_3c8 = local_3c8 + 1;

                  puVar12 = local_3c8;

                  goto LAB_00992b95;

                }

LAB_00992b7c:

                FUN_00443b40(local_3c8,1,&local_3d8);

                puVar12 = local_3c8;

                pvVar16 = local_3cc;

              }

            }

LAB_00992b95:

            pfVar9 = local_3d4;

          } while ((int)local_3d4 < 3);

          local_3a0 = local_3a0 + 3;

        } while (local_3a0 < local_39c);

      }

      local_2c4 = (uint32_t /* width from decompiler */ *)0x0;

      local_2c0 = 0;

      local_2bc = 0;

      local_2b8 = 0;

      local_2b4 = 0;

      local_4 = CONCAT31(local_4._1_3_,3);

      FUN_0044c3c0(0,0);

      puVar5 = &DAT_00a24248;

      puVar18 = local_2c4;

      for (iVar8 = 0x22; iVar8 != 0; iVar8 = iVar8 + -1) {

        *puVar18 = *puVar5;

        puVar5 = puVar5 + 1;

        puVar18 = puVar18 + 1;

      }

      FUN_00746d00();

      piVar17 = *(int **)(*(int *)(param_1 + 4) + 0x10);

      if ((piVar17 != (int *)0x0) && (piVar3 = (int *)*piVar17, piVar3 != (int *)0x0)) {

        piVar1 = piVar17 + 4;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                         "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

          piVar17[4] = 0;

        }

        else {

          (**(code **)(*piVar3 + 0x30))(piVar3);

        }

      }

      if (local_394 == 0) {

        iVar8 = 0;

      }

      else {

        iVar8 = (local_390 - local_394) / 0xb0;

      }

      FUN_00414c20(iVar8,local_2c8,8,0);

      FUN_00440110(local_394,0,0);

      piVar17 = *(int **)(*(int *)(param_2 + 4) + 0x10);

      if ((piVar17 != (int *)0x0) && (piVar3 = (int *)*piVar17, piVar3 != (int *)0x0)) {

        piVar1 = piVar17 + 3;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",0xca,1,

                         "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo...");

          piVar17[3] = 0;

        }

        else {

          (**(code **)(*piVar3 + 0x30))(piVar3);

        }

      }

      pvVar16 = local_3cc;

      if (local_3cc == (void *)0x0) {

        iVar8 = 0;

      }

      else {

        iVar8 = (int)puVar12 - (int)local_3cc >> 1;

      }

      FUN_0044b9c0(iVar8,8,0,0);

      FUN_0044bad0(pvVar16,0);

      if (*(int *)(param_2 + 4) == 0) {

        iVar8 = 0;

      }

      else {

        iVar8 = *(int *)(*(int *)(param_2 + 4) + 0x1c);

      }

      if (*(int *)((int)pvStack_c + 4) == 0) {

        uVar7 = 0;

      }

      else {

        uVar7 = *(uint32_t /* width from decompiler */ *)(*(int *)((int)pvStack_c + 4) + 0x18);

      }

      uVar7 = FUN_0076cec0(&stack0xfffffc18,

                           "After adding degenerate quads at sharp edges: %d verts, %d faces",uVar7,

                           iVar8 / 3);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxShadowVolume.cpp",0x5de,1,

                     uVar7);

      FUN_00414b60();

      if (pvVar16 == (void *)0x0) {

        if (local_3a4 == (void *)0x0) {

          uStack_14 = 0xffffffff;

          FUN_00454290(&stack0xfffffc18,*local_3bc,local_3bc);

                    /* WARNING: Subroutine does not return */

          operator_delete(local_3bc);

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(local_3a4);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar16);

    }

  }

  FUN_0044ba80();

  FUN_00414a50();

  local_4 = 0xffffffff;

  FUN_00454290(&local_3d8,*local_3ac,local_3ac);

                    /* WARNING: Subroutine does not return */

  operator_delete(local_3ac);

}
