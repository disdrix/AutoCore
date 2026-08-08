// =============================================================================
// Named_CalleeOf_Named_Combat_0051f8e0  — RETIRED SCAFFOLD NAME
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f8e0
// Address:   0x0051f8e0  (autoassault.exe, image base 0x400000)
// Status:    RETIRED by R12-017 dual seal (2026-08-05)
// Replace:   LookupRaceDisplayName_Inferred.cpp  /  FUN_0051f8e0.cpp
// Reason:    Scaffold chain plate mislabeled this leaf as combat callee; live
//            callers are UI_AppendItemRequirements + UI_AppendCraftRequirements
//            race/"Required Faction" lines. Body is pure race-id display lookup.
// =============================================================================

// See LookupRaceDisplayName_Inferred.cpp for the authoritative clean source.
// Historical scaffold body (CF unchanged):

char * Named_CalleeOf_Named_Combat_0051f8e0_RETIRED(int param_1)
{
  if (param_1 == 0) {
    return "Human";
  }
  if (param_1 != 1) {
    if (param_1 != 2) {
      return "Unknown";
    }
    return "Biomek";
  }
  return "Mutant";
}
