// =============================================================================
// FUN_00406e50 — scaffold alias
// Named plate: StdVector_UninitializedFillN_Elem0x28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00406e50
// Address:   0x00406e50  (autoassault.exe, image base 0x400000)
// Body:      0x00406e50–0x00406e6c (28 B / 0x1c); ret 4
// Dual A/B:  accept-with-gaps (2026-08-04 WQ9G-H)
// See:       StdVector_UninitializedFillN_Elem0x28_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void FUN_00409d40(
    /*ECX*/ const void* value,
    /*stack*/ void* dest,
    /*stack*/ int count);

// Decompiler lost EDI=dst / ESI=count; recovered ABI in named plate.
extern "C" void* FUN_00406e50(const void* value)
{
  void* dst = nullptr; // EDI
  int count = 0;       // ESI
  (void)value;
  FUN_00409d40(value, dst, count);
  return reinterpret_cast<uint8_t*>(dst) + static_cast<size_t>(count) * 0x28u;
}
