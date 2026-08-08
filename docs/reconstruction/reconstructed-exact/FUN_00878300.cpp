// =============================================================================
// FUN_00878300
// -----------------------------------------------------------------------------
// Stable ID: aa_00878300
// Address:   0x00878300  (autoassault.exe, image base 0x400000)
// Body:      0x00878300–0x00878c14 inclusive (0x915 B)
// System:    inventory-transfer (partition; pure client UI construct)
// Generated: 2026-08-05 R13-010 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            XML paths + command ids restored from disasm (decompiler drops them).
// Named:     UI_ArenaConsole_CreateChildWidgets_Inferred.cpp
// Dual A/B:  accept-with-gaps; Terminal false; never Runtime Confirmed.
// =============================================================================

// Ghidra residual twin — keep FUN_* name as synonym.
// Canonical: UI_ArenaConsole_CreateChildWidgets_Inferred

typedef unsigned char  undefined1;
typedef unsigned int   undefined4;

extern void *ExceptionList;
extern undefined1 LAB_009b902f;
extern float DAT_00aaac10;   // -99998.0f
extern float DAT_00aaa670;   // 1200.0f
extern float DAT_00aaa674;   // 1600.0f
extern int DAT_00d17944;
extern int DAT_00d1e818;
extern int DAT_00d1e81c;
extern int DAT_00d1b6d8;

extern void *operator_new(unsigned);
extern int FUN_007b5dd0(void);
extern int FUN_00864f20(void);
extern int FUN_0078f890(void);
extern int FUN_0079c860(void);
extern int FUN_008230b0(void);
extern void FUN_00792600(void);
extern void FUN_00822cb0(void);
extern void FUN_00756c90(void);
extern void FUN_00877790(void);
extern void FUN_008778e0(int *);
extern void FUN_00877c50(void);

void __fastcall FUN_00878300(int *param_1 /* ECX = host */)
{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  char *pcVar8;
  char *pcStack_e0;
  undefined4 uStack_d8;
  char *pcStack_d4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b902f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;

  *(undefined1 *)(param_1 + 0x149) = 0;           /* host+0x524 */
  *(undefined1 *)((int)param_1 + 0xc5) = 0;
  param_1[0x13f] = 0xf;                           /* host+0x4fc */
  param_1[0x140] = 1;                             /* host+0x500 */
  (**(code **)(*param_1 + 0x110))();
  (**(code **)(*param_1 + 0x130))();
  FUN_00792600();

  /* +0x54c bg_fill */
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_007b5dd0(); }
  param_1[0x153] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x153] + 0x28))("i_d_arena/i_d_arena_console_wnd_bg_fill.xml");

  /* +0x550 fx */
  pvVar1 = operator_new(0x4bc);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_00864f20(); }
  param_1[0x154] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x154] + 0x28))("i_d_arena/i_d_arena_console_wnd_fx.xml");

  /* +0x554 bg_texture */
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_007b5dd0(); }
  param_1[0x155] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x155] + 0x28))("i_d_arena/i_d_arena_console_wnd_bg_texture.xml");

  /* +0x55c title */
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_007b5dd0(); }
  param_1[0x157] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x157] + 0x28))("i_d_arena/i_d_arena_console_wnd_title.xml");

  /* +0x560 bg_logo */
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_007b5dd0(); }
  param_1[0x158] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x158] + 0x28))("i_d_arena/i_d_arena_console_wnd_bg_logo.xml");

  /* +0x564 bg_help */
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_007b5dd0(); }
  param_1[0x159] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x159] + 0x28))("i_d_arena/i_d_arena_console_wnd_bg_help.xml");

  /* +0x568 help */
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_007b5dd0(); }
  param_1[0x15a] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15a] + 0x28))("i_d_arena/i_d_arena_console_wnd_help.xml");

  /* +0x558 arena_logo */
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_007b5dd0(); }
  param_1[0x156] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x156] + 0x28))("i_d_arena/i_d_arena_console_wnd_arena_logo.xml");

  /* +0x56c bg_dynamic_news */
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_007b5dd0(); }
  param_1[0x15b] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15b] + 0x28))("i_d_arena/i_d_arena_console_wnd_bg_dynamic_news.xml");

  /* +0x570 stats_dynamic_news */
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_007b5dd0(); }
  param_1[0x15c] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15c] + 0x28))("i_d_arena/i_d_arena_console_wnd_stats_dynamic_news.xml");

  /* +0x574 sb_dynamic_news */
  pvVar1 = operator_new(0x954);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_0078f890(); }
  param_1[0x15d] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15d] + 0x28))("i_d_arena/i_d_arena_console_sb_dynamic_news.xml");
  (**(code **)(*(int *)param_1[0x15d] + 0x43c))();
  (**(code **)(*(int *)param_1[0x15d] + 0x468))(1);
  (**(code **)(*(int *)param_1[0x15d] + 0x74))(0x9c46);
  FUN_00877790();

  /* +0x578 instant_action */
  pvVar1 = operator_new(0x4cc);
  iVar2 = 0;
  if (pvVar1 != (void *)0x0) { iVar2 = FUN_0079c860(); }
  param_1[0x15e] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15e] + 0x28))("i_d_arena/i_d_arena_console_btn_instant_action.xml");
  (**(code **)(*(int *)param_1[0x15e] + 0x74))(0x9c41);

  /* +0x57c my_stats */
  pvVar1 = operator_new(0x4cc);
  iVar2 = 0;
  if (pvVar1 != (void *)0x0) { iVar2 = FUN_0079c860(); }
  param_1[0x15f] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x15f] + 0x28))("i_d_arena/i_d_arena_console_btn_my_stats.xml");
  (**(code **)(*(int *)param_1[0x15f] + 0x74))(0x9c42);

  /* +0x504 close */
  pvVar1 = operator_new(0x4cc);
  iVar2 = 0;
  if (pvVar1 != (void *)0x0) { iVar2 = FUN_0079c860(); }
  param_1[0x141] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x141] + 0x28))("i_d_arena/i_d_arena_console_btn_close.xml");
  (**(code **)(*(int *)param_1[0x141] + 0x74))(0x9c40);

  /* +0x580 tab_console (selected) */
  pvVar1 = operator_new(0x81c);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_008230b0(); }
  param_1[0x160] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x160] + 0x28))("i_d_arena/i_d_arena_console_tab_console.xml");
  (**(code **)(*(int *)param_1[0x160] + 0x43c))();
  (**(code **)(*(int *)param_1[0x160] + 0x74))(0x9c43);
  /* ESI=tab; BL=1; PUSH 1; CALL UI_TabChrome_SetSelected */
  FUN_00822cb0();
  (**(code **)(*(int *)param_1[0x160] + 0x94))();

  /* +0x584 tab_tournament (collapsed + MoveToFront) */
  pvVar1 = operator_new(0x81c);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_008230b0(); }
  param_1[0x161] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x161] + 0x28))("i_d_arena/i_d_arena_console_tab_tournament.xml");
  (**(code **)(*(int *)param_1[0x161] + 0x43c))();
  (**(code **)(*(int *)param_1[0x161] + 0x74))(0x9c44);
  /* ESI=tab; BL=0; PUSH 1; CALL SetSelected */
  FUN_00822cb0();
  /* EDI=tab; CALL MoveToFront */
  FUN_00756c90();

  /* +0x588 tab_advanced (collapsed + MoveToFront) */
  pvVar1 = operator_new(0x81c);
  if (pvVar1 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_008230b0(); }
  param_1[0x162] = iVar2;
  (**(code **)(*param_1 + 0xa8))();
  (**(code **)(*(int *)param_1[0x162] + 0x28))("i_d_arena/i_d_arena_console_tab_advanced.xml");
  (**(code **)(*(int *)param_1[0x162] + 0x43c))();
  (**(code **)(*(int *)param_1[0x162] + 0x74))(0x9c45);
  FUN_00822cb0();
  FUN_00756c90();

  /* +0x58c mini bg */
  pcStack_d4 = operator_new(0x488);
  if (pcStack_d4 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  } else {
    pvVar1 = (void *)FUN_007b5dd0();
  }
  param_1[0x163] = (int)pvVar1;
  (**(code **)(*param_1 + 0xa8))();
  pcVar8 = "i_d_arena/i_d_arena_console_mini_wnd_bg_texture.xml";
  (**(code **)(*(int *)param_1[0x163] + 0x28))
            ("i_d_arena/i_d_arena_console_mini_wnd_bg_texture.xml");
  uVar7 = 0;
  (**(code **)(*(int *)param_1[0x163] + 0xcc))(0);
  fVar5 = DAT_00aaac10; /* -99998.0f */
  *(undefined1 *)(param_1[0x163] + 0xc4) = 1;
  if (((float)param_1[0x14c] <= fVar5) || ((float)param_1[0x14d] <= fVar5)) {
    iVar2 = (**(code **)(*(int *)param_1[0x163] + 0x120))(&uStack_d8, 1, 0);
    pcVar8 = (char *)(float)(*(int *)(iVar2 + 4) + param_1[0x14b]);
    piVar3 = (int *)(**(code **)(*(int *)param_1[0x163] + 0x120))(&pcStack_e0 /* size */, 1, 0);
    if (DAT_00d17944 == 0) {
      fVar5 = 0.0f;
      fVar6 = 0.0f;
    } else {
      fVar5 = ((float)(*piVar3 + param_1[0x14a]) * DAT_00aaa674) / (float)DAT_00d1e818; /* *1600 */
      fVar6 = ((float)/* height component */ *(int *)(iVar2 + 4) /* restored via stack */ * DAT_00aaa670)
              / (float)DAT_00d1e81c; /* *1200 — see disasm for exact stack temps */
      (void)pcStack_e0;
    }
    param_1[0x14c] = (int)fVar5;
    param_1[0x14d] = (int)fVar6;
  }
  pcStack_e0 = (char *)0x0;
  (**(code **)(*(int *)param_1[0x163] + 0x110))(&pcStack_e0, uVar7, pcVar8);

  /* +0x590 mini status */
  pvVar4 = operator_new(0x488);
  if (pvVar4 == (void *)0x0) { iVar2 = 0; } else { iVar2 = FUN_007b5dd0(); }
  param_1[0x164] = iVar2;
  (**(code **)(*param_1 + 0xa8))(iVar2);
  (**(code **)(*(int *)param_1[0x164] + 0x28))
            ("i_d_arena/i_d_arena_console_mini_wnd_label_status.xml");
  (**(code **)(*(int *)param_1[0x164] + 0xcc))(0);
  *(undefined1 *)(param_1[0x164] + 0xc4) = 1;

  /* +0x594 mini cancel */
  pvVar4 = operator_new(0x4cc);
  iVar2 = 0;
  if (pvVar4 != (void *)0x0) { iVar2 = FUN_0079c860(); }
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
  ExceptionList = pvStack_c;
  return;
}
