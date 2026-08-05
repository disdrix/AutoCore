// =============================================================================
// UI_video_icon_cover
// -----------------------------------------------------------------------------
// Stable ID: aa_0081ac20
// Address:   0x0081ac20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_video_icon_cover @ 0x0081ac20
// Stable ID: aa_0081ac20
// Embedded strings (evidence for future rename):
//   - "i_o_video_2d_wnd_title.xml"
//   - "i_o_video_2d_wnd_icon.xml"
//   - "i_o_video_2d_wnd_icon_cover.xml"
//   - "i_o_video_2d_btn_close.xml"
//   - "i_o_video_2d_btn_accept.xml"
//   - "i_o_video_2d_btn_cancel.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~429 non-empty decompiler lines.
//  - Control keywords: if×58, for×1, return×1.
//  - Notable callees: FUN_00816be0×16, FUN_008191a0×10, FUN_00817840×7, FUN_00819060×7, FUN_007b5dd0×4, FUN_0079c860×3, FUN_008176d0×3, FUN_00818a50×3.
//  - Strings: "i_o_video_2d_wnd_title.xml"; "i_o_video_2d_wnd_icon.xml"; "i_o_video_2d_wnd_icon_cover.xml"; "i_o_video_2d_btn_close.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_o_video_2d_wnd_icon_cover.xml"
 * Domain alias of FUN_0081ac20 (FUN_* retained)
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



void __fastcall UI_video_icon_cover(int *param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int *unaff_EBP;

  int *unaff_ESI;

  int *piVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb6c3;

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

  (**(code **)(*unaff_EBP + 0x28))();

  (**(code **)(*unaff_ESI + 0xfc))();

  param_1[0x39c] = iVar2;

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

  param_1[0x39d] = iVar2;

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

  param_1[0x39e] = iVar2;

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

    iVar2 = FUN_007b5dd0(pvVar1);

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(iRam3f000000 + 0x28))("i_o_video_2d_wnd_title.xml");

  param_1[0x39f] = 1;

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_007b5dd0(pvVar1,0);

  }

  (**(code **)(*param_1 + 0xa8))(uVar3);

  (**(code **)(iRam00000001 + 0x28))("i_o_video_2d_wnd_icon.xml");

  param_1[0x39f] = iVar2;

  (**(code **)(*param_1 + 0x404))(&stack0xffffffa0,"i_o_video_2d_wnd_icon_cover.xml",0xffffffff);

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar4);

  (**(code **)(*piVar4 + 0x28))("i_o_video_2d_btn_close.xml");

  (**(code **)(*piVar4 + 0x74))(40000);

  (**(code **)(*piVar4 + 0xfc))(1,0x3f000000);

  param_1[0x141] = (int)piVar4;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar4);

  (**(code **)(*piVar4 + 0x28))("i_o_video_2d_btn_accept.xml");

  (**(code **)(*piVar4 + 0x74))(0x9c41);

  (**(code **)(*piVar4 + 0xfc))(1,0x3f000000);

  param_1[0x3a1] = (int)piVar4;

  pvVar1 = operator_new(0x4cc);

  if (pvVar1 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar4);

  (**(code **)(*piVar4 + 0x28))("i_o_video_2d_btn_cancel.xml");

  (**(code **)(*piVar4 + 0x74))(0x9c42);

  (**(code **)(*piVar4 + 0xfc))(1,0x3f000000);

  param_1[0x3a2] = (int)piVar4;

  pvVar1 = operator_new(0x70c);

  if (pvVar1 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_00818a50(pvVar1);

  }

  (**(code **)(*piVar4 + 0x28))(param_1 + 599);

  FUN_008176d0(piVar4);

  param_1[0x3a3] = (int)piVar4;

  if (piVar4[0x180] != 0) {

    (**(code **)(*(int *)piVar4[0x180] + 0x1d8))("Resolution:",1,1);

    (**(code **)(*(int *)piVar4[0x180] + 0x34c))();

  }

  if (*(int *)(param_1[0x3a3] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a3] + 0x600) + 0x308))

              ("Use this box to select your resolution");

  }

  FUN_00819c30(param_1);

  iVar2 = FUN_008191a0(DAT_00d1b201 == '\0');

  param_1[0x3a4] = iVar2;

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Full-screen:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a4] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a4] + 0x600) + 0x308))

              (

              "If this option is checked, the game will run in full-screen (otherwise, it will be windowed)"

              );

  }

  iVar2 = FUN_008191a0(DAT_00d1b202);

  param_1[0x3a5] = iVar2;

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Windowed Mode Border:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a5] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a5] + 0x600) + 0x308))

              (

              "If this option is checked and the game is in windowed mode, it will have a standard windows border"

              );

  }

  iVar2 = FUN_008191a0(DAT_00d1b264);

  param_1[0x3a6] = iVar2;

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Allow UI Scale:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a6] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a6] + 0x600) + 0x308))

              (

              "If this option is checked, the UI will scale according to the slider below.  Otherwise, it will stay relative to the screen resolution."

              );

  }

  iVar2 = FUN_00819060(0xffffffff);

  param_1[0x3a7] = iVar2;

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("UI Scale:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a7] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a7] + 0x600) + 0x308))

              (

              "Changes the UI scale.  Note that the UI cannot be made any smaller than what it appears at 800x600."

              );

  }

  FUN_00817840(2);

  FUN_00816be0(&DAT_00a78848);

  FUN_00816be0(&DAT_00a78844);

  if (*(int *)(param_1[0x3a7] + 0x708) != 0) {

    (**(code **)(**(int **)(param_1[0x3a7] + 0x708) + 0x454))(DAT_00d1b260,1);

  }

  pvVar1 = operator_new(0x70c);

  if (pvVar1 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_00818a50(pvVar1);

  }

  (**(code **)(*piVar4 + 0x28))(param_1 + 599);

  FUN_008176d0(piVar4);

  param_1[0x3a8] = (int)piVar4;

  if (piVar4[0x180] != 0) {

    (**(code **)(*(int *)piVar4[0x180] + 0x1d8))("Shadow Mode :",1,1);

    (**(code **)(*(int *)piVar4[0x180] + 0x34c))();

  }

  if (*(int *)(param_1[0x3a8] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a8] + 0x600) + 0x308))

              ("Use this box to select your shadow mode");

  }

  FUN_00819b20();

  iVar2 = FUN_008191a0(DAT_00aefa54);

  param_1[0x3a9] = iVar2;

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Better Shadow Culling:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a9] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a9] + 0x600) + 0x308))

              (

              "If this option is checked, the game will render shadows for objects out of view to prevent popping"

              );

  }

  pvVar1 = operator_new(0x70c);

  if (pvVar1 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_00818a50(pvVar1);

  }

  piVar5 = param_1 + 599;

  (**(code **)(*piVar4 + 0x28))();

  FUN_008176d0(piVar4);

  param_1[0x3b9] = (int)piVar4;

  if (piVar4[0x180] != 0) {

    (**(code **)(*(int *)piVar4[0x180] + 0x1d8))("Texture Resolution:",1,1);

    (**(code **)(*(int *)piVar4[0x180] + 0x34c))();

  }

  if (*(int *)(param_1[0x3b9] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b9] + 0x600) + 0x308))

              ("Use this box to select your texture resolution");

  }

  FUN_00819dc0(param_1);

  iVar2 = FUN_008191a0(DAT_00d1b20e);

  param_1[0x3b2] = iVar2;

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Use Environmental Shaders:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b2] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b2] + 0x600) + 0x308))

              ("If this option is checked, the game will render environmental effects such as glow")

    ;

  }

  iVar2 = FUN_008191a0(DAT_00d1b210);

  param_1[0x3b3] = iVar2;

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Use Advanced Shaders:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b3] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b3] + 0x600) + 0x308))

              ("If this option is checked, the game will render advanced shaders");

  }

  iVar2 = FUN_008191a0(DAT_00d1b206);

  param_1[0x3b5] = iVar2;

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Antialiased:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b5] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b5] + 0x600) + 0x308))

              ("If this option is checked, the game will be antialiased");

  }

  iVar2 = FUN_008191a0(DAT_00d1b21e);

  param_1[0x3b4] = iVar2;

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Draw Ground Cover:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b4] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b4] + 0x600) + 0x308))

              ("If this option is checked, the game will draw ground cover");

  }

  piVar4 = (int *)FUN_00819060(0xffffffff);

  param_1[0x3ba] = (int)piVar4;

  (**(code **)(*piVar4 + 0x74))(0x9c43);

  iVar2 = param_1[0x3ba];

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Fullscreen Gamma:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  FUN_00817840(3);

  FUN_00816be0(&DAT_00a76d20);

  FUN_00816be0(&DAT_00a76d1c);

  FUN_00816be0(&DAT_00a76d14);

  if (*(int *)(param_1[0x3ba] + 0x708) != 0) {

    (**(code **)(**(int **)(param_1[0x3ba] + 0x708) + 0x454))

              ((DAT_00d1b268 - DAT_00a0f298) * _DAT_00aaacb4,0);

  }

  param_1[0x3cd] = DAT_00b036ac;

  piVar4 = (int *)FUN_00819060(0xffffffff);

  param_1[0x3bb] = (int)piVar4;

  (**(code **)(*piVar4 + 0x74))(0x9c44);

  iVar2 = param_1[0x3bb];

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Terrain View Distance:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  FUN_00817840(2);

  FUN_00816be0(&DAT_00a7a290);

  FUN_00816be0(&DAT_00a7a28c);

  if (*(int *)(param_1[0x3bb] + 0x708) != 0) {

    (**(code **)(**(int **)(param_1[0x3bb] + 0x708) + 0x454))(param_1[0x3cd],0);

  }

  param_1[0x3cf] = DAT_00af06e0;

  piVar4 = (int *)FUN_00819060(0xffffffff);

  param_1[0x3bd] = (int)piVar4;

  (**(code **)(*piVar4 + 0x74))(0x9c4c);

  iVar2 = param_1[0x3bd];

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Number of Particles:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  FUN_00817840(3);

  FUN_00816be0(&DAT_00a2d820);

  FUN_00816be0(&DAT_00a76d1c);

  FUN_00816be0(&DAT_00a76d14);

  if (*(int *)(param_1[0x3bd] + 0x708) != 0) {

    (**(code **)(**(int **)(param_1[0x3bd] + 0x708) + 0x454))(param_1[0x3cf],0);

  }

  iVar2 = FUN_008191a0(DAT_00d1b220);

  param_1[0x3b8] = iVar2;

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Flush Memory:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b8] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b8] + 0x600) + 0x308))

              (

              "If this option is checked, the game will release more memory between map loads, but will cause more hitching on map start"

              );

  }

  piVar4 = (int *)FUN_00819060(0xffffffff);

  param_1[0x3ab] = (int)piVar4;

  (**(code **)(*piVar4 + 0x74))(0x9c49);

  iVar2 = param_1[0x3ab];

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Shadow Distance:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3ab] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3ab] + 0x600) + 0x308))

              ("Affects how far away shadows are drawn");

  }

  FUN_00817840(2);

  FUN_00816be0("Close ");

  FUN_00816be0(&DAT_00a7a28c);

  if (*(int *)(param_1[0x3ab] + 0x708) != 0) {

    (**(code **)(**(int **)(param_1[0x3ab] + 0x708) + 0x454))

              ((DAT_00afa2e0 - (float)param_1[0x3ac]) /

               ((float)param_1[0x3ad] - (float)param_1[0x3ac]),1);

  }

  piVar4 = (int *)FUN_00819060(0xffffffff);

  param_1[0x3ae] = (int)piVar4;

  (**(code **)(*piVar4 + 0x74))(0x9c4a);

  iVar2 = param_1[0x3ae];

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("LOD Bias:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3ae] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3ae] + 0x600) + 0x308))

              ("Affects when lower detail models are drawn");

  }

  FUN_00817840(2);

  FUN_00816be0("Close ");

  FUN_00816be0(&DAT_00a7a28c);

  if (*(int *)(param_1[0x3ae] + 0x708) != 0) {

    (**(code **)(**(int **)(param_1[0x3ae] + 0x708) + 0x454))

              ((DAT_00d1a540 - (float)param_1[0x3af]) /

               ((float)param_1[0x3b0] - (float)param_1[0x3af]),1);

  }

  piVar4 = (int *)FUN_00819060(0xffffffff);

  param_1[0x3b1] = (int)piVar4;

  (**(code **)(*piVar4 + 0x74))(0x9c4b);

  iVar2 = param_1[0x3b1];

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("LOD Slope:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b1] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b1] + 0x600) + 0x308))

              ("Affects when lower detail models are drawn");

  }

  FUN_00817840(2);

  FUN_00816be0("Close ");

  FUN_00816be0(&DAT_00a7a28c);

  if (*(int *)(param_1[0x3b1] + 0x708) != 0) {

    (**(code **)(**(int **)(param_1[0x3b1] + 0x708) + 0x454))(DAT_00afa2ec,1);

  }

  iVar2 = FUN_008191a0(DAT_00aef950);

  param_1[0x3aa] = iVar2;

  if (*(int *)(iVar2 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x1d8))("Use Fading:",1,1);

    (**(code **)(**(int **)(iVar2 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3aa] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3aa] + 0x600) + 0x308))

              ("Fade objects into view.(Can reduce framerates)");

  }

  FUN_00817eb0();

  FUN_00816ee0();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = piVar5;

  return;

}
