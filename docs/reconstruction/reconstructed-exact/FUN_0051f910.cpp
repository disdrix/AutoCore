// =============================================================================
// FUN_0051f910  (Ghidra twin of LookupRaceShortCode_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f910
// Address:   0x0051f910  (autoassault.exe, image base 0x400000)
// Body:      0x0051f910 – 0x0051f93b exclusive (43 B / 0x2B); pad CC
// System:    skills-abilities
// Generated: 2026-08-05 R13-032 dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (no runtime Confirmed).
// Named clean: LookupRaceShortCode_Inferred.cpp
// Rejected:  Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_0051f910
// =============================================================================

// PURPOSE:
//   Pure leaf race id → 3-letter short code: HUM / MUT / BIO / Unknown.
//   cdecl; plain RET; static rodata return.
//
// RACE SHORT MAP:
//   0 → "HUM" @ 0x009cef04
//   1 → "MUT" @ 0x009cef08
//   2 → "BIO" @ 0x009cef0c
//   * → "Unknown" @ 0x00a37c4c

const char * FUN_0051f910(int raceId)
{
  if (raceId == 0) {
    return "HUM";
  }
  if (raceId != 1) {
    if (raceId != 2) {
      return "Unknown";
    }
    return "BIO";
  }
  return "MUT";
}
