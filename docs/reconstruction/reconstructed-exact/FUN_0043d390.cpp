// =============================================================================
// FUN_0043d390 — clean twin of GuardedVector_RingCopyElements
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d390
// Address:   0x0043d390 – 0x0043d411
// Dual:      W28-A 2026-07-29
// =============================================================================

#include <cstdint>

// Behavior-preserving twin of GuardedVector_RingCopyElements.
// Avoid bare undefined4: dword elements via uint32_t.
//
// cdecl 7 stack formals:
//   outPair, srcCont, srcIdx, srcEndCont, srcEndIdx, dstCont, dstIdx
// Ring map @ container+4, capacity @ +8, 4 dwords/block.
// Copy one uint32_t per step until (srcCont,srcIdx)==(srcEndCont,srcEndIdx).
// Write *outPair = {dstCont, finalDstIdx}.

struct RingIterPair {
  void* container;
  uint32_t index;
};

extern "C" void FUN_0043d390(RingIterPair* outPair,
                             void* srcCont,
                             uint32_t srcIdx,
                             void* srcEndCont,
                             uint32_t srcEndIdx,
                             void* dstCont,
                             uint32_t dstIdx);

// Full body lives in GuardedVector_RingCopyElements.cpp (named reconstruction).
