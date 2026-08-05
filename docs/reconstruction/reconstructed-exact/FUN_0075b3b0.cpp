// =============================================================================
// FUN_0075b3b0  (Ghidra twin of GfxView_SetNear_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0075b3b0
// Address:   0x0075b3b0  (autoassault.exe, image base 0x400000)
// System:    graphics / client camera (GfxView)
// Generated: 2026-07-29 W31-O (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving; bytes sealed via read_memory (28 B, RET 4).
// Canonical clean: GfxView_SetNear_Inferred.cpp
// =============================================================================

#include <cstdint>

// ECX = this; stack float; RET 4
extern "C" void __thiscall FUN_0075b3b0(uint8_t *self, float nearPlane)
{
  *reinterpret_cast<float *>(self + 0xF0) = nearPlane;
  self[0x48] = 1;
  self[0xCC] = 1;
}
