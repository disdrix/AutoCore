// =============================================================================
// FUN_00416260 — twin of Math_QuatNearlyEqual_DoubleCover
// -----------------------------------------------------------------------------
// Stable ID: aa_00416260
// Address:   0x00416260 – 0x0041634e  (autoassault.exe, image base 0x400000)
// System:    math / quaternion compare
// Dual:      W26-A 2026-07-29
// Exactness: Behavior-preserving rewrite. Not bit-exact certified.
// =============================================================================
//
// See Math_QuatNearlyEqual_DoubleCover.cpp for full plate + ABI notes.
// Machine ABI: ESI=a, EDI=b, stack relTol/absTol, RET 8, EAX 0|1.
// =============================================================================

#include <cstdint>

std::uint32_t Math_FloatNearlyEqual_AbsRel(float a, float b, float relTol, float absTol);

// Readable restatement of decompiler CF (pointers as C formals).
std::uint32_t FUN_00416260_body(const float *a, const float *b, float relTol, float absTol)
{
  char cVar1;

  cVar1 = (char)Math_FloatNearlyEqual_AbsRel(b[3], a[3], relTol, absTol);
  if ((((cVar1 != '\0') &&
        (cVar1 = (char)Math_FloatNearlyEqual_AbsRel(b[0], a[0], relTol, absTol), cVar1 != '\0')) &&
       (cVar1 = (char)Math_FloatNearlyEqual_AbsRel(b[1], a[1], relTol, absTol), cVar1 != '\0')) &&
      (cVar1 = (char)Math_FloatNearlyEqual_AbsRel(b[2], a[2], relTol, absTol), cVar1 != '\0')) {
    return 1;
  }

  cVar1 = (char)Math_FloatNearlyEqual_AbsRel(b[3], 0.0f - a[3], relTol, absTol);
  if (((cVar1 != '\0') &&
       (cVar1 = (char)Math_FloatNearlyEqual_AbsRel(b[0], 0.0f - a[0], relTol, absTol), cVar1 != '\0')) &&
      ((cVar1 = (char)Math_FloatNearlyEqual_AbsRel(b[1], 0.0f - a[1], relTol, absTol), cVar1 != '\0') &&
       (cVar1 = (char)Math_FloatNearlyEqual_AbsRel(b[2], 0.0f - a[2], relTol, absTol), cVar1 != '\0'))) {
    return 1;
  }

  return 0;
}
