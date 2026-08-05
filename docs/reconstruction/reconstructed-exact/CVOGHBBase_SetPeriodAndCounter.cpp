// READABILITY (auto CF):
//  - Body size: 19 bytes (machine-sealed).
//  - Control: one conditional store; no loops; void ret 8.
//  - Notable callees: none.
//  - Return sites: 1.

// =============================================================================
// CVOGHBBase_SetPeriodAndCounter
// -----------------------------------------------------------------------------
// Purpose:  Write period/sentinel at +0x0C; optionally mirror to counter +0x10.
//
// Address:  0x005081a0  (autoassault.exe, image base 0x400000)
// Body:     0x005081a0–0x005081b3 (19 bytes)
// Stable:   aa_005081a0
// System:   heartbeat / timed-actions
//
// Machine (read_memory 2026-07-29):
//   80 7C 24 08 00    cmp  byte [esp+8], 0
//   8B 44 24 04       mov  eax, [esp+4]
//   89 41 0C          mov  [ecx+0x0C], eax
//   74 03             jz   skip
//   89 41 10          mov  [ecx+0x10], eax
//   C2 08 00          ret  8
//
// Sentinel -1000 (0xFFFFFC18) = always-ready (combat pool). Does NOT write
// pulse period at +0x08 — Regeneration sets +0x08 (3000/5000) after this call.
//
// Exactness: CF mirrors raw + machine; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-29 residual seal
// =============================================================================

/* CVOGHBBase_SetPeriodAndCounter - write nPeriodSentinel (+0x0C) and optionally nPeriodCounter
   (+0x10).

   Parameters:
     this (ECX): CVOGHBBase*
     nPeriodSentinel: value written to +0x0C
     bAlsoSetCounter: if true (byte non-zero) also write +0x10

   Algorithm: combat pool / regen / weapon-track pass (-1000, true) for always-ready
   reschedule mode. Pulse ms at +0x08 is set by callers when needed.

   Returns: void (ret 8) */
void __thiscall CVOGHBBase_SetPeriodAndCounter(void *this, int nPeriodSentinel, bool bAlsoSetCounter)
{
  *(int *)((int)this + 0xc) = nPeriodSentinel;
  if (bAlsoSetCounter) {
    *(int *)((int)this + 0x10) = nPeriodSentinel;
  }
  return;
}
