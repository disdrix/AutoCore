// =============================================================================
// FUN_008b1f80
// -----------------------------------------------------------------------------
// Stable ID: aa_008b1f80
// Address:   0x008b1f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b1f80 @ 0x008b1f80
// Stable ID: aa_008b1f80
// Embedded strings (evidence for future rename):
//   - "i_d_map2.xml"
//   - "i_d_map2_2d_wnd_frame.xml"
//   - "i_d_map2_2d_wnd_frame_bottom.xml"
//   - "i_d_map2_2d_wnd_frame_right.xml"
//   - "i_d_map2_2d_wnd_frame_world_map.xml"
//   - "i_d_map2_2d_btn_world_map.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~147 non-empty decompiler lines.
//  - Control keywords: if×11, return×1.
//  - Notable callees: FUN_0079c860×3, FUN_007b5dd0×2, FUN_0078e2f0, FUN_00792600, FUN_008b1430, FUN_008b1f80, __RTDynamicCast.
//  - Strings: "i_d_map2.xml"; "i_d_map2_2d_wnd_frame.xml"; "i_d_map2_2d_wnd_frame_bottom.xml"; "i_d_map2_2d_wnd_frame_right.xml".
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

void __fastcall FUN_008b1f80(int *param_1)



{

  int *piVar1;

  int iVar2;

  void *pvVar3;

  void *pvVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  char *pcStack_2c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b9aed;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pcStack_2c = (char *)0x8b1fad;

  pcStack_2c = operator_new(0x488);

  local_4 = 0;

  if (pcStack_2c == (char *)0x0) {

    iVar2 = 0;

  }

  else {

    uStack_30 = 0x8b1fc5;

    iVar2 = FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  param_1[0x144] = iVar2;

  pcStack_2c = (char *)0x8b1fe1;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_2c = "i_d_map2.xml";

  uStack_30 = 0x8b1ff1;

  (**(code **)(*(int *)param_1[0x144] + 0x28))();

  uStack_30 = 0x9c46;

  uStack_34 = 0x8b2001;

  (**(code **)(*(int *)param_1[0x144] + 0x74))();

  uStack_34 = 1;

  (**(code **)(*(int *)param_1[0x144] + 0xcc))();

  (**(code **)(*(int *)param_1[0x144] + 0x15c))(0,&stack0xffffffdc);

  pcStack_2c = (char *)0x0;

  (**(code **)(*(int *)param_1[0x144] + 0x15c))(1,&pcStack_2c);

  uStack_34 = 0;

  uStack_30 = 0;

  (**(code **)(*(int *)param_1[0x144] + 0x110))(&uStack_34);

  *(uint8_t *)(param_1[0x144] + 0xc4) = 1;

  *(uint8_t *)(param_1[0x144] + 0xc5) = 0;

  if (param_1[0x14e] != 0) {

    (**(code **)(*param_1 + 0xa8))(param_1[0x14e]);

    (**(code **)(*(int *)param_1[0x14e] + 0x43c))();

    (**(code **)(*(int *)param_1[0x14e] + 0x74))(0x9c45);

    (**(code **)(*(int *)param_1[0x14e] + 0xfc))(1,0x3f000000);

    iVar2 = param_1[0x1a] + 1;

    param_1[0x1a] = iVar2;

    param_1[0x1d] = (int)(float)-iVar2;

    if (param_1[0x1c] < iVar2) {

      param_1[0x1c] = iVar2;

    }

    (**(code **)(*param_1 + 0x3f4))(1);

  }

  pvVar3 = operator_new(0x488);

  if (pvVar3 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar3,0);

  }

  param_1[0x143] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x143] + 0x28))("i_d_map2_2d_wnd_frame.xml");

  (**(code **)(*(int *)param_1[0x143] + 0xfc))(1,0x3f000000);

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x145,"i_d_map2_2d_wnd_frame_bottom.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x146,"i_d_map2_2d_wnd_frame_right.xml",0xffffffff);

  (**(code **)(*param_1 + 0x404))(param_1 + 0x147,"i_d_map2_2d_wnd_frame_world_map.xml",0xffffffff);

  (**(code **)(*(int *)param_1[0x145] + 0xcc))(0);

  (**(code **)(*(int *)param_1[0x146] + 0xcc))(0);

  (**(code **)(*(int *)param_1[0x147] + 0xcc))(0);

  (**(code **)(*param_1 + 0x408))(param_1 + 0x14c,"i_d_map2_2d_btn_world_map.xml",0x9c44);

  (**(code **)(*(int *)param_1[0x14c] + 0xcc))(0);

  pvVar3 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar3 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14a] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14a] + 0x28))("i_d_map2_2d_btn_zoom_in.xml");

  (**(code **)(*(int *)param_1[0x14a] + 0x74))(0x9c42);

  (**(code **)(*(int *)param_1[0x14a] + 0xcc))(0);

  pvVar3 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar3 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x14b] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x14b] + 0x28))("i_d_map2_2d_btn_zoom_out.xml");

  (**(code **)(*(int *)param_1[0x14b] + 0x74))(0x9c43);

  (**(code **)(*(int *)param_1[0x14b] + 0xcc))(0);

  pvVar3 = operator_new(0x4cc);

  pvVar4 = (void *)0x0;

  if (pvVar3 != (void *)0x0) {

    pvVar4 = (void *)FUN_0079c860();

  }

  param_1[0x148] = (int)pvVar4;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x148] + 0x28))("i_d_map2_2d_btn_change_instances.xml");

  (**(code **)(*(int *)param_1[0x148] + 0x74))(0x9c41);

  (**(code **)(*(int *)param_1[0x148] + 0xcc))(0);

  pvVar3 = operator_new(0x938);

  if (pvVar3 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078e2f0();

  }

  param_1[0x149] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x149] + 0x28))("i_d_map2_2d_cb_instances.xml");

  (**(code **)(*(int *)param_1[0x149] + 0x43c))();

  (**(code **)(*(int *)param_1[0x149] + 0xcc))(0);

  *(uint8_t *)(param_1[0x149] + 0x4fe) = 0;

  piVar1 = *(int **)(param_1[0x149] + 0x930);

  if (piVar1 != (int *)0x0) {

    *(uint8_t *)((int)piVar1 + 0x489) = 1;

    piVar5 = (int *)(**(code **)(*piVar1 + 0x170))(0xb);

    piVar1[0x8b] = *piVar5;

    piVar5 = (int *)__RTDynamicCast(piVar1[0xac],0,&CNDUIWindow::RTTI_Type_Descriptor,

                                    &CNDUIDialog::RTTI_Type_Descriptor,0);

    if ((piVar5 != (int *)0x0) && ((int *)piVar5[0x12f] == piVar1)) {

      (**(code **)(*piVar5 + 0x1c8))(0);

      (**(code **)(*piVar5 + 0x3c0))(0);

    }

  }

  FUN_008b1430();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar4;

  return;

}
