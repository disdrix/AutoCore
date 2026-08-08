// =============================================================================
// LookupRaceShortCode_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f910
// Address:   0x0051f910  (autoassault.exe, image base 0x400000)
// Body:      0x0051f910 – 0x0051f93b exclusive (43 B / 0x2B); pad CC; next FUN_0051f940
// System:    skills-abilities
// Generated: 2026-08-05 R13-032 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (no runtime Confirmed).
// Ghidra twin: FUN_0051f910
// Rejected:  Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_0051f910
// =============================================================================

// PURPOSE:
//   Pure leaf: map integer race id → static 3-letter product short code.
//   Used by UI host FUN_00871150 to format "%d/%s/%s" (level / class-short / race-short)
//   after class short peer FUN_0051fa10.
//
// ABI:
//   cdecl; 1 stack arg (raceId); plain RET; returns const char* in EAX
//   (immediate rodata pointer — do not free; not a TLS ring buffer).
//
// RACE SHORT MAP (product strings sealed via read_memory):
//   0 → "HUM"     @ 0x009cef04
//   1 → "MUT"     @ 0x009cef08
//   2 → "BIO"     @ 0x009cef0c
//   * → "Unknown" @ 0x00a37c4c  (shared with LookupRaceDisplayName_Inferred)
//
// PEERS (not this unit):
//   0x0051f8e0 LookupRaceDisplayName_Inferred (English Human/Mutant/Biomek)
//   0x0051f940 LookupClassDisplayName_Inferred
//   0x0051fa10 class short codes COM/ENG/…×race (caller peer)
//   0x0051f550 BuildRaceClassSuffix_Inferred (_h/_m/_b path tokens)
//   0x00521800 Character_GetRaceDisplayName_Inferred (thiscall + ring)
//
// CALLERS:
//   0x00871150 @ 0x00871273  (UI level/class/race short formatter)

const char * LookupRaceShortCode_Inferred(int raceId)
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
