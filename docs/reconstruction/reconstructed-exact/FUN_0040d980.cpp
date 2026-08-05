// =============================================================================
// FUN_0040d980  (Ghidra twin of GuardedVector_PopFront)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d980
// Address:   0x0040d980–0x0040d9b1  (autoassault.exe, image base 0x400000)
// Dual:      W30-B 2026-07-29
// Named clean: GuardedVector_PopFront.cpp
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================

#include <cstdint>

// Retail ABI: EAX=container; 0 stack formals; plain RET; void
void FUN_0040d980(void)
{
  int in_EAX; // container — register this

  if (*(int*)(in_EAX + 0x10) != 0) {
    *(int*)(in_EAX + 0xc) = *(int*)(in_EAX + 0xc) + 1;
    if ((uint32_t)(*(int*)(in_EAX + 8) * 4) <= *(uint32_t*)(in_EAX + 0xc)) {
      *(uint32_t*)(in_EAX + 0xc) = 0;
    }
    int iVar1 = *(int*)(in_EAX + 0x10) + -1;
    *(int*)(in_EAX + 0x10) = iVar1;
    if (iVar1 == 0) {
      *(uint32_t*)(in_EAX + 0xc) = 0;
    }
  }
  return;
}
