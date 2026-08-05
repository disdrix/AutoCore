// =============================================================================
// FUN_00636370  →  see Phys_ActionBase_ctor.cpp
// -----------------------------------------------------------------------------
// Stable ID: aa_00636370
// Address:   0x00636370  (autoassault.exe, image base 0x400000)
// System:    physics / Havok-like action base
// Generated: 2026-07-29 W17-P dual seal (prior scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE: Dual-vtbl action base ctor. Canonical plate: Phys_ActionBase_ctor.cpp
// NOTE: Call to FUN_00507290 is thiscall ECX=host, stack=this (see annotated).
//

#include <cstdint>

extern "C" void *PTR_FUN_009e39f4;
extern "C" void *PTR_LAB_009e3a68;
extern "C" void *PTR_LAB_009e5e78;
void __thiscall FUN_00507290(void *host, void *elem);

uint32_t *__thiscall FUN_00636370(uint32_t *param_1, int param_2)
{
  *(uint16_t *)((int)param_1 + 6) = 1;
  param_1[2] = (uint32_t)&PTR_LAB_009e3a68;
  param_1[3] = 0;
  param_1[5] = 0;
  *param_1 = (uint32_t)&PTR_FUN_009e39f4;
  param_1[2] = (uint32_t)&PTR_LAB_009e5e78;
  param_1[6] = (uint32_t)param_2;
  if (param_2 != 0) {
    // Machine: ECX=param_2 (host), stack arg=param_1 (action)
    FUN_00507290((void *)param_2, param_1);
    *(int16_t *)(param_1[6] + 6) = (int16_t)(*(int16_t *)(param_1[6] + 6) + 1);
  }
  return param_1;
}
