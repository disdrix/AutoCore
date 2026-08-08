// =============================================================================
// FUN_0040a590  (alias of StdVector_UninitializedCopy_Elem12_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a590
// Address:   0x0040a590–0x0040a5f4 inclusive (101 B / 0x65)
// Dual A/B:  2026-08-05 WQ9K-J
// See:       StdVector_UninitializedCopy_Elem12_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void StdVector_PodCopyElement_Elem12_Inferred(
    /*EAX*/ void* dest,
    /*ECX*/ const void* src);

extern "C" void* FUN_0040a590(
    /*ECX*/ const void* src_end,
    /*stack*/ const void* src_begin,
    /*stack*/ void* dest)
{
  const unsigned char* src = static_cast<const unsigned char*>(src_begin);
  const unsigned char* const end = static_cast<const unsigned char*>(src_end);
  unsigned char* out = static_cast<unsigned char*>(dest);

  while (src != end) {
    StdVector_PodCopyElement_Elem12_Inferred(out, src);
    src += 0x0C;
    out += 0x0C;
  }
  return out;
}
