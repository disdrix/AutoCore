// =============================================================================
// FUN_00650d30  (scaffold alias → CVOGHBMissionPatrol_ctor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00650d30
// Address:   0x00650d30  (autoassault.exe, image base 0x400000)
// Canonical: CVOGHBMissionPatrol_ctor  (see CVOGHBMissionPatrol_ctor.cpp)
// System:    missions-progression / mission-patrol HB
// Generated: 2026-07-23 scaffold; 2026-07-29 W23-T dual seal refresh
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void *__thiscall CVOGHBBase_ctor(void *self);
extern "C" void __thiscall CVOGHBBase_SetPeriodAndCounter(void *self, int period, bool alsoCounter);
extern "C" void __thiscall CVOGHBBase_AttachOwnerObject(void *self, void *owner);
extern "C" void *PTR_FUN_009e52e4;
extern "C" void *ExceptionList;
extern "C" void *LAB_009a8ec8;

using uint32_t = std::uint32_t;
using uint8_t = std::uint8_t;

uint32_t *__thiscall FUN_00650d30(uint32_t *param_1, void *param_2, int *param_3)
{
  uint32_t uVar1;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = (uint8_t *)&LAB_009a8ec8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  CVOGHBBase_ctor(param_1);
  *param_1 = (uint32_t)&PTR_FUN_009e52e4;
  local_4 = 0;
  uVar1 = (*(uint32_t(__thiscall **)(int *))(*param_3 + 0x58))(param_3);
  param_1[9] = uVar1;
  param_1[10] = *(uint32_t *)(param_3[1] + 0x10);
  param_1[0xc] = (uint32_t)param_3[0xc];
  param_1[0xd] = (uint32_t)param_3[0xd];
  param_1[0xe] = (uint32_t)param_3[7];
  param_1[7] = 0xc;
  CVOGHBBase_SetPeriodAndCounter(param_1, -1000, true);
  if (param_2 != (void *)0x0) {
    param_2 = (void *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 4 + (int)param_2);
  }
  CVOGHBBase_AttachOwnerObject(param_1, param_2);
  param_1[2] = 1000;
  ExceptionList = pvStack_c;
  return param_1;
}
