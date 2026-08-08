// =============================================================================
// RETIRED SCAFFOLD ALIAS — do not use for ports
// -----------------------------------------------------------------------------
// Stable ID: aa_00418700
// Address:   0x00418700
// Retired:   2026-08-05 MEGA-081
// Reason:    Parent-seed Named_CalleeOf_* name; unit is shared list _Buynode
//            with 61 CALL xrefs across domains (not DebugListMissionsStatus-only).
// Canonical: StdList_BuyNode_Dword_Seh  (see StdList_BuyNode_Dword_Seh.cpp)
// Ghidra:    FUN_00418700
// =============================================================================

#include <cstdint>

// Forward to canonical implementation name for any stale includes.
void *Named_CalleeOf_Client_DebugListMissionsStatus_00418700(
    void *link0, void *link1, uint32_t *pValue)
{
  // Identical CF to StdList_BuyNode_Dword_Seh — kept only as retired symbol stub.
  uint32_t *node = (uint32_t *)operator_new(0xC);
  if (node != nullptr) {
    node[0] = (uint32_t)(uintptr_t)link0;
    node[1] = (uint32_t)(uintptr_t)link1;
    node[2] = *pValue;
  }
  return node;
}
