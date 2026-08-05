// =============================================================================
// FUN_0040d3f0 — twin of Math_Vec3NearlyEqual_AbsRel
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d3f0
// Address:   0x0040d3f0 – 0x0040d44a  (autoassault.exe, image base 0x400000)
// System:    math / vec3 compare
// Dual:      W26-A 2026-07-29
// Exactness: Behavior-preserving rewrite. Not bit-exact certified.
// =============================================================================
//
// See Math_Vec3NearlyEqual_AbsRel.cpp for full plate + ABI notes.
// Machine ABI: ESI=a, EDI=b, stack relTol/absTol, RET 8, EAX 0|1.
// =============================================================================

#include <cstdint>

std::uint32_t Math_FloatNearlyEqual_AbsRel(float a, float b, float relTol, float absTol);

// Readable restatement of decompiler CF (pointers as C formals).
std::uint32_t FUN_0040d3f0_body(const float *a, const float *b, float relTol, float absTol)
{
  char cVar1;

  cVar1 = (char)Math_FloatNearlyEqual_AbsRel(b[0], a[0], relTol, absTol);
  if (cVar1 != '\0') {
    cVar1 = (char)Math_FloatNearlyEqual_AbsRel(b[1], a[1], relTol, absTol);
    if (cVar1 != '\0') {
      cVar1 = (char)Math_FloatNearlyEqual_AbsRel(b[2], a[2], relTol, absTol);
      if (cVar1 != '\0') {
        return 1;
      }
    }
  }
  return 0;
}
