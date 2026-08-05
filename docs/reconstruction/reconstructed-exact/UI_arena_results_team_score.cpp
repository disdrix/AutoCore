// =============================================================================
// UI_arena_results_team_score
// -----------------------------------------------------------------------------
// Stable ID: aa_00871c30
// Address:   0x00871c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_arena_results_team_score @ 0x00871c30
// Stable ID: aa_00871c30
// Embedded strings (evidence for future rename):
//   - "i_d_arena/i_d_arena_results_lb_last_match.xml"
//   - "i_d_arena/i_d_arena_results_wnd_scores.xml"
//   - "i_d_arena/i_d_arena_results_wnd_team_name_%d.xml"
//   - "i_d_arena/i_d_arena_results_wnd_team_score_%d.xml"
//   - "i_d_arena/i_d_arena_results_btn_close.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~495 non-empty decompiler lines.
//  - Control keywords: if×43, do×1, while×1, return×1.
//  - Notable callees: FUN_007b5dd0×20, FUN_0079c860×11, FUN_0078b6e0×7, FUN_0078f890×3, sprintf×2, FUN_00792600, FUN_007fbe50, FUN_00864f20.
//  - Strings: "i_d_arena/i_d_arena_results_lb_last_match.xml"; "i_d_arena/i_d_arena_results_wnd_scores.xml"; "i_d_arena/i_d_arena_results_wnd_team_name_%d.xml"; "i_d_arena/i_d_arena_results_wnd_team_score_%d.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_arena/i_d_arena_results_wnd_team_score_%d.xml"
 * Domain alias of FUN_00871c30 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_arena_results_team_score(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  void *pvStack_2e8;

  int iStack_2e4;

  char *pcStack_2e0;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8ed5;

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

  param_1[0x15b] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15b] + 0x28))();

  pvVar1 = operator_new(0x4bc);

  pvStack_c = (void *)0x1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00864f20();

  }

  pvStack_c = (void *)0xffffffff;

  param_1[0x15c] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15c] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x15d] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15d] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x15e] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15e] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x15f] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x15f] + 0x28))();

  FUN_00870290();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x160] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x160] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x161] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x161] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x162] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x162] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x163] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  if (DAT_00d1b20d == '\x01') {

    (**(code **)(*(int *)param_1[0x163] + 0x28))();

  }

  else {

    (**(code **)(*(int *)param_1[0x163] + 0x28))();

  }

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x164] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x164] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x165] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x165] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x166] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x166] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x167] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x167] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x168] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x168] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x169] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x169] + 0x28))();

  pvVar1 = operator_new(0x954);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078f890();

  }

  param_1[0x16a] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x16a] + 0x28))();

  (**(code **)(*(int *)param_1[0x16a] + 0x74))();

  (**(code **)(*(int *)param_1[0x16a] + 0x43c))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x16b] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x16b] + 0x28))();

  FUN_008703b0();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x16c] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x16c] + 0x28))();

  pvVar1 = operator_new(0x954);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078f890();

  }

  param_1[0x16d] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x16d] + 0x28))();

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

  FUN_00870320();

  pvVar1 = operator_new(0x954);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078f890();

  }

  param_1[0x16f] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x16f] + 0x28))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x170] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x170] + 0x28))();

  (**(code **)(*(int *)param_1[0x170] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x171] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x171] + 0x28))();

  (**(code **)(*(int *)param_1[0x171] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x172] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x172] + 0x28))();

  (**(code **)(*(int *)param_1[0x172] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x173] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x173] + 0x28))();

  (**(code **)(*(int *)param_1[0x173] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x174] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x174] + 0x28))();

  (**(code **)(*(int *)param_1[0x174] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x175] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x175] + 0x28))();

  (**(code **)(*(int *)param_1[0x175] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x176] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x176] + 0x28))();

  (**(code **)(*(int *)param_1[0x176] + 0x74))();

  (**(code **)(*(int *)param_1[0x176] + 0x1d8))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x177] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x177] + 0x28))();

  (**(code **)(*(int *)param_1[0x177] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x178] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x178] + 0x28))();

  (**(code **)(*(int *)param_1[0x178] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x179] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x179] + 0x28))();

  (**(code **)(*(int *)param_1[0x179] + 0x74))();

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x17a] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17a] + 0x28))();

  (**(code **)(*(int *)param_1[0x17a] + 0x474))();

  (**(code **)(*(int *)param_1[0x17a] + 0x43c))();

  (**(code **)(*(int *)param_1[0x17a] + 0xfc))();

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x17b] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17b] + 0x28))();

  (**(code **)(*(int *)param_1[0x17b] + 0x474))();

  (**(code **)(*(int *)param_1[0x17b] + 0x43c))();

  (**(code **)(*(int *)param_1[0x17b] + 0xfc))();

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x17c] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17c] + 0x28))();

  (**(code **)(*(int *)param_1[0x17c] + 0x474))();

  (**(code **)(*(int *)param_1[0x17c] + 0x43c))();

  (**(code **)(*(int *)param_1[0x17c] + 0xfc))();

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x17d] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17d] + 0x28))();

  (**(code **)(*(int *)param_1[0x17d] + 0x474))();

  (**(code **)(*(int *)param_1[0x17d] + 0x43c))();

  (**(code **)(*(int *)param_1[0x17d] + 0xfc))();

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x17e] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17e] + 0x28))();

  (**(code **)(*(int *)param_1[0x17e] + 0x474))();

  (**(code **)(*(int *)param_1[0x17e] + 0x43c))();

  (**(code **)(*(int *)param_1[0x17e] + 0xfc))();

  (**(code **)(*(int *)param_1[0x17e] + 0x480))();

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x17f] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17f] + 0x28))();

  (**(code **)(*(int *)param_1[0x17f] + 0x474))();

  (**(code **)(*(int *)param_1[0x17f] + 0x43c))();

  (**(code **)(*(int *)param_1[0x17f] + 0xfc))();

  (**(code **)(*(int *)param_1[0x17f] + 0x480))();

  pcStack_2e0 = (char *)0x872af2;

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x180] = iVar2;

  pcStack_2e0 = (char *)0x872b2c;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_2e0 = "i_d_arena/i_d_arena_results_lb_last_match.xml";

  iStack_2e4 = 0x872b3c;

  (**(code **)(*(int *)param_1[0x180] + 0x28))();

  iStack_2e4 = 0x9c4c;

  pvStack_2e8 = (void *)0x872b4f;

  (**(code **)(*(int *)param_1[0x180] + 0x474))();

  pvStack_2e8 = (void *)0x872b5d;

  (**(code **)(*(int *)param_1[0x180] + 0x43c))();

  pvStack_2e8 = (void *)0x3f000000;

  (**(code **)(*(int *)param_1[0x180] + 0xfc))(1);

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar1,0);

  }

  param_1[0x181] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x181] + 0x28))("i_d_arena/i_d_arena_results_wnd_scores.xml");

  iVar2 = 1;

  piVar4 = param_1 + 0x186;

  iStack_2e4 = 4;

  do {

    sprintf(&stack0xfffffd24,"i_d_arena/i_d_arena_results_wnd_team_name_%d.xml",iVar2);

    pcStack_2e0 = operator_new(0x488);

    if (pcStack_2e0 == (char *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_007b5dd0(pcStack_2e0,0);

    }

    piVar4[-4] = iVar3;

    (**(code **)(*param_1 + 0xa8))(iVar3);

    (**(code **)(*(int *)piVar4[-4] + 0x28))(&pcStack_2e0);

    sprintf((char *)&iStack_2e4,"i_d_arena/i_d_arena_results_wnd_team_score_%d.xml",iVar2);

    pvStack_2e8 = operator_new(0x488);

    if (pvStack_2e8 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_007b5dd0(pvStack_2e8,0);

    }

    *piVar4 = iVar3;

    (**(code **)(*param_1 + 0xa8))(iVar3);

    (**(code **)(*(int *)*piVar4 + 0x28))(&pvStack_2e8);

    piVar4 = piVar4 + 1;

    iVar2 = iVar2 + 1;

    iStack_2e4 = iStack_2e4 + -1;

  } while (iStack_2e4 != 0);

  pcStack_2e0 = operator_new(0x4cc);

  if (pcStack_2e0 == (char *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0079c860();

  }

  param_1[0x141] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x141] + 0x28))("i_d_arena/i_d_arena_results_btn_close.xml");

  (**(code **)(*(int *)param_1[0x141] + 0x74))(40000);

  (**(code **)(*(int *)param_1[0x171] + 0xd4))(0);

  (**(code **)(*(int *)param_1[0x172] + 0xd4))(0);

  FUN_00870680(param_1[0x143]);

  FUN_00870070();

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  *(uint8_t *)(param_1 + 0x152) = 1;

  FUN_007fbe50();

  ExceptionList = (void *)0x9c42;

  return;

}
