// =============================================================================
// CVOGHBBase_StampLastFireTime
// -----------------------------------------------------------------------------
// Purpose:  Write dwLastFireTickMs (+0x14) = g_dwClientTickMs (manual / vtbl stamp).
//
// Address:  0x00508270  (autoassault.exe, image base 0x400000)
// Body:     0x00508270–0x00508278 (9 bytes)
// Stable:   aa_00508270
// System:   heartbeat / timed-actions
//
// Machine:
//   A1 CC41B000    mov  eax, [g_dwClientTickMs]   ; 0x00b041cc
//   89 41 14       mov  [ecx+0x14], eax
//   C3             ret
//
// TryFire inlines the same store after successful OnHeartBeat (does not call here).
// Named callers: CVOGHBOKToCastAgain_OnStart (tail), FUN_00578b30 (×2).
//
// Exactness: CF mirrors raw ≡ machine; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept sealed 2026-07-29
// =============================================================================

void __fastcall CVOGHBBase_StampLastFireTime(CVOGHBBase *this)
{
  this->dwLastFireTickMs = g_dwClientTickMs;
  return;
}
