// =============================================================================
// InventoryGrid_CanPlaceItem
// -----------------------------------------------------------------------------
// Purpose:  Thin InvSize-aware wrapper around InventoryGrid_CanPlace.
//           Null item → 0. Else load InvSizeX/Y from item clonebase blob
//           (+0x406/+0x407) and forward to CanPlace with caller origin +
//           optional conflictOut. Does NOT stamp, clear, or mutate cells.
//
// Address:  0x005715d0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005715d0
// System:   inventory-transfer
// Ghidra:   FUN_005715d0
//
// Convention: MSVC __thiscall (grid in ECX); four stack args; RET 0x10
//             (epilogue bytes: C2 10 00). Body 0x005715d0–0x0057161d.
//
// Signature (byte-sealed 2026-08-04):
//   uint32_t InventoryGrid_CanPlaceItem(
//       InventoryGrid* this,        // ECX (saved, restored into CanPlace this)
//       ItemObject*    item,        // stack0 — null-checked
//       uint32_t       originX,     // stack1
//       uint32_t       originY,     // stack2
//       uint32_t*      conflictOut  // stack3 — nullable; passed through
//   );
//   // returns CanPlace result (1 fit / 0 reject)
//
// Clonebase path: item+0xa8 → type host; host+0x3c → blob; blob+0x406/407 sizes.
//
// Callers (Ghidra xrefs, sample): FUN_008012f0, Client_ConfirmEquipOrCustomizeItem
//   (0x00941b20), FUN_00952bc0, FUN_00955010 — equip / place-probe paths.
//   Typical conflictOut = 0 (any occupancy rejects).
//
// Related: InventoryGrid_CanPlace (0x00570840), FindFreeForItem (0x005714e0),
//          PlaceItemFootprint (0x00571620), MoveItemFootprint (0x00570af0).
// Dual: reviews/A|B_aa_005715d0_InventoryGrid_CanPlaceItem.md
// Exactness: Leaf wrapper; decompile ≡ bytes for CF; ABI sealed via RET 0x10.
// =============================================================================

#include <cstdint>

struct InventoryGrid;
struct ItemObject;

// 0x00570840
char __thiscall InventoryGrid_CanPlace(InventoryGrid* self,
                                       std::uint32_t sizeX,
                                       std::uint32_t sizeY,
                                       std::uint32_t originX,
                                       std::uint32_t originY,
                                       std::uint32_t* conflictOut);

/// Probe whether item's InvSize footprint fits at (originX, originY).
/// @return 1 if CanPlace accepts, 0 if item null or CanPlace rejects.
std::uint32_t __thiscall InventoryGrid_CanPlaceItem(InventoryGrid* self,
                                                    ItemObject* item,
                                                    std::uint32_t originX,
                                                    std::uint32_t originY,
                                                    std::uint32_t* conflictOut)
{
    if (item == nullptr) {
        return 0;
    }

    // item+0xa8 type host; +0x3c clonebase blob
    auto* const typeHost =
        *reinterpret_cast<std::uint8_t**>(reinterpret_cast<std::uint8_t*>(item) +
                                          0xa8);
    auto* const blob = *reinterpret_cast<std::uint8_t**>(typeHost + 0x3c);
    const std::uint32_t sizeX =
        static_cast<std::uint32_t>(*reinterpret_cast<std::uint8_t*>(blob + 0x406));
    const std::uint32_t sizeY =
        static_cast<std::uint32_t>(*reinterpret_cast<std::uint8_t*>(blob + 0x407));

    return static_cast<std::uint32_t>(static_cast<std::uint8_t>(
        InventoryGrid_CanPlace(self, sizeX, sizeY, originX, originY, conflictOut)));
}
