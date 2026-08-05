// =============================================================================
// StdVector_Elem28_Size
// -----------------------------------------------------------------------------
// Stable ID: aa_00469c50
// Address:   0x00469c50–0x00469c70  (autoassault.exe, image base 0x400000)
// System:    containers / std::vector size helper
// Generated: dual A/B seal 2026-07-29 (W33-J); Ghidra FUN_00469c50
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Null-safe vector size for element stride 0x1c (28).
 * - Layout: begin @ +4, end @ +8 (capacity not read).
 * - ABI: ECX = vec (__fastcall / thiscall host); bare RET; size in EAX.
 * - Division: MSVC signed magic 0x92492493 for /28 (decompiler shows / 0x1c).
 * - Sibling: StdVector_DwordSize @ 0x004024b0 uses (end-begin)>>2.
 * - Name is structural Inferred; multi-domain callers (string bags + other 28-B PODs).
 * - Leaf; no callees.
 */

#include <cstdint>

// Retail: ECX=vec; bare RET; returns element count in EAX.
int __fastcall StdVector_Elem28_Size(void* vec /*ECX*/)
{
  const auto* base = reinterpret_cast<const uint8_t*>(vec);
  const int begin = *reinterpret_cast<const int*>(base + 4);
  if (begin == 0) {
    return 0;
  }
  const int end = *reinterpret_cast<const int*>(base + 8);
  return (end - begin) / 0x1c;
}
