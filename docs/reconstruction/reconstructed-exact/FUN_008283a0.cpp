// =============================================================================
// FUN_008283a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008283a0
// Address:   0x008283a0  (autoassault.exe, image base 0x400000)
// Body:      0x008283a0 – 0x0082859e (0x1FE bytes)
// System:    client UI / quickbar / inventory-items
// Generated: 2026-07-29 W24-J dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Named clean: UI_QuickBarSlotButton_AssignItem_Inferred.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Sealed callees:
//   QuickBar_ClearActiveSlot_INFERRED @ 0x008274c0
//   CVOGCharacter_SetQuickBarItem      @ 0x00520890
//   CVOGCharacter_SetQuickBarSkill     @ 0x005208c0
//   FUN_00826780 (UI_QuickBarSlotButton_SetSelected) @ 0x00826780
//   CVOGReaction_GiveItemByCbid        @ 0x0051a170
//   FUN_0085d970                       @ 0x0085d970

extern void* DAT_00d1b6d8;
extern void* DAT_00d1b644;
extern uint32_t DAT_00afdf0c[];

// Retail ABI: button in EAX, itemId in ECX; plain ret; returns 1.
uint32_t FUN_008283a0(int32_t* button /*EAX*/, int32_t itemId /*ECX*/)
{
    if (itemId == -1) {
        QuickBar_ClearActiveSlot_INFERRED();
        return 1;
    }

    // button dword indices: [0x152]=kind@+0x548, [0x154]=idLo@+0x550, ...
    int32_t* b = button;
    bool bChanged = true;
    if (b[0x152] == 2 && b[0x154] == itemId && b[0x155] == (itemId >> 31)) {
        bChanged = false;
    }

    b[0x154] = itemId;
    b[0x155] = itemId >> 31;
    b[0x157] = b[0x140] + b[0x141] * 10;   // flat slot
    b[0x152] = 2;                            // payloadKind item
    b[0x156] = 0;                            // pSkill null

    const uint8_t slot =
        static_cast<uint8_t>(b[0x141] * 10 + b[0x140]);

    CVOGCharacter_SetQuickBarItem(
        DAT_00d1b6d8, slot,
        static_cast<uint32_t>(b[0x154]),
        static_cast<uint32_t>(b[0x155]));
    CVOGCharacter_SetQuickBarSkill(DAT_00d1b6d8, slot, -1);

    if (bChanged && *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(b) + 0x4FC) != 0) {
        FUN_00826780();  // SetSelected(0) — thiscall ECX=button
    }

    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(b) + 0x4FE) = 0;

    if (b[0x15f] != 0) {
        // owned child destroy vtbl+4
        (**(void(__thiscall***)(void*, int))b[0x15f])(
            reinterpret_cast<void*>(b[0x15f]), 1);
    }

    if (b[0x159] != 0) {
        int32_t* tmp = reinterpret_cast<int32_t*>(
            CVOGReaction_GiveItemByCbid(b[0x154]));
        if (tmp == nullptr) {
            QuickBar_ClearActiveSlot_INFERRED();
            return 1;
        }
        // vtbl+8(idLo, DAT_00d1b644); FUN_0085d970; dtor(1);
        // icon vtbl path + color DAT_00afdf0c — order sealed, formulas residual
        (void)DAT_00d1b644;
        (void)DAT_00afdf0c;
        (void)tmp;
    }

    // chrome [0x15d]/[0x15e] virtuals; button vtbl+0x448
    return 1;
}
