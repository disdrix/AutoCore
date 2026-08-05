// =============================================================================
// Item_IsWantedByStore_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00513770
// Address:   0x00513770  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-29 dual A/B (from raw 2026-07-23 + live decompile/read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   Store/vendor pre-gate on an inventory Item*: ensure clonebase def is loaded,
//   then return true iff the def is still missing OR *(i32*)(def+0x3B4)==1.
//   Callers that see false toast "The store does not want that item."
//
// PRIOR NAMES: FUN_00513770, Named_CalleeOf_Client_UI_InventoryDropToGrid_00513770
//
// ABI (asm-sealed):
//   bool __thiscall (Item* this in ECX); no stack args; plain RET; result in AL.
//
// LAYOUT (cross-sealed with Item_CanAcceptStackQty):
//   this+0xA8     → clonebase*
//   clonebase+0x3C → def blob* (nullable)
//   def+0x3B4     → i32 store-want flag (must be 1)
//
// CALLEE:
//   FUN_004f1e20(clonebase, 0, 1)  — ensure def when null (thiscall on clonebase)
//
// DECOMPILER ARTIFACTS (do not port literally):
//   - CONCAT31 on return → bool AL only (setz / mov al,1)
//   - FUN_004f1e20(0,1) free call → missing ECX=clonebase thiscall
// =============================================================================

// Forward: ensure-load on clonebase when def pointer null (product name open).
int __thiscall FUN_004f1e20(void* clonebase, char param_2, char param_3);

// Item* this — inventory/held item instance (not bare clonebase).
unsigned char /* bool AL */ __thiscall Item_IsWantedByStore_Inferred(void* item)
{
  void* clonebase;
  void* def;

  clonebase = *(void**)((char*)item + 0xA8);

  if (*(void**)((char*)clonebase + 0x3C) == 0) {
    FUN_004f1e20(clonebase, /*param_2*/ 0, /*param_3*/ 1);
  }

  def = *(void**)((char*)(*(void**)((char*)item + 0xA8)) + 0x3C);
  if (def == 0) {
    return 1;
  }

  return (*(int*)((char*)def + 0x3B4) == 1) ? 1 : 0;
}
