// =============================================================================
// FUN_00588290 — twin of CVOGStore_TryAddItemQty_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00588290
// Address:   0x00588290  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-04 WQ8R-A dual (supersedes 2026-07-23 iVar scaffold)
// Named clean: CVOGStore_TryAddItemQty_Inferred.cpp
// =============================================================================

#include <cstdint>
#include <windows.h>

struct CVOGStore;
struct InventoryGrid;
struct InventoryItem;

extern "C" void __fastcall FUN_004294f0(void* list);
extern "C" unsigned __thiscall FUN_004022a0(
    void* list, int* iterNode, void** outItem);
extern "C" std::uint8_t __fastcall Item_IsStackEligible(InventoryItem* item);
extern "C" void __fastcall FUN_00512670(void* obj);
extern "C" std::uint32_t __thiscall InventoryGrid_FindFreeSlot(
    InventoryGrid* self, std::uint32_t sizeX, std::uint32_t sizeY,
    std::uint8_t* outX, std::uint8_t* outY, char pageIndex);
extern "C" std::uint32_t __thiscall InventoryGrid_FindFreeForItem(
    InventoryGrid* self, InventoryItem* item, std::uint8_t* outX,
    std::uint8_t* outY, char allowStack, int pageIndex);
extern "C" std::uint32_t __thiscall InventoryGrid_PlaceItemFootprint(
    InventoryGrid* self, InventoryItem* item, std::uint32_t cellX,
    std::uint32_t cellY, std::uint32_t qty);

using GetQty_t = int(__thiscall*)(InventoryItem* self);
using SetQty_t = void(__thiscall*)(InventoryItem* self, int qty);

static inline void GridList_UnlockIfHeld(std::uint8_t* gridBase)
{
    if (*reinterpret_cast<char*>(gridBase + 0x54) != 0) {
        *reinterpret_cast<char*>(gridBase + 0x54) = 0;
        LeaveCriticalSection(
            reinterpret_cast<LPCRITICAL_SECTION>(gridBase + 0x30));
    }
}

static inline int Item_GetQty(InventoryItem* item)
{
    void** vtbl = *reinterpret_cast<void***>(item);
    return reinterpret_cast<GetQty_t>(vtbl[0x25C / 4])(item);
}

static inline void Item_SetQty(InventoryItem* item, int qty)
{
    void** vtbl = *reinterpret_cast<void***>(item);
    reinterpret_cast<SetQty_t>(vtbl[0x260 / 4])(item, qty);
}

static inline int Item_GetCbid(InventoryItem* item)
{
    auto* holder = *reinterpret_cast<std::uint8_t**>(
        reinterpret_cast<std::uint8_t*>(item) + 0xa8);
    return *reinterpret_cast<int*>(holder + 0x34);
}

int __thiscall FUN_00588290(CVOGStore* self, InventoryItem* item, int qty)
{
    auto* host = reinterpret_cast<std::uint8_t*>(self);
    auto* grid = *reinterpret_cast<InventoryGrid**>(host + 0x35c);
    if (item == nullptr || grid == nullptr)
        return 0;

    auto* gridBase = reinterpret_cast<std::uint8_t*>(grid);
    void* list = gridBase + 0x2c;
    int iterNode = 0;
    void* existingRaw = nullptr;

    FUN_004294f0(list);
    unsigned done = FUN_004022a0(list, &iterNode, &existingRaw);
    while (done == 0) {
        auto* existing = reinterpret_cast<InventoryItem*>(existingRaw);
        if (existing != nullptr
            && Item_GetCbid(existing) == Item_GetCbid(item)
            && Item_IsStackEligible(existing) != 0) {
            Item_SetQty(existing, Item_GetQty(existing) + qty);
            GridList_UnlockIfHeld(gridBase);
            return qty;
        }
        done = FUN_004022a0(list, &iterNode, &existingRaw);
    }
    GridList_UnlockIfHeld(gridBase);

    Item_SetQty(item, qty);
    *reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<std::uint8_t*>(item) + 0x17c) |= 0x10u;
    FUN_00512670(item);

    std::uint8_t outX = 0, outY = 0;
    std::uint32_t found = 0;
    auto* holder = *reinterpret_cast<std::uint8_t**>(
        reinterpret_cast<std::uint8_t*>(item) + 0xa8);
    auto* blob = *reinterpret_cast<std::uint8_t**>(holder + 0x3c);

    if (blob[0x406] == 0 && blob[0x407] == 0) {
        found = InventoryGrid_FindFreeSlot(
            grid, 2, 2, &outX, &outY, static_cast<char>(-1));
    } else {
        found = InventoryGrid_FindFreeForItem(
            grid, item, &outX, &outY, 1, -1);
    }

    if (found != 0) {
        InventoryGrid_PlaceItemFootprint(
            grid, item, outX, outY,
            static_cast<std::uint32_t>(Item_GetQty(item)));
        return qty;
    }
    return 0;
}
