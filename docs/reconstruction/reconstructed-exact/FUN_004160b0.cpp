// =============================================================================
// FUN_004160b0 — alias twin for Class_00a6f61c_ScalarDeletingDtor
// Stable ID: aa_004160b0 | VA 0x004160b0 | WQ9I-E 2026-08-04
// Canonical clean: Class_00a6f61c_ScalarDeletingDtor.cpp
// =============================================================================

#include <cstdint>

extern "C" void* __thiscall Class_00a6f61c_ScalarDeletingDtor(void* self, uint8_t flags);

extern "C" void* __thiscall FUN_004160b0(void* self, uint8_t flags)
{
  return Class_00a6f61c_ScalarDeletingDtor(self, flags);
}
