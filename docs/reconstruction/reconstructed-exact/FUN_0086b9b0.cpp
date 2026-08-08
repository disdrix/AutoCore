// =============================================================================
// FUN_0086b9b0  /  UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0086b9b0
// Address:   0x0086b9b0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (UI arena tournament-schedule chrome builder)
// Dual:      R13-009 2026-08-05 — accept-with-gaps
// Exactness: Scaffold twin. Prefer named clean:
//   reconstructed-exact/UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred.cpp
// Canonical: UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred (_Inferred)
// Supersedes plate alias: UI_arena_tournament_schedule_mini_label
// ABI: __thiscall ECX=host*; plain RET; body 0x0086b9b0-0x0086cc81 (0x12D2)
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / Runtime Confirmed).
// =============================================================================

// PURPOSE: Virtual create-child-widgets for Arena Tournament Schedule dialog.
// Embedded plate family: i_d_arena/i_d_arena_tournament_schedule_*.xml
// Dualed helpers: FUN_00822cb0 (tab select), FUN_00756c90 (move-to-front).
// See annotated + named clean for sealed slot/tab tables.

// READABILITY (auto CF retained below from 2026-07-23 scaffold):
//  - Body size: ~576 non-empty decompiler lines.
//  - Notable callees: FUN_007b5dd0×many, FUN_0079c860, FUN_00822cb0×3,
//    FUN_008230b0×3, FUN_00756c90×2, FUN_0078b6e0×2, FUN_0078f890, FUN_00792600.
//  - Return sites: 1 (plain RET after SEH restore).

/*
 * Behavioral notes (R13-009):
 * - __thiscall ECX = host; virtual via DATA 0x00a5ed20 (vtbl +0x43C).
 * - Not inventory wire; not mini-label-only.
 * - Runtime / differential verification: OPEN.
 */


void /*__thiscall ECX*/ FUN_0086b9b0(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  void *pvVar4;

  float fVar5;

  float fVar6;

  uint32_t /* width from decompiler */ uVar7;

  char *pcVar8;

  char *pcStack_218;

  uint32_t /* width from decompiler */ uStack_210;

  char *pcStack_20c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b8a89;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  *(uint8_t *)(param_1 + 0x14a) = 0;

  *(uint8_t *)((int)param_1 + 0xc5) = 0;

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

  param_1[0x162] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x162] + 0x28))();

  pvVar1 = operator_new(0x4bc);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00864f20();

  }

  param_1[0x163] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x163] + 0x28))();

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

  param_1[0x165] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x165] + 0x28))();

  (**(code **)(*(int *)param_1[0x165] + 0x1d8))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x167] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x167] + 0x28))();

  (**(code **)(*(int *)param_1[0x167] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x168] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x168] + 0x28))();

  (**(code **)(*(int *)param_1[0x168] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x16b] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x16b] + 0x28))();

  (**(code **)(*(int *)param_1[0x16b] + 0x74))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x16c] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x16c] + 0x28))();

  (**(code **)(*(int *)param_1[0x16c] + 0x74))();

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x16d] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x16d] + 0x28))();

  (**(code **)(*(int *)param_1[0x16d] + 0x74))();

  (**(code **)(*(int *)param_1[0x16d] + 0x474))();

  (**(code **)(*(int *)param_1[0x16d] + 0x43c))();

  (**(code **)(*(int *)param_1[0x16d] + 0xfc))();

  pvVar1 = operator_new(0x9a8);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078b6e0();

  }

  param_1[0x16e] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x16e] + 0x28))();

  (**(code **)(*(int *)param_1[0x16e] + 0x74))();

  (**(code **)(*(int *)param_1[0x16e] + 0x474))();

  (**(code **)(*(int *)param_1[0x16e] + 0x43c))();

  (**(code **)(*(int *)param_1[0x16e] + 0xfc))();

  pvVar1 = operator_new(0x954);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_0078f890();

  }

  param_1[0x171] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x171] + 0x28))();

  (**(code **)(*(int *)param_1[0x171] + 0x74))();

  (**(code **)(*(int *)param_1[0x171] + 0x468))();

  (**(code **)(*(int *)param_1[0x171] + 0x43c))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x186] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x186] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x187] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x187] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x188] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x188] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x174] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x174] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x172] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x172] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x173] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x173] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x175] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x175] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x177] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x177] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x181] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x181] + 0x28))();

  (**(code **)(*(int *)param_1[0x181] + 0x74))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x17c] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17c] + 0x28))();

  (**(code **)(*(int *)param_1[0x17c] + 0x74))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x176] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x176] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x178] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x178] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x182] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x182] + 0x28))();

  (**(code **)(*(int *)param_1[0x182] + 0x74))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x17d] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17d] + 0x28))();

  (**(code **)(*(int *)param_1[0x17d] + 0x74))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x179] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x179] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x183] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x183] + 0x28))();

  (**(code **)(*(int *)param_1[0x183] + 0x74))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x17e] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17e] + 0x28))();

  (**(code **)(*(int *)param_1[0x17e] + 0x74))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x17a] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17a] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x184] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x184] + 0x28))();

  (**(code **)(*(int *)param_1[0x184] + 0x74))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x17f] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17f] + 0x28))();

  (**(code **)(*(int *)param_1[0x17f] + 0x74))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x17b] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x17b] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x185] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x185] + 0x28))();

  (**(code **)(*(int *)param_1[0x185] + 0x74))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x180] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x180] + 0x28))();

  (**(code **)(*(int *)param_1[0x180] + 0x74))();

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

  param_1[0x189] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x189] + 0x28))();

  pvVar1 = operator_new(0x488);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0();

  }

  param_1[0x18a] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x18a] + 0x28))();

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x18b] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x18b] + 0x28))();

  (**(code **)(*(int *)param_1[0x18b] + 0x74))();

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_008230b0();

  }

  param_1[0x18c] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x18c] + 0x28))();

  (**(code **)(*(int *)param_1[0x18c] + 0x43c))();

  (**(code **)(*(int *)param_1[0x18c] + 0x74))();

  FUN_00822cb0();

  FUN_00756c90();

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_008230b0();

  }

  param_1[0x18d] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x18d] + 0x28))();

  (**(code **)(*(int *)param_1[0x18d] + 0x43c))();

  (**(code **)(*(int *)param_1[0x18d] + 0x74))();

  pcStack_20c = (char *)0x86c916;

  FUN_00822cb0();

  (**(code **)(*(int *)param_1[0x18d] + 0x94))();

  pcStack_20c = (char *)0x86c92e;

  pvVar1 = operator_new(0x81c);

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    pcStack_20c = (char *)0x86c947;

    iVar2 = FUN_008230b0();

  }

  param_1[0x18e] = iVar2;

  pcStack_20c = (char *)0x86c965;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_20c = "i_d_arena/i_d_arena_tournament_schedule_tab_advanced.xml";

  uStack_210 = 0x86c975;

  (**(code **)(*(int *)param_1[0x18e] + 0x28))();

  uStack_210 = 0x86c983;

  (**(code **)(*(int *)param_1[0x18e] + 0x43c))();

  uStack_210 = 0x9c47;

  (**(code **)(*(int *)param_1[0x18e] + 0x74))();

  pcStack_218 = (char *)0x86c9a2;

  FUN_00822cb0();

  FUN_00756c90();

  pcStack_218 = (char *)0x86c9b7;

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x141] = iVar2;

  pcStack_218 = (char *)0x86c9ee;

  (**(code **)(*param_1 + 0xa8))();

  pcStack_218 = "i_d_arena/i_d_arena_tournament_schedule_btn_close.xml";

  (**(code **)(*(int *)param_1[0x141] + 0x28))();

  (**(code **)(*(int *)param_1[0x141] + 0x74))(40000);

  pcStack_20c = operator_new(0x488);

  if (pcStack_20c == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    pvVar1 = (void *)FUN_007b5dd0(pcStack_20c,0);

  }

  param_1[399] = (int)pvVar1;

  (**(code **)(*param_1 + 0xa8))();

  pcVar8 = "i_d_arena/i_d_arena_tournament_schedule_mini_wnd_bg_texture.xml";

  (**(code **)(*(int *)param_1[399] + 0x28))

            ("i_d_arena/i_d_arena_tournament_schedule_mini_wnd_bg_texture.xml");

  uVar7 = 0;

  (**(code **)(*(int *)param_1[399] + 0xcc))(0);

  fVar5 = DAT_00aaac10;

  *(uint8_t *)(param_1[399] + 0xc4) = 1;

  if (((float)param_1[0x14d] <= fVar5) || ((float)param_1[0x14e] <= fVar5)) {

    iVar2 = (**(code **)(*(int *)param_1[399] + 0x120))(&uStack_210,1,0);

    pcVar8 = (char *)(float)(*(int *)(iVar2 + 4) + param_1[0x14c]);

    piVar3 = (int *)(**(code **)(*(int *)param_1[399] + 0x120))(&stack0xfffffdec,1,0);

    if (DAT_00d17944 == 0) {

      fVar5 = 0.0;

      fVar6 = 0.0;

    }

    else {

      fVar5 = ((float)(*piVar3 + param_1[0x14b]) * DAT_00aaa674) / (float)DAT_00d1e818;

      fVar6 = ((float)pcStack_218 * DAT_00aaa670) / (float)DAT_00d1e81c;

    }

    param_1[0x14d] = (int)fVar5;

    param_1[0x14e] = (int)fVar6;

  }

  pcStack_218 = (char *)0x0;

  (**(code **)(*(int *)param_1[399] + 0x110))(&pcStack_218,uVar7,pcVar8);

  pvVar4 = operator_new(0x488);

  if (pvVar4 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_007b5dd0(pvVar4,0);

  }

  param_1[400] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[400] + 0x28))

            ("i_d_arena/i_d_arena_tournament_schedule_mini_wnd_label_status.xml");

  (**(code **)(*(int *)param_1[400] + 0xcc))(0);

  *(uint8_t *)(param_1[400] + 0xc4) = 1;

  pvVar4 = operator_new(0x4cc);

  iVar2 = 0;

  if (pvVar4 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  param_1[0x191] = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)param_1[0x191] + 0x28))

            ("i_d_arena/i_d_arena_tournament_schedule_mini_btn_cancel.xml");

  (**(code **)(*(int *)param_1[0x191] + 0x74))(0x9c4a);

  (**(code **)(*(int *)param_1[0x191] + 0xcc))(0);

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  FUN_0086b370();

  FUN_0086a900(0xffffffff,0xffffffff);

  if ((DAT_00d1b6d8 != 0) && (*(char *)(DAT_00d1b6d8 + 0x4fc) != '\0')) {

    FUN_0086b3c0();

  }

  ExceptionList = pvVar1;

  return;

}
