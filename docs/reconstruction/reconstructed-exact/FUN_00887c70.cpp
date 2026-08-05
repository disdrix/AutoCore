// =============================================================================
// FUN_00887c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00887c70
// Address:   0x00887c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00887c70 @ 0x00887c70
// Stable ID: aa_00887c70
// Embedded strings (evidence for future rename):
//   - "i_d_tabs_so_2d_tab_enemies.xml"
//   - "i_d_tabs_so_2d_btn_close.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~137 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: FUN_007b5dd0×3, FUN_008230b0×3, FUN_008073b0×2, FUN_00792600, FUN_0079c860, FUN_00864f20, FUN_00887780, FUN_00887c70.
//  - Strings: "i_d_tabs_so_2d_tab_enemies.xml"; "i_d_tabs_so_2d_btn_close.xml".
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

void __fastcall FUN_00887c70(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int iStack_78;

  int iStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  char *pcStack_6c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b578a;

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

  param_1[0x14a] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14a] + 0x28))();

  pvVar1 = operator_new(0x4bc);

  pvStack_c = (void *)0x1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00864f20();

  }

  pvStack_c = (void *)0xffffffff;

  param_1[0x14b] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14b] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x149] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x149] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x14c] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x14c] + 0x28))();

  (**(code **)(*param_1 + 0x404))();

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_008230b0();

  }

  param_1[0x146] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x146] + 0x28))();

  (**(code **)(*(int *)param_1[0x146] + 0x43c))();

  (**(code **)(*(int *)param_1[0x146] + 0x74))();

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_008230b0();

  }

  param_1[0x147] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x147] + 0x28))();

  (**(code **)(*(int *)param_1[0x147] + 0x43c))();

  (**(code **)(*(int *)param_1[0x147] + 0x74))();

  pcStack_6c = (char *)0x887ec6;

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    pcStack_6c = (char *)0x887edf;

    iVar2 = FUN_008230b0();

  }

  param_1[0x148] = iVar2;

  pcStack_6c = (char *)0x887ef8;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_6c = "i_d_tabs_so_2d_tab_enemies.xml";

  uStack_70 = 0x887f08;

  (**(code **)(*(int *)param_1[0x148] + 0x28))();

  uStack_70 = 0x887f16;

  (**(code **)(*(int *)param_1[0x148] + 0x43c))();

  uStack_70 = 0x9c44;

  iStack_74 = 0x887f26;

  (**(code **)(*(int *)param_1[0x148] + 0x74))();

  iStack_74 = param_1[0x143];

  iStack_78 = 0x887f37;

  (**(code **)(*param_1 + 0xa8))();

  iStack_78 = param_1[0x144];

  (**(code **)(*param_1 + 0xa8))();

  pvVar1 = (void *)param_1[0x145];

  (**(code **)(*param_1 + 0xa8))();

  pcStack_6c = operator_new(0x4cc);

  iVar2 = 0;

  if (pcStack_6c != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x141] + 0x28))("i_d_tabs_so_2d_btn_close.xml");

  (**(code **)(*(int *)param_1[0x141] + 0x74))(40000);

  FUN_00887780(param_1,1);

  if (DAT_00d1da29 == '\0') {

    DAT_00d1da29 = '\x01';

    iStack_78 = 0x802e;

    FUN_008073b0(4,&iStack_78);

  }

  if (DAT_00d1da28 == '\0') {

    DAT_00d1da28 = '\x01';

    iStack_78 = 0x8023;

    FUN_008073b0(4,&iStack_78);

  }

  (**(code **)(*param_1 + 0xfc))(1,0x3f000000);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar1;

  return;

}
