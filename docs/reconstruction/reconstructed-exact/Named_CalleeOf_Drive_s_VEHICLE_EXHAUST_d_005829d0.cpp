// =============================================================================
// Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_005829d0  (LEGACY ALIAS)
// -----------------------------------------------------------------------------
// Stable ID: aa_005829d0
// Address:   0x005829d0  (autoassault.exe, image base 0x400000)
// Status:    SUPERSEDED by NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred
// Reason:    Scaffold parent-string alias is too narrow — 12 xrefs across
//            hardpoint expansion and other host paths, not exhaust-only.
// See:       reconstructed-exact/NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred.cpp
//            reconstructed-exact/FUN_005829d0.cpp
//            reviews/A_aa_005829d0_*.md / B_aa_005829d0_*.md
// Generated: 2026-07-29 W24-A (alias retained for path continuity)
// =============================================================================

#include <stdint.h>

extern "C" {

void __thiscall FUN_00518590(void *a, uint32_t b, uint32_t c);
void __thiscall FUN_004b7030(void *related, uint32_t a, uint32_t b, uint32_t c);

// Legacy name → same body as FUN_005829d0
void __thiscall Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_005829d0(
    int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
  FUN_00518590((void *)param_2, param_3, param_4);
  if (*(int *)(param_1 + -0x88) != 0) {
    FUN_004b7030(*(void **)(param_1 + -0x88), 0, 0, 0xffffffff);
  }
  return;
}

} // extern "C"
