// =============================================================================
// FUN_0055cf60
// -----------------------------------------------------------------------------
// Stable ID: aa_0055cf60
// Address:   0x0055cf60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055cf60 @ 0x0055cf60
// Stable ID: aa_0055cf60
// Embedded strings (evidence for future rename):
//   - "UIResample4x4wLum.fx"
//   - "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGBlurFilter.cpp"
//   - "failed to load filter effect."
//   - "UIGaussianBloom.fx"
//   - "FilterDirection"
//   - "UISideChannelAdd.fx"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~251 non-empty decompiler lines.
//  - Control keywords: if×32, for×4, return×1.
//  - Notable callees: vog_LogMessage×8, CONCAT31×6, FUN_009888b0×5, FUN_009685e0×4, FUN_0096f0e0×4, FUN_009701d0×4, FUN_00988610×4, FUN_009886d0×4.
//  - Strings: "UIResample4x4wLum.fx"; "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGBlurFilter.cpp"; "failed to load filter effect."; "UIGaussianBloom.fx".
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

uint32_t /* width from decompiler */ __fastcall FUN_0055cf60(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int *piVar4;

  void *pvVar5;

  int unaff_EDI;

  void *pvStack_30;

  void *local_2c [2];

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  void *local_1c;

  int iStack_18;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4a08;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_2c[0] = operator_new(0x18);

  local_4 = 0;

  if (local_2c[0] == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_009886d0();

  }

  local_4 = 0xffffffff;

  *param_1 = uVar2;

  local_2c[0] = operator_new(0x18);

  local_4 = 1;

  if (local_2c[0] == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_009886d0();

  }

  local_4 = 0xffffffff;

  param_1[1] = uVar2;

  local_2c[0] = operator_new(0x18);

  local_4 = 2;

  if (local_2c[0] == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_009886d0();

  }

  local_4 = 0xffffffff;

  param_1[2] = uVar2;

  local_2c[0] = operator_new(0x18);

  local_4 = 3;

  if (local_2c[0] == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_009886d0();

  }

  local_4 = 0xffffffff;

  param_1[3] = uVar2;

  FUN_0096f530();

  local_4 = 4;

  FUN_00989e00(local_2c,"UIResample4x4wLum.fx");

  FUN_009701d0(local_2c);

  iVar3 = FUN_00988610(&local_1c);

  if (iVar3 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGBlurFilter.cpp",0x2a,3,

                   "failed to load filter effect.");

  }

  FUN_00989e00(local_2c,"UIGaussianBloom.fx");

  FUN_009701d0(local_2c);

  iVar3 = FUN_00988610(&local_1c);

  if (iVar3 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGBlurFilter.cpp",0x2f,3,

                   "failed to load filter effect.");

  }

  local_24 = 0;

  FUN_00442640("FilterDirection",&local_24);

  FUN_00989e00(local_2c,"UIGaussianBloom.fx");

  FUN_009701d0(local_2c);

  iVar3 = FUN_00988610(&local_1c);

  if (iVar3 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGBlurFilter.cpp",0x36,3,

                   "failed to load filter effect.");

  }

  local_20 = 1;

  FUN_00442640("FilterDirection",&local_20);

  FUN_00989e00(local_2c,"UISideChannelAdd.fx");

  FUN_009701d0(local_2c);

  iVar3 = FUN_00988610(&local_1c);

  if (iVar3 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGBlurFilter.cpp",0x3d,3,

                   "failed to load filter effect.");

  }

  local_14 = *(int *)(*(int *)(DAT_00d1f058 + 0x2c) + 0x80);

  local_10 = *(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1f058 + 0x2c) + 0x84);

  local_2c[0] = operator_new(0xd4);

  local_4._0_1_ = 5;

  if (local_2c[0] == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_009685e0();

  }

  param_1[4] = piVar4;

  local_4 = CONCAT31(local_4._1_3_,4);

  (**(code **)(*piVar4 + 8))(&local_14);

  pvStack_30 = operator_new(0xd4);

  puStack_8._0_1_ = 6;

  if (pvStack_30 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_009685e0();

  }

  pvStack_30 = (void *)((int)(iStack_18 + (iStack_18 >> 0x1f & 3U)) >> 2);

  local_2c[0] = (void *)((int)(local_14 + (local_14 >> 0x1f & 3U)) >> 2);

  param_1[5] = piVar4;

  puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,4);

  (**(code **)(*piVar4 + 8))(&pvStack_30);

  pvVar5 = operator_new(0xd4);

  pvStack_c._0_1_ = 7;

  if (pvVar5 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_009685e0();

  }

  pvStack_30 = (void *)((int)(iStack_18 + (iStack_18 >> 0x1f & 3U)) >> 2);

  param_1[6] = piVar4;

  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);

  (**(code **)(*piVar4 + 8))(&stack0xffffffcc);

  pvVar5 = operator_new(0xd4);

  local_10._0_1_ = 8;

  if (pvVar5 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_009685e0();

  }

  param_1[7] = piVar4;

  local_10 = CONCAT31(local_10._1_3_,4);

  (**(code **)(*piVar4 + 8))(&stack0xffffffc8);

  FUN_0096ef70();

  local_14 = CONCAT31(local_14._1_3_,9);

  iVar3 = FUN_0096f0e0(0x16,param_1[4] + 0x80,1,0x31,1,0);

  if (iVar3 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGBlurFilter.cpp",0x5b,3,

                   "failed to create buffer texture for buffered window");

  }

  iVar3 = param_1[4];

  if (unaff_EDI != 0) {

    *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + 1;

    if (*(int *)(unaff_EDI + 8) == 1) {

      (**(code **)(*(int *)(unaff_EDI + 4) + 4))();

    }

  }

  iVar1 = *(int *)(iVar3 + 0xb8);

  if (iVar1 != 0) {

    piVar4 = (int *)(iVar1 + 8);

    *piVar4 = *piVar4 + -1;

    if (*piVar4 == 0) {

      (**(code **)(*(int *)(iVar1 + 4) + 8))();

    }

  }

  *(int *)(iVar3 + 0xb8) = unaff_EDI;

  *(uint32_t /* width from decompiler */ *)(param_1[4] + 0xc4) = 0xffff0000;

  iVar3 = FUN_0096f0e0(0x15,param_1[5] + 0x80,1,0x11,1,0);

  if (iVar3 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGBlurFilter.cpp",0x62,3,

                   "failed to create buffer texture for buffered window");

  }

  iVar3 = param_1[5];

  if (unaff_EDI != 0) {

    *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + 1;

    if (*(int *)(unaff_EDI + 8) == 1) {

      (**(code **)(*(int *)(unaff_EDI + 4) + 4))();

    }

  }

  iVar1 = *(int *)(iVar3 + 0xb8);

  if (iVar1 != 0) {

    piVar4 = (int *)(iVar1 + 8);

    *piVar4 = *piVar4 + -1;

    if (*piVar4 == 0) {

      (**(code **)(*(int *)(iVar1 + 4) + 8))();

    }

  }

  *(int *)(iVar3 + 0xb8) = unaff_EDI;

  *(uint32_t /* width from decompiler */ *)(param_1[5] + 0xc0) = 0;

  iVar3 = FUN_0096f0e0(0x15,param_1[6] + 0x80,1,0x11,1,0);

  if (iVar3 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGBlurFilter.cpp",0x69,3,

                   "failed to create buffer texture for buffered window");

  }

  iVar3 = param_1[6];

  if (unaff_EDI != 0) {

    *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + 1;

    if (*(int *)(unaff_EDI + 8) == 1) {

      (**(code **)(*(int *)(unaff_EDI + 4) + 4))();

    }

  }

  iVar1 = *(int *)(iVar3 + 0xb8);

  if (iVar1 != 0) {

    piVar4 = (int *)(iVar1 + 8);

    *piVar4 = *piVar4 + -1;

    if (*piVar4 == 0) {

      (**(code **)(*(int *)(iVar1 + 4) + 8))();

    }

  }

  *(int *)(iVar3 + 0xb8) = unaff_EDI;

  *(uint32_t /* width from decompiler */ *)(param_1[6] + 0xc0) = 0;

  iVar3 = FUN_0096f0e0(0x15,param_1[7] + 0x80,1,0x11,1,0);

  if (iVar3 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGBlurFilter.cpp",0x70,3,

                   "failed to create buffer texture for buffered window");

  }

  iVar3 = param_1[7];

  if (unaff_EDI != 0) {

    *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + 1;

    if (*(int *)(unaff_EDI + 8) == 1) {

      (**(code **)(*(int *)(unaff_EDI + 4) + 4))();

    }

  }

  iVar1 = *(int *)(iVar3 + 0xb8);

  if (iVar1 != 0) {

    piVar4 = (int *)(iVar1 + 8);

    *piVar4 = *piVar4 + -1;

    if (*piVar4 == 0) {

      (**(code **)(*(int *)(iVar1 + 4) + 8))();

    }

  }

  *(int *)(iVar3 + 0xb8) = unaff_EDI;

  *(uint32_t /* width from decompiler */ *)(param_1[7] + 0xc0) = 0;

  FUN_009888b0(param_1[4],0);

  FUN_007567b0(*param_1,0);

  FUN_009888b0(param_1[5],0);

  FUN_007567b0(param_1[1],0);

  FUN_009888b0(param_1[6],0);

  FUN_007567b0(param_1[2],0);

  FUN_009888b0(param_1[4],0);

  FUN_009888b0(param_1[7],1);

  local_14 = CONCAT31(local_14._1_3_,4);

  FUN_0096efd0();

  local_14 = -1;

  FUN_0096f510();

  ExceptionList = local_1c;

  return 0;

}
