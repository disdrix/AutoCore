// =============================================================================
// FUN_00570f50  (Ghidra scaffold twin of named clean)
// -----------------------------------------------------------------------------
// Stable ID: aa_00570f50
// Address:   0x00570f50 – 0x00570f62  (19 B / 0x13)
// Named:     InventoryGrid_RemoveAllAndReEmptyCells_Inferred
// System:    inventory-transfer
// Wave:      R10-013 OWN-ONLY dual (2026-08-05)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Assembly seals LEA ECX,[this+0x2c] before List_RemoveAll.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Thin re-empty of InventoryGrid — List_RemoveAll(grid+0x2c) then
//          InventoryGrid_AllocateCellArray_Inferred(grid) via tail-JMP.
// Twin:    FUN_00570f70 does full item walk/detach before RemoveAll+Allocate.

void __fastcall List_RemoveAll(void* list);                                 // 0x004bc580
void __fastcall InventoryGrid_AllocateCellArray_Inferred(void* grid);       // 0x00570720

void __fastcall FUN_00570f50(void* param_1 /* InventoryGrid* this / ECX */)
{
  // Decompiler drops list this; assembly: LEA ECX,[ESI+0x2c]
  List_RemoveAll((void*)((char*)param_1 + 0x2c));
  InventoryGrid_AllocateCellArray_Inferred(param_1);
  return;
}
