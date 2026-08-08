// =============================================================================
// FUN_00574a90 — scaffold twin of VehicleCrew_ClearMemberObject_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00574a90
// Address:   0x00574a90  (autoassault.exe, image base 0x400000)
// System:    skills-abilities (crew roster)
// Generated: 2026-08-04 WQ9D-G seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite; prefer named unit for docs.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// __thiscall; RET 4; AL bool
std::uint8_t __thiscall FUN_00574a90(void *self, void *candidate)
{
  int offBase =
      *reinterpret_cast<int *>(*reinterpret_cast<int *>(static_cast<char *>(candidate) + 4) + 4);
  int coidLo = *reinterpret_cast<int *>(offBase + 0x164 + reinterpret_cast<int>(candidate));
  int coidHi = *reinterpret_cast<int *>(offBase + 0x168 + reinterpret_cast<int>(candidate));

  int *slot = reinterpret_cast<int *>(static_cast<char *>(self) + 0x198);
  int i = 0;
  while (slot[0] != coidLo || slot[1] != coidHi) {
    ++i;
    slot += 4;
    if (i > 3)
      return 0;
  }

  *reinterpret_cast<int *>(static_cast<char *>(self) + (i + 0x1A) * 0x10) = 0;
  *reinterpret_cast<int *>(static_cast<char *>(candidate) + 0xCB0) = 0;
  return 1;
}
