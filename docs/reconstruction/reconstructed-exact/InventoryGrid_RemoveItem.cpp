// =============================================================================
// InventoryGrid_RemoveItem  (FUN_00571b80)
// -----------------------------------------------------------------------------
// Purpose:  Remove / pull an item from an inventory grid:
//           - Require item present in list at grid+0x2c (FUN_00415c00).
//           - Optional stack peel (FUN_00513e70 stack-mode): SetQty(cur-removeQty);
//             if remaining > 0 and forceFull==0, skip unstamp/detach and return null.
//           - Full path: clear every footprint cell to empty (-1,-1), detach list
//             node (FUN_005085b0 @ grid+0x2c), SetQty(saved), unbind vtbl+0x158(0),
//             dirty owner/grid, return item*.
//
// Address:  0x00571b80  (autoassault.exe, image base 0x400000)
// Stable:   aa_00571b80
// System:   inventory-transfer
//
// Convention: MSVC __thiscall (grid in ECX); callee RET 0x0C (3 stack args)
// Decompiler label: FUN_00571b80
//
// Signature (thiscall + stack) — sealed 2026-07-29 from read_memory:
//   ItemObject* InventoryGrid_RemoveItem(
//       InventoryGrid* this,
//       ItemObject*    item,
//       int            removeQty,
//       char           forceFullRemove);
//
// Unstamp index (asm clear loop; inverse of PlaceItemFootprint stamp):
//   index = *(grid+0x0c) * (originX + dx) + (originY + dy)
//   for dx in [0, sizeX), dy in [0, sizeY)
//   cells[index].lo/hi = 0xFFFFFFFF / 0xFFFFFFFF
//
// Type 4: skip multi-cell clear (still list-detach + unbind).
// Footprint sizes: clonebase blob +0x406 / +0x407 = InvSizeX / InvSizeY.
// Origins: item vtbl +0x250 / +0x254 (bytes stored).
//
// Related: PlaceItemFootprint 0x00571620, ContainsItem 0x00571b60,
//          FindItemByCoid 0x00571010, MergeStackQty 0x00571830
// Dual: reviews/A_aa_00571b80_InventoryGrid_RemoveItem.md
//       reviews/B_aa_00571b80_InventoryGrid_RemoveItem.md
// Exactness: CF + clear formula + ABI sealed; runtime/diff open.
// =============================================================================

#include <cstdint>

static constexpr std::uintptr_t kOffHeight    = 0x0c;
static constexpr std::uintptr_t kOffCellCount = 0x10;
static constexpr std::uintptr_t kOffOwner     = 0x24;
static constexpr std::uintptr_t kOffDirty    = 0x21;
static constexpr std::uintptr_t kOffCellArray = 0x28;
static constexpr std::uintptr_t kOffListSub   = 0x2c;

// Item: +0xa8 type host; host+0x38 type; host+0x3c blob;
//        blob +0x406/+0x407 InvSizeX/Y; +0x17c flags (bit15 skip-unless-force)

// List contains: thiscall on grid+0x2c, item on stack (same as ContainsItem).
extern "C" std::uint8_t __thiscall FUN_00415c00(void* list, void* item);
// Stack-mode probe on item (fastcall/this=item in retail path).
extern "C" std::uint8_t __fastcall FUN_00513e70(void* item);
// List detach: thiscall on grid+0x2c, item on stack.
extern "C" std::uint32_t __thiscall FUN_005085b0(void* list, void* item);
// Dirty mark *(obj+0x17c) |= 0x20000 (+ children).
extern "C" void __fastcall FUN_00512670(void* obj);

struct InventoryGrid;
struct ItemObject;

using GetQty_t   = int(__thiscall*)(ItemObject* self);
using SetQty_t   = void(__thiscall*)(ItemObject* self, int qty);
using GetCoord_t = std::uint8_t(__thiscall*)(ItemObject* self);
using BindFn_t   = void(__thiscall*)(ItemObject* self, std::uint32_t arg);

/// Remove item from grid occupancy + list, or peel stack qty.
/// @return item* on full remove; nullptr on gate fail or partial peel (forceFull==0).
ItemObject* __thiscall InventoryGrid_RemoveItem(InventoryGrid* self,
                                                ItemObject* item,
                                                int removeQty,
                                                char forceFullRemove)
{
    auto* const grid = reinterpret_cast<std::uint8_t*>(self);

    if (item == nullptr) {
        return nullptr;
    }
    if (FUN_00415c00(grid + kOffListSub, item) == 0) {
        return nullptr;
    }

    auto* const pItem = item;
    void** vtbl       = *reinterpret_cast<void***>(pItem);
    auto getQty       = reinterpret_cast<GetQty_t>(vtbl[0x25C / 4]);
    auto setQty       = reinterpret_cast<SetQty_t>(vtbl[0x260 / 4]);
    auto getOriginX   = reinterpret_cast<GetCoord_t>(vtbl[0x250 / 4]);
    auto getOriginY   = reinterpret_cast<GetCoord_t>(vtbl[0x254 / 4]);
    auto unbind       = reinterpret_cast<BindFn_t>(vtbl[0x158 / 4]);

    int savedQtyOrOne = 1;
    ItemObject* result = nullptr;

    if (FUN_00513e70(item) != 0) {
        savedQtyOrOne = getQty(item);
        int cur       = getQty(item);
        std::uint32_t flags =
            *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(item) +
                                              0x17c);
        const bool bit15 = ((flags >> 15) & 1u) != 0;

        if (cur <= 1 || bit15) {
            if (bit15) {
                if (forceFullRemove == 0) {
                    goto dirty_out; // result stays null
                }
                // forceFull != 0 → full remove below
            }
            // cur <= 1 && !bit15 → full remove
        } else {
            setQty(item, cur - removeQty);
            if (getQty(item) > 0) {
                if (forceFullRemove == 0) {
                    goto dirty_out; // partial peel; cells stay stamped
                }
            }
            // remaining <= 0 or force → full remove
        }
    }

    // Full remove path
    {
        auto* itemBytes = reinterpret_cast<std::uint8_t*>(item);
        std::int32_t typeHost =
            *reinterpret_cast<std::int32_t*>(itemBytes + 0xa8);
        std::int32_t objType =
            *reinterpret_cast<std::int32_t*>(typeHost + 0x38);

        if (objType != 4) {
            std::uint8_t originX = getOriginX(item);
            std::uint8_t originY = getOriginY(item);
            std::int32_t blob =
                *reinterpret_cast<std::int32_t*>(typeHost + 0x3c);
            std::uint8_t sizeX =
                *reinterpret_cast<std::uint8_t*>(blob + 0x406);
            std::uint8_t sizeY =
                *reinterpret_cast<std::uint8_t*>(blob + 0x407);

            std::int32_t height =
                *reinterpret_cast<std::int32_t*>(grid + kOffHeight);
            std::int32_t cellCount =
                *reinterpret_cast<std::int32_t*>(grid + kOffCellCount);
            auto* cells =
                *reinterpret_cast<std::int32_t**>(grid + kOffCellArray);

            if (sizeX != 0) {
                for (int dx = 0; dx < static_cast<int>(sizeX); ++dx) {
                    if (sizeY != 0) {
                        for (int dy = 0; dy < static_cast<int>(sizeY); ++dy) {
                            int idx =
                                height * (static_cast<int>(originX) + dx) +
                                (static_cast<int>(originY) + dy);
                            if (idx >= 0 && idx < cellCount) {
                                cells[idx * 2]     = -1;
                                cells[idx * 2 + 1] = -1;
                            }
                        }
                    }
                }
            }
        }

        FUN_005085b0(grid + kOffListSub, item);
        setQty(item, savedQtyOrOne);
        unbind(item, 0);
        result = item;
    }

dirty_out:
    void* owner = *reinterpret_cast<void**>(grid + kOffOwner);
    if (owner != nullptr) {
        FUN_00512670(owner);
    }
    *reinterpret_cast<std::uint8_t*>(grid + kOffDirty) = 1;
    return result;
}

// Ghidra name alias
extern "C" ItemObject* __thiscall FUN_00571b80(InventoryGrid* self,
                                               ItemObject* item,
                                               int removeQty,
                                               char forceFullRemove)
{
    return InventoryGrid_RemoveItem(self, item, removeQty, forceFullRemove);
}
