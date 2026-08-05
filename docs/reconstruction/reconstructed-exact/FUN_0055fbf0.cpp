// =============================================================================
// FUN_0055fbf0  (twin of WorldObj_UnbindLinks_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0055fbf0
// Address:   0x0055fbf0 – 0x0055fd72
// Dual:      W26-D 2026-07-29
// See:       WorldObj_UnbindLinks_Inferred.cpp for full plate + notes
// =============================================================================

#include <cstdint>

void __thiscall WorldObj_UnbindLinks_Inferred(int manager, int obj);

extern "C" void __thiscall FUN_0055fbf0(int manager /*ECX*/, int obj /*stack*/)
{
  WorldObj_UnbindLinks_Inferred(manager, obj);
}
