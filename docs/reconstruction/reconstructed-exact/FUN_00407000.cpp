// =============================================================================
// FUN_00407000  (twin of StdVector_UninitializedFillN_Elem0x10_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00407000
// Address:   0x00407000  (autoassault.exe, image base 0x400000)
// Body:      0x00407000–0x0040701d (29 B / 0x1d); ret 4
// System:    util / container (std::vector uninitialized_fill_n, POD stride 0x10)
// Generated: 2026-08-05 R10-007 dual seal (refreshed from 2026-07-23 scaffold)
// Exactness: Behavior-preserving reconstruction. Not modernization.
// Dual A/B: accept-with-gaps (2026-08-05).
// Canonical: StdVector_UninitializedFillN_Elem0x10_Inferred
// =============================================================================

#include <cstdint>

struct Pod16 {
  uint32_t d0, d1, d2, d3;
};

extern "C" void FUN_00409e20(Pod16* dest, int count /*, ECX = const Pod16* value */);

// Ghidra symbol twin — prefer named clean for ports.
extern "C" Pod16* FUN_00407000(
    Pod16* dest /*EDI*/,
    int count /*ESI*/,
    const Pod16* value /*stack*/)
{
  (void)value;
  FUN_00409e20(dest, count);
  return reinterpret_cast<Pod16*>(reinterpret_cast<char*>(dest) + count * 0x10);
}
