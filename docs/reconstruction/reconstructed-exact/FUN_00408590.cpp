// =============================================================================
// FUN_00408590  (scaffold twin → StdTree_IteratorIncrement_Isnil31)
// -----------------------------------------------------------------------------
// Stable ID: aa_00408590
// Address:   0x00408590–0x004085db exclusive  (75 B / 0x4B)
// Module:    autoassault.exe (image base 0x400000)
// Generated: 2026-08-04 WQ9H-H dual seal
// Canonical: StdTree_IteratorIncrement_Isnil31
// =============================================================================

#include <stdint.h>

// See StdTree_IteratorIncrement_Isnil31.cpp for full plate + purpose.
// EDX = iterator (node**); ECX unused; void; plain RET.

void StdTree_IteratorIncrement_Isnil31(int32_t *it /*EDX*/);

void __fastcall FUN_00408590(uint32_t /*ecx unused*/, int32_t *param_2 /*EDX*/)
{
  char cVar1;
  int32_t iVar2;
  int32_t *piVar3;
  int32_t *piVar4;

  iVar2 = *param_2;
  if (*(char *)(iVar2 + 0x31) == '\0') {
    piVar3 = *(int32_t **)(iVar2 + 8);
    if (*(char *)((int32_t)piVar3 + 0x31) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x31);
      piVar4 = (int32_t *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x31);
        piVar3 = piVar4;
        piVar4 = (int32_t *)*piVar4;
      }
      *param_2 = (int32_t)piVar3;
      return;
    }
    iVar2 = *(int32_t *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x31);
    while ((cVar1 == '\0') && (*param_2 == *(int32_t *)(iVar2 + 8))) {
      *param_2 = iVar2;
      iVar2 = *(int32_t *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x31);
    }
    *param_2 = iVar2;
  }
  return;
}
