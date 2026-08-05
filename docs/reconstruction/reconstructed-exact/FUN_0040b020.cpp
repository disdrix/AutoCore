// =============================================================================
// FUN_0040b020  (scaffold twin of ThreadSafeObjectList_PopFront)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b020
// Address:   0x0040b020  (autoassault.exe, image base 0x400000)
// System:    client::util / lock-protected object list
// Generated: 2026-07-29 W24-S dual A/B (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Named plate: reconstructed-exact/ThreadSafeObjectList_PopFront.cpp
// =============================================================================

#include <cstdint>
#include <windows.h>

uint32_t __fastcall FUN_0040b020(int param_1)
{
  uint32_t* puVar1;
  uint32_t uVar2;
  int iVar3;
  bool bVar4;
  void* local_10;
  uint8_t* puStack_c;
  uint32_t local_8;

  puStack_c = (uint8_t*)&/*LAB_009bc590*/local_8;  // SEH registration (symbolic)
  local_10 = nullptr;  // ExceptionList save site
  local_8 = 0;
  if (*(int*)(param_1 + 4) != 0) {
    // ExceptionList = &local_10;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
    puVar1 = *(uint32_t**)(param_1 + 4);
    bVar4 = *(LONG*)(param_1 + 0xc) < 2;
    if (bVar4) {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    }
    uVar2 = puVar1[1];
    iVar3 = *(int*)(*(int*)(param_1 + 4) + 8);
    *(int*)(param_1 + 4) = iVar3;
    if (iVar3 == 0) {
      *(uint32_t*)(param_1 + 8) = 0;
    }
    puVar1[1] = 0;
    (**(code**)*puVar1)(1);
    if (bVar4) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
    InterlockedDecrement((LONG*)(param_1 + 0xc));
    // ExceptionList = local_10;
    return uVar2;
  }
  return 0;
}
