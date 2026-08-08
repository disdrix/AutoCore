// =============================================================================
// InventoryGrid_SetDirtyFlag_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005706d0
// Address:   0x005706d0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Ghidra:    FUN_005706d0
// Generated: 2026-08-04 WQ8R-J (reconfirm dual 2026-07-29)
// Exactness: Behavior-preserving; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Mark inventory grid dirty after mutating place/merge/refresh paths.
//   if (grid->owner) Object_PropagateDirtyBit0x20000(owner);
//   grid->dirty = 1;
//
// ABI: __thiscall (ECX = InventoryGrid*); no stack args; plain ret.
//
// REJECT: scaffold Named_CalleeOf_…_005706d0

#include <cstdint>

struct InventoryGrid;
// Object_PropagateDirtyBit0x20000 @ 0x00512670 — __fastcall/thiscall ECX=object
extern "C" void __fastcall Object_PropagateDirtyBit0x20000(void* obj);

void __thiscall InventoryGrid_SetDirtyFlag_Inferred(InventoryGrid* grid)
{
  auto* g = reinterpret_cast<uint8_t*>(grid);
  void* owner = *reinterpret_cast<void**>(g + 0x24);
  if (owner != nullptr) {
    Object_PropagateDirtyBit0x20000(owner);
  }
  *(g + 0x21) = 1;
}
