// =============================================================================
// GuardedVector_PopBack
// -----------------------------------------------------------------------------
// Stable ID: aa_0043df70
// Address:   0x0043df70–0x0043df86  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043df70
// System:    STL / guarded ring-deque container
// Dual:      W30-C 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = container; no stack formals; plain RET.
// If size!=0: size--. If size becomes 0: begin = 0.
// Bookkeeping only — no element dtor, no page free.
// Name structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;   // +0x04
  int32_t  capacity;  // +0x08
  int32_t  begin;     // +0x0c
  int32_t  size;      // +0x10
};

// Retail: this in ECX.
void GuardedVector_PopBack(GuardedVectorHeader* container /*ECX*/)
{
  int32_t size = container->size;
  if (size == 0) {
    return;
  }
  size -= 1;
  container->size = size;
  if (size == 0) {
    container->begin = 0;
  }
}
