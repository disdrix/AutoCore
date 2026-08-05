// READABILITY (auto CF):
//  - Body size: ~221 non-empty decompiler lines.
//  - Control keywords: if×20, for×1, return×1.
//  - Notable callees: FUN_00820910×8, FUN_007b5dd0×4, FUN_008191a0×4, FUN_0079c860×3, FUN_00792600, FUN_00816ee0, FUN_00817eb0, FUN_008209c0.
//  - Strings: "i_o_audio_2d_wnd_title.xml"; "i_o_audio_2d_wnd_icon.xml"; "i_o_audio_2d_wnd_icon_cover.xml"; "i_o_audio_2d_btn_close.xml".
//  - Return sites: 1.

// =============================================================================
// Drive_Player_Vehicle_Sound_Volume_00820ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_00820ba0
// Address:   0x00820ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Player Vehicle Sound Volume:"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Drive_Player_Vehicle_Sound_Volume_00820ba0(int *param_1)



{

  uint8_t uVar1;

  void *pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int *unaff_EBX;

  int *unaff_ESI;

  bool bVar6;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb8a3;

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

    iVar3 = FUN_007b5dd0(pvVar2);

  }

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(iRam3f000000 + 0x28))("i_o_audio_2d_wnd_title.xml");

  param_1[0x39f] = 1;

  pvVar2 = operator_new(0x488);

  if (pvVar2 == (void *)0x0) {

    uVar4 = 0;

  }

  else {

    uVar4 = FUN_007b5dd0(pvVar2,0);

  }

  (**(code **)(*param_1 + 0xa8))(uVar4);

  (**(code **)(iRam00000001 + 0x28))("i_o_audio_2d_wnd_icon.xml");

  param_1[0x39f] = iVar3;

  (**(code **)(*param_1 + 0x404))(&stack0xffffffa0,"i_o_audio_2d_wnd_icon_cover.xml",0xffffffff);

  pvVar2 = operator_new(0x4cc);

  if (pvVar2 == (void *)0x0) {

    piVar5 = (int *)0x0;

  }

  else {

    piVar5 = (int *)FUN_0079c860();

  }

  (**(code **)(*param_1 + 0xa8))(piVar5);

  (**(code **)(*piVar5 + 0x28))("i_o_audio_2d_btn_close.xml");

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

  (**(code **)(*piVar5 + 0x28))("i_o_audio_2d_btn_accept.xml");

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

  (**(code **)(*piVar5 + 0x28))("i_o_audio_2d_btn_cancel.xml");

  (**(code **)(*piVar5 + 0x74))();

  (**(code **)(*piVar5 + 0xfc))(1,0x3f000000);

  param_1[0x3a2] = (int)piVar5;

  uVar1 = DAT_00d1b227;

  *(uint8_t *)(param_1 + 0x3a3) = DAT_00d1b227;

  piVar5 = (int *)FUN_008191a0(uVar1);

  param_1[0x3ad] = (int)piVar5;

  (**(code **)(*piVar5 + 0x74))(0x9c49);

  iVar3 = param_1[0x3ad];

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Use Music:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3ad] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3ad] + 0x600) + 0x308))

              ("If this option is checked, music will be enabled");

  }

  param_1[0x3a4] = DAT_00d1b22c;

  param_1[0x3a5] = DAT_00d1b230;

  iVar3 = FUN_00820910(0x9c43,"Music Volume:",param_1[0x3a4]);

  param_1[0x3af] = iVar3;

  param_1[0x3a5] = DAT_00d1b230;

  iVar3 = FUN_00820910(0x9c44,"Environmental Volume:",param_1[0x3a5]);

  param_1[0x3b0] = iVar3;

  uVar1 = DAT_00d1b226;

  *(uint8_t *)((int)param_1 + 0xe8d) = DAT_00d1b226;

  piVar5 = (int *)FUN_008191a0(uVar1);

  param_1[0x3b1] = (int)piVar5;

  (**(code **)(*piVar5 + 0x74))(0x9c4a);

  iVar3 = param_1[0x3b1];

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Use Sound:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3b1] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3b1] + 0x600) + 0x308))

              ("If this option is checked, sound effects will be enabled");

  }

  if (DAT_00d1a851 == '\0') {

    bVar6 = DAT_00d1b229 == '\0';

    *(char *)((int)param_1 + 0xe8e) = DAT_00d1b229;

    piVar5 = (int *)FUN_008191a0(bVar6);

    param_1[0x3b2] = (int)piVar5;

    (**(code **)(*piVar5 + 0x74))(0x9c4b);

    iVar3 = param_1[0x3b2];

    if (*(int *)(iVar3 + 0x600) != 0) {

      (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Use High Quality Sound:",1,1);

      (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

    }

    if (*(int *)(param_1[0x3b2] + 0x600) != 0) {

      (**(code **)(**(int **)(param_1[0x3b2] + 0x600) + 0x308))

                (

                "If this option is checked, higher quality sound is used at the cost of performance."

                );

    }

  }

  FUN_008209c0(param_1);

  param_1[0x3ab] = DAT_00d1b248;

  iVar3 = FUN_00820910(0x9c4d,"General Sound Volume:",param_1[0x3ab]);

  param_1[0x3b8] = iVar3;

  param_1[0x3a6] = DAT_00d1b240;

  iVar3 = FUN_00820910(0x9c45,"2D Sound Volume:",param_1[0x3a6]);

  param_1[0x3b3] = iVar3;

  param_1[0x3a7] = DAT_00d1b234;

  iVar3 = FUN_00820910(0x9c47,"Local Sound Volume:",param_1[0x3a7]);

  param_1[0x3b4] = iVar3;

  param_1[0x3a8] = DAT_00d1b238;

  iVar3 = FUN_00820910(0x9c46,"3D Sound Volume:",param_1[0x3a8]);

  param_1[0x3b5] = iVar3;

  param_1[0x3a9] = DAT_00d1b23c;

  iVar3 = FUN_00820910(0x9c48,"Collision Sound Volume:",param_1[0x3a9]);

  param_1[0x3b6] = iVar3;

  param_1[0x3aa] = DAT_00d1b244;

  iVar3 = FUN_00820910(0x9c4c,"Player Vehicle Sound Volume:",param_1[0x3aa]);

  param_1[0x3b7] = iVar3;

  piVar5 = (int *)FUN_008191a0(DAT_00d1b24c);

  param_1[0x3ae] = (int)piVar5;

  (**(code **)(*piVar5 + 0x74))(0x9c4b);

  iVar3 = param_1[0x3ae];

  if (*(int *)(iVar3 + 0x600) != 0) {

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x1d8))("Don\'t play summon sounds:",1,1);

    (**(code **)(**(int **)(iVar3 + 0x600) + 0x34c))();

  }

  if (*(int *)(param_1[0x3ae] + 0x600) != 0) {

    (**(code **)(**(int **)(param_1[0x3ae] + 0x600) + 0x308))

              ("If this option is checked, status sounds won\'t play for summons.");

  }

  FUN_00817eb0();

  FUN_00816ee0();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0x9c42;

  return;

}
