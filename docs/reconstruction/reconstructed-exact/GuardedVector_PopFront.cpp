// =============================================================================
// GuardedVector_PopFront
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d980
// Address:   0x0040d980–0x0040d9b1  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0040d980
// System:    STL / guarded ring-deque container
// Dual:      W30-B 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EAX = container; 0 stack formals; plain RET; void.
// Header-only pop_front: advance begin (wrap at capacity*4), size--.
// No element dtor, no page free, no CS. Name structural (GuardedVector_*).
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;   // +0x04  (unused by this leaf)
  int32_t  capacity;  // +0x08  page count
  int32_t  begin;     // +0x0c  absolute element index of front
  int32_t  size;      // +0x10  element count
};

// Clean signature: container explicit (retail keeps it in EAX).
void GuardedVector_PopFront(GuardedVectorHeader* container /*EAX*/)
{
  if (container->size == 0) {
    return;
  }

  container->begin += 1;
  // Total element slots in ring = page_capacity * 4.
  if (static_cast<uint32_t>(container->capacity * 4) <=
      static_cast<uint32_t>(container->begin)) {
    container->begin = 0;
  }

  container->size -= 1;
  if (container->size == 0) {
    container->begin = 0;
  }
}
