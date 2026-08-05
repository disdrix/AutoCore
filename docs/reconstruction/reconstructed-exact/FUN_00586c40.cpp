// =============================================================================
// FUN_00586c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00586c40
// Address:   0x00586c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00586c40 @ 0x00586c40
// Stable ID: aa_00586c40
// Embedded strings (evidence for future rename):
//   - "UIBackBuffDownsample.fx"
//   - "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGSpecGlowFilter.cpp"
//   - "failed to load filter effect."
//   - "BackBufferTexture"
//   - "UIMapExtents0"
//   - "UISpecularBloomHorizontal.fx"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~287 non-empty decompiler lines.
//  - Control keywords: if×31, for×3, return×1.
//  - Notable callees: CONCAT31×9, vog_LogMessage×7, FUN_0096f530×5, FUN_009701d0×5, FUN_00989e00×5, FUN_009685e0×4, FUN_0096f510×4, FUN_00988610×4.
//  - Strings: "UIBackBuffDownsample.fx"; "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGSpecGlowFilter.cpp"; "failed to load filter effect."; "BackBufferTexture".
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ __fastcall FUN_00586c40(int param_1)



{

  void *pvVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  void **ppvVar5;

  int *piVar6;

  int iVar7;

  int iStack_74;

  void *pvStack_70;

  void *pvStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  void *pvStack_64;

  void *local_60;

  int iStack_5c;

  int local_58;

  int local_54;

  uint8_t local_50 [8];

  uint8_t local_48 [8];

  uint8_t local_40 [8];

  uint8_t local_38 [8];

  float local_30;

  void *local_2c;

  float local_28;

  float local_24;

  uint8_t uStack_20;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a564b;

  pvStack_1c = ExceptionList;

  local_58 = *(int *)(*(int *)(DAT_00d1f058 + 0x2c) + 0x80);

  local_54 = *(int *)(*(int *)(DAT_00d1f058 + 0x2c) + 0x84);

  ExceptionList = &pvStack_1c;

  local_60 = operator_new(0x18);

  local_14 = 0;

  if (local_60 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_009886d0();

  }

  local_14 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = uVar3;

  local_60 = operator_new(0x18);

  local_14 = 1;

  if (local_60 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_009886d0();

  }

  local_14 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar3;

  local_60 = operator_new(0x18);

  local_14 = 2;

  if (local_60 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_009886d0();

  }

  local_14 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = uVar3;

  local_60 = operator_new(0x18);

  local_14 = 3;

  if (local_60 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_009886d0();

  }

  local_14 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = uVar3;

  FUN_0096f530();

  local_14 = 4;

  FUN_00989e00(&local_60,"UIBackBuffDownsample.fx");

  FUN_009701d0(&local_60);

  iVar4 = FUN_00988610(local_38);

  if (iVar4 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGSpecGlowFilter.cpp",0x4f,3,

                   "failed to load filter effect.");

  }

  uVar3 = FUN_00491e80(param_1 + 0x18);

  FUN_00970140("BackBufferTexture",uVar3);

  if (*(int *)(*(int *)(param_1 + 0x20) + 0xc) == 0) {

    local_60 = (void *)0xffffffff;

    ppvVar5 = &local_60;

  }

  else {

    ppvVar5 = (void **)FUN_00752310(&local_60,"UIMapExtents0");

  }

  pvVar1 = *ppvVar5;

  local_24 = g_flOne / (float)local_54;

  local_28 = g_flOne / (float)local_58;

  local_30 = g_flOne;

  local_2c = (void *)g_flOne;

  cVar2 = FUN_0096fdf0();

  uStack_68._3_1_ = cVar2;

  iVar4 = FUN_00752a00(pvVar1,&local_30);

  if ((iVar4 == -1) && (uStack_68._3_1_ != '\0')) {

    FUN_0096f5d0();

  }

  FUN_0096f530();

  local_14 = CONCAT31(local_14._1_3_,5);

  FUN_00989e00(&local_60,"UISpecularBloomHorizontal.fx");

  FUN_009701d0(&local_60);

  iVar4 = FUN_00988610(local_40);

  if (iVar4 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGSpecGlowFilter.cpp",0x5d,3,

                   "failed to load filter effect.");

  }

  FUN_0096f530();

  local_14 = CONCAT31(local_14._1_3_,6);

  FUN_00989e00(&local_60,"UISpecularBloomVertical.fx");

  FUN_009701d0(&local_60);

  iVar4 = FUN_00988610(local_48);

  if (iVar4 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGSpecGlowFilter.cpp",0x69,3,

                   "failed to load filter effect.");

  }

  FUN_0096f530();

  local_14 = CONCAT31(local_14._1_3_,7);

  FUN_00989e00(&local_60,"UISpecularBlend.fx");

  FUN_009701d0(&local_60);

  iVar4 = FUN_00988610(local_50);

  if (iVar4 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGSpecGlowFilter.cpp",0x72,3,

                   "failed to load filter effect.");

  }

  local_60 = operator_new(0xd4);

  local_14._0_1_ = 8;

  if (local_60 == (void *)0x0) {

    piVar6 = (int *)0x0;

  }

  else {

    piVar6 = (int *)FUN_009685e0();

  }

  *(int **)(param_1 + 0x3c) = piVar6;

  local_14 = CONCAT31(local_14._1_3_,7);

  (**(code **)(*piVar6 + 8))(&local_58);

  pvStack_64 = operator_new(0xd4);

  puStack_18._0_1_ = 9;

  if (pvStack_64 == (void *)0x0) {

    piVar6 = (int *)0x0;

  }

  else {

    piVar6 = (int *)FUN_009685e0();

  }

  pvStack_64 = (void *)((int)(iStack_5c + (iStack_5c >> 0x1f & 3U)) >> 2);

  local_60 = (void *)((int)(local_58 + (local_58 >> 0x1f & 3U)) >> 2);

  *(int **)(param_1 + 0x24) = piVar6;

  puStack_18 = (uint8_t *)CONCAT31(puStack_18._1_3_,7);

  (**(code **)(*piVar6 + 8))(&pvStack_64);

  uStack_68 = operator_new(0xd4);

  pvStack_1c._0_1_ = 10;

  if (uStack_68 == (void *)0x0) {

    piVar6 = (int *)0x0;

  }

  else {

    piVar6 = (int *)FUN_009685e0();

  }

  uStack_68 = (void *)((int)((int)local_60 + ((int)local_60 >> 0x1f & 3U)) >> 2);

  pvStack_64 = (void *)((int)(iStack_5c + (iStack_5c >> 0x1f & 3U)) >> 2);

  *(int **)(param_1 + 0x2c) = piVar6;

  pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,7);

  (**(code **)(*piVar6 + 8))(&uStack_68);

  pvStack_6c = operator_new(0xd4);

  uStack_20 = 0xb;

  if (pvStack_6c == (void *)0x0) {

    piVar6 = (int *)0x0;

  }

  else {

    piVar6 = (int *)FUN_009685e0();

  }

  pvStack_6c = (void *)((int)((int)pvStack_64 + ((int)pvStack_64 >> 0x1f & 3U)) >> 2);

  uStack_68 = (void *)((int)((int)local_60 + ((int)local_60 >> 0x1f & 3U)) >> 2);

  *(int **)(param_1 + 0x34) = piVar6;

  uStack_20 = 7;

  (**(code **)(*piVar6 + 8))(&pvStack_6c);

  FUN_0096ef70();

  local_24 = (float)CONCAT31(local_24._1_3_,0xc);

  iVar4 = FUN_0096f0e0(0x15,*(int *)(param_1 + 0x24) + 0x80,1,0x4011,0,0);

  if (iVar4 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGSpecGlowFilter.cpp",0x90,3,

                   "failed to create buffer texture for buffered window");

  }

  iVar4 = *(int *)(param_1 + 0x24);

  if (iStack_74 != 0) {

    *(int *)(iStack_74 + 8) = *(int *)(iStack_74 + 8) + 1;

    if (*(int *)(iStack_74 + 8) == 1) {

      (**(code **)(*(int *)(iStack_74 + 4) + 4))();

    }

  }

  iVar7 = *(int *)(iVar4 + 0xb8);

  if (iVar7 != 0) {

    piVar6 = (int *)(iVar7 + 8);

    *piVar6 = *piVar6 + -1;

    if (*piVar6 == 0) {

      (**(code **)(*(int *)(iVar7 + 4) + 8))();

    }

  }

  *(int *)(iVar4 + 0xb8) = iStack_74;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x24) + 0xc0) = 0;

  iVar4 = FUN_0096f0e0(0x15,*(int *)(param_1 + 0x2c) + 0x80,1,0x4011,0,0);

  if (iVar4 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGSpecGlowFilter.cpp",0x97,3,

                   "failed to create buffer texture for buffered window");

  }

  iVar4 = *(int *)(param_1 + 0x2c);

  if (iStack_74 != 0) {

    *(int *)(iStack_74 + 8) = *(int *)(iStack_74 + 8) + 1;

    if (*(int *)(iStack_74 + 8) == 1) {

      (**(code **)(*(int *)(iStack_74 + 4) + 4))();

    }

  }

  iVar7 = *(int *)(iVar4 + 0xb8);

  if (iVar7 != 0) {

    piVar6 = (int *)(iVar7 + 8);

    *piVar6 = *piVar6 + -1;

    if (*piVar6 == 0) {

      (**(code **)(*(int *)(iVar7 + 4) + 8))();

    }

  }

  *(int *)(iVar4 + 0xb8) = iStack_74;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x2c) + 0xc0) = 0;

  iVar4 = FUN_0096f0e0(0x15,*(int *)(param_1 + 0x34) + 0x80,1,0x4011,0,0);

  if (iVar4 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGSpecGlowFilter.cpp",0x9e,3,

                   "failed to create buffer texture for buffered window");

  }

  iVar4 = *(int *)(param_1 + 0x34);

  if (iStack_74 != 0) {

    *(int *)(iStack_74 + 8) = *(int *)(iStack_74 + 8) + 1;

    if (*(int *)(iStack_74 + 8) == 1) {

      (**(code **)(*(int *)(iStack_74 + 4) + 4))();

    }

  }

  iVar7 = *(int *)(iVar4 + 0xb8);

  if (iVar7 != 0) {

    piVar6 = (int *)(iVar7 + 8);

    *piVar6 = *piVar6 + -1;

    if (*piVar6 == 0) {

      (**(code **)(*(int *)(iVar7 + 4) + 8))();

    }

  }

  *(int *)(iVar4 + 0xb8) = iStack_74;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x34) + 0xc0) = 0;

  FUN_007567b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x20),0);

  FUN_009888b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),0);

  FUN_007567b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x28),0);

  FUN_009888b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c),0);

  FUN_007567b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x30),0);

  FUN_009888b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),1);

  *(uint8_t *)(*(int *)(param_1 + 0x38) + 0x14) = 0;

  pvStack_70 = operator_new(8);

  local_24._0_1_ = 0xd;

  if (pvStack_70 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0096f530();

  }

  local_24 = (float)CONCAT31(local_24._1_3_,0xc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = uVar3;

  FUN_00989e00(&pvStack_70,"NDLake.fx");

  FUN_009701d0(&pvStack_70);

  iVar4 = **(int **)(param_1 + 0x40);

  iVar7 = FUN_0073f2c0((int)*(short *)(iVar4 + 0x1c));

  if (iVar7 == 0) {

    FUN_0073f2f0((int)*(short *)(iVar4 + 0x1c));

  }

  local_24._0_1_ = 7;

  FUN_0096efd0();

  local_24._0_1_ = 6;

  FUN_0096f510();

  local_24._0_1_ = 5;

  FUN_0096f510();

  local_24 = (float)CONCAT31(local_24._1_3_,4);

  FUN_0096f510();

  local_24 = -NAN;

  FUN_0096f510();

  ExceptionList = local_2c;

  return 0;

}
