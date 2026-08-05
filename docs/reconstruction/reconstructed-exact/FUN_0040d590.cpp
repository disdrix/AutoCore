// =============================================================================
// FUN_0040d590 — scaffold twin of Class_009c7938_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d590
// Address:   0x0040d590  (autoassault.exe, image base 0x400000)
// Wave:      W31-E OWN-ONLY dual 2026-07-29
// Prefer:    Class_009c7938_ScalarDeletingDtor.cpp
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_0040d820(void* self);
extern "C" void operator_delete(void* p);
extern "C" void* __thiscall Class_009c7938_ScalarDeletingDtor(void* self, uint8_t flags);

extern "C" void* __thiscall FUN_0040d590(void* param_1, uint8_t param_2)
{
  return Class_009c7938_ScalarDeletingDtor(param_1, param_2);
}
