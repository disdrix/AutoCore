// =============================================================================
// FUN_007917c0  — twin of CNDUIDialog_TeardownChildHash_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_007917c0
// Address:   0x007917c0 – 0x007918e1 inclusive (290 B / 0x122)
// Wave:      WQ9L-I OWN-ONLY dual 2026-08-05
// Note:      Named implementation is the authority; this twin keeps the
//            Ghidra symbol entry point for call-graph / scaffold consumers.
// =============================================================================

#include <cstdint>

extern "C" void __fastcall CNDUIDialog_TeardownChildHash_Inferred(void *self);

extern "C" void __fastcall FUN_007917c0(void *self)
{
  CNDUIDialog_TeardownChildHash_Inferred(self);
}
