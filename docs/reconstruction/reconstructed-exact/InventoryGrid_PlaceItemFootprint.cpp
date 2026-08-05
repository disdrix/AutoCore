// =============================================================================
// InventoryGrid_PlaceItemFootprint
// -----------------------------------------------------------------------------
// Purpose:  Place an item into the inventory grid at (originX, originY): reject
//           disallowed object types, special-case type 4, CanPlace-check the
//           InvSizeX×InvSizeY footprint, bind item to grid, then stamp the item
//           COID into EVERY cell of the footprint rectangle.
//
// Address:  0x00571620  (autoassault.exe, image base 0x400000)
// Stable:   aa_00571620
// System:   inventory-transfer
//
// Convention: MSVC __thiscall  (grid in ECX); callee RET 0x10 (4 stack args)
// Decompiler label: FUN_00571620
//
// Signature (thiscall + stack) — sealed 2026-07-29 from full asm:
//   uint32_t InventoryGrid_PlaceItemFootprint(
//       InventoryGrid* this,
//       ItemObject*    item,
//       uint32_t       originX,
//       uint32_t       originY,
//       uint32_t       quantity);   // → item vfunc +0x260
//
// Stamp index (asm @ 0x005717b0; matches CanPlace/FindFree):
//   index = *(grid+0x0c) * (originX + dx) + (originY + dy)
//   for dx in [0, sizeX), dy in [0, sizeY)
//   cells[index].lo/hi = item+0x160 / +0x164
//
// Decompiler raw incorrectly used unaff_SI / height*(sizeY+row)+… — do not port.
//
// Footprint sizes: clonebase blob +0x406 / +0x407 = InvSizeX / InvSizeY.
// Grid type==4 forces minimum 2×2 when size is zero.
//
// Reject object types (type id at *(item+0xa8)+0x38):
//   0x12, 0x14, 0x16, 0x36, 0x38, 0x3a
// Type 4: FUN_00566f00(grid+0x2c, item) + vfunc+0x158(grid+0x24) — no stamp.
//
// Related: docs/inventory-cargo-wire-re.md, docs/inventory-grid-footprint.md
//          reviews/a_00571620.md (dual residual seal)
// Exactness: Asm-sealed stamp + ABI; runtime/diff still open.
// =============================================================================

#include <cstdint>

static constexpr std::uintptr_t kOffGridType  = 0x04;
static constexpr std::uintptr_t kOffHeight    = 0x0c;
static constexpr std::uintptr_t kOffOwnerOrId = 0x24;
static constexpr std::uintptr_t kOffCellArray = 0x28;
static constexpr std::uintptr_t kOffListSub   = 0x2c; // FUN_00566f00 this

// Item: +0xa8 type host; blob +0x406/+0x407 InvSizeX/Y;
//        +0x160/+0x164 COID lo/hi; +0x17c flags (bit6 gfx; |0x10 after place)

// CanPlace: thiscall; last arg conflictOut nullable (place passes 0).
char FUN_00570840(void* grid, std::uint32_t sizeX, std::uint32_t sizeY,
                  std::uint32_t originX, std::uint32_t originY,
                  std::uint32_t* conflictOut);
// List subobject op: thiscall on grid+0x2c, item on stack.
void FUN_00566f00(void* listSub, void* item);
void FUN_00512670(void* item);
void FUN_005706d0(void* grid);

struct InventoryGrid;
struct ItemObject;

/// Stamp item COID into every footprint cell at (originX, originY).
/// @param quantity  Stack count written via item vfunc +0x260.
/// @return 1 on success, 0 on reject / CanPlace fail.
std::uint32_t InventoryGrid_PlaceItemFootprint(InventoryGrid* self,
                                               ItemObject* item,
                                               std::uint32_t originX,
                                               std::uint32_t originY,
                                               std::uint32_t quantity)
{
    auto* const grid  = reinterpret_cast<std::uint8_t*>(self);
    auto* const pItem = reinterpret_cast<std::int32_t*>(item);
    auto* const vt    = *reinterpret_cast<void***>(pItem);

    // Type host at item+0xa8 (dword index 0x2a in decompiler).
    std::int32_t typeHost = pItem[0x2a];
    std::int32_t objType  = *reinterpret_cast<std::int32_t*>(typeHost + 0x38);

    if (objType == 0x12 || objType == 0x14 || objType == 0x16 ||
        objType == 0x36 || objType == 0x38 || objType == 0x3a) {
        return 0;
    }

    // Type 4: special bind path, no multi-cell stamp.
    if (objType == 4) {
        FUN_00566f00(grid + kOffListSub, item);
        using BindFn = void(__thiscall*)(void*, std::uint32_t);
        reinterpret_cast<BindFn>(
            *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(vt) + 0x158))(
            item, *reinterpret_cast<std::uint32_t*>(grid + kOffOwnerOrId));
        return 1;
    }

    // InvSizeX / InvSizeY from clonebase runtime blob.
    std::int32_t blob = *reinterpret_cast<std::int32_t*>(typeHost + 0x3c);
    std::uint32_t sizeX =
        static_cast<std::uint32_t>(*reinterpret_cast<std::uint8_t*>(blob + 0x406));
    std::uint32_t sizeY =
        static_cast<std::uint32_t>(*reinterpret_cast<std::uint8_t*>(blob + 0x407));

    // Grid type 4: force minimum 2×2 when zero-sized.
    if (*reinterpret_cast<std::int32_t*>(grid + kOffGridType) == 4) {
        if (static_cast<std::int32_t>(sizeX) <= 0) {
            sizeX = 2;
        }
        if (static_cast<std::int32_t>(sizeY) <= 0) {
            sizeY = 2;
        }
    }

    if (FUN_00570840(self, sizeX, sizeY, originX, originY, nullptr) == '\0') {
        return 0;
    }

    // Bind item (no arg on this path) → set pos → mark flag
    {
        using BindFn = void(__thiscall*)(void*);
        // Type-4 pushed grid+0x24; normal path also pushes it before call in asm
        // (PUSH EAX from [EDI+0x24]) — keep one-arg form matching asm.
        using Bind1Fn = void(__thiscall*)(void*, std::uint32_t);
        reinterpret_cast<Bind1Fn>(
            *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(vt) + 0x158))(
            item, *reinterpret_cast<std::uint32_t*>(grid + kOffOwnerOrId));
    }
    {
        using SetPosFn = void(__thiscall*)(void*, std::uint32_t, std::uint32_t);
        reinterpret_cast<SetPosFn>(
            *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(vt) + 0x24c))(
            item, originX, originY);
    }
    {
        using SetFlagFn = void(__thiscall*)(void*, std::int32_t);
        reinterpret_cast<SetFlagFn>(
            *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(vt) + 0x40))(
            item, 1);
    }

    // Optional graphics when item flags bit 6 set (item+0x17c).
    if (((static_cast<std::uint32_t>(pItem[0x5f]) >> 6) & 1u) != 0) {
        using GetGfxFn = std::int32_t(__thiscall*)(void*);
        std::int32_t gfx = reinterpret_cast<GetGfxFn>(
            *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(vt) + 0x1cc))(item);

        std::int32_t nested =
            *reinterpret_cast<std::int32_t*>(
                *reinterpret_cast<std::int32_t*>(
                    *reinterpret_cast<std::int32_t*>(gfx + 4) + 4) + 4 + gfx);

        if (*reinterpret_cast<std::int32_t*>(gfx + 8) != 0) {
            using SetScaleFn = void(__thiscall*)(void*, std::uint32_t);
            reinterpret_cast<SetScaleFn>(
                *reinterpret_cast<void**>(nested + 0xb8))(
                reinterpret_cast<void*>(nested), 0x3f800000u); // 1.0f
        }
        {
            using FxFn = void(__thiscall*)(void*);
            reinterpret_cast<FxFn>(
                *reinterpret_cast<void**>(nested + 0xfc))(
                reinterpret_cast<void*>(nested));
        }
    }

    // Set stack quantity (vfunc +0x260).
    {
        using SetQtyFn = void(__thiscall*)(void*, std::uint32_t);
        reinterpret_cast<SetQtyFn>(
            *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(vt) + 0x260))(
            item, quantity);
    }

    // Stamp COID into each footprint cell — asm-sealed formula.
    if (sizeX != 0) {
        const std::int32_t height =
            *reinterpret_cast<std::int32_t*>(grid + kOffHeight);
        auto* cells =
            *reinterpret_cast<std::int32_t**>(grid + kOffCellArray);
        const std::int32_t coidLo = pItem[0x58]; // item+0x160
        const std::int32_t coidHi = pItem[0x59]; // item+0x164

        for (std::uint32_t dx = 0; dx < sizeX; ++dx) {
            if (sizeY == 0) {
                continue;
            }
            for (std::uint32_t dy = 0; dy < sizeY; ++dy) {
                const std::int32_t cellIndex =
                    height * static_cast<std::int32_t>(originX + dx)
                    + static_cast<std::int32_t>(originY + dy);
                cells[cellIndex * 2 + 0] = coidLo;
                cells[cellIndex * 2 + 1] = coidHi;
            }
        }
    }

    FUN_00566f00(grid + kOffListSub, item);
    pItem[0x5f] = pItem[0x5f] | 0x10; // placed-in-grid flag (item+0x17c)
    FUN_00512670(item);
    FUN_005706d0(self);
    return 1;
}
