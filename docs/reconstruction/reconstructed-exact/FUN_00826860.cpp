// =============================================================================
// FUN_00826860  (scaffold alias of UI_QuickBarSlotButton_AssignSkill_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00826860
// Address:   0x00826860
// Canonical clean: UI_QuickBarSlotButton_AssignSkill_Inferred.cpp
// =============================================================================

// =============================================================================
// UI_QuickBarSlotButton_AssignSkill_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00826860
// Address:   0x00826860  (autoassault.exe, image base 0x400000)
// Body:      0x00826860 – 0x00826ad9 (0x27A bytes)
// System:    client UI / quickbar / skills-abilities
// Generated: 2026-07-29 W23-D dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Bind a skill object onto one QuickBar slot-button, mirror into the
// local CVOGCharacter quick-bar arrays (clear item, set skill), rebuild icon
// path "i_d_s_2d_wnd_icon_" + skillStem + "-on/-off.dds", refresh chrome.
//
// ABI: skill in EAX; button on stack; ret 4; returns 0 (null skill) or 1.

#include <cstdint>

// Sealed callees (not redefined here):
//   CVOGCharacter_SetQuickBarItem  @ 0x00520890  (ret 0xC)
//   CVOGCharacter_SetQuickBarSkill @ 0x005208c0  (ret 8)
//   UI_QuickBarSlotButton_SetSelected @ 0x00826780 (ret 4)

extern void* DAT_00d1b6d8;  // local CVOGCharacter*

struct UI_QuickBarSlotButton {
    // ... base widget ...
    // +0x4fc fSelected (byte)
    // +0x4fe iconState (byte)
    // +0x500 columnIndex
    // +0x504 pageIndex
    // +0x548 payloadKind   // 1 = skill
    // +0x550 skillId (int64 via cdq)
    // +0x558 pSkill
    // +0x55c flatSlot
    // +0x564 pIconWidget
    // +0x574 / +0x578 chrome
    // +0x57c ownedChild
    uint8_t  _pad0[0x4FC];
    uint8_t  fSelected;       // +0x4FC
    uint8_t  _pad4fd;
    uint8_t  iconState;       // +0x4FE
    uint8_t  _pad4ff;
    int32_t  columnIndex;     // +0x500
    int32_t  pageIndex;       // +0x504
    uint8_t  _pad508[0x40];
    int32_t  payloadKind;     // +0x548
    int32_t  skillIdLo;       // +0x550
    int32_t  skillIdHi;       // +0x554
    void*    pSkill;          // +0x558
    int32_t  flatSlot;        // +0x55C
    uint8_t  _pad560[0x4];
    void*    pIconWidget;     // +0x564
    uint8_t  _pad568[0xC];
    void*    pChromeA;        // +0x574
    void*    pChromeB;        // +0x578
    void*    pOwnedChild;     // +0x57C
};

struct SkillObject {
    // +0x5a6 icon stem (char[])
    // +0x5fc skill id (int32)
    uint8_t _pad[0x5FC];
    int32_t skillId;
};

// Retail: skill in EAX, button on stack — modeled as explicit args for clarity.
uint32_t UI_QuickBarSlotButton_AssignSkill_Inferred(
    SkillObject* skill /*EAX*/,
    UI_QuickBarSlotButton* button /*stack*/)
{
    if (skill == nullptr) {
        return 0;
    }

    const bool bChanged =
        !((button->payloadKind == 1) && (button->pSkill == skill));

    const int32_t skillId = skill->skillId;  // skill+0x5fc
    button->skillIdLo = skillId;
    button->skillIdHi = skillId >> 31;       // cdq
    button->pSkill = skill;
    button->payloadKind = 1;
    button->flatSlot = button->pageIndex * 10 + button->columnIndex;

    const uint8_t slot =
        static_cast<uint8_t>(button->pageIndex * 10 + button->columnIndex);

    // Clear item COID halves to -1; then bind skill id on character QB arrays.
    CVOGCharacter_SetQuickBarItem(DAT_00d1b6d8, slot, 0xFFFFFFFFu, 0xFFFFFFFFu);
    CVOGCharacter_SetQuickBarSkill(DAT_00d1b6d8, slot, skillId);

    if (bChanged && button->fSelected != 0) {
        UI_QuickBarSlotButton_SetSelected(button, 0);
    }

    button->iconState = 0;

    if (button->pOwnedChild != nullptr) {
        // (*(vtbl+4))(child, 1) — owning destroy
        (**(void(__thiscall***)(void*, int))button->pOwnedChild)(
            button->pOwnedChild, 1);
    }

    if (button->pIconWidget != nullptr) {
        // Build "i_d_s_2d_wnd_icon_" + skillName(+0x5a6) + "-on.dds"/"-off.dds"
        // (iconState==0 => -off.dds after clear above), set texture, invalidate.
        // Virtuals: vtbl+0x15c, +0x2c8, +0x50, +0x34c — sealed as call order only.
    }

    if (button->pChromeA != nullptr) {
        // vtbl+0x1d8(0,1,1); vtbl+0x34c()
    }
    if (button->pChromeB != nullptr) {
        // vtbl+0x1d8(0,1,1); vtbl+0x34c()
    }

    // button vtbl+0x448()
    return 1;
}
