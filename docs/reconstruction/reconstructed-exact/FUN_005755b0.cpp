// =============================================================================
// FUN_005755b0  (scaffold twin → VehicleCrew_InsertMember_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005755b0
// Address:   0x005755b0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities (crew roster writer)
// Generated: 2026-08-04 WQ9D-D (supersedes 2026-07-23 scaffold paste)
// Exactness: Behavior-preserving; see named clean for primary port source.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" std::uint8_t __thiscall VehicleCrew_InsertMember_Inferred(
    void* self,
    void* member);

extern "C" std::uint8_t __thiscall FUN_005755b0(void* param_1, void* param_2)
{
  return VehicleCrew_InsertMember_Inferred(param_1, param_2);
}
