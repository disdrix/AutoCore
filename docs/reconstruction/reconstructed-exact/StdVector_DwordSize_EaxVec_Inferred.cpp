// =============================================================================
// StdVector_DwordSize_EaxVec_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00401c30
// Address:   0x00401c30–0x00401c42  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00401c30
// System:    containers / shared dword-vector size helper
// Generated: MEGA-082 dual A/B seal 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Null-safe vector size for element stride 4 (dword / pointer).
 * - Layout: begin @ +4, end @ +8 (capacity not read).
 * - ABI: EAX = vec (register-arg); bare RET (C3); size in EAX.
 * - Distinct from dualed StdVector_DwordSize @ 0x004024b0 (ECX = vec, same formula).
 * - Multi-domain callers (UI list scroll, char-create vehicle panel case 0x9c45, ptr tables).
 * - Retire Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_00401c30
 *   (plate-parent seed only; this leaf is not product-string-specific).
 * - Leaf; no callees.
 * - Name structural _Inferred: product element type English open.
 */

#include <cstdint>

// Retail: EAX=vec; bare RET; returns element count in EAX.
int StdVector_DwordSize_EaxVec_Inferred(void* vec /*EAX*/)
{
  const auto* base = reinterpret_cast<const uint8_t*>(vec);
  const int begin = *reinterpret_cast<const int*>(base + 4);
  if (begin == 0) {
    return 0;
  }
  const int end = *reinterpret_cast<const int*>(base + 8);
  return (end - begin) >> 2;
}
