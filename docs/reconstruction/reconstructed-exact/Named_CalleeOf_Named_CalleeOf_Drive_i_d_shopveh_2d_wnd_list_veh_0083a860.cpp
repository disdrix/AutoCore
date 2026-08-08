// =============================================================================
// RETIRED scaffold — Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0083a860
// -----------------------------------------------------------------------------
// Stable ID: aa_0083a860
// Address:   0x0083a860
// Wave:      WQ9L-I OWN-ONLY dual 2026-08-05
// Note:      Scaffold name was xref-depth chain only. Authority is the named
//            clean with sealed EAX=host / EBX=list_i / AL=bool ABI.
// Authority: ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred.cpp
// Twin:      FUN_0083a860.cpp
// =============================================================================

#include <cstdint>

extern "C" std::uint8_t ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred(
    void *host, int list_i);

// Retired alias — portable form only (register ABI not expressible as C formals).
extern "C" std::uint8_t Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0083a860(
    void *host, int list_i)
{
  return ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred(host, list_i);
}
