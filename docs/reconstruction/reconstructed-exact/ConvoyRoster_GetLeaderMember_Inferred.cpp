// =============================================================================
// ConvoyRoster_GetLeaderMember_Inferred  (FUN_00574880)
// -----------------------------------------------------------------------------
// Stable ID: aa_00574880
// Address:   0x00574880-0x0057489b  (autoassault.exe, image base 0x400000)
// System:    convoy / crew roster
// Generated: 2026-08-04 WQ9F-I dual seal (from raw 2026-07-23 + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Return the convoy/crew member object* at the leader slot, or null.
//   Gate: member-count byte at this+0x1d8 == 0 → null.
//   Else load slot index from this+0x194 and return
//     *(this + (slot + 0x1a) * 0x10)  // same algebra as GetMemberBySlot
//   Call sites compare EAX to DAT_00d1b6d8 (local player) for leader gates
//   (Invite/Kick disable, roster UI, residual mission/UI paths).
//
// ABI (image-sealed):
//   ECX = roster / crew host (often *(local+0xCB0))
//   no stack args
//   plain RET (C3)
//   returns void* in EAX (member object or null)
//
// Body hex:
//   80 B9 D8 01 00 00 00  77 03  33 C0  C3
//   8B 81 94 01 00 00  83 C0 1A  C1 E0 04  8B 04 08  C3
//
// Twin: ConvoyRoster_GetMemberBySlot_Inferred @ 0x00574760
// Peers: VehicleCrew_ContainsMember / ClearMember share +0x198 slot table
//
// Dual reviews:
//   reviews/A_aa_00574880_ConvoyRoster_GetLeaderMember_Inferred.md
//   reviews/B_aa_00574880_ConvoyRoster_GetLeaderMember_Inferred.md
// =============================================================================

#include <stdint.h>

void *__fastcall ConvoyRoster_GetLeaderMember_Inferred(void *roster)
{
  if (*(uint8_t *)((char *)roster + 0x1d8) == 0) {
    return 0;
  }
  int leaderSlot = *(int *)((char *)roster + 0x194);
  return *(void **)((char *)roster + (leaderSlot + 0x1a) * 0x10);
}
