// =============================================================================
// CVOGStore_TryAddItemQty_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00588290
// Address:   0x00588290  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-04 WQ8R-A dual A/B (supersedes scaffold FUN_00588290.cpp)
// Exactness: Behavior-preserving rewrite of live decompile + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false (no runtime Confirmed)
// =============================================================================
//
// PURPOSE:
//   CVOGStore (host+0x35c → InventoryGrid*): try to absorb `qty` of `item` into
//   the store grid. Prefer in-list CBID stack merge under IsStackEligible; else
//   set item qty, mark flag 0x10, find free cell (2×2 if both InvSize 0, else
//   FindFreeForItem with stack preferred), PlaceItemFootprint.
//
// ABI (byte-sealed):
//   __thiscall  ECX = CVOGStore* (or host with grid @ +0x35c)
//   stack: item*, qty
//   ret 0x08
//   return: qty on success, 0 on null/full miss
//
// ODD (preserve):
//   - Stack-merge path does NOT call Item_CanAcceptStackQty / max-stack clamp.
//   - Free path SetQty(item, qty) is absolute assign of the argument.
//   - Degenerate InvSize (0,0) forces footprint search as 2×2 via FindFreeSlot.
//   - Decompiler unaff_EBX/unaff_retaddr == outX/outY locals from FindFree*.
//
// Dual: reviews/A_aa_00588290_CVOGStore_TryAddItemQty_Inferred.md
//       reviews/B_aa_00588290_CVOGStore_TryAddItemQty_Inferred.md
// =============================================================================

#include <cstdint>
#include <windows.h>

struct CVOGStore;
struct InventoryGrid;
struct InventoryItem;

extern "C" void __fastcall FUN_004294f0(void* list);
extern "C" unsigned __thiscall FUN_004022a0(
    void* list, int* iterNode, void** outItem);

extern "C" std::uint8_t __fastcall Item_IsStackEligible(InventoryItem* item); // 0x00513e70
extern "C" void __fastcall FUN_00512670(void* obj); // mark dirty |= 0x20000

extern "C" std::uint32_t __thiscall InventoryGrid_FindFreeSlot(
    InventoryGrid* self,
    std::uint32_t sizeX,
    std::uint32_t sizeY,
    std::uint8_t* outX,
    std::uint8_t* outY,
    char pageIndex); // 0x005713a0

extern "C" std::uint32_t __thiscall InventoryGrid_FindFreeForItem(
    InventoryGrid* self,
    InventoryItem* item,
    std::uint8_t* outX,
    std::uint8_t* outY,
    char allowStack,
    int pageIndex); // 0x005714e0 — thiscall ECX = grid

extern "C" std::uint32_t __thiscall InventoryGrid_PlaceItemFootprint(
    InventoryGrid* self,
    InventoryItem* item,
    std::uint32_t cellX,
    std::uint32_t cellY,
    std::uint32_t qty); // 0x00571620

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
    // item+0xa8 → type holder; holder+0x34 → CBID
    auto* holder = *reinterpret_cast<std::uint8_t**>(
        reinterpret_cast<std::uint8_t*>(item) + 0xa8);
    return *reinterpret_cast<int*>(holder + 0x34);
}

int __thiscall CVOGStore_TryAddItemQty_Inferred(
    CVOGStore* self,
    InventoryItem* item,
    int qty)
{
    auto* host = reinterpret_cast<std::uint8_t*>(self);
    auto* grid = *reinterpret_cast<InventoryGrid**>(host + 0x35c);

    if (item == nullptr || grid == nullptr) {
        return 0;
    }

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
            // ODD: no CanAcceptStackQty — may grow past max stack
            int cur = Item_GetQty(existing);
            Item_SetQty(existing, cur + qty);
            GridList_UnlockIfHeld(gridBase);
            return qty;
        }
        done = FUN_004022a0(list, &iterNode, &existingRaw);
    }
    GridList_UnlockIfHeld(gridBase);

    // Free-path prep on the incoming item
    Item_SetQty(item, qty);
    *reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<std::uint8_t*>(item) + 0x17c) |= 0x10u;
    FUN_00512670(item);

    std::uint8_t outX = 0;
    std::uint8_t outY = 0;
    std::uint32_t found = 0;

    auto* holder = *reinterpret_cast<std::uint8_t**>(
        reinterpret_cast<std::uint8_t*>(item) + 0xa8);
    auto* blob = *reinterpret_cast<std::uint8_t**>(holder + 0x3c);

    if (blob[0x406] == 0 && blob[0x407] == 0) {
        found = InventoryGrid_FindFreeSlot(
            grid, 2, 2, &outX, &outY, static_cast<char>(-1));
    } else {
        // Call site loads ECX = grid from host+0x35c (sealed residual a_005714e0)
        found = InventoryGrid_FindFreeForItem(
            grid, item, &outX, &outY, /*allowStack=*/1, /*pageIndex=*/-1);
    }

    if (found != 0) {
        int q = Item_GetQty(item);
        InventoryGrid_PlaceItemFootprint(
            grid, item, outX, outY, static_cast<std::uint32_t>(q));
        return qty;
    }
    return 0;
}
