// =============================================================================
// FUN_0043d940  (canonical: GuardedVector_Resize_Thiscall)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d940
// Address:   0x0043d940–0x0043d989  (autoassault.exe, image base 0x400000)
// Dual:      W33-L 2026-07-29
// See also:  GuardedVector_Resize_Thiscall.cpp
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

extern "C" void GuardedVector_InsertN_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                               GuardedVectorHeader* seed,
                                               int32_t insert_at,
                                               uint32_t n,
                                               const uint32_t* fill);

extern "C" void FUN_0043df90(GuardedVectorIteratorPair* out,
                             GuardedVectorHeader* c,
                             int32_t erase_from,
                             GuardedVectorHeader* seed,
                             int32_t erase_to);

// Retail: ECX=container; stack (new_size, fill); RET 0x8
extern "C" void FUN_0043d940(GuardedVectorHeader* container /*ECX*/,
                             uint32_t new_size,
                             uint32_t fill)
{
  const uint32_t size = static_cast<uint32_t>(container->size);

  if (size < new_size) {
    const uint32_t n = new_size - size;
    GuardedVector_InsertN_Thiscall(container, container,
                                   container->begin + static_cast<int32_t>(size),
                                   n, &fill);
    return;
  }

  if (new_size < size) {
    GuardedVectorIteratorPair out{};
    FUN_0043df90(&out, container,
                 container->begin + static_cast<int32_t>(new_size),
                 container,
                 container->begin + static_cast<int32_t>(size));
  }
}
