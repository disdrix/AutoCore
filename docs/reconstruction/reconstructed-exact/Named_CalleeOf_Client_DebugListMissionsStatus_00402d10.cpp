// =============================================================================
// RETIRED scaffold — Named_CalleeOf_Client_DebugListMissionsStatus_00402d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00402d10
// Address:   0x00402d10
// Status:    RETIRED 2026-08-05 by MEGA-126 dual A/B
//
// Parent-seed name was misleading: this unit is a **shared** MSVC std::list
// push_back helper (7 call sites / 3 parents), not mission-debug exclusive.
//
// Canonical clean:
//   docs/reconstruction/reconstructed-exact/StdList_PushBack_Dword_Inferred.cpp
// Scaffold twin:
//   docs/reconstruction/reconstructed-exact/FUN_00402d10.cpp
// =============================================================================

#include <cstdint>

// Forward to sealed name (behavior-preserving).
void __thiscall StdList_PushBack_Dword_Inferred(void* list, const std::uint32_t* pValue);

void __thiscall Named_CalleeOf_Client_DebugListMissionsStatus_00402d10(
    void* list, const std::uint32_t* pValue)
{
  StdList_PushBack_Dword_Inferred(list, pValue);
}
