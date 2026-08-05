// =============================================================================
// GuardedVector_Resize_Thiscall
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d940
// Address:   0x0043d940–0x0043d989  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043d940
// System:    STL / guarded ring-deque container
// Dual:      W33-L 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = container; stack (new_size, fill); RET 0x8.
// Grow: GuardedVector_InsertN_Thiscall at end (begin+size) with N = new-size-size.
// Shrink: FUN_0043df90 erase [begin+new_size, begin+size) (unowned thiscall erase).
// Twin of W28-D GuardedVector_Resize (EAX/ECX register ABI + internal fill0).
// Name is structural (GuardedVector_* family); product/PDB open.
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

// Sealed W32-F: ECX=container; stack (seed, insert_at, N, fill*); RET 0x10
extern "C" void GuardedVector_InsertN_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                               GuardedVectorHeader* seed,
                                               int32_t insert_at,
                                               uint32_t n,
                                               const uint32_t* fill);

// Unowned thiscall erase-range twin of GuardedVector_EraseRange (W27-C).
extern "C" void FUN_0043df90(GuardedVectorIteratorPair* out,
                             GuardedVectorHeader* c /*ECX-ish stack pack*/,
                             int32_t erase_from,
                             GuardedVectorHeader* seed,
                             int32_t erase_to);

// Clean: container explicit (retail keeps it in ECX).
extern "C" void GuardedVector_Resize_Thiscall(GuardedVectorHeader* container /*ECX*/,
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
