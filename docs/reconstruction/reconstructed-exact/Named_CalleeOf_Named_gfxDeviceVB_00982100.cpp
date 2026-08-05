// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_00982100
// -----------------------------------------------------------------------------
// Stable ID: aa_00982100
// Callee of Named_gfxDeviceVB
// Address:   0x00982100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~515 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: FUN_0046c300×15, FUN_0076f240×3, FUN_0076eb00×2, FUN_0076f5f0×2, SQRT×2, fcos×2, fsin×2, FUN_00982100.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxDeviceVB
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_gfxDeviceVB_00982100(int param_1)



{

  float fVar1;

  int iVar2;

  int extraout_EDX;

  int unaff_EBX;

  float10 fVar3;

  float10 fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float local_374;

  float local_370;

  float local_36c;

  float local_368;

  float local_364;

  float local_360;

  float local_35c;

  float local_358;

  float local_354;

  float local_350;

  float local_34c;

  float local_348;

  float local_344;

  float local_340;

  float local_33c;

  float local_338;

  float local_334;

  float local_330;

  float local_32c;

  float local_328;

  float local_324;

  float local_320;

  float local_31c;

  float local_318;

  float local_314;

  float local_310;

  float local_30c;

  int local_308;

  float local_304;

  float local_300;

  float local_2fc;

  float local_2f8;

  float local_2f4;

  float local_2f0;

  float local_2ec;

  float local_2e8;

  float local_2e4;

  float local_2e0;

  float local_2dc;

  float local_2d8;

  float local_2d4;

  float local_2d0;

  float local_2cc;

  float local_2c8;

  uint32_t /* width from decompiler */ local_2c4;

  float local_2c0;

  float local_2bc;

  float local_2b8;

  uint32_t /* width from decompiler */ local_2b4;

  float local_2b0;

  float local_2ac;

  float local_2a8;

  uint32_t /* width from decompiler */ local_2a4;

  float local_29c;

  float local_298;

  float local_294;

  float local_290;

  float local_28c;

  float local_288;

  float local_284;

  float local_280;

  float local_27c;

  float local_278;

  float local_274;

  float local_270;

  float local_26c;

  float local_268;

  float local_264;

  float local_260;

  float local_25c;

  float local_258;

  float local_254;

  float local_250;

  float local_24c;

  float local_248;

  float local_244;

  float local_240;

  float local_23c;

  float local_238;

  float local_234;

  float local_230;

  float local_22c;

  float local_228;

  float local_224;

  float local_220;

  float local_21c;

  float local_218;

  float local_214;

  float local_210;

  uint32_t /* width from decompiler */ local_20c;

  float local_208;

  uint32_t /* width from decompiler */ local_204;

  float local_200;

  float local_1fc;

  float local_1f8;

  float local_1f4;

  float local_1f0;

  float local_1ec;

  uint32_t /* width from decompiler */ local_1e8;

  float local_1e4;

  float local_1e0;

  float local_1dc;

  float local_1d8;

  float local_1d4;

  float local_1d0;

  float local_1cc;

  float local_1c8;

  uint32_t /* width from decompiler */ local_1c4;

  float local_1c0;

  float local_1bc;

  float local_1b8;

  float local_1b4;

  float local_1b0;

  float local_1ac;

  float local_1a8;

  float local_1a4;

  uint32_t /* width from decompiler */ local_1a0;

  float local_19c;

  float local_198;

  float local_194;

  float local_190;

  float local_18c;

  float local_188;

  float local_184;

  float local_180;

  uint32_t /* width from decompiler */ local_17c;

  float local_178;

  float local_174;

  float local_170;

  float local_16c;

  float local_168;

  float local_164;

  float local_160;

  float local_15c;

  uint32_t /* width from decompiler */ local_158;

  float local_154;

  uint32_t /* width from decompiler */ local_150;

  float local_14c;

  float local_148;

  float local_144;

  float local_140;

  float local_13c;

  float local_138;

  uint32_t /* width from decompiler */ local_134;

  float local_130;

  uint32_t /* width from decompiler */ local_12c;

  float local_128;

  float local_124;

  float local_120;

  float local_11c;

  float local_118;

  float local_114;

  uint32_t /* width from decompiler */ local_110;

  float local_10c;

  uint32_t /* width from decompiler */ local_108;

  float local_104;

  float local_100;

  float local_fc;

  float local_f8;

  float local_f4;

  float local_f0;

  uint32_t /* width from decompiler */ local_ec;

  float local_e8;

  float local_e4;

  float local_e0;

  float local_dc;

  float local_d8;

  float local_d4;

  float local_d0;

  float local_cc;

  uint32_t /* width from decompiler */ local_c8;

  float local_c4;

  uint32_t /* width from decompiler */ local_c0;

  float local_bc;

  float local_b8;

  float local_b4;

  float local_b0;

  float local_ac;

  float local_a8;

  uint32_t /* width from decompiler */ local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  uint32_t /* width from decompiler */ local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  uint32_t /* width from decompiler */ local_5c;

  float local_58;

  float local_54;

  uint8_t local_50 [76];

  

  fVar5 = DAT_00a1e8fc;

  if (*(void **)(unaff_EBX + 8) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_EBX + 8));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x10) = 0;

  fVar5 = fVar5 / (float)param_1;

  fVar6 = *(float *)(unaff_EBX + 0x38) + *(float *)(unaff_EBX + 0x34);

  local_2dc = *(float *)(unaff_EBX + 0x20) * fVar6 + *(float *)(unaff_EBX + 0x14);

  fVar9 = *(float *)(unaff_EBX + 0x34);

  fVar11 = *(float *)(unaff_EBX + 0x1c) + *(float *)(unaff_EBX + 0x28) * fVar6;

  fVar10 = *(float *)(unaff_EBX + 0x18) + *(float *)(unaff_EBX + 0x24) * fVar6;

  fVar6 = *(float *)(unaff_EBX + 0x18) + *(float *)(unaff_EBX + 0x24) * fVar9;

  fVar7 = *(float *)(unaff_EBX + 0x1c) + *(float *)(unaff_EBX + 0x28) * fVar9;

  local_304 = *(float *)(unaff_EBX + 0x14);

  local_300 = *(float *)(unaff_EBX + 0x18);

  local_2fc = *(float *)(unaff_EBX + 0x1c);

  fVar8 = *(float *)(unaff_EBX + 0x14) + fVar9 * *(float *)(unaff_EBX + 0x20);

  local_36c = *(float *)(unaff_EBX + 0x24) * 0.0;

  local_374 = local_36c - *(float *)(unaff_EBX + 0x28);

  local_370 = *(float *)(unaff_EBX + 0x28) * 0.0 - *(float *)(unaff_EBX + 0x20) * 0.0;

  local_36c = *(float *)(unaff_EBX + 0x20) - local_36c;

  fVar9 = fVar8;

  local_2d8 = fVar10;

  local_2d4 = fVar11;

  if (g_flMsToSeconds_Inferred <=

      local_374 * local_374 + local_36c * local_36c + local_370 * local_370) {

    FUN_0076f5f0(&local_374,&local_374);

  }

  else {

    local_374 = g_flOne;

    local_370 = 0.0;

    local_36c = 0.0;

  }

  local_348 = local_370 * *(float *)(unaff_EBX + 0x28) - *(float *)(unaff_EBX + 0x24) * local_36c;

  local_344 = *(float *)(unaff_EBX + 0x20) * local_36c - *(float *)(unaff_EBX + 0x28) * local_374;

  local_340 = *(float *)(unaff_EBX + 0x24) * local_374 - *(float *)(unaff_EBX + 0x20) * local_370;

  fVar1 = *(float *)(unaff_EBX + 0x30);

  fVar9 = local_2dc - (fVar1 * local_374 + fVar9);

  fVar10 = fVar10 - (local_370 * fVar1 + fVar6);

  fVar11 = fVar11 - (local_36c * fVar1 + fVar7);

  local_354 = local_340 * fVar10 - local_344 * fVar11;

  local_350 = fVar11 * local_348 - local_340 * fVar9;

  local_34c = local_344 * fVar9 - fVar10 * local_348;

  fVar11 = local_370;

  FUN_0076f5f0(&local_354,&local_354);

  fVar9 = *(float *)(unaff_EBX + 0x3c);

  local_354 = fVar9 * local_354;

  local_350 = local_350 * fVar9;

  local_34c = local_34c * fVar9;

  local_32c = local_374;

  local_324 = local_36c;

  local_308 = 1;

  if (0 < extraout_EDX) {

    local_35c = 0.0 - *(float *)(unaff_EBX + 0x20) * fVar9;

    local_358 = 0.0 - *(float *)(unaff_EBX + 0x24) * fVar9;

    local_364 = 0.0 - *(float *)(unaff_EBX + 0x28) * fVar9;

    local_338 = local_354;

    local_334 = local_350;

    local_330 = local_34c;

    local_328 = fVar11;

    local_280 = local_35c;

    local_27c = local_358;

    local_278 = local_364;

    do {

      local_360 = SQRT(*(float *)(unaff_EBX + 0x28) * *(float *)(unaff_EBX + 0x28) +

                       *(float *)(unaff_EBX + 0x24) * *(float *)(unaff_EBX + 0x24) +

                       *(float *)(unaff_EBX + 0x20) * *(float *)(unaff_EBX + 0x20));

      if ((_DAT_00a240ec <= local_360) || (local_360 <= DAT_00aaa640)) {

        local_248 = g_flOne / local_360;

        local_250 = *(float *)(unaff_EBX + 0x20) * local_248;

        local_24c = *(float *)(unaff_EBX + 0x24) * local_248;

        local_248 = *(float *)(unaff_EBX + 0x28) * local_248;

      }

      local_284 = (float)local_308;

      local_368 = local_284 * fVar5;

      local_2e0 = local_368 * DAT_00a0f298;

      fVar3 = (float10)fsin((float10)local_2e0);

      local_244 = (float)((float10)local_250 * fVar3);

      local_240 = (float)((float10)local_24c * fVar3);

      local_23c = (float)((float10)local_248 * fVar3);

      fVar3 = (float10)fcos((float10)local_2e0);

      local_238 = (float)fVar3;

      FUN_0076eb00(local_50,&local_244);

      local_2d0 = local_374;

      local_2cc = local_370;

      local_2c8 = local_36c;

      local_2c4 = 0;

      FUN_0076f240(&local_2d0);

      local_348 = local_2d0;

      local_344 = local_2cc;

      local_340 = local_2c8;

      local_2b0 = local_354;

      local_2ac = local_350;

      local_320 = local_2d0;

      local_2a8 = local_34c;

      local_31c = local_2cc;

      local_318 = local_2c8;

      local_2a4 = 0;

      FUN_0076f240(&local_2b0);

      fVar10 = local_2a8;

      fVar11 = local_2ac;

      fVar9 = local_2b0;

      local_314 = local_2b0;

      local_310 = local_2ac;

      local_30c = local_2a8;

      local_360 = SQRT(*(float *)(unaff_EBX + 0x28) * *(float *)(unaff_EBX + 0x28) +

                       *(float *)(unaff_EBX + 0x24) * *(float *)(unaff_EBX + 0x24) +

                       *(float *)(unaff_EBX + 0x20) * *(float *)(unaff_EBX + 0x20));

      if ((_DAT_00a240ec <= local_360) || (local_360 <= DAT_00aaa640)) {

        local_264 = g_flOne / local_360;

        local_26c = *(float *)(unaff_EBX + 0x20) * local_264;

        local_268 = local_264 * *(float *)(unaff_EBX + 0x24);

        local_264 = *(float *)(unaff_EBX + 0x28) * local_264;

      }

      fVar3 = ((float10)local_284 - (float10)DAT_00a0f298) * (float10)fVar5 * (float10)DAT_00a0f298;

      fVar4 = (float10)fsin(fVar3);

      local_234 = (float)((float10)local_26c * fVar4);

      local_230 = (float)((float10)local_268 * fVar4);

      local_22c = (float)((float10)local_264 * fVar4);

      fVar3 = (float10)fcos(fVar3);

      local_228 = (float)fVar3;

      FUN_0076eb00(local_50,&local_234);

      local_2c0 = local_354;

      local_2bc = local_350;

      local_2b8 = local_34c;

      local_2b4 = 0;

      FUN_0076f240(&local_2c0);

      local_29c = local_2c0;

      local_298 = local_2bc;

      local_294 = local_2b8;

      local_28c = local_2bc;

      local_ec = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_f8 = local_35c;

      local_288 = local_2b8;

      local_290 = local_2c0;

      local_f4 = local_358;

      local_f0 = local_364;

      local_e4 = DAT_00a0f298;

      local_104 = fVar8;

      local_100 = fVar6;

      local_fc = fVar7;

      local_e8 = fVar5;

      FUN_0046c300();

      fVar1 = *(float *)(unaff_EBX + 0x30);

      local_17c = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_194 = local_320 * fVar1 + fVar8;

      local_190 = local_31c * fVar1 + fVar6;

      local_18c = local_318 * fVar1 + fVar7;

      local_178 = local_368;

      local_188 = local_35c;

      local_184 = local_358;

      local_180 = local_364;

      local_174 = DAT_00a0f298;

      FUN_0046c300();

      iVar2 = local_308;

      fVar1 = *(float *)(unaff_EBX + 0x30);

      local_5c = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_74 = fVar1 * local_32c + fVar8;

      local_33c = (float)(local_308 + -1) * fVar5;

      local_70 = local_328 * fVar1 + fVar6;

      local_6c = local_324 * fVar1 + fVar7;

      local_68 = local_35c;

      local_64 = local_358;

      local_60 = local_364;

      local_54 = DAT_00a0f298;

      local_58 = local_33c;

      FUN_0046c300();

      local_134 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_14c = local_2dc;

      local_148 = local_2d8;

      local_144 = local_2d4;

      local_140 = local_290;

      local_13c = local_28c;

      local_138 = local_288;

      local_12c = 0;

      local_130 = fVar5;

      FUN_0046c300();

      fVar1 = *(float *)(unaff_EBX + 0x30);

      local_bc = fVar1 * local_32c + fVar8;

      local_a4 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_b8 = local_328 * fVar1 + fVar6;

      local_b0 = local_338;

      local_ac = local_334;

      local_a8 = local_330;

      local_b4 = local_324 * fVar1 + fVar7;

      local_a0 = local_33c;

      local_9c = DAT_00a0f298;

      FUN_0046c300();

      fVar1 = *(float *)(unaff_EBX + 0x30);

      local_1c4 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_1dc = fVar1 * local_320 + fVar8;

      local_1d0 = local_314;

      local_1cc = local_310;

      local_1c8 = local_30c;

      local_1d8 = local_31c * fVar1 + fVar6;

      local_1d4 = local_318 * fVar1 + fVar7;

      local_1c0 = local_368;

      local_1bc = DAT_00a0f298;

      FUN_0046c300();

      local_2e4 = *(float *)(unaff_EBX + 0x2c);

      local_1a0 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_2f8 = local_2e4 * local_320;

      local_2f4 = local_31c * local_2e4;

      local_2f0 = local_318 * local_2e4;

      local_2ec = local_2e4 * local_32c;

      local_2e8 = local_328 * local_2e4;

      local_1b8 = local_304;

      local_2e4 = local_324 * local_2e4;

      local_1b4 = local_300;

      local_1b0 = local_2fc;

      local_1ac = local_35c;

      local_1a8 = local_358;

      local_1a4 = local_364;

      local_198 = g_flOne;

      local_19c = fVar5;

      FUN_0046c300();

      local_258 = local_2f8 + local_304;

      local_158 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_274 = local_2f4 + local_300;

      local_270 = local_2f0 + local_2fc;

      local_154 = local_368;

      local_164 = local_35c;

      local_160 = local_358;

      local_15c = local_364;

      local_150 = DAT_00a0f708;

      local_170 = local_258;

      local_16c = local_274;

      local_168 = local_270;

      FUN_0046c300();

      local_25c = local_2ec + local_304;

      local_110 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_254 = local_2e8 + local_300;

      local_260 = local_2e4 + local_2fc;

      local_11c = local_280;

      local_118 = local_27c;

      local_114 = local_278;

      local_10c = local_33c;

      local_108 = DAT_00a0f708;

      local_128 = local_25c;

      local_124 = local_254;

      local_120 = local_260;

      FUN_0046c300();

      local_20c = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_224 = local_25c;

      local_218 = local_338;

      local_214 = local_334;

      local_210 = local_330;

      local_208 = local_33c;

      local_220 = local_254;

      local_21c = local_260;

      local_204 = DAT_00a0f708;

      FUN_0046c300();

      local_c8 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_e0 = local_258;

      local_d4 = local_314;

      local_d0 = local_310;

      local_cc = local_30c;

      local_c4 = local_368;

      local_dc = local_274;

      local_d8 = local_270;

      local_c0 = DAT_00a0f708;

      FUN_0046c300();

      local_200 = local_2f8 + fVar8;

      local_1e8 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_1fc = local_2f4 + fVar6;

      local_1f8 = local_2f0 + fVar7;

      local_1f4 = local_314;

      local_1f0 = local_310;

      local_1ec = local_30c;

      local_1e4 = local_368;

      local_1e0 = DAT_00a0f298;

      FUN_0046c300();

      FUN_0046c300();

      FUN_0046c300();

      local_98 = local_2ec + fVar8;

      local_80 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40);

      local_94 = local_2e8 + fVar6;

      local_90 = local_2e4 + fVar7;

      local_8c = local_338;

      local_88 = local_334;

      local_84 = local_330;

      local_7c = local_33c;

      local_78 = DAT_00a0f298;

      FUN_0046c300();

      local_32c = local_348;

      local_324 = local_340;

      local_308 = iVar2 + 1;

      local_328 = local_344;

      local_338 = fVar9;

      local_334 = fVar11;

      local_330 = fVar10;

    } while (local_308 <= param_1);

  }

  return;

}
