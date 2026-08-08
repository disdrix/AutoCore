// =============================================================================
// CVOGHBMoveVehicle_ScalarDeletingDtor  (aa_00636d10)
// -----------------------------------------------------------------------------
// Purpose:  MSVC scalar-deleting destructor for CVOGHBMoveVehicle (vtbl[0] of
//           PTR_FUN_009e3b70): always run complete/body dtor FUN_00636b90,
//           then optionally operator_delete when (flags & 1).
//
// Address:  0x00636d10–0x00636d2d inclusive (30 B / 0x1E)
//            autoassault.exe, image base 0x400000
// Stable:   aa_00636d10
// Ghidra:   FUN_00636d10
// System:   input-drive-control / heartbeat MoveVehicle lifecycle
// Wave:     R11-024 OWN-ONLY dual 2026-08-05
//
// ABI:      __thiscall — ECX = this; stack uint8_t flags; ret 4; EAX = this
// Complete: FUN_00636b90 @ 0x00636b90 (restore PTR_FUN_009e3b70; chain
//           FUN_00508390 / CVOGHBBase complete dtor). Residual dual.
// RTTI:     .?AVCVOGHBMoveVehicle@@  (type_info @ 0x00af33c0)
// Vtbl:     PTR_FUN_009e3b70 dword0 only (ToMouse uses 0x005996a0)
// Exactness: CF ≡ raw ≡ live decompile ≡ full-body read_memory.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (R11-024).
// =============================================================================

#include <cstdint>

// Complete/body dtor: *this = &PTR_FUN_009e3b70; chain CVOGHBBase dtor.
// Does not free this. Residual (not dualed in R11-024 OWN).
extern "C" void __fastcall FUN_00636b90(void *self); // 0x00636b90

extern "C" void __cdecl operator_delete(void *p);

/* CVOGHBMoveVehicle_ScalarDeletingDtor — vtbl[0] scalar deleting dtor.

   Parameters:
     self:  CVOGHBMoveVehicle* in ECX
     flags: bit0 = 1 → heap free via operator_delete

   Algorithm:
     1) FUN_00636b90(self)   // complete/body
     2) if (flags & 1): operator_delete(self)
     3) return self

   Returns: this pointer (EAX) */

extern "C" void *__thiscall CVOGHBMoveVehicle_ScalarDeletingDtor(
    void *self /* ECX */,
    uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_00636b90(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
    // machine: ADD ESP, 4 after cdecl delete
  }

  return self;
}
