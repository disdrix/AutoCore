// =============================================================================
// FUN_004e4e10  — Ghidra-name twin of StdTree_EraseRange_Isnil21_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004e4e10
// Address:   0x004e4e10 – 0x004e4ec4 exclusive (180 B / 0xB4)
// System:    skills-abilities / STL map-set (isnil@+0x21)
// Generated: 2026-08-05 R13-024 dual seal
// Prefer:    StdTree_EraseRange_Isnil21_Inferred.cpp for named types
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

extern "C" void FUN_004e2e00(void *root);
extern "C" void __thiscall FUN_004e3e70(void *map, void **outIt, void *node);

void __thiscall FUN_004e4e10(
    int map,           // ECX — head @ +4, size @ +8
    uint32_t *outIt,   // stack0
    int *first,        // stack1
    int *last)         // stack2
{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;

  piVar4 = last;
  piVar6 = *(int **)(map + 4); // head
  piVar3 = first;
  if ((first == (int *)*piVar6) && (last == piVar6)) {
    FUN_004e2e00((void *)piVar6[1]); // free root subtree
    *(int *)(*(int *)(map + 4) + 4) = *(int *)(map + 4);
    *(uint32_t *)(map + 8) = 0;
    **(uint32_t **)(map + 4) = *(uint32_t *)(map + 4);
    *(int *)(*(int *)(map + 4) + 8) = *(int *)(map + 4);
    *outIt = **(uint32_t **)(map + 4);
    return; // ret 0x0c
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x21) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x21) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x21);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x21);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      } else {
        cVar1 = *(char *)(piVar3[1] + 0x21);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x21);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004e3e70((void *)map, (void **)&first, piVar3);
    piVar3 = piVar6;
  }
  *outIt = (uint32_t)piVar3;
  return; // ret 0x0c
}
