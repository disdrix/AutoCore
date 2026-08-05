// =============================================================================
// FUN_004bcbf0  (scaffold twin of ThreadSafeObjectList_Dtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bcbf0
// Address:   0x004bcbf0  (autoassault.exe, image base 0x400000)
// Body:      0x004bcbf0 – 0x004bcc31
// System:    client::util / lock-protected object list
// Generated: 2026-07-29 W25-C dual A/B seal
// Canonical: ThreadSafeObjectList_Dtor.cpp
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" void* __fastcall FUN_0040b020(void* list);
extern "C" void* PTR_FUN_009cb368;

void __fastcall FUN_004bcbf0(uint32_t* param_1)
{
  uint32_t* puVar1;

  *param_1 = (uint32_t)&PTR_FUN_009cb368;
  puVar1 = (uint32_t*)FUN_0040b020(param_1);
  while (puVar1 != nullptr) {
    (**(void(__thiscall***)(uint32_t*, int))*puVar1)(puVar1, 1);
    puVar1 = (uint32_t*)FUN_0040b020(param_1);
  }
  param_1[3] = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));   // +0x10
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 10));  // +0x28
}
