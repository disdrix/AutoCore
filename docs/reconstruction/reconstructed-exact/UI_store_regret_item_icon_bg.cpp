// =============================================================================
// UI_store_regret_item_icon_bg
// -----------------------------------------------------------------------------
// Stable ID: aa_0088f8e0
// Address:   0x0088f8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_store_regret_item_icon_bg @ 0x0088f8e0
// Stable ID: aa_0088f8e0
// Embedded strings (evidence for future rename):
//   - "i_d_store_regret_2d_wnd_item_icon_bg.xml"
//   - "i_d_store_regret_2d_wnd_item_icon.xml"
//   - "Junkyard"
//   - "%s: %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~290 non-empty decompiler lines.
//  - Control keywords: if×29, for×3, return×2.
//  - Notable callees: FUN_007b5dd0×16, FUN_007a6de0×3, FUN_00792600, FUN_0079c860, FUN_007a69d0, FUN_007fef20, FUN_00860700, FUN_00864f20.
//  - Strings: "i_d_store_regret_2d_wnd_item_icon_bg.xml"; "i_d_store_regret_2d_wnd_item_icon.xml"; "Junkyard"; "%s: %s".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_store_regret_2d_wnd_item_icon_bg.xml"
 * Domain alias of FUN_0088f8e0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Heritage AFTER dead removal. Example location: r0x3f000000 : 0x0088fb97 */

/* WARNING: Restarted to delay deadcode elimination for space: ram */

/* WARNING: Restarted to delay deadcode elimination for space: stack */



void __fastcall UI_store_regret_item_icon_bg(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *unaff_EBX;

  int unaff_EBP;

  int unaff_EDI;

  uint32_t /* width from decompiler */ *puVar7;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009b95ec;

  local_14 = ExceptionList;

  ExceptionList = &local_14;

  FUN_00792600();

  pvVar1 = Object_ResolveFromTFID((TFID_16 *)(param_1 + 0x14a));

  if ((pvVar1 != (void *)0x0) && (*(int *)(*(int *)((int)pvVar1 + 0xa8) + 0x38) == 0x16)) {

    iVar2 = __RTDynamicCast();

    param_1[0x162] = iVar2;

    if (iVar2 == 0) {

      (**(code **)(*param_1 + 0x440))();

      ExceptionList = local_14;

      return;

    }

    pvVar1 = operator_new(0x488);

    local_c = 0;

    if (pvVar1 != (void *)0x0) {

      FUN_007b5dd0();

    }

    local_c = 0xffffffff;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*unaff_EBX + 0x28))();

    (**(code **)(unaff_EBP + 0xfc))();

    param_1[0x163] = unaff_EDI;

    iVar2 = param_1[0x1a] + 1;

    param_1[0x1a] = iVar2;

    param_1[0x1d] = (int)(float)-iVar2;

    if (param_1[0x1c] < iVar2) {

      param_1[0x1c] = iVar2;

    }

    (**(code **)(*param_1 + 0x3f4))();

    pvVar1 = operator_new(0x4bc);

    if (pvVar1 != (void *)0x0) {

      FUN_00864f20();

    }

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(s_i_d_shop_2d_wnd_bg_fill_xml_00a52bc0._0_4_ + 0x28))();

    (**(code **)(iRam3f000000 + 0xfc))();

    param_1[0x164] = 1;

    iVar2 = param_1[0x1a] + 1;

    param_1[0x1a] = iVar2;

    param_1[0x1d] = (int)(float)-iVar2;

    if (param_1[0x1c] < iVar2) {

      param_1[0x1c] = iVar2;

    }

    (**(code **)(*param_1 + 0x3f4))();

    pvVar1 = operator_new(0x488);

    if (pvVar1 != (void *)0x0) {

      FUN_007b5dd0();

    }

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(s_i_d_shop_2d_wnd_fx_xml_00a52ba8._0_4_ + 0x28))();

    (**(code **)(iRam3f000000 + 0xfc))();

    param_1[0x165] = 1;

    iVar2 = param_1[0x1a] + 1;

    param_1[0x1a] = iVar2;

    param_1[0x1d] = (int)(float)-iVar2;

    if (param_1[0x1c] < iVar2) {

      param_1[0x1c] = iVar2;

    }

    (**(code **)(*param_1 + 0x3f4))();

    pvVar1 = operator_new(0x488);

    if (pvVar1 != (void *)0x0) {

      FUN_007b5dd0();

    }

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(s_i_d_shop_2d_wnd_bg_texture_xml_00a52b88._0_4_ + 0x28))();

    (**(code **)(iRam3f000000 + 0xfc))();

    param_1[0x167] = 1;

    (**(code **)(*param_1 + 0x404))();

    (**(code **)(iRam3f000000 + 0xfc))();

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = (int *)FUN_007b5dd0();

    }

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(s_i_d_shop_2d_wnd_icon_cover_xml_00a52b4c._0_4_ + 0x28))();

    (*pcRam000000fd)();

    param_1[0x166] = 1;

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      piVar4 = (int *)0x0;

    }

    else {

      piVar4 = (int *)FUN_007b5dd0();

    }

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*piVar3 + 0x28))();

    (**(code **)(s_i_d_shop_2d_wnd_bg_grid_xml_00a52b30._0_4_ + 0xfc))();

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = (int *)FUN_007b5dd0();

    }

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*piVar4 + 0x28))();

    (**(code **)(s_i_d_shop_2d_wnd_inventory_bg_xml_00a52b0c._0_4_ + 0xfc))();

    pvVar1 = operator_new(0x488);

    if (pvVar1 != (void *)0x0) {

      FUN_007b5dd0();

    }

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*piVar3 + 0x28))();

    (**(code **)(s_i_d_shop_2d_wnd_bg_filters_xml_00a52aec._0_4_ + 0xfc))();

    iVar2 = param_1[0x1a] + 1;

    param_1[0x1a] = iVar2;

    param_1[0x1d] = (int)(float)-iVar2;

    if (param_1[0x1c] < iVar2) {

      param_1[0x1c] = iVar2;

    }

    (**(code **)(*param_1 + 0x3f4))();

    pvVar1 = operator_new(0x5bc);

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      (**(code **)(*param_1 + 0x1a0))();

      iVar2 = FUN_008c1040();

    }

    param_1[0x16c] = iVar2;

    *(uint8_t *)(iVar2 + 0x534) = *(uint8_t *)(param_1[0x162] + 0x4e6);

    (**(code **)(*(int *)param_1[0x16c] + 0x43c))();

    piVar3 = (int *)param_1[0x16c];

    (**(code **)(*param_1 + 0xa8))();

    *(uint32_t /* width from decompiler */ *)(param_1[0x16c] + 0x554) = *(uint32_t /* width from decompiler */ *)(param_1[0x162] + 0x35c);

    (**(code **)(*(int *)param_1[0x16c] + 0xfc))();

    (**(code **)(*(int *)param_1[0x16c] + 0x94))();

    iVar2 = param_1[0x1a] + 1;

    param_1[0x1a] = iVar2;

    param_1[0x1d] = (int)(float)-iVar2;

    if (param_1[0x1c] < iVar2) {

      param_1[0x1c] = iVar2;

    }

    (**(code **)(*param_1 + 0x3f4))();

    pvVar1 = operator_new(0x488);

    if (pvVar1 != (void *)0x0) {

      FUN_007b5dd0();

    }

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*piVar3 + 0x28))();

    param_1[0x168] = 0x3f000000;

    pvVar1 = operator_new(0x488);

    if (pvVar1 != (void *)0x0) {

      FUN_007b5dd0();

    }

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(iRam00000001 + 0x28))();

    param_1[0x169] = 1;

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

    param_1[0x141] = (int)piVar3;

    param_1[0x127] = 40000;

    if (param_1[0x16c] != 0) {

      FUN_008c0d10();

    }

    if (param_1[0x16b] != 0) {

      FUN_00860700();

    }

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_007b5dd0();

    }

    param_1[0x16d] = iVar2;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)param_1[0x16d] + 0x28))();

    (**(code **)(*(int *)param_1[0x16d] + 0xcc))();

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_007b5dd0();

    }

    param_1[0x16e] = iVar2;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)param_1[0x16e] + 0x28))();

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_007b5dd0();

    }

    param_1[0x16f] = iVar2;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)param_1[0x16f] + 0x28))();

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_007b5dd0();

    }

    param_1[0x170] = iVar2;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)param_1[0x170] + 0x28))();

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_007b5dd0();

    }

    param_1[0x171] = iVar2;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)param_1[0x171] + 0x28))();

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_007b5dd0(pvVar1);

    }

    param_1[0x172] = iVar2;

    (**(code **)(*param_1 + 0xa8))();

    (**(code **)(*(int *)param_1[0x172] + 0x28))("i_d_store_regret_2d_wnd_item_icon_bg.xml");

    (**(code **)(*(int *)param_1[0x172] + 0x74))(0x9c48);

    pvVar1 = operator_new(0x488);

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_007b5dd0(pvVar1,0);

    }

    param_1[0x173] = iVar2;

    (**(code **)(*param_1 + 0xa8))(iVar2);

    (**(code **)(*(int *)param_1[0x173] + 0x28))("i_d_store_regret_2d_wnd_item_icon.xml");

    (**(code **)(*(int *)param_1[0x173] + 0x74))(0x9c48);

    FUN_007fef20(4,1,0);

    FUN_00889fb0(DAT_00d1b880,0);

    (**(code **)(**(int **)(DAT_00d1b880 + 0x50c) + 0x74))(0x9c46);

    FUN_007a69d0();

    puVar7 = (uint32_t /* width from decompiler */ *)&stack0xfffffdca;

    for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar7 = 0;

      puVar7 = puVar7 + 1;

    }

    *(uint16_t *)puVar7 = 0;

    uVar5 = *(uint32_t /* width from decompiler */ *)(param_1[0x162] + 0x4d8);

    if (*(char *)(param_1[0x162] + 0x4e4) == '\0') {

      FUN_007a6de0(uVar5,0xffffffff);

    }

    else {

      uVar5 = FUN_007a6de0(uVar5,0xffffffff);

      uVar6 = FUN_007a6de0("Junkyard",0xffffffff);

      sprintf(&stack0xfffffdc8,"%s: %s",uVar6,uVar5);

    }

    FUN_0088f000();

    FUN_0088f500();

    FUN_0088ef70();

    (**(code **)(*param_1 + 0x34c))();

  }

  ExceptionList = local_14;

  return;

}
