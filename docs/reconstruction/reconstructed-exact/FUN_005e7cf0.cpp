// =============================================================================
// FUN_005e7cf0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e7cf0
// Address:   0x005e7cf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e7cf0 @ 0x005e7cf0
// Stable ID: aa_005e7cf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~895 non-empty decompiler lines.
//  - Control keywords: if×46, return×16, while×10, do×8, for×2.
//  - Notable callees: FUN_004b0b40×8, FUN_0096efd0×6, CONCAT31×5, FUN_004cd220×5, FUN_0076f5f0×5, FUN_004b08b0×4, FUN_00788280×4, FUN_0076e240×3.
//  - Return sites: 16.

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



void __thiscall

FUN_005e7cf0(void *param_1,float **param_2,int *param_3,float param_4,float param_5,float param_6,

            float *param_7,float *param_8)



{

  float *pfVar1;

  uint8_t *puVar2;

  uint8_t *puVar3;

  char cVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ *puVar9;

  ushort *puVar10;

  ushort uVar11;

  uint uVar12;

  float *pfVar13;

  void *pvVar14;

  float *pfVar15;

  char *pcVar16;

  uint32_t /* width from decompiler */ *puVar17;

  float10 fVar18;

  float fVar19;

  int *unaff_retaddr;

  uint8_t auStack_3d0 [4];

  uint32_t /* width from decompiler */ uStack_3cc;

  void ***pppvStack_3c8;

  float **ppfStack_3c4;

  void **ppvStack_3c0;

  void ***pppvStack_3bc;

  float **ppfStack_3ac;

  float **ppfStack_3a4;

  void ***pppvStack_3a0;

  float local_388;

  void **local_384;

  void *local_380;

  float local_37c;

  uint8_t *local_378;

  uint8_t *local_374;

  uint8_t *local_370;

  void *local_36c;

  void **ppvStack_368;

  void *pvStack_364;

  void **local_360;

  float fStack_35c;

  void *pvStack_358;

  void *pvStack_354;

  float fStack_350;

  float local_34c;

  void *local_348;

  float local_344;

  void **local_340;

  float local_33c;

  void *local_338;

  float *local_334;

  uint32_t /* width from decompiler */ local_330;

  void *local_32c;

  void *local_328;

  uint32_t /* width from decompiler */ local_324;

  uint32_t /* width from decompiler */ uStack_320;

  void *pvStack_31c;

  void *pvStack_318;

  uint32_t /* width from decompiler */ uStack_314;

  void *local_310;

  void *local_30c;

  float local_308;

  uint32_t /* width from decompiler */ local_304;

  void **ppvStack_300;

  void *pvStack_2fc;

  void **ppvStack_2f8;

  void **ppvStack_2f4;

  void *local_2e8;

  void *local_2e4;

  void *pvStack_2e0;

  float fStack_2dc;

  float fStack_2d8;

  void *pvStack_2d4;

  float fStack_2d0;

  int iStack_2cc;

  uint32_t /* width from decompiler */ uStack_2c8;

  uint32_t /* width from decompiler */ uStack_2c4;

  uint32_t /* width from decompiler */ uStack_2c0;

  void *local_2b4;

  uint32_t /* width from decompiler */ local_2b0;

  void **local_2a4;

  void *local_2a0;

  float *pfStack_29c;

  void *pvStack_298;

  float fStack_294;

  void *local_290;

  float local_28c;

  float local_288;

  float *pfStack_284;

  void *pvStack_280;

  float fStack_27c;

  void *pvStack_278;

  float fStack_274;

  float fStack_270;

  void **ppvStack_26c;

  float fStack_268;

  float *local_260;

  uint32_t /* width from decompiler */ local_25c;

  uint32_t /* width from decompiler */ *local_258;

  int local_250;

  uint32_t /* width from decompiler */ local_24c;

  uint32_t /* width from decompiler */ local_248;

  void **local_244;

  float local_240;

  float local_23c;

  void *local_238;

  void **local_234;

  void **local_230;

  float fStack_22c;

  float fStack_228;

  void **local_224;

  uint8_t auStack_220 [4];

  void *pvStack_21c;

  float afStack_218 [63];

  char cStack_119;

  void *apvStack_118 [62];

  uint8_t uStack_20;

  int *piStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a777b;

  pvStack_c = ExceptionList;

  local_260 = (float *)0x0;

  local_25c = 0;

  local_258 = (uint32_t /* width from decompiler */ *)0x0;

  local_250 = 0;

  local_24c = 0;

  local_248 = 0;

  pppvStack_3a0 = &local_290;

  local_4 = 1;

  local_290 = (float *)0x0;

  local_28c = g_flOne;

  local_288 = 0.0;

  ppfStack_3a4 = (float **)0x5e7d86;

  ExceptionList = &pvStack_c;

  local_338 = param_1;

  FUN_0076f5f0();

  local_340 = &ppfStack_3a4;

  local_334 = (float *)SQRT(((float)param_2[3] - (float)param_2[5]) *

                            ((float)param_2[3] - (float)param_2[5]) +

                            ((float)param_2[2] - (float)param_2[4]) *

                            ((float)param_2[2] - (float)param_2[4]));

  local_374 = (uint8_t *)(1 - (int)ROUND((float)local_334 * _DAT_009dca08));

  local_378 = (uint8_t *)((int)local_374 * 2);

  local_370 = (uint8_t *)(DAT_00a0f298 / (float)(int)local_374);

  ppfStack_3ac = (float **)0x5e7e0f;

  FUN_005c53b0();

  local_36c = param_2[3];

  local_360 = (void **)param_2[2];

  if (param_7 == (float *)0x0) {

    local_310 = (void *)((float)param_2[4] - (float)*param_2);

    local_308 = (float)param_2[5] - (float)param_2[1];

    pppvStack_3a0 = &local_310;

    ppfStack_3a4 = (float **)&local_384;

    local_30c = (void *)0x0;

    FUN_0076e240();

  }

  else {

    local_384 = (void **)*param_7;

    local_380 = (void *)param_7[1];

    local_37c = param_7[2];

  }

  pppvStack_3a0 = &local_384;

  ppfStack_3a4 = (float **)0x5e7ea1;

  FUN_0076f5f0();

  pfVar13 = local_260;

  fVar19 = *(float *)((int)param_1 + 0x164) * DAT_00a0f298;

  local_384 = (void **)(fVar19 * (float)local_384);

  local_37c = fVar19 * local_37c;

  local_380 = (void *)(fVar19 * (float)local_380);

  local_344 = (float)local_36c + local_37c;

  local_34c = (float)local_360 + (float)local_384;

  *local_260 = local_34c;

  local_260[1] = (float)local_380;

  local_260[2] = local_344;

  pppvStack_3a0 = (void ***)*local_260;

  ppfStack_3a4 = (float **)0x5e7f33;

  local_348 = local_380;

  fVar18 = (float10)FUN_004cd220();

  pfVar13[1] = (float)(fVar18 + (float10)_DAT_009d8238);

  local_344 = (float)local_36c - local_37c;

  local_34c = (float)local_360 - (float)local_384;

  local_348 = (void *)(0.0 - (float)local_380);

  pfVar13[3] = local_34c;

  pfVar13[4] = (float)local_348;

  pfVar13[5] = local_344;

  pppvStack_3a0 = (void ***)pfVar13[3];

  ppfStack_3a4 = (float **)0x5e7f9d;

  fVar18 = (float10)FUN_004cd220();

  pfVar13[4] = (float)(fVar18 + (float10)_DAT_009d8238);

  local_2a4 = (void **)param_2[2];

  local_2a0 = param_2[3];

  local_2e4 = (void *)(0.0 - local_37c);

  local_33c = local_37c;

  local_2e8 = (void *)(0.0 - (float)local_384);

  local_340 = local_384;

  local_36c = param_2[5];

  local_360 = (void **)param_2[4];

  local_2b4 = local_2e8;

  local_2b0 = (float)local_2e4;

  if (param_8 == (float *)0x0) {

    local_308 = (float)param_2[7] - (float)param_2[3];

    local_310 = (void *)((float)param_2[6] - (float)param_2[2]);

    pppvStack_3a0 = &local_310;

    ppfStack_3a4 = (float **)&local_384;

    local_30c = (void *)0x0;

    FUN_0076e240();

  }

  else {

    local_384 = (void **)*param_8;

    local_380 = (void *)param_8[1];

    local_37c = param_8[2];

  }

  pppvStack_3a0 = &local_384;

  ppfStack_3a4 = (float **)0x5e80a1;

  FUN_0076f5f0();

  fVar19 = *(float *)((int)param_1 + 0x164) * DAT_00a0f298;

  local_384 = (void **)(fVar19 * (float)local_384);

  local_37c = fVar19 * local_37c;

  local_380 = (void *)(fVar19 * (float)local_380);

  local_344 = (float)local_36c + local_37c;

  pfVar13 = pfVar13 + (int)local_378 * 3;

  local_34c = (float)local_360 + (float)local_384;

  *pfVar13 = local_34c;

  pfVar13[1] = (float)local_380;

  pfVar13[2] = local_344;

  pppvStack_3a0 = (void ***)*pfVar13;

  ppfStack_3a4 = (float **)0x5e8136;

  local_348 = local_380;

  fVar18 = (float10)FUN_004cd220();

  pfVar13[1] = (float)(fVar18 + (float10)_DAT_009d8238);

  local_344 = (float)local_36c - local_37c;

  local_34c = (float)local_360 - (float)local_384;

  local_348 = (void *)(0.0 - (float)local_380);

  pfVar13[3] = local_34c;

  pfVar13[4] = (float)local_348;

  pfVar13[5] = local_344;

  pppvStack_3a0 = (void ***)pfVar13[3];

  ppfStack_3a4 = (float **)0x5e81a0;

  fVar18 = (float10)FUN_004cd220();

  pfVar13[4] = (float)(fVar18 + (float10)_DAT_009d8238);

  local_234 = (void **)param_2[4];

  local_230 = (void **)param_2[5];

  local_240 = local_37c;

  local_2e4 = (void *)(0.0 - local_37c);

  local_2e8 = (void *)(0.0 - (float)local_384);

  local_244 = local_384;

  local_36c = (void *)0x1;

  local_23c = (float)local_2e8;

  local_238 = local_2e4;

  if (1 < (int)local_374) {

    local_378 = (uint8_t *)(g_flOne / (float)local_334);

    local_334 = local_260 + 6;

    do {

      local_388 = (float)(int)local_36c * DAT_00aaa6c4 * (float)local_378;

      if (g_flOne <= local_388) {

        local_370 = (uint8_t *)(0.0 - (float)local_370);

        local_388 = g_flOne;

      }

      pppvStack_3a0 = (void ***)(param_2 + 6);

      ppfStack_3ac = param_2;

      ppfStack_3a4 = param_2 + 4;

      D3DXVec2CatmullRom();

      ppfStack_3c4 = param_2;

      pppvStack_3c8 = &local_234;

      uStack_3cc = 0x5e82d6;

      ppvStack_3c0 = param_2 + 2;

      pppvStack_3bc = (void ***)(param_2 + 4);

      D3DXVec2CatmullRom();

      local_384 = (void **)((float)pvStack_21c - (float)local_224);

      local_360 = local_224;

      local_37c = afStack_218[0] - (float)auStack_220;

      pvStack_358 = (void *)auStack_220;

      if (g_flOne <= local_388) {

        local_37c = 0.0 - local_37c;

        local_384 = (void **)(0.0 - (float)local_384);

        pvStack_280 = (float *)0x0;

        pfStack_284 = (float *)local_384;

        fStack_27c = local_37c;

      }

      local_380 = (void *)0x0;

      pppvStack_3a0 = &local_384;

      ppfStack_3a4 = (float **)0x5e8389;

      FUN_0076f5f0();

      ppfStack_3a4 = &local_290;

      ppfStack_3ac = (float **)&local_384;

      FUN_0076e240();

      FUN_0076f5f0();

      fVar19 = *(float *)((int)local_338 + 0x164) * DAT_00a0f298;

      local_384 = (void **)(fVar19 * (float)local_384);

      local_380 = (void *)(fVar19 * (float)local_380);

      local_37c = fVar19 * local_37c;

      local_310 = (void *)(0.0 - (float)local_384);

      local_30c = (void *)(0.0 - (float)local_380);

      local_308 = 0.0 - local_37c;

      ppvStack_2f8 = local_2a4;

      ppvStack_300 = local_360;

      pvStack_2d4 = (void *)((float)local_360 + (float)local_384);

      ppvStack_368 = (void **)((float)local_2a4 + (float)local_340);

      ppvStack_2f4 = local_2a0;

      pvStack_2fc = pvStack_358;

      fStack_2d0 = (float)pvStack_358 + local_37c;

      pvStack_364 = (void *)((float)local_2a0 + local_33c);

      pppvStack_3bc = &ppvStack_2f8;

      ppvStack_3c0 = &pvStack_2d4;

      ppfStack_3c4 = (float **)&ppvStack_300;

      pppvStack_3c8 = (void ***)0x0;

      uStack_3cc = 0x5e8502;

      local_2e8 = ppvStack_368;

      local_2e4 = pvStack_364;

      pvStack_278 = local_310;

      fStack_274 = (float)local_30c;

      fStack_270 = local_308;

      cVar4 = FUN_00788280();

      if (cVar4 != '\0') {

        local_37c = (float)pvStack_364 - (float)pvStack_2fc;

        local_384 = (void **)((float)ppvStack_368 - (float)ppvStack_300);

      }

      pvStack_2d4 = (void *)((float)local_310 + (float)ppvStack_300);

      fStack_2d0 = local_308 + (float)pvStack_2fc;

      ppvStack_368 = (void **)((float)ppvStack_2f8 + (float)local_2b4);

      pvStack_364 = (void *)((float)ppvStack_2f4 + local_2b0);

      pppvStack_3a0 = &ppvStack_2f8;

      ppfStack_3a4 = &pvStack_2d4;

      ppfStack_3ac = (float **)0x0;

      ppvStack_26c = ppvStack_368;

      fStack_268 = (float)pvStack_364;

      cVar4 = FUN_00788280();

      if (cVar4 != '\0') {

        local_308 = (float)pvStack_364 - (float)pvStack_2fc;

        local_310 = (void *)((float)ppvStack_368 - (float)ppvStack_300);

      }

      pvStack_2fc = pvStack_358;

      fStack_2d0 = (float)pvStack_358 + local_37c;

      ppvStack_300 = local_360;

      pvStack_2d4 = (void *)((float)local_360 + (float)local_384);

      ppvStack_2f8 = local_234;

      ppvStack_368 = (void **)((float)local_234 + (float)local_244);

      ppvStack_2f4 = local_230;

      pvStack_364 = (void *)((float)local_230 + local_240);

      pppvStack_3a0 = &ppvStack_2f8;

      ppfStack_3a4 = &pvStack_2d4;

      ppfStack_3ac = (float **)0x0;

      fStack_22c = (float)ppvStack_368;

      fStack_228 = (float)pvStack_364;

      cVar4 = FUN_00788280();

      if (cVar4 != '\0') {

        local_37c = (float)pvStack_364 - (float)pvStack_2fc;

        local_384 = (void **)((float)ppvStack_368 - (float)ppvStack_300);

      }

      pvStack_2d4 = (void *)((float)local_310 + (float)ppvStack_300);

      fStack_2d0 = local_308 + (float)pvStack_2fc;

      ppvStack_368 = (void **)(local_23c + (float)ppvStack_2f8);

      pvStack_364 = (void *)((float)local_238 + (float)ppvStack_2f4);

      pppvStack_3a0 = &ppvStack_2f8;

      ppfStack_3a4 = &pvStack_2d4;

      ppfStack_3ac = (float **)0x0;

      local_34c = (float)ppvStack_368;

      local_348 = pvStack_364;

      cVar4 = FUN_00788280();

      local_2b4 = local_310;

      local_2b0 = local_308;

      if (cVar4 != '\0') {

        local_2b4 = (float *)((float)ppvStack_368 - (float)ppvStack_300);

        local_2b0 = (float)pvStack_364 - (float)pvStack_2fc;

      }

      local_2a4 = local_360;

      pvStack_298 = local_380;

      local_2a0 = pvStack_358;

      pfStack_29c = (float *)((float)local_360 + (float)local_384);

      fStack_294 = (float)pvStack_358 + local_37c;

      *local_334 = (float)pfStack_29c;

      fStack_2dc = (float)local_30c;

      local_334[1] = (float)local_380;

      local_334[2] = fStack_294;

      pvStack_2e0 = (void *)((float)local_2b4 + (float)local_360);

      local_334[3] = (float)pvStack_2e0;

      local_334[4] = (float)local_30c;

      fStack_2d8 = local_2b0 + (float)pvStack_358;

      local_334[5] = fStack_2d8;

      local_340 = local_384;

      local_36c = (void *)((int)local_36c + 1);

      local_334 = local_334 + 6;

      local_33c = local_37c;

    } while ((int)local_36c < (int)local_374);

  }

  local_388 = 0.0;

  local_30c = (void *)0x0;

  local_308 = 0.0;

  local_304 = 0;

  local_32c = (void *)0x0;

  local_328 = (void *)0x0;

  local_324 = 0;

  local_4._0_1_ = 3;

  pppvStack_3a0 = (void ***)0x5e891e;

  FUN_004b0330();

  pvStack_31c = (void *)0x0;

  pvStack_318 = (void *)0x0;

  uStack_314 = 0;

  local_4 = CONCAT31(local_4._1_3_,4);

  if (**(int **)((int)local_338 + 0x14) != 0) {

    fVar18 = (float10)(**(code **)(*(int *)**(int **)((int)local_338 + 0x14) + 0x9c))();

    local_388 = (float)fVar18;

  }

  pvVar14 = local_32c;

  puVar3 = local_378;

  if (0 < (int)local_374) {

    pfVar13 = local_260 + 4;

    local_378 = local_374;

    do {

      pvStack_2e0 = (void *)(pfVar13[-4] + pfVar13[-1]);

      fStack_2d8 = pfVar13[-2] + pfVar13[1];

      pfStack_29c = (float *)(pfVar13[5] + pfVar13[2]);

      fStack_2dc = pfVar13[-3] + *pfVar13;

      pvStack_298 = (void *)(pfVar13[3] + pfVar13[6]);

      fStack_294 = pfVar13[7] + pfVar13[4];

      local_334 = (float *)((float)pvStack_2e0 * DAT_00a0f298 - (float)pfStack_29c * DAT_00a0f298);

      local_36c = (void *)(fStack_2d8 * DAT_00a0f298 - fStack_294 * DAT_00a0f298);

      local_374 = (uint8_t *)&ppfStack_3ac;

      local_340 = (void **)(SQRT((float)local_36c * (float)local_36c +

                                 (float)local_334 * (float)local_334) * g_flMultiKillCountBlend +

                           local_388);

      local_370 = (uint8_t *)(DAT_00a110d8 / *(float *)((int)local_338 + 0x164));

      local_2a4 = local_340;

      pfStack_284 = pfStack_29c;

      pvStack_280 = pvStack_298;

      fStack_27c = fStack_294;

      pvStack_278 = pvStack_2e0;

      fStack_274 = fStack_2dc;

      fStack_270 = fStack_2d8;

      ppvStack_26c = local_340;

      FUN_004b08b0();

      local_374 = (uint8_t *)&ppfStack_3ac;

      FUN_004b08b0();

      local_360 = (void **)pfVar13[-4];

      fStack_35c = pfVar13[-3];

      pvStack_358 = (void *)pfVar13[-2];

      pvStack_354 = (void *)((float)local_370 * local_388);

      fStack_350 = 0.0;

      pppvStack_3a0 = (void ***)0x5e8b4d;

      FUN_004b0b40();

      pvStack_354 = (void *)((float)local_370 * (float)ppvStack_26c);

      local_360 = (void **)pfVar13[2];

      fStack_35c = pfVar13[3];

      pvStack_358 = (void *)pfVar13[4];

      fStack_350 = 0.0;

      pppvStack_3a0 = (void ***)0x5e8b98;

      local_2e8 = pvStack_354;

      FUN_004b0b40();

      pvStack_354 = (void *)((float)local_370 * local_388);

      local_360 = (void **)pfVar13[-1];

      fStack_35c = *pfVar13;

      pvStack_358 = (void *)pfVar13[1];

      fStack_350 = g_flOne;

      pppvStack_3a0 = (void ***)0x5e8be5;

      local_2b4 = pvStack_354;

      FUN_004b0b40();

      pppvStack_3a0 = (void ***)&uStack_320;

      ppfStack_3a4 = (float **)0x5e8c04;

      FUN_004ae3d0();

      local_388 = 0.0;

      local_374 = (uint8_t *)0x0;

      while( true ) {

        if (local_32c == (void *)0x0) {

          iVar5 = 0;

        }

        else {

          iVar5 = ((int)local_328 - (int)local_32c) / 0x14;

        }

        if (iVar5 <= (int)local_388) break;

        pppvStack_3a0 = (void ***)0x5e8c51;

        FUN_004b0b40();

        local_388 = (float)((int)local_388 + 1);

        local_374 = (uint8_t *)((int)local_374 + 0x14);

      }

      local_374 = (uint8_t *)&ppfStack_3ac;

      FUN_004b08b0();

      local_374 = (uint8_t *)&ppfStack_3ac;

      FUN_004b08b0();

      local_360 = (void **)pfVar13[2];

      fStack_35c = pfVar13[3];

      pvStack_358 = (void *)pfVar13[4];

      pvStack_354 = local_2e8;

      fStack_350 = 0.0;

      pppvStack_3a0 = (void ***)0x5e8cc0;

      FUN_004b0b40();

      local_360 = (void **)pfVar13[5];

      pvStack_354 = (void *)((float)local_370 * (float)local_2a4);

      fStack_35c = pfVar13[6];

      pvStack_358 = (void *)pfVar13[7];

      fStack_350 = g_flOne;

      pppvStack_3a0 = (void ***)0x5e8d06;

      FUN_004b0b40();

      local_360 = (void **)pfVar13[-1];

      pvStack_358 = (void *)pfVar13[1];

      fStack_35c = *pfVar13;

      pvStack_354 = local_2b4;

      fStack_350 = g_flOne;

      pppvStack_3a0 = (void ***)0x5e8d45;

      FUN_004b0b40();

      pppvStack_3a0 = (void ***)&uStack_320;

      ppfStack_3a4 = (float **)0x5e8d64;

      FUN_004ae3d0();

      local_388 = 0.0;

      while( true ) {

        pvVar14 = local_32c;

        if (local_32c == (void *)0x0) {

          iVar5 = 0;

        }

        else {

          iVar5 = ((int)local_328 - (int)local_32c) / 0x14;

        }

        if (iVar5 <= (int)local_388) break;

        pppvStack_3a0 = (void ***)0x5e8da9;

        FUN_004b0b40();

        local_388 = (float)((int)local_388 + 1);

      }

      fVar18 = (float10)_CIfmod();

      local_388 = (float)fVar18;

      pfVar13 = pfVar13 + 6;

      *(float *)((int)local_338 + 0x168) = (float)fVar18;

      local_378 = local_378 + -1;

    } while (local_378 != (uint8_t *)0x0);

    puVar3 = (uint8_t *)0.0;

    if ((local_30c != (void *)0x0) &&

       (puVar2 = (uint8_t *)(((int)local_308 - (int)local_30c) / 0x14), local_370 = puVar2,

       0 < (int)puVar2)) {

      local_2b4 = (void *)((int)puVar2 / 3);

      if ((uint8_t *)((int)local_2b4 * 3) != puVar2) {

        pppvStack_3a0 = (void ***)0x0;

        ppfStack_3a4 = (float **)0x5e8e3c;

        FUN_007a4480();

      }

      local_340 = (void **)auStack_3d0;

      FUN_005e9d40(puVar2);

      if (0 < (int)puVar2) {

        pfVar15 = (float *)(local_250 + 4);

        local_378 = local_370;

        pfVar13 = (float *)((int)local_30c + 0x10);

        do {

          pfVar1 = pfVar15 + -1;

          *pfVar1 = pfVar13[-4];

          *pfVar15 = pfVar13[-3];

          pfVar15[1] = pfVar13[-2];

          pppvStack_3a0 = (void ***)*pfVar1;

          ppfStack_3a4 = (float **)0x5e8eae;

          fVar18 = (float10)FUN_004cd220();

          *pfVar15 = (float)(fVar18 + (float10)_DAT_009d8238);

          pvStack_2e0 = (void *)(*pfVar1 - param_4);

          fStack_2dc = *pfVar15 - param_5;

          fStack_2d8 = pfVar15[1] - param_6;

          *pfVar1 = (float)pvStack_2e0;

          *pfVar15 = fStack_2dc;

          pfVar15[1] = fStack_2d8;

          pfVar15[2] = (float)local_290;

          pfVar15[3] = local_28c;

          pfVar15[4] = local_288;

          pfVar15[5] = pfVar13[-1];

          pfVar15[6] = *pfVar13;

          pfVar15 = pfVar15 + 0xe;

          local_378 = local_378 + -1;

          pfVar13 = pfVar13 + 5;

        } while (local_378 != (uint8_t *)0x0);

      }

      if ((uint32_t /* width from decompiler */ *)*param_3 != (uint32_t /* width from decompiler */ *)0x0) {

        pppvStack_3a0 = (void ***)0x5e8f66;

        (*(code *)**(uint32_t /* width from decompiler */ **)*param_3)();

        *param_3 = 0;

      }

      pppvStack_3a0 = (void ***)0x5e8f72;

      local_340 = operator_new(0x14c);

      local_4._0_1_ = 5;

      if (local_340 == (void *)0x0) {

        iVar5 = 0;

      }

      else {

        iVar5 = FUN_00764030();

      }

      local_4._0_1_ = 4;

      *param_3 = iVar5;

      pppvStack_3a0 = (void ***)0x5e900c;

      FUN_007638d0();

      pppvStack_3a0 = (void ***)0x5e9016;

      local_340 = operator_new(0xc4);

      local_4._0_1_ = 6;

      if (local_340 == (void *)0x0) {

        piVar6 = (int *)0x0;

      }

      else {

        piVar6 = (int *)FUN_00748960();

      }

      local_4 = CONCAT31(local_4._1_3_,4);

      iVar7 = (**(code **)(*(int *)*param_3 + 0xc))();

      iVar5 = *piVar6;

      piVar6[0x19] = iVar7;

      (**(code **)(*(int *)*param_3 + 100))();

      pppvStack_3a0 = (void ***)0x5e9058;

      (**(code **)(iVar5 + 0x34))();

      pppvStack_3a0 = (void ***)*param_3;

      ppfStack_3a4 = (float **)0x5e9063;

      (**(code **)(*piVar6 + 0x20))();

      ppfStack_3a4 = (float **)0xa2def8;

      ppfStack_3ac = (float **)0x5e9077;

      FUN_00989e00();

      ppfStack_3a4 = &local_348;

      FUN_009701d0();

      pcVar16 = (char *)((int)local_340 + 0x30);

      pcVar8 = pcVar16;

      do {

        cVar4 = *pcVar8;

        pcVar8[(int)afStack_218 + (-4 - (int)pcVar16)] = cVar4;

        pcVar8 = pcVar8 + 1;

      } while (cVar4 != '\0');

      puVar9 = (uint32_t /* width from decompiler */ *)(auStack_220 + 3);

      do {

        puVar17 = puVar9;

        puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar17 + 1);

      } while (*(char *)((int)puVar17 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar17 + 1) = DAT_00a2c53c;

      *(uint8_t *)((int)puVar17 + 5) = DAT_00a2c540;

      ppfStack_3a4 = (float **)0x5e90d7;

      FUN_0096ef70();

      ppfStack_3a4 = &pvStack_21c;

      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,7);

      ppfStack_3ac = (float **)0x5e90f6;

      FUN_00989e00();

      ppfStack_3a4 = (float **)0x0;

      ppfStack_3ac = (float **)0x5e9108;

      FUN_0096f3e0();

      ppfStack_3a4 = ppvStack_2f4;

      ppfStack_3ac = (float **)0x5e911d;

      FUN_00970140();

      iVar5 = (int)apvStack_118 - (int)pcVar16;

      do {

        cVar4 = *pcVar16;

        pcVar16[iVar5] = cVar4;

        pcVar16 = pcVar16 + 1;

      } while (cVar4 != '\0');

      pcVar8 = &cStack_119;

      do {

        pcVar16 = pcVar8;

        pcVar8 = pcVar16 + 1;

      } while (pcVar16[1] != '\0');

      *(uint32_t /* width from decompiler */ *)(pcVar16 + 1) = s__bump_dds_009dcc34._0_4_;

      *(uint32_t /* width from decompiler */ *)(pcVar16 + 5) = s__bump_dds_009dcc34._4_4_;

      *(uint16_t *)(pcVar16 + 9) = s__bump_dds_009dcc34._8_2_;

      ppfStack_3a4 = (float **)0x5e9171;

      FUN_0096ef70();

      ppfStack_3a4 = apvStack_118;

      pvStack_c._0_1_ = 8;

      ppfStack_3ac = (float **)0x5e9190;

      FUN_00989e00();

      ppfStack_3a4 = (float **)0x0;

      ppfStack_3ac = (float **)0x5e91a2;

      FUN_0096f3e0();

      ppfStack_3a4 = ppvStack_2f8;

      ppfStack_3ac = (float **)0x5e91b7;

      FUN_00970140();

      fStack_2d0 = 0.0;

      iStack_2cc = 0;

      uStack_2c8 = 0;

      ppfStack_3a4 = (float **)0x112;

      pvStack_c._0_1_ = 9;

      uStack_2c4 = 0;

      uStack_2c0 = 0;

      FUN_007478c0();

      ppfStack_3a4 = &local_2b4;

      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,10);

      local_2b4 = (float *)0x0;

      local_2b0 = 5.51016e-40;

      FUN_007471c0();

      ppfStack_3a4 = &local_2b4;

      local_2b0 = (float)CONCAT13(1,(undefined3)local_2b0);

      FUN_007471c0();

      piVar6[0x2f] = piVar6[0x2f] | 1;

      ppfStack_3a4 = (float **)0x0;

      ppfStack_3ac = &pvStack_2d4;

      iVar5 = FUN_00414c20();

      if (-1 < iVar5) {

        if (*(int *)(piVar6[5] + 0x10) != 0) {

          ppfStack_3a4 = (float **)0x0;

          ppfStack_3ac = *(float ***)(piVar6[5] + 0x14);

          puVar9 = (uint32_t /* width from decompiler */ *)FUN_00746520();

          if (puVar9 != (uint32_t /* width from decompiler */ *)0x0) {

            puVar17 = local_258;

            for (uVar12 = (uint)((int)local_378 * 0x38) >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

              *puVar9 = *puVar17;

              puVar17 = puVar17 + 1;

              puVar9 = puVar9 + 1;

            }

            for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {

              *(uint8_t *)puVar9 = *(uint8_t *)puVar17;

              puVar17 = (uint32_t /* width from decompiler */ *)((int)puVar17 + 1);

              puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

            }

            if (*(int *)(piVar6[5] + 0x10) != 0) {

              ppfStack_3a4 = (float **)0x5e93d4;

              FUN_007464e0();

            }

            puVar3 = local_378;

            ppfStack_3a4 = (float **)0x0;

            ppfStack_3ac = (float **)0x20;

            FUN_0044b9c0();

            if (*(int *)(piVar6[3] + 0x10) != 0) {

              pppvStack_3bc = *(void ****)(piVar6[3] + 0x18);

              ppvStack_3c0 = (void **)0x5e9403;

              puVar10 = (ushort *)FUN_00743be0();

              if (puVar10 != (ushort *)0x0) {

                if ((ushort)puVar3 != 0) {

                  uVar11 = 0;

                  do {

                    *puVar10 = uVar11;

                    uVar11 = uVar11 + 1;

                    puVar10 = puVar10 + 1;

                  } while (uVar11 < (ushort)puVar3);

                }

                if (*(int *)(piVar6[3] + 0x10) != 0) {

                  FUN_00743ba0();

                }

                if (piVar6[5] != 0) {

                  pppvStack_3bc = (void ***)0x5e9552;

                  FUN_009999d0();

                }

                piVar6[0x2a] = iStack_2cc;

                piVar6[0x2b] = 4;

                FUN_0096f740();

                piVar6 = piStack_10;

                FUN_007647c0();

                (**(code **)(*(int *)*piVar6 + 0x50))();

                iVar5 = (**(code **)(*(int *)*piVar6 + 0x10))();

                *(uint32_t /* width from decompiler */ *)(iVar5 + 0xbc) = 0xffffffff;

                *(int *)(iVar5 + 0xb4) = *(int *)(iVar5 + 0xb4) + 1;

                *(int **)(iVar5 + 0x90) = piStack_10;

                *(void **)(iVar5 + 0x94) = pvStack_c;

                *(uint8_t **)(iVar5 + 0x98) = puStack_8;

                *(uint8_t *)(*piVar6 + 0x139) = 1;

                fStack_2d8 = 0.0;

                pvStack_2d4 = (float *)0x0;

                if (local_2e4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

                  pppvStack_3bc = (void ***)&UNK_005e95eb;

                  operator_delete(local_2e4);

                }

                local_2e4 = (void *)0x0;

                pvStack_2e0 = (void *)0x0;

                fStack_2dc = 0.0;

                uStack_20 = 7;

                FUN_0096efd0();

                uStack_20 = 4;

                FUN_0096efd0();

                if (local_338 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

                  pppvStack_3bc = (void ***)&UNK_005e9639;

                  operator_delete(local_338);

                }

                local_338 = (void *)0x0;

                local_334 = (float *)0x0;

                local_330 = 0;

                if (local_348 == (float *)0x0) {

                  local_348 = (float *)0x0;

                  local_344 = 0.0;

                  local_340 = (void **)0x0;

                    /* WARNING: Subroutine does not return */

                  pppvStack_3bc = (void ***)&UNK_005e9678;

                  operator_delete(local_328);

                }

                    /* WARNING: Subroutine does not return */

                pppvStack_3bc = (void ***)&UNK_005e965c;

                operator_delete(local_348);

              }

            }

            pppvStack_3bc = (void ***)0x5e9416;

            FUN_007a4480();

            if (*(int *)(piVar6[3] + 0x10) != 0) {

              FUN_00743ba0();

            }

            if ((uint32_t /* width from decompiler */ *)*piStack_10 != (uint32_t /* width from decompiler */ *)0x0) {

              (*(code *)**(uint32_t /* width from decompiler */ **)*piStack_10)();

            }

            *piStack_10 = 0;

            (**(code **)*piVar6)();

            fStack_2d8 = 0.0;

            pvStack_2d4 = (float *)0x0;

            if (local_2e4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

              pppvStack_3bc = (void ***)&UNK_005e9465;

              operator_delete(local_2e4);

            }

            local_2e4 = (void *)0x0;

            pvStack_2e0 = (void *)0x0;

            fStack_2dc = 0.0;

            uStack_20 = 7;

            FUN_0096efd0();

            uStack_20 = 4;

            FUN_0096efd0();

            if (local_338 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

              pppvStack_3bc = (void ***)&UNK_005e94b3;

              operator_delete(local_338);

            }

            local_338 = (void *)0x0;

            local_334 = (float *)0x0;

            local_330 = 0;

            if (local_348 == (float *)0x0) {

              local_348 = (float *)0x0;

              local_344 = 0.0;

              local_340 = (void **)0x0;

                    /* WARNING: Subroutine does not return */

              pppvStack_3bc = (void ***)&UNK_005e94f2;

              operator_delete(local_328);

            }

                    /* WARNING: Subroutine does not return */

            pppvStack_3bc = (void ***)&UNK_005e94d6;

            operator_delete(local_348);

          }

        }

        if (*(int *)(piVar6[5] + 0x10) != 0) {

          ppfStack_3a4 = (float **)0x5e92ad;

          FUN_007464e0();

        }

      }

      if ((uint32_t /* width from decompiler */ *)*unaff_retaddr != (uint32_t /* width from decompiler */ *)0x0) {

        ppfStack_3a4 = (float **)0x1;

        (*(code *)**(uint32_t /* width from decompiler */ **)*unaff_retaddr)();

      }

      *unaff_retaddr = 0;

      ppfStack_3a4 = (float **)0x1;

      (**(code **)*piVar6)();

      uStack_2c8 = 0;

      uStack_2c4 = 0;

      if (pvStack_2d4 != (float *)0x0) {

                    /* WARNING: Subroutine does not return */

        ppfStack_3ac = (float **)&UNK_005e92ea;

        operator_delete(pvStack_2d4);

      }

      piStack_10._0_1_ = 7;

      iStack_2cc = 0;

      fStack_2d0 = 0.0;

      pvStack_2d4 = (float *)0x0;

      FUN_0096efd0();

      piStack_10 = (int *)CONCAT31(piStack_10._1_3_,4);

      FUN_0096efd0();

      if (local_328 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        ppfStack_3ac = (float **)&UNK_005e9338;

        operator_delete(local_328);

      }

      local_328 = (void *)0x0;

      local_324 = 0;

      uStack_320 = 0;

      if (local_338 == (void *)0x0) {

        local_338 = (void *)0x0;

        local_334 = (float *)0x0;

        local_330 = 0;

                    /* WARNING: Subroutine does not return */

        ppfStack_3ac = (float **)&UNK_005e9377;

        operator_delete(pvStack_318);

      }

                    /* WARNING: Subroutine does not return */

      ppfStack_3ac = (float **)&UNK_005e935b;

      operator_delete(local_338);

    }

  }

  local_378 = puVar3;

  if (pvStack_31c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    pppvStack_3a0 = (void ***)&UNK_005e8fa7;

    operator_delete(pvStack_31c);

  }

  pvStack_31c = (void *)0x0;

  pvStack_318 = (void *)0x0;

  uStack_314 = 0;

  if (pvVar14 == (void *)0x0) {

    local_32c = (void *)0x0;

    local_328 = (void *)0x0;

    local_324 = 0;

    if (local_30c == (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      pppvStack_3a0 = (void ***)&UNK_005e969c;

      operator_delete(local_260);

    }

                    /* WARNING: Subroutine does not return */

    pppvStack_3a0 = (void ***)&UNK_005e8fe7;

    operator_delete(local_30c);

  }

                    /* WARNING: Subroutine does not return */

  pppvStack_3a0 = (void ***)&UNK_005e8fca;

  operator_delete(pvVar14);

}
