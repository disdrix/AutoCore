// =============================================================================
// FUN_00571d80  →  InventoryGrid_RemoveItemByCoid
// -----------------------------------------------------------------------------
// Stable ID: aa_00571d80
// Address:   0x00571d80  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-23 scaffold; refined 2026-08-04 WQ8R-D
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Preferred clean: InventoryGrid_RemoveItemByCoid.cpp
// =============================================================================

#include <cstdint>

// thiscall; ret 0x0C — returns ItemObject* (EAX from RemoveItem)
void* FUN_00571d80(uint32_t coidLo, uint32_t coidHi, uint32_t forceFull /* ECX=grid */)
{
    // See InventoryGrid_RemoveItemByCoid.cpp for named body.
    // Body: FindItemByCoid(coidLo,coidHi) then RemoveItem(item, 1, forceFull).
    (void)coidLo; (void)coidHi; (void)forceFull;
    return nullptr; // scaffold stub — use named clean
}
