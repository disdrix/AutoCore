// =============================================================================
// FUN_0089e9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0089e9c0
// Address:   0x0089e9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0089e9c0 @ 0x0089e9c0
// Stable ID: aa_0089e9c0
// Embedded strings (evidence for future rename):
//   - "i_d_rnd_2d_wnd_divider_1.xml"
//   - "i_d_rnd_2d_wnd_bg_reverse_engineering.xml"
//   - "i_d_rnd_2d_btn_rnd_reverse_engineer.xml"
//   - "i_d_rnd_2d_btn_rnd_experimentation.xml"
//   - "i_d_rnd_2d_btn_rnd_memorization.xml"
//   - "i_d_rnd_2d_wnd_value_reverse_engineering.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~459 non-empty decompiler lines.
//  - Control keywords: if×39, for×2, return×1.
//  - Notable callees: FUN_007b5dd0×26, FUN_00824e10×4, FUN_00792600, FUN_0079c860, FUN_0089e9c0, FUN_008a05a0, sprintf.
//  - Strings: "i_d_rnd_2d_wnd_divider_1.xml"; "i_d_rnd_2d_wnd_bg_reverse_engineering.xml"; "i_d_rnd_2d_btn_rnd_reverse_engineer.xml"; "i_d_rnd_2d_btn_rnd_experimentation.xml".
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

/* WARNING: Restarted to delay deadcode elimination for space: ram */

/* WARNING: Restarted to delay deadcode elimination for space: stack */



void __fastcall FUN_0089e9c0(int *param_1)



{

  char cVar1;

  void *pvVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int *unaff_EBX;

  int *unaff_EBP;

  int unaff_ESI;

  void *pvStack_1d0;

  char *pcVar8;

  char *pcVar9;

  void *pvStack_dc;

  uint32_t /* width from decompiler */ **ppuStack_d8;

  int *piStack_d4;

  char *pcStack_d0;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b60d3;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar2 = operator_new(0x488);

  local_4 = 0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*unaff_EBX + 0x28))();

  (**(code **)(*unaff_EBP + 0xfc))();

  param_1[0x148] = iVar3;

  (**(code **)(*param_1 + 0x404))();

  (*(code *)puRam00000001[0x3f])();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(iRam3f000000 + 0x28))();

  (*(code *)puRam00000001[0x3f])();

  param_1[0x147] = iVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(s_i_d_rnd_2d_wnd_title_xml_00a4dd44._0_4_ + 0x28))();

  (**(code **)(iRam3f000000 + 0xfc))();

  param_1[0x160] = iVar3;

  pcStack_d0 = (char *)0x89eb71;

  pcStack_d0 = operator_new(0x488);

  if (pcStack_d0 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    piStack_d4 = (int *)0x89eb8b;

    iVar3 = FUN_007b5dd0();

  }

  pcStack_d0 = (char *)0x89eba2;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_d0 = "i_d_rnd_2d_wnd_divider_1.xml";

  piStack_d4 = (int *)0x89ebb0;

  (**(code **)(s_i_d_rnd_2d_wnd_bg_points_remaini_00a4dd1c._0_4_ + 0x28))();

  piStack_d4 = &iRam3f000000;

  ppuStack_d8 = &puRam00000001;

  pvStack_dc = (void *)0x89ebc3;

  (**(code **)(iRam3f000000 + 0xfc))();

  param_1[0x165] = iVar3;

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  pvStack_dc = (void *)0x1;

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    pcStack_d0 = (char *)0x0;

  }

  else {

    pcStack_d0 = (char *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piStack_d4 + 0x28))();

  (*(code *)(*ppuStack_d8)[0x3f])();

  param_1[0x15b] = unaff_ESI;

  pvStack_dc = operator_new(0x4cc);

  if (pvStack_dc == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(*piVar4 + 0x74))();

  (**(code **)(*piVar4 + 0xfc))();

  param_1[0x168] = (int)piVar4;

  pvVar2 = operator_new(0x488);

  if (pvVar2 != (void *)0x0) {

    FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(s_i_d_rnd_2d_btn_activate_reverse__00a4dca0._0_4_ + 0x28))();

  (**(code **)(iRam00009c4f + 0xfc))();

  param_1[0x15a] = 1;

  if (DAT_00d1b6d8 != 0) {

    sprintf((char *)&pvStack_dc,"%i");

    (**(code **)(*(int *)param_1[0x15a] + 0x1d8))();

  }

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  pcVar9 = "i_d_rnd_2d_wnd_bg_reverse_engineering.xml";

  (**(code **)(s_i_d_rnd_2d_wnd_discipline_points_00a4dc70._0_4_ + 0x28))();

  (**(code **)(iRam3f000000 + 0xfc))();

  param_1[0x15c] = 1;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(*(int *)pcVar9 + 0xfc))();

  param_1[0x15d] = 1;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(s_i_d_rnd_2d_wnd_bg_experimentatio_00a4dc1c._0_4_ + 0xfc))();

  param_1[0x15e] = 1;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(s_i_d_rnd_2d_wnd_bg_memorization_x_00a4dbf8._0_4_ + 0xfc))();

  param_1[0x15f] = 1;

  pvVar2 = operator_new(0x488);

  ppuStack_d8 = (uint32_t /* width from decompiler */ **)0xb;

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0();

  }

  ppuStack_d8 = (uint32_t /* width from decompiler */ **)0xffffffff;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(s_i_d_rnd_2d_wnd_bg_gadgeting_xml_00a4dbd8._0_4_ + 0xfc))();

  param_1[0x156] = 1;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(s_i_d_rnd_2d_wnd_label_reverse_eng_00a4dba8._0_4_ + 0xfc))();

  param_1[0x157] = 1;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar5 + 0x28))();

  (**(code **)(s_i_d_rnd_2d_wnd_label_experimenta_00a4db7c._0_4_ + 0xfc))();

  param_1[0x158] = 1;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(s_i_d_rnd_2d_wnd_label_memorizatio_00a4db54._0_4_ + 0xfc))();

  param_1[0x159] = 1;

  puVar6 = operator_new(0x488);

  if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0();

  }

  pcVar9 = "i_d_rnd_2d_btn_rnd_reverse_engineer.xml";

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(*piVar5 + 0x120))();

  (*(code *)*puRam00000001)();

  puVar7 = operator_new(0x488);

  if (puVar7 == (uint32_t /* width from decompiler */ *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0();

  }

  pcVar8 = "i_d_rnd_2d_btn_rnd_experimentation.xml";

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(*(int *)pcVar9 + 0x120))();

  if (&stack0x00000000 != (uint8_t *)0x184) {

    (*(code *)*puVar6)();

  }

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0();

  }

  pcVar9 = "i_d_rnd_2d_btn_rnd_memorization.xml";

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(*(int *)pcVar8 + 0x120))();

  if (&stack0x00000000 != (uint8_t *)0x18c) {

    pvStack_1d0 = (void *)0x89f236;

    (*(code *)*piVar5)();

  }

  pvStack_1d0 = (void *)0x89f244;

  pvStack_1d0 = operator_new(0x488);

  if (pvStack_1d0 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_007b5dd0();

  }

  pvStack_1d0 = (void *)0x89f27c;

  (**(code **)(*piVar4 + 0x28))();

  pvStack_1d0 = (void *)0x0;

  (**(code **)(*(int *)pcVar9 + 0x120))();

  if (&stack0x00000000 != (uint8_t *)0x194) {

    (*(code *)*puVar7)();

  }

  pvVar2 = operator_new(0x510);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_00824e10();

  }

  param_1[0x14e] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14e] + 0x114))();

  (**(code **)(*(int *)param_1[0x14e] + 0x43c))();

  (**(code **)(*(int *)param_1[0x14e] + 0x74))();

  piVar4 = (int *)param_1[0x14e];

  piVar4[0x141] = 1;

  (**(code **)(*piVar4 + 0x444))();

  (**(code **)(*piVar4 + 0x34c))();

  (**(code **)(*(int *)param_1[0x14e] + 0xfc))(1);

  pvVar2 = operator_new(0x510);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_00824e10(pvVar2);

  }

  param_1[0x14f] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x14f] + 0x114))(&pvStack_1d0);

  (**(code **)(*(int *)param_1[0x14f] + 0x43c))();

  (**(code **)(*(int *)param_1[0x14f] + 0x74))(0x9c42);

  piVar4 = (int *)param_1[0x14f];

  piVar4[0x141] = 0;

  (**(code **)(*piVar4 + 0x444))();

  (**(code **)(*piVar4 + 0x34c))();

  (**(code **)(*(int *)param_1[0x14f] + 0xfc))(1,0x3f000000);

  pvVar2 = operator_new(0x510);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_00824e10(pvVar2);

  }

  param_1[0x150] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x150] + 0x114))(&stack0xfffffe24);

  (**(code **)(*(int *)param_1[0x150] + 0x43c))();

  (**(code **)(*(int *)param_1[0x150] + 0x74))(0x9c43);

  piVar4 = (int *)param_1[0x150];

  piVar4[0x141] = 2;

  (**(code **)(*piVar4 + 0x444))();

  (**(code **)(*piVar4 + 0x34c))();

  (**(code **)(*(int *)param_1[0x150] + 0xfc))(1,0x3f000000);

  pvVar2 = operator_new(0x510);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_00824e10(pvVar2);

  }

  param_1[0x151] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x151] + 0x114))();

  (**(code **)(*(int *)param_1[0x151] + 0x43c))();

  (**(code **)(*(int *)param_1[0x151] + 0x74))();

  piVar4 = (int *)param_1[0x151];

  piVar4[0x141] = 3;

  (**(code **)(*piVar4 + 0x444))();

  (**(code **)(*piVar4 + 0x34c))();

  (**(code **)(*(int *)param_1[0x151] + 0xfc))(1,0x3f000000);

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))();

  pcVar9 = "i_d_rnd_2d_wnd_value_reverse_engineering.xml";

  (*pcRam3f000028)();

  (**(code **)(iRam00009c44 + 0xfc))(1);

  param_1[0x161] = iVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))();

  pcVar8 = "i_d_rnd_2d_wnd_value_experimentation.xml";

  (**(code **)(*(int *)pcVar9 + 0x28))();

  (**(code **)(iRam3f000000 + 0xfc))(1);

  param_1[0x162] = iVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))();

  pcVar9 = "i_d_rnd_2d_wnd_value_memorization.xml";

  (**(code **)(*(int *)pcVar8 + 0x28))();

  (**(code **)(iRam3f000000 + 0xfc))(1);

  param_1[0x163] = iVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))();

  pcVar8 = "i_d_rnd_2d_wnd_value_gadgeting.xml";

  (**(code **)(*(int *)pcVar9 + 0x28))();

  (**(code **)(iRam3f000000 + 0xfc))(1);

  param_1[0x164] = iVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))();

  pcVar9 = "i_d_rnd_2d_wnd_preview_reverse_engineering.xml";

  (**(code **)(*(int *)pcVar8 + 0x28))();

  (**(code **)(iRam3f000000 + 0xfc))(1);

  param_1[0x16d] = iVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))();

  pcVar8 = "i_d_rnd_2d_wnd_preview_experimentation.xml";

  (**(code **)(*(int *)pcVar9 + 0x28))();

  (**(code **)(iRam3f000000 + 0xfc))(1);

  param_1[0x16e] = iVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))();

  pcVar9 = "i_d_rnd_2d_wnd_preview_memorization.xml";

  (**(code **)(*(int *)pcVar8 + 0x28))();

  (**(code **)(iRam3f000000 + 0xfc))(1);

  param_1[0x16f] = iVar3;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)pcVar9 + 0x28))("i_d_rnd_2d_wnd_preview_gadgeting.xml");

  (**(code **)(iRam3f000000 + 0xfc))(1,0x3f000000);

  param_1[0x170] = iVar3;

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  DAT_00d17929 = 0;

  if ((DAT_00d1b8f0 != (int *)0x0) &&

     (cVar1 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar1 != '\0')) {

    FUN_008a05a0();

  }

  ExceptionList = &iRam3f000000;

  return;

}
