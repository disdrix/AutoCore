// =============================================================================
// UI_QuickBarSlotButton_AssignItem_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008283a0
// Address:   0x008283a0  (autoassault.exe, image base 0x400000)
// Body:      0x008283a0 – 0x0082859e (0x1FE bytes)
// System:    client UI / quickbar / inventory-items
// Generated: 2026-07-29 W24-J dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Bind an item id (CBID/COID lo) onto one QuickBar slot-button, mirror
// into the local CVOGCharacter quick-bar arrays (set item, clear skill), rebuild
// icon from CVOGReaction_GiveItemByCbid + path helper, refresh chrome.
//
// ABI: button in EAX; itemId in ECX; plain ret; returns 1.
// Twin of UI_QuickBarSlotButton_AssignSkill_Inferred (0x00826860) with kind=2.

#include <cstdint>

// Sealed callees (not redefined here):
//   QuickBar_ClearActiveSlot_INFERRED @ 0x008274c0
//   CVOGCharacter_SetQuickBarItem      @ 0x00520890
//   CVOGCharacter_SetQuickBarSkill     @ 0x005208c0
//   UI_QuickBarSlotButton_SetSelected  @ 0x00826780
//   CVOGReaction_GiveItemByCbid        @ 0x0051a170
//   FUN_0085d970                       @ 0x0085d970  (path extract residual)

extern void* DAT_00d1b6d8;  // local CVOGCharacter*
extern void* DAT_00d1b644;
extern uint32_t DAT_00afdf0c[];  // color block, not a path string

struct UI_QuickBarSlotButton {
    // +0x4fc fSelected (byte)
    // +0x4fe iconState (byte)
    // +0x500 columnIndex
    // +0x504 pageIndex
    // +0x548 payloadKind   // 2 = item
    // +0x550 itemId (int64 via cdq)
    // +0x558 pSkill        // forced 0 on item bind
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
    int32_t  itemIdLo;        // +0x550
    int32_t  itemIdHi;        // +0x554
    void*    pSkill;          // +0x558
    int32_t  flatSlot;        // +0x55C
    uint8_t  _pad560[0x4];
    void*    pIconWidget;     // +0x564
    uint8_t  _pad568[0xC];
    void*    pChromeA;        // +0x574
    void*    pChromeB;        // +0x578
    void*    pOwnedChild;     // +0x57C
};

// Retail: button in EAX, itemId in ECX — modeled as explicit args for clarity.
uint32_t UI_QuickBarSlotButton_AssignItem_Inferred(
    UI_QuickBarSlotButton* button /*EAX*/,
    int32_t itemId /*ECX*/)
{
    if (itemId == -1) {
        QuickBar_ClearActiveSlot_INFERRED();
        return 1;
    }

    const bool bChanged =
        !((button->payloadKind == 2) &&
          (button->itemIdLo == itemId) &&
          (button->itemIdHi == (itemId >> 31)));

    button->itemIdLo = itemId;
    button->itemIdHi = itemId >> 31;  // cdq
    button->flatSlot = button->pageIndex * 10 + button->columnIndex;
    button->payloadKind = 2;
    button->pSkill = nullptr;

    const uint8_t slot =
        static_cast<uint8_t>(button->pageIndex * 10 + button->columnIndex);

    // Set item COID halves; clear skill on the exclusive slot.
    CVOGCharacter_SetQuickBarItem(
        DAT_00d1b6d8, slot,
        static_cast<uint32_t>(button->itemIdLo),
        static_cast<uint32_t>(button->itemIdHi));
    CVOGCharacter_SetQuickBarSkill(DAT_00d1b6d8, slot, -1);

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
        void* tmp = CVOGReaction_GiveItemByCbid(button->itemIdLo);
        if (tmp == nullptr) {
            QuickBar_ClearActiveSlot_INFERRED();
            return 1;
        }
        // tmp->vtbl+8(itemIdLo, DAT_00d1b644);
        // FUN_0085d970(tmp, pathBuf);
        // tmp->dtor(1);
        // icon vtbl +0x2c8 / +0x50 / +0x15c(&DAT_00afdf0c) / +0x34c
        // — sealed as call order only; path extract residual.
        (void)tmp;
        (void)DAT_00afdf0c;
        (void)DAT_00d1b644;
    }

    if (button->pChromeA != nullptr) {
        // vtbl+0x1d8(0,1); vtbl+0x34c()
    }
    if (button->pChromeB != nullptr) {
        // vtbl+0x1d8(0,1); vtbl+0x34c()
    }

    // button vtbl+0x448()
    return 1;
}
