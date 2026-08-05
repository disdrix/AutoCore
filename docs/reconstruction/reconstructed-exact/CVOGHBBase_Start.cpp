// =============================================================================
// CVOGHBBase_Start
// -----------------------------------------------------------------------------
// Purpose:  Arm a dormant heartbeat: clear fDormant (+0x21) and tail-call
//           virtual OnStart (vtbl+4). Idempotent if already armed.
//
// Address:  0x005081c0  (autoassault.exe, image base 0x400000)
// Body:     0x005081c0–0x005081cf (16 bytes)
// Stable:   aa_005081c0
// System:   heartbeat / timed-actions
//
// Does NOT: Enqueue into CVOGHBList, AttachOwner, SetPeriod, stamp lastFire.
// Callers typically: Enqueue(map+0xe4ec / list) then Start (e.g. cast-again).
// Ctor seeds fDormant=1; TryFire returns Inactive while dormant.
// Sibling Stop (0x005081d0): set dormant + tail OnEnd (vtbl+0x10).
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 residual seal).
// =============================================================================

/* CVOGHBBase_Start — begin receiving TryFire ticks (clear dormant + OnStart).

   Parameters:
     this (ECX): CVOGHBBase*

   Algorithm:
     if fDormant (+0x21): clear fDormant; tail-call vtable[1] OnStart
     else: return

   Returns: void */

void __fastcall CVOGHBBase_Start(CVOGHBBase *this)
{
  if (this->fDormant != false) {
    this->fDormant = false;
    /* bytes: FF 60 04 — jmp dword ptr [eax+4]; decompiler may warn "jumptable" */
    (**(code **)((int)this->pVTable + 4))();
    return;
  }
  return;
}
