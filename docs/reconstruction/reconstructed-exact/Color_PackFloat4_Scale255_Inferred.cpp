// =============================================================================
// Color_PackFloat4_Scale255_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Scale float4 by 255.0f and pack into a 4-byte color buffer via
//           FUN_00973590 (clamp+ROUND per channel). Dest is ECX (hidden from
//           naive decompiler surface).
//
// Address:  0x00973820  (autoassault.exe, image base 0x400000)
// Body:     0x00973820–0x00973872 (83 B / 0x53)
// Stable:   aa_00973820
// System:   client color pack utility
//
// ABI:      ECX = uint8_t* dest (packed color)
//           stack: const float* src  (float4, often normalized 0..1)
//           ret 4 (C2 04 00); void
//
// Constant: DAT_00aaa6f8 = 255.0f
// Callee:   FUN_00973590 (clamp ROUND pack; writes dest via EAX)
//
// Exactness: CF mirrors raw + read_memory bytes; ECX dest restored from bytes.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W28-E seal).
// =============================================================================

#include <stdint.h>

// Nested packer (not dualed this wave): clamps ROUND(f) to 0..255 into dest.
// Channel map (from FUN_00973590 decompile): dest[2]=f0, dest[1]=f1,
// dest[0]=f2, dest[3]=f3  (BGRA-style if src is RGBA).
extern void FUN_00973590(float f0, float f1, float f2, float f3);

// Image constant DAT_00aaa6f8
static const float kColorScale255 = 255.0f;

void Color_PackFloat4_Scale255_Inferred(uint8_t *dest /*ecx*/, const float *src)
{
  // Body: mul each src[i] by 255.0f, push as four float args, mov eax,ecx,
  // call FUN_00973590, ret 4.
  // Represent ECX dest as explicit first param for the port surface.
  (void)dest; // consumed as EAX into FUN_00973590 in the image
  FUN_00973590(src[0] * kColorScale255,
               src[1] * kColorScale255,
               src[2] * kColorScale255,
               src[3] * kColorScale255);
}
