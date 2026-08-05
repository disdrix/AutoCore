// =============================================================================
// FUN_0044e4f0  (canonical: GuardedVector_AssignLinearRangeAt)
// -----------------------------------------------------------------------------
// Stable ID: aa_0044e4f0
// Address:   0x0044e4f0–0x0044e553  (autoassault.exe, image base 0x400000)
// Dual:      W33-L 2026-07-29
// See also:  GuardedVector_AssignLinearRangeAt.cpp
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;   // +0x04
  uint32_t capacity;  // +0x08
  int32_t  begin;     // +0x0c
  int32_t  size;      // +0x10
};

struct GuardedVectorIteratorPair {
  GuardedVectorHeader* container;
  int32_t              index;
};

// Retail: cdecl; plain RET; 5 live formals (+ optional 6th residual at call sites)
extern "C" void FUN_0044e4f0(GuardedVectorIteratorPair* out,
                             const uint32_t* first,
                             const uint32_t* last,
                             GuardedVectorHeader* container,
                             uint32_t dest_idx)
{
  for (; first != last; ++first) {
    uint32_t page = dest_idx >> 2;
    const uint32_t sub = dest_idx - (page * 4u);
    if (container->capacity <= page) {
      page -= container->capacity;
    }
    uint32_t* slot = container->pages[page] + sub;
    if (slot != first) {
      *slot = *first;
    }
    dest_idx++;
  }
  out->index = static_cast<int32_t>(dest_idx);
  out->container = container;
}
