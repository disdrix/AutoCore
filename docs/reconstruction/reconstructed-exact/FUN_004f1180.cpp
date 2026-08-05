// =============================================================================
// FUN_004f1180
// -----------------------------------------------------------------------------
// Stable ID: aa_004f1180
// Address:   0x004f1180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f1180 @ 0x004f1180
// Stable ID: aa_004f1180
// Embedded strings (evidence for future rename):
//   - "!!!!!Rigid body of object \'%s\' failed to load: %s."
//   - "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\CloneBase.cpp"
//   - "REAL BAD. A PHYSICS OBJECT FAILED TO LOAD PROPERLY %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~176 non-empty decompiler lines.
//  - Control keywords: if×15, for×2, return×2.
//  - Notable callees: CONCAT31×4, free×3, FUN_00403450×2, FUN_00402d50, FUN_004eaf30, FUN_004ee080, FUN_004f1180, FUN_004f32d0.
//  - Strings: "!!!!!Rigid body of object \'%s\' failed to load: %s."; "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\CloneBase.cpp"; "REAL BAD. A PHYSICS OBJECT FAILED TO LOAD PROPERLY %s".
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

void __fastcall FUN_004f1180(int param_1)



{

  ushort uVar1;

  wchar_t *_Str;

  size_t sVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint3 uVar7;

  uint8_t **ppuVar8;

  uint32_t /* width from decompiler */ *puVar9;

  float fVar10;

  uint32_t /* width from decompiler */ auStack_2f4 [20];

  uint32_t /* width from decompiler */ uStack_2a4;

  uint8_t *puStack_2a0;

  uint32_t /* width from decompiler */ uStack_29c;

  uint32_t /* width from decompiler */ uStack_298;

  int iStack_294;

  uint uStack_290;

  uint uStack_28c;

  uint32_t /* width from decompiler */ uStack_288;

  uint32_t /* width from decompiler */ uStack_284;

  char *pcStack_280;

  float fStack_27c;

  uint uStack_278;

  float local_260;

  float local_258;

  uint local_254;

  uint8_t *puStack_230;

  uint8_t auStack_22c [128];

  uint8_t *puStack_1ac;

  uint8_t auStack_1a8 [128];

  char acStack_128 [268];

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a2ad8;

  local_1c = ExceptionList;

  ExceptionList = &local_1c;

  FUN_004eaf30();

  _Str = *(wchar_t **)(param_1 + 0x3c);

  if (_Str != (wchar_t *)0x0) {

    _Str = _Str + 0x205;

  }

  uStack_278 = 0x4f11c4;

  sVar2 = wcslen(_Str);

  if (1 < sVar2) {

    local_258 = g_flOne;

    if (*(int *)(param_1 + 0x38) == 0x12) {

      local_258 = *(float *)(*(int *)(param_1 + 0x3c) + 0x4d4);

    }

    if ((*(int *)(param_1 + 0x38) == 0xe) &&

       ((*(byte *)(*(int *)(param_1 + 0x3c) + 0x5f0) & 0x10) != 0)) {

      FUN_006c9a50();

      uStack_278 = 0x20;

      fStack_27c = 7.261625e-39;

      iVar3 = (**(code **)(*DAT_00b05060 + 0x10))();

      *(uint16_t *)(iVar3 + 4) = 0x20;

      uStack_14 = 0;

      uStack_278 = 0x4f1292;

      iVar3 = FUN_006c7bc0();

      uStack_14 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 8) = 1;

    }

    uVar1 = *(ushort *)(*(int *)(param_1 + 0x3c) + 0x3f2);

    local_260 = DAT_00a0f298;

    local_254 = CONCAT31(local_254._1_3_,(char)(uVar1 >> 8)) & 0xffffff01;

    fVar10 = DAT_00a10e78;

    if ((*(int *)(param_1 + 0x38) == 0xe) || (fVar10 = g_flOne, (uVar1 & 0x100) != 0)) {

      local_260 = fVar10;

    }

    if ((DAT_00b036d4 != (int *)0x0) && (*DAT_00b036d4 != 0)) {

      uStack_278 = 0x4f12fe;

      pvVar4 = operator_new(100);

      if (pvVar4 == (void *)0x0) {

        uVar5 = 0;

      }

      else {

        uVar5 = FUN_004f32d0();

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = uVar5;

    }

    if (*(int *)(param_1 + 0x3c) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(param_1 + 0x3c) + 0x40a;

    }

    puStack_230 = auStack_22c;

    (*(code *)PTR_FUN_00af8c9c)();

    fStack_27c = 7.26191e-39;

    uStack_278 = iVar3;

    FUN_00403450();

    iVar3 = *(int *)(param_1 + 0x3c);

    uStack_29c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x3e4);

    uStack_278 = local_254;

    fStack_27c = local_260;

    uVar7 = (uint3)((uint)local_260 >> 8);

    pcStack_280 = (char *)local_258;

    uStack_284 = 0;

    uStack_288 = 0;

    uStack_290 = CONCAT31((int3)((uint)local_258 >> 8),*(uint8_t *)(iVar3 + 0x3f2)) & 0xffffff01;

    iStack_294 = param_1 + 0x90;

    uStack_28c = CONCAT31(uVar7 >> 1,(char)(CONCAT31(uVar7,*(uint8_t *)(iVar3 + 0x3f2)) >> 1)) &

                 0xffffff01;

    uStack_14 = 1;

    uStack_298 = 0x3f800000;

    puStack_2a0 = puStack_230;

    uStack_2a4 = 0x4f139e;

    uVar5 = FUN_004ee080();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = uVar5;

    uStack_14 = 0xffffffff;

    if (puStack_230 != auStack_22c) {

      uStack_278 = 0x4f13c5;

      free(puStack_230);

    }

    if (*(int *)(param_1 + 0x98) == 0) {

      if (*(int *)(param_1 + 0x3c) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_1 + 0x3c) + 0x40a;

      }

      puStack_230 = auStack_22c;

      (*(code *)PTR_FUN_00af8c9c)();

      fStack_27c = 7.262177e-39;

      uStack_278 = iVar3;

      FUN_00403450();

      ppuVar8 = &puStack_230;

      puVar6 = auStack_2f4;

      for (iVar3 = 0x21; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar6 = *ppuVar8;

        ppuVar8 = ppuVar8 + 1;

        puVar6 = puVar6 + 1;

      }

      sprintf(acStack_128,"!!!!!Rigid body of object \'%s\' failed to load: %s.",param_1 + 0x40);

      if (puStack_230 != auStack_22c) {

        uStack_278 = 0x4f144b;

        free(puStack_230);

      }

      uStack_278 = 2;

      fStack_27c = 1.27098e-42;

      pcStack_280 = "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\CloneBase.cpp";

      uStack_284 = 0x4f1467;

      vog_LogMessage();

      ExceptionList = local_1c;

      return;

    }

    if ((0 < *(int *)(param_1 + 0x9c)) && (*(int *)(param_1 + 0xa4) < 1)) {

      uStack_278 = 0x4f14a9;

      puVar6 = (uint32_t /* width from decompiler */ *)FUN_00402d50();

      uStack_14 = 2;

      puVar9 = auStack_2f4;

      for (iVar3 = 0x21; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar9 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar9 = puVar9 + 1;

      }

      FUN_007a4480(1,"REAL BAD. A PHYSICS OBJECT FAILED TO LOAD PROPERLY %s");

      uStack_14 = 0xffffffff;

      if (puStack_1ac != auStack_1a8) {

        uStack_278 = 0x4f14fb;

        free(puStack_1ac);

      }

    }

    if (*(int *)(param_1 + 0x38) == 0x38) {

      uStack_278 = 0x1000;

      fStack_27c = 7.262574e-39;

      FUN_005f5700();

    }

  }

  ExceptionList = local_1c;

  return;

}
