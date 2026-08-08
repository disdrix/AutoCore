// =============================================================================
// FUN_00409db0  (scaffold twin of StdVector_ConstructN_Elem12_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409db0
// Address:   0x00409db0  (autoassault.exe, image base 0x400000)
// Body:      0x00409db0–0x00409e12 (99 B / 0x63); plain ret C3
// System:    util / container (std::vector construct-N, POD stride 0x0C)
// Generated: 2026-08-05 WQ9I-A — points at named clean
// Exactness: Behavior-preserving. Not modernization. Bit-for-bit DEFERRED.
// Dual A/B: accept-with-gaps (2026-08-05).
// Canonical clean: StdVector_ConstructN_Elem12_Inferred.cpp
// =============================================================================

#include <cstdint>

struct Pod0x0C {
  uint32_t d[3];
};

extern "C" void FUN_00409f50(/*EAX*/ Pod0x0C* dst, /*ECX*/ const Pod0x0C* src);

// ECX = value*; stack dest, count; plain ret
extern "C" void FUN_00409db0(
    /*ECX*/ const Pod0x0C* value,
    Pod0x0C* dest,
    int count)
{
  for (; count != 0; --count) {
    FUN_00409f50(dest, value);
    dest = reinterpret_cast<Pod0x0C*>(reinterpret_cast<char*>(dest) + 0x0C);
  }
}
