// =============================================================================
// FUN_005114e0  — twin of StdVector_CopyCtor_Elem0x10_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005114e0
// Address:   0x005114e0–0x00511583 inclusive (164 B / 0xA4)
// System:    skills-abilities (R13-029; parent 0x00511950)
// Dual A/B:  2026-08-05; dual start 2686
// Canonical named source: StdVector_CopyCtor_Elem0x10_Inferred.cpp
// =============================================================================

#include <cstdint>

// Forward to named reconstruction (same ABI / CF).
extern "C" void* __thiscall StdVector_CopyCtor_Elem0x10_Inferred(void* self, const void* src);

extern "C" void* __thiscall FUN_005114e0(void* self, const void* src)
{
  return StdVector_CopyCtor_Elem0x10_Inferred(self, src);
}
