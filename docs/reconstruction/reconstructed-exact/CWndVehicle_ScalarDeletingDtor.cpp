// =============================================================================
// CWndVehicle_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004160d0
// Address:   0x004160d0–0x004160ee exclusive (30 B / 0x1E, autoassault.exe base 0x400000)
// System:    CWndVehicle / MSVC scalar-deleting destructor
// Generated: 2026-08-05 WQ9I-F dual A/B (decompile + read_memory + RTTI)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004160d0
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for CWndVehicle (vtbl[0] of PTR_FUN_00a6fbcc).
//   RTTI COL 0x00ab5d3c → .?AVCWndVehicle@@. Always runs complete dtor
//   FUN_00834520. If (flags & 1), operator_delete the host. Returns this; ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags; ret 4; returns this*.
//   Entry: 56 8B F1 …
//   Exit:  8B C6 5E C2 04 00
//
// TWINS / RELATED:
//   FUN_00834520  — complete dtor (installs PTR_FUN_00a6fbcc + teardown)
//   FUN_008345c0  — ctor (same vtbl after CNDUIWndBuffered base)
//   aa_004160f0   — CWidgetRotateVehicle_ScalarDeletingDtor (sibling OWN WQ9I-F)
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_00834520(void* self);  // CWndVehicle complete dtor
extern "C" void operator_delete(void* p);

// Machine: void* __thiscall FUN_004160d0(void* this, uint8_t flags)
extern "C" void* __thiscall CWndVehicle_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_00834520(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}
