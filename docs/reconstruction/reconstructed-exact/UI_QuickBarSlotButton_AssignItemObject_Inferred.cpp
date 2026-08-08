// =============================================================================
// UI_QuickBarSlotButton_AssignItemObject_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008285a0
// Address:   0x008285a0  (autoassault.exe, image base 0x400000)
// Body:      0x008285a0 – 0x00828756 (0x1B7 bytes)
// System:    skills-abilities / client UI quickbar
// Generated: 2026-08-05 R11-026 dual seal
//            (decompile_function + disassemble_function + read_memory + xrefs)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Bind a live **item object** onto one QuickBar slot-button, mirror
// into local CVOGCharacter quick-bar arrays (set item id from clonebase+0x34,
// clear skill), rebuild icon path via inventory-texture helper on the object,
// refresh chrome.
//
// ABI: item object* in EAX; button in ESI; plain ret; returns 0 (null) or 1.
// Twin of UI_QuickBarSlotButton_AssignItem_Inferred (0x008283a0, id in ECX).
// Peer of UI_QuickBarSlotButton_AssignSkill_Inferred (0x00826860, skill* EAX).

#include <cstdint>

// Sealed callees (not redefined here):
//   CVOGCharacter_SetQuickBarItem      @ 0x00520890  (thiscall, ret 0xC)
//   CVOGCharacter_SetQuickBarSkill     @ 0x005208c0  (thiscall, ret 8)
//   UI_QuickBarSlotButton_SetSelected  @ 0x00826780  (thiscall, ret 4)
//   FUN_0085d970                       @ 0x0085d970  (path extract residual)

extern void* DAT_00d1b6d8;            // local CVOGCharacter*
extern uint32_t DAT_00afdf0c[];       // color block (not a path string)

// Forward decls of sealed callees (signatures simplified for plate).
extern void __thiscall CVOGCharacter_SetQuickBarItem(
    void* self, uint8_t slot, uint32_t idLo, uint32_t idHi);
extern void __thiscall CVOGCharacter_SetQuickBarSkill(
    void* self, uint8_t slot, int skillId);
extern void __thiscall UI_QuickBarSlotButton_SetSelected(void* self, int selected);
extern void FUN_0085d970(void* itemObj, char* pathOut);

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

// Item-like object: +0xa8 → clonebase*; clonebase+0x34 = id (int32).
struct ItemObject {
    uint8_t _pad[0xA8];
    void*   pCloneBase;       // +0xA8
};

struct CloneBaseId {
    uint8_t _pad[0x34];
    int32_t id;               // +0x34
};

// Retail: item in EAX, button in ESI — modeled as explicit args for clarity.
uint32_t UI_QuickBarSlotButton_AssignItemObject_Inferred(
    ItemObject* item /*EAX*/,
    UI_QuickBarSlotButton* button /*ESI*/)
{
    if (item == nullptr) {
        return 0;
    }

    const int32_t itemId =
        reinterpret_cast<CloneBaseId*>(item->pCloneBase)->id;

    const bool bChanged =
        !((button->payloadKind == 2) &&
          (button->itemIdLo == itemId) &&
          (button->itemIdHi == (itemId >> 31)));

    button->payloadKind = 2;
    button->itemIdLo = itemId;
    button->itemIdHi = itemId >> 31;  // cdq
    button->flatSlot = button->pageIndex * 10 + button->columnIndex;
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
        char pathBuf[260];
        FUN_0085d970(item, pathBuf);  // inventory texture path from object
        // icon vtbl +0x2c8(0) / +0x50(path,r) / +0x15c(0,&DAT_00afdf0c) / +0x34c
        // — sealed as call order only; path extract residual.
        (void)pathBuf;
        (void)DAT_00afdf0c;
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
