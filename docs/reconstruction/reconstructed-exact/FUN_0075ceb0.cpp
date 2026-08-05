// =============================================================================
// FUN_0075ceb0  (Ghidra twin of GfxView_Ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0075ceb0
// Address:   0x0075ceb0  (autoassault.exe, image base 0x400000)
// System:    graphics / client camera (GfxView)
// Generated: 2026-07-29 W31-O (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving CF; constants sealed via read_memory.
// Canonical clean: GfxView_Ctor_Inferred.cpp
// =============================================================================
//
// Ghidra raw uses undefined4*; this twin uses uint32_t* / float where sealed.
// Full behavioral body lives in GfxView_Ctor_Inferred.cpp — include that for port.
//

#include <cstdint>

extern "C" void *__fastcall GfxView_Ctor_Inferred(void *self);

extern "C" void *__fastcall FUN_0075ceb0(void *self)
{
  return GfxView_Ctor_Inferred(self);
}
