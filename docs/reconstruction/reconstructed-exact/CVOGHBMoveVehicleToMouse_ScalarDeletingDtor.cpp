// =============================================================================
// CVOGHBMoveVehicleToMouse_ScalarDeletingDtor  (aa_005996a0)
// -----------------------------------------------------------------------------
// Purpose:  MSVC scalar-deleting destructor for CVOGHBMoveVehicleToMouse
//           (vtbl[0] of PTR_FUN_009d5590): always run complete/body dtor
//           FUN_00599570, then optionally operator_delete when (flags & 1).
//
// Address:  0x005996a0–0x005996bd inclusive (30 B / 0x1E)
//            autoassault.exe, image base 0x400000
// Stable:   aa_005996a0
// Ghidra:   FUN_005996a0
// System:   input-drive-control / heartbeat MoveVehicleToMouse lifecycle
// Wave:     R12-028 OWN-ONLY dual 2026-08-05
//
// ABI:      __thiscall — ECX = this; stack uint8_t flags; ret 4; EAX = this
// Complete: FUN_00599570 @ 0x00599570 (restore PTR_FUN_009d5590; chain
//           FUN_00636b90 / MoveVehicle complete). Residual dual.
// RTTI:     .?AVCVOGHBMoveVehicleToMouse@@  (type_info @ 0x00af33e0)
// Vtbl:     PTR_FUN_009d5590 dword0 only (base MoveVehicle uses 0x00636d10)
// Exactness: CF ≡ raw ≡ live decompile ≡ full-body read_memory.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (R12-028). Never Runtime Confirmed.
// =============================================================================

#include <cstdint>

// ToMouse complete/body dtor: *this = &PTR_FUN_009d5590; chain FUN_00636b90.
// Does not free this. Residual (not dualed in R12-028 OWN).
extern "C" void __fastcall FUN_00599570(void *self); // 0x00599570

extern "C" void __cdecl operator_delete(void *p);

/* CVOGHBMoveVehicleToMouse_ScalarDeletingDtor — vtbl[0] scalar deleting dtor.

   Parameters:
     self:  CVOGHBMoveVehicleToMouse* in ECX
     flags: bit0 = 1 → heap free via operator_delete

   Algorithm:
     1) FUN_00599570(self)   // complete/body
     2) if (flags & 1): operator_delete(self)
     3) return self

   Returns: this pointer (EAX) */

extern "C" void *__thiscall CVOGHBMoveVehicleToMouse_ScalarDeletingDtor(
    void *self /* ECX */,
    uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_00599570(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
    // machine: ADD ESP, 4 after cdecl delete
  }

  return self;
}
