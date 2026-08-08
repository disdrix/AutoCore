// =============================================================================
// FUN_005996a0  — twin of CVOGHBMoveVehicleToMouse_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_005996a0
// Address:   0x005996a0–0x005996bd inclusive (30 B / 0x1E)
//            autoassault.exe, image base 0x400000
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; R12-028 dual refresh 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + machine CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B: accept (R12-028) — see CVOGHBMoveVehicleToMouse_ScalarDeletingDtor.cpp
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_00599570(void *self);
extern "C" void __cdecl operator_delete(void *p);

// Canonical: CVOGHBMoveVehicleToMouse_ScalarDeletingDtor
// MSVC scalar-deleting dtor — vtbl[0] of PTR_FUN_009d5590.
// thiscall ECX=this; stack flags; RET 4; EAX=this.
// Complete body FUN_00599570; free if (flags & 1).

extern "C" void *__thiscall FUN_005996a0(void *param_1 /* ECX */, uint8_t param_2)
{
  FUN_00599570(param_1);

  if ((param_2 & 1u) != 0u) {
    operator_delete(param_1);
  }

  return param_1;
}
