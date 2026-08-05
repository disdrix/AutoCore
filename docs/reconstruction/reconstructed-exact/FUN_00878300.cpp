// =============================================================================
// FUN_00878300
// -----------------------------------------------------------------------------
// Stable ID: aa_00878300
// Address:   0x00878300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00878300 @ 0x00878300
// Stable ID: aa_00878300
// Embedded strings (evidence for future rename):
//   - "i_d_arena/i_d_arena_console_tab_tournament.xml"
//   - "i_d_arena/i_d_arena_console_tab_advanced.xml"
//   - "i_d_arena/i_d_arena_console_mini_wnd_bg_texture.xml"
//   - "i_d_arena/i_d_arena_console_mini_wnd_label_status.xml"
//   - "i_d_arena/i_d_arena_console_mini_btn_cancel.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~289 non-empty decompiler lines.
//  - Control keywords: if×23, return×1.
//  - Notable callees: FUN_007b5dd0×11, FUN_0079c860×4, FUN_00822cb0×3, FUN_008230b0×3, FUN_00756c90×2, FUN_0078f890, FUN_00792600, FUN_00864f20.
//  - Strings: "i_d_arena/i_d_arena_console_tab_tournament.xml"; "i_d_arena/i_d_arena_console_tab_advanced.xml"; "i_d_arena/i_d_arena_console_mini_wnd_bg_texture.xml"; "i_d_arena/i_d_arena_console_mini_wnd_label_status.xml".
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

void __fastcall FUN_00878300(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  void *pvVar4;

  float fVar5;

  float fVar6;

  uint32_t /* width from decompiler */ uVar7;

  char *pcVar8;

  char *pcStack_e0;

  uint32_t /* width from decompiler */ uStack_d8;

  char *pcStack_d4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b902f;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *(uint8_t *)(param_1 + 0x149) = 0;

  *(uint8_t *)((int)param_1 + 0xc5) = 0;

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  (**(code **)(*param_1 + 0x110))();

  (**(code **)(*param_1 + 0x130))();

  FUN_00792600();

  pvVar1 = operator_new(0x488);

  pvStack_c = (void *)0x0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  pvStack_c = (void *)0xffffffff;

  param_1[0x153] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x153] + 0x28))();

  pvVar1 = operator_new(0x4bc);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00864f20();

  }

  param_1[0x154] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x154] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x155] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x155] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x157] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x157] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x158] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x158] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x159] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x159] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x15a] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15a] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x156] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x156] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x15b] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15b] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x15c] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15c] + 0x28))();

  pvVar1 = operator_new(0x954);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078f890();

  }

  param_1[0x15d] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15d] + 0x28))();

  (**(code **)(*(int *)param_1[0x15d] + 0x43c))();

  (**(code **)(*(int *)param_1[0x15d] + 0x468))();

  (**(code **)(*(int *)param_1[0x15d] + 0x74))();

  FUN_00877790();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x15e] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15e] + 0x28))();

  (**(code **)(*(int *)param_1[0x15e] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x15f] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15f] + 0x28))();

  (**(code **)(*(int *)param_1[0x15f] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x141] + 0x28))();

  (**(code **)(*(int *)param_1[0x141] + 0x74))();

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_008230b0();

  }

  param_1[0x160] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x160] + 0x28))();

  (**(code **)(*(int *)param_1[0x160] + 0x43c))();

  (**(code **)(*(int *)param_1[0x160] + 0x74))();

  pcStack_d4 = (char *)0x878895;

  FUN_00822cb0();

  (**(code **)(*(int *)param_1[0x160] + 0x94))();

  pcStack_d4 = (char *)0x8788ad;

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    pcStack_d4 = (char *)0x8788c6;

    iVar2 = FUN_008230b0();

  }

  param_1[0x161] = iVar2;

  pcStack_d4 = (char *)0x8788e0;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_d4 = "i_d_arena/i_d_arena_console_tab_tournament.xml";

  uStack_d8 = 0x8788f0;

  (**(code **)(*(int *)param_1[0x161] + 0x28))();

  uStack_d8 = 0x8788fe;

  (**(code **)(*(int *)param_1[0x161] + 0x43c))();

  uStack_d8 = 0x9c44;

  (**(code **)(*(int *)param_1[0x161] + 0x74))();

  pcStack_e0 = (char *)0x87891d;

  FUN_00822cb0();

  FUN_00756c90();

  pcStack_e0 = (char *)0x878932;

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    pcStack_e0 = (char *)0x87894b;

    iVar2 = FUN_008230b0();

  }

  param_1[0x162] = iVar2;

  pcStack_e0 = (char *)0x878969;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_e0 = "i_d_arena/i_d_arena_console_tab_advanced.xml";

  (**(code **)(*(int *)param_1[0x162] + 0x28))();

  (**(code **)(*(int *)param_1[0x162] + 0x43c))();

  (**(code **)(*(int *)param_1[0x162] + 0x74))(0x9c45);

  FUN_00822cb0(1);

  FUN_00756c90();

  pcStack_d4 = operator_new(0x488);

  if (pcStack_d4 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    pvVar1 = (void *)FUN_007b5dd0(pcStack_d4,0);

  }

  param_1[0x163] = (int)pvVar1;

  (**(code **)(*param_1 + 0xa8))();

  pcVar8 = "i_d_arena/i_d_arena_console_mini_wnd_bg_texture.xml";

  (**(code **)(*(int *)param_1[0x163] + 0x28))

            ("i_d_arena/i_d_arena_console_mini_wnd_bg_texture.xml");

  uVar7 = 0;

  (**(code **)(*(int *)param_1[0x163] + 0xcc))(0);

  fVar5 = DAT_00aaac10;

  *(uint8_t *)(param_1[0x163] + 0xc4) = 1;

  if (((float)param_1[0x14c] <= fVar5) || ((float)param_1[0x14d] <= fVar5)) {

    iVar2 = (**(code **)(*(int *)param_1[0x163] + 0x120))(&uStack_d8,1,0);

    pcVar8 = (char *)(float)(*(int *)(iVar2 + 4) + param_1[0x14b]);

    piVar3 = (int *)(**(code **)(*(int *)param_1[0x163] + 0x120))(&stack0xffffff24,1,0);

    if (DAT_00d17944 == 0) {

      fVar5 = 0.0;

      fVar6 = 0.0;

    }

    else {

      fVar5 = ((float)(*piVar3 + param_1[0x14a]) * DAT_00aaa674) / (float)DAT_00d1e818;

      fVar6 = ((float)pcStack_e0 * DAT_00aaa670) / (float)DAT_00d1e81c;

    }

    param_1[0x14c] = (int)fVar5;

    param_1[0x14d] = (int)fVar6;

  }

  pcStack_e0 = (char *)0x0;

  (**(code **)(*(int *)param_1[0x163] + 0x110))(&pcStack_e0,uVar7,pcVar8);

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar4,0);

  }

  param_1[0x164] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x164] + 0x28))

            ("i_d_arena/i_d_arena_console_mini_wnd_label_status.xml");

  (**(code **)(*(int *)param_1[0x164] + 0xcc))(0);

  *(uint8_t *)(param_1[0x164] + 0xc4) = 1;

  pvVar4 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar4 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x165] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x165] + 0x28))("i_d_arena/i_d_arena_console_mini_btn_cancel.xml");

  (**(code **)(*(int *)param_1[0x165] + 0x74))(0x9c47);

  (**(code **)(*(int *)param_1[0x165] + 0xcc))(0);

  FUN_008778e0(param_1);

  if ((DAT_00d1b6d8 != 0) && (*(char *)(DAT_00d1b6d8 + 0x4fc) != '\0')) {

    FUN_00877c50();

  }

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = pvVar1;

  return;

}
