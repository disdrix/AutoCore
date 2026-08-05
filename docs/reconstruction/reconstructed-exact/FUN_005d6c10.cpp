// =============================================================================
// FUN_005d6c10 — Ghidra twin of CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005d6c10
// Address:   0x005d6c10  (autoassault.exe, image base 0x400000)
// Named:     reconstructed-exact/CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred.cpp
// Wave:      W30-T (2026-07-29)
// Exactness: Same CF as named clean; Ghidra name retained as twin entry.
// =============================================================================

#include <cstdint>

extern "C" void __thiscall CVOGCreature_SlewFacingYaw_Inferred(void *pCreature, int deltaMs);
extern "C" void __thiscall CVOGHBBase_RescheduleAfterFire(void *hb, uint32_t *pOutNextDelayMs);

uint32_t *__thiscall FUN_005d6c10(void *param_1, uint32_t *pOutStatus)
{
  if (*(void **)((char *)param_1 + 0x18) != nullptr) {
    void *rawOwner = *(void **)((char *)param_1 + 0x24);
    int periodMs = *(int *)((char *)param_1 + 0x08);
    CVOGCreature_SlewFacingYaw_Inferred(rawOwner, periodMs);
  }
  CVOGHBBase_RescheduleAfterFire(param_1, pOutStatus);
  return pOutStatus;
}
