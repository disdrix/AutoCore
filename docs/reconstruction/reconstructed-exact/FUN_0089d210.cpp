// =============================================================================
// FUN_0089d210
// -----------------------------------------------------------------------------
// Stable ID: aa_0089d210
// Address:   0x0089d210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0089d210 @ 0x0089d210
// Stable ID: aa_0089d210
// Embedded strings (evidence for future rename):
//   - "i_d_ref_2d_wnd_instructions.xml"
//   - "i_d_ref_2d_wnd_warning.xml"
//   - "i_d_ref_2d_wnd_comp_info.xml"
//   - "i_d_ref_2d_wnd_comp_icon.xml"
//   - "i_d_ref_2d_btn_recipe_2.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~572 non-empty decompiler lines.
//  - Control keywords: if×43, do×1, while×1, return×1.
//  - Notable callees: FUN_007b5dd0×21, FUN_0079c860×8, FUN_0078b6e0×2, FUN_0078f890×2, FUN_007fbe50×2, FUN_0078e2f0, FUN_00792600, FUN_00795f20.
//  - Strings: "i_d_ref_2d_wnd_instructions.xml"; "i_d_ref_2d_wnd_warning.xml"; "i_d_ref_2d_wnd_comp_info.xml"; "i_d_ref_2d_wnd_comp_icon.xml".
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

void __fastcall FUN_0089d210(int *param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  float *pfVar8;

  int *unaff_EBX;

  char *pcVar9;

  int unaff_ESI;

  float fStack_338;

  int iStack_334;

  uint32_t /* width from decompiler */ uStack_330;

  char *pcStack_32c;

  uint32_t /* width from decompiler */ uStack_2f8;

  char *pcStack_2f4;

  char *pcStack_2f0;

  void *pvStack_2e4;

  char *pcStack_2e0;

  int iVar10;

  int *piStack_78;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009b982b;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  local_c = 0;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0();

  }

  local_c = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piStack_78 + 0x28))();

  (**(code **)(*unaff_EBX + 0xfc))();

  param_1[0x14f] = unaff_ESI;

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x4bc);

  if (pvVar1 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_00864f20();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(s_i_d_ref_2d_wnd_bg_fill_xml_00a4e8c4._0_4_ + 0xfc))();

  param_1[0x150] = 1;

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 != (void *)0x0) {

    FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar4 + 0x28))();

  (**(code **)(s_i_d_ref_2d_wnd_fx_xml_00a4e8ac._0_4_ + 0xfc))();

  param_1[0x151] = 1;

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x156] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x156] + 0x28))();

  (**(code **)(*(int *)param_1[0x156] + 0xfc))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x152] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x152] + 0x28))();

  (**(code **)(*(int *)param_1[0x152] + 0xfc))();

  (**(code **)(*param_1 + 0x404))();

  (**(code **)(s_i_d_ref_2d_wnd_icon_xml_00a4e858._0_4_ + 0xfc))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x162] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x162] + 0x28))();

  (**(code **)(*(int *)param_1[0x162] + 0xfc))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0();

  }

  param_1[0x163] = (int)piVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x163] + 0x28))();

  (**(code **)(*(int *)param_1[0x163] + 0xfc))();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 != (void *)0x0) {

    FUN_007b5dd0();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(s_i_d_ref_2d_wnd_divider_2_xml_00a4e7f8._0_4_ + 0xfc))();

  param_1[0x153] = 1;

  pvVar1 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x17c] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17c] + 0x28))();

  (**(code **)(*(int *)param_1[0x17c] + 0x74))();

  (**(code **)(*(int *)param_1[0x17c] + 0xd4))();

  (**(code **)(*(int *)param_1[0x17c] + 0xfc))();

  pvVar1 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x17d] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17d] + 0x28))();

  (**(code **)(*(int *)param_1[0x17d] + 0x74))();

  (**(code **)(*(int *)param_1[0x17d] + 0xd4))();

  (**(code **)(*(int *)param_1[0x17d] + 0xfc))();

  pvVar1 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x17e] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17e] + 0x28))();

  (**(code **)(*(int *)param_1[0x17e] + 0x74))();

  (**(code **)(*(int *)param_1[0x17e] + 0xd4))();

  (**(code **)(*(int *)param_1[0x17e] + 0xfc))();

  pvVar1 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x17f] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17f] + 0x28))();

  (**(code **)(*(int *)param_1[0x17f] + 0x74))();

  (**(code **)(*(int *)param_1[0x17f] + 0xd4))();

  (**(code **)(*(int *)param_1[0x17f] + 0xfc))();

  pvVar1 = operator_new(0x4a4);

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_00795f20();

  }

  param_1[0x182] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x182] + 0x28))();

  (**(code **)(*(int *)param_1[0x182] + 0x1d0))();

  (**(code **)(*(int *)param_1[0x182] + 0xd4))();

  (**(code **)(*(int *)param_1[0x182] + 0x3ac))();

  (**(code **)(*(int *)param_1[0x182] + 0x74))();

  *(uint8_t *)(param_1[0x182] + 0x48b) = 1;

  *(uint8_t *)(param_1[0x182] + 0x48d) = 1;

  (**(code **)(*(int *)param_1[0x182] + 0xfc))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x154] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x154] + 0x28))();

  (**(code **)(*(int *)param_1[0x154] + 0xfc))();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x180] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x180] + 0x28))();

  (**(code **)(*(int *)param_1[0x180] + 0xfc))();

  param_1[0x14d] = -1;

  pvVar1 = operator_new(0x938);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0078e2f0();

  }

  param_1[0x181] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x181] + 0x28))();

  (**(code **)(*(int *)param_1[0x181] + 0x43c))();

  (**(code **)(*(int *)param_1[0x181] + 0x74))();

  piVar2 = *(int **)(param_1[0x181] + 0x930);

  if (piVar2 != (int *)0x0) {

    *(uint8_t *)((int)piVar2 + 0x489) = 1;

    piVar4 = (int *)(**(code **)(*piVar2 + 0x170))();

    piVar2[0x8b] = *piVar4;

    piVar4 = (int *)__RTDynamicCast();

    if ((piVar4 != (int *)0x0) && ((int *)piVar4[0x12f] == piVar2)) {

      (**(code **)(*piVar4 + 0x1c8))();

      (**(code **)(*piVar4 + 0x3c0))();

    }

  }

  iVar3 = (**(code **)(*(int *)param_1[0x181] + 0x448))();

  param_1[0x14d] = iVar3;

  (**(code **)(*(int *)param_1[0x181] + 0x448))();

  (**(code **)(*(int *)param_1[0x181] + 0x448))();

  (**(code **)(*(int *)param_1[0x181] + 0x448))();

  (**(code **)(*(int *)param_1[0x181] + 0x448))();

  (**(code **)(*(int *)param_1[0x181] + 0x448))();

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(*piVar2 + 0x74))();

  (**(code **)(*piVar2 + 0xd4))();

  (**(code **)(*piVar2 + 0xfc))();

  param_1[0x155] = (int)piVar2;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(*piVar2 + 0x74))();

  (**(code **)(*piVar2 + 0xfc))();

  param_1[0x141] = (int)piVar2;

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0078b6e0();

  }

  param_1[0x15a] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15a] + 0x28))();

  (**(code **)(*(int *)param_1[0x15a] + 0x474))();

  (**(code **)(*(int *)param_1[0x15a] + 0x74))();

  (**(code **)(*(int *)param_1[0x15a] + 0x43c))();

  (**(code **)(*(int *)param_1[0x15a] + 0x4a0))();

  (**(code **)(*(int *)param_1[0x15a] + 0xfc))();

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0078b6e0();

  }

  param_1[0x15b] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15b] + 0x28))();

  (**(code **)(*(int *)param_1[0x15b] + 0x474))();

  (**(code **)(*(int *)param_1[0x15b] + 0x74))();

  (**(code **)(*(int *)param_1[0x15b] + 0x43c))();

  (**(code **)(*(int *)param_1[0x15b] + 0x4a0))();

  (**(code **)(*(int *)param_1[0x15b] + 0xfc))();

  pvVar1 = operator_new(0x954);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0078f890();

  }

  param_1[0x15c] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15c] + 0x28))();

  (**(code **)(*(int *)param_1[0x15c] + 0x43c))();

  (**(code **)(*(int *)param_1[0x15c] + 0x74))();

  (**(code **)(*(int *)param_1[0x15c] + 0xfc))();

  pvVar1 = operator_new(0x954);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0078f890();

  }

  param_1[0x15d] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15d] + 0x28))();

  (**(code **)(*(int *)param_1[0x15d] + 0x43c))();

  (**(code **)(*(int *)param_1[0x15d] + 0x74))();

  (**(code **)(*(int *)param_1[0x15d] + 0xfc))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x157] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x157] + 0x28))();

  (**(code **)(*(int *)param_1[0x157] + 0xfc))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x158] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x158] + 0x28))();

  (**(code **)(*(int *)param_1[0x158] + 0xfc))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x15f] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15f] + 0x28))();

  (**(code **)(*(int *)param_1[0x15f] + 0xfc))();

  (**(code **)(*(int *)param_1[0x15f] + 0x1d8))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x15e] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15e] + 0x28))();

  (**(code **)(*(int *)param_1[0x15e] + 0xfc))();

  (**(code **)(*(int *)param_1[0x15e] + 0x1d8))();

  pcStack_2e0 = (char *)0x89e017;

  pcStack_2e0 = operator_new(0x488);

  if (pcStack_2e0 == (char *)0x0) {

    iVar3 = 0;

  }

  else {

    pvStack_2e4 = (void *)0x89e031;

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x160] = iVar3;

  pcStack_2e0 = (char *)0x89e04a;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_2e0 = "i_d_ref_2d_wnd_instructions.xml";

  pvStack_2e4 = (void *)0x89e05a;

  (**(code **)(*(int *)param_1[0x160] + 0x28))();

  pvStack_2e4 = (void *)0x3f000000;

  (**(code **)(*(int *)param_1[0x160] + 0xfc))();

  pcStack_2f0 = (char *)0x89e079;

  pcStack_2f0 = operator_new(0x488);

  if (pcStack_2f0 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    pcStack_2f4 = (char *)0x89e093;

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x161] = iVar3;

  pcStack_2f0 = (char *)0x89e0ac;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_2f0 = "i_d_ref_2d_wnd_warning.xml";

  pcStack_2f4 = (char *)0x89e0bc;

  (**(code **)(*(int *)param_1[0x161] + 0x28))();

  pcStack_2f4 = (char *)0x3f000000;

  uStack_2f8 = 1;

  (**(code **)(*(int *)param_1[0x161] + 0xfc))();

  pcStack_2e0 = (char *)0x0;

  iVar10 = 0;

  piVar2 = param_1 + 0x164;

  do {

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar5 = 0;

    }

    else {

      iVar5 = FUN_007b5dd0();

    }

    *piVar2 = iVar5;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)*piVar2 + 0x28))();

    (**(code **)(*(int *)*piVar2 + 0xcc))();

    (**(code **)(*(int *)*piVar2 + 0x74))();

    pvStack_2e4 = (void *)(int)((float)DAT_00d1e81c * (float)iVar3 * DAT_00aaa678);

    iVar5 = (**(code **)(*(int *)*piVar2 + 0x120))();

    pcVar9 = pcStack_2f0 + *(int *)(iVar5 + 4);

    puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)*piVar2 + 0x120))();

    uStack_2f8 = *puVar6;

    pcStack_2f4 = pcVar9;

    (**(code **)(*(int *)*piVar2 + 0x110))();

    pcStack_32c = (char *)0x89e1bc;

    pcStack_32c = operator_new(0x488);

    if (pcStack_32c == (void *)0x0) {

      iVar5 = 0;

    }

    else {

      uStack_330 = 0x89e1d7;

      iVar5 = FUN_007b5dd0();

    }

    piVar2[5] = iVar5;

    pcStack_32c = (char *)0x89e1ed;

    (**(code **)(*param_1 + 0xa8))();

    pcStack_32c = "i_d_ref_2d_wnd_comp_info.xml";

    uStack_330 = 0x89e1fa;

    (**(code **)(*(int *)piVar2[5] + 0x28))();

    uStack_330 = 0;

    iStack_334 = 0x89e207;

    (**(code **)(*(int *)piVar2[5] + 0xcc))();

    iStack_334 = 0;

    fStack_338 = 1.4013e-45;

    (**(code **)(*(int *)piVar2[5] + 0x120))(&pcStack_2e0);

    iVar5 = 0;

    (**(code **)(*(int *)piVar2[5] + 0x120))(&pvStack_2e4,1,0);

    (**(code **)(*(int *)piVar2[5] + 0x110))(&stack0xfffffce8);

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar7 = 0;

    }

    else {

      iVar7 = FUN_007b5dd0(pvVar1,0);

    }

    piVar2[10] = iVar7;

    (**(code **)(*param_1 + 0xa8))(iVar7);

    (**(code **)(*(int *)piVar2[10] + 0x28))("i_d_ref_2d_wnd_comp_icon.xml");

    (**(code **)(*(int *)piVar2[10] + 0xcc))(0);

    iStack_334 = (int)((float)DAT_00d1e81c * fStack_338 * DAT_00aaa678);

    iVar7 = (**(code **)(*(int *)piVar2[10] + 0x120))(&uStack_2f8,1,0);

    iVar7 = *(int *)(iVar7 + 4);

    pfVar8 = (float *)(**(code **)(*(int *)piVar2[10] + 0x120))(&stack0xfffffd04,1,0);

    fStack_338 = *pfVar8;

    iStack_334 = iVar7 + iVar5;

    (**(code **)(*(int *)piVar2[10] + 0x110))(&fStack_338);

    pcStack_2e0 = pcStack_2e0 + 1;

    iVar10 = iVar10 + 0x44;

    piVar2 = piVar2 + 1;

  } while (iVar10 < 0x154);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x178] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x178] + 0x28))();

  (**(code **)(*(int *)param_1[0x178] + 0x74))();

  (**(code **)(*(int *)param_1[0x178] + 0xcc))();

  pvStack_2e4 = operator_new(0x488);

  if (pvStack_2e4 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x179] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x179] + 0x28))();

  (**(code **)(*(int *)param_1[0x179] + 0xcc))();

  pcStack_2f0 = operator_new(0x488);

  if (pcStack_2f0 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  param_1[0x17a] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17a] + 0x28))();

  (**(code **)(*(int *)param_1[0x17a] + 0xcc))();

  pvVar1 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x183] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_32c = (char *)0x89e4bd;

  (**(code **)(*(int *)param_1[0x183] + 0x28))();

  pcStack_32c = (char *)0x9c4d;

  uStack_330 = 0x89e4cd;

  (**(code **)(*(int *)param_1[0x183] + 0x74))();

  *(uint32_t /* width from decompiler */ *)(param_1[0x183] + 0x498) = 0x9c4f;

  uStack_330 = 0;

  iStack_334 = 0x89e4ee;

  (**(code **)(*(int *)param_1[0x183] + 0xcc))();

  iStack_334 = 1;

  fStack_338 = 1.266361e-38;

  (**(code **)(*(int *)param_1[0x183] + 0x3b4))();

  fStack_338 = 1.4013e-45;

  (**(code **)(*(int *)param_1[0x183] + 0x3c8))(1);

  pvVar1 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x184] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x184] + 0x28))("i_d_ref_2d_btn_recipe_2.xml");

  (**(code **)(*(int *)param_1[0x184] + 0x74))(0x9c4e);

  *(uint32_t /* width from decompiler */ *)(param_1[0x184] + 0x498) = 0x9c4f;

  (**(code **)(*(int *)param_1[0x184] + 0xcc))(0);

  (**(code **)(*(int *)param_1[0x184] + 0x3b4))(1);

  FUN_007fbe50();

  FUN_007fbe50();

  (**(code **)(*(int *)param_1[0x181] + 0x45c))(param_1[0x14b] + param_1[0x14d]);

  (**(code **)(*(int *)param_1[0x181] + 0x94))();

  FUN_0089c6c0(1);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pcStack_2e0;

  return;

}
