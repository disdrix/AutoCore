// =============================================================================
// Math_FloatNearlyEqual_AbsRel
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d450
// Address:   0x0040d450 – 0x0040d4ac  (autoassault.exe, image base 0x400000)
// System:    math / float compare
// Dual:      W25-T 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Combined absolute + relative nearness test for two floats.
//   Returns true when |a-b| <= absTol, OR when |a-b| <= max(|a|,|b|)*relTol.
//   Returns false only when both thresholds are exceeded.
//
//   Callers:
//     FUN_0040d3f0  — vec3 component-wise nearness
//     FUN_00416260  — quaternion nearness (q and -q paths)
//     FUN_0076e5e0  — skip quat normalize when lenSq ≈ 1.0 (eps ~1e-6)
//     FUN_0076f240  — same family
//
// ABI (machine):
//   cdecl; 4 stack floats (a, b, relTol, absTol)
//   prologue PUSH ECX (scratch); epilogue POP ECX; RET
//   returns EAX = 0 | 1
// =============================================================================

#include <cstdint>
#include <cmath>

// Ghidra name: FUN_0040d450
std::uint32_t Math_FloatNearlyEqual_AbsRel(float a, float b, float relTol, float absTol)
{
  float diff = a - b;
  if (absTol < std::fabs(diff)) {
    // Decompiler rewrites stack slots to hold abs(b) and abs(a), then
    // selects a pointer to max(|a|,|b|).
    float abs_b = std::fabs(b);
    float abs_a = std::fabs(a);
    float maxAbs = (abs_a <= abs_b) ? abs_b : abs_a;
    if (maxAbs * relTol < std::fabs(diff)) {
      return 0;
    }
  }
  return 1;
}

// Scaffold twin entry (Ghidra symbol)
extern "C" std::uint32_t FUN_0040d450(float a, float b, float relTol, float absTol)
{
  return Math_FloatNearlyEqual_AbsRel(a, b, relTol, absTol);
}
