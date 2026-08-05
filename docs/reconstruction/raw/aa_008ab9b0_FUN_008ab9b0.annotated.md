# Annotated low-level: FUN_008ab9b0

| Field | Value |
|---|---|
| Stable ID | `aa_008ab9b0` |
| VA | `0x008ab9b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008ab9b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
bool __thiscall FUN_008ab9b0(int *param_1,uint *param_2)

{
  void *pObjective;
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  undefined4 *puVar7;
  char local_3a0 [2];
  undefined4 local_39e [64];
  undefined1 *puStack_29c;
  undefined1 auStack_298 [128];
  int aiStack_218 [10];
  undefined1 auStack_1ee [470];
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009b2aaf;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007a69d0();
  pObjective = *(void **)((param_2[0x4f] - 4) + (uint)(byte)param_2[0x4c] * 4);
  local_3a0[0] = '\0';
  local_3a0[1] = '\0';
  puVar7 = local_39e;
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  if (pObjective != (void *)0x0) {
    if (((((short)param_2[0x2b] != -1) && (DAT_00d1b6d8 != 0)) &&
        (*(void **)(DAT_00d1b6d8 + 0x538) != (void *)0x0)) &&
       (pvVar2 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x538),*param_2),
       pvVar2 != (void *)0x0)) {
      uVar3 = FUN_007a6de0("(Rewards Already Received)",0xffffffff);
      sprintf(local_3a0,"%s",uVar3);
      (**(code **)(*param_1 + 0x250))(local_3a0);
      ExceptionList = pvStack_18;
      return true;
    }
    iVar5 = *(int *)((int)pObjective + 0x130);
    bVar6 = 0 < iVar5;
    if (bVar6) {
      uVar3 = FUN_007a6de0(&DAT_00a4abd4,0xffffffff);
      sprintf(local_3a0,"%d %s",iVar5,uVar3);
      (**(code **)(*param_1 + 0x250))(local_3a0);
    }
    if (0 < *(int *)((int)pObjective + 0x134)) {
      if (bVar6) {
        (**(code **)(*param_1 + 0x250))(&DAT_00a34230);
      }
      uVar3 = *(undefined4 *)((int)pObjective + 0x134);
      uVar4 = FUN_007a6de0(&DAT_00a4abd0,0xffffffff);
      sprintf(local_3a0,"%d %s",uVar3,uVar4);
      (**(code **)(*param_1 + 0x250))(local_3a0);
      bVar6 = true;
    }
    iVar5 = Mission_ComputeObjectiveCredits(pObjective);
    if (0 < iVar5) {
      if (bVar6 != false) {
        (**(code **)(*param_1 + 0x250))(&DAT_00a34230);
      }
      iVar5 = Mission_ComputeObjectiveCredits(pObjective);
      FUN_00977a30(DAT_00d1ad30,iVar5,iVar5 >> 0x1f);
      bVar6 = true;
    }
    if ((param_2[0x40] != 0xffffffff) && (iVar5 = FUN_0051a0e0(param_2[0x40]), iVar5 != 0)) {
      if (bVar6 != false) {
        (**(code **)(*param_1 + 0x250))(&DAT_00a34230);
      }
      uVar3 = *(undefined4 *)(iVar5 + 4);
      uVar4 = FUN_007a6de0("Medal",0xffffffff);
      uVar3 = FUN_007a6de0(uVar3,0xffffffff);
      sprintf(local_3a0,"%s %s",uVar3,uVar4);
      (**(code **)(*param_1 + 0x250))(local_3a0);
      bVar6 = true;
    }
    if (param_2[0x43] != 0xffffffff) {
      aiStack_218[0] = -1;
      FUN_0052b040(param_2[0x43],aiStack_218);
      if (aiStack_218[0] != -1) {
        if (bVar6 != false) {
          (**(code **)(*param_1 + 0x250))(&DAT_00a34230);
        }
        puStack_29c = auStack_298;
        uVar3 = (*(code *)PTR_FUN_00af8c9c)();
        FUN_00403450(auStack_1ee,uVar3);
        uStack_c = 0;
        uVar3 = FUN_007a6de0(puStack_29c,0xffffffff);
        uVar4 = FUN_007a6de0("Unlocks",0xffffffff);
        sprintf(local_3a0,"%s %s",uVar4,uVar3);
        uStack_c = 0xffffffff;
        if (puStack_29c != auStack_298) {
          free(puStack_29c);
        }
        (**(code **)(*param_1 + 0x250))(local_3a0);
        bVar6 = true;
      }
    }
    if (0 < (int)param_2[0x45]) {
      if (bVar6 != false) {
        (**(code **)(*param_1 + 0x250))(&DAT_00a34230);
      }
      uVar1 = param_2[0x45];
      uVar3 = FUN_007a6de0(&DAT_00a4abbc,0xffffffff);
      sprintf(local_3a0,"%d %s",uVar1,uVar3);
      (**(code **)(*param_1 + 0x250))(local_3a0);
      bVar6 = true;
    }
    ExceptionList = local_14;
    return bVar6;
  }
  ExceptionList = local_14;
  return false;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
