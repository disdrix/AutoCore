// =============================================================================
// Math_CopyFloat4_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Copy float[4] src → dst via SSE movss (all four components).
//           EAX returns dst*. Leaf. Not normalize / quat / transform.
//
// Address:  0x004e96e0  (autoassault.exe, image base 0x400000)
// Body:     0x004e96e0–0x004e9715 (54 bytes)
// Stable:   aa_004e96e0
// System:   shared math leaf
//
// Sibling:  Math_CopyFloat3ToFloat4_Inferred (0x004e9530) copies xyz only;
//           that unit's W is an uninitialized stack local — different contract.
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W17-O seal).
// =============================================================================

/* Math_CopyFloat4_Inferred — full float4 component copy.

   Parameters (cdecl stack):
     dst: float[4] destination  ([ebp+8])
     src: float[4] source       ([ebp+0xC])

   Returns: dst* in EAX (leftover from last load of param_1). */

float *Math_CopyFloat4_Inferred(float *dst, const float *src)
{
  float w = src[3];
  float y = src[1];
  float z = src[2];
  dst[0] = src[0];
  dst[1] = y;
  dst[2] = z;
  dst[3] = w;
  return dst;
}
