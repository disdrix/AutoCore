// =============================================================================
// Named_CalleeOf_Client_UI_InventoryDropToGrid_00513770 (legacy parent-seed name)
// -----------------------------------------------------------------------------
// Stable ID: aa_00513770
// Address:   0x00513770
// Canonical: Item_IsWantedByStore_Inferred
// See:       reconstructed-exact/Item_IsWantedByStore_Inferred.cpp
// Dual A/B:  2026-07-29 OWN-ONLY
// =============================================================================

// Parent-seed alias only. Body is the store-want predicate used by DropToGrid
// type-4 path (toast "The store does not want that item." on false).

int __thiscall FUN_004f1e20(void* clonebase, char param_2, char param_3);

unsigned char /* bool AL */ __thiscall
Named_CalleeOf_Client_UI_InventoryDropToGrid_00513770(void* item)
{
  void* clonebase;
  void* def;

  clonebase = *(void**)((char*)item + 0xA8);

  if (*(void**)((char*)clonebase + 0x3C) == 0) {
    FUN_004f1e20(clonebase, 0, 1);
  }

  def = *(void**)((char*)(*(void**)((char*)item + 0xA8)) + 0x3C);
  if (def == 0) {
    return 1;
  }

  return (*(int*)((char*)def + 0x3B4) == 1) ? 1 : 0;
}
