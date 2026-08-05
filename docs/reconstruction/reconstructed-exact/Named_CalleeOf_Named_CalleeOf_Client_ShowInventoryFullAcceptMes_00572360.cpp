// =============================================================================
// SUPERSEDED ALIAS — aa_00572360
// -----------------------------------------------------------------------------
// Seed name from ShowInventoryFullAcceptMessage parent scan. Prefer:
//   InventoryGrid_RePlaceItems_Inferred
//   FUN_00572360
// Sealed 2026-07-29 W21-B. Primary callers: SortAndRepack, cargo resize, wrapper.
// =============================================================================

// This alias file intentionally does not duplicate the full body.
// See: reconstructed-exact/InventoryGrid_RePlaceItems_Inferred.cpp
//      reconstructed-exact/FUN_00572360.cpp

#include <cstdint>

extern uint32_t __thiscall FUN_00572360(void *thisGrid, uint32_t relatedPtr, char flag);

uint32_t __thiscall Named_CalleeOf_Named_CalleeOf_Client_ShowInventoryFullAcceptMes_00572360(
    void *param_1, uint32_t param_2, char param_3)
{
  return FUN_00572360(param_1, param_2, param_3);
}
