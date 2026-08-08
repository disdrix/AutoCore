// =============================================================================
// RETIRED SCAFFOLD — do not use as canonical clean
// -----------------------------------------------------------------------------
// Former: Named_CalleeOf_Client_InteractClickPickTarget_0040d020
// Stable ID: aa_0040d020  VA: 0x0040d020
// Retired:   2026-08-05 MEGA-137
// Reason:    Parent-only scaffold; function is a shared pure math leaf with
//            two caller functions (Client_InteractClickPickTarget + FUN_005ba440),
//            not exclusive to pick-target.
// Canonical: Math_Vec3Length_Inferred.cpp
// Twin:      FUN_0040d020.cpp
// =============================================================================

// Redirect stub kept so old links resolve; body matches sealed CF.

typedef long double float10;

float10 Named_CalleeOf_Client_InteractClickPickTarget_0040d020(float param_1, float param_2, float param_3)
{
  /* RETIRED name — use Math_Vec3Length_Inferred */
  return SQRT((float10)param_3 * (float10)param_3 +
              (float10)param_2 * (float10)param_2 +
              (float10)param_1 * (float10)param_1);
}
