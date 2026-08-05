// =============================================================================
// FUN_00433280 — alias of NDAssetImage_WriteAlphaPlaneByte
// -----------------------------------------------------------------------------
// Stable ID: aa_00433280
// Address:   0x00433280  (autoassault.exe, image base 0x400000)
// Canonical: NDAssetImage_WriteAlphaPlaneByte
// See:       reconstructed-exact/NDAssetImage_WriteAlphaPlaneByte.cpp
// Generated: 2026-07-29 W23-A dual A/B seal
// Exactness: Behavior-preserving; register ABI sealed from read_memory.
// =============================================================================

#include <stdint.h>

/*
 * Machine ABI (sealed):
 *   EAX = image this
 *   ESI = row (y)
 *   EDX = col (x)
 *   [esp+4] = uint8_t alpha
 *   RET 4
 *
 * Decompiler residual names in_EAX / unaff_ESI kept for cross-ref to raw.
 */

void FUN_00433280(
    uint32_t /*param_1_unused_decomp_display*/,
    int32_t col /*edx = param_2*/,
    uint8_t alpha /*stack = param_3*/)
{
  int32_t in_EAX;     /* image* — EAX at entry */
  int32_t unaff_ESI;  /* row    — ESI at entry */
  uint8_t *plane;
  int32_t width;

  plane = *(uint8_t **)(in_EAX + 0x1b0);
  if (plane == 0) {
    return;
  }
  if (unaff_ESI < 0) {
    return;
  }
  if (unaff_ESI >= *(int32_t *)(in_EAX + 0x10)) {
    return;
  }
  if (col < 0) {
    return;
  }
  width = *(int32_t *)(in_EAX + 0x0c);
  if (col >= width) {
    return;
  }
  plane[width * unaff_ESI + col] = alpha;
}
