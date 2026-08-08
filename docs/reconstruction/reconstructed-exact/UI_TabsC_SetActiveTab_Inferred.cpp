// =============================================================================
// UI_TabsC_SetActiveTab_Inferred  (Ghidra: FUN_00889410)
// -----------------------------------------------------------------------------
// Stable ID: aa_00889410
// Address:   0x00889410–0x008896f3 (autoassault.exe, image base 0x400000)
// Body:      740 B (0x2E4); terminal RET 8 (C2 08 00); pad CC
// System:    inventory-transfer  (i_d_tabs_c_* char / locker / achievements)
// Generated: 2026-08-05 R11-032 dual (live Ghidra decompile + disasm + read_memory)
// Exactness: Behavior-preserving rewrite of machine control flow. Not modernization.
//            Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Switch the host i_d_tabs_c dialog to tabIndex {0=char, 1=achievements,
//   2=locker}: show/hide content panes, select/deselect tab buttons, refresh
//   the newly selected tab (vtbl+0x94). No-op when host is not visible, or
//   when force==0 and tabIndex already equals dialog+0x530.
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
//   +0x50c [0x143] content pane  — tab 0 char
//   +0x510 [0x144] content pane  — tab 2 locker
//   +0x514 [0x145] content pane  — tab 1 achievements
//   +0x518 [0x146] tab button    — char         (i_d_tabs_c_2d_tab_char.xml)
//   +0x51c [0x147] tab button    — locker       (i_d_tabs_c_2d_tab_locker.xml)
//   +0x520 [0x148] tab button    — achievements (i_d_tabs_c_2d_tab_achievements.xml)
//   +0x530 [0x14c] active tab index (int)
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
//   FUN_00756c90():            EDI=widget  (remove from parent group)
//
// CALLERS (evidence; not dualled here):
//   FUN_00889960                     ctor / child build
//   FUN_0082f510                     UI_Window_OnCommand_Class8 case 4 → tab 0
//   Client_Input_PollBoundActions    hotkey paths → tabs 0/1/2
//   residual @ 0x008897xx / 0x0082dbxx / 0x008b05xx / 0x00889838
//
// HOST GLOBAL: DAT_00d1b874
//
// Retired scaffold product name:
//   Named_CalleeOf_Client_Input_PollBoundActions_00889410
// =============================================================================

#include <cstdint>

// Residual helpers — register ABI sealed at call sites inside this unit.
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

static inline void TabBtn_RemoveFromGroup_Inferred(void *widget) {
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
extern "C" void UI_TabsC_SetActiveTab_Inferred(int *dialog, char force,
                                               int tabIndex /* @EAX */) {
  if (Ui_IsVisible(dialog) == 0) {
    return;
  }
  // Skip if not forced and already on this tab (dialog+0x530).
  if (force == 0 && tabIndex == dialog[0x14c]) {
    return;
  }

  dialog[0x14c] = tabIndex;

  void *panelChar = reinterpret_cast<void *>(dialog[0x143]);   // +0x50c
  void *panelLocker = reinterpret_cast<void *>(dialog[0x144]); // +0x510
  void *panelAch = reinterpret_cast<void *>(dialog[0x145]);    // +0x514
  void *tabChar = reinterpret_cast<void *>(dialog[0x146]);     // +0x518
  void *tabLocker = reinterpret_cast<void *>(dialog[0x147]);   // +0x51c
  void *tabAch = reinterpret_cast<void *>(dialog[0x148]);      // +0x520

  if (tabIndex == 0) {
    // Char page.
    Ui_ShowIfHidden(panelChar);
    Ui_HideIfVisible(panelLocker);
    Ui_HideIfVisible(panelAch);
    TabBtn_SetSelected_Inferred(tabChar, force, 1);
    Ui_TabRefresh(tabChar);
    TabBtn_SetSelected_Inferred(tabLocker, force, 0);
    TabBtn_RemoveFromGroup_Inferred(tabLocker);
    TabBtn_SetSelected_Inferred(tabAch, force, 0);
    TabBtn_RemoveFromGroup_Inferred(tabAch);
    return;
  }

  if (tabIndex == 1) {
    // Achievements page (early RET — no shared tail).
    Ui_HideIfVisible(panelChar);
    Ui_HideIfVisible(panelLocker);
    Ui_ShowIfHidden(panelAch);
    TabBtn_SetSelected_Inferred(tabChar, force, 0);
    TabBtn_RemoveFromGroup_Inferred(tabChar);
    TabBtn_SetSelected_Inferred(tabLocker, force, 0);
    TabBtn_RemoveFromGroup_Inferred(tabLocker);
    TabBtn_SetSelected_Inferred(tabAch, force, 1);
    Ui_TabRefresh(tabAch);
    return;
  }

  if (tabIndex != 2) {
    return; // out-of-range: active index stored, no panel work
  }

  // Locker page.
  Ui_HideIfVisible(panelChar);
  Ui_ShowIfHidden(panelLocker);
  Ui_HideIfVisible(panelAch);
  TabBtn_SetSelected_Inferred(tabChar, force, 0);
  TabBtn_RemoveFromGroup_Inferred(tabChar);
  TabBtn_SetSelected_Inferred(tabLocker, force, 1);
  Ui_TabRefresh(tabLocker);
  TabBtn_SetSelected_Inferred(tabAch, force, 0);
  TabBtn_RemoveFromGroup_Inferred(tabAch);
}
