// READABILITY (auto CF):
//  - Body size: ~509 non-empty decompiler lines.
//  - Control keywords: if×71, for×3, while×1, return×1.
//  - Notable callees: FUN_008191a0×24, FUN_00817140×6, FUN_007b5dd0×4, FUN_0079c860×3, FUN_00816eb0×3, FUN_008176d0×3, FUN_00818d90×3, avatar×2.
//  - Strings: "i_o_ui_2d_wnd_title.xml"; "i_o_ui_2d_wnd_icon.xml"; "i_o_ui_2d_wnd_icon_cover.xml"; "i_o_ui_2d_btn_close.xml".
//  - Return sites: 1.

// =============================================================================
// Mission_If_this_option_is_checked_a_new_mission_will_be_
// -----------------------------------------------------------------------------
// Stable ID: aa_0081c4d0
// Address:   0x0081c4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "If this option is checked, a new mission will be set to the active mission"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Mission_If_this_option_is_checked_a_new_mission_will_be_(int *param_1)



{

  int iVar1;

  void *pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int *unaff_EBX;

  int unaff_EBP;

  int *unaff_ESI;

  int iStack_60;

  int *piStack_5c;

  int iStack_58;

  int *piStack_54;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb746;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar2 = operator_new(0x488);

  local_4 = 0;

  if (pvVar2 != (void *)0x0) {

    FUN_007b5dd0();

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*unaff_EBX + 0x28))();

  (**(code **)(*unaff_ESI + 0xfc))();

  param_1[0x39c] = unaff_EBP;

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x4bc);

  if (pvVar2 != (void *)0x0) {

    FUN_00864f20();

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(s_i_o_ui_2d_wnd_bg_fill_xml_00a79c8c._0_4_ + 0x28))();

  (**(code **)(iRam3f000000 + 0xfc))();

  param_1[0x39d] = 1;

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  piStack_54 = (int *)0x81c620;

  piStack_54 = operator_new(0x488);

  if (piStack_54 != (void *)0x0) {

    iStack_58 = 0x81c63b;

    FUN_007b5dd0();

  }

  piStack_54 = (int *)0x81c652;

  (**(code **)(*param_1 + 0xa8))();

  piStack_54 = (int *)0xa79c54;

  iStack_58 = 0x81c660;

  (**(code **)(s_i_o_ui_2d_wnd_fx_xml_00a79c74._0_4_ + 0x28))();

  iStack_58 = 0x3f000000;

  piStack_5c = (int *)0x1;

  iStack_60 = 0x81c673;

  (**(code **)(iRam3f000000 + 0xfc))();

  param_1[0x39e] = 1;

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  iStack_60 = 1;

  (**(code **)(*param_1 + 0x3f4))();

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    uVar4 = 0;

  }

  else {

    uVar4 = FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))(uVar4);

  (**(code **)(*piStack_54 + 0x28))("i_o_ui_2d_wnd_title.xml");

  param_1[0x39f] = iStack_58;

  piStack_54 = operator_new(0x488);

  if (piStack_54 == (void *)0x0) {

    iStack_58 = 0;

  }

  else {

    iStack_58 = FUN_007b5dd0(piStack_54,0);

  }

  (**(code **)(*param_1 + 0xa8))(iStack_58);

  (**(code **)(*piStack_5c + 0x28))("i_o_ui_2d_wnd_icon.xml");

  param_1[0x39f] = iStack_60;

  (**(code **)(*param_1 + 0x404))(&iStack_60,"i_o_ui_2d_wnd_icon_cover.xml",0xffffffff);

  pvVar2 = operator_new(0x4cc);

  piStack_5c = (int *)0x5;

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0079c860();

  }

  piStack_5c = (int *)0xffffffff;

  (**(code **)(*param_1 + 0xa8))(piVar5);

  (**(code **)(*piVar5 + 0x28))("i_o_ui_2d_btn_close.xml");

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

  (**(code **)(*piVar5 + 0x28))("i_o_ui_2d_btn_accept.xml");

  (**(code **)(*piVar5 + 0x74))(0x9c41);

  (**(code **)(*piVar5 + 0xfc))(1,0x3f000000);

  param_1[0x3a1] = (int)piVar5;

  pvVar2 = operator_new(0x4cc);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar5);

  (**(code **)(*piVar5 + 0x28))("i_o_ui_2d_btn_cancel.xml");

  (**(code **)(*piVar5 + 0x74))(0x9c42);

  (**(code **)(*piVar5 + 0xfc))(1,0x3f000000);

  param_1[0x3a2] = (int)piVar5;

  pvVar2 = operator_new(0x71c);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_00818d90(pvVar2);

  }

  (**(code **)(*piVar5 + 0x28))(param_1 + 0x153);

  FUN_008176d0(piVar5);

  param_1[0x3a3] = (int)piVar5;

  (**(code **)(*piVar5 + 0x74))(0x9c43);

  iVar3 = param_1[0x3a3];

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Reset Window Positions:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  FUN_00817140(param_1[0x3a3],"Reset",0);

  iVar3 = param_1[0x3a3];

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x70c) = 0;

  if (*(int **)(iVar3 + 0x708) != (int *)0x0) {

    iVar1 = **(int **)(iVar3 + 0x708);

    uVar4 = FUN_00816eb0(1,1);

    (**(code **)(iVar1 + 0x1d8))(uVar4);

    (**(code **)(**(int **)(iVar3 + 0x708) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a3] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a3] + 0x600) + 0x308))

              ("This option restores all windows to their original positions");

  }

  iVar3 = FUN_008191a0(DAT_00afa140);

  param_1[0x3a4] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("All Windows Can Be Dragged:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a4] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a4] + 0x600) + 0x308))

              (

              "If this option is checked, the interface is no longer stationary... you can drag windows at your discretion."

              );

  }

  iVar3 = FUN_008191a0(DAT_00af93f8);

  param_1[0x3a5] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Quickbar Drag Requires Shift:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a5] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a5] + 0x600) + 0x308))

              (

              "If this option is checked, you must hold the shift key to drag items from the quickbar"

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b225);

  param_1[0x3a6] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Enable Profanity Filter:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a6] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a6] + 0x600) + 0x308))

              ("If this option is checked, chat will be filtered for profanity");

  }

  iVar3 = FUN_008191a0(DAT_00d1b20b);

  param_1[0x3a9] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Invert Mouse:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3a9] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3a9] + 0x600) + 0x308))

              ("If this option is checked, moving the mouse upward will angle the camera downward");

  }

  iVar3 = FUN_008191a0(DAT_00d1b221);

  param_1[0x3aa] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Mouse-Move In Town:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3aa] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3aa] + 0x600) + 0x308))

              (

              "If this option is checked, you can use the mouse to navigate your avatar (character) in town"

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b222);

  param_1[0x3ab] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Mouse-Move In Vehicle:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3ab] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3ab] + 0x600) + 0x308))

              (

              "If this option is checked, you can use the mouse to navigate your avatar (vehicle) outside town"

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b20c);

  param_1[0x3ac] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Use Vibration:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3ac] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3ac] + 0x600) + 0x308))

              (

              "If this option is checked, joystick controllers that support rumble/vibration will be activiate"

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b205);

  param_1[0x3ad] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Self Targeting:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3ad] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3ad] + 0x600) + 0x308))

              (

              "If this option is checked, you can select yourself by clicking on your character/vehicle."

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b213);

  param_1[0x3ae] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Use Combat Cursor:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3ae] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3ae] + 0x600) + 0x308))

              (

              "If this option is checked, the mouse cursor will contain extra information about your character such as HP, Shields, and Heat."

              );

  }

  pvVar2 = operator_new(0x71c);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_00818d90(pvVar2);

  }

  (**(code **)(*piVar5 + 0x28))(param_1 + 0x153);

  FUN_008176d0(piVar5);

  param_1[0x3af] = (int)piVar5;

  if (piVar5[0x180] != 0) {

    (**(code **)(*(int *)piVar5[0x180] + 0x1d8))("Distance/Speed Units:",1,1);

    (**(code **)(*(int *)piVar5[0x180] + 0x34c))();

  }

  FUN_00817140(param_1[0x3af],"Standard - mph",0);

  FUN_00817140(param_1[0x3af],"Metric - km/h",1);

  iVar3 = param_1[0x3af];

  *(uint *)(iVar3 + 0x70c) = (uint)DAT_00d1b24f;

  if (*(int **)(iVar3 + 0x708) != (int *)0x0) {

    iVar1 = **(int **)(iVar3 + 0x708);

    uVar4 = FUN_00816eb0(1,1);

    (**(code **)(iVar1 + 0x1d8))(uVar4);

    (**(code **)(**(int **)(iVar3 + 0x708) + 0x34c))();

  }

  if (*(int *)(param_1[0x3af] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3af] + 0x600) + 0x308))

              (

              "This option toggles the display of the vehicle speed and distance to waypoints between Standard and Metric"

              );

  }

  pvVar2 = operator_new(0x71c);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_00818d90(pvVar2);

  }

  (**(code **)(*piVar5 + 0x28))(param_1 + 0x153);

  FUN_008176d0(piVar5);

  param_1[0x3b0] = (int)piVar5;

  if (piVar5[0x180] != 0) {

    (**(code **)(*(int *)piVar5[0x180] + 0x1d8))("Screen-shot Format:",1,1);

    (**(code **)(*(int *)piVar5[0x180] + 0x34c))();

  }

  FUN_00817140(param_1[0x3b0],&DAT_00a79668,0);

  FUN_00817140(param_1[0x3b0],&DAT_00a79664,1);

  FUN_00817140(param_1[0x3b0],&DAT_00a79660,2);

  iVar3 = param_1[0x3b0];

  *(uint *)(iVar3 + 0x70c) = (uint)DAT_00d1b250;

  if (*(int **)(iVar3 + 0x708) != (int *)0x0) {

    iVar1 = **(int **)(iVar3 + 0x708);

    uVar4 = FUN_00816eb0(1,1);

    (**(code **)(iVar1 + 0x1d8))(uVar4);

    (**(code **)(**(int **)(iVar3 + 0x708) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b0] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b0] + 0x600) + 0x308))

              ("This option toggles between the available screen-shot output formats.");

  }

  iVar3 = FUN_008191a0(DAT_00d1b212);

  param_1[0x3b1] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Camera Locks Behind Player In Town:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b1] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b1] + 0x600) + 0x308))

              (

              "If this option is checked, the camera will clamp itself behind you in town when you are not manually controlling it"

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b218);

  param_1[0x3b3] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Auto-Targeting:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b3] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b3] + 0x600) + 0x308))

              (

              "If this option is checked, firing upon enemies or killing the current target will automatically select a new target"

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b219);

  param_1[0x3b4] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Target Attackers:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b4] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b4] + 0x600) + 0x308))

              (

              "If this option is checked, whenever an enemy attacks you while you have no target, that enemy will automatically become your target"

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b20f);

  param_1[0x3b5] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Enable Joystick:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b5] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b5] + 0x600) + 0x308))

              (

              "If this option is checked, game controllers plugged into the computer will function in the game"

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b26c);

  param_1[0x3b6] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Extended Camera Zoom:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b6] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b6] + 0x600) + 0x308))

              ("If this option is checked, the camera will be able to be zoomed further out");

  }

  iVar3 = FUN_008191a0(DAT_00d1b26d);

  param_1[0x3b7] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Slower Camera Movement:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b7] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b7] + 0x600) + 0x308))

              (

              "If this option is checked, the camera will move more slowly and therefore slightly smoother"

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b211);

  param_1[0x3b8] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Camera Stays Behind Vehicle:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b8] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b8] + 0x600) + 0x308))

              (

              "If this option is checked, the camera will always attempt to stay directly behind the vehicle"

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b26e);

  param_1[0x3b9] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Camera Easier Look Up:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b9] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b9] + 0x600) + 0x308))

              ("If this option is checked, the camera will look up when rotating into terrain");

  }

  iVar3 = FUN_008191a0(DAT_00d1b21a);

  param_1[0x3ba] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Mouse Drags Tooltips:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3ba] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3ba] + 0x600) + 0x308))

              (

              "If this option is checked, tooltips will follow the mouse rather than staying put when they first appear"

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b216);

  param_1[0x3bb] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Auto-set New Mission Active:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3bb] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3bb] + 0x600) + 0x308))

              ("If this option is checked, a new mission will be set to the active mission");

  }

  iVar3 = FUN_008191a0(DAT_00d1b217);

  param_1[0x3bc] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Hide Waypoint for Kill:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3bc] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3bc] + 0x600) + 0x308))

              (

              "If this option is checked, you won\'t get a specific waypoint for kill missions (among other types)"

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b21b);

  param_1[0x3bd] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Swap Rotate And Strafe:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3bd] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3bd] + 0x600) + 0x308))

              (

              "If this option is checked, the default movement keys of WASD will strafe, and QE will turn when controlling a character, drone, or hazard mode creature."

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b21c);

  param_1[0x3be] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Dialogue Fades In:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3be] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3be] + 0x600) + 0x308))

              (

              "If this option is checked, text from talking to npcs will gradually fade in.  Otherwise, it will all appear instantly."

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b223);

  param_1[0x3bf] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Show Full QuickBar Useability",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3bf] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3bf] + 0x600) + 0x308))

              (

              "If checked, skills that aren\'t useable in the QuickBar will be fully red.  Otherwise, only their slot numbers will be red."

              );

  }

  iVar3 = FUN_008191a0(DAT_00d1b224);

  param_1[0x3c0] = iVar3;

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Show Stunts",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3c0] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3c0] + 0x600) + 0x308))

              (

              "If checked, doing stunts will show a display in the screen\'s corner when they are more impressive than ones you\'ve done recently."

              );

  }

  FUN_00817eb0();

  FUN_00816ee0();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar2;

  return;

}
