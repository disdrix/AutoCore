// READABILITY (auto CF):
//  - Body size: ~376 non-empty decompiler lines.
//  - Control keywords: if×25, for×1, return×1.
//  - Notable callees: FUN_007b5dd0×10, FUN_0079c860×6, FUN_00795f20×2, sprintf×2, FUN_00792600, FUN_008c9830, GetKeyboardState, SendInput.
//  - Strings: "v.%i.%i.%i.%i"; "%i.%i.%i.%i"; "i_d_fet_2d_edt_password.xml"; "i_d_fet_2d_wnd_frame_btn_login.xml".
//  - Return sites: 1.

// =============================================================================
// Auth_i_d_fet_2d_wnd_frame_btn_login_xml
// -----------------------------------------------------------------------------
// Stable ID: aa_008c9830
// Address:   0x008c9830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_fet_2d_wnd_frame_btn_login.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Auth_i_d_fet_2d_wnd_frame_btn_login_xml(int *param_1)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  BYTE *pBVar4;

  uint32_t /* width from decompiler */ uStack_2ac;

  uint8_t *puStack_2a8;

  uint32_t /* width from decompiler */ uStack_2a4;

  char *pcStack_2a0;

  char acStack_1c8 [4];

  int *piStack_1c4;

  tagINPUT local_190;

  uint32_t /* width from decompiler */ local_174;

  uint32_t /* width from decompiler */ local_170;

  uint32_t /* width from decompiler */ local_16c;

  uint32_t /* width from decompiler */ local_168;

  uint32_t /* width from decompiler */ local_164;

  uint32_t /* width from decompiler */ local_160;

  uint32_t /* width from decompiler */ local_15c;

  uint32_t /* width from decompiler */ uStack_158;

  uint32_t /* width from decompiler */ uStack_144;

  uint32_t /* width from decompiler */ uStack_130;

  BYTE local_118 [20];

  byte local_104;

  uint32_t /* width from decompiler */ uStack_fc;

  uint32_t /* width from decompiler */ uStack_dc;

  uint32_t /* width from decompiler */ uStack_cc;

  uint32_t /* width from decompiler */ uStack_bc;

  uint32_t /* width from decompiler */ uStack_ac;

  uint32_t /* width from decompiler */ uStack_9c;

  uint32_t /* width from decompiler */ uStack_8c;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ local_1c;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009b6cf4;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  FUN_00792600();

  pBVar4 = local_118;

  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {

    pBVar4[0] = '\0';

    pBVar4[1] = '\0';

    pBVar4[2] = '\0';

    pBVar4[3] = '\0';

    pBVar4 = pBVar4 + 4;

  }

  local_1c = 0;

  GetKeyboardState(local_118);

  if ((local_104 & 1) != 0) {

    local_190.field1_0x4.mi.dy = 0;

    local_190.field1_0x4.mi.mouseData = 0;

    local_190.field1_0x4.mi.dwFlags = 0;

    local_190.field1_0x4.mi.time = 0;

    local_190.field1_0x4.mi.dwExtraInfo = 0;

    local_168 = 0;

    local_164 = 0;

    local_160 = 0;

    local_15c = 0;

    local_190.type = 1;

    local_190.field1_0x4.mi.dx = 0x14;

    local_174 = 1;

    local_170 = 0x14;

    local_16c = 2;

    SendInput(2,&local_190,0x1c);

  }

  DAT_00d1a980 = 0;

  pvVar1 = operator_new(0x488);

  local_c = 0;

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  local_c = 0xffffffff;

  param_1[0x155] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x155] + 0x28))();

  (**(code **)(*(int *)param_1[0x155] + 0xfc))();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  piStack_1c4 = (int *)0x8c999d;

  piStack_1c4 = operator_new(0x488);

  uStack_20 = 1;

  if (piStack_1c4 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    acStack_1c8[0] = -0x46;

    acStack_1c8[1] = -0x67;

    acStack_1c8[2] = -0x74;

    acStack_1c8[3] = '\0';

    iVar3 = FUN_007b5dd0();

  }

  uStack_20 = 0xffffffff;

  param_1[0x156] = iVar3;

  piStack_1c4 = (int *)0x8c99d7;

  (**(code **)(*param_1 + 0xa8))();

  piStack_1c4 = (int *)0xa429ec;

  builtin_strncpy(acStack_1c8,"癌",4);

  (**(code **)(*(int *)param_1[0x156] + 0x28))();

  acStack_1c8[0] = '\0';

  acStack_1c8[1] = '\0';

  acStack_1c8[2] = '\0';

  acStack_1c8[3] = '?';

  (**(code **)(*(int *)param_1[0x156] + 0xfc))();

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))();

  piVar2 = operator_new(0x488);

  uStack_34 = 2;

  if (piVar2 != (int *)0x0) {

    FUN_007b5dd0();

  }

  uStack_34 = 0xffffffff;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*piVar2 + 0x28))();

  (**(code **)(*piStack_1c4 + 0xfc))();

  (**(code **)(*param_1 + 0x404))();

  (**(code **)(*param_1 + 0x404))();

  pvVar1 = operator_new(0x488);

  uStack_5c = 3;

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  uStack_5c = 0xffffffff;

  param_1[0x157] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x157] + 0x28))();

  (**(code **)(*(int *)param_1[0x157] + 0xfc))();

  pvVar1 = operator_new(0x488);

  uStack_6c = 4;

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  uStack_6c = 0xffffffff;

  param_1[0x158] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x158] + 0x28))();

  (**(code **)(*(int *)param_1[0x158] + 0xfc))();

  sprintf(acStack_1c8,"v.%i.%i.%i.%i");

  (**(code **)(*(int *)param_1[0x158] + 0x1d8))();

  sprintf(&stack0xfffffe2c,"%i.%i.%i.%i");

  (**(code **)(*(int *)param_1[0x158] + 0x308))();

  pvVar1 = operator_new(0x488);

  uStack_8c = 5;

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  uStack_8c = 0xffffffff;

  param_1[0x15f] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15f] + 0x28))();

  (**(code **)(*(int *)param_1[0x15f] + 0xfc))();

  pvVar1 = operator_new(0x488);

  uStack_9c = 6;

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  uStack_9c = 0xffffffff;

  param_1[0x160] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x160] + 0x28))();

  (**(code **)(*(int *)param_1[0x160] + 0xfc))();

  pvVar1 = operator_new(0x488);

  uStack_ac = 7;

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  uStack_ac = 0xffffffff;

  param_1[0x161] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x161] + 0x28))();

  (**(code **)(*(int *)param_1[0x161] + 0xfc))();

  pvVar1 = operator_new(0x488);

  uStack_bc = 8;

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  uStack_bc = 0xffffffff;

  param_1[0x162] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x162] + 0x28))();

  (**(code **)(*(int *)param_1[0x162] + 0xfc))();

  pvVar1 = operator_new(0x488);

  uStack_cc = 9;

  if (pvVar1 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_007b5dd0();

  }

  uStack_cc = 0xffffffff;

  param_1[0x163] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x163] + 0x28))();

  (**(code **)(*(int *)param_1[0x163] + 0xfc))();

  pvVar1 = operator_new(0x4a4);

  uStack_dc = 10;

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_00795f20();

  }

  uStack_dc = 0xffffffff;

  param_1[0x164] = iVar3;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x164] + 0x28))();

  (**(code **)(*(int *)param_1[0x164] + 0x74))();

  (**(code **)(*(int *)param_1[0x164] + 0x3ac))();

  (**(code **)(*(int *)param_1[0x164] + 0x1d0))();

  (**(code **)(*(int *)param_1[0x164] + 0x98))();

  (**(code **)(*(int *)param_1[0x164] + 0xfc))();

  *(uint8_t *)(param_1[0x164] + 0x48d) = 1;

  pcStack_2a0 = (char *)0x8c9ee5;

  pvVar1 = operator_new(0x4a4);

  uStack_fc = 0xb;

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_00795f20();

  }

  uStack_fc = 0xffffffff;

  param_1[0x165] = iVar3;

  pcStack_2a0 = (char *)0x8c9f1d;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_2a0 = "i_d_fet_2d_edt_password.xml";

  uStack_2a4 = 0x8c9f2d;

  (**(code **)(*(int *)param_1[0x165] + 0x28))();

  uStack_2a4 = 0x9c49;

  puStack_2a8 = (uint8_t *)0x8c9f3d;

  (**(code **)(*(int *)param_1[0x165] + 0x74))();

  if (param_1 == (int *)0xfffffad3) {

    puStack_2a8 = &DAT_00a1419b;

  }

  else {

    puStack_2a8 = (uint8_t *)(DAT_00d1b64c + 0x2d);

  }

  uStack_2ac = 0x8c9f65;

  (**(code **)(*(int *)param_1[0x165] + 0x3ac))();

  uStack_2ac = 0x20;

  (**(code **)(*(int *)param_1[0x165] + 0x1d0))();

  (**(code **)(*(int *)param_1[0x165] + 0x98))(1);

  (**(code **)(*(int *)param_1[0x165] + 0xdc))(1);

  (**(code **)(*(int *)param_1[0x165] + 0xfc))(1,0x3f000000);

  iVar3 = param_1[0x1a] + 1;

  param_1[0x1a] = iVar3;

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  (**(code **)(*param_1 + 0x404))(&uStack_2ac,"i_d_fet_2d_wnd_frame_btn_login.xml",0xffffffff);

  pvVar1 = operator_new(0x4cc);

  uStack_130 = 0xc;

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  uStack_130 = 0xffffffff;

  param_1[0x159] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x159] + 0x28))("i_d_fet_2d_btn_login.xml");

  (**(code **)(*(int *)param_1[0x159] + 0x74))(40000);

  (**(code **)(*(int *)param_1[0x159] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x4cc);

  uStack_144 = 0xd;

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  uStack_144 = 0xffffffff;

  param_1[0x15a] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x15a] + 0x28))("i_d_fet_2d_btn_options.xml");

  (**(code **)(*(int *)param_1[0x15a] + 0x74))(0x9c41);

  (**(code **)(*(int *)param_1[0x15a] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x4cc);

  uStack_158 = 0xe;

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  uStack_158 = 0xffffffff;

  param_1[0x15b] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x15b] + 0x28))("i_d_fet_2d_btn_create.xml");

  (**(code **)(*(int *)param_1[0x15b] + 0x74))(0x9c43);

  (**(code **)(*(int *)param_1[0x15b] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x4cc);

  local_16c = 0xf;

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  local_16c = 0xffffffff;

  param_1[0x15c] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x15c] + 0x28))("i_d_fet_2d_btn_remember.xml");

  (**(code **)(*(int *)param_1[0x15c] + 0x74))(0x9c44);

  (**(code **)(*(int *)param_1[0x15c] + 0x3b4))(1);

  (**(code **)(*(int *)param_1[0x15c] + 0xfc))(1,0x3f000000);

  (**(code **)(*(int *)param_1[0x15c] + 0x3c8))(DAT_00d1b200,1);

  pvVar1 = operator_new(0x4cc);

  local_190.field1_0x4.mi.dx = 0x10;

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  local_190.field1_0x4.mi.dx = -1;

  param_1[0x15d] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x15d] + 0x28))("i_d_fet_2d_btn_cinematic.xml");

  (**(code **)(*(int *)param_1[0x15d] + 0x74))(0x9c45);

  (**(code **)(*(int *)param_1[0x15d] + 0xfc))(1,0x3f000000);

  pvVar1 = operator_new(0x4cc);

  iVar3 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar3 = FUN_0079c860();

  }

  param_1[0x15e] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x15e] + 0x28))("i_d_fet_2d_btn_quit.xml");

  (**(code **)(*(int *)param_1[0x15e] + 0x74))(0x9c42);

  (**(code **)(*(int *)param_1[0x15e] + 0xfc))(1,0x3f000000);

  if (DAT_00d1b20d != '\0') {

    (**(code **)(*(int *)param_1[0x15e] + 0xd4))(0);

  }

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar3 = param_1[0x1a];

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  (**(code **)(*param_1 + 0x3f4))(1);

  param_1[0x126] = 40000;

  param_1[0x127] = 0x9c42;

  (**(code **)(*(int *)param_1[0x161] + 0x1c8))(0);

  (**(code **)(*(int *)param_1[0x162] + 0x1c8))(0);

  (**(code **)(*(int *)param_1[0x163] + 0x1c8))(0);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0x1;

  return;

}
