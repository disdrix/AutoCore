// =============================================================================
// UI_TabsSo_SetActiveTab_Inferred  (Ghidra: FUN_00887780)
// -----------------------------------------------------------------------------
// Stable ID: aa_00887780
// Address:   0x00887780–0x00887a63 (autoassault.exe, image base 0x400000)
// Body:      740 B (0x2E4); terminal RET 8 (C2 08 00); pad CC
// System:    inventory-transfer  (i_d_tabs_so_* friends / clan / enemies)
// Generated: 2026-08-05 R13-012 dual (live Ghidra decompile + disasm + read_memory)
// Exactness: Behavior-preserving rewrite of machine control flow. Not modernization.
//            Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Switch the host i_d_tabs_so dialog to tabIndex {0=friends, 1=clan,
//   2=enemies}: show/hide content panes, select/deselect tab buttons, refresh
//   the newly selected tab (vtbl+0x94). No-op when host is not visible, or
//   when force==0 and tabIndex already equals dialog+0x534.
//
// ABI (bytes-sealed):
//   hybrid __usercall
//     EAX     = tabIndex (int 0/1/2; other values = store-only after gate)
//     stack+4 = dialog*  (int* / UI object)
//     stack+8 = force    (char / bool)
//   RET 0x8; void
//   NOT thiscall — entry: PUSH EBP; MOV EBP,[ESP+8]; PUSH ESI; MOV ESI,EAX
//
// LAYOUT (dialog):
//   +0x50c [0x143] content pane  — tab 0 friends
//   +0x510 [0x144] content pane  — tab 1 clan
//   +0x514 [0x145] content pane  — tab 2 enemies
//   +0x518 [0x146] tab button    — friends  (i_d_tabs_so_2d_tab_friends.xml)
//   +0x51c [0x147] tab button    — clan     (i_d_tabs_so_2d_tab_clan.xml)
//   +0x520 [0x148] tab button    — enemies  (i_d_tabs_so_2d_tab_enemies.xml)
//   +0x534 [0x14d] active tab index (int)
//
// VTBL (child widgets / host):
//   +0x3d8  is-visible → AL
//   +0x43c  show-prep (before enable)
//   +0x440  hide-post (after disable)
//   +0x4    set-enabled(bool)   // push 0/1
//   +0x94   tab refresh (selected tab only)
//
// CALLEES (register ABI — decompiler shows unaff_*):
//   FUN_00822cb0(force@stack): ESI=widget, BL=selected (0/1)
//     dualed UI_TabChrome_SetSelected_Inferred (R12-002)
//   FUN_00756c90():            EDI=widget  (move-to-front / reparent group)
//     dualed UI_Widget_MoveToFrontInParentGroup_Inferred (R12-003; partition parent)
//
// CALLERS (evidence; not dualled here):
//   FUN_00887c70                     CreateChildWidgets force re-apply
//   Client_Input_PollBoundActions    hotkey paths → tabs 0/1/2 on DAT_00d1b878
//   residual cmd/toggle sites        @ 0x00887a95 / 0x00887aad / 0x00887ac5 /
//                                    0x00887b2b / 0x00887b44
//
// HOST GLOBAL: DAT_00d1b878
//
// Retired scaffold product name:
//   Named_CalleeOf_Client_Input_PollBoundActions_00887780
// Plate under-specific (ctor alias, not this VA):
//   UI_tabs_so_tab_enemies
// =============================================================================

#include <cstdint>

// Dualed helpers — register ABI sealed at call sites inside this unit.
// Decompiler surfaces them as stack-only; machine uses ESI/EDI/BL.
extern "C" void FUN_00822cb0(char force);
extern "C" uint32_t FUN_00756c90(void);

// Portable model of the register-bearing callees for readability.
// Image call sites set ESI/BL (00822cb0) and EDI (00756c90) before CALL.
static inline void TabBtn_SetSelected_Inferred(void *widget, char force,
                                               char selected) {
  // Machine: MOV ESI, widget; MOV BL, selected; PUSH force; CALL 00822cb0
  (void)widget;
  (void)selected;
  FUN_00822cb0(force);
}

static inline void TabBtn_MoveToFront_Inferred(void *widget) {
  // Machine: MOV EDI, widget; CALL 00756c90
  (void)widget;
  FUN_00756c90();
}

using VCall0 = char(__thiscall *)(void *self);
using VCall1 = void(__thiscall *)(void *self, int arg);

static inline void **Vtbl(void *obj) {
  return *reinterpret_cast<void ***>(obj);
}

static inline char Ui_IsVisible(void *obj) {
  return reinterpret_cast<VCall0>(Vtbl(obj)[0x3d8 / 4])(obj);
}

static inline void Ui_ShowIfHidden(void *obj) {
  if (Ui_IsVisible(obj) == 0) {
    reinterpret_cast<VCall0>(Vtbl(obj)[0x43c / 4])(obj);
    reinterpret_cast<VCall1>(Vtbl(obj)[0x4 / 4])(obj, 1);
  }
}

static inline void Ui_HideIfVisible(void *obj) {
  if (Ui_IsVisible(obj) != 0) {
    reinterpret_cast<VCall1>(Vtbl(obj)[0x4 / 4])(obj, 0);
    reinterpret_cast<VCall0>(Vtbl(obj)[0x440 / 4])(obj);
  }
}

static inline void Ui_TabRefresh(void *tabBtn) {
  reinterpret_cast<VCall0>(Vtbl(tabBtn)[0x94 / 4])(tabBtn);
}

// Image entry: tabIndex arrives in EAX; dialog + force on stack; RET 8.
// C signature is documentary — MSVC will not place tabIndex in EAX automatically.
extern "C" void UI_TabsSo_SetActiveTab_Inferred(int *dialog, char force,
                                                int tabIndex /* @EAX */) {
  if (Ui_IsVisible(dialog) == 0) {
    return;
  }
  // Skip if not forced and already on this tab (dialog+0x534).
  if (force == 0 && tabIndex == dialog[0x14d]) {
    return;
  }

  dialog[0x14d] = tabIndex;

  void *panelFriends = reinterpret_cast<void *>(dialog[0x143]); // +0x50c
  void *panelClan = reinterpret_cast<void *>(dialog[0x144]);    // +0x510
  void *panelEnemies = reinterpret_cast<void *>(dialog[0x145]); // +0x514
  void *tabFriends = reinterpret_cast<void *>(dialog[0x146]);   // +0x518
  void *tabClan = reinterpret_cast<void *>(dialog[0x147]);      // +0x51c
  void *tabEnemies = reinterpret_cast<void *>(dialog[0x148]);   // +0x520

  if (tabIndex == 0) {
    // Friends page.
    Ui_ShowIfHidden(panelFriends);
    Ui_HideIfVisible(panelClan);
    Ui_HideIfVisible(panelEnemies);
    TabBtn_SetSelected_Inferred(tabFriends, force, 1);
    Ui_TabRefresh(tabFriends);
    TabBtn_SetSelected_Inferred(tabClan, force, 0);
    TabBtn_MoveToFront_Inferred(tabClan);
    TabBtn_SetSelected_Inferred(tabEnemies, force, 0);
    TabBtn_MoveToFront_Inferred(tabEnemies);
    return;
  }

  if (tabIndex == 1) {
    // Clan page (shared tail deselects enemies).
    Ui_HideIfVisible(panelFriends);
    Ui_ShowIfHidden(panelClan);
    Ui_HideIfVisible(panelEnemies);
    TabBtn_SetSelected_Inferred(tabFriends, force, 0);
    TabBtn_MoveToFront_Inferred(tabFriends);
    TabBtn_SetSelected_Inferred(tabClan, force, 1);
    Ui_TabRefresh(tabClan);
    TabBtn_SetSelected_Inferred(tabEnemies, force, 0);
    TabBtn_MoveToFront_Inferred(tabEnemies);
    return;
  }

  if (tabIndex != 2) {
    return; // out-of-range: active index stored, no panel work
  }

  // Enemies page (early RET after select — no shared tail).
  Ui_HideIfVisible(panelFriends);
  Ui_HideIfVisible(panelClan);
  Ui_ShowIfHidden(panelEnemies);
  TabBtn_SetSelected_Inferred(tabFriends, force, 0);
  TabBtn_MoveToFront_Inferred(tabFriends);
  TabBtn_SetSelected_Inferred(tabClan, force, 0);
  TabBtn_MoveToFront_Inferred(tabClan);
  TabBtn_SetSelected_Inferred(tabEnemies, force, 1);
  Ui_TabRefresh(tabEnemies);
}
