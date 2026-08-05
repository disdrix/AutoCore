// =============================================================================
// UI_reg_icon_cover
// -----------------------------------------------------------------------------
// Stable ID: aa_008999b0
// Address:   0x008999b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_reg_icon_cover @ 0x008999b0
// Stable ID: aa_008999b0
// Embedded strings (evidence for future rename):
//   - "i_d_reg_2d_wnd_icon.xml"
//   - "i_d_reg_2d_wnd_icon_cover.xml"
//   - "i_d_reg_2d_btn_close.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~170 non-empty decompiler lines.
//  - Control keywords: if×16, return×1.
//  - Notable callees: FUN_007b5dd0×4, FUN_0079c860×2, FUN_0078e2f0, FUN_00792600, FUN_00864f20, FUN_00899030, FUN_00899300, UI_reg_icon_cover.
//  - Strings: "i_d_reg_2d_wnd_icon.xml"; "i_d_reg_2d_wnd_icon_cover.xml"; "i_d_reg_2d_btn_close.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_reg_2d_wnd_icon_cover.xml"
 * Domain alias of FUN_008999b0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_reg_icon_cover(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *unaff_EBX;

  int *unaff_ESI;

  void *pvVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b9695;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*unaff_EBX + 0x28))();

  (**(code **)(*unaff_ESI + 0xfc))();

  param_1[0x143] = iVar2;

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x4bc);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00864f20();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(iRam3f000000 + 0x28))();

  (**(code **)(iRam00000001 + 0xfc))();

  param_1[0x143] = iVar2;

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(iRam3f000000 + 0x28))();

  (**(code **)(iRam00000001 + 0xfc))();

  param_1[0x144] = iVar2;

  iVar2 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar2;

  param_1[0x1d] = (int)(float)-iVar2;

  if (param_1[0x1c] < iVar2) {

    param_1[0x1c] = iVar2;

  }

  (**(code **)(*param_1 + 0x3f4))();

  if (param_1[0x14d] != 0) {

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)param_1[0x14d] + 0x43c))();

    if (*(int *)(param_1[0x14d] + 0x59c) == 0) {

      *(int *)(param_1[0x14d] + 0x59c) = param_1[0x14f];

    }

    (**(code **)(*(int *)param_1[0x14d] + 0x74))();

    (**(code **)(*(int *)param_1[0x14d] + 0xfc))();

    iVar2 = param_1[0x1a] + 1;

    param_1[0x1a] = iVar2;

    param_1[0x1d] = (int)(float)-iVar2;

    if (param_1[0x1c] < iVar2) {

      param_1[0x1c] = iVar2;

    }

    (**(code **)(*param_1 + 0x3f4))();

  }

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar3 + 0x28))();

  (**(code **)(*piVar3 + 0x74))();

  (**(code **)(*piVar3 + 0xfc))();

  param_1[0x148] = (int)piVar3;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(iRam00009c43 + 0x28))();

  (**(code **)(iRam3f000000 + 0xfc))();

  param_1[0x149] = iVar2;

  pvVar1 = operator_new(0x938);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078e2f0();

  }

  param_1[0x14a] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14a] + 0x28))();

  (**(code **)(*(int *)param_1[0x14a] + 0x43c))();

  (**(code **)(*(int *)param_1[0x14a] + 0xfc))();

  *(uint8_t *)(param_1[0x14a] + 0x4fe) = 0;

  piVar3 = *(int **)(param_1[0x14a] + 0x930);

  if (piVar3 != (int *)0x0) {

    *(uint8_t *)((int)piVar3 + 0x489) = 1;

    piVar4 = (int *)(**(code **)(*piVar3 + 0x170))(0xb);

    piVar3[0x8b] = *piVar4;

    piVar4 = (int *)__RTDynamicCast(piVar3[0xac],0,&CNDUIWindow::RTTI_Type_Descriptor,

                                    &CNDUIDialog::RTTI_Type_Descriptor,0);

    if ((piVar4 != (int *)0x0) && ((int *)piVar4[0x12f] == piVar3)) {

      (**(code **)(*piVar4 + 0x1c8))(0);

      (**(code **)(*piVar4 + 0x3c0))(0);

    }

  }

  FUN_00899300();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1);

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(s_i_d_reg_2d_cb_instances_xml_00a4edb0._0_4_ + 0x28))("i_d_reg_2d_wnd_icon.xml");

  piVar3 = (int *)0x1;

  (**(code **)(iRam3f000000 + 0xfc))(1,0x3f000000);

  param_1[0x146] = iVar2;

  (**(code **)(*param_1 + 0x404))(&stack0xffffff6c,"i_d_reg_2d_wnd_icon_cover.xml",0xffffffff);

  pvVar5 = (void *)0x1;

  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar3);

  (**(code **)(*piVar3 + 0x28))("i_d_reg_2d_btn_close.xml");

  (**(code **)(*piVar3 + 0x74))(40000);

  (**(code **)(*piVar3 + 0xfc))(1,0x3f000000);

  param_1[0x141] = (int)piVar3;

  FUN_00899030();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar5;

  return;

}
