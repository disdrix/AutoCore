// =============================================================================
// FUN_00973820  (twin of Color_PackFloat4_Scale255_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00973820
// Address:   0x00973820  (autoassault.exe, image base 0x400000)
// Body:      0x00973820–0x00973872 (83 B)
// System:    client color pack utility
// Generated: 2026-07-29 W28-E OWN dual (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI fix.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>

// DAT_00aaa6f8 = 255.0f
extern float DAT_00aaa6f8;
extern void FUN_00973590(float f0, float f1, float f2, float f3);

// Image ABI: ECX = dest byte buffer; stack float* src; ret 4.
// Decompiler surface drops ECX; restored from read_memory (`mov eax,ecx`).
void FUN_00973820(uint8_t *dest /*ecx*/, float *src)
{
  (void)dest;
  FUN_00973590(*src * DAT_00aaa6f8,
               src[1] * DAT_00aaa6f8,
               src[2] * DAT_00aaa6f8,
               src[3] * DAT_00aaa6f8);
}
