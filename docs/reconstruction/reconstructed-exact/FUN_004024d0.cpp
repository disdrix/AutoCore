// =============================================================================
// FUN_004024d0  (scaffold alias — prefer CsSList_AppendPayload_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_004024d0
// Address:   0x004024d0  (autoassault.exe, image base 0x400000)
// System:    client containers / deferred-queue append
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W18-B)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: reconstructed-exact/CsSList_AppendPayload_Inferred.cpp
// =============================================================================

#include <windows.h>
#include <cstdint>

extern "C" void *operator_new(unsigned size);
extern "C" uint8_t FUN_00402598(void);
extern "C" void *ExceptionList;
extern "C" uint32_t PTR_FUN_009cb340;

uint32_t __thiscall FUN_004024d0(int param_1, int param_2)
{
  uint32_t *puVar1;
  uint32_t uVar2;
  void *local_10;
  uint8_t *puStack_c;
  uint32_t local_8;

  puStack_c = (uint8_t *)0; // &LAB_009bc1ab
  local_10 = ExceptionList;
  if (param_2 == 0) {
    return (uint32_t)ExceptionList & 0xffffff00;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  puVar1 = (uint32_t *)operator_new(0xC);
  if (puVar1 == (uint32_t *)0) {
    puVar1 = (uint32_t *)0;
  } else {
    *puVar1 = (uint32_t)&PTR_FUN_009cb340;
    puVar1[2] = 0;
    puVar1[1] = 0;
  }
  local_8 = local_8 & 0xffffff00;
  puVar1[1] = (uint32_t)param_2;
  if (*(int *)(param_1 + 0xC) < 4) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  if (*(int *)(param_1 + 8) == 0) {
    *(uint32_t **)(param_1 + 4) = puVar1;
    *(uint32_t **)(param_1 + 8) = puVar1;
    uVar2 = FUN_00402598();
    return uVar2;
  }
  *(uint32_t **)(*(int *)(param_1 + 8) + 8) = puVar1;
  *(uint32_t **)(param_1 + 8) = puVar1;
  uVar2 = FUN_00402598();
  return uVar2;
}
