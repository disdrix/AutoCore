// =============================================================================
// UI_Cs2dTabs_SelectTab_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Select active tab on the client Cs2d dual-tab host window
//           (i_d_tabs_cs_2d_*): tab 0 = R&D, tab 1 = Memorization.
//           Swaps content panels, expands/collapses tab chrome, refreshes
//           the newly active tab control (vtbl+0x94).
//
// Address:  0x00888b00  (autoassault.exe, image base 0x400000)
// Stable:   aa_00888b00
// System:   inventory-transfer (UI craft/memorize tabs — no inventory wire)
// Ghidra:   FUN_00888b00
//
// Convention (custom stdcall + EAX formal):
//   EAX          = tabIndex  (0 = R&D, 1 = Memorization)
//   stack arg0   = window*   (Cs2d host; often DAT_00d1b870)
//   stack arg1   = force     (char; non-zero re-applies same tab)
//   RET 8
//
// Layout (window):
//   +0x510 [0x144]  content panel 0 (R&D)
//   +0x514 [0x145]  content panel 1 (Memorization)
//   +0x51c [0x147]  tab control R&D      (xml tab_randd; cmd 0x9c43)
//   +0x520 [0x148]  tab control Mem      (xml tab_memorization; cmd 0x9c44)
//   +0x534 [0x14d]  selected tab index
//
// Shared UI vtbl:
//   +0x3d8 is-visible; +0x43c show; +0x440 hide; +0x4 enable(0/1); +0x94 tab activate
//
// Callees:
//   FUN_00822cb0 — ESI=tab control, BL=expand(1)/collapse(0), stack force
//   FUN_00756c90 — EDI=collapsed tab control
//
// Callers (evidence): Client_Input_PollBoundActions; FUN_0082f510 case5;
//   FUN_0080dcc0 memorize-success; FUN_00888e50 ctor; FUN_00937270; tab OnCommand.
//
// Exactness: Behavior-preserving CF from live disasm + decompile.
// Dual R11-031 2026-08-05.
// Dual reviews:
//   reviews/A_aa_00888b00_UI_Cs2dTabs_SelectTab_Inferred.md
//   reviews/B_aa_00888b00_UI_Cs2dTabs_SelectTab_Inferred.md
// Scaffold twin: reconstructed-exact/FUN_00888b00.cpp
// =============================================================================

#include <cstdint>

// Residual callees — dual elsewhere / open.
extern "C" void FUN_00822cb0(char force); // ESI=ctrl, BL=expand; force stack
extern "C" int  FUN_00756c90(void);       // EDI=ctrl

using Vcall0  = char (__thiscall *)(void* self);
using Vcall1i = void (__thiscall *)(void* self, int a);
using VcallV  = void (__thiscall *)(void* self);

static inline char UiIsVisible(void* obj)
{
    auto** vt = *reinterpret_cast<void***>(obj);
    return reinterpret_cast<Vcall0>(vt[0x3d8 / 4])(obj);
}

static inline void UiShow(void* obj)
{
    auto** vt = *reinterpret_cast<void***>(obj);
    reinterpret_cast<VcallV>(vt[0x43c / 4])(obj);
}

static inline void UiHide(void* obj)
{
    auto** vt = *reinterpret_cast<void***>(obj);
    reinterpret_cast<VcallV>(vt[0x440 / 4])(obj);
}

static inline void UiSetEnabled(void* obj, int enabled)
{
    auto** vt = *reinterpret_cast<void***>(obj);
    reinterpret_cast<Vcall1i>(vt[0x4 / 4])(obj, enabled);
}

static inline void UiTabActivate(void* obj)
{
    auto** vt = *reinterpret_cast<void***>(obj);
    reinterpret_cast<VcallV>(vt[0x94 / 4])(obj);
}

/// Select Cs2d R&D/Memorization tab (INFERRED product name).
/// Custom ABI: tabIndex in EAX; window + force on stack; RET 8.
void UI_Cs2dTabs_SelectTab_Inferred(int* window, int force /*char*/, int tabIndex /*EAX*/)
{
    auto** wvt = *reinterpret_cast<void***>(window);
    char visible = reinterpret_cast<Vcall0>(wvt[0x3d8 / 4])(window);
    if (visible == 0) {
        return;
    }

    int* selected = reinterpret_cast<int*>(reinterpret_cast<char*>(window) + 0x534);
    if (static_cast<char>(force) == 0 && tabIndex == *selected) {
        return;
    }

    *selected = tabIndex;

    void* panel0 = *reinterpret_cast<void**>(reinterpret_cast<char*>(window) + 0x510);
    void* panel1 = *reinterpret_cast<void**>(reinterpret_cast<char*>(window) + 0x514);
    void* tabRnd = *reinterpret_cast<void**>(reinterpret_cast<char*>(window) + 0x51c);
    void* tabMem = *reinterpret_cast<void**>(reinterpret_cast<char*>(window) + 0x520);

    if (tabIndex == 0) {
        if (UiIsVisible(panel0) == 0) {
            UiShow(panel0);
            UiSetEnabled(panel0, 1);
        }
        if (UiIsVisible(panel1) != 0) {
            UiSetEnabled(panel1, 0);
            UiHide(panel1);
        }
        // Expand R&D tab chrome, activate; collapse Memorization.
        // FUN_00822cb0: ESI=tabRnd, BL=1; then ESI=tabMem, BL=0
        // FUN_00756c90: EDI=tabMem
        FUN_00822cb0(static_cast<char>(force)); // ESI/BL set by caller asm
        UiTabActivate(tabRnd);
        FUN_00822cb0(static_cast<char>(force));
        FUN_00756c90();
        return;
    }

    if (tabIndex == 1) {
        if (UiIsVisible(panel0) != 0) {
            UiSetEnabled(panel0, 0);
            UiHide(panel0);
        }
        if (UiIsVisible(panel1) == 0) {
            UiShow(panel1);
            UiSetEnabled(panel1, 1);
        }
        // Collapse R&D; expand + activate Memorization.
        FUN_00822cb0(static_cast<char>(force));
        FUN_00756c90();
        FUN_00822cb0(static_cast<char>(force));
        UiTabActivate(tabMem);
        return;
    }
    // tabIndex outside {0,1}: selected stored only
}
