// =============================================================================
// Color_LerpPackedARGB_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Clamp blend factor t to [0,1], lerp two packed 0xAARRGGBB colors
//           channel-wise, write result to *dest (BGRA bytes via pack helper).
//
// Address:  0x00973690  (autoassault.exe, image base 0x400000)
// Body:     0x00973690–0x0097376e (222 bytes / 0xDE)
// Stable:   aa_00973690
// System:   graphics / color
// Ghidra:   FUN_00973690
//
// ABI:      ECX = uint32_t *dest
//           stack: float t, uint32_t color0, uint32_t color1
//           epilogue: ret 0x0C (stdcall-clean 3 dwords); void
// ISA:      SSE movss / comiss clamp; integer channel extract; call pack
//
// Exactness: CF mirrors raw + read_memory + call-site LEA ECX seals.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W28-F seal).
// =============================================================================

/* Color_LerpPackedARGB_Inferred — packed ARGB lerp → dest.

   Parameters:
     dest:   ECX — output packed color (0xAARRGGBB / BGRA memory)
     t:      blend factor; clamped to [0,1] using g_flOne
     color0: start color (packed)
     color1: end color (packed)

   Algorithm:
     t' = clamp(t, 0, 1)
     for each channel ch in {R,G,B,A}:
       out_ch = (float)(int)(ch1 - ch0) * t' + (float)ch0
     FUN_00973590(R,G,B,A) packs/clamps 0..255 into *dest

   Returns: void */

extern float g_flOne; /* 0x00a0f2a0 = 1.0f */

void FUN_00973590(float r, float g, float b, float a); /* EAX=dest on entry */

void __fastcall Color_LerpPackedARGB_Inferred(uint32_t *dest /*ECX*/,
                                              float t,
                                              uint32_t color0,
                                              uint32_t color1)
{
  float local_zero;
  float local_one;
  float *p_t;
  float t_clamped;
  uint32_t c0_g;
  uint32_t c0_r;
  float out_r;
  float out_g;
  float out_b;
  float out_a;

  local_zero = 0.0f;
  local_one = g_flOne;
  p_t = &local_zero;
  if (0.0f <= t) {
    p_t = &local_one;
    if (t <= g_flOne) {
      p_t = &t;
    }
  }
  t_clamped = *p_t;

  c0_g = (color0 >> 8) & 0xff;
  c0_r = (color0 >> 16) & 0xff;

  out_r = (float)(int)(((color1 >> 16) & 0xff) - c0_r) * t_clamped + (float)c0_r;
  out_g = (float)(int)(((color1 >> 8) & 0xff) - c0_g) * t_clamped + (float)c0_g;
  out_b = (float)(int)((color1 & 0xff) - (color0 & 0xff)) * t_clamped
          + (float)(color0 & 0xff);
  out_a = (float)(int)((color1 >> 24) - (color0 >> 24)) * t_clamped
          + (float)(color0 >> 24);

  /* retail: mov eax, ecx before call — pack helper writes through EAX */
  (void)dest;
  FUN_00973590(out_r, out_g, out_b, out_a);
  return;
}
