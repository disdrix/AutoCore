// =============================================================================
// FUN_00754480 — Ghidra-name twin of Palantir_ResetDevice
// -----------------------------------------------------------------------------
// Stable ID: aa_00754480
// Address:   0x00754480–0x007544E0 exclusive (96 B)
// Wave:      W35-K OWN-ONLY 2026-07-29
// See:       Palantir_ResetDevice.cpp for full sealed reconstruction.
// =============================================================================

#include <cstdint>

struct Palantir;

extern "C" int __fastcall Palantir_ResetDevice(Palantir* self);

extern "C" int __fastcall FUN_00754480(Palantir* self)
{
  return Palantir_ResetDevice(self);
}
