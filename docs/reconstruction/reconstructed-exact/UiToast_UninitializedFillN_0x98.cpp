// =============================================================================
// UiToast_UninitializedFillN_0x98
// -----------------------------------------------------------------------------
// Purpose:  Fill-N / uninitialized_fill_n for UI toast POD (stride 0x98).
//           Calls UiToast_ConstructN_0x98 then returns end = dst + count*0x98.
//
// Address:  0x00404130  (autoassault.exe, image base 0x400000)
// Body:     0x00404130–0x0040415f (48 bytes)
// Stable:   aa_00404130
// System:   missions-progression / shared UI toast vector helpers
// Ghidra:   FUN_00404130
//
// ABI:      three stack args; ret 0x0C. ECX may be live from parent thiscall
//           and is pushed as a phantom formal into ConstructN (unused by leaf).
// Callee:   FUN_00404670 / UiToast_ConstructN_0x98
// Twin:     CombatFloater_UninitializedFillN_0x38 @ 0x00402ea0 (stride 0x38)
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W20-G seal).
// =============================================================================

/* UiToast_UninitializedFillN_0x98 — construct N toast PODs; return end.

   Algorithm:
     1. UiToast_ConstructN_0x98(dst, count, src)  // stamp template into [dst, end)
     2. return dst + count * 0x98

   Parent: UiToastVector_InsertN (0x00403980) uses this on realloc and in-place
   insert paths to fill the newly opened hole with N copies of the value. */

#include <stdint.h>

/* FUN_00404670 — sealed UiToast_ConstructN_0x98 */
extern void UiToast_ConstructN_0x98(void *dst, int count, const void *src);

void *UiToast_UninitializedFillN_0x98(void *dst, int count, const void *src)
{
  UiToast_ConstructN_0x98(dst, count, src);
  return (uint8_t *)dst + (size_t)count * 0x98u;
}
