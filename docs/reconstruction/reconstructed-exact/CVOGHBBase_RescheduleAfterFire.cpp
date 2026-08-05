// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: CVOGHBBase_RescheduleAfterFire, g_dwTimedActionDefaultPeriodMs, pOutNextDelayMs, pThis.
//  - Return sites: 3.

// =============================================================================
// CVOGHBBase_RescheduleAfterFire
// -----------------------------------------------------------------------------
// Purpose:  After OnHeartBeat: write next delay / stamp last-fire and re-arm period so
//           list tick waits nPeriodMs (or combat-pool sentinel handling).
//
// Address:  0x00508350  (autoassault.exe, image base 0x400000)
// Stable:   aa_00508350
// System:   heartbeat / timed-actions
//
// Called from Regeneration_OnHeartBeat, CreatureBase_OnHeartBeat, cast paths.
// Companion to StampLastFireTime / SetPeriodAndCounter.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

/* CVOGHBBase_RescheduleAfterFire - next list delay after OnHeartBeat.
   
   Parameters:
     pThis (ECX): CVOGHBBase* [typed via __fastcall; true ABI thiscall]
     pOutNextDelayMs (stack+4): out delay ms
   
   Algorithm:
     if nPeriodSentinel==-1000 (combat pool): *out=0 (g_dwHBStatusContinue)
     else decrement nPeriodCounter; if still >0 *out=0
     else *out=g_dwTimedActionDefaultPeriodMs (16)
   
   Returns: void via out-param
   
   Combat pool interval is TryFire vs nPeriodMs, not this 16ms default. */
void __fastcall CVOGHBBase_RescheduleAfterFire(CVOGHBBase *pThis,uint *pOutNextDelayMs)
{
  uint *in_stack_00000004;
  
  if (pThis->nPeriodSentinel == -1000) {
    *in_stack_00000004 = g_dwHBStatusContinue;
    return;
  }
  pThis->nPeriodCounter = pThis->nPeriodCounter + -1;
  if (0 < pThis->nPeriodCounter) {
    *in_stack_00000004 = g_dwHBStatusContinue;
    return;
  }
  *in_stack_00000004 = g_dwTimedActionDefaultPeriodMs;
  return;
}
