// =============================================================================
// FUN_0075f7f0  (scaffold twin → GfxDevice_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0075f7f0
// Address:   0x0075f7f0  (autoassault.exe, image base 0x400000)
// System:    client / Palantir graphics
// Generated: 2026-07-29 W35-R (re-verify; prefers named clean)
// Exactness: Forwards to GfxDevice_Ctor_Inferred.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void *__thiscall GfxDevice_Ctor_Inferred(void *d3d9, void *self, void *device9);

extern "C" void *__thiscall FUN_0075f7f0(void *d3d9, void *self, void *device9)
{
  return GfxDevice_Ctor_Inferred(d3d9, self, device9);
}
