// =============================================================================
// FUN_00574880  (scaffold alias of ConvoyRoster_GetLeaderMember_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00574880
// Address:   0x00574880  (autoassault.exe, image base 0x400000)
// System:    convoy / crew roster
// Generated: 2026-08-04 WQ9F-I (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: ConvoyRoster_GetLeaderMember_Inferred
// =============================================================================

#include <stdint.h>

uint32_t __fastcall FUN_00574880(void *param_1)
{
  if (*(uint8_t *)((char *)param_1 + 0x1d8) == 0) {
    return 0;
  }
  int leaderSlot = *(int *)((char *)param_1 + 0x194);
  return *(uint32_t *)((char *)param_1 + (leaderSlot + 0x1a) * 0x10);
}
