// =============================================================================
// FUN_00626530  (alias → CVOGHB_FixedPeriod1_ctor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00626530
// Address:   0x00626530–0x00626561  (50 B / 0x32)
// Dual A/B:  2026-07-29 accept-with-gaps (W29-O)
// Authoritative named clean: CVOGHB_FixedPeriod1_ctor_Inferred.cpp
// =============================================================================

#include <stdint.h>

void *__thiscall FUN_00626530(
    void *param_1,
    void *param_2,
    uint32_t param_3,
    uint32_t param_4,
    uint32_t param_5)
{
  (void)param_3;
  (void)param_4;

  CVOGHBBase_ctor(param_1);
  *(uint32_t *)param_1 = 0x009e3188u;
  CVOGHBBase_AttachOwnerObject(param_1, param_2);
  *(uint32_t *)((char *)param_1 + 0x08) = param_5;
  CVOGHBBase_SetPeriodAndCounter(param_1, 1, 1);
  return param_1;
}
