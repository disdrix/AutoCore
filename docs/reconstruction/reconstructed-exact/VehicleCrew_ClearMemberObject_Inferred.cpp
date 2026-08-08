// =============================================================================
// VehicleCrew_ClearMemberObject_Inferred  (FUN_00574a90)
// -----------------------------------------------------------------------------
// Stable ID: aa_00574a90
// Address:   0x00574a90  (autoassault.exe, image base 0x400000)
// Body:      0x00574a90–0x00574af4 exclusive (100 B); CC pad
// System:    skills-abilities (crew roster clear; Client_ClearObjectReferences)
// Generated: 2026-08-04 WQ9D-G dual (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed callee this.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / not run).
// =============================================================================
//
// PURPOSE:
//   Find candidate COID in this host's 4-slot crew table @ +0x198. On match:
//   null the live object* at (slot+0x1A)*0x10 and clear candidate+0xCB0
//   (crew-host back-link) via FUN_00520330(0). Return AL bool success.
//
//   Does NOT free COID (no 0xFFFFFFFF sentinel) and does NOT decrement +0x1D8.
//
// Twins: Contains FUN_005749d0 (dualed WQ9R-A); Insert FUN_005755b0 (OWN WQ9D-D).
// Sole caller: Client_ClearObjectReferences (0x00944d50).
//
// ABI: __thiscall; ECX=crew host*; stack candidate*; RET 4; AL = 0/1.
//
// Dual: reviews/A|B_aa_00574a90_VehicleCrew_ClearMemberObject_Inferred.md

#include <cstdint>

// Crew host (partial):
//   +0x198 slot[4] stride 0x10: [0]=coidLo, [1]=coidHi
//   object* at (i + 0x1A) * 0x10  → +0x1A0 + i*0x10
// Candidate:
//   COID via SharedBase offBase +0x164/+0x168
//   +0xCB0 crew-host back-pointer (cleared to 0)

// __thiscall helper used at hit path (not OWN)
static inline void Object_SetCrewHostPtr_Inferred(void *obj, void *hostOrNull)
{
  *reinterpret_cast<void **>(static_cast<char *>(obj) + 0xCB0) = hostOrNull;
}

// __thiscall
extern "C" std::uint8_t __thiscall VehicleCrew_ClearMemberObject_Inferred(
    void *self,
    void *candidate)
{
  int offBase =
      *reinterpret_cast<int *>(*reinterpret_cast<int *>(static_cast<char *>(candidate) + 4) + 4);
  int coidLo = *reinterpret_cast<int *>(offBase + 0x164 + reinterpret_cast<int>(candidate));
  int coidHi = *reinterpret_cast<int *>(offBase + 0x168 + reinterpret_cast<int>(candidate));

  int *slot = reinterpret_cast<int *>(static_cast<char *>(self) + 0x198);
  int i = 0;
  while (slot[0] != coidLo || slot[1] != coidHi) {
    ++i;
    slot += 4; /* +0x10 bytes */
    if (i > 3) {
      return 0;
    }
  }

  *reinterpret_cast<int *>(static_cast<char *>(self) + (i + 0x1A) * 0x10) = 0;
  Object_SetCrewHostPtr_Inferred(candidate, nullptr); /* FUN_00520330(0), ECX=candidate */
  return 1;
}

// Legacy symbol alias.
extern "C" std::uint8_t __thiscall FUN_00574a90(void *self, void *candidate)
{
  return VehicleCrew_ClearMemberObject_Inferred(self, candidate);
}
