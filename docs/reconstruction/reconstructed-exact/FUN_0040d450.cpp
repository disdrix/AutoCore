// =============================================================================
// FUN_0040d450  (scaffold twin of Math_FloatNearlyEqual_AbsRel)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d450
// Address:   0x0040d450 – 0x0040d4ac  (autoassault.exe, image base 0x400000)
// System:    math / float compare
// Dual:      W25-T 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================

#include <cstdint>
#include <cmath>

// cdecl; EAX = 0|1
std::uint32_t FUN_0040d450(float param_1, float param_2, float param_3, float param_4)
{
  float fVar1;
  float *pfVar2;

  fVar1 = param_1 - param_2;
  if (param_4 < std::fabs(fVar1)) {
    pfVar2 = &param_2;
    param_4 = std::fabs(param_2);
    param_2 = std::fabs(param_1);
    if (std::fabs(param_1) <= param_4) {
      pfVar2 = &param_4;
    }
    if (*pfVar2 * param_3 < std::fabs(fVar1)) {
      return 0;
    }
  }
  return 1;
}
