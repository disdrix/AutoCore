// =============================================================================
// FUN_0043c660  (twin of GuardedVector_ClearAndSwap)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c660
// Address:   0x0043c660–0x0043c6e8  (autoassault.exe, image base 0x400000)
// Dual:      W29-A 2026-07-29
// Prefer:    GuardedVector_ClearAndSwap.cpp for named plate
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

// Prefer named clean: docs/reconstruction/reconstructed-exact/GuardedVector_ClearAndSwap.cpp

// Retail: ESI=A, EDI=B (optional CS at EDI+0x14, flag EDI+0x2c).
// Clear A via FUN_0043c7e0 (EAX=ESI, ECX=0), then swap +4/+8/+0xc/+0x10.

void FUN_0043c660(void /* ESI, EDI */)
{
  // See GuardedVector_ClearAndSwap.cpp for sealed body.
}
