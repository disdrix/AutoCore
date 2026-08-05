// =============================================================================
// Math_QuatNormalize
// -----------------------------------------------------------------------------
// Stable ID: aa_0076e5e0
// Address:   0x0076e5e0 – 0x0076e6ab  (autoassault.exe, image base 0x400000)
// System:    math / quaternion
// Dual:      W26-B 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Normalize a 4-float quaternion. Skips work when lenSq is near zero
//   (|lenSq| < 1e-6) or near unit (abs+rel FloatNearlyEqual vs 1.0 with
//   both tols 1e-6). Otherwise scales out by 1/sqrt(lenSq).
//
// ABI (machine):
//   cdecl; float *out @ Stack[0x4], float *in @ Stack[0x8]
//   EAX = out; PUSH ESI / POP ESI; RET
// =============================================================================

#include <cstdint>
#include <cmath>

// Math_FloatNearlyEqual_AbsRel @ 0x0040d450 (W25-T sealed)
extern "C" std::uint32_t Math_FloatNearlyEqual_AbsRel(
    float a, float b, float relTol, float absTol);

// Image globals (float bits confirmed via read_memory)
extern float _DAT_00a240ec;  // +1e-6  bits 0x358637BD
extern float DAT_00aaa640;   // -1e-6  bits 0xB58637BD
extern float g_flOne;        // 1.0f   @ 0x00a0f2a0

extern "C" float * Math_QuatNormalize(float *out, float *in)
{
  float lenSq =
      in[0] * in[0] + in[1] * in[1] + in[2] * in[2] + in[3] * in[3];

  // Early-out: -1e-6 < lenSq < +1e-6
  if ((lenSq < _DAT_00a240ec) && (DAT_00aaa640 < lenSq)) {
    return out;
  }

  // relTol = absTol = 1e-6 (imm 0x358637BD); one = 0x3F800000
  std::uint32_t nearly = Math_FloatNearlyEqual_AbsRel(
      lenSq, 1.0f, 1e-6f, 1e-6f);

  if (nearly == 0) {
    float scale = g_flOne / std::sqrt(lenSq);
    // Machine scales *out* (callers typically pass out == in)
    out[0] = scale * out[0];
    out[1] = scale * out[1];
    out[2] = scale * out[2];
    out[3] = scale * out[3];
  } else if (out != in) {
    out[0] = in[0];
    out[1] = in[1];
    out[2] = in[2];
    out[3] = in[3];
  }
  return out;
}
