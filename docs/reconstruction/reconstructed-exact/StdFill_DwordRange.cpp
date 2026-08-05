// =============================================================================
// StdFill_DwordRange
// -----------------------------------------------------------------------------
// Purpose:  Fill half-open range [first, last) with the dword at *value.
//           POD 4-byte assign loop (MSVC std::fill / _Fill class for uint32).
//
// Address:  0x005739b0  (autoassault.exe, image base 0x400000)
// Body:     0x005739b0–0x005739cd (30 bytes)
// Stable:   aa_005739b0
// System:   containers / POD fill
// Ghidra:   FUN_005739b0
//
// ABI:      __cdecl
//           void StdFill_DwordRange(uint32_t *first, uint32_t *last,
//                                   uint32_t const *value)
//           stack: [esp+4]=first, [esp+8]=last, [esp+0xC]=value; bare RET
// ISA:      integer mov / add 4; leaf (no call)
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W19-B seal).
// =============================================================================

/* StdFill_DwordRange — fill [first, last) with *value (4-byte elements).

   Parameters:
     first: start of writable dword range (inclusive)
     last:  end of range (exclusive); first==last → no-op
     value: pointer to template dword (re-read each iteration)

   Algorithm:
     for (; first != last; ++first) *first = *value;

   Returns: void

   Parents: vector insert-N / assign paths (e.g. FUN_004507a0, FUN_004073a0). */

#include <stdint.h>

void __cdecl StdFill_DwordRange(uint32_t *first, uint32_t *last,
                                uint32_t const *value)
{
  for (; first != last; first = first + 1) {
    *first = *value;
  }
  return;
}
