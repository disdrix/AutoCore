// =============================================================================
// FUN_004e96e0  /  Math_CopyFloat4_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004e96e0
// Address:   0x004e96e0  (autoassault.exe, image base 0x400000)
// Body:      0x004e96e0–0x004e9715 (54 bytes)
// System:    shared math leaf
// Generated: 2026-07-23 scaffold; 2026-07-29 W17-O dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow + SSE bytes.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual A/B: accept — full float4 copy sealed.
// Prefer: reconstructed-exact/Math_CopyFloat4_Inferred.cpp
// =============================================================================

/*
 * Full float[4] component copy (SSE movss). Leaf.
 * cdecl: dst=[ebp+8], src=[ebp+0xC]; EAX returns dst*.
 * Sibling 0x004e9530 copies xyz only (dirty W) — different contract.
 */

float *FUN_004e96e0(float *param_1 /* dst */, const float *param_2 /* src */)
{
  float uVar1;
  float uVar2;
  float uVar3;

  uVar1 = param_2[3];
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  *param_1 = *param_2;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  return param_1;
}
