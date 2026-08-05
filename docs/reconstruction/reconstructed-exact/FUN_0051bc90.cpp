// Twin of ObjectCsList_ClearDestroyNoNode4_Inferred.cpp (Ghidra symbol name)
// Stable ID: aa_0051bc90  VA: 0x0051bc90
// See: reconstructed-exact/ObjectCsList_ClearDestroyNoNode4_Inferred.cpp

#include <stdint.h>
#include <windows.h>

extern "C" void *__cdecl _CxxThrowException(void *pExceptionObject, void *pThrowInfo);
extern "C" void *DAT_00acc430;

void __fastcall FUN_0051bc90(int list)
{
  EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
  uint32_t *node = *reinterpret_cast<uint32_t **>(list + 0x1C);

  if (*reinterpret_cast<char *>(list + 0x28) != 0) {
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
    uint32_t hr = 0x80070005u;
    _CxxThrowException(&hr, &DAT_00acc430);
  }

  while (node != nullptr) {
    *reinterpret_cast<uint32_t **>(list + 0x1C) = reinterpret_cast<uint32_t *>(node[2]);
    reinterpret_cast<void(__thiscall *)(uint32_t *, int)>(*reinterpret_cast<void **>(*node))(node, 1);
    node = *reinterpret_cast<uint32_t **>(list + 0x1C);
  }

  *reinterpret_cast<uint32_t *>(list + 0x24) = 0;
  *reinterpret_cast<uint32_t *>(list + 0x20) = 0;
  *reinterpret_cast<uint32_t *>(list + 0x1C) = 0;
  LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
}
