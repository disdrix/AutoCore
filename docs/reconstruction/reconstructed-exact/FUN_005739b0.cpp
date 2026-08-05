// =============================================================================
// FUN_005739b0  (alias scaffold → StdFill_DwordRange)
// -----------------------------------------------------------------------------
// Stable ID: aa_005739b0
// Address:   0x005739b0  (autoassault.exe, image base 0x400000)
// Canonical: StdFill_DwordRange
// Dual A/B:  accept (2026-07-29 W19-B)
// Named clean: reconstructed-exact/StdFill_DwordRange.cpp (authoritative)
// =============================================================================

/* Scaffold alias — keep FUN_* name for coverage index; prefer named clean. */

#include <stdint.h>

void FUN_005739b0(uint32_t *param_1, uint32_t *param_2, uint32_t *param_3)
{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    *param_1 = *param_3;
  }
  return;
}
