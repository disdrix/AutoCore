// =============================================================================
// FUN_0076e5e0  (twin of Math_QuatNormalize)
// -----------------------------------------------------------------------------
// Stable ID: aa_0076e5e0
// Address:   0x0076e5e0 – 0x0076e6ab  (autoassault.exe, image base 0x400000)
// System:    math / quaternion
// Dual:      W26-B 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================

#include <cstdint>
#include <cmath>

extern "C" std::uint32_t FUN_0040d450(float a, float b, float relTol, float absTol);

extern float _DAT_00a240ec;  // +1e-6
extern float DAT_00aaa640;   // -1e-6
extern float g_flOne;        // 1.0f

extern "C" float * FUN_0076e5e0(float *param_1, float *param_2)
{
  float fVar2 =
      param_2[0] * param_2[0] + param_2[1] * param_2[1] +
      param_2[2] * param_2[2] + param_2[3] * param_2[3];

  if ((fVar2 < _DAT_00a240ec) && (DAT_00aaa640 < fVar2)) {
    return param_1;
  }

  // Imm args: one=0x3F800000, tols=0x358637BD
  char cVar1 = static_cast<char>(FUN_0040d450(
      fVar2, 1.0f /*0x3f800000*/, 1e-6f /*0x358637bd*/, 1e-6f /*0x358637bd*/));

  if (cVar1 == '\0') {
    fVar2 = g_flOne / std::sqrt(fVar2);
    param_1[0] = fVar2 * param_1[0];
    param_1[1] = fVar2 * param_1[1];
    param_1[2] = fVar2 * param_1[2];
    param_1[3] = fVar2 * param_1[3];
  } else if (param_1 != param_2) {
    param_1[0] = param_2[0];
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    return param_1;
  }
  return param_1;
}
