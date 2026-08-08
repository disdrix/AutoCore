// =============================================================================
// FUN_004e12c0  (scaffold twin → StdTree_IteratorIncrement_Isnil21_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e12c0
// Address:   0x004e12c0–0x004e130b exclusive  (75 B / 0x4B)
// Module:    autoassault.exe (image base 0x400000)
// Generated: 2026-08-05 R13-003 dual seal
// Canonical: StdTree_IteratorIncrement_Isnil21_Inferred
// =============================================================================

#include <stdint.h>

// See StdTree_IteratorIncrement_Isnil21_Inferred.cpp for full plate + purpose.
// ECX = iterator (node**); void; plain RET.

void StdTree_IteratorIncrement_Isnil21_Inferred(int32_t *it /*ECX*/);

void __fastcall FUN_004e12c0(int32_t *param_1 /*ECX*/)
{
  char cVar1;
  int32_t iVar2;
  int32_t *piVar3;
  int32_t *piVar4;

  iVar2 = *param_1;
  if (*(char *)(iVar2 + 0x21) == '\0') {
    piVar3 = *(int32_t **)(iVar2 + 8);
    if (*(char *)((int32_t)piVar3 + 0x21) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x21);
      piVar4 = (int32_t *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x21);
        piVar3 = piVar4;
        piVar4 = (int32_t *)*piVar4;
      }
      *param_1 = (int32_t)piVar3;
      return;
    }
    iVar2 = *(int32_t *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x21);
    while ((cVar1 == '\0') && (*param_1 == *(int32_t *)(iVar2 + 8))) {
      *param_1 = iVar2;
      iVar2 = *(int32_t *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x21);
    }
    *param_1 = iVar2;
  }
  return;
}
