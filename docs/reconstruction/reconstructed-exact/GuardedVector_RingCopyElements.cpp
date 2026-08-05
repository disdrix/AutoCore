// =============================================================================
// GuardedVector_RingCopyElements
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d390
// Address:   0x0043d390 – 0x0043d411  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043d390
// System:    STL / guarded ring/deque-like container
// Dual:      W28-A 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================
//
// Shared leaf used by GuardedVector_RingCopyRange (FUN_0043ce90),
// GuardedVector_EraseRange forward path (FUN_0043c8c0), and related helpers.
// Reverse-side sister: FUN_0043d300 (not this unit).
// =============================================================================

#include <cstdint>

struct GuardedRingContainer {
  uint32_t reserved0;   // +0
  uint32_t** map;       // +4  block pointers
  uint32_t capacity;    // +8  block count (wrap modulus)
  // +0xc begin, +0x10 size live on full object (not required inside this leaf)
};

struct RingIterPair {
  GuardedRingContainer* container;  // [0]
  uint32_t index;                   // [1] absolute dword index
};

static inline uint32_t* ring_slot(GuardedRingContainer* c, uint32_t abs_idx)
{
  uint32_t block = abs_idx >> 2;
  const uint32_t slot = abs_idx + block * static_cast<uint32_t>(-4);  // abs_idx % 4
  if (c->capacity <= block) {
    block = block - c->capacity;
  }
  return reinterpret_cast<uint32_t*>(
      reinterpret_cast<uint8_t*>(c->map[block]) + slot * 4u);
}

// cdecl; 7 stack formals; plain RET (caller cleans).
void GuardedVector_RingCopyElements(RingIterPair* outPair,
                                    GuardedRingContainer* srcCont,
                                    uint32_t srcIdx,
                                    GuardedRingContainer* srcEndCont,
                                    uint32_t srcEndIdx,
                                    GuardedRingContainer* dstCont,
                                    uint32_t dstIdx)
{
  while (!(srcCont == srcEndCont && srcIdx == srcEndIdx)) {
    uint32_t* dst = ring_slot(dstCont, dstIdx);
    uint32_t* src = ring_slot(srcCont, srcIdx);
    *dst = *src;
    srcIdx += 1u;
    dstIdx += 1u;
  }
  outPair->container = dstCont;
  outPair->index = dstIdx;
}
