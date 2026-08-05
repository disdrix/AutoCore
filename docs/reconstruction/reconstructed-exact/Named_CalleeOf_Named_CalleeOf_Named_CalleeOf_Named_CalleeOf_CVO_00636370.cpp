// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00636370
// -----------------------------------------------------------------------------
// Stable ID: aa_00636370
// Alias:     parent-seed scaffold — prefer Phys_ActionBase_ctor / FUN_00636370
// Address:   0x00636370  (autoassault.exe, image base 0x400000)
// System:    physics / Havok-like action base
// Generated: 2026-07-23 scaffold; 2026-07-29 W17-P dual seal notes
// =============================================================================
//
// NOTE: Auto parent-seed name (…CVOGHBAIDriver…) is misleading. This is the
// shared action-base ctor used by VehicleAction, flipper constraint, etc.
//

#include <cstdint>

extern "C" void *PTR_FUN_009e39f4;
extern "C" void *PTR_LAB_009e3a68;
extern "C" void *PTR_LAB_009e5e78;
void __thiscall FUN_00507290(void *host, void *elem);

uint32_t *__thiscall
Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00636370(
    uint32_t *param_1, int param_2)
{
  *(uint16_t *)((int)param_1 + 6) = 1;
  param_1[2] = (uint32_t)&PTR_LAB_009e3a68;
  param_1[3] = 0;
  param_1[5] = 0;
  *param_1 = (uint32_t)&PTR_FUN_009e39f4;
  param_1[2] = (uint32_t)&PTR_LAB_009e5e78;
  param_1[6] = (uint32_t)param_2;
  if (param_2 != 0) {
    FUN_00507290((void *)param_2, param_1);
    *(int16_t *)(param_1[6] + 6) = (int16_t)(*(int16_t *)(param_1[6] + 6) + 1);
  }
  return param_1;
}
