// =============================================================================
// UI_QuickBarSlotButton_AssignItemOrMacro_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00827670
// Address:   0x00827670  (autoassault.exe, image base 0x400000)
// Body:      0x00827670 – 0x00827918 exclusive (680 B / 0x2A8)
// System:    client UI / quickbar
// Generated: 2026-07-29 W24-I dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI corrections.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Bind an item/macro (non-skill) payload onto one QuickBar slot-button:
// store kind+id, mirror into CVOGCharacter (set item, clear skill), optional
// deselect, rebuild kind-specific chrome (Power/Battle/Macro).
//
// ABI: button in ESI; kind in EAX; id on stack; ret 4; returns 1.
// Twin skill path: UI_QuickBarSlotButton_AssignSkill_Inferred @ 0x00826860
// Sibling type-2 item object path: FUN_008283a0

#include <cstdint>
#include <cstdio>

extern void* DAT_00d1b6d8;

// Sealed callees:
//   CVOGCharacter_SetQuickBarItem  @ 0x00520890
//   CVOGCharacter_SetQuickBarSkill @ 0x005208c0
//   UI_QuickBarSlotButton_SetSelected @ 0x00826780
//   FUN_008264f0 (macro chrome helper)

struct UI_QuickBarSlotButton {
    void**   vtbl;            // +0x00; +0x448 refresh
    uint8_t  _pad004[0x4F8];
    uint8_t  fSelected;       // +0x4FC
    uint8_t  _pad4fd;
    uint8_t  iconState;       // +0x4FE
    uint8_t  _pad4ff;
    int32_t  columnIndex;     // +0x500
    int32_t  pageIndex;       // +0x504
    uint8_t  _pad508[0x40];
    int32_t  payloadKind;     // +0x548  (3=Power,4=Battle,5=Macro, …)
    int32_t  idLo;            // +0x550
    int32_t  idHi;            // +0x554
    void*    pExtra;          // +0x558 cleared to 0 here
    int32_t  flatSlot;        // +0x55C
    uint8_t  _pad560[0x4];
    void*    pIconWidget;     // +0x564
    uint8_t  _pad568[0xC];
    void*    pChromeA;        // +0x574  "Power"/"Battle"
    void*    pChromeB;        // +0x578  secondary / "(%d)"
    void*    pOwnedChild;     // +0x57C
};

// Modeled with explicit args; retail uses ESI/EAX live-ins.
uint32_t UI_QuickBarSlotButton_AssignItemOrMacro_Inferred(
    UI_QuickBarSlotButton* btn /*ESI*/,
    int32_t kind /*EAX*/,
    int32_t id /*stack*/)
{
    const bool bChanged =
        !((btn->payloadKind == kind) &&
          (btn->idLo == id) &&
          (btn->idHi == (id >> 31)));

    btn->idLo = id;
    btn->idHi = id >> 31;
    btn->flatSlot = btn->columnIndex + btn->pageIndex * 10;
    btn->payloadKind = kind;
    btn->pExtra = nullptr;

    const int slot =
        static_cast<char>(btn->pageIndex) * 10 +
        static_cast<char>(btn->columnIndex);

    // Character exclusive policy: item present, skill cleared.
    // CVOGCharacter_SetQuickBarItem(DAT_00d1b6d8, slot, idLo, idHi);
    // CVOGCharacter_SetQuickBarSkill(DAT_00d1b6d8, slot, -1);

    if (bChanged && btn->fSelected != 0) {
        // UI_QuickBarSlotButton_SetSelected(btn, 0);
    }

    btn->iconState = 0;

    if (btn->pOwnedChild != nullptr) {
        // (*vtbl+4)(1) destroy/release
    }

    if (btn->pIconWidget != nullptr) {
        // vtbl+0x58 reset
        if (kind == 3) {
            // SetText empty; chromeB null; chromeA "Power"
        } else if (kind == 4) {
            // SetText empty; chromeB null; chromeA "Battle"
        } else if (kind == 5) {
            // texture "i_d_macro_2d_wnd_icon.dds"
            char buf[8];
            std::sprintf(buf, "(%d)", id + 0xbb9);
            // chromeB SetText(buf); FUN_008264f0(btn);
        }
        // shared: chrome refresh + color pair (-1 / 0xFFFFFFFF) via vtbl+0x15c
    }

    // btn->vtbl[0x448/4]();
    return 1;
}

// Scaffold
uint32_t FUN_00827670(UI_QuickBarSlotButton* btn, int32_t kind, int32_t id)
{
    return UI_QuickBarSlotButton_AssignItemOrMacro_Inferred(btn, kind, id);
}
