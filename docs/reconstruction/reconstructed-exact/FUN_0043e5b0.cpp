// =============================================================================
// FUN_0043e5b0  (Ghidra twin of GuardedVector_ContainsFirstEqual)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e5b0
// Address:   0x0043e5b0–0x0043e62a  (autoassault.exe, image base 0x400000)
// Dual:      W30-B 2026-07-29
// Named clean: GuardedVector_ContainsFirstEqual.cpp
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================

#include <cstdint>
#include <windows.h>

// Retail ABI: EAX=container; stdcall 1 stack formal; RET 0x4; AL=bool
uint8_t FUN_0043e5b0(int* param_1)
{
  int in_EAX; // container — register this, not stack

  if (*(char*)(in_EAX + 0x2c) != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x14));
  }

  uint32_t uVar3 = *(uint32_t*)(in_EAX + 0xc);
  uint8_t uVar4 = 0;
  uint32_t uVar5 = *(int*)(in_EAX + 0x10) + uVar3;

  do {
    if (uVar3 == uVar5) {
      if (*(char*)(in_EAX + 0x2c) != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x14));
      }
      return uVar4;
    }
    uint32_t uVar2 = uVar3 >> 2;
    int iVar1 = static_cast<int>(uVar2 * static_cast<uint32_t>(-4));
    if (*(uint32_t*)(in_EAX + 8) <= uVar2) {
      uVar2 = uVar2 - *(uint32_t*)(in_EAX + 8);
    }
    if (*(int*)(*(int*)(*(int*)(in_EAX + 4) + uVar2 * 4) +
                (uVar3 + iVar1) * 4) == *param_1) {
      uVar4 = 1;
      if (*(char*)(in_EAX + 0x2c) != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x14));
      }
      return uVar4;
    }
    uVar3 = uVar3 + 1;
  } while (true);
}
