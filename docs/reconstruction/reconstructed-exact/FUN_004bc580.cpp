// Twin of List_RemoveAll.cpp (Ghidra name stable id path).
// See: docs/reconstruction/reconstructed-exact/List_RemoveAll.cpp
// Stable ID: aa_004bc580  VA: 0x004bc580–0x004bc67b (252 B)
//
// Behavior-preserving twin kept under FUN_* for tooling paths.

#include <cstdint>
#include <windows.h>

extern "C" void __stdcall _CxxThrowException(void*, void*);
extern uint8_t DAT_00acc430[];

void __fastcall FUN_004bc580(int host /* ECX */)
{
  EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(host + 4));

  uint32_t* node = *reinterpret_cast<uint32_t**>(host + 0x1c);

  if (*reinterpret_cast<char*>(host + 0x28) != 0) {
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(host + 4));
    uint32_t code = 0x80070005u;
    _CxxThrowException(&code, reinterpret_cast<void*>(&DAT_00acc430));
  }

  while (node != nullptr) {
    *reinterpret_cast<uint32_t**>(host + 0x1c) = reinterpret_cast<uint32_t*>(node[2]);
    node[1] = 0;
    (**(void(__thiscall***)(uint32_t*, int))node)(node, 1);
    node = *reinterpret_cast<uint32_t**>(host + 0x1c);
  }

  *reinterpret_cast<uint32_t*>(host + 0x24) = 0;
  *reinterpret_cast<uint32_t*>(host + 0x20) = 0;
  *reinterpret_cast<uint32_t*>(host + 0x1c) = 0;

  LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(host + 4));
}
