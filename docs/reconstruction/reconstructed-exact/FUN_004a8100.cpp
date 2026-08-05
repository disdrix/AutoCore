// =============================================================================
// FUN_004a8100 — scaffold twin of StdVector_PushBack_BasicStringW (aa_004a8100)
// Wave W38-K 2026-08-04. Prefer named clean:
//   docs/reconstruction/reconstructed-exact/StdVector_PushBack_BasicStringW.cpp
// =============================================================================

#include <cstdint>

// See StdVector_PushBack_BasicStringW.cpp for full plate + types.
extern "C" void StdVector_PushBack_BasicStringW(void* vec /*ECX*/, const void* value);

extern "C" void __thiscall FUN_004a8100(void* vec, const void* value)
{
  StdVector_PushBack_BasicStringW(vec, value);
}
