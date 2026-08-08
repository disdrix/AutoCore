// =============================================================================
// FUN_00424060  (Ghidra twin of ObjectCsList_DestroyAll_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00424060
// Address:   0x00424060–0x0042415a inclusive (251 B / 0xFB)
// Wave:      WQ9L-E OWN-ONLY dual 2026-08-05
// Named:     ObjectCsList_DestroyAll_Inferred
// =============================================================================

#include <cstdint>
#include <windows.h>

struct ObjectCsListNode {
  void** vtbl;
  uint32_t field04;
  ObjectCsListNode* next;
};

extern "C" void* __cdecl _CxxThrowException(void* pExceptionObject, void* pThrowInfo);
extern "C" void* DAT_00acc430;

extern "C" void __fastcall FUN_00424060(void* list_raw)
{
  auto* list = reinterpret_cast<uint8_t*>(list_raw);

  EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));

  auto* node = *reinterpret_cast<ObjectCsListNode**>(list + 0x1C);

  if (list[0x28] != 0) {
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
    uint32_t hr = 0x80070005u;
    _CxxThrowException(&hr, &DAT_00acc430);
  }

  while (node != nullptr) {
    *reinterpret_cast<ObjectCsListNode**>(list + 0x1C) = node->next;
    using ScalarDtor = void(__thiscall*)(ObjectCsListNode*, int);
    reinterpret_cast<ScalarDtor>(node->vtbl[0])(node, 1);
    node = *reinterpret_cast<ObjectCsListNode**>(list + 0x1C);
  }

  *reinterpret_cast<uint32_t*>(list + 0x24) = 0;
  *reinterpret_cast<uint32_t*>(list + 0x20) = 0;
  *reinterpret_cast<uint32_t*>(list + 0x1C) = 0;

  LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
}
