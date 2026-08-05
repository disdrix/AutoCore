// =============================================================================
// FUN_00854a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00854a20
// Address:   0x00854a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00854a20 @ 0x00854a20
// Stable ID: aa_00854a20
// Embedded strings (evidence for future rename):
//   - "i_w_pb_wnd_bg_texture.xml"
//   - "i_w_pb_gauge.xml"
//   - "i_w_pb_wnd_label_inside.xml"
//   - "i_w_pb_wnd_label_outside.xml"
//   - "i_w_pb_wnd_fg_texture.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_007b5dd0×4, FUN_00792600, FUN_00854a20, FUN_0097ffa0.
//  - Strings: "i_w_pb_wnd_bg_texture.xml"; "i_w_pb_gauge.xml"; "i_w_pb_wnd_label_inside.xml"; "i_w_pb_wnd_label_outside.xml".
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

void __fastcall FUN_00854a20(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  char *pcVar7;

  char *pcVar8;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b86c9;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  local_4 = 0xffffffff;

  param_1[0x144] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  pcVar8 = "i_w_pb_wnd_bg_texture.xml";

  (**(code **)(*(int *)param_1[0x144] + 0x28))("i_w_pb_wnd_bg_texture.xml");

  pvVar1 = operator_new(0x4f8);

  pvStack_c = (void *)0x1;

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0097ffa0(pvVar1);

  }

  pvStack_c = (void *)0xffffffff;

  param_1[0x146] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3,pcVar8,iVar2,pvVar1);

  pcVar8 = "i_w_pb_gauge.xml";

  (**(code **)(*(int *)param_1[0x146] + 0x28))("i_w_pb_gauge.xml");

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_007b5dd0(pvVar4,0);

  }

  param_1[0x147] = iVar5;

  (**(code **)(*param_1 + 0xa8))(iVar5,pcVar8,iVar3,pvVar4,iVar2,pvVar1,0xffffffff);

  pcVar8 = "i_w_pb_wnd_label_inside.xml";

  (**(code **)(*(int *)param_1[0x147] + 0x28))("i_w_pb_wnd_label_inside.xml");

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x148] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,pcVar8,iVar5,pvVar1,iVar3,pvVar4,0xffffffff);

  pcVar7 = "i_w_pb_wnd_label_outside.xml";

  (**(code **)(*(int *)param_1[0x148] + 0x28))();

  uVar6 = 1;

  iVar2 = (**(code **)(*(int *)param_1[0x148] + 0x164))(1);

  *(uint8_t *)(param_1 + 0x149) = *(uint8_t *)(iVar2 + 3);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x145] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2,uVar6,pcVar7,pvVar1,pcVar8,iVar5,0xffffffff);

  (**(code **)(*(int *)param_1[0x145] + 0x28))("i_w_pb_wnd_fg_texture.xml");

  ExceptionList = pcVar7;

  return;

}
