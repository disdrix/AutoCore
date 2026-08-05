// =============================================================================
// FUN_004b2910  (twin of Color_LerpU8x3_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004b2910
// Address:   0x004b2910  (autoassault.exe, image base 0x400000)
// Body:      0x004b2910–0x004b29cd (190 B)
// System:    client color / object-motion stage params
// Generated: 2026-07-29 W28-E OWN dual (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>

extern double ROUND(double x);

// cdecl; plain ret; void
// out[i] = from[i] + ROUND((to[i]-from[i])*t)  for i = 2,1,0
void FUN_004b2910(float t, uint8_t *out, const uint8_t *from, const uint8_t *to)
{
  int d2 = (int)to[2] - (int)from[2];
  out[2] = (uint8_t)(from[2] + (int)ROUND((float)d2 * t));

  int d1 = (int)to[1] - (int)from[1];
  out[1] = (uint8_t)(from[1] + (int)ROUND((float)d1 * t));

  int d0 = (int)to[0] - (int)from[0];
  out[0] = (uint8_t)(from[0] + (int)ROUND((float)d0 * t));
}
