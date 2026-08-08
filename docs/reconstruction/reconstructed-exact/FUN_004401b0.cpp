// =============================================================================
// FUN_004401b0  (scaffold twin → see gfxUIWindow_ScalarDeletingDtor.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_004401b0
// Address:   0x004401b0–0x004401cd inclusive (30 B / 0x1E)
// Wave:      MEGA-129 OWN-ONLY dual 2026-08-05
// Canonical: gfxUIWindow_ScalarDeletingDtor
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_00759de0(void* self);
extern "C" void operator_delete(void* p);

// Prefer gfxUIWindow_ScalarDeletingDtor as the named port entry.
extern "C" void* __thiscall FUN_004401b0(void* self, uint8_t flags)
{
  FUN_00759de0(self);
  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }
  return self;
}
