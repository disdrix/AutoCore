// =============================================================================
// FUN_008b06a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008b06a0
// Address:   0x008b06a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b06a0 @ 0x008b06a0
// Stable ID: aa_008b06a0
// Embedded strings (evidence for future rename):
//   - "i_d_notify_2d_wnd_bg_fill.xml"
//   - "i_d_notify_2d_btn_add_skills.xml"
//   - "i_d_notify_2d_btn_add_attributes.xml"
//   - "i_d_notify_2d_btn_add_disciplines.xml"
//   - "i_d_notify_2d_btn_add_medals.xml"
//   - "i_d_notify_2d_wnd_frame_left.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~177 non-empty decompiler lines.
//  - Control keywords: if×13, do×1, while×1, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×4, FUN_00424830×4, FUN_0079c860×4, FUN_0098c3f0×4, block×4, FUN_007b5dd0×3, FUN_00792600, FUN_008a0370.
//  - Strings: "i_d_notify_2d_wnd_bg_fill.xml"; "i_d_notify_2d_btn_add_skills.xml"; "i_d_notify_2d_btn_add_attributes.xml"; "i_d_notify_2d_btn_add_disciplines.xml".
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

/* WARNING: Removing unreachable block (ram,0x008b08b4) */

/* WARNING: Removing unreachable block (ram,0x008b0758) */

/* WARNING: Removing unreachable block (ram,0x008b0806) */

/* WARNING: Removing unreachable block (ram,0x008b0961) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_008b06a0(int *param_1)



{

  void *pvVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  int *piVar5;

  char *pcVar6;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b64e0;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x498);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0098c3f0(pvVar1);

  }

  local_4 = 0xffffffff;

  param_1[0x159] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x159] + 0x28))("i_d_notify_2d_wnd_bg_fill.xml");

  (**(code **)(*(int *)param_1[0x159] + 0x15c))(0,param_1 + 0x15d);

  (**(code **)(*(int *)param_1[0x159] + 0xcc))(0);

  CVOGReaction_RandomUnitScalar();

  uVar3 = FUN_00424830();

  *(float *)(param_1[0x159] + 0x494) = (float)(uVar3 % 1000) * _DAT_00aaabdc;

  pvVar1 = operator_new(0x498);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0098c3f0(pvVar1);

  }

  param_1[0x158] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x158] + 0x28))("i_d_notify_2d_wnd_bg_fill.xml");

  (**(code **)(*(int *)param_1[0x158] + 0x15c))(0,param_1 + 0x15c);

  (**(code **)(*(int *)param_1[0x158] + 0xcc))(0);

  CVOGReaction_RandomUnitScalar();

  uVar3 = FUN_00424830();

  *(float *)(param_1[0x158] + 0x494) = (float)(uVar3 % 1000) * _DAT_00aaabdc;

  pvVar1 = operator_new(0x498);

  iVar2 = 2;

  if (pvVar1 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_0098c3f0(pvVar1);

  }

  param_1[0x157] = iVar4;

  (**(code **)(*param_1 + 0xa8))(iVar4);

  (**(code **)(*(int *)param_1[0x157] + 0x28))("i_d_notify_2d_wnd_bg_fill.xml");

  (**(code **)(*(int *)param_1[0x157] + 0x15c))(0,param_1 + 0x15b);

  (**(code **)(*(int *)param_1[0x157] + 0xcc))(0);

  CVOGReaction_RandomUnitScalar();

  uVar3 = FUN_00424830();

  *(float *)(param_1[0x157] + 0x494) = (float)(uVar3 % 1000) * _DAT_00aaabdc;

  pvVar1 = operator_new(0x498);

  if (pvVar1 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_0098c3f0(pvVar1);

  }

  param_1[0x15a] = iVar4;

  (**(code **)(*param_1 + 0xa8))(iVar4);

  (**(code **)(*(int *)param_1[0x15a] + 0x28))("i_d_notify_2d_wnd_bg_fill.xml");

  (**(code **)(*(int *)param_1[0x15a] + 0x15c))(0,param_1 + 0x15e);

  (**(code **)(*(int *)param_1[0x15a] + 0xcc))(0);

  CVOGReaction_RandomUnitScalar();

  uVar3 = FUN_00424830();

  *(float *)(param_1[0x15a] + 0x494) = (float)(uVar3 % 1000) * _DAT_00aaabdc;

  pvVar1 = operator_new(0x4cc);

  iVar4 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar4 = FUN_0079c860();

  }

  param_1[0x155] = iVar4;

  (**(code **)(*param_1 + 0xa8))(iVar4);

  (**(code **)(*(int *)param_1[0x155] + 0x28))("i_d_notify_2d_btn_add_skills.xml");

  (**(code **)(*(int *)param_1[0x155] + 0x74))(2);

  (**(code **)(*(int *)param_1[0x155] + 0xcc))(0);

  pvVar1 = operator_new(0x4cc);

  iVar4 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar4 = FUN_0079c860();

  }

  param_1[0x154] = iVar4;

  (**(code **)(*param_1 + 0xa8))(iVar4);

  (**(code **)(*(int *)param_1[0x154] + 0x28))("i_d_notify_2d_btn_add_attributes.xml");

  (**(code **)(*(int *)param_1[0x154] + 0x74))(1);

  (**(code **)(*(int *)param_1[0x154] + 0xcc))(0);

  pvVar1 = operator_new(0x4cc);

  iVar4 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar4 = FUN_0079c860();

  }

  param_1[0x153] = iVar4;

  (**(code **)(*param_1 + 0xa8))(iVar4);

  (**(code **)(*(int *)param_1[0x153] + 0x28))("i_d_notify_2d_btn_add_disciplines.xml");

  (**(code **)(*(int *)param_1[0x153] + 0x74))(0);

  (**(code **)(*(int *)param_1[0x153] + 0xcc))(0);

  pvVar1 = operator_new(0x4cc);

  iVar4 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar4 = FUN_0079c860();

  }

  param_1[0x156] = iVar4;

  (**(code **)(*param_1 + 0xa8))(iVar4);

  (**(code **)(*(int *)param_1[0x156] + 0x28))("i_d_notify_2d_btn_add_medals.xml");

  (**(code **)(*(int *)param_1[0x156] + 0x74))(3);

  (**(code **)(*(int *)param_1[0x156] + 0xcc))(0);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x15f] = iVar4;

  (**(code **)(*param_1 + 0xa8))(iVar4);

  pcVar6 = "i_d_notify_2d_wnd_frame_left.xml";

  (**(code **)(*(int *)param_1[0x15f] + 0x28))();

  (**(code **)(*(int *)param_1[0x15f] + 0xcc))(0);

  piVar5 = param_1 + 0x160;

  do {

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar4 = 0;

    }

    else {

      iVar4 = FUN_007b5dd0(pvVar1,0);

    }

    *piVar5 = iVar4;

    (**(code **)(*param_1 + 0xa8))(iVar4);

    (**(code **)(*(int *)*piVar5 + 0x28))("i_d_notify_2d_wnd_frame_middle.xml");

    (**(code **)(*(int *)*piVar5 + 0xcc))(0);

    piVar5 = piVar5 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x162] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x162] + 0x28))("i_d_notify_2d_wnd_frame_right.xml");

  (**(code **)(*(int *)param_1[0x162] + 0xcc))(0);

  FUN_008af180(1);

  if (param_1[0xac] != 0) {

    FUN_008a0370();

  }

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar2 = param_1[0x1a];

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  ExceptionList = pcVar6;

  return;

}
