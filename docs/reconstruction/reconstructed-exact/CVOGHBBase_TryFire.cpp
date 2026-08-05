// =============================================================================
// CVOGHBBase_TryFire
// -----------------------------------------------------------------------------
// Purpose:  Per-tick decision for a heartbeat action: whether to run virtual
//           OnHeartBeat (vtable+0x0C) this frame and what EHBStatus to return.
//
// Address:  0x005082c0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005082c0
// System:   client heartbeat / timed actions
//
// Convention: MSVC __thiscall (decomp may show __fastcall)
//   this        CVOGHBBase*  (ECX)
//   pOutStatus  EHBStatus* on stack — Continue=0, Inactive=2, Remove=0x10
//   returns     pOutStatus; ret 4
//
// Algorithm (machine-sealed 2026-07-29):
//   if cStopped (+0x20):
//       *out = Remove   (g_dwTimedActionDefaultPeriodMs == 16)
//   else if nPeriodMs (+0x08) == -1000:
//       *out = Continue   // suppress period-based fire (NOT "always fire")
//   else if elapsed > nPeriodMs OR tick wrapped (lastFire > tick):
//       if fDormant (+0x21): *out = Inactive (2)
//       else:
//           status = *vtable[3] OnHeartBeat()
//           dwLastFireTickMs (+0x14) = g_dwClientTickMs   // inlined stamp
//           *out = status
//   else:
//       *out = Continue
//
// Dual-field period model (siblings):
//   +0x08 nPeriodMs       — pulse period; TryFire / GetRemaining consume
//   +0x0C nPeriodSentinel — SetPeriodAndCounter / RescheduleAfterFire
//   Combat pool (Regeneration_ctor): SetPeriodAndCounter(-1000,true) then
//   write real 3000/5000 ms at +0x08. Interval is TryFire vs +0x08, NOT 16.
//
// NOTE: value 16 is Remove status / list delay token, NOT combat-pool period.
//
// Exactness: Control flow + offsets from read_memory body. Decompiler confuses
// pOutStatus / unaff_retaddr — both are the stack out-param.
// Seal: 2026-07-29 dual A/B residual (prior 2026-07-23 plate corrected)
// =============================================================================

#include <cstdint>

// EHBStatus (values used by this unit + List_Tick Remove mask)
//   Continue = 0
//   Inactive = 2
//   Remove   = 0x10  (same numeric value as g_dwTimedActionDefaultPeriodMs = 16)

struct CVOGHBBase {
    void*          pVTable;           // +0x00
    // +0x04 …
    int            nPeriodMs;         // +0x08  pulse period (ms); -1000 → no period fire
    int            nPeriodSentinel;   // +0x0C  SetPeriod/Reschedule (not read here)
    int            nPeriodCounter;    // +0x10  (not read here)
    unsigned       dwLastFireTickMs;  // +0x14
    // +0x18 …
    char           cStopped;          // +0x20  stopped → Remove
    bool           fDormant;          // +0x21  true until Start()
};

extern unsigned g_dwClientTickMs;                 // 0x00b041cc
extern unsigned g_dwTimedActionDefaultPeriodMs;   // 0x00af19e8 = 16 (Remove token)
extern unsigned g_dwHBStatusInactive;             // 0x00af19e4 = 2
extern unsigned g_dwHBStatusContinue;             // 0x00b041d0 = 0

// +0x08 sentinel: suppress period-based OnHeartBeat (Continue only)
static constexpr int kPeriodSuppressFire = -1000; // 0xFFFFFC18

unsigned* /* pOutStatus */ __thiscall CVOGHBBase_TryFire(
    CVOGHBBase* pThis,
    unsigned*   pOutStatus)
{
    if (pThis->cStopped != '\0') {
        *pOutStatus = g_dwTimedActionDefaultPeriodMs; // Remove (16)
        return pOutStatus;
    }

    // If pulse period is -1000, skip fire path entirely (Continue).
    // Combat-pool regen does NOT use this: it keeps real ms at +0x08.
    if (pThis->nPeriodMs == kPeriodSuppressFire) {
        *pOutStatus = g_dwHBStatusContinue; // 0
        return pOutStatus;
    }

    const unsigned tick    = g_dwClientTickMs;
    const unsigned lastFire = pThis->dwLastFireTickMs;
    const unsigned elapsed = tick - lastFire;
    const bool     wrapped = lastFire > tick;

    if ((unsigned)pThis->nPeriodMs < elapsed || wrapped) {
        if (pThis->fDormant) {
            *pOutStatus = g_dwHBStatusInactive; // 2
            return pOutStatus;
        }

        // vtable+0x0C = OnHeartBeat → returns EHBStatus*
        using OnHeartBeatFn = unsigned* (__thiscall*)(CVOGHBBase*);
        auto* const pFn =
            *reinterpret_cast<OnHeartBeatFn*>(
                reinterpret_cast<std::uint8_t*>(pThis->pVTable) + 0x0C);
        unsigned* pStatusFromHb = pFn(pThis);
        const unsigned status = *pStatusFromHb;

        pThis->dwLastFireTickMs = g_dwClientTickMs; // inline stamp (not helper call)
        *pOutStatus = status;
        return pOutStatus;
    }

    *pOutStatus = g_dwHBStatusContinue; // 0
    return pOutStatus;
}
