// =============================================================================
// FUN_0040dab0  (Ghidra twin of Math_RoundFloatToInt_MissionXpBias_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040dab0
// Address:   0x0040dab0–0x0040dad7  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-08-05 MEGA-119 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: Math_RoundFloatToInt_MissionXpBias_Inferred.cpp
// =============================================================================

// PURPOSE:
//   Ghidra-symbol twin for indexing. Prefer the named clean unit for ports.
//   Signed float→int round via g_flMissionXpRoundBias (0.5001f).

extern float g_flMissionXpRoundBias; // VA 0x00aaa6d0 = 0.5001f

int FUN_0040dab0(float param_1)
{
  if (param_1 < 0.0f) {
    return (int)(param_1 - g_flMissionXpRoundBias);
  }
  return (int)(param_1 + g_flMissionXpRoundBias);
}
