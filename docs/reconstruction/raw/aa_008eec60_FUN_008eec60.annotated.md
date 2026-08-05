# Annotated low-level: FUN_008eec60

| Field | Value |
|---|---|
| Stable ID | `aa_008eec60` |
| VA | `0x008eec60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008eec60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x008eee1a) */
/* WARNING: Removing unreachable block (ram,0x008eef27) */

void __thiscall FUN_008eec60(int param_1,uint param_2)

{
  void *pvVar1;
  void *pvVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  bool bVar6;
  undefined8 uVar7;
  longlong lVar8;
  char *pcVar9;
  uint key;
  undefined **ppuStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  _RTL_CRITICAL_SECTION _Stack_c4;
  _RTL_CRITICAL_SECTION _Stack_ac;
  undefined4 uStack_94;
  undefined1 *local_90;
  undefined1 local_8c [124];
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &LAB_009b2c1a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  key = param_2;
  pvVar1 = (void *)FUN_00541a80();
  pvVar1 = CNDHash_LookupByKey(pvVar1,key);
  if (pvVar1 == (void *)0x0) {
    FUN_008ed8a0();
    ExceptionList = local_c;
    return;
  }
  FUN_007a69d0();
  bVar6 = true;
  *(undefined4 *)(param_1 + 0x50c) = 1;
  FUN_008eba20();
  *(uint *)(param_1 + 0x540) = param_2;
  iVar5 = DAT_00d1b6d8;
  if ((DAT_00d1b644 == 0) || (*(uint *)(DAT_00d1b644 + 0xfc) != param_2)) {
    bVar6 = false;
  }
  if (((DAT_00d1b6d8 != 0) &&
      (pvVar2 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x534),param_2), pvVar2 != (void *)0x0
      )) && (*(char *)((int)pvVar2 + 4) == '\x02')) {
    bVar6 = true;
  }
  if (*(int *)(param_1 + 0x59c) != 0) {
    local_90 = local_8c;
    uVar3 = (*(code *)PTR_FUN_00af8c9c)();
    FUN_00403450((int)pvVar1 + 0xb4,uVar3);
    iStack_4 = 0;
    (**(code **)(**(int **)(param_1 + 0x59c) + 0x1d8))(local_90,1,1);
    uStack_10 = 0xffffffff;
    if (_Stack_ac.LockSemaphore != &_Stack_ac.SpinCount) {
      free(_Stack_ac.LockSemaphore);
    }
    (**(code **)(**(int **)(param_1 + 0x59c) + 0x34c))();
    iVar5 = DAT_00d1b6d8;
  }
  if (*(int **)(param_1 + 0x66c) == (int *)0x0) goto LAB_008eeeca;
  (**(code **)(**(int **)(param_1 + 0x66c) + 0x268))();
  (**(code **)(**(int **)(param_1 + 0x66c) + 0x160))(1,0xffffffff);
  if ((DAT_00d1b644 == 0) || (*(int *)(DAT_00d1b644 + 0xfc) != iStack_4)) {
    if (!bVar6) {
      pcVar9 = "You must first visit this map before INC can take you here!";
      goto LAB_008eeea8;
    }
    if ((DAT_00d1b6d8 == 0) ||
       (lVar8 = FUN_0040ccb0(),
       lVar8 <= CONCAT44((*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -
                         (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728)),
                         *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728)))) {
      pcVar9 = "Click to have INC take you here for:";
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x66c) + 0x160))(1,0xffff2020);
      pcVar9 = "To have INC take you here costs:";
    }
    iVar5 = **(int **)(param_1 + 0x66c);
    uVar3 = FUN_007a6de0(pcVar9,0xffffffff);
    (**(code **)(iVar5 + 0x250))(uVar3);
    (**(code **)(**(int **)(param_1 + 0x66c) + 0x250))(&DAT_00a15104);
    if (DAT_00d1b6d8 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = FUN_0040ccb0();
    }
    FUN_00977a30(DAT_00d1ad30,uVar7);
  }
  else {
    pcVar9 = "Click this button to have INC take you to a local repair station:";
LAB_008eeea8:
    (**(code **)(**(int **)(param_1 + 0x66c) + 0x1d8))(pcVar9,1,1);
  }
  (**(code **)(**(int **)(param_1 + 0x66c) + 0x34c))();
  iVar5 = DAT_00d1b6d8;
LAB_008eeeca:
  if (*(int *)(param_1 + 0x678) != 0) {
    if ((((DAT_00d1b644 == 0) || (*(uint *)(DAT_00d1b644 + 0xfc) == param_2)) || (iVar5 == 0)) ||
       ((0 < *(int *)(iVar5 + 0x6b4) ||
        (lVar8 = FUN_0040ccb0(),
        lVar8 <= CONCAT44((*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -
                          (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728)),
                          *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728)))))) {
      (**(code **)(**(int **)(param_1 + 0x678) + 0xd4))(bVar6);
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x678) + 0xd4))(0);
    }
    (**(code **)(**(int **)(param_1 + 0x678) + 0x34c))();
  }
  if (*(int **)(param_1 + 0x574) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x574) + 0x50))("sec_unknown.dds",1,0);
    *(undefined1 *)(*(int *)(param_1 + 0x574) + 0xd7) = 0;
    (**(code **)(**(int **)(param_1 + 0x574) + 0x34c))();
  }
  bVar6 = *(uint *)(DAT_00d1b644 + 0xfc) == param_2;
  if (*(int **)(param_1 + 0x674) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x674) + 4))(!bVar6);
  }
  if (*(int *)(param_1 + 0x67c) != 0) {
    FUN_008edf80(param_1,param_2);
    *(bool *)(*(int *)(param_1 + 0x67c) + 0x4fc) = bVar6;
    (**(code **)(**(int **)(param_1 + 0x67c) + 0x444))();
    if (*(int *)(param_1 + 0x680) == 0) {
      (**(code **)(**(int **)(param_1 + 0x67c) + 0xcc))(0);
    }
    else {
      FUN_0084fbd0();
      (**(code **)(**(int **)(param_1 + 0x67c) + 0x54))(*(undefined4 *)(param_1 + 0x680),1,0,0);
      (**(code **)(**(int **)(param_1 + 0x67c) + 0xcc))(1);
      FUN_008edc80(param_1,param_2);
    }
    (**(code **)(**(int **)(param_1 + 0x67c) + 0x34c))();
  }
  ppuStack_d4 = &PTR_FUN_00a39350;
  uStack_d0 = 0;
  uStack_cc = 0;
  uStack_c8 = 0;
  uStack_94 = 0xffffffff;
  InitializeCriticalSection(&_Stack_c4);
  InitializeCriticalSection(&_Stack_ac);
  iStack_4 = 1;
  param_1 = param_1 + 0x5b0;
  piVar4 = (int *)FUN_0040e490(param_1);
  while (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 4))(0);
    FUN_0040e230(&ppuStack_d4);
    piVar4 = (int *)FUN_0040e490(param_1);
  }
  iVar5 = FUN_0040e490(&ppuStack_d4);
  while (iVar5 != 0) {
    FUN_0040e230(param_1);
    iVar5 = FUN_0040e490(&ppuStack_d4);
  }
  iStack_4 = 0xffffffff;
  FUN_0040e1e0();
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
