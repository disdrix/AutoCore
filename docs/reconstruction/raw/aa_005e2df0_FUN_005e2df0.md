# Raw capture: FUN_005e2df0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e2df0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005e2df0` |
| **Canonical name** | `FUN_005e2df0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_005e2df0(int *param_1,float *param_2,int *param_3,float param_4,float param_5,float param_6,
            float *param_7,float *param_8)

{
  void *pvVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  float *pfVar5;
  int *piVar6;
  undefined4 *puVar7;
  ushort *puVar8;
  ushort uVar9;
  int iVar10;
  uint uVar11;
  float *pfVar12;
  float *pfVar13;
  undefined4 *puVar14;
  undefined2 in_FPUControlWord;
  float10 fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined1 auStack_598 [8];
  undefined4 uStack_590;
  float *pfStack_58c;
  float *pfStack_588;
  float *pfStack_584;
  float *pfStack_580;
  float *pfStack_57c;
  float *pfStack_578;
  float *pfStack_574;
  float *pfStack_570;
  void **ppvStack_56c;
  float fStack_54c;
  float fStack_548;
  void *pvStack_544;
  undefined1 *puStack_540;
  float fStack_53c;
  float fStack_538;
  float fStack_534;
  float *pfStack_530;
  float fStack_52c;
  void *pvStack_528;
  float fStack_524;
  int iStack_520;
  float fStack_51c;
  float fStack_518;
  float fStack_514;
  float fStack_510;
  float fStack_50c;
  float fStack_508;
  float fStack_504;
  float fStack_500;
  float fStack_4fc;
  float fStack_4f8;
  float fStack_4f4;
  float fStack_4f0;
  float fStack_4ec;
  float fStack_4e8;
  float fStack_4e4;
  undefined1 *puStack_4e0;
  void *pvStack_4dc;
  float fStack_4d8;
  float *pfStack_4d4;
  undefined1 auStack_4cc [4];
  float *pfStack_4c8;
  float *pfStack_4c4;
  float fStack_4c0;
  void *pvStack_4bc;
  undefined4 uStack_4b8;
  undefined4 uStack_4b4;
  undefined4 uStack_4b0;
  undefined4 uStack_4ac;
  undefined4 uStack_4a8;
  float fStack_4a0;
  undefined1 uStack_49c;
  undefined1 uStack_49b;
  undefined1 uStack_49a;
  undefined1 uStack_499;
  float fStack_494;
  float fStack_490;
  float local_48c;
  float local_488;
  float local_484;
  float fStack_480;
  float fStack_47c;
  float fStack_478;
  float fStack_474;
  float fStack_470;
  float fStack_46c;
  float fStack_468;
  float fStack_464;
  float fStack_460;
  float fStack_45c;
  float fStack_458;
  float fStack_454;
  float fStack_450;
  float fStack_44c;
  float fStack_448;
  float fStack_444;
  float fStack_440;
  float fStack_43c;
  void *pvStack_438;
  float *local_430;
  undefined4 local_42c;
  undefined4 local_428;
  float fStack_424;
  float fStack_420;
  float fStack_41c;
  void *pvStack_418;
  undefined4 *puStack_414;
  int local_410;
  undefined4 local_40c;
  undefined4 local_408;
  float fStack_404;
  float fStack_400;
  float fStack_3fc;
  float fStack_3f8;
  float fStack_3f4;
  float fStack_3f0;
  float fStack_3ec;
  float fStack_3e8;
  float fStack_3e4;
  float fStack_3e0;
  float fStack_3dc;
  float fStack_3d8;
  float fStack_3d4;
  float fStack_3d0;
  float fStack_3cc;
  float fStack_3c8;
  float fStack_3c4;
  float fStack_3c0;
  float fStack_3bc;
  float fStack_3b8;
  float fStack_3b4;
  float fStack_3b0;
  float fStack_3ac;
  float fStack_3a8;
  float fStack_3a4;
  float fStack_3a0;
  float fStack_39c;
  float fStack_398;
  float fStack_394;
  float fStack_390;
  float fStack_38c;
  float fStack_388;
  float fStack_384;
  float fStack_380;
  float fStack_37c;
  float fStack_378;
  float fStack_374;
  float fStack_370;
  float fStack_36c;
  float fStack_368;
  float fStack_364;
  float fStack_360;
  float fStack_35c;
  float fStack_358;
  float fStack_354;
  float fStack_350;
  float fStack_328;
  float fStack_324;
  float fStack_320;
  float fStack_31c;
  float fStack_318;
  float fStack_314;
  float fStack_2ec;
  float fStack_2e8;
  float fStack_2e4;
  float fStack_2e0;
  float fStack_2dc;
  float fStack_2d8;
  float fStack_2b0;
  float fStack_2ac;
  float fStack_2a8;
  float fStack_2a4;
  float fStack_2a0;
  float fStack_29c;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  undefined4 uStack_268;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  float fStack_244;
  float fStack_238;
  float fStack_22c;
  float fStack_220;
  undefined4 uStack_219;
  undefined1 auStack_214 [255];
  undefined4 uStack_115;
  undefined1 auStack_110 [260];
  int *piStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a75bb;
  piStack_c = ExceptionList;
  local_430 = (float *)0x0;
  local_42c = 0;
  local_428 = 0;
  local_410 = 0;
  local_40c = 0;
  local_408 = 0;
  local_4 = 1;
  local_48c = 0.0;
  local_488 = g_flOne;
  local_484 = 0.0;
  ExceptionList = &piStack_c;
  FUN_0076f5f0();
  fVar15 = (float10)(**(code **)(*param_1 + 200))();
  pfStack_530 = (float *)(float)fVar15;
  if ((*(int *)param_1[5] != 0) &&
     (iVar3 = (**(code **)(**(int **)param_1[5] + 0x24))(), iVar3 != 0)) {
    piVar4 = (int *)(**(code **)(**(int **)param_1[5] + 0x24))();
    fVar15 = (float10)(**(code **)(*piVar4 + 200))();
    pfStack_530 = (float *)(float)fVar15;
  }
  iStack_520 = CONCAT22(iStack_520._2_2_,in_FPUControlWord);
  pfVar5 = param_2 + 2;
  pfVar12 = param_2 + 4;
  puStack_4e0 = &stack0xfffffa98;
  fStack_500 = SQRT((param_2[3] - param_2[5]) * (param_2[3] - param_2[5]) +
                    (*pfVar5 - *pfVar12) * (*pfVar5 - *pfVar12));
  fStack_534 = (float)(int)ROUND((fStack_500 - DAT_00aaa664) * _DAT_009dca08);
  fStack_524 = (float)(1 - (int)fStack_534);
  ppvStack_56c = (void **)((int)fStack_524 * 2 + 2);
  fStack_4a0 = g_flOne / (float)(int)fStack_524;
  pfStack_570 = (float *)0x5e2f57;
  FUN_005c53b0();
  fStack_534 = param_2[3];
  fStack_4ec = *pfVar5;
  fVar15 = (float10)FUN_004cd220();
  fStack_4e8 = (float)(fVar15 + (float10)(float)pfStack_530);
  fStack_440 = (float)(fVar15 + (float10)(float)pfStack_530);
  if (param_7 == (float *)0x0) {
    fStack_518 = *pfVar12 - *param_2;
    fStack_510 = param_2[5] - param_2[1];
    fStack_514 = 0.0;
    ppvStack_56c = (void **)0x5e2fee;
    FUN_0076e240();
  }
  else {
    fStack_54c = *param_7;
    fStack_548 = param_7[1];
    pvStack_544 = (void *)param_7[2];
  }
  FUN_0076f5f0();
  fVar16 = (float)param_1[0x59] * DAT_00a0f298;
  fStack_54c = fVar16 * fStack_54c;
  pvStack_544 = (void *)(fVar16 * (float)pvStack_544);
  fStack_548 = fVar16 * fStack_548;
  *local_430 = fStack_4ec + fStack_54c;
  local_430[1] = fStack_548 + fStack_4e8;
  local_430[2] = fStack_534 + (float)pvStack_544;
  fStack_4d8 = fStack_534 - (float)pvStack_544;
  local_430[3] = fStack_4ec - fStack_54c;
  local_430[4] = fStack_4e8 - fStack_548;
  local_430[5] = fStack_4d8;
  fStack_490 = param_2[3];
  fStack_494 = *pfVar5;
  puStack_540 = (undefined1 *)(0.0 - fStack_54c);
  fStack_53c = 0.0 - (float)pvStack_544;
  pfStack_4c4 = (float *)param_2[5];
  fStack_4ec = *pfVar12;
  fStack_50c = (float)puStack_540;
  fStack_508 = fStack_53c;
  puStack_4e0 = (undefined1 *)fStack_54c;
  pvStack_4dc = pvStack_544;
  fVar15 = (float10)FUN_004cd220();
  fStack_534 = (float)fVar15;
  fVar15 = (float10)(**(code **)(*param_1 + 200))();
  fStack_4e8 = (float)(fVar15 + (float10)fStack_534);
  if (param_8 == (float *)0x0) {
    fStack_518 = param_2[6] - *pfVar5;
    fStack_510 = param_2[7] - param_2[3];
    fStack_514 = 0.0;
    ppvStack_56c = (void **)0x5e31ea;
    FUN_0076e240();
  }
  else {
    fStack_54c = *param_8;
    fStack_548 = param_8[1];
    pvStack_544 = (void *)param_8[2];
  }
  FUN_0076f5f0();
  fVar16 = (float)param_1[0x59] * DAT_00a0f298;
  fStack_54c = fVar16 * fStack_54c;
  pvStack_544 = (void *)(fVar16 * (float)pvStack_544);
  fStack_548 = fVar16 * fStack_548;
  pfVar13 = local_430 + (int)fStack_524 * 6;
  *pfVar13 = fStack_4ec + fStack_54c;
  pfVar13[1] = fStack_548 + fStack_4e8;
  pfVar13[2] = (float)pfStack_4c4 + (float)pvStack_544;
  fStack_504 = (float)pfStack_4c4 - (float)pvStack_544;
  pfVar13[3] = fStack_4ec - fStack_54c;
  pfVar13[4] = fStack_4e8 - fStack_548;
  pfVar13[5] = fStack_504;
  fStack_424 = *pfVar12;
  fStack_420 = param_2[5];
  fStack_508 = 0.0 - (float)pvStack_544;
  fStack_50c = 0.0 - fStack_54c;
  fStack_51c = 1.4013e-45;
  fStack_450 = fStack_50c;
  fStack_44c = fStack_508;
  fStack_43c = fStack_54c;
  pvStack_438 = pvStack_544;
  if (1 < (int)fStack_524) {
    fStack_534 = g_flOne / fStack_500;
    pfStack_4c8 = local_430 + 6;
    pfStack_4c4 = (float *)0x0;
    do {
      pfStack_530 = (float *)((float)(int)fStack_51c * DAT_00aaa6c4 * fStack_534);
      pfStack_4d4 = (float *)((float)pfStack_530 + fStack_4a0);
      if (g_flOne <= (float)pfStack_530 + fStack_4a0) {
        pfStack_4d4 = (float *)g_flOne;
        pfStack_530 = pfStack_4c4;
      }
      pfStack_570 = param_2;
      pfStack_574 = &fStack_36c;
      pfStack_578 = (float *)0x5e33f3;
      ppvStack_56c = (void **)pfVar5;
      pfStack_4c4 = pfStack_4d4;
      D3DXVec2CatmullRom();
      pfStack_578 = (float *)fStack_4ec;
      pfStack_57c = param_2 + 6;
      pfStack_588 = param_2;
      pfStack_58c = &fStack_38c;
      uStack_590 = 0x5e340f;
      pfStack_584 = pfVar5;
      pfStack_580 = pfVar12;
      D3DXVec2CatmullRom();
      fStack_54c = fStack_374 - fStack_36c;
      fStack_4ec = fStack_36c;
      pvStack_544 = (void *)(fStack_370 - fStack_368);
      fStack_4e4 = fStack_368;
      fStack_548 = 0.0;
      FUN_0076f5f0();
      ppvStack_56c = (void **)&fStack_54c;
      pfStack_570 = &fStack_54c;
      pfStack_574 = (float *)0x5e3483;
      FUN_0076e240();
      pfStack_578 = &fStack_54c;
      pfStack_57c = (float *)0x5e3490;
      pfStack_574 = pfStack_578;
      FUN_0076f5f0();
      fVar16 = (float)param_1[0x59] * DAT_00a0f298;
      fStack_54c = fVar16 * fStack_54c;
      fStack_548 = fVar16 * fStack_548;
      pvStack_544 = (void *)(fVar16 * (float)pvStack_544);
      fStack_514 = 0.0 - fStack_548;
      fStack_510 = 0.0 - (float)pvStack_544;
      fStack_518 = 0.0 - fStack_54c;
      fStack_4fc = fStack_4ec;
      fStack_4c0 = fStack_4ec + fStack_54c;
      fStack_4f8 = fStack_4e4;
      fStack_4f4 = fStack_494;
      fStack_52c = fStack_494 + (float)puStack_4e0;
      pvStack_4bc = (void *)(fStack_4e4 + (float)pvStack_544);
      fStack_4f0 = fStack_490;
      pvStack_528 = (void *)(fStack_490 + (float)pvStack_4dc);
      pfStack_57c = &fStack_52c;
      pfStack_580 = &fStack_4f4;
      pfStack_584 = &fStack_4c0;
      pfStack_588 = &fStack_4fc;
      pfStack_58c = (float *)0x0;
      uStack_590 = 0x5e35d6;
      fStack_50c = fStack_52c;
      fStack_508 = (float)pvStack_528;
      fStack_474 = fStack_518;
      fStack_470 = fStack_514;
      fStack_46c = fStack_510;
      cVar2 = FUN_00788280();
      if (cVar2 != '\0') {
        pvStack_544 = (void *)((float)pvStack_528 - fStack_4f8);
        fStack_54c = fStack_52c - fStack_4fc;
      }
      fStack_4c0 = fStack_518 + fStack_4fc;
      pvStack_4bc = (void *)(fStack_510 + fStack_4f8);
      fStack_52c = fStack_4f4 + (float)puStack_540;
      pvStack_528 = (void *)(fStack_4f0 + fStack_53c);
      ppvStack_56c = (void **)&fStack_4fc;
      pfStack_570 = (float *)0x0;
      pfStack_574 = (float *)0x5e3693;
      fStack_458 = fStack_52c;
      fStack_454 = (float)pvStack_528;
      cVar2 = FUN_00788280();
      if (cVar2 != '\0') {
        fStack_510 = (float)pvStack_528 - fStack_4f8;
        fStack_518 = fStack_52c - fStack_4fc;
      }
      fStack_4f8 = fStack_4e4;
      pvStack_4bc = (void *)(fStack_4e4 + (float)pvStack_544);
      fStack_4fc = fStack_4ec;
      fStack_4c0 = fStack_4ec + fStack_54c;
      fStack_4f4 = fStack_424;
      fStack_52c = fStack_424 + fStack_43c;
      fStack_4f0 = fStack_420;
      pvStack_528 = (void *)(fStack_420 + (float)pvStack_438);
      ppvStack_56c = (void **)&fStack_4fc;
      pfStack_570 = (float *)0x0;
      pfStack_574 = (float *)0x5e376e;
      fStack_448 = fStack_52c;
      fStack_444 = (float)pvStack_528;
      cVar2 = FUN_00788280();
      if (cVar2 != '\0') {
        pvStack_544 = (void *)((float)pvStack_528 - fStack_4f8);
        fStack_54c = fStack_52c - fStack_4fc;
      }
      fStack_4c0 = fStack_518 + fStack_4fc;
      pvStack_4bc = (void *)(fStack_510 + fStack_4f8);
      fStack_52c = fStack_450 + fStack_4f4;
      pvStack_528 = (void *)(fStack_44c + fStack_4f0);
      ppvStack_56c = (void **)&fStack_4fc;
      pfStack_570 = (float *)0x0;
      pfStack_574 = (float *)0x5e382b;
      fStack_41c = fStack_52c;
      pvStack_418 = pvStack_528;
      cVar2 = FUN_00788280();
      puStack_540 = (undefined1 *)fStack_518;
      fStack_53c = fStack_510;
      if (cVar2 != '\0') {
        puStack_540 = (undefined1 *)(fStack_52c - fStack_4fc);
        fStack_53c = (float)pvStack_528 - fStack_4f8;
      }
      fStack_460 = fStack_548;
      fStack_494 = fStack_4ec;
      fStack_490 = fStack_4e4;
      fStack_464 = fStack_4ec + fStack_54c;
      fStack_45c = fStack_4e4 + (float)pvStack_544;
      *pfStack_4c8 = fStack_464;
      fStack_47c = fStack_514;
      pfStack_4c8[1] = fStack_548;
      pfStack_4c8[2] = fStack_45c;
      fStack_480 = (float)puStack_540 + fStack_4ec;
      pfStack_4c8[3] = fStack_480;
      pfStack_4c8[4] = fStack_514;
      fStack_478 = fStack_53c + fStack_4e4;
      pfStack_4c8[5] = fStack_478;
      puStack_4e0 = (undefined1 *)fStack_54c;
      fStack_51c = (float)((int)fStack_51c + 1);
      pfStack_4c8 = pfStack_4c8 + 6;
      pvStack_4dc = pvStack_544;
    } while ((int)fStack_51c < (int)fStack_524);
  }
  fStack_51c = 0.0;
  uStack_270 = 0;
  uStack_26c = 0;
  uStack_268 = 0;
  uStack_250 = 0;
  uStack_24c = 0;
  uStack_248 = 0;
  uStack_260 = 0;
  uStack_25c = 0;
  uStack_258 = 0;
  local_4 = CONCAT31(local_4._1_3_,4);
  if (*(int *)param_1[5] != 0) {
    fVar15 = (float10)(**(code **)(**(int **)param_1[5] + 0x9c))();
    fStack_51c = (float)fVar15;
  }
  fVar16 = fStack_524;
  iStack_520 = (int)((float)param_1[0x59] * g_flMultiKillCountBlend);
  if (iStack_520 < 3) {
    iStack_520 = 2;
  }
  fStack_524 = (float)(iStack_520 * (int)fStack_524 * 6);
  puStack_4e0 = (undefined1 *)((int)fStack_524 / 3);
  puStack_540 = auStack_598;
  FUN_005e53b0(fStack_524);
  pfStack_4c8 = (float *)fStack_440;
  if (0 < (int)fVar16) {
    puStack_540 = (undefined1 *)(iStack_520 * 0x168);
    pfStack_530 = (float *)(local_410 + 0x48);
    fStack_398 = (fStack_4e8 - fStack_440) / fStack_500;
    pfStack_4d4 = local_430 + 4;
    fStack_534 = fVar16;
    fVar16 = local_488;
    fStack_3e0 = 0.0;
    do {
      fStack_480 = pfStack_4d4[-4] + pfStack_4d4[-1];
      fStack_47c = pfStack_4d4[-3] + *pfStack_4d4;
      fStack_478 = pfStack_4d4[-2] + pfStack_4d4[1];
      fStack_460 = pfStack_4d4[3] + pfStack_4d4[6];
      fStack_464 = pfStack_4d4[5] + pfStack_4d4[2];
      fStack_45c = pfStack_4d4[7] + pfStack_4d4[4];
      fStack_4a0 = fStack_480 * DAT_00a0f298 - fStack_464 * DAT_00a0f298;
      pfStack_4c4 = (float *)(fStack_478 * DAT_00a0f298 - fStack_45c * DAT_00a0f298);
      fStack_364 = pfStack_4d4[-4];
      fStack_360 = pfStack_4d4[-3];
      fStack_35c = pfStack_4d4[-2];
      fStack_328 = pfStack_4d4[2];
      fVar17 = SQRT((float)pfStack_4c4 * (float)pfStack_4c4 + fStack_4a0 * fStack_4a0);
      fStack_324 = pfStack_4d4[3];
      fStack_50c = fVar17 * g_flMultiKillCountBlend + fStack_51c;
      fStack_3e0 = fVar17 + fStack_3e0;
      fStack_500 = fStack_398 * fStack_3e0 + fStack_440;
      fStack_320 = pfStack_4d4[4];
      fStack_2ec = pfStack_4d4[-1];
      fStack_2e8 = *pfStack_4d4;
      fStack_2ac = pfStack_4d4[6];
      fStack_2e4 = pfStack_4d4[1];
      fStack_2b0 = pfStack_4d4[5];
      fStack_2a8 = pfStack_4d4[7];
      fStack_350 = local_484;
      fStack_314 = local_484;
      fStack_2d8 = local_484;
      fStack_29c = local_484;
      fStack_468 = 0.0;
      fStack_358 = local_48c;
      fStack_31c = local_48c;
      fStack_2e0 = local_48c;
      fStack_2a4 = local_48c;
      fStack_494 = fStack_50c;
      fStack_38c = fStack_480;
      fStack_388 = fStack_47c;
      fStack_384 = fStack_478;
      fStack_380 = fStack_464;
      fStack_37c = fStack_460;
      fStack_378 = fStack_45c;
      fStack_354 = fVar16;
      fStack_318 = fVar16;
      fStack_2dc = fVar16;
      fStack_2a0 = fVar16;
      if (0 < iStack_520) {
        fStack_404 = fStack_2a8 - fStack_320;
        fStack_3f4 = fStack_2ec - fStack_364;
        fStack_3cc = fStack_2b0 - fStack_328;
        fStack_390 = (float)iStack_520;
        fStack_3dc = local_484 - local_484;
        fStack_3bc = fVar16 - fVar16;
        fStack_394 = local_48c - local_48c;
        fStack_43c = local_484 - local_484;
        fStack_450 = fVar16 - fVar16;
        fStack_448 = local_48c - local_48c;
        fStack_3e4 = fStack_2e4 - fStack_35c;
        fStack_458 = fStack_50c - fStack_50c;
        pfVar5 = pfStack_530;
        fStack_424 = fStack_450;
        fStack_41c = fStack_43c;
        fStack_3ac = fStack_3dc;
        fStack_3a8 = fStack_3e4;
        fStack_3a4 = fStack_3bc;
        fStack_39c = fStack_404;
        fStack_244 = fStack_448;
        fStack_238 = fStack_3cc;
        fStack_22c = fStack_394;
        fStack_220 = fStack_3f4;
        do {
          fVar17 = (float)(int)fStack_468 / fStack_390;
          fStack_468 = (float)((int)fStack_468 + 1);
          fVar18 = (float)(int)fStack_468 / fStack_390;
          fStack_474 = fVar17 * fStack_3f4 + fStack_364;
          fStack_46c = fStack_35c + fVar17 * fStack_3a8;
          fVar19 = fVar17 * g_flZero;
          fStack_470 = (float)pfStack_4c8 + fVar19;
          pfVar5[-0x12] = fStack_474;
          pfVar5[-0x11] = fStack_470;
          pfVar5[-0x10] = fStack_46c;
          fStack_518 = fVar18 * fStack_220 + fStack_364;
          fStack_510 = fStack_35c + fVar18 * fStack_3e4;
          fStack_3a0 = fVar18 * g_flZero;
          fStack_514 = (float)pfStack_4c8 + fStack_3a0;
          pfVar5[0xc] = fStack_518;
          pfVar5[0xd] = fStack_514;
          pfVar5[0xe] = fStack_510;
          fStack_4e4 = fStack_320 + fVar17 * fStack_39c;
          fStack_4ec = fStack_328 + fVar17 * fStack_3cc;
          fStack_4e8 = fStack_500 + fVar19;
          pfVar5[-3] = fStack_4ec;
          pfVar5[-2] = fStack_4e8;
          fStack_3d0 = fStack_320 + fVar18 * fStack_404;
          pfVar5[-1] = fStack_4e4;
          fStack_3d4 = fStack_500 + fStack_3a0;
          fStack_3d8 = fStack_328 + fVar18 * fStack_238;
          pfVar5[0x2a] = fStack_3d8;
          pfVar5[0x2b] = fStack_3d4;
          pfVar5[0x2c] = fStack_3d0;
          fStack_3c8 = fVar17 * fStack_394 + fStack_358;
          fStack_3c0 = fStack_350 + fVar17 * fStack_3dc;
          fStack_3c4 = fStack_354 + fVar17 * fStack_3a4;
          pfVar5[-0xf] = fStack_3c8;
          pfVar5[-0xe] = fStack_3c4;
          pfVar5[-0xd] = fStack_3c0;
          fStack_3b0 = fStack_350 + fVar18 * fStack_3ac;
          fStack_3b4 = fStack_354 + fVar18 * fStack_3bc;
          fStack_3b8 = fVar18 * fStack_22c + fStack_358;
          pfVar5[0xf] = fStack_3b8;
          pfVar5[0x10] = fStack_3b4;
          fStack_3f8 = fStack_314 + fVar17 * fStack_41c;
          fStack_3fc = fStack_318 + fVar17 * fStack_450;
          pfVar5[0x11] = fStack_3b0;
          fStack_400 = fStack_31c + fVar17 * fStack_448;
          *pfVar5 = fStack_400;
          pfVar5[1] = fStack_3fc;
          pfVar5[2] = fStack_3f8;
          fStack_3e8 = fStack_314 + fVar18 * fStack_43c;
          fStack_3ec = fStack_318 + fVar18 * fStack_424;
          fStack_3f0 = fStack_31c + fVar18 * fStack_244;
          pfVar5[0x2d] = fStack_3f0;
          pfVar5[0x2e] = fStack_3ec;
          pfVar5[0x2f] = fStack_3e8;
          fVar16 = g_flOne;
          pfVar5[-0xb] = fStack_51c + fVar19;
          pfVar5[-10] = 0.0;
          pfVar5[0x13] = fStack_51c + fStack_3a0;
          pfVar5[0x14] = fVar16;
          pfVar5[4] = fStack_458 * fVar17 + fStack_50c;
          pfVar5[5] = 0.0;
          pfVar5[0x31] = fStack_458 * fVar18 + fStack_50c;
          pfVar5[0x32] = fVar16;
          fVar16 = (float)(**(code **)(*param_1 + 0xd8))();
          pfVar5[-0xc] = fVar16;
          fVar16 = (float)(**(code **)(*param_1 + 0xd8))();
          pfVar5[0x12] = fVar16;
          ppvStack_56c = (void **)0x5e439d;
          fVar16 = (float)(**(code **)(*param_1 + 0xd8))();
          pfVar5[3] = fVar16;
          pfStack_570 = (float *)0x5e43ab;
          ppvStack_56c = (void **)(pfVar5 + 0x2a);
          fVar16 = (float)(**(code **)(*param_1 + 0xd8))();
          pfVar5[0x30] = fVar16;
          pfVar12 = pfVar5 + -3;
          pfVar13 = pfVar5 + 0x1b;
          for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
            *pfVar13 = *pfVar12;
            pfVar12 = pfVar12 + 1;
            pfVar13 = pfVar13 + 1;
          }
          pfVar13 = pfVar5 + 0x39;
          pfVar12 = pfVar5 + 0xc;
          pfVar5 = pfVar5 + 0x5a;
          for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
            *pfVar13 = *pfVar12;
            pfVar12 = pfVar12 + 1;
            pfVar13 = pfVar13 + 1;
          }
          fVar16 = local_488;
          fVar17 = fStack_468;
        } while ((int)fStack_468 < iStack_520);
      }
      fStack_468 = fVar17;
      fVar15 = (float10)_CIfmod();
      pfStack_530 = (float *)((int)pfStack_530 + (int)puStack_540);
      pfStack_4c8 = (float *)fStack_500;
      fStack_51c = (float)fVar15;
      pfStack_4d4 = pfStack_4d4 + 6;
      param_1[0x5a] = (int)(float)fVar15;
      fStack_534 = (float)((int)fStack_534 + -1);
    } while (fStack_534 != 0.0);
  }
  iVar3 = 0;
  if (3 < (int)fStack_524) {
    pfVar5 = (float *)(local_410 + 0x44);
    iVar10 = ((int)fStack_524 - 4U >> 2) + 1;
    iVar3 = iVar10 * 4;
    do {
      pfVar5[-0x11] = pfVar5[-0x11] - param_4;
      pfVar5[-0x10] = pfVar5[-0x10] - param_5;
      pfVar5[-0xf] = pfVar5[-0xf] - param_6;
      pfVar5[-2] = pfVar5[-2] - param_4;
      pfVar5[-1] = pfVar5[-1] - param_5;
      *pfVar5 = *pfVar5 - param_6;
      pfVar5[0xd] = pfVar5[0xd] - param_4;
      pfVar5[0xe] = pfVar5[0xe] - param_5;
      pfVar5[0xf] = pfVar5[0xf] - param_6;
      puStack_540 = (undefined1 *)(pfVar5[0x1c] - param_4);
      pfVar5[0x1c] = (float)puStack_540;
      fStack_53c = pfVar5[0x1d] - param_5;
      pfVar5[0x1d] = fStack_53c;
      fStack_538 = pfVar5[0x1e] - param_6;
      pfVar5[0x1e] = fStack_538;
      pfVar5 = pfVar5 + 0x3c;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  if (iVar3 < (int)fStack_524) {
    iVar10 = (int)fStack_524 - iVar3;
    pfVar5 = (float *)(local_410 + iVar3 * 0x3c);
    do {
      puStack_540 = (undefined1 *)(*pfVar5 - param_4);
      *pfVar5 = (float)puStack_540;
      fStack_53c = pfVar5[1] - param_5;
      fStack_538 = pfVar5[2] - param_6;
      pfVar5[1] = fStack_53c;
      iVar10 = iVar10 + -1;
      pfVar5[2] = fStack_538;
      pfVar5 = pfVar5 + 0xf;
    } while (iVar10 != 0);
  }
  if ((undefined4 *)*param_3 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*param_3)();
    *param_3 = 0;
  }
  puStack_540 = operator_new(0x14c);
  local_4._0_1_ = 5;
  if (puStack_540 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00764030();
  }
  local_4._0_1_ = 4;
  *param_3 = iVar3;
  FUN_007638d0();
  puStack_540 = operator_new(0xc4);
  local_4._0_1_ = 6;
  if (puStack_540 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_00748960();
  }
  local_4 = CONCAT31(local_4._1_3_,4);
  iVar3 = (**(code **)(*(int *)*param_3 + 0xc))();
  piVar4[0x19] = iVar3;
  iVar3 = *piVar4;
  (**(code **)(*(int *)*param_3 + 100))();
  (**(code **)(iVar3 + 0x34))();
  piVar6 = param_1 + 0xc;
  ppvStack_56c = (void **)0x5e46a5;
  strstr((char *)piVar6,"goo");
  ppvStack_56c = (void **)0x5e46cc;
  FUN_00989e00();
  FUN_009701d0();
  iVar3 = 1 - (int)piVar6;
  do {
    iVar10 = *piVar6;
    *(char *)((int)&uStack_115 + iVar3 + (int)piVar6) = (char)iVar10;
    piVar6 = (int *)((int)piVar6 + 1);
  } while ((char)iVar10 != '\0');
  puVar7 = &uStack_115;
  do {
    puVar14 = puVar7;
    puVar7 = (undefined4 *)((int)puVar14 + 1);
  } while (*(char *)((int)puVar14 + 1) != '\0');
  *(undefined4 *)((int)puVar14 + 1) = DAT_00a2c53c;
  *(undefined1 *)((int)puVar14 + 5) = DAT_00a2c540;
  param_1 = param_1 + 0xc;
  iVar3 = 1 - (int)param_1;
  do {
    iVar10 = *param_1;
    *(char *)((int)&uStack_219 + iVar3 + (int)param_1) = (char)iVar10;
    param_1 = (int *)((int)param_1 + 1);
  } while ((char)iVar10 != '\0');
  puVar7 = &uStack_219;
  do {
    puVar14 = puVar7;
    puVar7 = (undefined4 *)((int)puVar14 + 1);
  } while (*(char *)((int)puVar14 + 1) != '\0');
  *(undefined4 *)((int)puVar14 + 1) = DAT_009d4800;
  *(undefined2 *)((int)puVar14 + 5) = DAT_009d4804;
  puVar7 = &uStack_219;
  do {
    puVar14 = puVar7;
    puVar7 = (undefined4 *)((int)puVar14 + 1);
  } while (*(char *)((int)puVar14 + 1) != '\0');
  *(undefined4 *)((int)puVar14 + 1) = DAT_00a2c53c;
  *(undefined1 *)((int)puVar14 + 5) = DAT_00a2c540;
  FUN_0096ef70();
  puStack_8._0_1_ = 7;
  ppvStack_56c = (void **)0x5e47a6;
  FUN_00989e00();
  ppvStack_56c = (void **)0x5e47b8;
  FUN_0096f3e0();
  ppvStack_56c = (void **)0x5e47cf;
  FUN_00970140();
  FUN_0096ef70();
  puStack_8._0_1_ = 8;
  ppvStack_56c = (void **)0x5e47fa;
  FUN_00989e00();
  ppvStack_56c = (void **)0x5e480c;
  FUN_0096f3e0();
  ppvStack_56c = (void **)0x5e4820;
  FUN_00970140();
  FUN_00491e30();
  ppvStack_56c = (void **)0x5e483f;
  FUN_00970140();
  FUN_005b3400();
  ppvStack_56c = (void **)0x5e4863;
  FUN_00970140();
  ppvStack_56c = (void **)0x5e4876;
  FUN_009700f0();
  ppvStack_56c = (void **)0x5e4883;
  FUN_009700f0();
  uStack_4b8 = 0;
  uStack_4b4 = 0;
  uStack_4b0 = 0;
  puStack_8._0_1_ = 9;
  uStack_4ac = 0;
  uStack_4a8 = 0;
  FUN_007478c0();
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,10);
  fStack_4a0 = 0.0;
  uStack_49c = 2;
  uStack_49b = 0;
  uStack_49a = 6;
  uStack_499 = 0;
  FUN_007471c0();
  uStack_499 = 1;
  FUN_007471c0();
  piVar4[0x2f] = piVar4[0x2f] | 1;
  ppvStack_56c = &pvStack_4bc;
  pfStack_570 = pvStack_528;
  pfStack_574 = (float *)0x5e4948;
  iVar3 = FUN_00414c20();
  if (iVar3 < 0) {
    if ((undefined4 *)*param_2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*param_2)();
    }
    *param_2 = 0.0;
    (**(code **)*piVar4)();
    uStack_4b0 = 0;
    uStack_4ac = 0;
    if (pvStack_4bc != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ppvStack_56c = (void **)&UNK_005e498d;
      operator_delete(pvStack_4bc);
    }
    pvStack_4bc = (void *)0x0;
    uStack_4b8 = 0;
    uStack_4b4 = 0;
    piStack_c._0_1_ = 7;
    FUN_0096efd0();
    piStack_c = (int *)CONCAT31(piStack_c._1_3_,4);
    FUN_0096efd0();
    if (pvStack_418 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ppvStack_56c = (void **)&UNK_005e49e2;
      operator_delete(pvStack_418);
    }
  }
  else {
    if (*(int *)(piVar4[5] + 0x10) != 0) {
      ppvStack_56c = *(void ***)(piVar4[5] + 0x14);
      pfStack_570 = (void *)0x5e4a0a;
      puVar7 = (undefined4 *)FUN_00746520();
      if (puVar7 != (undefined4 *)0x0) {
        for (uVar11 = (uint)((int)pvStack_528 * 0x3c) >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
          *puVar7 = *puStack_414;
          puStack_414 = puStack_414 + 1;
          puVar7 = puVar7 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puStack_414;
          puStack_414 = (undefined4 *)((int)puStack_414 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        if (*(int *)(piVar4[5] + 0x10) != 0) {
          FUN_007464e0();
        }
        pvVar1 = pvStack_528;
        ppvStack_56c = (void **)0x20;
        pfStack_570 = pvStack_528;
        pfStack_574 = (float *)0x5e4b09;
        FUN_0044b9c0();
        iVar3 = piVar4[3];
        if (*(int *)(iVar3 + 0x10) != 0) {
          pfStack_578 = *(float **)(iVar3 + 0x1c);
          pfStack_57c = *(float **)(iVar3 + 0x18);
          pfStack_574 = (float *)0x800;
          pfStack_580 = (float *)0x5e4b25;
          puVar8 = (ushort *)FUN_00743be0();
          if (puVar8 != (ushort *)0x0) {
            uVar9 = 0;
            if ((ushort)pvVar1 != 0) {
              do {
                *puVar8 = uVar9;
                uVar9 = uVar9 + 1;
                puVar8 = puVar8 + 1;
              } while (uVar9 < (ushort)pvVar1);
            }
            if (*(int *)(piVar4[3] + 0x10) != 0) {
              pfStack_574 = (float *)0x5e4c0f;
              FUN_00743ba0();
            }
            if (piVar4[5] != 0) {
              pfStack_578 = (float *)auStack_4cc;
              pfStack_57c = (float *)0x5e4c26;
              pfStack_574 = (float *)(piVar4 + 2);
              FUN_009999d0();
            }
            piVar4[0x2a] = (int)fStack_4f4;
            piVar4[0x2b] = 4;
            pfStack_574 = (float *)0x5e4c42;
            FUN_0096f740();
            piVar6 = piStack_c;
            pfStack_578 = (float *)0x5e4c51;
            pfStack_574 = (float *)piVar4;
            FUN_007647c0();
            pfStack_574 = (float *)0x5e4c58;
            (**(code **)(*(int *)*piVar6 + 0x50))();
            pfStack_574 = (float *)0x3;
            pfStack_578 = (float *)0x5e4c61;
            iVar3 = (**(code **)(*(int *)*piVar6 + 0x10))();
            *(undefined4 *)(iVar3 + 0xbc) = 0xffffffff;
            *(int *)(iVar3 + 0xb4) = *(int *)(iVar3 + 0xb4) + 1;
            *(float **)(iVar3 + 0x90) = param_2;
            *(int **)(iVar3 + 0x94) = param_3;
            *(float *)(iVar3 + 0x98) = param_4;
            uStack_4b0 = 0;
            uStack_4ac = 0;
            if (pvStack_4bc != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
              ppvStack_56c = (void **)&UNK_005e4cb5;
              operator_delete(pvStack_4bc);
            }
            pvStack_4bc = (void *)0x0;
            uStack_4b8 = 0;
            uStack_4b4 = 0;
            piStack_c._0_1_ = 7;
            FUN_0096efd0();
            piStack_c = (int *)CONCAT31(piStack_c._1_3_,4);
            FUN_0096efd0();
            if (pvStack_418 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
              ppvStack_56c = (void **)&UNK_005e4d06;
              operator_delete(pvStack_418);
            }
            goto LAB_005e4d11;
          }
        }
        pfStack_574 = (float *)0xa15844;
        pfStack_578 = (float *)0x0;
        pfStack_57c = (float *)0x5e4b39;
        FUN_007a4480();
        if (*(int *)(piVar4[3] + 0x10) != 0) {
          pfStack_574 = (float *)0x5e4b4d;
          FUN_00743ba0();
        }
        piVar6 = piStack_c;
        if ((undefined4 *)*piStack_c != (undefined4 *)0x0) {
          pfStack_574 = (float *)0x1;
          pfStack_578 = (float *)0x5e4b60;
          (*(code *)**(undefined4 **)*piStack_c)();
        }
        *piVar6 = 0;
        pfStack_574 = (float *)0x1;
        pfStack_578 = (float *)0x5e4b6b;
        (**(code **)*piVar4)();
        uStack_4b0 = 0;
        uStack_4ac = 0;
        if (pvStack_4bc != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
          ppvStack_56c = (void **)&UNK_005e4b8a;
          operator_delete(pvStack_4bc);
        }
        pvStack_4bc = (void *)0x0;
        uStack_4b8 = 0;
        uStack_4b4 = 0;
        piStack_c._0_1_ = 7;
        FUN_0096efd0();
        piStack_c = (int *)CONCAT31(piStack_c._1_3_,4);
        FUN_0096efd0();
        if (pvStack_418 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
          ppvStack_56c = (void **)&UNK_005e4bdb;
          operator_delete(pvStack_418);
        }
        goto LAB_005e4d11;
      }
    }
    if (*(int *)(piVar4[5] + 0x10) != 0) {
      FUN_007464e0();
    }
    if ((undefined4 *)*param_2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*param_2)();
    }
    *param_2 = 0.0;
    (**(code **)*piVar4)();
    uStack_4b0 = 0;
    uStack_4ac = 0;
    if (pvStack_4bc != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ppvStack_56c = (void **)&UNK_005e4a5e;
      operator_delete(pvStack_4bc);
    }
    pvStack_4bc = (void *)0x0;
    uStack_4b8 = 0;
    uStack_4b4 = 0;
    piStack_c._0_1_ = 7;
    FUN_0096efd0();
    piStack_c = (int *)CONCAT31(piStack_c._1_3_,4);
    FUN_0096efd0();
    if (pvStack_418 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      ppvStack_56c = (void **)&UNK_005e4aaf;
      operator_delete(pvStack_418);
    }
  }
LAB_005e4d11:
                    /* WARNING: Subroutine does not return */
  ppvStack_56c = (void **)&UNK_005e4d16;
  operator_delete(pvStack_438);
}
```
