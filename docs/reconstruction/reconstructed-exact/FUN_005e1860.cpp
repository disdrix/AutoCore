// =============================================================================
// FUN_005e1860 / IntRange_MergeSorted_WriteEndPtr
// -----------------------------------------------------------------------------
// Stable ID: aa_005e1860
// Address:   0x005e1860 – 0x005e18cf  (autoassault.exe, image base 0x400000)
// System:    inventory / loot catalog
// Generated: 2026-07-29 (W16-D dual seal; replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   Sorted merge of two half-open int32 ranges into an output write cursor
//   (std::merge-style). Writes the advanced cursor to *pOutEndSlot.
//   Sole live caller FUN_005e0cd0 always passes empty range A (pure copy of B).
//
// ABI: __cdecl; 6 stack pointer args; bare RET (caller cleans 0x18).
// Leaf: no callees, no globals.
// Compare: signed int; on equal takes from A.

#include <stdint.h>

void FUN_005e1860(
    int32_t **pOutEndSlot, /* param_1 */
    int32_t  *beginA,      /* param_2 */
    int32_t  *endA,        /* param_3 */
    int32_t  *beginB,      /* param_4 */
    int32_t  *endB,        /* param_5 */
    int32_t  *out)         /* param_6 */
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
