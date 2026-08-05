// =============================================================================
// InventoryGrid_MergeStackQty
// -----------------------------------------------------------------------------
// Stable ID: aa_00571830
// Address:   0x00571830  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-29 dual A/B seal (supersedes scaffold FUN_00571830.cpp)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Merge qtyDelta onto the existing stack whose instance COID matches
//   (coidLo, coidHi) inside this InventoryGrid. Does not place, stamp cells,
//   or clamp max stack.
//
// ABI (byte-sealed):
//   __thiscall  ECX = InventoryGrid*
//   stack: qtyDelta, coidLo, coidHi
//   ret 0x0C
//   return AL: 1 = merged, 0 = COID not found
//
// SEALED formulas:
//   item = FindItemByCoid(this, coidLo, coidHi)
//   if !item: debug(0,"VOG_DEBUG_STOP"); return 0
//   SetQty(GetQty(item) + qtyDelta)
//   MarkDirty_0x20000(item)
//   if (owner = *(this+0x24)) MarkDirty_0x20000(owner)
//   *(u8*)(this+0x21) = 1
//   return 1
//
// Dual: reviews/A_aa_00571830_InventoryGrid_MergeStackQty.md
//       reviews/B_aa_00571830_InventoryGrid_MergeStackQty.md
// Residual: reviews/a_00571830.md
// =============================================================================

#include <cstdint>

// Forward decls (leave FUN_* where product name open)
struct InventoryGrid;
struct InventoryItem; // CVOG object with vtbl qty + dirty fields

extern "C" InventoryItem* __thiscall InventoryGrid_FindItemByCoid(
    InventoryGrid* self, int coidLo, int coidHi); // 0x00571010

extern "C" void __fastcall FUN_00512670(void* obj); // mark *(obj+0x17C) |= 0x20000
extern "C" void FUN_007a4480(char enable, const char* fmt, ...);

// Item vtbl slots (sealed roles across inventory duals)
//   +0x25C GetQty() -> int
//   +0x260 SetQty(int)

using GetQty_t = int(__thiscall*)(InventoryItem* self);
using SetQty_t = void(__thiscall*)(InventoryItem* self, int qty);

std::uint8_t __thiscall InventoryGrid_MergeStackQty(
    InventoryGrid* self,
    int qtyDelta,
    int coidLo,
    int coidHi)
{
    InventoryItem* item =
        InventoryGrid_FindItemByCoid(self, coidLo, coidHi);
    if (item == nullptr) {
        // enable=0 → FUN_007a4480 never logs (body requires enable==1)
        FUN_007a4480(0, "VOG_DEBUG_STOP");
        return 0;
    }

    void** vtbl = *reinterpret_cast<void***>(item);
    auto getQty = reinterpret_cast<GetQty_t>(vtbl[0x25C / 4]);
    auto setQty = reinterpret_cast<SetQty_t>(vtbl[0x260 / 4]);

    int cur = getQty(item);
    setQty(item, cur + qtyDelta);

    FUN_00512670(item);

    // grid+0x24 = owner object pointer (CreateCargo binds via vfunc +0x18)
    void* owner = *reinterpret_cast<void**>(
        reinterpret_cast<char*>(self) + 0x24);
    if (owner != nullptr) {
        FUN_00512670(owner);
    }

    *reinterpret_cast<std::uint8_t*>(
        reinterpret_cast<char*>(self) + 0x21) = 1;
    return 1;
}
