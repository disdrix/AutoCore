// =============================================================================
// FUN_00571e10  (scaffold twin of InventoryGrid_CommitPlacementMap_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00571e10
// Address:   0x00571e10 – 0x00571fae
// System:    inventory-transfer
// Dual:      2026-07-29 W22-C — see InventoryGrid_CommitPlacementMap_Inferred.cpp
// =============================================================================

#include <cstdint>

struct InventoryGrid;
struct ItemObject;

extern "C" ItemObject* InventoryGrid_RemoveItem(
    InventoryGrid* thisGrid, ItemObject* item, int removeQty, char forceFull);
extern "C" void FUN_005731c0(void* mapShell, void* nodeRight);
extern "C" void operator_delete(void* p);
extern "C" void InventoryGrid_CommitPlacementMap_Inferred(
    InventoryGrid* self, InventoryGrid* related, char doRemoveFromRelated);

extern "C" void FUN_00571e10(InventoryGrid* param_1, InventoryGrid* param_2, char param_3)
{
  InventoryGrid_CommitPlacementMap_Inferred(param_1, param_2, param_3);
}
