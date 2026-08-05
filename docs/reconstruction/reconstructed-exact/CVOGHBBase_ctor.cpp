// =============================================================================
// CVOGHBBase_ctor
// -----------------------------------------------------------------------------
// Purpose:  Construct generic heartbeat/timed-action base (sizeof 0x28):
//           base vtbl, dual period zeros, dormant/stopped defaults, lastFire seed.
//
// Address:  0x00508200–0x0050822c  (autoassault.exe, image base 0x400000)
// Stable:   aa_00508200
// System:   heartbeat / timed-actions
// Body:     45 bytes; no callees; __thiscall (ECX = this)
//
// Layout (Ghidra CVOGHBBase size 40; dual residual 2026-07-29):
//   +0x00 pVTable              → PTR_FUN_009cdab0 (0x009cdab0)
//   +0x04 nRefOrFlags          = 0
//   +0x08 nPeriodMs            = 0   // real pulse (TryFire / GetRemaining)
//   +0x0C nPeriodSentinel      = 0   // SetPeriodAndCounter / Reschedule
//   +0x10 nPeriodCounter       = 0
//   +0x14 dwLastFireTickMs     = g_dwClientTickMs (0x00b041cc)
//   +0x18 pOwnerObject         = 0
//   +0x1C nTypeTag             = 0   // Ghidra nUnusedOrFlags; siblings: 1/4/8
//   +0x20 cStopped             = 0
//   +0x21 fDormant             = 1   // Start() clears; TryFire Inactive while set
//   +0x22..+0x27               NOT written (subclass / debounce / skill*)
//
// Base vtbl[1] (+0x04) = CVOGHBBase_StampLastFireTime — default OnStart.
// Subclasses replace vtbl then SetPeriod / type / AttachOwner / Start.
//
// Exactness: CF ≡ raw ≡ machine (read_memory). Names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B residual: accept sealed 2026-07-29
// =============================================================================

#include <cstdint>

struct CVOGHBBase {
    void*          pVTable;            // +0x00
    int            nRefOrFlags;        // +0x04
    int            nPeriodMs;          // +0x08  real pulse period (ms)
    int            nPeriodSentinel;    // +0x0C  SetPeriod / Reschedule
    int            nPeriodCounter;     // +0x10
    unsigned       dwLastFireTickMs;   // +0x14
    void*          pOwnerObject;       // +0x18
    int            nTypeTag;           // +0x1C  (Ghidra: nUnusedOrFlags)
    char           cStopped;           // +0x20
    bool           fDormant;           // +0x21
    // +0x22..+0x27: not initialized by this ctor
};

extern unsigned g_dwClientTickMs; // VA 0x00b041cc
extern void*    PTR_FUN_009cdab0; // base vtbl @ 0x009cdab0

/* TimedAction_ctorBase — zero/init common TimedAction fields; vtable = base.
   Sets lastFireTick(+0x14) = g_dwClientTickMs (plate: g_ActionSchedulerTickMs). */
void __thiscall CVOGHBBase_ctor(void* thisHb)
{
    auto* self = static_cast<CVOGHBBase*>(thisHb);

    self->pVTable          = &PTR_FUN_009cdab0;
    self->nTypeTag         = 0;
    self->fDormant         = true;
    self->nPeriodMs        = 0;
    self->nPeriodSentinel  = 0;
    self->nPeriodCounter   = 0;
    self->dwLastFireTickMs = g_dwClientTickMs;
    self->cStopped         = 0;
    self->pOwnerObject     = nullptr;
    self->nRefOrFlags      = 0;
    return;
}
