// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_004ed470
// -----------------------------------------------------------------------------
// Stable ID: aa_004ed470
// Callee of Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x004ed470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~393 non-empty decompiler lines.
//  - Control keywords: if×21, return×4, do×3, while×3, goto×2, for×1.
//  - Notable callees: CONCAT31×4, FUN_005d3ef0×2, FUN_005d4240×2, FUN_005d4440×2, FUN_005e1c80×2, FUN_004ed470, FUN_004f2d70, FUN_005070b0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SkyBoxParticles
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

int Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_004ed470(int param_1,float param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,char param_5,

                uint32_t /* width from decompiler */ *param_6,uint32_t /* width from decompiler */ *param_7,uint32_t /* width from decompiler */ param_8,int param_9)



{

  bool bVar1;

  void *pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  float *pfVar5;

  char *pcVar6;

  int iVar7;

  float *pfVar8;

  int iVar9;

  int iStack_294;

  uint32_t /* width from decompiler */ uStack_28c;

  int local_284;

  int local_280;

  int local_27c;

  uint local_278;

  uint local_274;

  float local_270;

  float local_26c;

  float local_268;

  float local_264;

  uint32_t /* width from decompiler */ local_260;

  uint32_t /* width from decompiler */ local_25c;

  uint32_t /* width from decompiler */ local_258;

  float local_254;

  uint32_t /* width from decompiler */ uStack_250;

  void *pvStack_24c;

  uint32_t /* width from decompiler */ uStack_248;

  void *local_244;

  uint32_t /* width from decompiler */ uStack_240;

  uint32_t /* width from decompiler */ uStack_23c;

  uint uStack_238;

  uint uStack_234;

  float fStack_230;

  float fStack_22c;

  uint32_t /* width from decompiler */ uStack_228;

  uint32_t /* width from decompiler */ uStack_224;

  uint32_t /* width from decompiler */ uStack_220;

  uint32_t /* width from decompiler */ uStack_21c;

  uint32_t /* width from decompiler */ uStack_218;

  uint32_t /* width from decompiler */ uStack_214;

  uint32_t /* width from decompiler */ uStack_210;

  uint32_t /* width from decompiler */ uStack_20c;

  uint32_t /* width from decompiler */ uStack_208;

  uint32_t /* width from decompiler */ uStack_204;

  float fStack_200;

  uint32_t /* width from decompiler */ uStack_1fc;

  uint32_t /* width from decompiler */ uStack_1f8;

  uint32_t /* width from decompiler */ uStack_1f4;

  float local_1f0 [4];

  float local_1e0 [4];

  float local_1d0 [4];

  uint8_t auStack_1c0 [8];

  int local_1b8;

  uint32_t /* width from decompiler */ *local_1b4;

  int iStack_1ac;

  uint32_t /* width from decompiler */ uStack_198;

  uint32_t /* width from decompiler */ uStack_194;

  uint32_t /* width from decompiler */ uStack_190;

  uint32_t /* width from decompiler */ uStack_18c;

  uint32_t /* width from decompiler */ uStack_188;

  uint32_t /* width from decompiler */ uStack_184;

  uint32_t /* width from decompiler */ uStack_180;

  uint32_t /* width from decompiler */ uStack_17c;

  uint32_t /* width from decompiler */ uStack_158;

  uint32_t /* width from decompiler */ uStack_154;

  uint32_t /* width from decompiler */ uStack_150;

  uint32_t /* width from decompiler */ uStack_14c;

  uint32_t /* width from decompiler */ uStack_148;

  uint32_t /* width from decompiler */ uStack_144;

  uint32_t /* width from decompiler */ uStack_140;

  uint32_t /* width from decompiler */ uStack_13c;

  uint32_t /* width from decompiler */ uStack_138;

  uint32_t /* width from decompiler */ uStack_134;

  float fStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  uint uStack_128;

  uint uStack_124;

  float fStack_120;

  float fStack_11c;

  float fStack_118;

  uint8_t uStack_104;

  uint32_t /* width from decompiler */ *puStack_f4;

  uint32_t /* width from decompiler */ uStack_f0;

  int iStack_ec;

  uint32_t /* width from decompiler */ local_e8;

  uint32_t /* width from decompiler */ uStack_e4;

  uint8_t local_e0 [4];

  int *local_dc;

  uint32_t /* width from decompiler */ uStack_d0;

  uint32_t /* width from decompiler */ uStack_cc;

  uint32_t /* width from decompiler */ uStack_c8;

  uint32_t /* width from decompiler */ uStack_c4;

  uint32_t /* width from decompiler */ uStack_c0;

  uint32_t /* width from decompiler */ uStack_bc;

  uint32_t /* width from decompiler */ uStack_b8;

  uint32_t /* width from decompiler */ uStack_b4;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint uStack_58;

  uint uStack_54;

  float fStack_50;

  char cStack_3c;

  void *pvStack_2c;

  uint uStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a294f;

  pvStack_1c = ExceptionList;

  iVar9 = 0;

  local_284 = 0;

  if ((*(int *)(param_1 + 4) == 0) || (iVar7 = *(int *)(param_1 + 0xc), iVar7 == 0)) {

    ExceptionList = &pvStack_1c;

    FUN_005e1c80();

    local_14 = 4;

    FUN_005d3ef0(local_e0);

    iVar9 = (**(code **)(*local_dc + 0x14))();

    if (iVar9 == 4) {

      if ((DAT_00b03e64 != '\0') && ((fStack_50 == 0.0 || (cStack_3c == '\a')))) {

        cStack_3c = '\x04';

        fStack_50 = DAT_00a0f520;

        uStack_250 = 0;

        pvStack_24c = (void *)0x0;

        uStack_234 = 0;

        uStack_238 = 0;

        uStack_23c = 0;

        uStack_240 = 0;

        uStack_224 = 0;

        uStack_228 = 0;

        fStack_22c = 0.0;

        fStack_230 = 0.0;

        uStack_214 = 0;

        uStack_218 = 0;

        uStack_21c = 0;

        uStack_220 = 0;

        uStack_204 = 0;

        uStack_208 = 0;

        uStack_20c = 0;

        uStack_210 = 0;

        FUN_005ee680(param_2,0x447a0000,&uStack_250);

        FUN_004f2d70(&fStack_230);

        uStack_60 = uStack_240;

        uStack_5c = uStack_23c;

        uStack_58 = uStack_238;

        uStack_54 = uStack_234;

      }

      uStack_d0 = *param_6;

      uStack_cc = param_6[1];

      uStack_c8 = param_6[2];

      uStack_c4 = param_6[3];

      uStack_c0 = *param_7;

      uStack_bc = param_7[1];

      uStack_b8 = param_7[2];

      uStack_b4 = param_7[3];

      if (iStack_ec == 0) {

        uStack_24 = 0xffffffff;

        if (-1 < (int)local_dc) {

          (**(code **)(*DAT_00b05060 + 0x14))(uStack_e4,(int)local_dc * 8,0x12);

        }

        ExceptionList = pvStack_2c;

        return 0;

      }

      iVar9 = (**(code **)(*DAT_00b05060 + 0x10))(0x10,0x22);

      *(uint16_t *)(iVar9 + 4) = 0x10;

      pvStack_2c._0_1_ = 5;

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_006c7fa0(param_2);

      pvStack_2c = (void *)CONCAT31(pvStack_2c._1_3_,4);

      puStack_f4 = puVar4;

      iVar7 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

      *(uint16_t *)(iVar7 + 4) = 0xa0;

      uStack_24._0_1_ = 6;

      iStack_294 = FUN_005d4240(&uStack_f0);

      *(short *)((int)puVar4 + 6) = *(short *)((int)puVar4 + 6) + -1;

      uStack_24 = CONCAT31(uStack_24._1_3_,4);

      if (*(short *)((int)puVar4 + 6) == 0) {

        (**(code **)*puVar4)(1);

      }

      if ((char)((uint)iVar9 >> 0x18) != '\0') {

        FUN_005d4440(6);

      }

    }

    if ((int)local_dc < 0) {

      ExceptionList = pvStack_2c;

      return iStack_294;

    }

    iVar9 = (int)local_dc * 8;

    uStack_28c = uStack_e4;

    goto LAB_004ee05a;

  }

  iVar3 = iVar7 * 4;

  ExceptionList = &pvStack_1c;

  local_280 = iVar3;

  local_244 = operator_new__(iVar7 << 4);

  if (3 < iVar3) {

    local_1b8 = 4 - (int)local_244;

    pfVar5 = (float *)((int)local_244 + 8);

    local_1b4 = (uint32_t /* width from decompiler */ *)(-8 - (int)local_244);

    iVar7 = (iVar3 - 4U >> 2) + 1;

    local_284 = 8;

    iVar9 = iVar7 * 4;

    do {

      pfVar5[-2] = *(float *)((int)local_1b4 + (int)pfVar5 + *(int *)(param_1 + 4)) * param_2;

      iVar3 = local_284 + 0x10;

      pfVar5[-1] = *(float *)((int)local_1b4 + (int)pfVar5 + 4 + *(int *)(param_1 + 4)) * param_2;

      *pfVar5 = *(float *)(local_284 + *(int *)(param_1 + 4)) * param_2;

      pfVar5[1] = *(float *)((int)pfVar5 + *(int *)(param_1 + 4) + local_1b8) * param_2;

      pfVar5 = pfVar5 + 4;

      iVar7 = iVar7 + -1;

      local_284 = iVar3;

      iVar3 = local_280;

    } while (iVar7 != 0);

  }

  for (; iVar9 < iVar3; iVar9 = iVar9 + 1) {

    *(float *)((int)local_244 + iVar9 * 4) = *(float *)(*(int *)(param_1 + 4) + iVar9 * 4) * param_2

    ;

  }

  local_e8 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  iVar9 = 0;

  local_270 = *(float *)(param_1 + 0x50) * param_2;

  local_26c = *(float *)(param_1 + 0x54) * param_2;

  local_268 = *(float *)(param_1 + 0x58) * param_2;

  local_264 = *(float *)(param_1 + 0x5c) * param_2;

  local_27c = 0;

  local_278 = 0;

  local_274 = 0x80000000;

  iVar7 = 0;

  local_14 = 0;

  if (0 < *(int *)(param_1 + 0x14)) {

    do {

      local_260 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + iVar9);

      iVar3 = *(int *)(param_1 + 0x10) + iVar9;

      local_25c = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

      local_258 = *(uint32_t /* width from decompiler */ *)(iVar3 + 8);

      local_254 = *(float *)(iVar3 + 0xc) * param_2;

      if (local_278 == (local_274 & 0x7fffffff)) {

        FUN_005b3370(&local_27c,0x10);

      }

      puVar4 = (uint32_t /* width from decompiler */ *)(local_278 * 0x10 + local_27c);

      local_278 = local_278 + 1;

      *puVar4 = local_260;

      puVar4[1] = local_25c;

      puVar4[2] = local_258;

      iVar7 = iVar7 + 1;

      puVar4[3] = local_254;

      iVar9 = iVar9 + 0x10;

    } while (iVar7 < *(int *)(param_1 + 0x14));

  }

  pfVar8 = local_1d0;

  pfVar5 = (float *)(param_1 + 0x30);

  iVar9 = 3;

  do {

    pfVar8[-8] = pfVar5[-4] * param_2 * param_2 * param_2;

    pfVar8[-4] = *pfVar5 * param_2 * param_2 * param_2;

    *pfVar8 = pfVar5[4] * param_2 * param_2 * param_2;

    pfVar5 = pfVar5 + 1;

    pfVar8 = pfVar8 + 1;

    iVar9 = iVar9 + -1;

  } while (iVar9 != 0);

  iVar9 = (**(code **)(*DAT_00b05060 + 0x10))(0xe0,0x22);

  pvVar2 = pvStack_24c;

  *(uint16_t *)(iVar9 + 4) = 0xe0;

  pvStack_1c._0_1_ = 1;

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_006c90d0(pvStack_24c,uStack_f0,0x10,&local_284);

  pvStack_1c._0_1_ = 0;

  operator_delete__(pvVar2);

  FUN_005e1c80();

  pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,2);

  FUN_005d3ef0(&local_1b8);

  uStack_198 = *param_6;

  uStack_194 = param_6[1];

  uStack_190 = param_6[2];

  uStack_18c = param_6[3];

  uStack_188 = *param_7;

  uStack_184 = param_7[1];

  uStack_180 = param_7[2];

  uStack_17c = param_7[3];

  if (0 < param_9) {

    local_1b8 = param_9;

  }

  bVar1 = false;

  local_1b4 = puVar4;

  if (param_5 == '\0') {

    puVar4[3] = DAT_00a10e78;

    uStack_144 = local_1f0[3];

    uStack_140 = local_1e0[0];

    uStack_13c = local_1e0[1];

    uStack_138 = local_1e0[2];

    uStack_134 = local_1e0[3];

    fStack_130 = local_1d0[0];

LAB_004edbac:

    uStack_128 = local_278;

    uStack_124 = local_274;

    fStack_120 = local_270;

    uStack_104 = 4;

    fStack_11c = local_26c;

    uStack_158 = uStack_1f8;

    uStack_154 = uStack_1f4;

    uStack_150 = local_1f0[0];

    uStack_14c = local_1f0[1];

    uStack_148 = local_1f0[2];

    uStack_12c = local_1d0[1];

  }

  else if (DAT_00b03e64 != '\0') {

    bVar1 = true;

    uStack_144 = local_1f0[3];

    uStack_140 = local_1e0[0];

    uStack_13c = local_1e0[1];

    uStack_138 = local_1e0[2];

    uStack_134 = local_1e0[3];

    fStack_130 = local_1d0[0];

    if (fStack_118 == 0.0) {

      fStack_118 = DAT_00aaa880;

      uStack_248 = 0;

      local_244 = (void *)0x0;

      fStack_22c = 0.0;

      fStack_230 = 0.0;

      uStack_234 = 0;

      uStack_238 = 0;

      uStack_21c = 0;

      uStack_220 = 0;

      uStack_224 = 0;

      uStack_228 = 0;

      uStack_20c = 0;

      uStack_210 = 0;

      uStack_214 = 0;

      uStack_218 = 0;

      uStack_1fc = 0;

      fStack_200 = 0.0;

      uStack_204 = 0;

      uStack_208 = 0;

      FUN_005f2b60(puVar4,0x461c4000,&uStack_248);

      uStack_1f8 = uStack_228;

      uStack_1f4 = uStack_224;

      local_278 = uStack_238;

      local_1f0[0] = (float)uStack_220;

      local_274 = uStack_234;

      local_1f0[1] = (float)uStack_21c;

      local_270 = fStack_230;

      local_1f0[2] = (float)uStack_218;

      local_26c = fStack_22c;

      local_1d0[1] = (float)uStack_1fc;

      uStack_144 = (float)uStack_214;

      uStack_140 = (float)uStack_210;

      uStack_13c = (float)uStack_20c;

      uStack_138 = (float)uStack_208;

      uStack_134 = (float)uStack_204;

      fStack_130 = fStack_200;

    }

    goto LAB_004edbac;

  }

  iVar9 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

  *(uint16_t *)(iVar9 + 4) = 0xa0;

  uStack_24._0_1_ = 3;

  iStack_294 = FUN_005d4240(auStack_1c0);

  uStack_24 = CONCAT31(uStack_24._1_3_,2);

  if (bVar1) {

    iVar9 = *(int *)(iStack_294 + 0x3c);

    local_270 = *(float *)(iVar9 + 0xb0);

    local_26c = *(float *)(iVar9 + 0xb4);

    local_268 = *(float *)(iVar9 + 0xb8);

    local_264 = *(float *)(iVar9 + 0xbc);

    FUN_005d4440(6);

    pcVar6 = (char *)FUN_005070b0(&stack0xfffffd6b);

    if ((*pcVar6 == '\0') && (*(int *)(iStack_294 + 0x44) != 0)) {

      FUN_005070d0();

    }

    if ((*(char *)(iStack_294 + 0x40) == '\0') || (*(int *)(iStack_294 + 8) == 0)) {

      (**(code **)(**(int **)(iStack_294 + 0x3c) + 0x40))(&local_270);

    }

  }

  *(short *)((int)puVar4 + 6) = *(short *)((int)puVar4 + 6) + -1;

  if (*(short *)((int)puVar4 + 6) == 0) {

    (**(code **)*puVar4)(1);

  }

  uStack_24 = uStack_24 & 0xffffff00;

  if (-1 < iStack_1ac) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_1b4,iStack_1ac * 8,0x12);

  }

  if (local_284 < 0) {

    ExceptionList = pvStack_2c;

    return iStack_294;

  }

  iVar9 = local_284 << 4;

LAB_004ee05a:

  uStack_24 = 0xffffffff;

  (**(code **)(*DAT_00b05060 + 0x14))(uStack_28c,iVar9,0x12);

  ExceptionList = pvStack_2c;

  return iStack_294;

}
