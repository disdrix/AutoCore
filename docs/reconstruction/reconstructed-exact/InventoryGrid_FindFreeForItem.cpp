// =============================================================================
// InventoryGrid_FindFreeForItem
// -----------------------------------------------------------------------------
// Purpose:  Item-aware free-space / placement-origin probe on an inventory grid.
//           Type class 4 → success at (0,0). Optional stack-merge to an existing
//           peer's XY. Else tail-calls InventoryGrid_FindFreeSlot with clonebase
//           InvSize and passthrough pageIndex. Does NOT stamp cells.
//
// Address:  0x005714e0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005714e0
// System:   inventory-transfer
//
// Convention: MSVC __thiscall  (grid in ECX; saved to EBX for body)
//             five stack args; ret 0x14
//
// Signature:
//   uint32_t InventoryGrid_FindFreeForItem(
//       InventoryGrid* this,
//       Item*          item,
//       uint8_t*       outX,
//       uint8_t*       outY,
//       char           allowStackMerge,
//       char           pageIndex);
//
// Relation (SEALED): fallthrough is
//   mov ecx, ebx ; call InventoryGrid_FindFreeSlot(this, InvSizeX, InvSizeY,
//                                                  outX, outY, pageIndex)
//   InvSize from *(clonebase+0x406 / +0x407) where clonebase =
//     *(*(item + 0xa8) + 0x3c)
//
// Dual: reviews/A|B_aa_005714e0_InventoryGrid_FindFreeForItem.md
// Residual: reviews/a_005714e0.md
// Exactness: Behavior-preserving rewrite of decompiler CF + memory-sealed CC.
// =============================================================================

#include <cstdint>

struct InventoryGrid;
struct Item;

// 0x005713a0 — first-fit free rect (Y outer, X inner). See InventoryGrid_FindFreeSlot.cpp
std::uint32_t __thiscall InventoryGrid_FindFreeSlot(InventoryGrid* self,
                                                    std::uint32_t sizeX,
                                                    std::uint32_t sizeY,
                                                    std::uint8_t* outX,
                                                    std::uint8_t* outY,
                                                    char pageIndex);

// 0x00513e70 — __fastcall ECX=item; stack-eligible probe
std::uint32_t __fastcall FUN_00513e70(Item* item);

// 0x005710c0 — find peer on grid by CBID with room for qty
Item* __thiscall FUN_005710c0(InventoryGrid* self,
                              std::uint32_t cbid,
                              char /*mode*/,
                              std::uint16_t qty);

// 0x0040abf0 — capacity check: can peer accept additional qty?
std::uint32_t __thiscall FUN_0040abf0(Item* peer, std::uint16_t addQty);

/// Item-aware free origin search.
/// @return 1 on success (outX/outY written), 0 on failure.
std::uint32_t __thiscall InventoryGrid_FindFreeForItem(InventoryGrid* self,
                                                       Item* item,
                                                       std::uint8_t* outX,
                                                       std::uint8_t* outY,
                                                       char allowStackMerge,
                                                       char pageIndex)
{
    if (item == nullptr) {
        return 0;
    }

    // item+0xa8 → type/clonebase holder; +0x38 type class
    auto* const holder = *reinterpret_cast<std::uint8_t**>(
        reinterpret_cast<std::uint8_t*>(item) + 0xa8);
    if (*reinterpret_cast<std::int32_t*>(holder + 0x38) == 4) {
        *outX = 0;
        *outY = 0;
        return 1;
    }

    if (allowStackMerge != 0) {
        if (static_cast<char>(FUN_00513e70(item)) != 0) {
            const auto cbid =
                *reinterpret_cast<std::uint32_t*>(holder + 0x34);
            // vfunc +0x25c → quantity (decompiler call; thiscall on item)
            auto** const vitem = *reinterpret_cast<void***>(item);
            using QtyFn = std::uint32_t(__thiscall*)(Item*);
            const auto qty = reinterpret_cast<QtyFn>(vitem[0x25c / 4])(item);

            Item* peer = FUN_005710c0(self, cbid, 0,
                                      static_cast<std::uint16_t>(qty));
            if (peer != nullptr) {
                auto** const vpeer = *reinterpret_cast<void***>(peer);
                using ByteFn = std::uint8_t(__thiscall*)(Item*);
                if (static_cast<char>(FUN_0040abf0(
                        peer, static_cast<std::uint16_t>(qty))) != 0) {
                    *outX = reinterpret_cast<ByteFn>(vpeer[0x250 / 4])(peer);
                    *outY = reinterpret_cast<ByteFn>(vpeer[0x254 / 4])(peer);
                    return 1;
                }
            }
        }
    }

    // Fallthrough → FindFreeSlot (SEALED tail)
    auto* const clonebase =
        *reinterpret_cast<std::uint8_t**>(holder + 0x3c);
    const auto sizeX = static_cast<std::uint32_t>(clonebase[0x406]);
    const auto sizeY = static_cast<std::uint32_t>(clonebase[0x407]);
    return InventoryGrid_FindFreeSlot(self, sizeX, sizeY, outX, outY, pageIndex);
}
