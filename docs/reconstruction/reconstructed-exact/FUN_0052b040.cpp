// =============================================================================
// FUN_0052b040  (clean twin — Ghidra symbol retained)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b040
// Address:   0x0052b040
// Named twin: DisciplineDefMap_TryCopyPayloadById_Inferred.cpp
// Dual:      R12-020 OWN-ONLY 2026-08-05
// =============================================================================

#include <stdint.h>

extern "C" void *__thiscall FUN_00538ab0(void *mapHeader, void *outNodeSlot, int *pKey);
extern "C" void *DAT_00b045b4;

extern "C" int FUN_0052b040(uint32_t param_1, uint32_t *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar4;
  uint32_t *puVar5;
  uint8_t local_4[4];

  piVar2 = (int *)FUN_00538ab0((void *)0x00b045b0, local_4, (int *)&param_1);
  iVar1 = *piVar2;
  if (iVar1 == (int)DAT_00b045b4) {
    return 0;
  }
  puVar5 = (uint32_t *)(iVar1 + 0x10);
  for (iVar4 = 0x7f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *param_2 = *puVar5;
    puVar5 = puVar5 + 1;
    param_2 = param_2 + 1;
  }
  return 1;
}
