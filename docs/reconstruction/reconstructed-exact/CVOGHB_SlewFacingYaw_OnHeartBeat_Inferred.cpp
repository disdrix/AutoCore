// =============================================================================
// CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Secondary facing-slew HB tick (vtbl 009daee8 +0x0C): if owner
//           attached, re-run CVOGCreature_SlewFacingYaw on raw owner with
//           period Δt from +0x08; always RescheduleAfterFire; return pOutStatus.
//
// Address:  0x005d6c10  (autoassault.exe, image base 0x400000)
// Body:     0x005d6c10–0x005d6c37 (0x28 / 40 B; RET 4)
// Stable:   aa_005d6c10
// System:   heartbeat / creature facing
//
// Vtbl:     PTR_FUN_009daee8 + 0x0C (DATA xref 0x009daef4)
// Sibling:  CVOGHB_SlewFacingYaw_ctor_Inferred (0x005d6b80, W28-K)
// Callees:  CVOGCreature_SlewFacingYaw_Inferred (0x004c7bd0);
//           CVOGHBBase_RescheduleAfterFire (0x00508350)
//
// Exactness: CF mirrors raw; slew ECX=raw owner sealed by read_memory.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-29 W30-T
// =============================================================================

// Ghidra: FUN_005d6c10
// ABI: __thiscall; stack pOutStatus; RET 4; returns pOutStatus

#include <cstdint>

extern "C" void __thiscall CVOGCreature_SlewFacingYaw_Inferred(void *pCreature, int deltaMs);
extern "C" void __thiscall CVOGHBBase_RescheduleAfterFire(void *hb, uint32_t *pOutNextDelayMs);

uint32_t *__thiscall CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred(
    void *self,
    uint32_t *pOutStatus)
{
  /* gate: pOwnerObject @ +0x18 */
  if (*(void **)((char *)self + 0x18) != nullptr) {
    /* bytes: ECX = raw owner @ +0x24; arg = nPeriodMs @ +0x08 */
    void *rawOwner = *(void **)((char *)self + 0x24);
    int periodMs = *(int *)((char *)self + 0x08);
    CVOGCreature_SlewFacingYaw_Inferred(rawOwner, periodMs);
  }
  CVOGHBBase_RescheduleAfterFire(self, pOutStatus);
  return pOutStatus;
}
