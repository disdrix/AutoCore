// =============================================================================
// RETIRED scaffold — Named_CalleeOf_Named_gfxUIWindow_00988710
// -----------------------------------------------------------------------------
// Stable ID: aa_00988710
// Address:   0x00988710
// Retired:   2026-08-05 MEGA-123 OWN-ONLY dual
// Replacement:
//   docs/reconstruction/reconstructed-exact/UiOwnedBlock_CompleteBeforeDelete_Inferred.cpp
//   docs/reconstruction/reconstructed-exact/FUN_00988710.cpp
//
// Do not use this scaffold name in new work. Parent seed rename only;
// meaningful name is UiOwnedBlock_CompleteBeforeDelete_Inferred.
// =============================================================================

#include <cstdint>

struct UiOwnedBlock_Inferred {
  void* head;
  std::uint32_t size;
  void* iface;
};

extern "C" void __fastcall UiOwnedBlock_CompleteBeforeDelete_Inferred(UiOwnedBlock_Inferred* self);

// Retired alias — forwards to sealed name.
extern "C" void __fastcall Named_CalleeOf_Named_gfxUIWindow_00988710(UiOwnedBlock_Inferred* self)
{
  UiOwnedBlock_CompleteBeforeDelete_Inferred(self);
}
