// =============================================================================
// FUN_005718a0 — twin of InventoryGrid_SetOwner_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005718a0
// Address:   0x005718a0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-04 WQ8R-A dual (supersedes 2026-07-23 iVar scaffold)
// Named clean: InventoryGrid_SetOwner_Inferred.cpp
// =============================================================================

#include <cstdint>
#include <windows.h>

struct InventoryGrid;
struct InventoryItem;

extern "C" void __fastcall FUN_004294f0(void* list);
extern "C" unsigned __thiscall FUN_004022a0(
    void* list, int* iterState, void** outItem);

using ItemBindOwner_t = void(__thiscall*)(InventoryItem* self, void* owner);

void __thiscall FUN_005718a0(InventoryGrid* self, void* ownerObject)
{
    auto* base = reinterpret_cast<std::uint8_t*>(self);
    *reinterpret_cast<void**>(base + 0x24) = ownerObject;

    void* list = base + 0x2c;
    int iterState = 0;
    void* itemCursor = nullptr;

    FUN_004294f0(list);
    unsigned done = FUN_004022a0(list, &iterState, &itemCursor);
    while (done == 0) {
        auto* item = reinterpret_cast<InventoryItem*>(itemCursor);
        void** vtbl = *reinterpret_cast<void***>(item);
        auto bind = reinterpret_cast<ItemBindOwner_t>(vtbl[0x158 / 4]);
        bind(item, *reinterpret_cast<void**>(base + 0x24));
        done = FUN_004022a0(list, &iterState, &itemCursor);
    }

    if (*reinterpret_cast<char*>(base + 0x54) != 0) {
        *reinterpret_cast<char*>(base + 0x54) = 0;
        LeaveCriticalSection(
            reinterpret_cast<LPCRITICAL_SECTION>(base + 0x30));
    }
}
