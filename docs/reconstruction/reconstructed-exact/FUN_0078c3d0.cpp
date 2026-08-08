// =============================================================================
// FUN_0078c3d0  (twin of CNDUIWndBuffered_TeardownBufferedOwned_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0078c3d0
// Address:   0x0078c3d0  (autoassault.exe, image base 0x400000)
// Body:      0x0078c3d0–0x0078c47e inclusive (175 B / 0xAF)
// Wave:      WQ9L-D2 OWN-ONLY dual 2026-08-05
// Exactness: Thin twin — see CNDUIWndBuffered_TeardownBufferedOwned_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void __fastcall CNDUIWndBuffered_TeardownBufferedOwned_Inferred(void *self);

// Ghidra symbol — same body as named clean.
extern "C" void __fastcall FUN_0078c3d0(void *self)
{
  CNDUIWndBuffered_TeardownBufferedOwned_Inferred(self);
}
