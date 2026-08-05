// =============================================================================
// Color_ClampRoundPackBGRA_Inferred
// -----------------------------------------------------------------------------
// Purpose:  ROUND each of four float channels and clamp to 0..255, then pack
//           into a 4-byte buffer in BGRA memory order when args are RGBA.
//
// Address:  0x00973590  (autoassault.exe, image base 0x400000)
// Body:     0x00973590–0x00973680 (240 B / 0xF0)
// Stable:   aa_00973590
// System:   client color pack utility
// Ghidra:   FUN_00973590
//
// ABI:      EAX = uint8_t *dest
//           stack: float f0, f1, f2, f3  (typically R,G,B,A in 0..255 scale)
//           epilogue: add esp,0xC; ret 0x10  (stdcall-clean 16 bytes)
//           void; leaf (FPU ROUND only)
//
// Channel map (bytes):
//   dest[2] = clamp_u8(ROUND(f0))  // R → BGRA[2]
//   dest[1] = clamp_u8(ROUND(f1))  // G → BGRA[1]
//   dest[0] = clamp_u8(ROUND(f2))  // B → BGRA[0]
//   dest[3] = clamp_u8(ROUND(f3))  // A → BGRA[3]
//
// Exactness: CF + channel indices + ret 0x10 sealed via decompile + read_memory.
// Decompiler mid-channel clamp *labels* may alias stack slots — algorithm is
// still 0..255 clamp (bytes win).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W29-I seal).
// =============================================================================

#include <stdint.h>
#include <math.h>

static inline uint8_t clamp_round_u8(float f)
{
  int v = (int)lroundf(f); /* image: FPU fistp ROUND */
  if (v < 0)
    return 0;
  if (v > 0xFF)
    return 0xFF;
  return (uint8_t)v;
}

/* Image ABI: dest arrives in EAX; four floats on stack; ret 0x10. */
void Color_ClampRoundPackBGRA_Inferred(uint8_t *dest /*eax*/,
                                       float f0, float f1, float f2, float f3)
{
  dest[2] = clamp_round_u8(f0);
  dest[1] = clamp_round_u8(f1);
  dest[0] = clamp_round_u8(f2);
  dest[3] = clamp_round_u8(f3);
}
