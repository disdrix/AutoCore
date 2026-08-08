// =============================================================================
// FUN_00599550  — twin of CVOGHBMoveVehicleToMouse_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_00599550
// Address:   0x00599550–0x0059956f inclusive (32 B / 0x20)
//            autoassault.exe, image base 0x400000
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; R13-007 dual refresh 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + machine CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B: accept-with-gaps (R13-007) — see CVOGHBMoveVehicleToMouse_ctor.cpp
// =============================================================================

#include <cstdint>

extern "C" void *__thiscall FUN_00636bd0(void *self, void *pEntity);
extern void *PTR_FUN_009d5590;

// Canonical: CVOGHBMoveVehicleToMouse_ctor
// thiscall ECX=this; stack pEntity, pHostCtx; RET 8; EAX=this.
// Base MoveVehicle ctor then install ToMouse vtbl; store pHostCtx at +0x40.

extern "C" void *__thiscall FUN_00599550(
    void *param_1 /* ECX */,
    void *param_2 /* pEntity */,
    void *param_3 /* pHostCtx → +0x40 */)
{
  FUN_00636bd0(param_1, param_2);

  *reinterpret_cast<void **>(param_1) = &PTR_FUN_009d5590;
  *reinterpret_cast<void **>(reinterpret_cast<char *>(param_1) + 0x40) = param_3;

  return param_1;
}
