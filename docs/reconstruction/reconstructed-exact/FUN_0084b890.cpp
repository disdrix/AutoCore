// =============================================================================
// FUN_0084b890 / UI_ItemDetailPanel_Refresh_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0084b890
// Address:   0x0084b890  (autoassault.exe, image base 0x400000)
// Body:      0x0084b890–0x0084ca69 (4569 bytes)
// System:    client UI / inventory item detail panel
// Generated: 2026-07-23 scaffold; W22-K seal 2026-07-29
// Named clean: UI_ItemDetailPanel_Refresh_Inferred.cpp (stage CF)
// Exactness: Full decompiler surface scaffold (stack temps). Prefer named clean
//            for stage semantics. Bit-for-bit: DEFERRED.
// Dual: reviews/A_aa_0084b890_* / B_aa_0084b890_*
// =============================================================================
//
// PURPOSE: Virtual item-detail panel refresh/layout (vtbl 0x00a697e4).
// ABI: thiscall ECX=panel*; gate this+0x518 object*.
// Strings: "i_g_2d_overlay_broken.dds"; "%.01f%% %s"; "%s: %s".
// Constants: DAT_00aaa67c≈0.000625; DAT_00aaa678≈0.000833; DAT_00aaa7ac=100;
//            DAT_00aaa99c≈114.5916 (acos scale).
//

// READABILITY (auto CF):
//  - Body size: ~995 non-empty decompiler lines.
//  - Control keywords: if×23, return×2, do×1, while×1.
//  - Notable callees: CONCAT44×11, FUN_007a6de0×3, FUN_0075bf40×2, sprintf×2, CONCAT22, FUN_0040d0a0, FUN_00514050, FUN_005140d0.
//  - Strings: "i_g_2d_overlay_broken.dds"; "%.01f%% %s"; "%s: %s".
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



void __fastcall FUN_0084b890(float *param_1)



{

  uint32_t /* width from decompiler */ **ppuVar1;

  char cVar2;

  float fVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *piVar7;

  int iVar8;

  int iVar9;

  int *piVar10;

  uint *puVar11;

  int iVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint uVar14;

  uint32_t /* width from decompiler */ ****ppppuVar15;

  float10 fVar16;

  uint32_t /* width from decompiler */ uStack_3f4;

  uint32_t /* width from decompiler */ *puStack_3f0;

  uint32_t /* width from decompiler */ ***pppuStack_3ec;

  uint32_t /* width from decompiler */ *puStack_3e8;

  uint32_t /* width from decompiler */ *puStack_3e4;

  uint32_t /* width from decompiler */ *puStack_3e0;

  uint32_t /* width from decompiler */ ***pppuStack_3dc;

  uint32_t /* width from decompiler */ ***pppuStack_3d8;

  uint32_t /* width from decompiler */ **ppuStack_3d4;

  uint32_t /* width from decompiler */ *puStack_3d0;

  uint32_t /* width from decompiler */ uStack_3cc;

  uint32_t /* width from decompiler */ ***pppuStack_3c8;

  uint32_t /* width from decompiler */ uStack_3c4;

  uint32_t /* width from decompiler */ *puStack_3c0;

  uint32_t /* width from decompiler */ **ppuStack_3bc;

  uint32_t /* width from decompiler */ uStack_3b8;

  uint32_t /* width from decompiler */ *puStack_3b4;

  uint32_t /* width from decompiler */ uStack_3b0;

  uint32_t /* width from decompiler */ uStack_3ac;

  uint32_t /* width from decompiler */ **ppuStack_3a8;

  int iStack_3a4;

  uint32_t /* width from decompiler */ **ppuStack_3a0;

  uint32_t /* width from decompiler */ uStack_39c;

  uint32_t /* width from decompiler */ uStack_398;

  uint32_t /* width from decompiler */ *puStack_394;

  uint32_t /* width from decompiler */ uStack_390;

  uint32_t /* width from decompiler */ *puStack_38c;

  uint32_t /* width from decompiler */ uStack_388;

  uint32_t /* width from decompiler */ **ppuStack_384;

  uint32_t /* width from decompiler */ **ppuStack_380;

  uint32_t /* width from decompiler */ *puStack_37c;

  uint32_t /* width from decompiler */ *puStack_378;

  uint32_t /* width from decompiler */ ***pppuStack_374;

  uint32_t /* width from decompiler */ uStack_370;

  uint32_t /* width from decompiler */ *puStack_36c;

  uint32_t /* width from decompiler */ *puStack_368;

  uint32_t /* width from decompiler */ uStack_364;

  uint32_t /* width from decompiler */ uStack_360;

  uint32_t /* width from decompiler */ *puStack_35c;

  uint32_t /* width from decompiler */ uStack_358;

  uint32_t /* width from decompiler */ ***pppuStack_354;

  uint32_t /* width from decompiler */ uStack_350;

  uint32_t /* width from decompiler */ uStack_34c;

  uint32_t /* width from decompiler */ *puStack_348;

  uint32_t /* width from decompiler */ *puStack_344;

  uint32_t /* width from decompiler */ uStack_340;

  uint32_t /* width from decompiler */ **ppuStack_33c;

  uint32_t /* width from decompiler */ *puStack_338;

  uint32_t /* width from decompiler */ uStack_334;

  uint32_t /* width from decompiler */ *puStack_330;

  uint32_t /* width from decompiler */ uStack_32c;

  uint32_t /* width from decompiler */ *puStack_328;

  uint32_t /* width from decompiler */ uStack_324;

  uint32_t /* width from decompiler */ uStack_320;

  uint32_t /* width from decompiler */ uStack_31c;

  uint32_t /* width from decompiler */ **ppuStack_318;

  uint32_t /* width from decompiler */ uStack_314;

  uint32_t /* width from decompiler */ *puStack_310;

  uint32_t /* width from decompiler */ uStack_30c;

  uint32_t /* width from decompiler */ uStack_308;

  uint32_t /* width from decompiler */ ***pppuStack_304;

  uint32_t /* width from decompiler */ *puStack_300;

  uint32_t /* width from decompiler */ uStack_2fc;

  uint32_t /* width from decompiler */ uStack_2f8;

  uint32_t /* width from decompiler */ *puStack_2f4;

  uint32_t /* width from decompiler */ ***pppuStack_2f0;

  uint32_t /* width from decompiler */ uStack_2ec;

  uint32_t /* width from decompiler */ *puStack_2e8;

  uint32_t /* width from decompiler */ *puStack_2e4;

  uint32_t /* width from decompiler */ uStack_2e0;

  uint32_t /* width from decompiler */ uStack_2dc;

  uint32_t /* width from decompiler */ *puStack_2d8;

  uint32_t /* width from decompiler */ uStack_2d4;

  uint32_t /* width from decompiler */ *puStack_2d0;

  uint32_t /* width from decompiler */ uStack_2cc;

  uint32_t /* width from decompiler */ uStack_2c8;

  uint32_t /* width from decompiler */ **ppuStack_2c4;

  uint32_t /* width from decompiler */ *puStack_2c0;

  uint32_t /* width from decompiler */ uStack_2bc;

  uint32_t /* width from decompiler */ **ppuStack_2b8;

  uint32_t /* width from decompiler */ uStack_2b4;

  uint32_t /* width from decompiler */ *puStack_2b0;

  uint32_t /* width from decompiler */ *puStack_2ac;

  uint32_t /* width from decompiler */ uStack_2a8;

  uint32_t /* width from decompiler */ uStack_2a4;

  uint32_t /* width from decompiler */ uStack_2a0;

  uint32_t /* width from decompiler */ uStack_29c;

  uint **ppuStack_298;

  uint32_t /* width from decompiler */ uStack_294;

  uint32_t /* width from decompiler */ uStack_290;

  uint32_t /* width from decompiler */ *puStack_28c;

  uint32_t /* width from decompiler */ *puStack_288;

  uint32_t /* width from decompiler */ uStack_284;

  uint32_t /* width from decompiler */ *puStack_280;

  uint32_t /* width from decompiler */ *puStack_27c;

  uint32_t /* width from decompiler */ uStack_278;

  uint32_t /* width from decompiler */ uStack_274;

  uint32_t /* width from decompiler */ **ppuStack_270;

  uint32_t /* width from decompiler */ uStack_26c;

  uint32_t /* width from decompiler */ *puStack_268;

  uint32_t /* width from decompiler */ uStack_264;

  uint32_t /* width from decompiler */ uStack_260;

  uint *puStack_25c;

  uint32_t /* width from decompiler */ *puStack_258;

  uint32_t /* width from decompiler */ uStack_254;

  uint32_t /* width from decompiler */ uStack_250;

  uint32_t /* width from decompiler */ **ppuStack_24c;

  uint uStack_248;

  uint32_t /* width from decompiler */ uStack_244;

  uint32_t /* width from decompiler */ *puStack_240;

  int *piStack_23c;

  uint32_t /* width from decompiler */ uStack_238;

  uint32_t /* width from decompiler */ uStack_234;

  uint32_t /* width from decompiler */ *puStack_230;

  uint32_t /* width from decompiler */ uStack_22c;

  uint32_t /* width from decompiler */ *puStack_228;

  uint32_t /* width from decompiler */ uStack_224;

  float fStack_220;

  uint32_t /* width from decompiler */ uStack_21c;

  uint32_t /* width from decompiler */ uStack_218;

  int *piStack_214;

  uint32_t /* width from decompiler */ *puStack_210;

  uint32_t /* width from decompiler */ uStack_20c;

  uint32_t /* width from decompiler */ *puStack_208;

  uint32_t /* width from decompiler */ uStack_204;

  int iStack_200;

  uint32_t /* width from decompiler */ **ppuStack_1fc;

  uint32_t /* width from decompiler */ *puStack_1f8;

  uint32_t /* width from decompiler */ uStack_1f4;

  uint32_t /* width from decompiler */ uStack_1f0;

  uint32_t /* width from decompiler */ uStack_1ec;

  uint32_t /* width from decompiler */ *puStack_1e8;

  uint32_t /* width from decompiler */ *puStack_1e4;

  uint32_t /* width from decompiler */ uStack_1e0;

  uint32_t /* width from decompiler */ uStack_1dc;

  uint32_t /* width from decompiler */ *puStack_1d8;

  uint32_t /* width from decompiler */ uStack_1d4;

  uint32_t /* width from decompiler */ uStack_1d0;

  int *piStack_1cc;

  uint32_t /* width from decompiler */ *puStack_1c8;

  uint32_t /* width from decompiler */ uStack_1c4;

  uint8_t **ppuStack_1c0;

  uint32_t /* width from decompiler */ uStack_1bc;

  int iStack_1b8;

  uint8_t ***pppuStack_1b4;

  int ***pppiStack_1b0;

  uint32_t /* width from decompiler */ uStack_1ac;

  uint32_t /* width from decompiler */ uStack_1a8;

  uint32_t /* width from decompiler */ uStack_1a4;

  uint8_t **ppuStack_1a0;

  char **ppcStack_19c;

  int *piStack_198;

  uint8_t *puStack_194;

  uint32_t /* width from decompiler */ uStack_190;

  uint8_t *puStack_18c;

  uint32_t /* width from decompiler */ uStack_188;

  int iStack_184;

  char **ppcStack_180;

  float **ppfStack_17c;

  double dStack_170;

  char *pcStack_16c;

  char *pcStack_168;

  char *pcStack_164;

  float fStack_160;

  float *pfStack_15c;

  float local_148;

  int iStack_144;

  uint32_t /* width from decompiler */ local_13c;

  uint8_t uStack_132;

  uint8_t uStack_131;

  uint32_t /* width from decompiler */ uStack_124;

  uint32_t /* width from decompiler */ uStack_120;

  char acStack_114 [272];

  

  if (param_1[0x146] != 0.0) {

    pfStack_15c = (float *)0x84b8b4;

    fVar3 = (float)FUN_007a69d0();

    fStack_160 = 1.2188578e-38;

    pfStack_15c = param_1;

    local_148 = fVar3;

    FUN_0084b210();

    *(uint32_t /* width from decompiler */ *)((int)param_1[0x14d] + 0x488) = 1;

    if (*(short *)(*(int *)(*(int *)((int)param_1[0x146] + 0xa8) + 0x3c) + 0x3f4) == 8) {

      pfStack_15c = *(float **)((int)param_1[0x146] + 200);

      fStack_160 = 1.2188652e-38;

      uVar4 = FUN_00519d20();

      pfStack_15c = (float *)(uVar4 | 0xdf000000);

      fStack_160 = 1.2188685e-38;

      (**(code **)(*(int *)param_1[0x14d] + 0x1a0))();

      fStack_160 = 1.2188694e-38;

      FUN_0075bf40();

    }

    else {

      local_13c = 0;

      pfStack_15c = (float *)0x0;

      fStack_160 = 1.2188752e-38;

      (**(code **)(*(int *)param_1[0x14d] + 0x1a0))();

      fStack_160 = 1.2188762e-38;

      FUN_0075bf40();

    }

    if (((*(uint *)((int)param_1[0x146] + 0x17c) >> 0x13 & 1) == 0) && (DAT_00d1791c == '\0')) {

      pfStack_15c = (float *)0x84b976;

      (**(code **)(*(int *)param_1[0x14d] + 0x58))();

    }

    else {

      piVar7 = (int *)param_1[0x14d];

      iVar8 = *piVar7;

      pfStack_15c = (float *)0x84b98c;

      pfStack_15c = (float *)(**(code **)(*piVar7 + 0x2d8))();

      fStack_160 = 1.2188863e-38;

      fStack_160 = (float)(**(code **)(*piVar7 + 0x2c8))();

      pcStack_164 = "i_g_2d_overlay_broken.dds";

      pcStack_168 = (char *)0x84b9a6;

      (**(code **)(iVar8 + 0x50))();

      fVar3 = local_148;

    }

    pfStack_15c = (float *)0x84b9b5;

    uStack_132 = FUN_00845b40();

    pfStack_15c = (float *)0x84b9c4;

    uStack_131 = FUN_00845af0();

    local_148 = (float)(int)((float)DAT_00d1e818 * *(float *)((int)param_1[0x14b] + 0x254) *

                            DAT_00aaa67c);

    iStack_144 = (int)((float)DAT_00d1e81c * *(float *)((int)param_1[0x14b] + 600) * DAT_00aaa678);

    pfStack_15c = &local_148;

    fStack_160 = 1.2189062e-38;

    (**(code **)(*(int *)param_1[0x14b] + 300))();

    fStack_160 = 1.4013e-45;

    pcStack_164 = &stack0xfffffeb4;

    pcStack_168 = (char *)0x84ba3a;

    puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x14f] + 0x140))();

    uStack_124 = *puVar5;

    uStack_120 = puVar5[1];

    pcStack_168 = (char *)0x84ba55;

    (**(code **)(*(int *)param_1[0x14f] + 0x268))();

    if (DAT_00d1791c != '\0') {

      if (DAT_00d1b6d8 == 0) {

        local_148 = 0.0;

      }

      else {

        pcStack_168 = (char *)param_1[0x146];

        dStack_170 = (double)CONCAT44(0x84ba7d,uVar6);

        fVar16 = (float10)FUN_0052e640();

        local_148 = (float)fVar16;

      }

      local_148 = local_148 * DAT_00aaa7ac;

      if (DAT_00aaa7ac < local_148) {

        local_148 = DAT_00aaa7ac;

      }

      pcStack_168 = (char *)0xffffffff;

      dStack_170 = 1.611601007019218e-305;

      pcStack_168 = (char *)FUN_007a6de0();

      dStack_170 = (double)local_148;

      ppfStack_17c = (float **)0x84bace;

      sprintf(acStack_114,"%.01f%% %s");

      pcStack_168 = (char *)0xffffff33;

      dStack_170 = (double)CONCAT44(acStack_114,0x84bae9);

      (**(code **)(*(int *)param_1[0x14f] + 0x224))();

    }

    if ((((uint)((int *)param_1[0x146])[0x5f] >> 0x13 & 1) == 0) && (DAT_00d1791c == '\0')) {

      iVar8 = *(int *)param_1[0x14f];

      pcStack_168 = (char *)0x84bb15;

      (**(code **)(*(int *)param_1[0x146] + 0x15c))();

      dStack_170 = (double)CONCAT44(0x84bb1d,uVar6);

      pcStack_168 = (char *)fVar3;

      pcStack_168 = (char *)FUN_007a6a30();

      dStack_170 = (double)CONCAT44(0x84bb2a,uVar6);

      (**(code **)(iVar8 + 0x250))();

    }

    else {

      pcStack_168 = (char *)0xffffffff;

      dStack_170 = (double)CONCAT44(0x84bb3c,uVar6);

      uVar6 = (**(code **)(*(int *)param_1[0x146] + 0x15c))();

      dStack_170 = (double)CONCAT44(uVar6,0x84bb44);

      pcStack_168 = (char *)FUN_007a6de0();

      dStack_170 = -NAN;

      uVar6 = FUN_007a6de0();

      dStack_170 = (double)CONCAT44(uVar6,"%s: %s");

      sprintf(acStack_114,"%s: %s");

      pcStack_168 = acStack_114;

      dStack_170 = (double)CONCAT44(0x84bb76,uVar6);

      (**(code **)(*(int *)param_1[0x14f] + 0x250))();

    }

    iVar8 = *(int *)param_1[0x14f];

    dStack_170 = (double)CONCAT44(&stack0xfffffea8,0x84bb8e);

    uVar6 = FUN_00514050();

    dStack_170 = (double)CONCAT44(uVar6,1);

    (**(code **)(iVar8 + 0x15c))();

    fStack_160 = (float)DAT_00d1e81c * *(float *)((int)param_1[0x14f] + 600) * DAT_00aaa678;

    ppfStack_17c = (float **)0x84bbd6;

    piVar7 = (int *)(**(code **)(*(int *)param_1[0x14b] + 0x140))();

    pfStack_15c = (float *)(*piVar7 + -10);

    ppfStack_17c = &pfStack_15c;

    ppcStack_180 = (char **)0x84bbfc;

    (**(code **)(*(int *)param_1[0x14f] + 300))();

    ppcStack_180 = &pcStack_16c;

    dStack_170 = (double)CONCAT44(5,uVar6);

    pcStack_168 = (char *)0x6;

    iStack_184 = 0x84bc20;

    (**(code **)(*(int *)param_1[0x14f] + 0x110))();

    iStack_184 = 0x84bc2e;

    (**(code **)(*(int *)param_1[0x14f] + 0x13c))();

    piVar7 = (int *)param_1[0x14f];

    iStack_184 = 0;

    uStack_188 = 1;

    puStack_18c = &stack0xfffffea8;

    uStack_190 = 0x84bc46;

    ppfStack_17c = (float **)(**(code **)(*piVar7 + 0x120))();

    uStack_190 = 1;

    puStack_194 = (uint8_t *)&stack0xfffffe90;

    piStack_198 = (int *)0x84bc5b;

    iVar8 = (**(code **)(*piVar7 + 0x140))();

    iVar8 = *(int *)(iStack_184 + 4) + 1 + *(int *)(iVar8 + 4);

    piStack_198 = (int *)0x84bc77;

    (**(code **)(*(int *)param_1[0x151] + 0x268))();

    piStack_198 = (int *)param_1[0x146];

    ppcStack_19c = (char **)param_1[0x151];

    ppuStack_1a0 = (uint8_t **)0x84bc8a;

    iVar9 = FUN_00845880();

    if (iVar9 < 1) {

      piStack_198 = &iStack_184;

      iStack_184 = 0;

      ppcStack_180 = (char **)0x0;

      ppcStack_19c = (char **)0x84bd6d;

      (**(code **)(*(int *)param_1[0x151] + 300))();

      ppcStack_19c = (char **)0x0;

      ppuStack_1a0 = (uint8_t **)0x84bd7c;

      (**(code **)(*(int *)param_1[0x151] + 0xcc))();

    }

    else {

      piStack_198 = (int *)0x1;

      ppcStack_19c = &pcStack_16c;

      ppuStack_1a0 = (uint8_t **)0x84bcaa;

      piVar7 = (int *)(**(code **)(*(int *)param_1[0x14f] + 0x140))();

      puStack_18c = (uint8_t *)*piVar7;

      ppuStack_1a0 = &puStack_18c;

      uStack_188 = 0;

      uStack_1a4 = 0x84bcc4;

      (**(code **)(*(int *)param_1[0x151] + 8))();

      uStack_1a4 = 0x84bcd2;

      (**(code **)(*(int *)param_1[0x151] + 0x13c))();

      uStack_1a4 = 1;

      uStack_1a8 = 0x84bce2;

      (**(code **)(*(int *)param_1[0x151] + 0xcc))();

      uStack_1a8 = 0;

      uStack_1ac = 1;

      pppiStack_1b0 = (int ***)&ppfStack_17c;

      pppuStack_1b4 = (uint8_t ***)0x84bcf8;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x14f] + 0x120))();

      ppuStack_1a0 = (uint8_t **)*puVar5;

      pppuStack_1b4 = &ppuStack_1a0;

      iStack_1b8 = 0x84bd15;

      ppcStack_19c = (char **)iVar8;

      (**(code **)(*(int *)param_1[0x151] + 0x118))();

      piVar7 = (int *)param_1[0x151];

      iStack_1b8 = 0;

      uStack_1bc = 1;

      ppuStack_1c0 = &puStack_18c;

      uStack_1c4 = 0x84bd2d;

      pppiStack_1b0 = (int ***)(**(code **)(*piVar7 + 0x120))();

      uStack_1c4 = 1;

      puStack_1c8 = &uStack_1a4;

      piStack_1cc = (int *)0x84bd42;

      iVar8 = (**(code **)(*piVar7 + 0x140))();

      iVar8 = *(int *)(iStack_1b8 + 4) + 1 + *(int *)(iVar8 + 4);

    }

    piStack_1cc = &iStack_1b8;

    iStack_1b8 = 5;

    uStack_1d0 = 0x84bd97;

    pppuStack_1b4 = (uint8_t ***)iVar8;

    (**(code **)(*(int *)param_1[0x14d] + 0x110))();

    uStack_1d0 = 0;

    uStack_1d4 = 1;

    puStack_1d8 = &uStack_1a4;

    uStack_1dc = 0x84bdad;

    iVar9 = (**(code **)(*(int *)param_1[0x14d] + 0x120))();

    uVar13 = *(uint32_t /* width from decompiler */ *)(iVar9 + 4);

    uStack_1dc = 0;

    uStack_1e0 = 1;

    puStack_1e4 = &uStack_1bc;

    puStack_1e8 = (uint32_t /* width from decompiler */ *)0x84bdc6;

    puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x14d] + 0x120))();

    uStack_1d4 = *puVar5;

    puStack_1e8 = &uStack_1d4;

    uStack_1ec = 0x84bde3;

    uStack_1d0 = uVar13;

    (**(code **)(*(int *)param_1[0x14e] + 0x110))();

    uStack_1ec = 0x84bdf1;

    (**(code **)(*(int *)param_1[0x150] + 0x268))();

    uStack_1f0 = (uint8_t ***)param_1[0x146];

    uStack_1ec = 1;

    uStack_1f4 = 0x84be05;

    FUN_00847240();

    uStack_1ec = 1;

    uStack_1f0 = &ppuStack_1c0;

    uStack_1f4 = 0x84be1d;

    piVar7 = (int *)(**(code **)(*(int *)param_1[0x14e] + 0x140))();

    uStack_1f4 = 1;

    puStack_1f8 = &uStack_1d4;

    ppuStack_1fc = (uint32_t /* width from decompiler */ **)0x84be34;

    piVar10 = (int *)(**(code **)(*(int *)param_1[0x14f] + 0x140))();

    ppuStack_1fc = &puStack_1e8;

    puStack_1e8 = (uint32_t /* width from decompiler */ *)((*piVar10 - *piVar7) + -1);

    puStack_1e4 = (uint32_t /* width from decompiler */ *)0x0;

    iStack_200 = 0x84be56;

    (**(code **)(*(int *)param_1[0x150] + 300))();

    iStack_200 = 0x84be64;

    (**(code **)(*(int *)param_1[0x150] + 0x13c))();

    iStack_200 = 0;

    uStack_204 = 1;

    puStack_208 = &uStack_1d4;

    uStack_20c = 0x84be7a;

    piVar7 = (int *)(**(code **)(*(int *)param_1[0x14e] + 0x120))();

    uStack_20c = 1;

    puStack_210 = &uStack_1ec;

    piStack_214 = (int *)0x84be91;

    piVar10 = (int *)(**(code **)(*(int *)param_1[0x14e] + 0x140))();

    iStack_200 = *piVar7 + 1 + *piVar10;

    piStack_214 = &iStack_200;

    uStack_218 = 0x84beb4;

    ppuStack_1fc = (uint32_t /* width from decompiler */ **)iVar8;

    (**(code **)(*(int *)param_1[0x150] + 0x118))();

    if (uStack_1f0._3_1_ == '\0') {

      uStack_218 = 0;

      uStack_21c = 0x84c040;

      (**(code **)(*(int *)param_1[0x157] + 0xcc))();

      uStack_21c = 0;

      fStack_220 = 1.2191273e-38;

      (**(code **)(*(int *)param_1[0x158] + 0xcc))();

    }

    else {

      uStack_218 = 1;

      uStack_21c = 0x84bece;

      (**(code **)(*(int *)param_1[0x157] + 0xcc))();

      uStack_21c = 1;

      fStack_220 = 1.2190756e-38;

      (**(code **)(*(int *)param_1[0x158] + 0xcc))();

      fStack_220 = 1.2190775e-38;

      iVar8 = (**(code **)(*(int *)param_1[0x146] + 0x1e0))();

      if (iVar8 != 0) {

        fStack_220 = 1.21908e-38;

        iVar8 = (**(code **)(*(int *)param_1[0x146] + 0x1e0))();

        fStack_220 = *(float *)(iVar8 + 0xdc);

        iVar8 = *(int *)param_1[0x157];

        uStack_224 = 0x84bf12;

        fVar16 = (float10)FUN_0040d0a0();

        fStack_220 = (float)(fVar16 * (float10)_DAT_00aaa99c);

        uStack_224 = 0x84bf23;

        (**(code **)(iVar8 + 0x3ac))();

        uStack_224 = 0x84bf31;

        iVar8 = (**(code **)(*(int *)param_1[0x146] + 0x1e0))();

        uStack_224 = *(uint32_t /* width from decompiler */ *)(iVar8 + 0xe8);

        puStack_228 = (uint32_t /* width from decompiler */ *)0x84bf46;

        (**(code **)(*(int *)param_1[0x157] + 0x3b0))();

      }

      if (DAT_00d1b6d8 != 0) {

        iVar8 = *(int *)param_1[0x157];

        fStack_220 = 1.2190973e-38;

        fStack_220 = (float)FUN_00930ea0();

        uStack_224 = 0;

        puStack_228 = (uint32_t /* width from decompiler */ *)0x84bf83;

        (**(code **)(iVar8 + 0x15c))();

      }

      piVar7 = (int *)param_1[0x14e];

      fStack_220 = 0.0;

      uStack_224 = 1;

      puStack_228 = &uStack_1f4;

      uStack_22c = 0x84bf9b;

      iVar9 = (**(code **)(*piVar7 + 0x120))();

      uStack_22c = 1;

      puStack_230 = &uStack_20c;

      uStack_234 = 0x84bfae;

      iVar8 = (**(code **)(*piVar7 + 0x140))();

      iVar8 = *(int *)(iVar8 + 4);

      iVar9 = *(int *)(iVar9 + 4);

      uStack_234 = 0;

      uStack_238 = 1;

      piStack_23c = &iStack_200;

      puStack_240 = (uint32_t /* width from decompiler */ *)0x84bfce;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x14e] + 0x120))();

      uStack_22c = *puVar5;

      puStack_240 = &uStack_22c;

      uStack_244 = 0x84bfeb;

      puStack_228 = (uint32_t /* width from decompiler */ *)(iVar9 + 1 + iVar8);

      (**(code **)(*(int *)param_1[0x157] + 0x110))();

      uStack_244 = 0;

      uStack_248 = 1;

      ppuStack_24c = &puStack_210;

      uStack_250 = 0x84c001;

      iVar8 = (**(code **)(*(int *)param_1[0x157] + 0x120))();

      uVar13 = *(uint32_t /* width from decompiler */ *)(iVar8 + 4);

      uStack_250 = 0;

      uStack_254 = 1;

      puStack_258 = &uStack_224;

      puStack_25c = (uint *)0x84c01a;

      puVar11 = (uint *)(**(code **)(*(int *)param_1[0x157] + 0x120))();

      uStack_248 = *puVar11;

      puStack_25c = &uStack_248;

      uStack_260 = 0x84c037;

      uStack_244 = uVar13;

      (**(code **)(*(int *)param_1[0x158] + 0x110))();

    }

    uStack_260 = 0x84c05d;

    (**(code **)(*(int *)param_1[0x152] + 0x268))();

    uStack_260 = 0x84c06b;

    (**(code **)(*(int *)param_1[0x155] + 0x268))();

    if (DAT_00d1b6d8 != 0) {

      uVar4 = *(uint *)((int)param_1[0x146] + 0x160);

      uStack_248 = *(uint *)((int)param_1[0x146] + 0x164);

      if ((uVar4 & uStack_248) != 0xffffffff) {

        uVar14 = 0;

        do {

          if ((*(uint *)(DAT_00d1b6d8 + 0x5a0 + (uVar14 & 0xff) * 8) == uVar4) &&

             (*(uint *)(DAT_00d1b6d8 + 0x5a4 + (uVar14 & 0xff) * 8) == uStack_248)) {

            DAT_00d1791c = '\x01';

            break;

          }

          uVar14 = uVar14 + 1;

        } while ((int)uVar14 < 8);

      }

    }

    puStack_268 = (uint32_t /* width from decompiler */ *)param_1[0x146];

    uStack_260 = 0;

    uStack_264 = 1;

    uStack_26c = 0x84c0e1;

    UI_BuildItemTooltipStats();

    piVar7 = (int *)param_1[0x151];

    uStack_260 = 0;

    uStack_264 = 1;

    puStack_268 = &uStack_22c;

    uStack_26c = 0x84c0fc;

    iVar9 = (**(code **)(*piVar7 + 0x120))();

    uStack_26c = 1;

    ppuStack_270 = &puStack_240;

    uStack_274 = 0x84c10f;

    iVar8 = (**(code **)(*piVar7 + 0x140))();

    iVar8 = *(int *)(iVar8 + 4);

    iVar9 = *(int *)(iVar9 + 4);

    uStack_274 = 0;

    uStack_278 = 1;

    puStack_27c = &uStack_254;

    puStack_280 = (uint32_t /* width from decompiler */ *)0x84c12f;

    puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x152] + 0x120))();

    uStack_26c = *puVar5;

    puStack_280 = &uStack_26c;

    uStack_284 = 0x84c14c;

    puStack_268 = (uint32_t /* width from decompiler */ *)(iVar9 + 2 + iVar8);

    (**(code **)(*(int *)param_1[0x152] + 0x118))();

    uStack_284 = 1;

    puStack_288 = &uStack_250;

    puStack_28c = (uint32_t /* width from decompiler */ *)0x84c161;

    puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x150] + 0x140))();

    uStack_278 = *puVar5;

    puStack_28c = &uStack_278;

    uStack_274 = 0;

    uStack_290 = 0x84c17e;

    (**(code **)(*(int *)param_1[0x152] + 300))();

    piVar7 = (int *)param_1[0x150];

    uStack_290 = 0;

    uStack_294 = 1;

    ppuStack_298 = &puStack_25c;

    uStack_29c = 0x84c196;

    iVar9 = (**(code **)(*piVar7 + 0x120))();

    uStack_29c = 1;

    uStack_2a0 = &ppuStack_270;

    uStack_2a4 = 0x84c1a9;

    iVar8 = (**(code **)(*piVar7 + 0x140))();

    iVar8 = *(int *)(iVar8 + 4);

    iVar9 = *(int *)(iVar9 + 4);

    uStack_2a4 = 0;

    uStack_2a8 = 1;

    puStack_2ac = &uStack_284;

    puStack_2b0 = (uint32_t /* width from decompiler */ *)0x84c1c9;

    puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x150] + 0x120))();

    uStack_29c = *puVar5;

    puStack_2b0 = &uStack_29c;

    uStack_2b4 = 0x84c1e6;

    ppuStack_298 = (uint **)(iVar9 + 1 + iVar8);

    (**(code **)(*(int *)param_1[0x152] + 0x110))();

    uStack_2b4 = 0x84c1f4;

    (**(code **)(*(int *)param_1[0x152] + 0x13c))();

    uStack_2b4 = 1;

    ppuStack_2b8 = &puStack_280;

    uStack_2bc = 0x84c209;

    iVar8 = (**(code **)(*(int *)param_1[0x152] + 0x140))();

    uVar13 = *(uint32_t /* width from decompiler */ *)(iVar8 + 4);

    uStack_2bc = 1;

    puStack_2c0 = &uStack_290;

    ppuStack_2c4 = (uint32_t /* width from decompiler */ **)0x84c221;

    puStack_2b0 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x150] + 0x140))();

    puStack_2b0 = (uint32_t /* width from decompiler */ *)*puStack_2b0;

    ppuStack_2c4 = &puStack_2b0;

    uStack_2c8 = 0x84c23e;

    puStack_2ac = (uint32_t /* width from decompiler */ *)uVar13;

    (**(code **)(*(int *)param_1[0x152] + 300))();

    if (uStack_2a0._2_1_ == '\0') {

      uStack_2c8 = 0;

      uStack_2cc = 0x84c31c;

      (**(code **)(*(int *)param_1[0x155] + 4))();

    }

    else {

      uStack_2c8 = 0x84c259;

      FUN_00845be0();

      piVar7 = (int *)param_1[0x152];

      uStack_2c8 = 0;

      uStack_2cc = 1;

      puStack_2d0 = &uStack_294;

      uStack_2d4 = 0x84c271;

      iVar9 = (**(code **)(*piVar7 + 0x120))();

      uStack_2d4 = 1;

      puStack_2d8 = &uStack_2a8;

      uStack_2dc = 0x84c284;

      iVar8 = (**(code **)(*piVar7 + 0x140))();

      iVar8 = *(int *)(iVar8 + 4);

      iVar9 = *(int *)(iVar9 + 4);

      uStack_2dc = 0;

      uStack_2e0 = 1;

      puStack_2e4 = &uStack_2bc;

      puStack_2e8 = (uint32_t /* width from decompiler */ *)0x84c2a4;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x152] + 0x120))();

      uStack_2d4 = *puVar5;

      puStack_2e8 = &uStack_2d4;

      uStack_2ec = 0x84c2c1;

      puStack_2d0 = (uint32_t /* width from decompiler */ *)(iVar9 + 1 + iVar8);

      (**(code **)(*(int *)param_1[0x155] + 0x110))();

      uStack_2ec = 1;

      pppuStack_2f0 = &ppuStack_2b8;

      puStack_2f4 = (uint32_t /* width from decompiler */ *)0x84c2d6;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x152] + 0x140))();

      uStack_2e0 = *puVar5;

      puStack_2f4 = &uStack_2e0;

      uStack_2dc = 0;

      uStack_2f8 = 0x84c2f3;

      (**(code **)(*(int *)param_1[0x155] + 300))();

      uStack_2f8 = 0x84c301;

      (**(code **)(*(int *)param_1[0x155] + 0x13c))();

      uStack_2f8 = 1;

      uStack_2fc = 0x84c30e;

      (**(code **)(*(int *)param_1[0x155] + 4))();

    }

    uStack_2fc = 0x84c32a;

    (**(code **)(*(int *)param_1[0x153] + 0x268))();

    uStack_2fc = 1;

    puStack_300 = &uStack_2c8;

    pppuStack_304 = (uint32_t /* width from decompiler */ ***)0x84c33f;

    puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x14e] + 0x140))();

    pppuStack_2f0 = (uint32_t /* width from decompiler */ ***)*puVar5;

    pppuStack_304 = &pppuStack_2f0;

    uStack_2ec = 0;

    uStack_308 = 0x84c35c;

    (**(code **)(*(int *)param_1[0x153] + 300))();

    uStack_308 = 0;

    puStack_310 = &uStack_2d4;

    uStack_30c = 1;

    if (uStack_2e0._3_1_ == '\0') {

      piVar7 = (int *)param_1[0x14e];

      uStack_314 = 0x84c3af;

      iVar8 = (**(code **)(*piVar7 + 0x120))();

      uStack_314 = 1;

      ppuStack_318 = &puStack_2e8;

      uStack_31c = 0x84c3c2;

      iVar9 = (**(code **)(*piVar7 + 0x140))();

      iVar8 = *(int *)(iVar8 + 4) + 1 + *(int *)(iVar9 + 4);

      piVar7 = (int *)param_1[0x14e];

    }

    else {

      piVar7 = (int *)param_1[0x158];

      uStack_314 = 0x84c37a;

      iVar8 = (**(code **)(*piVar7 + 0x120))();

      uStack_314 = 1;

      ppuStack_318 = &puStack_2e8;

      uStack_31c = 0x84c38d;

      iVar9 = (**(code **)(*piVar7 + 0x140))();

      iVar8 = *(int *)(iVar8 + 4) + 1 + *(int *)(iVar9 + 4);

      piVar7 = (int *)param_1[0x158];

    }

    uStack_31c = 0;

    uStack_324 = &uStack_2fc;

    uStack_320 = 1;

    puStack_328 = (uint32_t /* width from decompiler */ *)0x84c3e2;

    puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar7 + 0x120))();

    uStack_314 = *puVar5;

    puStack_328 = &uStack_314;

    uStack_32c = 0x84c3ff;

    puStack_310 = (uint32_t /* width from decompiler */ *)iVar8;

    (**(code **)(*(int *)param_1[0x153] + 0x110))();

    puStack_330 = (uint32_t /* width from decompiler */ *)param_1[0x153];

    uStack_32c = 1;

    uStack_334 = 0x84c413;

    FUN_00845360();

    uStack_32c = 0x84c424;

    (**(code **)(*(int *)param_1[0x153] + 0x13c))();

    uStack_32c = 1;

    puStack_330 = &uStack_2f8;

    uStack_334 = 0x84c439;

    iVar8 = (**(code **)(*(int *)param_1[0x153] + 0x140))();

    uVar13 = *(uint32_t /* width from decompiler */ *)(iVar8 + 4);

    uStack_334 = 1;

    puStack_338 = &uStack_308;

    ppuStack_33c = (uint32_t /* width from decompiler */ **)0x84c451;

    puStack_328 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x14e] + 0x140))();

    puStack_328 = (uint32_t /* width from decompiler */ *)*puStack_328;

    ppuStack_33c = &puStack_328;

    uStack_340 = 0x84c46e;

    uStack_324 = (uint32_t /* width from decompiler */ *)uVar13;

    (**(code **)(*(int *)param_1[0x153] + 300))();

    uStack_340 = 0x84c47c;

    (**(code **)(*(int *)param_1[0x154] + 0x268))();

    uStack_340 = 1;

    puStack_344 = &uStack_30c;

    puStack_348 = (uint32_t /* width from decompiler */ *)0x84c491;

    puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x152] + 0x140))();

    uStack_334 = *puVar5;

    puStack_348 = &uStack_334;

    puStack_330 = (uint32_t /* width from decompiler */ *)0x0;

    uStack_34c = 0x84c4ae;

    (**(code **)(*(int *)param_1[0x154] + 300))();

    uStack_34c = 0;

    pppuStack_354 = &ppuStack_318;

    uStack_350 = 1;

    if (uStack_324._2_1_ == '\0') {

      piVar7 = (int *)param_1[0x152];

      uStack_358 = 0x84c501;

      iVar8 = (**(code **)(*piVar7 + 0x120))();

      uStack_358 = 1;

      puStack_35c = &uStack_32c;

      uStack_360 = 0x84c514;

      iVar9 = (**(code **)(*piVar7 + 0x140))();

      iVar8 = *(int *)(iVar8 + 4) + 1 + *(int *)(iVar9 + 4);

      piVar7 = (int *)param_1[0x152];

    }

    else {

      piVar7 = (int *)param_1[0x155];

      uStack_358 = 0x84c4cc;

      iVar8 = (**(code **)(*piVar7 + 0x120))();

      uStack_358 = 1;

      puStack_35c = &uStack_32c;

      uStack_360 = 0x84c4df;

      iVar9 = (**(code **)(*piVar7 + 0x140))();

      iVar8 = *(int *)(iVar8 + 4) + 1 + *(int *)(iVar9 + 4);

      piVar7 = (int *)param_1[0x155];

    }

    uStack_360 = 0;

    puStack_368 = &uStack_340;

    uStack_364 = 1;

    puStack_36c = (uint32_t /* width from decompiler */ *)0x84c534;

    puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar7 + 0x120))();

    uStack_358 = *puVar5;

    puStack_36c = &uStack_358;

    uStack_370 = 0x84c551;

    pppuStack_354 = (uint32_t /* width from decompiler */ ***)iVar8;

    (**(code **)(*(int *)param_1[0x154] + 0x110))();

    pppuStack_374 = (uint32_t /* width from decompiler */ ***)param_1[0x154];

    uStack_370 = 1;

    puStack_378 = (uint32_t /* width from decompiler */ *)0x84c565;

    FUN_0084b770();

    uStack_370 = 0x84c576;

    (**(code **)(*(int *)param_1[0x154] + 0x13c))();

    uStack_370 = 1;

    pppuStack_374 = &ppuStack_33c;

    puStack_378 = (uint32_t /* width from decompiler */ *)0x84c58b;

    iVar8 = (**(code **)(*(int *)param_1[0x154] + 0x140))();

    puVar5 = *(uint32_t /* width from decompiler */ **)(iVar8 + 4);

    puStack_378 = (uint32_t /* width from decompiler */ *)0x1;

    puStack_37c = &uStack_34c;

    ppuStack_380 = (uint32_t /* width from decompiler */ **)0x84c5a3;

    puStack_36c = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x152] + 0x140))();

    puStack_36c = (uint32_t /* width from decompiler */ *)*puStack_36c;

    ppuStack_380 = &puStack_36c;

    ppuStack_384 = (uint32_t /* width from decompiler */ ***)0x84c5c0;

    puStack_368 = puVar5;

    (**(code **)(*(int *)param_1[0x154] + 300))();

    piVar7 = (int *)param_1[0x154];

    piVar10 = (int *)param_1[0x153];

    ppuStack_384 = (uint32_t /* width from decompiler */ ***)0x0;

    uStack_388 = 1;

    puStack_38c = &uStack_350;

    uStack_390 = 0x84c5e1;

    puStack_37c = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar7 + 0x120))();

    uStack_390 = 1;

    puStack_394 = &uStack_364;

    uStack_398 = 0x84c5f6;

    iVar8 = (**(code **)(*piVar7 + 0x140))();

    ppuVar1 = (uint32_t /* width from decompiler */ **)ppuStack_384[1];

    iVar8 = *(int *)(iVar8 + 4);

    uStack_398 = 0;

    uStack_39c = 1;

    ppuStack_3a0 = &puStack_378;

    iStack_3a4 = 0x84c613;

    iVar9 = (**(code **)(*piVar10 + 0x120))();

    iStack_3a4 = 1;

    ppuStack_3a8 = &puStack_368;

    uStack_3ac = 0x84c626;

    iVar12 = (**(code **)(*piVar10 + 0x140))();

    puStack_3b4 = &uStack_370;

    uStack_3ac = 0;

    uStack_3b0 = 1;

    if (*(int *)(iVar9 + 4) + *(int *)(iVar12 + 4) < (int)ppuVar1 + iVar8) {

      piVar7 = (int *)param_1[0x154];

      uStack_3b8 = 0x84c649;

      iVar8 = (**(code **)(*piVar7 + 0x120))();

      uStack_3b8 = 1;

      ppuStack_3bc = &ppuStack_384;

      puStack_3c0 = (uint32_t /* width from decompiler */ *)0x84c65c;

      iVar9 = (**(code **)(*piVar7 + 0x140))();

      ppppuVar15 = (uint32_t /* width from decompiler */ ****)(*(int *)(iVar8 + 4) + *(int *)(iVar9 + 4));

      puStack_3c0 = (uint32_t /* width from decompiler */ *)0x0;

      uStack_3c4 = 1;

      pppuStack_3c8 = &ppuStack_384;

      uStack_3cc = 0x84c679;

      iVar8 = (**(code **)(*(int *)param_1[0x153] + 0x120))();

      iVar8 = *(int *)(iVar8 + 4);

      uStack_3cc = 1;

      puStack_3d0 = &uStack_398;

      ppuStack_3d4 = (uint32_t /* width from decompiler */ **)0x84c693;

      piVar7 = (int *)(**(code **)(*(int *)param_1[0x153] + 0x140))();

      puStack_3c0 = (uint32_t /* width from decompiler */ *)*piVar7;

      ppuStack_3d4 = &puStack_3c0;

      pppuStack_3d8 = (uint32_t /* width from decompiler */ ***)0x84c6b0;

      ppuStack_3bc = (uint32_t /* width from decompiler */ ***)((int)ppppuVar15 - iVar8);

      (**(code **)(*(int *)param_1[0x153] + 300))();

    }

    else {

      piVar7 = (int *)param_1[0x153];

      uStack_3b8 = 0x84c6c5;

      iVar8 = (**(code **)(*piVar7 + 0x120))();

      uStack_3b8 = 1;

      ppuStack_3bc = &ppuStack_384;

      puStack_3c0 = (uint32_t /* width from decompiler */ *)0x84c6d8;

      iVar9 = (**(code **)(*piVar7 + 0x140))();

      piVar7 = (int *)param_1[0x154];

      ppppuVar15 = (uint32_t /* width from decompiler */ ****)(*(int *)(iVar8 + 4) + *(int *)(iVar9 + 4));

      puStack_3c0 = (uint32_t /* width from decompiler */ *)0x0;

      uStack_3c4 = 1;

      if (uStack_398._2_1_ == '\0') {

        piVar10 = (int *)param_1[0x152];

        pppuStack_3c8 = &pppuStack_374;

        uStack_3cc = 0x84c76d;

        uStack_3b8 = (**(code **)(*piVar7 + 0x120))();

        uStack_3cc = 1;

        puStack_3d0 = &uStack_390;

        ppuStack_3d4 = (uint32_t /* width from decompiler */ **)0x84c782;

        iVar8 = (**(code **)(*piVar10 + 0x140))();

        iVar8 = *(int *)(iVar8 + 4);

        iVar9 = puStack_3c0[1];

        ppuStack_3d4 = (uint32_t /* width from decompiler */ **)0x1;

        pppuStack_3d8 = &ppuStack_3a0;

        pppuStack_3dc = (uint32_t /* width from decompiler */ ***)0x84c79d;

        iVar12 = (**(code **)(*piVar7 + 0x140))();

        iVar8 = (iVar8 - iVar9) - *(int *)(iVar12 + 4);

        pppuStack_3dc = (uint32_t /* width from decompiler */ ***)0x1;

        puStack_3e0 = &uStack_3b0;

        puStack_3e4 = (uint32_t /* width from decompiler */ *)0x84c7b7;

        puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x152] + 0x140))();

        uStack_3c4 = *puVar5;

        piVar7 = (int *)param_1[0x152];

      }

      else {

        piVar10 = (int *)param_1[0x155];

        pppuStack_3c8 = &ppuStack_384;

        uStack_3cc = 0x84c704;

        uStack_3b8 = (**(code **)(*piVar7 + 0x120))();

        uStack_3cc = 1;

        puStack_3d0 = &uStack_398;

        ppuStack_3d4 = (uint32_t /* width from decompiler */ **)0x84c719;

        iVar8 = (**(code **)(*piVar10 + 0x140))();

        iVar8 = *(int *)(iVar8 + 4);

        iVar9 = puStack_3c0[1];

        ppuStack_3d4 = (uint32_t /* width from decompiler */ **)0x1;

        pppuStack_3d8 = &ppuStack_3a8;

        pppuStack_3dc = (uint32_t /* width from decompiler */ ***)0x84c734;

        iVar12 = (**(code **)(*piVar7 + 0x140))();

        iVar8 = (iVar8 - iVar9) - *(int *)(iVar12 + 4);

        pppuStack_3dc = (uint32_t /* width from decompiler */ ***)0x1;

        puStack_3e0 = &uStack_390;

        puStack_3e4 = (uint32_t /* width from decompiler */ *)0x84c74e;

        puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x155] + 0x140))();

        uStack_3c4 = *puVar5;

        piVar7 = (int *)param_1[0x155];

      }

      puStack_3c0 = (uint32_t /* width from decompiler */ *)(iVar8 + (int)ppppuVar15);

      puStack_3e4 = &uStack_3c4;

      puStack_3e8 = (uint32_t /* width from decompiler */ *)0x84c7d4;

      (**(code **)(*piVar7 + 300))();

      puStack_3e8 = (uint32_t /* width from decompiler */ *)0x1;

      pppuStack_3ec = (uint32_t /* width from decompiler */ ***)&uStack_39c;

      puStack_3f0 = (uint32_t /* width from decompiler */ *)0x84c7e9;

      iVar8 = (**(code **)(*(int *)param_1[0x154] + 0x140))();

      puStack_3f0 = (uint32_t /* width from decompiler */ *)0x0;

      iVar8 = *(int *)(iVar8 + 4);

      uStack_3f4 = 1;

      puStack_3e8 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x154] + 0x120))(&puStack_3b4);

      puStack_3e8 = (uint32_t /* width from decompiler */ *)*puStack_3e8;

      puStack_3e4 = (uint32_t /* width from decompiler */ *)((int)ppppuVar15 - iVar8);

      (**(code **)(*(int *)param_1[0x154] + 0x110))(&puStack_3e8);

    }

    pppuStack_3d8 = (uint32_t /* width from decompiler */ ***)0x84c830;

    (**(code **)(*(int *)param_1[0x156] + 0x268))();

    if ((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1)) {

      pppuStack_3d8 = (uint32_t /* width from decompiler */ ***)&uStack_3c4;

      uStack_3c4 = 0;

      puStack_3c0 = (uint32_t /* width from decompiler */ *)0x0;

      pppuStack_3dc = (uint32_t /* width from decompiler */ ***)0x84c8ee;

      (**(code **)(*(int *)param_1[0x156] + 300))();

      pppuStack_3dc = (uint32_t /* width from decompiler */ ****)0x0;

      puStack_3e0 = (uint32_t /* width from decompiler */ *)0x84c8fd;

      (**(code **)(*(int *)param_1[0x156] + 0xcc))();

    }

    else {

      pppuStack_3d8 = (uint32_t /* width from decompiler */ ***)0x1;

      pppuStack_3dc = (uint32_t /* width from decompiler */ ***)0x84c85c;

      (**(code **)(*(int *)param_1[0x156] + 0xcc))();

      pppuStack_3c8 =

           (uint32_t /* width from decompiler */ ***)

           (int)((float)DAT_00d1e818 * (float)((int *)param_1[0x156])[0x95] * DAT_00aaa67c);

      pppuStack_3dc = &pppuStack_3c8;

      uStack_3c4 = 0;

      puStack_3e0 = (uint32_t /* width from decompiler */ *)0x84c893;

      (**(code **)(*(int *)param_1[0x156] + 300))();

      puStack_3e0 = (uint32_t /* width from decompiler */ *)0x84c8a4;

      FUN_008452f0();

      puStack_3e0 = (uint32_t /* width from decompiler */ *)0x84c8b2;

      (**(code **)(*(int *)param_1[0x156] + 0x13c))();

      puStack_3e0 = &uStack_3cc;

      uStack_3cc = 0;

      puStack_3e4 = (uint32_t /* width from decompiler */ *)0x84c8d1;

      pppuStack_3c8 = ppppuVar15;

      (**(code **)(*(int *)param_1[0x156] + 0x110))();

    }

    puStack_3e4 = (uint32_t /* width from decompiler */ *)0x1;

    puStack_3e8 = &uStack_398;

    pppuStack_3ec = (uint32_t /* width from decompiler */ ***)0x84c912;

    puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[0x14b] + 0x140))();

    ppuStack_3a8 = (uint32_t /* width from decompiler */ **)*puVar5;

    uStack_39c = puVar5[1];

    iStack_3a4 = (int)ppppuVar15 + 6;

    pppuStack_3ec = &ppuStack_3a8;

    puStack_3f0 = (uint32_t /* width from decompiler */ *)0x84c936;

    (**(code **)(*(int *)param_1[0x14b] + 8))();

    puStack_3f0 = (uint32_t /* width from decompiler */ *)0x84c944;

    cVar2 = (**(code **)(*(int *)param_1[0x156] + 0xd0))();

    if (cVar2 == '\0') {

      puStack_3f0 = &uStack_3ac;

      uStack_3f4 = 0x84c9a2;

      (**(code **)((int)*param_1 + 8))();

    }

    else {

      piVar7 = (int *)param_1[0x156];

      puStack_3f0 = (uint32_t /* width from decompiler */ *)0x0;

      uStack_3f4 = 1;

      iVar8 = (**(code **)(*piVar7 + 0x120))(&iStack_3a4);

      iVar9 = (**(code **)(*piVar7 + 0x140))(&puStack_3c0,1);

      pppuStack_3ec = (uint32_t /* width from decompiler */ ***)(*(int *)(iVar8 + 4) + *(int *)(iVar9 + 4));

      puStack_3f0 = puStack_3c0;

      (**(code **)((int)*param_1 + 8))(&puStack_3f0);

    }

    fVar3 = param_1[0x146];

    if (*(int *)(*(int *)((int)fVar3 + 0xa8) + 0x38) == 4) {

      puStack_3e8 = (uint32_t /* width from decompiler */ *)0xffffffff;

      (**(code **)(*(int *)param_1[0x14b] + 0x15c))(0,&puStack_3e8);

    }

    else {

      iVar8 = *(int *)param_1[0x14b];

      uVar13 = FUN_005140d0(&uStack_3f4,

                            CONCAT22((short)((uint)fVar3 >> 0x10),

                                     *(uint16_t *)

                                      (*(int *)(*(int *)((int)fVar3 + 0xa8) + 0x3c) + 0x4b8)));

      (**(code **)(iVar8 + 0x15c))(0,uVar13);

    }

    (**(code **)(*(int *)param_1[0x14b] + 0x34c))();

    if ((DAT_00d1791c == '\0') && (*(char *)(param_1 + 0x14a) == '\0')) {

      (**(code **)(*(int *)param_1[0x159] + 0x444))(param_1[0x146]);

      return;

    }

    (**(code **)(*(int *)param_1[0x159] + 0xcc))(0);

  }

  return;

}
