// =============================================================================
// Math_QuatNearlyEqual_DoubleCover
// -----------------------------------------------------------------------------
// Stable ID: aa_00416260
// Address:   0x00416260 – 0x0041634e  (autoassault.exe, image base 0x400000)
// System:    math / quaternion compare
// Dual:      W26-A 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Quaternion nearness with double-cover acceptance (q and -q).
//   Path 1: b ≈ a on (w,x,y,z). Path 2: b ≈ -a on (w,x,y,z).
//   Each component uses Math_FloatNearlyEqual_AbsRel(relTol, absTol).
//
// ABI (machine):
//   ESI = const float *a (quat xyzw)
//   EDI = const float *b (quat xyzw)
//   stack: float relTol, float absTol
//   callee cleans with RET 8
//   returns EAX = 0 | 1
//
// CALLER:
//   FUN_008335a0 @ 0x008335da — object quats +0x590 vs +0x5e0; both tols 0.002f
// =============================================================================

#include <cstdint>

std::uint32_t Math_FloatNearlyEqual_AbsRel(float a, float b, float relTol, float absTol);

// Ghidra name: FUN_00416260
// Layout: a[0]=x, a[1]=y, a[2]=z, a[3]=w (contiguous float4; w last).
std::uint32_t Math_QuatNearlyEqual_DoubleCover(const float a[4], const float b[4],
                                               float relTol, float absTol)
{
  // Path 1: b ≈ a  (machine order w, x, y, z)
  if (Math_FloatNearlyEqual_AbsRel(b[3], a[3], relTol, absTol)
      && Math_FloatNearlyEqual_AbsRel(b[0], a[0], relTol, absTol)
      && Math_FloatNearlyEqual_AbsRel(b[1], a[1], relTol, absTol)
      && Math_FloatNearlyEqual_AbsRel(b[2], a[2], relTol, absTol)) {
    return 1;
  }

  // Path 2: b ≈ -a  (double cover of unit quaternion)
  if (Math_FloatNearlyEqual_AbsRel(b[3], 0.0f - a[3], relTol, absTol)
      && Math_FloatNearlyEqual_AbsRel(b[0], 0.0f - a[0], relTol, absTol)
      && Math_FloatNearlyEqual_AbsRel(b[1], 0.0f - a[1], relTol, absTol)
      && Math_FloatNearlyEqual_AbsRel(b[2], 0.0f - a[2], relTol, absTol)) {
    return 1;
  }

  return 0;
}

// Scaffold twin: stack formals only (ESI/EDI not portable).
extern "C" std::uint32_t FUN_00416260(float relTol, float absTol)
{
  (void)relTol;
  (void)absTol;
  return 0;
}
