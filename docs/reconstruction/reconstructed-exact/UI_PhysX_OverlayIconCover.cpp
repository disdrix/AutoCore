// =============================================================================
// UI_PhysX_OverlayIconCover
// -----------------------------------------------------------------------------
// Stable ID: aa_0081d940
// Address:   0x0081d940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_PhysX_OverlayIconCover @ 0x0081d940
// Stable ID: aa_0081d940
// Embedded strings (evidence for future rename):
//   - "i_o_physx_2d_wnd_title.xml"
//   - "i_o_physx_2d_wnd_icon.xml"
//   - "i_o_physx_2d_wnd_icon_cover.xml"
//   - "i_o_physx_2d_btn_close.xml"
//   - "i_o_physx_2d_btn_accept.xml"
//   - "i_o_physx_2d_btn_cancel.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~223 non-empty decompiler lines.
//  - Control keywords: if×25, return×1.
//  - Notable callees: FUN_007b5dd0×5, FUN_00816be0×4, FUN_008191a0×4, FUN_0079c860×3, FUN_00817840×2, FUN_00819060×2, FUN_00792600, FUN_00816ee0.
//  - Strings: "i_o_physx_2d_wnd_title.xml"; "i_o_physx_2d_wnd_icon.xml"; "i_o_physx_2d_wnd_icon_cover.xml"; "i_o_physx_2d_btn_close.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_o_physx_2d_wnd_icon_cover.xml"
 * Domain alias of FUN_0081d940 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall UI_PhysX_OverlayIconCover(int *param_1)



{

  uint8_t uVar1;

  void *pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int *unaff_EBP;

  int *unaff_ESI;

  void *pvVar6;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb7b3;

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

  (**(code **)(*unaff_EBP + 0x28))();

  (**(code **)(*unaff_ESI + 0xfc))();

  param_1[0x39c] = iVar3;

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x4bc);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_00864f20();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(iRam3f000000 + 0x28))();

  (**(code **)(iRam00000001 + 0xfc))();

  param_1[0x39d] = iVar3;

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

  (**(code **)(iRam00000001 + 0xfc))();

  param_1[0x39e] = iVar3;

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

  (**(code **)(iRam00000001 + 0xfc))();

  param_1[0x3a1] = iVar3;

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

    iVar3 = FUN_007b5dd0(pvVar2);

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(iRam3f000000 + 0x28))("i_o_physx_2d_wnd_title.xml");

  param_1[0x39f] = 1;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    uVar4 = 0;

  }

  else {

    uVar4 = FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))(uVar4);

  (**(code **)(iRam00000001 + 0x28))("i_o_physx_2d_wnd_icon.xml");

  param_1[0x39f] = iVar3;

  (**(code **)(*param_1 + 0x404))(&stack0xffffff8c,"i_o_physx_2d_wnd_icon_cover.xml",0xffffffff);

  pvVar2 = operator_new(0x4cc);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar5);

  (**(code **)(*piVar5 + 0x28))("i_o_physx_2d_btn_close.xml");

  (**(code **)(*piVar5 + 0x74))(40000);

  (**(code **)(*piVar5 + 0xfc))(1,0x3f000000);

  param_1[0x141] = (int)piVar5;

  pvVar2 = operator_new(0x4cc);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar5);

  (**(code **)(*piVar5 + 0x28))("i_o_physx_2d_btn_accept.xml");

  (**(code **)(*piVar5 + 0x74))(0x9c41);

  pvVar6 = (void *)0x1;

  (**(code **)(*piVar5 + 0xfc))(1,0x3f000000);

  param_1[0x3a2] = (int)piVar5;

  pvVar2 = operator_new(0x4cc);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar5);

  (**(code **)(*piVar5 + 0x28))("i_o_physx_2d_btn_cancel.xml");

  (**(code **)(*piVar5 + 0x74))(0x9c42);

  (**(code **)(*piVar5 + 0xfc))(1,0x3f000000);

  uVar1 = DAT_00b036d9;

  param_1[0x3a3] = (int)piVar5;

  iVar3 = FUN_008191a0(uVar1);

  param_1[0x3a6] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Use PhysX:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a6] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a6] + 0x600) + 0x308))

              ("Enabled advanced PhysX features. (Requires Ageia hardware)");

  }

  iVar3 = FUN_00819060(0xffffffff);

  param_1[0x3a4] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Fluid Particles:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  FUN_00817840(2);

  FUN_00816be0(&DAT_00a78848);

  FUN_00816be0(&DAT_00a78844);

  if (*(int *)(param_1[0x3a4] + 0x708) != 0) {

    (**(code **)(**(int **)(param_1[0x3a4] + 0x708) + 0x454))(DAT_00aefa88 - DAT_00a0f298,1);

  }

  iVar3 = FUN_00819060(0xffffffff);

  param_1[0x3a5] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Debris Particles:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  FUN_00817840(2);

  FUN_00816be0(&DAT_00a78848);

  FUN_00816be0(&DAT_00a78844);

  if (*(int *)(param_1[0x3a5] + 0x708) != 0) {

    (**(code **)(**(int **)(param_1[0x3a5] + 0x708) + 0x454))

              ((DAT_00aefb3c - DAT_00a0f704) * _DAT_00aaacb8,1);

  }

  iVar3 = FUN_008191a0(DAT_00af06e8);

  param_1[0x3a7] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Use PhysX Fluid:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a7] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a7] + 0x600) + 0x308))

              ("Enabled advanced PhysX fluid simulation. (Requires Ageia hardware)");

  }

  iVar3 = FUN_008191a0(DAT_00af06e9);

  param_1[0x3a8] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Use PhysX Destruction:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a8] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a8] + 0x600) + 0x308))

              ("Enabled advanced PhysX destruction. (Requires Ageia hardware)");

  }

  iVar3 = FUN_008191a0(DAT_00af06ea);

  param_1[0x3a9] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Use PhysX Fences:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a9] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a9] + 0x600) + 0x308))

              ("Enabled advanced PhysX fence simulation. (Requires Ageia hardware)");

  }

  FUN_00817eb0();

  FUN_00816ee0();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar6;

  return;

}
