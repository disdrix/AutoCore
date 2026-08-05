// READABILITY (auto CF):
//  - Body size: ~156 non-empty decompiler lines.
//  - Control keywords: if×7, for×3, goto×2, return×2.
//  - Notable callees: FUN_0043f780×2, FUN_0076d1b0×2, fopen×2, CONCAT31, ExitProcess, FUN_00414b60, FUN_00414bc0, FUN_00414c20.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp"; "Failed to Create Background Vertex Buffer"; "c:\\VOGCRASH.txt"; "PalViewBackground.fx".
//  - Return sites: 2.

// =============================================================================
// Named_gfxView
// -----------------------------------------------------------------------------
// Stable ID: aa_0075ceb0
// Address:   0x0075ceb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxView"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __fastcall Named_gfxView(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  FILE *_File;

  int iVar6;

  uint32_t /* width from decompiler */ extraout_EDX;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  char *pcVar9;

  uint8_t local_2c [4];

  uint32_t /* width from decompiler */ *local_28;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  fVar1 = g_flOne;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b25d7;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00a9edc8;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = fVar1;

  local_28 = param_1;

  pvVar3 = _aligned_malloc(0xc0,0x10);

  uVar5 = 0;

  if (pvVar3 != (void *)0x0) {

    FUN_00972cc0();

    uVar5 = extraout_EDX;

  }

  param_1[2] = uVar5;

  local_4 = 0;

  FUN_0073f590(param_1 + 4);

  param_1[0x11] = 0;

  local_4._0_1_ = 2;

  *(uint8_t *)(param_1 + 0x12) = 1;

  *(uint8_t *)((int)param_1 + 0x49) = 1;

  param_1[0x13] = 0xffffffff;

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_0043f780();

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar7 = &DAT_00afdf70;

    puVar8 = puVar4;

    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar8 = *puVar7;

      puVar7 = puVar7 + 1;

      puVar8 = puVar8 + 1;

    }

  }

  param_1[0x14] = puVar4;

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_0043f780();

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar7 = &DAT_00afdf70;

    puVar8 = puVar4;

    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar8 = *puVar7;

      puVar7 = puVar7 + 1;

      puVar8 = puVar8 + 1;

    }

  }

  param_1[0x15] = puVar4;

  param_1[0x16] = 0;

  param_1[0x30] = 0;

  param_1[0x31] = 0;

  param_1[0x32] = 0;

  *(uint8_t *)(param_1 + 0x33) = 1;

  param_1[0x34] = 0xffffffff;

  param_1[0x36] = 0;

  param_1[0x35] = &PTR_FUN_00a9db18;

  uVar5 = DAT_00a0f298;

  param_1[0x37] = DAT_00d1f01c;

  param_1[0x38] = DAT_00d1f020;

  param_1[0x39] = DAT_00d1f024;

  uVar2 = DAT_00d1f028;

  param_1[0x3c] = uVar5;

  param_1[0x3d] = DAT_00aaa880;

  param_1[0x41] = DAT_00a0f520;

  uVar5 = DAT_00aaa628;

  param_1[0x3a] = uVar2;

  param_1[0x3b] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  param_1[0x40] = 0;

  param_1[0x42] = 0;

  param_1[0x43] = uVar5;

  param_1[0x44] = 0;

  param_1[0x45] = 0;

  param_1[0x46] = 0;

  param_1[0x47] = 0;

  param_1[0x48] = 0;

  param_1[0x49] = 0;

  *(uint8_t *)(param_1 + 0x4a) = 0;

  *(uint8_t *)((int)param_1 + 0x129) = 0;

  param_1[0x4c] = 0;

  param_1[0x4b] = &PTR_FUN_00a9db18;

  param_1[0x4d] = 0;

  *(uint8_t *)(param_1 + 0x4e) = 0;

  *(uint8_t *)((int)param_1 + 0x139) = 0;

  *(uint8_t *)((int)param_1 + 0x13a) = 0;

  param_1[0x4f] = 0;

  local_4._0_1_ = 7;

  param_1[0x50] = 0;

  param_1[0x51] = 0;

  param_1[0x52] = DAT_00afdf0c;

  *(uint8_t *)(param_1 + 0x53) = 0;

  *(uint8_t *)((int)param_1 + 0x14d) = 0;

  uVar5 = FUN_00414bc0(0x144);

  local_4._0_1_ = 8;

  iVar6 = FUN_00414c20(4,uVar5,3,0);

  local_4 = CONCAT31(local_4._1_3_,7);

  FUN_00414b60();

  if ((iVar6 < 0) &&

     (iVar6 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",0x45,

                           "Failed to Create Background Vertex Buffer"), iVar6 == 3)) {

    _File = fopen("c:\\VOGCRASH.txt","w");

    if (_File == (FILE *)0x0) goto LAB_0075d1c6;

    pcVar9 = "Failed to Create Background Vertex Buffer";

    uVar5 = 0x45;

  }

  else {

    FUN_00989e00(local_2c,"PalViewBackground.fx");

    iVar6 = FUN_009701d0(local_2c);

    if ((-1 < iVar6) ||

       (iVar6 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",0x48,

                             "Failed to create view background effect"), iVar6 != 3)) {

      param_1[0x10] = param_1;

      puVar4 = param_1 + 0x17;

      for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar4 = 0;

        puVar4 = puVar4 + 1;

      }

      ExceptionList = local_c;

      return param_1;

    }

    _File = fopen("c:\\VOGCRASH.txt","w");

    if (_File == (FILE *)0x0) goto LAB_0075d1c6;

    pcVar9 = "Failed to create view background effect";

    uVar5 = 0x48;

  }

  fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

          "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",uVar5,3,pcVar9);

  fclose(_File);

LAB_0075d1c6:

  raise(0x16);

                    /* WARNING: Subroutine does not return */

  ExitProcess(3);

}
