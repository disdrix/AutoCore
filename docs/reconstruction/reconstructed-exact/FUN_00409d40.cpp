// =============================================================================
// FUN_00409d40  (scaffold twin — prefer named clean)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409d40
// Named:     StdVector_ConstructN_Elem0x28_Inferred
// Address:   0x00409d40
// Dual:      WQ9H-B 2026-08-04 accept-with-gaps
// =============================================================================

#include <cstdint>

struct Pod0x28 { uint32_t d[10]; };

extern "C" void FUN_00409f30(Pod0x28* dst, const Pod0x28* src);

// Ghidra-facing name alias of StdVector_ConstructN_Elem0x28_Inferred
extern "C" void FUN_00409d40(const Pod0x28* value /*ECX*/, Pod0x28* dest, int count)
{
  for (; count != 0; --count) {
    FUN_00409f30(dest, value);
    dest = reinterpret_cast<Pod0x28*>(reinterpret_cast<char*>(dest) + 0x28);
  }
}
