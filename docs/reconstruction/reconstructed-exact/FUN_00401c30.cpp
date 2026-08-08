// =============================================================================
// FUN_00401c30 — clean twin of StdVector_DwordSize_EaxVec_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00401c30
// Address:   0x00401c30–0x00401c42  (autoassault.exe, image base 0x400000)
// Canonical: StdVector_DwordSize_EaxVec_Inferred
// Generated: MEGA-082 dual A/B seal 2026-08-05
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Machine twin kept under Ghidra name for path stability.
 * Prefer StdVector_DwordSize_EaxVec_Inferred.cpp for ports.
 *
 * ABI: EAX = vec; bare RET; size in EAX.
 * Formula: begin@+4 null → 0; else (end@+8 - begin) >> 2.
 */

#include <cstdint>

int FUN_00401c30(void* vec /*EAX*/)
{
  const auto* base = reinterpret_cast<const uint8_t*>(vec);
  const int begin = *reinterpret_cast<const int*>(base + 4);
  if (begin == 0) {
    return 0;
  }
  const int end = *reinterpret_cast<const int*>(base + 8);
  return (end - begin) >> 2;
}
