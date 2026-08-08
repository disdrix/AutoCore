// =============================================================================
// FUN_0040a520 — clean twin of StdVector_UninitializedCopy_Elem0x28_Inferred
// Stable ID: aa_0040a520 | VA 0x0040a520 | WQ9J-A 2026-08-05
// See: StdVector_UninitializedCopy_Elem0x28_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void FUN_00409f30(/*EAX*/ void* dest, /*EDX*/ const void* src);

extern "C" void* FUN_0040a520(
    /*ECX*/ const void* src_end,
    /*stack*/ const void* src_begin,
    /*stack*/ void* dest)
{
  const unsigned char* src = static_cast<const unsigned char*>(src_begin);
  const unsigned char* const end = static_cast<const unsigned char*>(src_end);
  unsigned char* out = static_cast<unsigned char*>(dest);

  while (src != end) {
    FUN_00409f30(out, src);
    src += 0x28;
    out += 0x28;
  }
  return out;
}
