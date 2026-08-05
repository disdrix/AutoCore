// =============================================================================
// GuardedVector_RingCopyRange
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ce90
// Address:   0x0043ce90 – 0x0043cebe  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043ce90
// System:    STL / guarded container (unlocked assign helpers)
// Dual:      W27-B 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================
//
// Exclusive caller: GuardedVector_CopyAssign (FUN_0043c730) — fit + grow paths.
// Sole callee: FUN_0043d390 (ring-aware element walk; not OWN this wave).
// Name is structural (GuardedVector_* family from W25-R / W26-G); product open.
// =============================================================================

#include <cstdint>

// Unowned. Performs the actual ring element copy and writes *outPair.
extern "C" void FUN_0043d390(int* outPair,
                             int srcContainer, uint32_t srcIdx,
                             int srcEndContainer, uint32_t srcEndIdx,
                             int dstContainer, uint32_t dstIdx);

// Retail shim: reshape parent stack args, call FUN_0043d390, return ESI (outPair).
// Parent cleans 0x18 after return; this unit cleans 0x24 of its own pushes.
void* GuardedVector_RingCopyRange(int* outPair /*ESI*/,
                                  int srcContainer, uint32_t srcIdx,
                                  int srcEndContainer, uint32_t srcEndIdx,
                                  int dstContainer, uint32_t dstIdx)
{
  FUN_0043d390(outPair, srcContainer, srcIdx, srcEndContainer, srcEndIdx,
               dstContainer, dstIdx);
  return outPair;
}
