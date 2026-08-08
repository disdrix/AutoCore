// =============================================================================
// FUN_00636d10  — twin of CVOGHBMoveVehicle_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00636d10
// Address:   0x00636d10–0x00636d2d inclusive (30 B / 0x1E)
//            autoassault.exe, image base 0x400000
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; R11-024 dual refresh 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + machine CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B: accept (R11-024) — see CVOGHBMoveVehicle_ScalarDeletingDtor.cpp
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_00636b90(void *self);
extern "C" void __cdecl operator_delete(void *p);

// Canonical: CVOGHBMoveVehicle_ScalarDeletingDtor
// MSVC scalar-deleting dtor — vtbl[0] of PTR_FUN_009e3b70.
// thiscall ECX=this; stack flags; RET 4; EAX=this.
// Complete body FUN_00636b90; free if (flags & 1).

extern "C" void *__thiscall FUN_00636d10(void *param_1 /* ECX */, uint8_t param_2)
{
  FUN_00636b90(param_1);

  if ((param_2 & 1u) != 0u) {
    operator_delete(param_1);
  }

  return param_1;
}
