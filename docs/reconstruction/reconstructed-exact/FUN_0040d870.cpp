// =============================================================================
// FUN_0040d870 — scaffold twin of Class_009c7948_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d870
// Address:   0x0040d870 – 0x0040d88e exclusive (30 B / 0x1E)
// Wave:      W33-A 2026-07-29 (replaces 2026-07-23 scaffold)
// Canonical: Class_009c7948_ScalarDeletingDtor.cpp
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_0040d890(void* self);
extern "C" void __cdecl operator_delete(void* p);

// ECX = this; stack flags; RET 4; returns this*.
extern "C" void* __thiscall FUN_0040d870(void* self, uint8_t flags)
{
  FUN_0040d890(self);
  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }
  return self;
}
