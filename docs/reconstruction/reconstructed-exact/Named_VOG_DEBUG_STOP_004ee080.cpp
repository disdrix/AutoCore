// READABILITY (auto CF):
//  - Body size: ~1963 non-empty decompiler lines.
//  - Control keywords: if×114, do×16, while×16, for×16, goto×11, return×4.
//  - Notable callees: CONCAT31×14, FUN_004f2d70×8, FUN_005d4240×8, FUN_005e1c80×8, _stricmp×7, FUN_004aed30×6, free×6, malloc×6.
//  - Strings: "sphere"; "humanoid"; "creature"; "capsule".
//  - Return sites: 4.

// =============================================================================
// Named_VOG_DEBUG_STOP_004ee080
// -----------------------------------------------------------------------------
// Stable ID: aa_004ee080
// Address:   0x004ee080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



int Named_VOG_DEBUG_STOP_004ee080(char *param_1,float param_2,float param_3,int *param_4,char param_5,char param_6,

                uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,float param_9,uint32_t /* width from decompiler */ param_10,

                char param_11,uint32_t /* width from decompiler */ *param_12)



{

  float *pfVar1;

  int iVar2;

  bool bVar3;

  uint32_t /* width from decompiler */ uVar4;

  char cVar5;

  short sVar6;

  char *pcVar7;

  uint uVar8;

  int iVar9;

  int iVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ *puVar12;

  float *pfVar13;

  float *pfVar14;

  void *pvVar15;

  uint uVar16;

  uint32_t /* width from decompiler */ *puVar17;

  float fVar18;

  int iVar19;

  float unaff_ESI;

  char *pcVar20;

  int *piVar21;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint32_t /* width from decompiler */ *puVar22;

  uint32_t /* width from decompiler */ *puVar23;

  float fVar24;

  size_t sVar25;

  float local_2654;

  float local_2650;

  uint32_t /* width from decompiler */ *local_264c;

  uint32_t /* width from decompiler */ *local_2648;

  uint32_t /* width from decompiler */ uStack_2644;

  float *local_2640;

  int local_263c;

  uint32_t /* width from decompiler */ local_2638;

  float fStack_2634;

  uint32_t /* width from decompiler */ local_2630;

  float local_262c;

  uint32_t /* width from decompiler */ local_2628;

  float local_2624;

  float local_2620;

  uint32_t /* width from decompiler */ local_261c;

  float local_2618;

  uint32_t /* width from decompiler */ local_2614;

  uint32_t /* width from decompiler */ local_2610;

  uint32_t /* width from decompiler */ local_260c;

  uint32_t /* width from decompiler */ local_2608;

  float local_2604;

  uint uStack_25f8;

  uint uStack_25f4;

  float fStack_25f0;

  float fStack_25ec;

  uint32_t /* width from decompiler */ uStack_25e8;

  uint32_t /* width from decompiler */ uStack_25e4;

  uint32_t /* width from decompiler */ uStack_25e0;

  uint32_t /* width from decompiler */ uStack_25dc;

  uint32_t /* width from decompiler */ uStack_25d8;

  uint32_t /* width from decompiler */ uStack_25d4;

  uint32_t /* width from decompiler */ uStack_25d0;

  uint32_t /* width from decompiler */ uStack_25cc;

  uint32_t /* width from decompiler */ uStack_25c8;

  uint32_t /* width from decompiler */ uStack_25c4;

  uint32_t /* width from decompiler */ uStack_25c0;

  uint32_t /* width from decompiler */ uStack_25bc;

  uint32_t /* width from decompiler */ uStack_25b8;

  float fStack_25b4;

  float local_25b0;

  int iStack_25ac;

  uint uStack_25a8;

  uint uStack_25a4;

  float fStack_25a0;

  float fStack_259c;

  uint32_t /* width from decompiler */ uStack_2598;

  uint32_t /* width from decompiler */ uStack_2594;

  uint32_t /* width from decompiler */ uStack_2590;

  uint32_t /* width from decompiler */ uStack_258c;

  uint32_t /* width from decompiler */ uStack_2588;

  uint32_t /* width from decompiler */ uStack_2584;

  uint32_t /* width from decompiler */ uStack_2580;

  uint32_t /* width from decompiler */ uStack_257c;

  uint32_t /* width from decompiler */ uStack_2578;

  uint32_t /* width from decompiler */ uStack_2574;

  uint32_t /* width from decompiler */ uStack_2570;

  uint32_t /* width from decompiler */ uStack_256c;

  int iStack_2568;

  uint32_t /* width from decompiler */ uStack_2564;

  char local_2560 [4];

  int local_255c;

  char local_2558 [4];

  char local_2554 [4];

  char local_2550 [2];

  char local_254e;

  uint32_t /* width from decompiler */ uStack_2548;

  uint32_t /* width from decompiler */ uStack_2544;

  uint32_t /* width from decompiler */ local_2540;

  uint32_t /* width from decompiler */ local_253c;

  uint32_t /* width from decompiler */ local_2538;

  uint32_t /* width from decompiler */ local_2534;

  uint uStack_24d8;

  uint uStack_24d4;

  float fStack_24d0;

  float fStack_24cc;

  float fStack_24c8;

  uint32_t /* width from decompiler */ uStack_24c4;

  uint32_t /* width from decompiler */ uStack_24c0;

  uint32_t /* width from decompiler */ local_24bc;

  uint32_t /* width from decompiler */ local_24b8;

  uint8_t uStack_24b4;

  uint8_t auStack_2458 [4];

  float fStack_2454;

  uint8_t local_2450 [4];

  float local_244c;

  uint uStack_2448;

  uint uStack_2444;

  float local_2440;

  float local_243c;

  float local_2438;

  float local_2434;

  float local_2430 [8];

  uint8_t auStack_2410 [16];

  int local_2400;

  uint32_t /* width from decompiler */ *puStack_23fc;

  uint32_t /* width from decompiler */ uStack_23e0;

  uint32_t /* width from decompiler */ uStack_23dc;

  uint32_t /* width from decompiler */ uStack_23d8;

  uint32_t /* width from decompiler */ uStack_23d4;

  uint32_t /* width from decompiler */ uStack_23d0;

  uint32_t /* width from decompiler */ uStack_23cc;

  uint32_t /* width from decompiler */ uStack_23c8;

  float fStack_23c4;

  float fStack_2370;

  float fStack_236c;

  float fStack_2368;

  float fStack_2364;

  float fStack_2360;

  uint32_t /* width from decompiler */ uStack_235c;

  uint32_t /* width from decompiler */ uStack_2358;

  uint32_t /* width from decompiler */ uStack_2354;

  uint8_t uStack_234c;

  uint8_t uStack_2339;

  uint32_t /* width from decompiler */ local_2338 [65];

  uint8_t uStack_2231;

  uint32_t /* width from decompiler */ local_2230;

  uint8_t local_222a [257];

  char cStack_2129;

  char local_2128 [6];

  char local_2122 [258];

  float local_2020 [2042];

  void *pvStack_38;

  void *pvStack_2c;

  uint32_t /* width from decompiler */ uStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a2aaa;

  pvStack_1c = ExceptionList;

  uStack_24 = 0x4ee0a6;

  pcVar7 = param_1;

  do {

    cVar5 = *pcVar7;

    pcVar7[(int)local_2338 - (int)param_1] = cVar5;

    pcVar7 = pcVar7 + 1;

  } while (cVar5 != '\0');

  puVar22 = (uint32_t /* width from decompiler */ *)&uStack_2339;

  do {

    pcVar7 = (char *)((int)puVar22 + 1);

    puVar22 = (uint32_t /* width from decompiler */ *)((int)puVar22 + 1);

  } while (*pcVar7 != '\0');

  *puVar22 = DAT_009cb318;

  pcVar7 = param_1;

  do {

    cVar5 = *pcVar7;

    pcVar7[(int)(local_2128 + -(int)param_1)] = cVar5;

    pcVar7 = pcVar7 + 1;

  } while (cVar5 != '\0');

  pcVar7 = &cStack_2129;

  do {

    pcVar20 = pcVar7;

    pcVar7 = pcVar20 + 1;

  } while (pcVar20[1] != '\0');

  *(uint32_t /* width from decompiler */ *)(pcVar20 + 1) = s__cache_009ccf18._0_4_;

  *(uint16_t *)(pcVar20 + 5) = s__cache_009ccf18._4_2_;

  pcVar20[7] = s__cache_009ccf18[6];

  pcVar7 = param_1;

  do {

    cVar5 = *pcVar7;

    pcVar7[(int)&local_2230 - (int)param_1] = cVar5;

    pcVar7 = pcVar7 + 1;

  } while (cVar5 != '\0');

  puVar22 = (uint32_t /* width from decompiler */ *)&uStack_2231;

  do {

    puVar23 = puVar22;

    puVar22 = (uint32_t /* width from decompiler */ *)((int)puVar23 + 1);

  } while (*(char *)((int)puVar23 + 1) != '\0');

  *(uint32_t /* width from decompiler */ *)((int)puVar23 + 1) = DAT_009cccf0;

  *(uint16_t *)((int)puVar23 + 5) = DAT_009cccf4;

  *(uint8_t *)((int)puVar23 + 7) = DAT_009cccf6;

  local_2558 = (char  [4])s____physics__00a9600c._8_4_;

  local_255c = s____physics__00a9600c._4_4_;

  local_2560 = (char  [4])s____physics__00a9600c._0_4_;

  pcVar7 = (char *)local_2338;

  do {

    cVar5 = *pcVar7;

    pcVar7 = pcVar7 + 1;

  } while (cVar5 != '\0');

  uVar8 = (int)pcVar7 - (int)local_2338;

  pcVar7 = (char *)((int)&uStack_2564 + 3);

  do {

    pcVar20 = pcVar7 + 1;

    pcVar7 = pcVar7 + 1;

  } while (*pcVar20 != '\0');

  pcVar20 = (char *)local_2338;

  for (uVar16 = uVar8 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar20;

    pcVar20 = pcVar20 + 4;

    pcVar7 = pcVar7 + 4;

  }

  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

    *pcVar7 = *pcVar20;

    pcVar20 = pcVar20 + 1;

    pcVar7 = pcVar7 + 1;

  }

  local_2558 = (char  [4])s____physics_planes__00a95ff8._8_4_;

  local_2560 = (char  [4])s____physics_planes__00a95ff8._0_4_;

  local_255c = s____physics_planes__00a95ff8._4_4_;

  local_254e = s____physics_planes__00a95ff8[0x12];

  local_2554 = (char  [4])s____physics_planes__00a95ff8._12_4_;

  local_2550 = (char  [2])s____physics_planes__00a95ff8._16_2_;

  pcVar7 = local_2128;

  do {

    cVar5 = *pcVar7;

    pcVar7 = pcVar7 + 1;

  } while (cVar5 != '\0');

  uVar8 = (int)pcVar7 - (int)local_2128;

  pcVar7 = (char *)((int)&uStack_2564 + 3);

  do {

    pcVar20 = pcVar7 + 1;

    pcVar7 = pcVar7 + 1;

  } while (*pcVar20 != '\0');

  pcVar20 = local_2128;

  for (uVar16 = uVar8 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar20;

    pcVar20 = pcVar20 + 4;

    pcVar7 = pcVar7 + 4;

  }

  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

    *pcVar7 = *pcVar20;

    pcVar20 = pcVar20 + 1;

    pcVar7 = pcVar7 + 1;

  }

  local_2560 = (char  [4])s____physics_physx__00a96084._0_4_;

  local_255c = s____physics_physx__00a96084._4_4_;

  local_2558 = (char  [4])s____physics_physx__00a96084._8_4_;

  local_2554 = (char  [4])s____physics_physx__00a96084._12_4_;

  local_2550 = (char  [2])s____physics_physx__00a96084._16_2_;

  pcVar7 = (char *)&local_2230;

  do {

    cVar5 = *pcVar7;

    pcVar7 = pcVar7 + 1;

  } while (cVar5 != '\0');

  uVar8 = (int)pcVar7 - (int)&local_2230;

  pcVar7 = (char *)((int)&uStack_2564 + 3);

  do {

    pcVar20 = pcVar7 + 1;

    pcVar7 = pcVar7 + 1;

  } while (*pcVar20 != '\0');

  pcVar20 = (char *)&local_2230;

  for (uVar16 = uVar8 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar20;

    pcVar20 = pcVar20 + 4;

    pcVar7 = pcVar7 + 4;

  }

  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

    *pcVar7 = *pcVar20;

    pcVar20 = pcVar20 + 1;

    pcVar7 = pcVar7 + 1;

  }

  ExceptionList = &pvStack_1c;

  iVar9 = _stricmp("sphere",param_1);

  if (iVar9 == 0) {

    iVar9 = 0x10;

    iVar10 = (**(code **)(*DAT_00b05060 + 0x10))(0x10,0x22);

    *(uint16_t *)(iVar10 + 4) = 0x10;

    pvStack_1c = (void *)0x0;

    puVar22 = (uint32_t /* width from decompiler */ *)FUN_006c7fa0(param_3);

    pvStack_1c = (void *)0xffffffff;

    FUN_005e1c80();

    uStack_24c4 = DAT_00a0f70c;

    pvStack_1c = (void *)0x1;

    uStack_2548 = 0;

    uStack_2544 = 0;

    local_2540 = 0;

    local_253c = 0;

    uStack_24c0 = 0;

    uStack_24b4 = 2;

    if (param_2 <= 0.0) {

      uStack_24b4 = 7;

    }

    fStack_24c8 = param_2;

    iStack_2568 = ((char)param_7 != '\0') + 3;

    uStack_2564 = puVar22;

    if (0.0 < param_2) {

      uStack_25b8 = 0;

      fStack_25b4 = 0.0;

      fStack_259c = 0.0;

      fStack_25a0 = 0.0;

      uStack_25a4 = 0;

      uStack_25a8 = 0;

      uStack_258c = 0;

      uStack_2590 = 0;

      uStack_2594 = 0;

      uStack_2598 = 0;

      uStack_257c = 0;

      uStack_2580 = 0;

      uStack_2584 = 0;

      uStack_2588 = 0;

      uStack_256c = 0;

      uStack_2570 = 0;

      uStack_2574 = 0;

      uStack_2578 = 0;

      FUN_005ee680(param_3,param_2,&uStack_25b8);

      FUN_004f2d70(&uStack_2598);

      uStack_24d8 = uStack_25a8;

      uStack_24d4 = uStack_25a4;

      fStack_24d0 = fStack_25a0;

      fStack_24cc = fStack_259c;

      fStack_24c8 = fStack_25b4;

    }

    iVar10 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

    *(uint16_t *)(iVar10 + 4) = 0xa0;

    uStack_24._0_1_ = 2;

    iVar10 = FUN_005d4240(&uStack_2570);

    *(short *)((int)puVar22 + 6) = *(short *)((int)puVar22 + 6) + -1;

    uStack_24 = CONCAT31(uStack_24._1_3_,1);

    if (*(short *)((int)puVar22 + 6) == 0) {

      (**(code **)*puVar22)(1);

    }

    if ((param_4 == (int *)0x0) || (*param_4 == 0)) goto LAB_004ee8ac;

    puVar22 = operator_new(0x6c);

    fVar24 = g_flOne;

    if (puVar22 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar22 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar22[1] = 1;

      puVar22[0xd] = 0;

      puVar22[0xc] = 0;

      puVar22[0xb] = 0;

      puVar22[2] = fVar24;

      puVar22[3] = 0;

      puVar22[4] = 0;

      puVar22[5] = 0;

      puVar22[6] = fVar24;

      puVar22[7] = 0;

      puVar22[8] = 0;

      puVar22[9] = 0;

      puVar22[10] = fVar24;

      puVar22[2] = fVar24;

      puVar22[3] = 0;

      puVar22[4] = 0;

      puVar22[5] = 0;

      puVar22[6] = fVar24;

      puVar22[7] = 0;

      puVar22[8] = 0;

      puVar22[9] = 0;

      puVar22[10] = fVar24;

      fVar18 = DAT_00aaa668;

      puVar22[0xd] = 0;

      puVar22[0xc] = 0;

      puVar22[0xb] = 0;

      *puVar22 = &PTR_FUN_009c7bb4;

      puVar22[2] = fVar24;

      puVar22[3] = 0;

      puVar22[4] = 0;

      puVar22[5] = 0;

      puVar22[6] = fVar24;

      puVar22[7] = 0;

      puVar22[8] = 0;

      puVar22[9] = 0;

      puVar22[10] = fVar24;

      puVar22[0xd] = 0;

      puVar22[0xc] = 0;

      puVar22[0xb] = 0;

      puVar22[0xe] = 8;

      *(uint16_t *)(puVar22 + 0xf) = 0;

      *(uint16_t *)((int)puVar22 + 0x3e) = 0;

      puVar22[0x10] = 0;

      puVar22[0x13] = fVar18;

      puVar22[0x11] = fVar24;

      puVar22[0x12] = fVar18;

      puVar22[0x14] = 0;

      puVar22[0x15] = 0;

      puVar22[0x16] = 0;

      puVar22[0x17] = 0;

      puVar22[0x18] = 0;

      puVar22[0x19] = 0;

      puVar22[0x1a] = fVar24;

    }

    puVar22[0x1a] = param_3;

    puVar22[0xb] = 0;

    puVar22[0xc] = 0;

    puVar22[0xd] = 0;

    if ((char)param_7 == '\0') {

      sVar6 = ((char)param_8 != '\0') + 1;

    }

    else {

      sVar6 = 4;

    }

    *(short *)(puVar22 + 0xf) = sVar6;

    if (sVar6 == 2) {

      *(byte *)((int)puVar22 + 0x39) = *(byte *)((int)puVar22 + 0x39) | 0x40;

    }

    iVar19 = *param_4;

    piVar21 = (int *)(iVar19 + 0x50);

    if (*(uint *)(iVar19 + 0x58) <= *(uint *)(iVar19 + 0x54)) {

      iVar2 = *piVar21;

      uVar8 = ((int)(*(uint *)(iVar19 + 0x54) - iVar2) >> 2) * 2 + 2;

      if (iVar2 == 0) {

        uVar16 = 0;

      }

      else {

        uVar16 = (int)(*(uint *)(iVar19 + 0x58) - iVar2) >> 2;

      }

      if (uVar16 < uVar8) {

        puVar11 = malloc(uVar8 * 4);

        puVar23 = *(uint32_t /* width from decompiler */ **)(iVar19 + 0x54);

        puVar17 = puVar11;

        for (puVar12 = (uint32_t /* width from decompiler */ *)*piVar21; puVar12 != puVar23; puVar12 = puVar12 + 1) {

          *puVar17 = *puVar12;

          puVar17 = puVar17 + 1;

        }

        if ((void *)*piVar21 != (void *)0x0) {

          free((void *)*piVar21);

        }

        iVar2 = *piVar21;

        *(uint32_t /* width from decompiler */ **)(iVar19 + 0x58) = puVar11 + uVar8;

        *piVar21 = (int)puVar11;

        *(uint32_t /* width from decompiler */ **)(iVar19 + 0x54) = puVar11 + (*(int *)(iVar19 + 0x54) - iVar2 >> 2);

      }

    }

    **(uint32_t /* width from decompiler */ **)(iVar19 + 0x54) = puVar22;

    *(int *)(iVar19 + 0x54) = *(int *)(iVar19 + 0x54) + 4;

    pfVar13 = operator_new(0x84);

    fVar24 = g_flOne;

    if (pfVar13 == (float *)0x0) {

      pfVar13 = (float *)0x0;

    }

    else {

      pfVar13[0xb] = 0.0;

      pfVar13[10] = 0.0;

      pfVar13[9] = 0.0;

      fVar18 = DAT_009c7b84;

      *pfVar13 = fVar24;

      pfVar13[1] = 0.0;

      pfVar13[2] = 0.0;

      pfVar13[3] = 0.0;

      pfVar13[4] = fVar24;

      pfVar13[5] = 0.0;

      pfVar13[6] = 0.0;

      pfVar13[7] = 0.0;

      pfVar13[8] = fVar24;

      pfVar13[0xb] = 0.0;

      pfVar13[10] = 0.0;

      pfVar13[9] = 0.0;

      pfVar13[0xe] = 0.0;

      pfVar13[0xd] = 0.0;

      pfVar13[0xc] = 0.0;

      pfVar13[0x12] = 0.0;

      pfVar13[0x11] = 0.0;

      pfVar13[0x10] = 0.0;

      pfVar13[0x15] = 0.0;

      pfVar13[0x14] = 0.0;

      pfVar13[0x13] = 0.0;

      pfVar13[0x16] = fVar18;

      pfVar13[0x18] = DAT_00a10e78;

      fVar18 = DAT_00aaa668;

      pfVar13[0xf] = 0.0;

      pfVar13[0x17] = 0.0;

      pfVar13[0x19] = fVar18;

      pfVar13[0x1c] = fVar18;

      pfVar13[0x1d] = fVar18;

      pfVar13[0x1a] = 0.0;

      pfVar13[0x1e] = 5.60519e-45;

      pfVar13[0x1b] = 3.22859e-42;

      pfVar13[0x1f] = fVar18;

      pfVar13[0x20] = 0.0;

    }

    pfVar13[0x1b] = (float)((-(uint)((char)param_8 != '\0') & 0xffffff80) + 0x80);

    if (param_2 != 0.0) {

      fVar24 = param_2;

    }

    pfVar13[0x18] = DAT_00af1850;

    pfVar13[0x1e] = 1.4013e-45;

LAB_004ee88c:

    pfVar13[0xf] = fVar24;

  }

  else {

    iVar9 = _stricmp("humanoid",param_1);

    if (iVar9 != 0) {

      iVar9 = _stricmp("creature",param_1);

      if (iVar9 != 0) {

        iVar9 = _stricmp("capsule",param_1);

        if (iVar9 == 0) {

          local_2654 = param_3 * param_9;

          FUN_005e1c80();

          local_2540 = 0;

          local_253c = 0;

          local_2538 = 0;

          local_2534 = 0;

          local_14 = 9;

          local_2650 = (float)(**(code **)(*DAT_00b05060 + 0x10))(0x30,0x22);

          *(uint16_t *)((int)local_2650 + 4) = 0x30;

          fStack_2634 = unaff_ESI * DAT_00a0f298;

          uStack_2644 = unaff_ESI * DAT_00aaa6cc;

          pvStack_1c._0_1_ = 10;

          local_2638 = 0;

          local_2630 = 0;

          local_262c = 0.0;

          local_2648 = (uint32_t /* width from decompiler */ *)0x0;

          local_2640 = (float *)0x0;

          local_263c = 0;

          puVar22 = (uint32_t /* width from decompiler */ *)FUN_006c9fd0(&local_2648,&local_2638,fStack_2634);

          pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,9);

          iStack_2568 = (-(uint)((char)param_7 != '\0') & 3) + 1;

          uStack_2564 = puVar22;

          if ((param_2 == 0.0) || (param_6 != '\0')) {

            uStack_24b4 = 7;

          }

          else {

            uStack_24b4 = 1;

            local_2608 = 0;

            local_2604 = 0.0;

            fStack_25ec = 0.0;

            fStack_25f0 = 0.0;

            uStack_25f4 = 0;

            uStack_25f8 = 0;

            uStack_25dc = 0;

            uStack_25e0 = 0;

            uStack_25e4 = 0;

            uStack_25e8 = 0;

            uStack_25cc = 0;

            uStack_25d0 = 0;

            uStack_25d4 = 0;

            uStack_25d8 = 0;

            uStack_25bc = 0;

            uStack_25c0 = 0;

            uStack_25c4 = 0;

            uStack_25c8 = 0;

            FUN_005f0210(puVar22 + 4,puVar22 + 8,unaff_ESI,param_2,&local_2608);

            FUN_004f2d70(&uStack_25e8);

            uStack_24d8 = uStack_25f8;

            uStack_24d4 = uStack_25f4;

            fStack_24d0 = fStack_25f0;

            fStack_24cc = fStack_25ec;

            fStack_24c8 = local_2604;

          }

          iVar9 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

          *(uint16_t *)(iVar9 + 4) = 0xa0;

          uStack_24._0_1_ = 0xb;

          iVar9 = FUN_005d4240(&uStack_2570);

          *(short *)((int)puVar22 + 6) = *(short *)((int)puVar22 + 6) + -1;

          uStack_24 = CONCAT31(uStack_24._1_3_,9);

          if (*(short *)((int)puVar22 + 6) == 0) {

            (**(code **)*puVar22)(1);

          }

          if ((param_4 == (int *)0x0) || (*param_4 == 0)) goto LAB_004f115b;

          puVar22 = operator_new(0x74);

          fVar24 = g_flOne;

          if (puVar22 == (uint32_t /* width from decompiler */ *)0x0) {

            puVar22 = (uint32_t /* width from decompiler */ *)0x0;

          }

          else {

            puVar22[1] = 3;

            puVar22[0xd] = 0;

            puVar22[0xc] = 0;

            puVar22[0xb] = 0;

            puVar22[2] = fVar24;

            puVar22[3] = 0;

            puVar22[4] = 0;

            puVar22[5] = 0;

            puVar22[6] = fVar24;

            puVar22[7] = 0;

            puVar22[8] = 0;

            puVar22[9] = 0;

            puVar22[10] = fVar24;

            puVar22[2] = fVar24;

            puVar22[3] = 0;

            puVar22[4] = 0;

            puVar22[5] = 0;

            puVar22[6] = fVar24;

            puVar22[7] = 0;

            puVar22[8] = 0;

            puVar22[9] = 0;

            puVar22[10] = fVar24;

            fVar18 = DAT_00aaa668;

            puVar22[0xd] = 0;

            puVar22[0xc] = 0;

            puVar22[0xb] = 0;

            *puVar22 = &PTR_FUN_009ccc38;

            puVar22[2] = fVar24;

            puVar22[3] = 0;

            puVar22[4] = 0;

            puVar22[5] = 0;

            puVar22[6] = fVar24;

            puVar22[7] = 0;

            puVar22[8] = 0;

            puVar22[9] = 0;

            puVar22[10] = fVar24;

            puVar22[0xd] = 0;

            puVar22[0xc] = 0;

            puVar22[0xb] = 0;

            puVar22[0xe] = 8;

            *(uint16_t *)(puVar22 + 0xf) = 0;

            *(uint16_t *)((int)puVar22 + 0x3e) = 0;

            puVar22[0x10] = 0;

            puVar22[0x13] = fVar18;

            puVar22[0x11] = fVar24;

            puVar22[0x12] = fVar18;

            puVar22[0x14] = 0;

            puVar22[0x15] = 0;

            puVar22[0x16] = 0;

            puVar22[0x17] = 0;

            puVar22[0x18] = 0;

            puVar22[0x19] = 0;

            puVar22[0x1a] = fVar24;

            puVar22[0x1b] = fVar24;

            puVar22[0x1c] = 0;

          }

          puVar22[0x1a] = param_3;

          puVar22[0x1b] = param_3;

          puVar22[0xb] = 0;

          puVar22[0xc] = 0;

          puVar22[0xd] = 0;

          if ((char)param_7 == '\0') {

            sVar6 = ((char)param_8 != '\0') + 1;

          }

          else {

            sVar6 = 4;

          }

          *(short *)(puVar22 + 0xf) = sVar6;

          if (sVar6 == 2) {

            *(byte *)((int)puVar22 + 0x39) = *(byte *)((int)puVar22 + 0x39) | 0x40;

          }

          iVar10 = *param_4;

          piVar21 = (int *)(iVar10 + 0x50);

          if (*(uint *)(iVar10 + 0x58) <= *(uint *)(iVar10 + 0x54)) {

            iVar19 = *piVar21;

            uVar8 = ((int)(*(uint *)(iVar10 + 0x54) - iVar19) >> 2) * 2 + 2;

            if (iVar19 == 0) {

              uVar16 = 0;

            }

            else {

              uVar16 = (int)(*(uint *)(iVar10 + 0x58) - iVar19) >> 2;

            }

            if (uVar16 < uVar8) {

              sVar25 = uVar8 * 4;

              puVar11 = malloc(sVar25);

              puVar23 = *(uint32_t /* width from decompiler */ **)(iVar10 + 0x54);

              puVar17 = puVar11;

              for (puVar12 = (uint32_t /* width from decompiler */ *)*piVar21; puVar12 != puVar23; puVar12 = puVar12 + 1) {

                *puVar17 = *puVar12;

                puVar17 = puVar17 + 1;

              }

              if ((void *)*piVar21 != (void *)0x0) {

                free((void *)*piVar21);

              }

              iVar19 = *piVar21;

              *piVar21 = (int)puVar11;

              *(size_t *)(iVar10 + 0x58) = sVar25 + (int)puVar11;

              *(uint32_t /* width from decompiler */ **)(iVar10 + 0x54) = puVar11 + (*(int *)(iVar10 + 0x54) - iVar19 >> 2);

            }

          }

          **(uint32_t /* width from decompiler */ **)(iVar10 + 0x54) = puVar22;

          *(int *)(iVar10 + 0x54) = *(int *)(iVar10 + 0x54) + 4;

          pfVar13 = operator_new(0x84);

          fVar24 = g_flOne;

          if (pfVar13 == (float *)0x0) {

            pfVar13 = (float *)0x0;

          }

          else {

            pfVar13[0xb] = 0.0;

            pfVar13[10] = 0.0;

            pfVar13[9] = 0.0;

            fVar18 = DAT_009c7b84;

            *pfVar13 = fVar24;

            pfVar13[1] = 0.0;

            pfVar13[2] = 0.0;

            pfVar13[3] = 0.0;

            pfVar13[4] = fVar24;

            pfVar13[5] = 0.0;

            pfVar13[6] = 0.0;

            pfVar13[7] = 0.0;

            pfVar13[8] = fVar24;

            pfVar13[0xb] = 0.0;

            pfVar13[10] = 0.0;

            pfVar13[9] = 0.0;

            pfVar13[0xe] = 0.0;

            pfVar13[0xd] = 0.0;

            pfVar13[0xc] = 0.0;

            pfVar13[0x12] = 0.0;

            pfVar13[0x11] = 0.0;

            pfVar13[0x10] = 0.0;

            pfVar13[0x15] = 0.0;

            pfVar13[0x14] = 0.0;

            pfVar13[0x13] = 0.0;

            pfVar13[0x16] = fVar18;

            pfVar13[0x18] = DAT_00a10e78;

            fVar18 = DAT_00aaa668;

            pfVar13[0xf] = 0.0;

            pfVar13[0x17] = 0.0;

            pfVar13[0x19] = fVar18;

            pfVar13[0x1c] = fVar18;

            pfVar13[0x1d] = fVar18;

            pfVar13[0x1a] = 0.0;

            pfVar13[0x1e] = 5.60519e-45;

            pfVar13[0x1b] = 3.22859e-42;

            pfVar13[0x1f] = fVar18;

            pfVar13[0x20] = 0.0;

          }

          pfVar13[0x1b] = (float)((-(uint)((char)param_8 != '\0') & 0xffffff80) + 0x80);

          if (param_2 != 0.0) {

            fVar24 = param_2;

          }

          pfVar13[0x18] = DAT_00af1850;

          pfVar13[0x1e] = 1.4013e-45;

        }

        else {

          iVar9 = _stricmp("tree",param_1);

          if (iVar9 == 0) {

            FUN_006ca7f0();

            local_262c = param_3;

            local_2620 = 0.0;

            local_261c = 0;

            local_2618 = 0.0;

            local_2614 = 0;

            local_2610 = 0;

            local_260c = DAT_00aaa690;

            local_2608 = 0;

            local_2604 = 0.0;

            iVar9 = (**(code **)(*DAT_00b05060 + 0x10))(0x30,0x22);

            *(uint16_t *)(iVar9 + 4) = 0x30;

            pvStack_1c = (void *)0xc;

            puVar22 = (uint32_t /* width from decompiler */ *)FUN_006ca750(&local_2638);

            pvStack_1c = (void *)0xffffffff;

            FUN_005e1c80();

            uStack_2548 = 0;

            uStack_2544 = 0;

            local_2540 = 0;

            local_253c = 0;

            uStack_24c0 = 0;

            uStack_24c4 = 0;

            uStack_24b4 = 7;

            iStack_2568 = 1;

            pvStack_1c = (void *)0xd;

            uStack_2564 = puVar22;

            iVar9 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

            *(uint16_t *)(iVar9 + 4) = 0xa0;

            uStack_24._0_1_ = 0xe;

            iVar9 = FUN_005d4240(&uStack_2570);

            *(short *)((int)puVar22 + 6) = *(short *)((int)puVar22 + 6) + -1;

            uStack_24 = CONCAT31(uStack_24._1_3_,0xd);

            if (*(short *)((int)puVar22 + 6) == 0) {

              (**(code **)*puVar22)(1);

            }

            if ((param_4 != (int *)0x0) && (*param_4 != 0)) {

              puVar22 = operator_new(0x74);

              fVar24 = g_flOne;

              if (puVar22 == (uint32_t /* width from decompiler */ *)0x0) {

                puVar22 = (uint32_t /* width from decompiler */ *)0x0;

              }

              else {

                puVar22[1] = 3;

                puVar22[0xd] = 0;

                puVar22[0xc] = 0;

                puVar22[0xb] = 0;

                puVar22[2] = fVar24;

                puVar22[3] = 0;

                puVar22[4] = 0;

                puVar22[5] = 0;

                puVar22[6] = fVar24;

                puVar22[7] = 0;

                puVar22[8] = 0;

                puVar22[9] = 0;

                puVar22[10] = fVar24;

                puVar22[2] = fVar24;

                puVar22[3] = 0;

                puVar22[4] = 0;

                puVar22[5] = 0;

                puVar22[6] = fVar24;

                puVar22[7] = 0;

                puVar22[8] = 0;

                puVar22[9] = 0;

                puVar22[10] = fVar24;

                fVar18 = DAT_00aaa668;

                puVar22[0xd] = 0;

                puVar22[0xc] = 0;

                puVar22[0xb] = 0;

                *puVar22 = &PTR_FUN_009ccc38;

                puVar22[2] = fVar24;

                puVar22[3] = 0;

                puVar22[4] = 0;

                puVar22[5] = 0;

                puVar22[6] = fVar24;

                puVar22[7] = 0;

                puVar22[8] = 0;

                puVar22[9] = 0;

                puVar22[10] = fVar24;

                puVar22[0xd] = 0;

                puVar22[0xc] = 0;

                puVar22[0xb] = 0;

                puVar22[0xe] = 8;

                *(uint16_t *)(puVar22 + 0xf) = 0;

                *(uint16_t *)((int)puVar22 + 0x3e) = 0;

                puVar22[0x10] = 0;

                puVar22[0x13] = fVar18;

                puVar22[0x11] = fVar24;

                puVar22[0x12] = fVar18;

                puVar22[0x14] = 0;

                puVar22[0x15] = 0;

                puVar22[0x16] = 0;

                puVar22[0x17] = 0;

                puVar22[0x18] = 0;

                puVar22[0x19] = 0;

                puVar22[0x1a] = fVar24;

                puVar22[0x1b] = fVar24;

                puVar22[0x1c] = 0;

              }

              puVar22[0x1a] = param_3;

              puVar22[0x1b] = DAT_00aaa690;

              puVar22[0xb] = 0;

              puVar22[0xc] = 0;

              puVar22[0xd] = 0;

              if ((char)param_7 == '\0') {

                sVar6 = ((char)param_8 != '\0') + 1;

              }

              else {

                sVar6 = 4;

              }

              *(short *)(puVar22 + 0xf) = sVar6;

              if (sVar6 == 2) {

                *(byte *)((int)puVar22 + 0x39) = *(byte *)((int)puVar22 + 0x39) | 0x40;

              }

              iVar10 = *param_4;

              piVar21 = (int *)(iVar10 + 0x50);

              if (*(uint *)(iVar10 + 0x58) <= *(uint *)(iVar10 + 0x54)) {

                iVar19 = *piVar21;

                uVar8 = ((int)(*(uint *)(iVar10 + 0x54) - iVar19) >> 2) * 2 + 2;

                if (iVar19 == 0) {

                  uVar16 = 0;

                }

                else {

                  uVar16 = (int)(*(uint *)(iVar10 + 0x58) - iVar19) >> 2;

                }

                if (uVar16 < uVar8) {

                  puVar11 = malloc(uVar8 * 4);

                  puVar23 = *(uint32_t /* width from decompiler */ **)(iVar10 + 0x54);

                  puVar17 = puVar11;

                  for (puVar12 = (uint32_t /* width from decompiler */ *)*piVar21; puVar12 != puVar23; puVar12 = puVar12 + 1)

                  {

                    *puVar17 = *puVar12;

                    puVar17 = puVar17 + 1;

                  }

                  if ((void *)*piVar21 != (void *)0x0) {

                    free((void *)*piVar21);

                  }

                  iVar19 = *piVar21;

                  *piVar21 = (int)puVar11;

                  *(uint32_t /* width from decompiler */ **)(iVar10 + 0x58) = puVar11 + uVar8;

                  *(uint32_t /* width from decompiler */ **)(iVar10 + 0x54) =

                       puVar11 + (*(int *)(iVar10 + 0x54) - iVar19 >> 2);

                }

              }

              **(uint32_t /* width from decompiler */ **)(iVar10 + 0x54) = puVar22;

              *(int *)(iVar10 + 0x54) = *(int *)(iVar10 + 0x54) + 4;

              pfVar13 = operator_new(0x84);

              fVar24 = g_flOne;

              if (pfVar13 == (float *)0x0) {

                pfVar13 = (float *)0x0;

              }

              else {

                pfVar13[0xb] = 0.0;

                pfVar13[10] = 0.0;

                pfVar13[9] = 0.0;

                fVar18 = DAT_009c7b84;

                *pfVar13 = fVar24;

                pfVar13[1] = 0.0;

                pfVar13[2] = 0.0;

                pfVar13[3] = 0.0;

                pfVar13[4] = fVar24;

                pfVar13[5] = 0.0;

                pfVar13[6] = 0.0;

                pfVar13[7] = 0.0;

                pfVar13[8] = fVar24;

                pfVar13[0xb] = 0.0;

                pfVar13[10] = 0.0;

                pfVar13[9] = 0.0;

                pfVar13[0xe] = 0.0;

                pfVar13[0xd] = 0.0;

                pfVar13[0xc] = 0.0;

                pfVar13[0x12] = 0.0;

                pfVar13[0x11] = 0.0;

                pfVar13[0x10] = 0.0;

                pfVar13[0x15] = 0.0;

                pfVar13[0x14] = 0.0;

                pfVar13[0x13] = 0.0;

                pfVar13[0x16] = fVar18;

                pfVar13[0x18] = DAT_00a10e78;

                fVar18 = DAT_00aaa668;

                pfVar13[0xf] = 0.0;

                pfVar13[0x17] = 0.0;

                pfVar13[0x19] = fVar18;

                pfVar13[0x1c] = fVar18;

                pfVar13[0x1d] = fVar18;

                pfVar13[0x1a] = 0.0;

                pfVar13[0x1e] = 5.60519e-45;

                pfVar13[0x1b] = 3.22859e-42;

                pfVar13[0x1f] = fVar18;

                pfVar13[0x20] = 0.0;

              }

              pfVar13[0x1b] = (float)((-(uint)((char)param_8 != '\0') & 0xffffff80) + 0x80);

              if (param_2 != 0.0) {

                fVar24 = param_2;

              }

              pfVar13[0xf] = fVar24;

              *(float **)(*param_4 + 0x30) = pfVar13;

              iVar10 = *param_4;

              *(uint32_t /* width from decompiler */ *)(iVar10 + 0x2c) = 0;

              *(uint32_t /* width from decompiler */ *)(iVar10 + 0x28) = 0;

              *(uint32_t /* width from decompiler */ *)(iVar10 + 0x24) = 0;

            }

            goto LAB_004f115b;

          }

          iVar9 = _stricmp("mine",param_1);

          if (iVar9 != 0) {

            iVar9 = _stricmp("hmine",param_1);

            if (iVar9 == 0) {

              FUN_006c9a50();

              local_2620 = param_3 * param_9 * DAT_00a0f298;

              local_2618 = DAT_00a0f298;

              local_261c = DAT_00aaa68c;

              local_2614 = 0;

              iVar9 = (**(code **)(*DAT_00b05060 + 0x10))(0x20,0x22);

              *(uint16_t *)(iVar9 + 4) = 0x20;

              pvStack_1c = (void *)0x12;

              puVar22 = (uint32_t /* width from decompiler */ *)FUN_006c7bc0(&local_2638);

              pvStack_1c = (void *)0xffffffff;

              FUN_005e1c80();

              uStack_24c4 = DAT_00a0f70c;

              pvStack_1c = (void *)0x13;

              uStack_2548 = 0;

              uStack_2544 = 0;

              local_2540 = 0;

              local_253c = 0;

              uStack_24c0 = 0;

              iStack_2568 = 1;

              uStack_2564 = puVar22;

              if ((param_2 == 0.0) || (param_6 != '\0')) {

                uStack_24b4 = 7;

              }

              else {

                uStack_24b4 = 1;

                FUN_004f2dc0();

                FUN_005ee750(&local_2628,param_2,auStack_2458);

                FUN_004f2d70(&local_2438);

                uStack_24d8 = uStack_2448;

                uStack_24d4 = uStack_2444;

                fStack_24d0 = local_2440;

                fStack_24cc = local_243c;

                fStack_24c8 = fStack_2454;

              }

              iVar9 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

              *(uint16_t *)(iVar9 + 4) = 0xa0;

              uStack_24._0_1_ = 0x14;

              iVar9 = FUN_005d4240(&uStack_2570);

              uStack_24 = CONCAT31(uStack_24._1_3_,0x13);

              FUN_005f5700(0x1000,1);

              *(short *)((int)puVar22 + 6) = *(short *)((int)puVar22 + 6) + -1;

              if (*(short *)((int)puVar22 + 6) == 0) {

                (**(code **)*puVar22)(1);

              }

              if ((char)local_24bc != '\a') {

                fStack_25b4 = 0.0;

                uStack_25b8 = 0;

                uStack_25bc = 0;

                uStack_25c0 = 0;

                uStack_25a4 = 0;

                uStack_25a8 = 0;

                iStack_25ac = 0;

                local_25b0 = 0.0;

                uStack_2594 = 0;

                uStack_2598 = 0;

                fStack_259c = 0.0;

                fStack_25a0 = 0.0;

                (**(code **)(**(int **)(iVar9 + 0x3c) + 0x30))(&uStack_25c0);

              }

              goto LAB_004f115b;

            }

            FUN_005e1c80();

            local_14 = 0x15;

            if (param_5 == '\0') {

              local_2400 = 0x10;

            }

            else if ((char)param_7 == '\0') {

              if (param_11 == '\0') {

                local_2400 = (param_6 != '\0') + 1;

              }

              else {

                local_2400 = 6;

              }

            }

            else {

              local_2400 = 4;

            }

            uStack_2644 = (float)CONCAT13(DAT_00b03e65 == '\0',(undefined3)uStack_2644);

            local_264c = (uint32_t /* width from decompiler */ *)0x0;

            local_2648 = (uint32_t /* width from decompiler */ *)0x0;

            FUN_004f2dc0();

            if ((char)param_8 == '\0') {

              iVar9 = (int)&uStack_2644 + 3;

              pcVar7 = local_2128;

              puVar22 = local_2338;

              FUN_007b6a20(puVar22,pcVar7,iVar9);

              local_264c = (uint32_t /* width from decompiler */ *)FUN_007b7b70(puVar22,pcVar7,iVar9);

              if (local_264c == (uint32_t /* width from decompiler */ *)0x0) goto LAB_004f0cea;

              if (uStack_2644._3_1_ == '\0') {

                local_2648 = (uint32_t /* width from decompiler */ *)

                             FUN_004ec8b0(param_1,param_2,param_3,param_4 + 1,param_4 + 3,

                                          param_4 + 4,local_2450);

              }

              else {

                local_2654 = 0.0;

                FUN_004aed30(&local_2654);

                piVar21 = param_4 + 4;

                if ((int)(param_4[6] & 0x7fffffffU) < (int)local_2654) {

                  fVar24 = (float)((param_4[6] & 0x7fffffffU) * 2);

                  fVar18 = local_2654;

                  if ((int)local_2654 < (int)fVar24) {

                    fVar18 = fVar24;

                  }

                  FUN_005b3300(piVar21,fVar18,0x10);

                }

                iVar9 = 0;

                if (0 < (int)local_2654) {

                  do {

                    FUN_004e1310(&local_2630);

                    local_2624 = local_2624 * param_3;

                    if (param_4[5] == (param_4[6] & 0x7fffffffU)) {

                      FUN_005b3370(piVar21,0x10);

                    }

                    puVar22 = (uint32_t /* width from decompiler */ *)(param_4[5] * 0x10 + *piVar21);

                    param_4[5] = param_4[5] + 1;

                    *puVar22 = local_2630;

                    puVar22[1] = local_262c;

                    puVar22[2] = local_2628;

                    iVar9 = iVar9 + 1;

                    puVar22[3] = local_2624;

                  } while (iVar9 < (int)local_2654);

                }

                FUN_004aed30(&local_263c);

                local_2648 = (uint32_t /* width from decompiler */ *)0x0;

                if (0 < local_263c) {

                  pfVar13 = local_2020 + 1;

                  do {

                    pfVar14 = pfVar13 + -1;

                    FUN_004aed30(pfVar14);

                    FUN_004aed30(pfVar13);

                    pfVar1 = pfVar13 + 1;

                    FUN_004aed30(pfVar1);

                    FUN_004aed30(pfVar13 + 2);

                    *pfVar14 = *pfVar14 * param_3;

                    *pfVar13 = *pfVar13 * param_3;

                    local_2648 = (uint32_t /* width from decompiler */ *)((int)local_2648 + 1);

                    pfVar13[2] = param_3 * pfVar13[2];

                    pfVar13 = pfVar13 + 4;

                    *pfVar1 = *pfVar1 * param_3;

                  } while ((int)local_2648 < local_263c);

                }

                puVar22 = local_264c;

                if ((param_2 != g_flZero) && (param_6 == '\0')) {

                  FUN_004f2cc0(local_2450);

                  if (param_2 != local_244c) {

                    if (local_244c == g_flZero) {

                      local_244c = g_flOne;

                    }

                    FUN_005ee8e0(param_2 / local_244c,local_2450);

                  }

                  local_2440 = local_2440 * param_3;

                  local_243c = local_243c * param_3;

                  local_2438 = local_2438 * param_3;

                  local_2434 = local_2434 * param_3;

                  if (param_3 != g_flOne) {

                    FUN_004f30d0(local_2430);

                    iVar9 = 0;

                    do {

                      iVar19 = 3;

                      iVar10 = iVar9;

                      do {

                        *(float *)((int)local_2430 + iVar10) =

                             *(float *)((int)&local_25b0 + iVar10) * param_3 * param_3 * param_3;

                        iVar10 = iVar10 + 0x10;

                        iVar19 = iVar19 + -1;

                      } while (iVar19 != 0);

                      iVar9 = iVar9 + 4;

                    } while (iVar9 < 0xc);

                  }

                }

                local_2640 = local_2020;

                local_2638 = 0x10;

                local_2650 = (float)(**(code **)(*DAT_00b05060 + 0x10))(0xe0,0x22);

                *(uint16_t *)((int)local_2650 + 4) = 0xe0;

                local_14._0_1_ = 0x16;

                local_2648 = (uint32_t /* width from decompiler */ *)

                             FUN_006c90d0(local_2640,local_263c,local_2638,param_4 + 4);

                local_14 = CONCAT31(local_14._1_3_,0x15);

                if (param_4 != (int *)0x0) {

                  if (local_263c < 1) {

                    (**(code **)*puVar22)(1);

                    FUN_007a4480(0,"VOG_DEBUG_STOP");

                    goto LAB_004f0cea;

                  }

                  pfVar14 = operator_new__(local_263c << 4);

                  param_4[1] = (int)pfVar14;

                  pfVar13 = local_2640;

                  for (uVar8 = (uint)(local_263c << 4) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

                    *pfVar14 = *pfVar13;

                    pfVar13 = pfVar13 + 1;

                    pfVar14 = pfVar14 + 1;

                  }

                  for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {

                    *(uint8_t *)pfVar14 = *(uint8_t *)pfVar13;

                    pfVar13 = (float *)((int)pfVar13 + 1);

                    pfVar14 = (float *)((int)pfVar14 + 1);

                  }

                  param_4[3] = local_263c;

                }

              }

            }

            cVar5 = FUN_004a6910();

            if ((cVar5 != '\0') && (*param_4 != 0)) {

              iVar9 = (int)&uStack_2644 + 2;

              puVar22 = &local_2230;

              uStack_2644._0_3_ = CONCAT12(DAT_00b03e65 == '\0',(uint16_t)uStack_2644);

              puVar23 = local_2338;

              FUN_007b6a20(puVar23,puVar22,iVar9);

              piVar21 = (int *)FUN_007b7b70(puVar23,puVar22,iVar9);

              if (piVar21 != (int *)0x0) {

                if (uStack_2644._2_1_ == '\0') {

                  FUN_004eb560(piVar21,param_1,param_2,0x3f800000,param_4,param_8,param_7);

                }

                else {

                  if ((void *)param_4[0x18] != (void *)0x0) {

                    operator_delete__((void *)param_4[0x18]);

                  }

                  param_4[0x18] = 0;

                  uVar8 = (**(code **)(*piVar21 + 0x1c))();

                  pvVar15 = operator_new__(uVar8);

                  param_4[0x18] = (int)pvVar15;

                  puVar22 = (uint32_t /* width from decompiler */ *)piVar21[1];

                  uVar8 = (**(code **)(*piVar21 + 0x1c))();

                  puVar23 = (uint32_t /* width from decompiler */ *)param_4[0x18];

                  for (uVar16 = uVar8 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {

                    *puVar23 = *puVar22;

                    puVar22 = puVar22 + 1;

                    puVar23 = puVar23 + 1;

                  }

                  bVar3 = param_3 == g_flOne;

                  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

                    *(uint8_t *)puVar23 = *(uint8_t *)puVar22;

                    puVar22 = (uint32_t /* width from decompiler */ *)((int)puVar22 + 1);

                    puVar23 = (uint32_t /* width from decompiler */ *)((int)puVar23 + 1);

                  }

                  if (bVar3) {

                    FUN_004b5790(param_4[0x18]);

                  }

                  else {

                    FUN_004b5cb0(param_4[0x18],param_2,param_3);

                  }

                }

              }

            }

            if (local_264c != (uint32_t /* width from decompiler */ *)0x0) {

              (**(code **)*local_264c)(1);

            }

            puVar22 = local_2648;

            if (local_2648 == (uint32_t /* width from decompiler */ *)0x0) {

LAB_004f0cea:

              local_14 = 0xffffffff;

              FUN_004eae80();

              ExceptionList = pvStack_1c;

              return 0;

            }

            if (param_12 != (uint32_t /* width from decompiler */ *)0x0) {

              FUN_006c9980();

              local_14 = CONCAT31(local_14._1_3_,0x17);

              if (uStack_25a8 == (uStack_25a4 & 0x7fffffff)) {

                FUN_005b3370(&iStack_25ac,4);

              }

              *(uint32_t /* width from decompiler */ **)(iStack_25ac + uStack_25a8 * 4) = puVar22;

              uStack_25a8 = uStack_25a8 + 1;

              if (uStack_25a8 == (uStack_25a4 & 0x7fffffff)) {

                FUN_005b3370(&iStack_25ac,4);

              }

              *(uint32_t /* width from decompiler */ **)(iStack_25ac + uStack_25a8 * 4) = param_12;

              uStack_25a8 = uStack_25a8 + 1;

              local_2650 = (float)(**(code **)(*DAT_00b05060 + 0x10))(0x38,0x22);

              *(uint16_t *)((int)local_2650 + 4) = 0x38;

              local_14._0_1_ = 0x18;

              puVar22 = (uint32_t /* width from decompiler */ *)FUN_006c9800(&local_25b0);

              local_14 = CONCAT31(local_14._1_3_,0x17);

              *(short *)((int)param_12 + 6) = *(short *)((int)param_12 + 6) + -1;

              if (*(short *)((int)param_12 + 6) == 0) {

                (**(code **)*param_12)(1);

              }

              *(short *)((int)local_2648 + 6) = *(short *)((int)local_2648 + 6) + -1;

              if (*(short *)((int)local_2648 + 6) == 0) {

                (**(code **)*local_2648)(1);

              }

              local_14 = CONCAT31(local_14._1_3_,0x15);

              FUN_004f3420();

            }

            puStack_23fc = puVar22;

            if ((param_2 == 0.0) || (param_6 != '\0')) {

              uStack_234c = 7;

              fStack_2360 = 0.0;

            }

            else {

              uStack_234c = 4;

              FUN_004f2d70(local_2430);

              fStack_2370 = local_2440;

              fStack_236c = local_243c;

              fStack_2368 = local_2438;

              fStack_2364 = local_2434;

              fStack_2360 = local_244c;

              param_4[0x14] = (int)local_2440;

              param_4[0x15] = (int)local_243c;

              param_4[0x16] = (int)local_2438;

              param_4[0x17] = (int)local_2434;

              FUN_004f2d70(local_2430);

            }

            uStack_23c8 = 0;

            uStack_23cc = 0;

            uStack_23d0 = 0;

            uStack_23e0 = 0;

            uStack_23dc = 0;

            uStack_23d8 = 0;

            uStack_23d4 = 0;

            uStack_2358 = 0;

            uStack_235c = 0;

            fStack_23c4 = g_flOne;

            uStack_2354 = param_10;

            iVar9 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

            *(uint16_t *)(iVar9 + 4) = 0xa0;

            uStack_24._0_1_ = 0x19;

            iVar9 = FUN_005d4240(auStack_2410);

            *(short *)((int)puVar22 + 6) = *(short *)((int)puVar22 + 6) + -1;

            uStack_24 = CONCAT31(uStack_24._1_3_,0x15);

            if (*(short *)((int)puVar22 + 6) == 0) {

              (**(code **)*puVar22)(1);

            }

            goto LAB_004f115b;

          }

          FUN_006c9a50();

          local_2650 = param_3 * param_9 * DAT_00a0f298;

          local_261c = DAT_00aaa68c;

          local_2614 = 0;

          local_2620 = local_2650;

          local_2618 = local_2650;

          iVar9 = (**(code **)(*DAT_00b05060 + 0x10))(0x20,0x22);

          *(uint16_t *)(iVar9 + 4) = 0x20;

          pvStack_1c = (void *)0xf;

          puVar22 = (uint32_t /* width from decompiler */ *)FUN_006c7bc0(&local_2638);

          pvStack_1c = (void *)0xffffffff;

          FUN_005e1c80();

          uStack_24c4 = DAT_00a0f70c;

          pvStack_1c = (void *)0x10;

          uStack_2548 = 0;

          uStack_2544 = 0;

          local_2540 = 0;

          local_253c = 0;

          uStack_24c0 = 0;

          iStack_2568 = 1;

          uStack_2564 = puVar22;

          if ((param_2 == 0.0) || (param_6 != '\0')) {

            uStack_24b4 = 7;

          }

          else {

            uStack_24b4 = 1;

            FUN_004f2dc0();

            FUN_005ee750(&local_2628,param_2,auStack_2458);

            FUN_004f2d70(&local_2438);

            uStack_24d8 = uStack_2448;

            uStack_24d4 = uStack_2444;

            fStack_24d0 = local_2440;

            fStack_24cc = local_243c;

            fStack_24c8 = fStack_2454;

          }

          iVar9 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

          *(uint16_t *)(iVar9 + 4) = 0xa0;

          uStack_24._0_1_ = 0x11;

          iVar9 = FUN_005d4240(&uStack_2570);

          uStack_24 = CONCAT31(uStack_24._1_3_,0x10);

          FUN_005f5700(0x1000,1);

          *(short *)((int)puVar22 + 6) = *(short *)((int)puVar22 + 6) + -1;

          if (*(short *)((int)puVar22 + 6) == 0) {

            (**(code **)*puVar22)(1);

          }

          if ((char)local_24bc != '\a') {

            fStack_25b4 = 0.0;

            uStack_25b8 = 0;

            uStack_25bc = 0;

            uStack_25c0 = 0;

            uStack_25a4 = 0;

            uStack_25a8 = 0;

            iStack_25ac = 0;

            local_25b0 = 0.0;

            uStack_2594 = 0;

            uStack_2598 = 0;

            fStack_259c = 0.0;

            fStack_25a0 = 0.0;

            (**(code **)(**(int **)(iVar9 + 0x3c) + 0x30))(&uStack_25c0);

          }

          if ((param_4 == (int *)0x0) || (*param_4 == 0)) goto LAB_004f115b;

          puVar22 = operator_new(0x74);

          fVar24 = g_flOne;

          if (puVar22 == (uint32_t /* width from decompiler */ *)0x0) {

            puVar22 = (uint32_t /* width from decompiler */ *)0x0;

          }

          else {

            puVar22[1] = 2;

            puVar22[0xd] = 0;

            puVar22[0xc] = 0;

            puVar22[0xb] = 0;

            puVar22[2] = fVar24;

            puVar22[3] = 0;

            puVar22[4] = 0;

            puVar22[5] = 0;

            puVar22[6] = fVar24;

            puVar22[7] = 0;

            puVar22[8] = 0;

            puVar22[9] = 0;

            puVar22[10] = fVar24;

            puVar22[2] = fVar24;

            puVar22[3] = 0;

            puVar22[4] = 0;

            puVar22[5] = 0;

            puVar22[6] = fVar24;

            puVar22[7] = 0;

            puVar22[8] = 0;

            puVar22[9] = 0;

            puVar22[10] = fVar24;

            fVar18 = DAT_00aaa668;

            puVar22[0xd] = 0;

            puVar22[0xc] = 0;

            puVar22[0xb] = 0;

            *puVar22 = &PTR_FUN_009c7ba4;

            puVar22[2] = fVar24;

            puVar22[3] = 0;

            puVar22[4] = 0;

            puVar22[5] = 0;

            puVar22[6] = fVar24;

            puVar22[7] = 0;

            puVar22[8] = 0;

            puVar22[9] = 0;

            puVar22[10] = fVar24;

            puVar22[0xd] = 0;

            puVar22[0xc] = 0;

            puVar22[0xb] = 0;

            puVar22[0xe] = 8;

            *(uint16_t *)(puVar22 + 0xf) = 0;

            *(uint16_t *)((int)puVar22 + 0x3e) = 0;

            puVar22[0x10] = 0;

            puVar22[0x13] = fVar18;

            puVar22[0x11] = fVar24;

            puVar22[0x12] = fVar18;

            puVar22[0x14] = 0;

            puVar22[0x15] = 0;

            puVar22[0x16] = 0;

            puVar22[0x17] = 0;

            puVar22[0x18] = 0;

            puVar22[0x19] = 0;

            puVar22[0x1c] = 0;

            puVar22[0x1b] = 0;

            puVar22[0x1a] = 0;

          }

          uVar4 = DAT_00aaa68c;

          puVar22[0x1a] = unaff_EDI;

          puVar22[0x1b] = uVar4;

          puVar22[0x1c] = unaff_EDI;

          puVar22[0xb] = 0;

          puVar22[0xc] = 0;

          puVar22[0xd] = 0;

          if ((char)param_7 == '\0') {

            sVar6 = ((char)param_8 != '\0') + 1;

          }

          else {

            sVar6 = 4;

          }

          *(short *)(puVar22 + 0xf) = sVar6;

          if (sVar6 == 2) {

            *(byte *)((int)puVar22 + 0x39) = *(byte *)((int)puVar22 + 0x39) | 0x40;

          }

          iVar10 = *param_4;

          piVar21 = (int *)(iVar10 + 0x50);

          if (*(uint *)(iVar10 + 0x58) <= *(uint *)(iVar10 + 0x54)) {

            iVar19 = *piVar21;

            uVar8 = ((int)(*(uint *)(iVar10 + 0x54) - iVar19) >> 2) * 2 + 2;

            if (iVar19 == 0) {

              uVar16 = 0;

            }

            else {

              uVar16 = (int)(*(uint *)(iVar10 + 0x58) - iVar19) >> 2;

            }

            if (uVar16 < uVar8) {

              sVar25 = uVar8 * 4;

              puVar11 = malloc(sVar25);

              puVar23 = *(uint32_t /* width from decompiler */ **)(iVar10 + 0x54);

              puVar17 = puVar11;

              for (puVar12 = (uint32_t /* width from decompiler */ *)*piVar21; puVar12 != puVar23; puVar12 = puVar12 + 1) {

                *puVar17 = *puVar12;

                puVar17 = puVar17 + 1;

              }

              if ((void *)*piVar21 != (void *)0x0) {

                free((void *)*piVar21);

              }

              iVar19 = *piVar21;

              *piVar21 = (int)puVar11;

              *(size_t *)(iVar10 + 0x58) = (int)puVar11 + sVar25;

              *(uint32_t /* width from decompiler */ **)(iVar10 + 0x54) = puVar11 + (*(int *)(iVar10 + 0x54) - iVar19 >> 2);

            }

          }

          **(uint32_t /* width from decompiler */ **)(iVar10 + 0x54) = puVar22;

          *(int *)(iVar10 + 0x54) = *(int *)(iVar10 + 0x54) + 4;

          pfVar13 = operator_new(0x84);

          fVar24 = g_flOne;

          if (pfVar13 == (float *)0x0) {

            pfVar13 = (float *)0x0;

          }

          else {

            pfVar13[0xb] = 0.0;

            pfVar13[10] = 0.0;

            pfVar13[9] = 0.0;

            fVar18 = DAT_009c7b84;

            *pfVar13 = fVar24;

            pfVar13[1] = 0.0;

            pfVar13[2] = 0.0;

            pfVar13[3] = 0.0;

            pfVar13[4] = fVar24;

            pfVar13[5] = 0.0;

            pfVar13[6] = 0.0;

            pfVar13[7] = 0.0;

            pfVar13[8] = fVar24;

            pfVar13[0xb] = 0.0;

            pfVar13[10] = 0.0;

            pfVar13[9] = 0.0;

            pfVar13[0xe] = 0.0;

            pfVar13[0xd] = 0.0;

            pfVar13[0xc] = 0.0;

            pfVar13[0x12] = 0.0;

            pfVar13[0x11] = 0.0;

            pfVar13[0x10] = 0.0;

            pfVar13[0x15] = 0.0;

            pfVar13[0x14] = 0.0;

            pfVar13[0x13] = 0.0;

            pfVar13[0x16] = fVar18;

            pfVar13[0x18] = DAT_00a10e78;

            fVar18 = DAT_00aaa668;

            pfVar13[0xf] = 0.0;

            pfVar13[0x17] = 0.0;

            pfVar13[0x19] = fVar18;

            pfVar13[0x1c] = fVar18;

            pfVar13[0x1d] = fVar18;

            pfVar13[0x1a] = 0.0;

            pfVar13[0x1e] = 5.60519e-45;

            pfVar13[0x1b] = 3.22859e-42;

            pfVar13[0x1f] = fVar18;

            pfVar13[0x20] = 0.0;

          }

          pfVar13[0x1b] = (float)((-(uint)((char)param_8 != '\0') & 0xffffff80) + 0x80);

          if (param_2 != 0.0) {

            fVar24 = param_2;

          }

        }

        pfVar13[0xf] = fVar24;

        *(float **)(*param_4 + 0x30) = pfVar13;

        iVar10 = *param_4;

        *(uint32_t /* width from decompiler */ *)(iVar10 + 0x2c) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar10 + 0x28) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar10 + 0x24) = 0;

LAB_004f115b:

        uStack_24 = 0xffffffff;

        FUN_004eae80();

        ExceptionList = pvStack_2c;

        return iVar9;

      }

      local_2654 = param_3 * param_9;

      FUN_005e1c80();

      local_2540 = 0;

      local_253c = 0;

      local_2538 = 0;

      local_2534 = 0;

      local_24b8 = 0;

      local_24bc = DAT_00a0f70c;

      iVar9 = 0x30;

      local_14 = 6;

      local_2650 = (float)(**(code **)(*DAT_00b05060 + 0x10))(0x30,0x22);

      *(uint16_t *)((int)local_2650 + 4) = 0x30;

      fStack_2634 = unaff_ESI * DAT_00a0f298;

      uStack_2644 = unaff_ESI * DAT_00aaa6cc;

      pvStack_1c._0_1_ = 7;

      local_2638 = 0;

      local_2630 = 0;

      local_262c = 0.0;

      local_2648 = (uint32_t /* width from decompiler */ *)0x0;

      local_2640 = (float *)0x0;

      local_263c = 0;

      puVar22 = (uint32_t /* width from decompiler */ *)FUN_006c9fd0(&local_2648,&local_2638,fStack_2634);

      pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,6);

      iStack_2568 = (-(uint)((char)param_7 != '\0') & 3) + 1;

      uStack_2564 = puVar22;

      if ((param_2 == 0.0) || (param_6 != '\0')) {

        uStack_24b4 = 7;

      }

      else {

        uStack_24b4 = 1;

        local_2608 = 0;

        local_2604 = 0.0;

        fStack_25ec = 0.0;

        fStack_25f0 = 0.0;

        uStack_25f4 = 0;

        uStack_25f8 = 0;

        uStack_25dc = 0;

        uStack_25e0 = 0;

        uStack_25e4 = 0;

        uStack_25e8 = 0;

        uStack_25cc = 0;

        uStack_25d0 = 0;

        uStack_25d4 = 0;

        uStack_25d8 = 0;

        uStack_25bc = 0;

        uStack_25c0 = 0;

        uStack_25c4 = 0;

        uStack_25c8 = 0;

        FUN_005f0210(puVar22 + 4,puVar22 + 8,unaff_ESI,param_2,&local_2608);

        FUN_004f2d70(&uStack_25e8);

        uStack_24d8 = uStack_25f8;

        uStack_24d4 = uStack_25f4;

        fStack_24d0 = fStack_25f0;

        fStack_24cc = fStack_25ec;

        fStack_24c8 = local_2604;

      }

      iVar10 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

      *(uint16_t *)(iVar10 + 4) = 0xa0;

      uStack_24._0_1_ = 8;

      iVar10 = FUN_005d4240(&uStack_2570);

      *(short *)((int)puVar22 + 6) = *(short *)((int)puVar22 + 6) + -1;

      uStack_24 = CONCAT31(uStack_24._1_3_,6);

      if (*(short *)((int)puVar22 + 6) == 0) {

        (**(code **)*puVar22)(1);

      }

      if ((param_4 == (int *)0x0) || (*param_4 == 0)) goto LAB_004ee8ac;

      puVar22 = operator_new(0x74);

      fVar24 = g_flOne;

      if (puVar22 == (uint32_t /* width from decompiler */ *)0x0) {

        puVar22 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        puVar22[1] = 3;

        puVar22[0xd] = 0;

        puVar22[0xc] = 0;

        puVar22[0xb] = 0;

        puVar22[2] = fVar24;

        puVar22[3] = 0;

        puVar22[4] = 0;

        puVar22[5] = 0;

        puVar22[6] = fVar24;

        puVar22[7] = 0;

        puVar22[8] = 0;

        puVar22[9] = 0;

        puVar22[10] = fVar24;

        puVar22[2] = fVar24;

        puVar22[3] = 0;

        puVar22[4] = 0;

        puVar22[5] = 0;

        puVar22[6] = fVar24;

        puVar22[7] = 0;

        puVar22[8] = 0;

        puVar22[9] = 0;

        puVar22[10] = fVar24;

        fVar18 = DAT_00aaa668;

        puVar22[0xd] = 0;

        puVar22[0xc] = 0;

        puVar22[0xb] = 0;

        *puVar22 = &PTR_FUN_009ccc38;

        puVar22[2] = fVar24;

        puVar22[3] = 0;

        puVar22[4] = 0;

        puVar22[5] = 0;

        puVar22[6] = fVar24;

        puVar22[7] = 0;

        puVar22[8] = 0;

        puVar22[9] = 0;

        puVar22[10] = fVar24;

        puVar22[0xd] = 0;

        puVar22[0xc] = 0;

        puVar22[0xb] = 0;

        puVar22[0xe] = 8;

        *(uint16_t *)(puVar22 + 0xf) = 0;

        *(uint16_t *)((int)puVar22 + 0x3e) = 0;

        puVar22[0x10] = 0;

        puVar22[0x13] = fVar18;

        puVar22[0x11] = fVar24;

        puVar22[0x12] = fVar18;

        puVar22[0x14] = 0;

        puVar22[0x15] = 0;

        puVar22[0x16] = 0;

        puVar22[0x17] = 0;

        puVar22[0x18] = 0;

        puVar22[0x19] = 0;

        puVar22[0x1a] = fVar24;

        puVar22[0x1b] = fVar24;

        puVar22[0x1c] = 0;

      }

      puVar22[0x1a] = param_3;

      puVar22[0x1b] = param_3;

      puVar22[0xb] = 0;

      puVar22[0xc] = 0;

      puVar22[0xd] = 0;

      if ((char)param_7 == '\0') {

        sVar6 = ((char)param_8 != '\0') + 1;

      }

      else {

        sVar6 = 4;

      }

      *(short *)(puVar22 + 0xf) = sVar6;

      if (sVar6 == 2) {

        *(byte *)((int)puVar22 + 0x39) = *(byte *)((int)puVar22 + 0x39) | 0x40;

      }

      iVar19 = *param_4;

      piVar21 = (int *)(iVar19 + 0x50);

      if (*(uint *)(iVar19 + 0x58) <= *(uint *)(iVar19 + 0x54)) {

        iVar2 = *piVar21;

        uVar8 = ((int)(*(uint *)(iVar19 + 0x54) - iVar2) >> 2) * 2 + 2;

        if (iVar2 == 0) {

          uVar16 = 0;

        }

        else {

          uVar16 = (int)(*(uint *)(iVar19 + 0x58) - iVar2) >> 2;

        }

        if (uVar16 < uVar8) {

          sVar25 = uVar8 * 4;

          puVar11 = malloc(sVar25);

          puVar23 = *(uint32_t /* width from decompiler */ **)(iVar19 + 0x54);

          puVar17 = puVar11;

          for (puVar12 = (uint32_t /* width from decompiler */ *)*piVar21; puVar12 != puVar23; puVar12 = puVar12 + 1) {

            *puVar17 = *puVar12;

            puVar17 = puVar17 + 1;

          }

          if ((void *)*piVar21 != (void *)0x0) {

            free((void *)*piVar21);

          }

          iVar2 = *piVar21;

          *piVar21 = (int)puVar11;

          *(size_t *)(iVar19 + 0x58) = sVar25 + (int)puVar11;

          *(uint32_t /* width from decompiler */ **)(iVar19 + 0x54) = puVar11 + (*(int *)(iVar19 + 0x54) - iVar2 >> 2);

        }

      }

      **(uint32_t /* width from decompiler */ **)(iVar19 + 0x54) = puVar22;

      *(int *)(iVar19 + 0x54) = *(int *)(iVar19 + 0x54) + 4;

      pfVar13 = operator_new(0x84);

      fVar24 = g_flOne;

      if (pfVar13 == (float *)0x0) {

        pfVar13 = (float *)0x0;

      }

      else {

        pfVar13[0xb] = 0.0;

        pfVar13[10] = 0.0;

        pfVar13[9] = 0.0;

        fVar18 = DAT_009c7b84;

        *pfVar13 = fVar24;

        pfVar13[1] = 0.0;

        pfVar13[2] = 0.0;

        pfVar13[3] = 0.0;

        pfVar13[4] = fVar24;

        pfVar13[5] = 0.0;

        pfVar13[6] = 0.0;

        pfVar13[7] = 0.0;

        pfVar13[8] = fVar24;

        pfVar13[0xb] = 0.0;

        pfVar13[10] = 0.0;

        pfVar13[9] = 0.0;

        pfVar13[0xe] = 0.0;

        pfVar13[0xd] = 0.0;

        pfVar13[0xc] = 0.0;

        pfVar13[0x12] = 0.0;

        pfVar13[0x11] = 0.0;

        pfVar13[0x10] = 0.0;

        pfVar13[0x15] = 0.0;

        pfVar13[0x14] = 0.0;

        pfVar13[0x13] = 0.0;

        pfVar13[0x16] = fVar18;

        pfVar13[0x18] = DAT_00a10e78;

        fVar18 = DAT_00aaa668;

        pfVar13[0xf] = 0.0;

        pfVar13[0x17] = 0.0;

        pfVar13[0x19] = fVar18;

        pfVar13[0x1c] = fVar18;

        pfVar13[0x1d] = fVar18;

        pfVar13[0x1a] = 0.0;

        pfVar13[0x1e] = 5.60519e-45;

        pfVar13[0x1b] = 3.22859e-42;

        pfVar13[0x1f] = fVar18;

        pfVar13[0x20] = 0.0;

      }

      pfVar13[0x1e] = 1.4013e-45;

      pfVar13[0x1b] = (float)((-(uint)((char)param_8 != '\0') & 0xffffff80) + 0x80);

      if (param_2 != 0.0) {

        fVar24 = param_2;

      }

      goto LAB_004ee88c;

    }

    iVar9 = 0x10;

    iVar10 = (**(code **)(*DAT_00b05060 + 0x10))(0x10,0x22);

    *(uint16_t *)(iVar10 + 4) = 0x10;

    pvStack_1c = (void *)0x3;

    puVar22 = (uint32_t /* width from decompiler */ *)FUN_006c7fa0(param_3);

    pvStack_1c = (void *)0xffffffff;

    FUN_005e1c80();

    pvStack_1c = (void *)0x4;

    iStack_2568 = (-(uint)((char)param_7 != '\0') & 3) + 1;

    uStack_2548 = 0;

    uStack_2544 = 0;

    local_2540 = 0;

    local_253c = 0;

    uStack_24c0 = 0;

    uStack_24c4 = DAT_00a0f70c;

    uStack_24b4 = 2;

    local_2608 = 0;

    local_2604 = 0.0;

    fStack_25ec = 0.0;

    fStack_25f0 = 0.0;

    uStack_25f4 = 0;

    uStack_25f8 = 0;

    uStack_25dc = 0;

    uStack_25e0 = 0;

    uStack_25e4 = 0;

    uStack_25e8 = 0;

    uStack_25cc = 0;

    uStack_25d0 = 0;

    uStack_25d4 = 0;

    uStack_25d8 = 0;

    uStack_25bc = 0;

    uStack_25c0 = 0;

    uStack_25c4 = 0;

    uStack_25c8 = 0;

    uStack_2564 = puVar22;

    FUN_005ee680(param_3,0x42480000,&local_2608);

    FUN_004f2d70(&uStack_25e8);

    uStack_24d8 = uStack_25f8;

    uStack_24d4 = uStack_25f4;

    fStack_24d0 = fStack_25f0;

    fStack_24cc = fStack_25ec;

    fStack_24c8 = local_2604;

    iVar10 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

    *(uint16_t *)(iVar10 + 4) = 0xa0;

    uStack_24._0_1_ = 5;

    iVar10 = FUN_005d4240(&uStack_2570);

    *(short *)((int)puVar22 + 6) = *(short *)((int)puVar22 + 6) + -1;

    uStack_24 = CONCAT31(uStack_24._1_3_,4);

    if (*(short *)((int)puVar22 + 6) == 0) {

      (**(code **)*puVar22)(1);

    }

    fStack_2634 = 0.0;

    local_2638 = 0;

    local_263c = 0;

    local_2640 = (float *)0x0;

    local_2624 = 0.0;

    local_2628 = 0;

    local_262c = 0.0;

    local_2630 = 0;

    local_2614 = 0;

    local_2618 = 0.0;

    local_261c = 0;

    local_2620 = 0.0;

    (**(code **)(**(int **)(iVar10 + 0x3c) + 0x30))(&local_2640);

    if ((param_4 == (int *)0x0) || (*param_4 == 0)) goto LAB_004ee8ac;

    pfVar13 = operator_new(0x84);

    fVar24 = g_flOne;

    if (pfVar13 == (float *)0x0) {

      pfVar13 = (float *)0x0;

    }

    else {

      pfVar13[0xb] = 0.0;

      pfVar13[10] = 0.0;

      pfVar13[9] = 0.0;

      *pfVar13 = fVar24;

      pfVar13[4] = fVar24;

      pfVar13[8] = fVar24;

      fVar24 = DAT_009c7b84;

      pfVar13[1] = 0.0;

      pfVar13[2] = 0.0;

      pfVar13[3] = 0.0;

      pfVar13[5] = 0.0;

      pfVar13[6] = 0.0;

      pfVar13[7] = 0.0;

      pfVar13[0xb] = 0.0;

      pfVar13[10] = 0.0;

      pfVar13[9] = 0.0;

      pfVar13[0xe] = 0.0;

      pfVar13[0xd] = 0.0;

      pfVar13[0xc] = 0.0;

      pfVar13[0x12] = 0.0;

      pfVar13[0x11] = 0.0;

      pfVar13[0x10] = 0.0;

      pfVar13[0x15] = 0.0;

      pfVar13[0x14] = 0.0;

      pfVar13[0x13] = 0.0;

      pfVar13[0x16] = fVar24;

      pfVar13[0x18] = DAT_00a10e78;

      fVar24 = DAT_00aaa668;

      pfVar13[0xf] = 0.0;

      pfVar13[0x17] = 0.0;

      pfVar13[0x19] = fVar24;

      pfVar13[0x1c] = fVar24;

      pfVar13[0x1d] = fVar24;

      pfVar13[0x1a] = 0.0;

      pfVar13[0x1e] = 5.60519e-45;

      pfVar13[0x1b] = 3.22859e-42;

      pfVar13[0x1f] = fVar24;

      pfVar13[0x20] = 0.0;

    }

    puVar22 = operator_new(0x6c);

    fVar24 = g_flOne;

    if (puVar22 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar22 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar22[1] = 1;

      puVar22[0xd] = 0;

      puVar22[0xc] = 0;

      puVar22[0xb] = 0;

      puVar22[2] = fVar24;

      puVar22[3] = 0;

      puVar22[4] = 0;

      puVar22[5] = 0;

      puVar22[6] = fVar24;

      puVar22[7] = 0;

      puVar22[8] = 0;

      puVar22[9] = 0;

      puVar22[10] = fVar24;

      puVar22[2] = fVar24;

      puVar22[3] = 0;

      puVar22[4] = 0;

      puVar22[5] = 0;

      puVar22[6] = fVar24;

      puVar22[7] = 0;

      puVar22[8] = 0;

      puVar22[9] = 0;

      puVar22[10] = fVar24;

      fVar18 = DAT_00aaa668;

      puVar22[0xd] = 0;

      puVar22[0xc] = 0;

      puVar22[0xb] = 0;

      *puVar22 = &PTR_FUN_009c7bb4;

      puVar22[2] = fVar24;

      puVar22[3] = 0;

      puVar22[4] = 0;

      puVar22[5] = 0;

      puVar22[6] = fVar24;

      puVar22[7] = 0;

      puVar22[8] = 0;

      puVar22[9] = 0;

      puVar22[10] = fVar24;

      puVar22[0xd] = 0;

      puVar22[0xc] = 0;

      puVar22[0xb] = 0;

      puVar22[0xe] = 8;

      *(uint16_t *)(puVar22 + 0xf) = 0;

      *(uint16_t *)((int)puVar22 + 0x3e) = 0;

      puVar22[0x10] = 0;

      puVar22[0x13] = fVar18;

      puVar22[0x11] = fVar24;

      puVar22[0x12] = fVar18;

      puVar22[0x14] = 0;

      puVar22[0x15] = 0;

      puVar22[0x16] = 0;

      puVar22[0x17] = 0;

      puVar22[0x18] = 0;

      puVar22[0x19] = 0;

      puVar22[0x1a] = fVar24;

    }

    puVar22[0x1a] = param_3;

    puVar22[0xb] = 0;

    puVar22[0xc] = param_3;

    puVar22[0xd] = 0;

    if ((char)param_7 == '\0') {

      sVar6 = ((char)param_8 != '\0') + 1;

    }

    else {

      sVar6 = 4;

    }

    *(short *)(puVar22 + 0xf) = sVar6;

    if (sVar6 == 2) {

      *(byte *)((int)puVar22 + 0x39) = *(byte *)((int)puVar22 + 0x39) | 0x40;

    }

    iVar19 = *param_4;

    piVar21 = (int *)(iVar19 + 0x50);

    if (*(uint *)(iVar19 + 0x58) <= *(uint *)(iVar19 + 0x54)) {

      iVar2 = *piVar21;

      uVar8 = ((int)(*(uint *)(iVar19 + 0x54) - iVar2) >> 2) * 2 + 2;

      if (iVar2 == 0) {

        uVar16 = 0;

      }

      else {

        uVar16 = (int)(*(uint *)(iVar19 + 0x58) - iVar2) >> 2;

      }

      if (uVar16 < uVar8) {

        puVar11 = malloc(uVar8 * 4);

        puVar23 = *(uint32_t /* width from decompiler */ **)(iVar19 + 0x54);

        puVar17 = puVar11;

        for (puVar12 = (uint32_t /* width from decompiler */ *)*piVar21; puVar12 != puVar23; puVar12 = puVar12 + 1) {

          *puVar17 = *puVar12;

          puVar17 = puVar17 + 1;

        }

        if ((void *)*piVar21 != (void *)0x0) {

          free((void *)*piVar21);

        }

        fVar24 = g_flOne;

        iVar2 = *piVar21;

        *piVar21 = (int)puVar11;

        *(uint32_t /* width from decompiler */ **)(iVar19 + 0x58) = puVar11 + uVar8;

        *(uint32_t /* width from decompiler */ **)(iVar19 + 0x54) = puVar11 + (*(int *)(iVar19 + 0x54) - iVar2 >> 2);

      }

    }

    **(uint32_t /* width from decompiler */ **)(iVar19 + 0x54) = puVar22;

    *(int *)(iVar19 + 0x54) = *(int *)(iVar19 + 0x54) + 4;

    pfVar13[0x1b] = (float)((-(uint)((char)param_8 != '\0') & 0xffffff80) + 0x80);

    if (param_2 != 0.0) {

      fVar24 = param_2;

    }

    pfVar13[0xf] = fVar24;

    pfVar13[0x1e] = 1.4013e-45;

  }

  *(float **)(*param_4 + 0x30) = pfVar13;

  iVar19 = *param_4;

  *(uint32_t /* width from decompiler */ *)(iVar19 + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar19 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar19 + 0x24) = 0;

LAB_004ee8ac:

  uStack_24 = 0xffffffff;

  if (local_255c < 0) {

    ExceptionList = pvStack_2c;

    return iVar10;

  }

  (**(code **)(*DAT_00b05060 + 0x14))(uStack_2564,local_255c * 8,0x12);

  ExceptionList = pvStack_38;

  return iVar9;

}
