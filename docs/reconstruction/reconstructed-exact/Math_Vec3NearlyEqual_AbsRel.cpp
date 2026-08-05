// =============================================================================
// Math_Vec3NearlyEqual_AbsRel
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d3f0
// Address:   0x0040d3f0 – 0x0040d44a  (autoassault.exe, image base 0x400000)
// System:    math / vec3 compare
// Dual:      W26-A 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Component-wise vec3 nearness using Math_FloatNearlyEqual_AbsRel on x,y,z.
//   Short-circuits on first failing component. Returns 1 only if all three pass.
//
// ABI (machine):
//   ESI = const float *a (vec3)
//   EDI = const float *b (vec3)
//   stack: float relTol, float absTol
//   callee cleans with RET 8
//   returns EAX = 0 | 1
//   leaf of callees: only FUN_0040d450
//
// CALLER:
//   FUN_0090f490 @ 0x0090f625 — live pos vs cached pos; both tols ≈ 1e-6
// =============================================================================

#include <cstdint>

// Declared in Math_FloatNearlyEqual_AbsRel.cpp (aa_0040d450)
std::uint32_t Math_FloatNearlyEqual_AbsRel(float a, float b, float relTol, float absTol);

// Ghidra name: FUN_0040d3f0
// Note: retail passes a/b in ESI/EDI; this C form is a readable restatement.
std::uint32_t Math_Vec3NearlyEqual_AbsRel(const float a[3], const float b[3],
                                          float relTol, float absTol)
{
  // Machine: NearlyEqual(*edi, *esi, rel, abs) — b first, a second
  if (!Math_FloatNearlyEqual_AbsRel(b[0], a[0], relTol, absTol)) {
    return 0;
  }
  if (!Math_FloatNearlyEqual_AbsRel(b[1], a[1], relTol, absTol)) {
    return 0;
  }
  if (!Math_FloatNearlyEqual_AbsRel(b[2], a[2], relTol, absTol)) {
    return 0;
  }
  return 1;
}

// Scaffold twin entry (Ghidra symbol) — stack formals only; register ptrs are
// not expressible in portable C without a custom calling-convention attribute.
extern "C" std::uint32_t FUN_0040d3f0(float relTol, float absTol)
{
  // Intentionally incomplete for portable C: ESI/EDI must be set by caller.
  // Prefer Math_Vec3NearlyEqual_AbsRel for ports.
  (void)relTol;
  (void)absTol;
  return 0;
}
