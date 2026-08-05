// =============================================================================
// SUPERSEDED ALIAS — aa_0050846f
// -----------------------------------------------------------------------------
// Seed name from parent MissionPatrol scan. Prefer:
//   CVOGHBBase_EndOrDestroy_SoftMarkEpilogue
//   FUN_0050846f
// Sealed 2026-07-29 W21-B. Sole callers are CVOGHBBase_EndOrDestroy hard-tail.
// =============================================================================

#include <cstdint>

extern void *ExceptionList;

// Redirect plate: keep symbol for old links; body matches sealed soft-tail.
void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGHBMissionPatro_0050846f(void)
{
  register uint32_t unaff_EBX;
  register int      unaff_EBP;
  register int      unaff_ESI;

  *(uint8_t *)(unaff_ESI + 0x20) = 1;
  *(uint32_t *)(unaff_ESI + 0x18) = unaff_EBX;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  return;
}
