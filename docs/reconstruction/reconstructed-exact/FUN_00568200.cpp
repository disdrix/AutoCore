// =============================================================================
// FUN_00568200 (scaffold alias of StdTree_IteratorIncrement_Isnil49)
// -----------------------------------------------------------------------------
// Stable ID: aa_00568200
// Address:   0x00568200–0x0056824a  (autoassault.exe, image base 0x400000)
// System:    shared client::stdtree
// Generated: 2026-07-29 W22-B dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Named clean: StdTree_IteratorIncrement_Isnil49.cpp
// Role: MSVC tree iterator operator++ (is_nil @ +0x49).

#include <stdint.h>

void __fastcall FUN_00568200(int32_t *param_1)
{
  char cVar1;
  int32_t iVar2;
  int32_t *piVar3;
  int32_t *piVar4;

  iVar2 = *param_1;
  if (*(char *)(iVar2 + 0x49) == '\0') {
    piVar3 = *(int32_t **)(iVar2 + 8);
    if (*(char *)((int32_t)piVar3 + 0x49) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x49);
      piVar4 = (int32_t *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x49);
        piVar3 = piVar4;
        piVar4 = (int32_t *)*piVar4;
      }
      *param_1 = (int32_t)piVar3;
      return;
    }
    iVar2 = *(int32_t *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x49);
    while ((cVar1 == '\0') && (*param_1 == *(int32_t *)(iVar2 + 8))) {
      *param_1 = iVar2;
      iVar2 = *(int32_t *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x49);
    }
    *param_1 = iVar2;
  }
  return;
}
