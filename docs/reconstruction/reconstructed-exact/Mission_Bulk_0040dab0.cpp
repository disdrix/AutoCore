// =============================================================================
// RETIRED scaffold alias — do not use as canonical
// -----------------------------------------------------------------------------
// Former name: Mission_Bulk_0040dab0 (keyword bulk scaffold; no plate evidence)
// Canonical:   Math_RoundFloatToInt_MissionXpBias_Inferred  (MEGA-119 dual 2026-08-05)
// Stable ID:   aa_0040dab0
// Address:     0x0040dab0
// See:         reconstructed-exact/Math_RoundFloatToInt_MissionXpBias_Inferred.cpp
// =============================================================================

// Body preserved for ledger continuity only — prefer the named clean unit.

extern float g_flMissionXpRoundBias; // VA 0x00aaa6d0 = 0.5001f

int Mission_Bulk_0040dab0(float param_1)
{
  if (param_1 < 0.0f) {
    return (int)(param_1 - g_flMissionXpRoundBias);
  }
  return (int)(param_1 + g_flMissionXpRoundBias);
}
