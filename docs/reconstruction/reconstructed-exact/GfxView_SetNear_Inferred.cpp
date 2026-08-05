// =============================================================================
// GfxView_SetNear_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0075b3b0
// Address:   0x0075b3b0  (autoassault.exe, image base 0x400000)
// System:    graphics / client camera (GfxView)
// Generated: 2026-07-29 W31-O (OWN-ONLY dual A/B)
// Exactness: Behavior-preserving rewrite of decompiler + full-body read_memory.
// Bit-for-bit vs retail EXE: DEFERRED (not run).
// =============================================================================
//
// PURPOSE: Set GfxView near plane and mark projection dirty.
//
// ABI: __thiscall — ECX = GfxView*; stack float near; RET 4.
// Body: 0x0075b3b0–0x0075b3cb (28 B). Full hex:
//   f30f10442404 b001 f30f1181f0000000 884148 8881cc000000 c20400
//
// Layout:
//   +0xF0 float near
//   +0x48 uint8  proj dirty (EnsureProjection gate)
//   +0xCC uint8  aux dirty
//
// Polarity twin: FUN_0075b390 stores far at +0xF4 (same dirty pair).
// Callers: FUN_004cda90 (0.5f), FUN_004c0a90, FUN_0055ca90 (~0.2f), FUN_005b3420.
//

#include <cstdint>

struct GfxView_Partial {
  uint8_t  _pad_000[0x48];
  uint8_t  projDirty;       // +0x48
  uint8_t  _pad_049[0x83];  // to +0xCC
  uint8_t  auxDirty;        // +0xCC
  uint8_t  _pad_0CD[0x23];  // to +0xF0
  float    nearPlane;       // +0xF0
};

// Retail: void __thiscall FUN_0075b3b0(int this, undefined4 nearBits)
extern "C" void __thiscall GfxView_SetNear_Inferred(GfxView_Partial *self, float nearPlane)
{
  self->nearPlane = nearPlane;
  self->projDirty = 1;
  self->auxDirty  = 1;
}

// Ghidra twin symbol
extern "C" void __thiscall FUN_0075b3b0(GfxView_Partial *self, float nearPlane)
{
  GfxView_SetNear_Inferred(self, nearPlane);
}
