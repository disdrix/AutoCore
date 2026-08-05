// =============================================================================
// FUN_0084e840
// -----------------------------------------------------------------------------
// Stable ID: aa_0084e840
// Address:   0x0084e840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084e840 @ 0x0084e840
// Stable ID: aa_0084e840
// Embedded strings (evidence for future rename):
//   - "i_w_a_2d_wnd_name.xml"
//   - "i_w_a_2d_wnd_description.xml"
//   - "i_w_a_2d_wnd_stats_full.xml"
//   - "Requirements Met: "
//   - "Requirements: "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~444 non-empty decompiler lines.
//  - Control keywords: if×25, while×11, do×10, return×6, for×5, goto×1.
//  - Notable callees: FUN_007a6de0×6, FUN_00411900×2, CNDHash_LookupByKey, FUN_00402c40, FUN_0051a0e0, FUN_007a69d0, FUN_0084e840, sprintf.
//  - Strings: "i_w_a_2d_wnd_name.xml"; "i_w_a_2d_wnd_description.xml"; "i_w_a_2d_wnd_stats_full.xml"; "Requirements Met: ".
//  - Return sites: 6.

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

void __fastcall FUN_0084e840(int *param_1)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  char *pcVar8;

  uint uVar9;

  char *pcVar10;

  char *pcVar11;

  char *pcVar12;

  uint16_t *puVar13;

  uint uVar14;

  float10 fVar15;

  uint8_t *puStack_3ac;

  uint32_t /* width from decompiler */ *puStack_3a8;

  uint32_t /* width from decompiler */ *puStack_3a4;

  uint32_t /* width from decompiler */ uStack_3a0;

  float fStack_39c;

  int **ppiStack_398;

  uint32_t /* width from decompiler */ uStack_394;

  char ***pppcStack_390;

  uint32_t /* width from decompiler */ uStack_38c;

  uint32_t /* width from decompiler */ uStack_388;

  uint8_t *puStack_384;

  uint32_t /* width from decompiler */ uStack_380;

  uint32_t /* width from decompiler */ uStack_370;

  char **ppcStack_36c;

  uint32_t /* width from decompiler */ uStack_368;

  uint uStack_364;

  int *piStack_360;

  void *pvStack_35c;

  uint32_t /* width from decompiler */ uStack_358;

  uint32_t /* width from decompiler */ **ppuStack_354;

  int iStack_350;

  char *pcStack_34c;

  char *pcStack_348;

  int aiStack_344 [2];

  uint32_t /* width from decompiler */ *puStack_33c;

  uint32_t /* width from decompiler */ *puStack_338;

  undefined *puStack_334;

  uint32_t /* width from decompiler */ uStack_320;

  int iStack_31c;

  uint8_t *puStack_318;

  int *piStack_314;

  uint32_t /* width from decompiler */ uStack_310;

  char *pcStack_30c;

  uint32_t /* width from decompiler */ uStack_308;

  uint32_t /* width from decompiler */ uStack_304;

  uint32_t /* width from decompiler */ uStack_300;

  int iStack_2fc;

  uint32_t /* width from decompiler */ uStack_2f8;

  uint8_t auStack_2f4 [4];

  char acStack_2f0 [4];

  char *pcStack_2ec;

  char *pcStack_2e8;

  char *pcStack_2e4;

  uint32_t /* width from decompiler */ uStack_2d0;

  char acStack_2cc [2];

  uint32_t /* width from decompiler */ auStack_2ca [3];

  int local_2bc;

  uint32_t /* width from decompiler */ local_2b8;

  uint32_t /* width from decompiler */ uStack_2b4;

  uint32_t /* width from decompiler */ uStack_2b0;

  uint32_t /* width from decompiler */ local_298;

  uint8_t auStack_120 [4];

  char acStack_11c [280];

  

  if (param_1[0x146] == 0) {

    return;

  }

  if (param_1[0x147] == 0) {

    return;

  }

  if (param_1[0x148] == 0) {

    return;

  }

  pcStack_2e4 = (char *)param_1[0x142];

  pcStack_2e8 = (char *)0x84e884;

  iVar4 = FUN_0051a0e0();

  if (iVar4 == 0) {

    return;

  }

  pcStack_2e4 = (char *)0x84e896;

  local_298 = FUN_007a69d0();

  local_2bc = 0;

  if (DAT_00d1b6d8 != 0) {

    piVar5 = *(int **)(DAT_00d1b6d8 + 0x574);

    piVar2 = *(int **)(DAT_00d1b6d8 + 0x578);

    if (piVar5 != piVar2) {

      do {

        if (*piVar5 == param_1[0x142]) break;

        piVar5 = piVar5 + 1;

      } while (piVar5 != piVar2);

      if (piVar5 != piVar2) goto LAB_0084e93e;

    }

    local_2b8 = 0;

    pcStack_2e4 = (char *)0x84e8e0;

    FUN_00402c40();

    pcStack_2e4 = (char *)&local_2b8;

    pcStack_2e8 = (char *)0x84e8f6;

    iVar6 = FUN_00411900();

    while ((iVar3 = local_2bc, iVar6 != 0 &&

           (iVar3 = iVar6, *(int *)(iVar6 + 0x100) != param_1[0x142]))) {

      pcStack_2e4 = (char *)&local_2b8;

      pcStack_2e8 = (char *)0x84e924;

      iVar6 = FUN_00411900();

    }

    local_2bc = iVar3;

    *(uint8_t *)(*(int *)(DAT_00d1b6d8 + 0x540) + 0x1d) = 0;

  }

LAB_0084e93e:

  *(bool *)(param_1 + 0x143) = local_2bc == 0;

  pcStack_2e4 = "i_w_a_2d_wnd_name.xml";

  pcStack_2e8 = (char *)0x84e95b;

  (**(code **)(*(int *)param_1[0x146] + 0x28))();

  pcStack_2e8 = "i_w_a_2d_wnd_description.xml";

  pcStack_2ec = (char *)0x84e96b;

  (**(code **)(*(int *)param_1[0x147] + 0x28))();

  pcStack_2ec = "i_w_a_2d_wnd_stats_full.xml";

  acStack_2f0[0] = '{';

  acStack_2f0[1] = -0x17;

  acStack_2f0[2] = -0x7c;

  acStack_2f0[3] = '\0';

  (**(code **)(*(int *)param_1[0x148] + 0x28))();

  acStack_2f0[0] = '\x01';

  acStack_2f0[1] = '\0';

  acStack_2f0[2] = '\0';

  acStack_2f0[3] = '\0';

  auStack_2f4 = (uint8_t  [4])&stack0xfffffd24;

  uStack_2f8 = 0x84e990;

  puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x146] + 0x140))();

  uStack_2b4 = *puVar7;

  uStack_2b0 = puVar7[1];

  *(uint32_t /* width from decompiler */ *)(param_1[0x146] + 0x214) = 1;

  uStack_300 = *(uint32_t /* width from decompiler */ *)(iVar4 + 4);

  uStack_2f8 = 1;

  iStack_2fc = 1;

  uStack_304 = 0x84e9c3;

  (**(code **)(*(int *)param_1[0x146] + 0x1d8))();

  uStack_304 = 0x84e9d1;

  (**(code **)(*(int *)param_1[0x146] + 0x13c))();

  uStack_304 = 0;

  uStack_308 = 1;

  pcStack_30c = acStack_2f0;

  uStack_310 = 0x84e9e7;

  iVar6 = (**(code **)(*(int *)param_1[0x146] + 0x120))();

  uStack_2d0 = *(uint32_t /* width from decompiler */ *)(iVar6 + 4);

  uStack_310 = 1;

  piStack_314 = &iStack_2fc;

  puStack_318 = (uint8_t *)0x84ea09;

  (**(code **)(*(int *)param_1[0x146] + 0x140))();

  puStack_318 = &stack0xfffffd24;

  iStack_31c = 0x84ea2b;

  (**(code **)(*(int *)param_1[0x147] + 0x118))();

  *(uint32_t /* width from decompiler */ *)(param_1[0x147] + 0x214) = 3;

  iStack_31c = 1;

  uStack_320 = 0x84ea4b;

  (**(code **)(*(int *)param_1[0x147] + 0x1c4))();

  acStack_2cc[0] = '\0';

  acStack_2cc[1] = '\0';

  puVar7 = auStack_2ca;

  for (iVar6 = 0x7f; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  *(uint16_t *)puVar7 = 0;

  pcVar10 = *(char **)(iVar4 + 8);

  pcVar8 = pcVar10;

  do {

    cVar1 = *pcVar8;

    pcVar8 = pcVar8 + 1;

  } while (cVar1 != '\0');

  pcVar12 = (char *)((int)&uStack_2d0 + 3);

  do {

    pcVar11 = pcVar12 + 1;

    pcVar12 = pcVar12 + 1;

  } while (*pcVar11 != '\0');

  pcVar11 = pcVar10;

  for (uVar9 = (uint)((int)pcVar8 - (int)pcVar10) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar12 = *(uint32_t /* width from decompiler */ *)pcVar11;

    pcVar11 = pcVar11 + 4;

    pcVar12 = pcVar12 + 4;

  }

  for (uVar9 = (int)pcVar8 - (int)pcVar10 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

    *pcVar12 = *pcVar11;

    pcVar11 = pcVar11 + 1;

    pcVar12 = pcVar12 + 1;

  }

  if (*(int *)(iVar4 + 0x14) == -1) {

    uStack_320 = 1;

    (**(code **)(*(int *)param_1[0x147] + 0x1d8))();

  }

  else {

    uStack_320 = 0x84eaa8;

    (**(code **)(*(int *)param_1[0x147] + 0x268))();

    iVar6 = *(int *)param_1[0x147];

    uStack_320 = 0xffffffff;

    uStack_320 = FUN_007a6de0();

    (**(code **)(iVar6 + 0x250))();

    (**(code **)(*(int *)param_1[0x147] + 0x250))();

    puVar7 = CVOGReaction_ResolveSkillTargets

                       (*(void **)(iVar4 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x18));

    if (puVar7 != (uint32_t /* width from decompiler */ *)0x0) {

      auStack_2f4 = *(uint8_t (*) [4])param_1[0x147];

      puStack_334 = (undefined *)0x84eb19;

      FUN_007a6de0();

      (**(code **)((int)auStack_2f4 + 0x224))();

                    /* WARNING: Subroutine does not return */

      puStack_334 = &UNK_0084eb30;

      operator_delete(puVar7);

    }

  }

  (**(code **)(*(int *)param_1[0x147] + 0x13c))();

  puStack_334 = (undefined *)0x84eb6d;

  puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x147] + 0x120))();

  uStack_2f8 = *puVar7;

  auStack_2f4 = (uint8_t  [4])puVar7[1];

  puStack_334 = (undefined *)0x1;

  puStack_338 = &uStack_320;

  puStack_33c = (uint32_t /* width from decompiler */ *)0x84eb8f;

  iVar6 = (**(code **)(*(int *)param_1[0x147] + 0x140))();

  iStack_2fc = iStack_2fc + 1 + *(int *)(iVar6 + 4);

  *(uint32_t /* width from decompiler */ *)(param_1[0x148] + 0x214) = 3;

  puStack_33c = &uStack_300;

  aiStack_344[1] = 0x84ebc1;

  (**(code **)(*(int *)param_1[0x148] + 0x118))();

  aiStack_344[1] = 1;

  aiStack_344[0] = 0x84ebd1;

  (**(code **)(*(int *)param_1[0x148] + 0x1c4))();

  aiStack_344[0] = -1;

  if (iStack_31c == 0) {

    pcStack_348 = "Requirements Met: ";

    pcStack_34c = (char *)0x84ec0a;

    pcVar8 = (char *)FUN_007a6de0();

    pcVar10 = acStack_2f0;

    do {

      cVar1 = *pcVar8;

      *pcVar10 = cVar1;

      pcVar8 = pcVar8 + 1;

      pcVar10 = pcVar10 + 1;

    } while (cVar1 != '\0');

  }

  else {

    pcStack_348 = "Requirements: ";

    pcStack_34c = (char *)0x84ebe6;

    pcVar8 = (char *)FUN_007a6de0();

    pcVar10 = acStack_2f0;

    do {

      cVar1 = *pcVar8;

      *pcVar10 = cVar1;

      pcVar8 = pcVar8 + 1;

      pcVar10 = pcVar10 + 1;

    } while (cVar1 != '\0');

  }

  pcStack_348 = *(char **)(iVar4 + 0xc);

  aiStack_344[0] = -1;

  pcStack_34c = (char *)0x84ec2b;

  pcVar8 = (char *)FUN_007a6de0();

  pcVar10 = pcVar8;

  do {

    cVar1 = *pcVar10;

    pcVar10 = pcVar10 + 1;

  } while (cVar1 != '\0');

  pcVar12 = auStack_2f4 + 3;

  do {

    pcVar11 = pcVar12 + 1;

    pcVar12 = pcVar12 + 1;

  } while (*pcVar11 != '\0');

  pcVar11 = pcVar8;

  for (uVar9 = (uint)((int)pcVar10 - (int)pcVar8) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar12 = *(uint32_t /* width from decompiler */ *)pcVar11;

    pcVar11 = pcVar11 + 4;

    pcVar12 = pcVar12 + 4;

  }

  for (uVar9 = (int)pcVar10 - (int)pcVar8 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

    *pcVar12 = *pcVar11;

    pcVar11 = pcVar11 + 1;

    pcVar12 = pcVar12 + 1;

  }

  puVar13 = (uint16_t *)(auStack_2f4 + 3);

  do {

    pcVar10 = (char *)((int)puVar13 + 1);

    puVar13 = (uint16_t *)((int)puVar13 + 1);

  } while (*pcVar10 != '\0');

  piVar5 = (int *)param_1[0x148];

  aiStack_344[0] = 1;

  *puVar13 = DAT_00a15104;

  pcStack_348 = (char *)0x1;

  pcStack_34c = acStack_2f0;

  iStack_350 = 0x84ec8d;

  (**(code **)(*piVar5 + 0x1d8))();

  iStack_350 = 0x84ec9b;

  (**(code **)(*(int *)param_1[0x148] + 0x13c))();

  iStack_350 = 1;

  ppuStack_354 = &puStack_33c;

  uStack_358 = 0x84ecb0;

  puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x145] + 0x140))();

  piStack_314 = (int *)*puVar7;

  uStack_310 = puVar7[1];

  piVar5 = (int *)param_1[0x148];

  uStack_358 = 0;

  pvStack_35c = (void *)0x1;

  piStack_360 = aiStack_344;

  uStack_364 = 0x84ecda;

  (**(code **)(*(int *)param_1[0x146] + 0x120))();

  uStack_364 = 0;

  uStack_368 = 1;

  ppcStack_36c = &pcStack_348;

  uStack_370 = 0x84ecef;

  (**(code **)(*piVar5 + 0x120))();

  uStack_370 = 1;

  (**(code **)(*piVar5 + 0x140))();

  if ((int *)param_1[0x149] != (int *)0x0) {

    if ((iStack_350 == 0) || (DAT_00d1b6d8 == 0)) {

      (**(code **)(*(int *)param_1[0x149] + 4))();

      if ((int *)param_1[0x14a] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x14a] + 4))();

      }

      if ((int *)param_1[0x14b] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x14b] + 4))();

      }

      if ((int *)param_1[0x14c] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x14c] + 4))();

      }

    }

    else {

      uStack_364 = (uint)*(byte *)(iStack_350 + 0x130);

      pcStack_34c = (char *)0x0;

      ppuStack_354 = (uint32_t /* width from decompiler */ **)0x0;

      aiStack_344[0] = 0;

      if (uStack_364 != 0) {

        do {

          iVar4 = *(int *)(*(int *)(iStack_350 + 0x13c) + aiStack_344[0] * 4);

          if (iVar4 != 0) {

            if (*(int *)(iVar4 + 0x158) == 0) {

              uVar9 = 0;

            }

            else {

              uVar9 = *(int *)(iVar4 + 0x15c) - *(int *)(iVar4 + 0x158) >> 2;

            }

            pcStack_34c = pcStack_34c + uVar9;

            pvStack_35c = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x55c),

                                              *(uint *)(iVar4 + 0x10));

            if ((pvStack_35c != (void *)0x0) && (uVar14 = 0, uVar9 != 0)) {

              do {

                piVar5 = *(int **)(*(int *)(iVar4 + 0x158) + uVar14 * 4);

                if (piVar5 != (int *)0x0) {

                  uStack_380 = 0x84edce;

                  fVar15 = (float10)(**(code **)(*piVar5 + 0x10))();

                  ppuStack_354 = (uint32_t /* width from decompiler */ **)(float)(fVar15 + (float10)(float)ppuStack_354);

                }

                uVar14 = uVar14 + 1;

              } while (uVar14 < uVar9);

            }

          }

          aiStack_344[0] = aiStack_344[0] + 1;

        } while (aiStack_344[0] < (int)uStack_364);

        if (pcStack_34c != (char *)0x0) {

          ppuStack_354 = (uint32_t /* width from decompiler */ **)((float)ppuStack_354 / (float)(int)pcStack_34c);

        }

      }

      uStack_380 = 0x84ee22;

      pcVar10 = (char *)FUN_007a6de0();

      uStack_380 = 0x84ee31;

      sprintf(acStack_11c,pcVar10);

      (**(code **)(*(int *)param_1[0x149] + 0xcc))();

      uStack_380 = 1;

      puStack_384 = auStack_120;

      uStack_388 = 0x84ee5e;

      (**(code **)(*(int *)param_1[0x149] + 0x1d8))();

      piVar5 = (int *)param_1[0x148];

      uStack_388 = 0;

      uStack_38c = 1;

      pppcStack_390 = &ppcStack_36c;

      uStack_394 = 0x84ee7d;

      iVar4 = (**(code **)(*piVar5 + 0x120))();

      uStack_394 = 1;

      ppiStack_398 = &piStack_360;

      fStack_39c = 1.2207866e-38;

      iVar6 = (**(code **)(*piVar5 + 0x140))();

      iVar4 = *(int *)(iVar4 + 4);

      iVar6 = *(int *)(iVar6 + 4);

      fStack_39c = 0.0;

      uStack_3a0 = 1;

      puStack_3a4 = &uStack_370;

      puStack_3a8 = (uint32_t /* width from decompiler */ *)0x84eead;

      puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x149] + 0x120))();

      uStack_394 = *puVar7;

      puStack_3a8 = &uStack_394;

      puStack_3ac = (uint8_t *)0x84eeca;

      pppcStack_390 = (char ***)(iVar4 + iVar6);

      (**(code **)(*(int *)param_1[0x149] + 0x110))();

      if ((int *)param_1[0x14b] != (int *)0x0) {

        puStack_3ac = &stack0xfffffc88;

        iVar4 = (**(code **)(*(int *)param_1[0x14b] + 0x124))();

        fStack_39c = (float)DAT_00d1e81c * *(float *)(iVar4 + 4) * DAT_00aaa678;

        iVar4 = (**(code **)(*(int *)param_1[0x149] + 0x120))(&puStack_384,1,0);

        iVar6 = (int)(float)puStack_3a8;

        iVar4 = *(int *)(iVar4 + 4);

        puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x14b] + 0x120))(&uStack_370,1,0);

        puStack_3ac = (uint8_t *)*puVar7;

        puStack_3a8 = (uint32_t /* width from decompiler */ *)(iVar6 + iVar4);

        (**(code **)(*(int *)param_1[0x14b] + 0x110))(&puStack_3ac);

        (**(code **)(*(int *)param_1[0x14b] + 0x3b0))(puStack_3a8);

        (**(code **)(*(int *)param_1[0x14b] + 4))(1);

      }

      if ((int *)param_1[0x14a] != (int *)0x0) {

        puStack_3ac = &stack0xfffffc88;

        iVar4 = (**(code **)(*(int *)param_1[0x14a] + 0x124))();

        fStack_39c = (float)DAT_00d1e81c * *(float *)(iVar4 + 4) * DAT_00aaa678;

        iVar4 = (**(code **)(*(int *)param_1[0x149] + 0x120))(&puStack_384,1,0);

        iVar6 = (int)(float)puStack_3a8;

        iVar4 = *(int *)(iVar4 + 4);

        puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x14a] + 0x120))(&uStack_370,1,0);

        puStack_3ac = (uint8_t *)*puVar7;

        puStack_3a8 = (uint32_t /* width from decompiler */ *)(iVar6 + iVar4);

        (**(code **)(*(int *)param_1[0x14a] + 0x110))(&puStack_3ac);

        (**(code **)(*(int *)param_1[0x14a] + 4))(1);

      }

      if ((int *)param_1[0x14c] != (int *)0x0) {

        puStack_3ac = &stack0xfffffc88;

        iVar4 = (**(code **)(*(int *)param_1[0x14c] + 0x124))();

        fStack_39c = (float)DAT_00d1e81c * *(float *)(iVar4 + 4) * DAT_00aaa678;

        iVar4 = (**(code **)(*(int *)param_1[0x149] + 0x120))(&puStack_384,1,0);

        iVar6 = (int)(float)puStack_3a8;

        iVar4 = *(int *)(iVar4 + 4);

        puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x14c] + 0x120))(&uStack_370,1,0);

        puStack_3ac = (uint8_t *)*puVar7;

        puStack_3a8 = (uint32_t /* width from decompiler */ *)(iVar6 + iVar4);

        (**(code **)(*(int *)param_1[0x14c] + 0x110))(&puStack_3ac);

        (**(code **)(*(int *)param_1[0x14c] + 4))(1);

      }

      puStack_3ac = (uint8_t *)0x1;

      (**(code **)(*(int *)param_1[0x149] + 0x140))(&ppiStack_398);

    }

  }

  (**(code **)(*(int *)param_1[0x145] + 8))();

  uStack_380 = 0x84f123;

  (**(code **)(*param_1 + 8))();

  return;

}
