// =============================================================================
// FUN_0094e530  (scaffold twin of Client_DebugCmd_AddDisciplinePoints)
// -----------------------------------------------------------------------------
// Stable ID: aa_0094e530
// Address:   0x0094e530–0x0094e617 (231 B / 0xE7)
// Dual:      2026-07-29 W31-T OWN-ONLY
// Prefer:    Client_DebugCmd_AddDisciplinePoints.cpp
// =============================================================================

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern "C" void __thiscall FUN_005305b0(void *character, uint32_t key, int32_t value);
extern "C" void __thiscall FUN_0052ade0(void *character, uint32_t key, int32_t value);

extern "C" uint32_t __thiscall FUN_0094e530(
    void *param_1 /*ECX client*/,
    void * /*param_2 unused*/,
    char *param_3 /*delim*/)
{
  char *pcVar2 = strtok(nullptr, param_3);
  if (pcVar2 == nullptr) {
    return 1;
  }
  int iVar3 = atoi(pcVar2);

  pcVar2 = strtok(nullptr, param_3);
  if (pcVar2 == nullptr) {
    return 1;
  }
  int iVar4 = atoi(pcVar2);

  bool bVar6 = false;
  pcVar2 = strtok(nullptr, param_3);
  if (pcVar2 != nullptr) {
    bVar6 = (atoi(pcVar2) == 1);
  }

  if (*(int *)((uint8_t *)param_1 + 0xe98) == 0) {
    return 1;
  }

  void *character = *(void **)((uint8_t *)param_1 + 0xe98);
  FUN_005305b0(character, (uint32_t)iVar3, iVar4);
  if (bVar6) {
    FUN_0052ade0(character, (uint32_t)iVar3, iVar4);
  }

  if (*(int *)((uint8_t *)param_1 + 0x1074) != 0) {
    void **ui = *(void ***)((uint8_t *)param_1 + 0x1074);
    void **vtbl = (void **)*ui;
    using VFn0 = char(__thiscall *)(void *);
    using VFn1 = void(__thiscall *)(void *);
    if (((VFn0)vtbl[0x3d8 / 4])(ui) != 0) {
      ((VFn1)vtbl[0x448 / 4])(ui);
    }
  }
  return 0;
}
