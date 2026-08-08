// =============================================================================
// RETIRED scaffold — MEGA-039 2026-08-05
// -----------------------------------------------------------------------------
// Former auto-name: Named_CalleeOf_Named_VOG_DEBUG_STOP_006c6c50
// Stable ID:        aa_006c6c50  /  VA 0x006c6c50
//
// Why retired: "Named_VOG_DEBUG_STOP" is a parent-path string
// ("VOG_DEBUG_STOP" fail when AABB world null inside GetObjectsInArea),
// not a product name for this leaf. Sole caller is dualed
// CVOGPhysicsUtils_GetObjectsInArea (0x004ea350) @ 0x004ea560; role is
// area-query filter bit-matrix test.
//
// Use instead:
//   docs/reconstruction/reconstructed-exact/
//     CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.cpp
//   twin: FUN_006c6c50.cpp
// =============================================================================

#error "Retired scaffold Named_CalleeOf_Named_VOG_DEBUG_STOP_006c6c50 — use CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.cpp"
