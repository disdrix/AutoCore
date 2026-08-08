// =============================================================================
// FUN_00409f50 — clean twin of StdVector_PodCopyElement_Elem12_Inferred
// Stable ID: aa_00409f50 | VA 0x00409f50 | WQ9J-A 2026-08-05
// See: StdVector_PodCopyElement_Elem12_Inferred.cpp
// =============================================================================

#include <cstdint>
#include <cstring>

extern "C" void FUN_00409f50(/*EAX*/ void* dest, /*ECX*/ const void* src)
{
  if (dest == nullptr)
    return;
  std::memcpy(dest, src, 0x0C);
}
