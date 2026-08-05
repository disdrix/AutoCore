// =============================================================================
// Vec3_Copy
// -----------------------------------------------------------------------------
// Purpose:  Copy three consecutive floats (XYZ) from src to dst.
//           Does NOT copy a fourth (W) component.
//
// Address:  0x004e88e0  (autoassault.exe, image base 0x400000)
// Body:     0x004e88e0–0x004e8904 (37 bytes)
// Stable:   aa_004e88e0
// System:   math / vector
// Ghidra:   FUN_004e88e0
//
// ABI:      __cdecl  void Vec3_Copy(float *dst, float const *src)
//           stack: [esp+4]=dst, [esp+8]=src; bare RET
// ISA:      SSE movss load×3 / store×3 (not integer mov)
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W17-B seal).
// =============================================================================

/* Vec3_Copy — pure float3 XYZ copy (leaf).

   Parameters:
     dst: destination float[3] (or float4 buffer; only [0..2] written)
     src: source float[3] (or float4 buffer; only [0..2] read)

   Algorithm:
     dst[0]=src[0]; dst[1]=src[1]; dst[2]=src[2];

   Returns: void */

void __cdecl Vec3_Copy(float *dst, float const *src)
{
  float x;
  float y;
  float z;

  x = src[0];
  y = src[1];
  z = src[2];
  dst[0] = x;
  dst[1] = y;
  dst[2] = z;
  return;
}
