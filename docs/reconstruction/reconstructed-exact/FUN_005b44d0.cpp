// =============================================================================
// FUN_005b44d0  (scaffold alias → Obj_009d95b4_ScalarDeletingDtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b44d0
// Address:   0x005b44d0  (autoassault.exe, image base 0x400000)
// System:    host object / MSVC scalar-deleting destructor
// Generated: 2026-07-29 W30-N dual seal
// Exactness: Behavior-preserving; see named clean for authority.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void* __thiscall Obj_009d95b4_ScalarDeletingDtor(void* self, uint8_t flags);

extern "C" void* __thiscall FUN_005b44d0(void* self, uint8_t flags)
{
  return Obj_009d95b4_ScalarDeletingDtor(self, flags);
}
