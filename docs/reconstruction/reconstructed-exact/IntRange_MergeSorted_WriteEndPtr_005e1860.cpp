// =============================================================================
// IntRange_MergeSorted_WriteEndPtr  (named alias of FUN_005e1860)
// -----------------------------------------------------------------------------
// Stable ID: aa_005e1860
// Address:   0x005e1860 – 0x005e18cf  (autoassault.exe, image base 0x400000)
// System:    inventory / loot catalog
// Generated: 2026-07-29 (W16-D dual seal)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>

// See FUN_005e1860.cpp for full plate. Named entry for dual-review consumers.

void IntRange_MergeSorted_WriteEndPtr(
    int32_t **pOutEndSlot,
    int32_t  *beginA,
    int32_t  *endA,
    int32_t  *beginB,
    int32_t  *endB,
    int32_t  *out)
{
  if (beginA != endA) {
    do {
      if (beginB == endB)
        break;
      if (*beginB < *beginA) {
        *out = *beginB;
        beginB = beginB + 1;
      } else {
        *out = *beginA;
        beginA = beginA + 1;
      }
      out = out + 1;
    } while (beginA != endA);

    for (; beginA != endA; beginA = beginA + 1) {
      *out = *beginA;
      out = out + 1;
    }
  }

  for (; beginB != endB; beginB = beginB + 1) {
    *out = *beginB;
    out = out + 1;
  }

  *pOutEndSlot = out;
  return;
}
