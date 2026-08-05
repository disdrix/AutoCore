// =============================================================================
// CVOGHBBase_Stop
// -----------------------------------------------------------------------------
// Purpose:  Disarm an armed heartbeat: set fDormant (+0x21) and tail-call
//           virtual OnEnd (vtbl+0x10). Idempotent if already dormant.
//
// Address:  0x005081d0  (autoassault.exe, image base 0x400000)
// Body:     0x005081d0–0x005081df (16 bytes)
// Stable:   aa_005081d0
// System:   heartbeat / timed-actions
//
// Does NOT: Dequeue from CVOGHBList, clear owner, SetPeriod, stamp lastFire.
// Callers may Remove/free separately after Stop.
// Ctor seeds fDormant=1; Start clears it; TryFire returns Inactive while dormant.
// Sibling Start (0x005081c0): clear dormant + tail OnStart (vtbl+4).
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 residual seal).
// =============================================================================

/* CVOGHBBase_Stop — stop receiving TryFire ticks (set dormant + OnEnd).

   Parameters:
     this (ECX): CVOGHBBase*

   Algorithm:
     if !fDormant (+0x21): set fDormant; tail-call vtable[4] OnEnd  // +0x10
     else: return

   Returns: void */

void __fastcall CVOGHBBase_Stop(CVOGHBBase *this)
{
  if (this->fDormant == false) {
    this->fDormant = true;
    /* bytes: FF 60 10 — jmp dword ptr [eax+0x10]; decompiler may warn "jumptable" */
    (**(code **)((int)this->pVTable + 0x10))();
    return;
  }
  return;
}
