// =============================================================================
// FUN_004c9430  (scaffold twin of Object_EnsurePrimaryHBAI_FromAIProfile)
// Stable ID: aa_004c9430
// Address:   0x004c9430
// Prefer:    Object_EnsurePrimaryHBAI_FromAIProfile.cpp
// W27-I:     2026-07-29 live re-verify; clean CF ≡ raw; types tightened.
// =============================================================================

#include <stdint.h>

struct CVOGHBBase {
  void **pVTable;
  char cStopped;
};

extern void *ExceptionList;
extern void *operator_new(uint32_t size);
extern int FUN_00540890(char);
extern void FUN_004cbd50(void **, void *);
extern CVOGHBBase *FUN_005d8330(void *);
extern CVOGHBBase *FUN_005d7f50(void *);
extern CVOGHBBase *FUN_005d7de0(void *);
extern CVOGHBBase *FUN_005d7bb0(void *);
extern CVOGHBBase *FUN_005d6da0(void *);
extern CVOGHBBase *FUN_005d6b80(void *);
extern void CVOGHBList_Enqueue(void *, CVOGHBBase *);
extern void CVOGHBBase_Start(CVOGHBBase *);
extern void FUN_005081d0(void); // CVOGHBBase_Stop thiscall
extern void *FUN_00516a00(char);

void *__thiscall FUN_004c9430(void *param_1, char param_2, char param_3)
{
  int iVar1;
  CVOGHBBase *pCVar2;
  void *pvVar3;
  void **ppvVar4;
  uint8_t *puVar5;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = (uint8_t *)0x009a1c71;
  local_c = ExceptionList;
  if (*(int *)((int)param_1 + 0x1fc) != 0) {
    return ExceptionList;
  }
  if (param_3 == -1) {
    param_3 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac +
                                         (int)param_1) +
                                0x3c) +
                       0x4dc);
  }
  puVar5 = (uint8_t *)&param_3;
  ppvVar4 = &local_10;
  ExceptionList = &local_c;
  local_10 = param_1;
  FUN_00540890(0);
  FUN_004cbd50(ppvVar4, puVar5);
  iVar1 = FUN_00540890(0);
  if (local_10 == *(void **)(iVar1 + 4)) {
    ExceptionList = local_c;
    return local_10;
  }
  *(int *)((int)param_1 + 0x200) = 1 << (*(uint8_t *)((int)local_10 + 0x10) & 0x1f);
  switch (*(uint16_t *)((int)local_10 + 0x10)) {
  case 2:
    local_4 = 0;
    pCVar2 = (operator_new(0xc0) != 0) ? FUN_005d8330(param_1) : 0;
    break;
  case 3:
    local_4 = 1;
    pCVar2 = (operator_new(0xb0) != 0) ? FUN_005d7f50(param_1) : 0;
    break;
  case 4:
    local_4 = 2;
    pCVar2 = (operator_new(0xc0) != 0) ? FUN_005d7de0(param_1) : 0;
    break;
  case 5:
    local_4 = 3;
    pCVar2 = (operator_new(0xc0) != 0) ? FUN_005d7bb0(param_1) : 0;
    break;
  default:
    local_4 = 4;
    pCVar2 = (operator_new(0xb0) != 0) ? FUN_005d6da0(param_1) : 0;
    break;
  }
  local_4 = 0xffffffff;
  if (pCVar2 != 0) {
    if (pCVar2->cStopped == 0) {
      *(CVOGHBBase **)((int)param_1 + 0x1fc) = pCVar2;
      CVOGHBList_Enqueue(
          *(void **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1) +
                     0xe4ec),
          pCVar2);
      if ((param_2 == 0) &&
          (*(char *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1) +
                     0x7e) != 0)) {
        FUN_005081d0();
      } else {
        CVOGHBBase_Start(pCVar2);
      }
    } else {
      ((void(__thiscall *)(CVOGHBBase *, int))pCVar2->pVTable[0])(pCVar2, 1);
    }
  }
  if (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac + (int)param_1) +
                       0x3c) +
               0x4e8) == 1) {
    local_4 = 5;
    pCVar2 = (operator_new(0x28) != 0) ? FUN_005d6b80(param_1) : 0;
    local_4 = 0xffffffff;
    CVOGHBList_Enqueue(
        *(void **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1) +
                   0xe4ec),
        pCVar2);
    CVOGHBBase_Start(pCVar2);
  }
  iVar1 = *(int *)(*(int *)((int)param_1 + 4) + 4);
  pvVar3 = (void *)(iVar1 + (int)param_1);
  if (*(int *)(*(int *)(iVar1 + 0xac + (int)param_1) + 0x38) != 0x14) {
    pvVar3 = FUN_00516a00(0);
  }
  ExceptionList = local_c;
  return pvVar3;
}
