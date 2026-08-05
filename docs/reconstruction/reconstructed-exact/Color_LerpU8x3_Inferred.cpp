// =============================================================================
// Color_LerpU8x3_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Lerp three U8 channels: out[i] = from[i] + ROUND((to[i]-from[i])*t)
//           for i in {2,1,0}. No alpha. Leaf math helper for motion stage colors.
//
// Address:  0x004b2910  (autoassault.exe, image base 0x400000)
// Body:     0x004b2910–0x004b29cd (190 B / 0xBE)
// Stable:   aa_004b2910
// System:   client color / object-motion stage params
//
// ABI:      cdecl (float t, uint8_t* out, const uint8_t* from, const uint8_t* to)
//           plain RET (C3); void. Callers clean 0x10.
//
// Callers:  ObjectMotion_ApplyStageParams_Inferred (FUN_004b2b90) ×3 sites
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W28-E seal).
// =============================================================================

#include <stdint.h>

// ROUND is the same CRT/FPU round-to-nearest used by the client image.
extern double ROUND(double x);

void Color_LerpU8x3_Inferred(float t, uint8_t *out, const uint8_t *from, const uint8_t *to)
{
  int d2 = (int)to[2] - (int)from[2];
  out[2] = (uint8_t)(from[2] + (int)ROUND((float)d2 * t));

  int d1 = (int)to[1] - (int)from[1];
  out[1] = (uint8_t)(from[1] + (int)ROUND((float)d1 * t));

  int d0 = (int)to[0] - (int)from[0];
  out[0] = (uint8_t)(from[0] + (int)ROUND((float)d0 * t));
}
