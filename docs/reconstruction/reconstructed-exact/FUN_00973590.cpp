// =============================================================================
// FUN_00973590  (scaffold twin of Color_ClampRoundPackBGRA_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00973590
// Address:   0x00973590  (autoassault.exe, image base 0x400000)
// Body:      0x00973590–0x00973680 (240 B / 0xF0)
// Wave:      W29-I OWN-ONLY dual (2026-07-29)
// Canonical: Color_ClampRoundPackBGRA_Inferred
// Exactness: Behavior-preserving rewrite; EAX dest + ret 0x10 restored.
// Bit-for-bit / runtime / differential: OPEN.
// =============================================================================

#include <stdint.h>
#include <math.h>

static inline uint8_t clamp_round_u8(float f)
{
  int v = (int)lroundf(f);
  if (v < 0)
    return 0;
  if (v > 0xFF)
    return 0xFF;
  return (uint8_t)v;
}

void FUN_00973590(uint8_t *dest /*eax*/,
                  float param_1, float param_2, float param_3, float param_4)
{
  dest[2] = clamp_round_u8(param_1);
  dest[1] = clamp_round_u8(param_2);
  dest[0] = clamp_round_u8(param_3);
  dest[3] = clamp_round_u8(param_4);
}
