// =============================================================================
// LookupRaceDisplayName_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f8e0
// Address:   0x0051f8e0  (autoassault.exe, image base 0x400000)
// Body:      0x0051f8e0 – 0x0051f90b exclusive (43 B / 0x2B); pad CC; next FUN_0051f910
// System:    skills-abilities
// Generated: 2026-08-05 R12-017 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (no runtime Confirmed).
// Ghidra twin: FUN_0051f8e0
// Rejected:  Named_CalleeOf_Named_Combat_0051f8e0
// =============================================================================

// PURPOSE:
//   Pure leaf: map integer race id → static product English display name.
//   Used by item/craft requirement UI for the "Required Faction" / race line
//   after def vfunc +0x14 yields a race id (callers skip when -1).
//
// ABI:
//   cdecl; 1 stack arg (raceId); plain RET; returns const char* in EAX
//   (immediate rodata pointer — do not free; not a TLS ring buffer).
//
// RACE MAP (product strings sealed via read_memory):
//   0 → "Human"   @ 0x00a40958
//   1 → "Mutant"  @ 0x00a40950
//   2 → "Biomek"  @ 0x00a40948
//   * → "Unknown" @ 0x00a37c4c
//
// PEERS (not this unit):
//   0x0051f910 short codes HUM/MUT/BIO
//   0x0051f940 LookupClassDisplayName_Inferred
//   0x00521800 Character_GetRaceDisplayName_Inferred (thiscall + ring; embeds same map)
//
// CALLERS:
//   0x00845360 UI_AppendItemRequirements @ 0x00845520
//   0x00846820 UI_AppendCraftRequirements_Inferred @ 0x00846d8c

const char * LookupRaceDisplayName_Inferred(int raceId)
{
  if (raceId == 0) {
    return "Human";
  }
  if (raceId != 1) {
    if (raceId != 2) {
      return "Unknown";
    }
    return "Biomek";
  }
  return "Mutant";
}
