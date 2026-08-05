// =============================================================================
// Named_CalleeOf_Client_UpdateNpcInteractIcons_004e88e0
// -----------------------------------------------------------------------------
// Alias scaffold kept for xref continuity. Prefer Vec3_Copy / FUN_004e88e0.
// Stable: aa_004e88e0 @ 0x004e88e0
// Dual A/B accept 2026-07-29 — pure float3 XYZ copy (__cdecl).
// =============================================================================

void __cdecl Named_CalleeOf_Client_UpdateNpcInteractIcons_004e88e0(
    float *dst, float const *src)
{
  float y;
  float z;

  y = src[1];
  z = src[2];
  dst[0] = src[0];
  dst[1] = y;
  dst[2] = z;
  return;
}
