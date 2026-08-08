// =============================================================================
// FUN_00416f00 — clean twin of Class_00a733ec_ScalarDeletingDtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00416f00
// Address:   0x00416f00  (autoassault.exe, image base 0x400000)
// See:       Class_00a733ec_ScalarDeletingDtor_Inferred.cpp for full plate
// Generated: 2026-08-05 WQ9J-E dual seal
// =============================================================================

#include <cstdint>

struct Class_00a733ec;

extern "C" Class_00a733ec *__thiscall Class_00a733ec_ScalarDeletingDtor_Inferred(
    Class_00a733ec *self, uint8_t flags);

extern "C" Class_00a733ec *__thiscall FUN_00416f00(Class_00a733ec *self,
                                                    uint8_t flags)
{
  return Class_00a733ec_ScalarDeletingDtor_Inferred(self, flags);
}
