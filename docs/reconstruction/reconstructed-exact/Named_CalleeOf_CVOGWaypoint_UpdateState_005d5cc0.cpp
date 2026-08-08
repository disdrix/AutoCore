// =============================================================================
// RETIRED scaffold — Named_CalleeOf_CVOGWaypoint_UpdateState_005d5cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d5cc0
// Address:   0x005d5cc0
// Retired:   2026-08-05 MEGA-057
// =============================================================================
//
// This parent-seed scaffold name is retired. Use the product-plate name:
//
//   CVOGWaypoint_DoFollowObjectShortcutsUpdate
//   docs/reconstruction/reconstructed-exact/CVOGWaypoint_DoFollowObjectShortcutsUpdate.cpp
//
// Evidence: plate string "CVOGWaypoint::DoFollowObjectShortcutsUpdate" @ 0x009dace4.
// Sole caller remains CVOGWaypoint_UpdateState (state case 2).
//
// Do not reintroduce Named_CalleeOf_* for this VA.

void __fastcall Named_CalleeOf_CVOGWaypoint_UpdateState_005d5cc0(void *this_wp)
{
  extern void __fastcall CVOGWaypoint_DoFollowObjectShortcutsUpdate(void *);
  CVOGWaypoint_DoFollowObjectShortcutsUpdate(this_wp);
}
