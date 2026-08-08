// =============================================================================
// RETIRED scaffold — Named_CalleeOf_Named_VOG_DEBUG_STOP_006c7fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c7fa0
// Address:   0x006c7fa0
// Status:    RETIRED by MEGA-071 (2026-08-05)
// Replacement:
//   docs/reconstruction/reconstructed-exact/PhysicsShape_Sphere_CtorFromRadius_Inferred.cpp
//   docs/reconstruction/reconstructed-exact/FUN_006c7fa0.cpp
//
// Why retired:
//   Parent-seed plate tied this VA to Named_VOG_DEBUG_STOP, but VOG_DEBUG_STOP
//   is the AABB-fail branch of CVOGPhysicsUtils::GetObjectsInArea — not a caller
//   of 0x006c7fa0. Live xrefs show 18 CALL sites for sphere-shape setup; mode-2
//   of GetObjectsInArea is the sealed product path.
// =============================================================================
