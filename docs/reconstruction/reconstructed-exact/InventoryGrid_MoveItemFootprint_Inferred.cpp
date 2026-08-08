// =============================================================================
// InventoryGrid_MoveItemFootprint_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Relocate an already-bound item on an inventory grid from its current
//           footprint origin (vtbl +0x250 / +0x254) to (originX, originY):
//             1) CanPlace(InvSizeX, InvSizeY, originX, originY, conflictOut)
//                — non-null conflictOut so same-COID cells (old footprint) are
//                  tolerated during the probe (overlap-safe move).
//             2) Clear old footprint cells to empty (-1,-1).
//             3) item.vtbl+0x24c(originX, originY) — set grid origin.
//             4) Stamp item COID (item+0x160/+0x164) into every new cell.
//             5) Optional FUN_00512670(*(grid+0x24)); dirty flag grid+0x21 = 1.
//
// Address:  0x00570af0  (autoassault.exe, image base 0x400000)
// Stable:   aa_00570af0
// System:   inventory-transfer
// Ghidra:   FUN_00570af0
//
// Convention: MSVC __thiscall (grid in ECX); three stack args; RET 0x0C
//             (epilogue bytes: C2 0C 00). Body 0x00570af0–0x00570cfb.
//
// Signature (byte-sealed 2026-08-04):
//   uint32_t InventoryGrid_MoveItemFootprint_Inferred(
//       InventoryGrid* this,   // ECX
//       ItemObject*    item,   // stack0
//       uint32_t       originX,// stack1
//       uint32_t       originY // stack2
//   );
//   // returns 1 success / 0 null-item or CanPlace fail
//
// Index family (same as CanPlace / Place / Remove / FindFree):
//   index = *(grid+0x0c) * x + y
//   clear:  x in [curX, curX+sizeX), y in [curY, curY+sizeY)
//   stamp:  x = originX+dx, y = originY+dy; dx∈[0,sizeX), dy∈[0,sizeY)
//
// InvSize: clonebase blob +0x406 / +0x407 (u8).
// Cell: 8-byte COID pair at *(grid+0x28) + index*8; empty = 0xFFFFFFFF halves.
//
// Decompiler corruption (do NOT port):
//   - stamp uses unaff_retaddr / (byte)param_2 — bytes show originX+dx / originY+dy
//   - CanPlace first size arg CONCAT31 artifact — bytes load u8 +0x406
//
// Ghidra xrefs: none found (orphan / indirect-only residual). Body still sealed.
// Related: InventoryGrid_CanPlace (0x00570840), PlaceItemFootprint (0x00571620),
//          RemoveItem (0x00571b80), CanPlaceItem (0x005715d0).
// Dual: reviews/A|B_aa_00570af0_InventoryGrid_MoveItemFootprint_Inferred.md
// Exactness: CF + stamp/clear index + ABI sealed via decompile+read_memory.
//           Runtime / bit-exact / product English open.
// =============================================================================

#include <cstdint>

struct InventoryGrid;
struct ItemObject;

// 0x00570840 — full-rect occupancy / bounds / page gate
char __thiscall InventoryGrid_CanPlace(InventoryGrid* self,
                                       std::uint32_t sizeX,
                                       std::uint32_t sizeY,
                                       std::uint32_t originX,
                                       std::uint32_t originY,
                                       std::uint32_t* conflictOut /* nullable; 2 dwords */);

// 0x00512670 — owner/item side helper (this = *(grid+0x24) when non-null)
void __thiscall FUN_00512670(void* ownerOrItem);

/// Move item footprint from current origin to (originX, originY).
/// @return 1 on success, 0 on null item or CanPlace reject.
std::uint32_t __thiscall InventoryGrid_MoveItemFootprint_Inferred(
    InventoryGrid* self,
    ItemObject* item,
    std::uint32_t originX,
    std::uint32_t originY)
{
    auto* const grid = reinterpret_cast<std::uint8_t*>(self);
    auto* const pItem = reinterpret_cast<std::int32_t*>(item);

    if (item == nullptr) {
        return 0;
    }

    // type host @ item+0xa8 (dword index 0x2a); clonebase blob @ host+0x3c
    auto* const typeHost = reinterpret_cast<std::uint8_t*>(pItem[0x2a]);
    auto* const blob = *reinterpret_cast<std::uint8_t**>(typeHost + 0x3c);
    const std::uint32_t sizeX =
        static_cast<std::uint32_t>(*reinterpret_cast<std::uint8_t*>(blob + 0x406));
    const std::uint32_t sizeY =
        static_cast<std::uint32_t>(*reinterpret_cast<std::uint8_t*>(blob + 0x407));

    // Local conflictOut: allows same-COID occupancy (old footprint) during probe.
    std::uint32_t conflictOut[2];
    if (InventoryGrid_CanPlace(self, sizeX, sizeY, originX, originY, conflictOut) ==
        '\0') {
        return 0;
    }

    auto* const vt = *reinterpret_cast<void***>(pItem);
    using GetCoordFn = std::uint32_t(__thiscall*)(ItemObject*);
    using SetPosFn = void(__thiscall*)(ItemObject*, std::uint32_t, std::uint32_t);

    // --- clear old footprint at current (vtbl+0x250 / +0x254) ---
    auto getX = reinterpret_cast<GetCoordFn>(
        *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(vt) + 0x250));
    auto getY = reinterpret_cast<GetCoordFn>(
        *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(vt) + 0x254));

    const std::uint32_t height =
        *reinterpret_cast<std::uint32_t*>(grid + 0x0c);
    auto* const cells =
        *reinterpret_cast<std::uint8_t**>(grid + 0x28);

    std::uint32_t curX = getX(item) & 0xff;
    const std::uint32_t endX = (getX(item) & 0xff) + sizeX;
    if (curX < endX) {
        do {
            std::uint32_t curY = getY(item) & 0xff;
            const std::uint32_t endY = (getY(item) & 0xff) + sizeY;
            if (curY < endY) {
                do {
                    const std::uint32_t index = height * curX + curY;
                    *reinterpret_cast<std::uint32_t*>(cells + index * 8) = 0xFFFFFFFFu;
                    *reinterpret_cast<std::uint32_t*>(cells + index * 8 + 4) =
                        0xFFFFFFFFu;
                    ++curY;
                } while (static_cast<std::int32_t>(curY) <
                         static_cast<std::int32_t>((getY(item) & 0xff) + sizeY));
            }
            ++curX;
        } while (static_cast<std::int32_t>(curX) <
                 static_cast<std::int32_t>((getX(item) & 0xff) + sizeX));
    }

    // --- set new origin ---
    auto setPos = reinterpret_cast<SetPosFn>(
        *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(vt) + 0x24c));
    setPos(item, originX, originY);

    // --- stamp new footprint (byte-sealed index) ---
    // sizeX / sizeY re-read from blob (matches body); skip if sizeX==0
    const std::uint32_t stampSX =
        static_cast<std::uint32_t>(*reinterpret_cast<std::uint8_t*>(blob + 0x406));
    const std::uint32_t stampSY =
        static_cast<std::uint32_t>(*reinterpret_cast<std::uint8_t*>(blob + 0x407));
    const std::int32_t coidLo = pItem[0x58]; // item+0x160
    const std::int32_t coidHi = pItem[0x59]; // item+0x164

    if (stampSX != 0) {
        for (std::uint32_t dx = 0; dx < stampSX; ++dx) {
            if (stampSY != 0) {
                for (std::uint32_t dy = 0; dy < stampSY; ++dy) {
                    // BYTES: height * (originX + dx) + (originY + dy)
                    // (decompiler unaff_retaddr / (byte)param_2 is WRONG)
                    const std::uint32_t index =
                        height * (originX + dx) + (originY + dy);
                    *reinterpret_cast<std::int32_t*>(cells + index * 8) = coidLo;
                    *reinterpret_cast<std::int32_t*>(cells + index * 8 + 4) = coidHi;
                }
            }
        }
    }

    // Optional owner helper + dirty
    auto* const owner = *reinterpret_cast<void**>(grid + 0x24);
    if (owner != nullptr) {
        FUN_00512670(owner);
    }
    *reinterpret_cast<std::uint8_t*>(grid + 0x21) = 1;
    return 1;
}
