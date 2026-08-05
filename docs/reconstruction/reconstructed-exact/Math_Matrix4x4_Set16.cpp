// =============================================================================
// Math_Matrix4x4_Set16
// -----------------------------------------------------------------------------
// Purpose:  Write sixteen float scalars into a destination float[16] matrix.
//           Leaf helper — no projection math (callers precompute elements).
//
// Address:  0x0043f210  (autoassault.exe, image base 0x400000)
// Body:     0x0043f210–0x0043f2df (208 bytes; ret 0x40)
// Stable:   aa_0043f210
// System:   math / matrix
// Ghidra:   FUN_0043f210
//
// ABI:      __thiscall
//             ECX = float *out
//             stack = 16× float (m00..m33 row-major)
//             ret 0x40
// ISA:      movss spill to aligned local + rep movsd ×16 dwords
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W18-E seal).
// =============================================================================

/* Math_Matrix4x4_Set16 — materialize 4×4 from 16 scalars (leaf).

   Parameters:
     out: destination float[16] (this / ECX)
     m00..m33: matrix elements in row-major stack order

   Algorithm:
     out[i] = arg[i] for i in 0..15

   Notes:
     - Not D3DXMatrixPerspective* / Ortho* — pure store.
     - Sibling FUN_0043f2e0 (Math_MatrixOrthoOffCenterLH) performs ortho math.
     - gfxView perspective path computes sx/sy/zScale then calls this. */

void __thiscall Math_Matrix4x4_Set16(
    float *out,
    float m00, float m01, float m02, float m03,
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23,
    float m30, float m31, float m32, float m33)
{
  out[0] = m00;
  out[1] = m01;
  out[2] = m02;
  out[3] = m03;
  out[4] = m10;
  out[5] = m11;
  out[6] = m12;
  out[7] = m13;
  out[8] = m20;
  out[9] = m21;
  out[10] = m22;
  out[11] = m23;
  out[12] = m30;
  out[13] = m31;
  out[14] = m32;
  out[15] = m33;
  return;
}
