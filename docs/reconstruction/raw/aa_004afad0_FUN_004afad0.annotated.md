# Annotated low-level: FUN_004afad0

| Field | Value |
|---|---|
| Stable ID | `aa_004afad0` |
| VA | `0x004afad0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004afad0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004afad0(int param_1,int param_2,uint param_3,undefined2 *param_4)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009a13b0;
  local_10 = ExceptionList;
  iVar6 = *(int *)(param_1 + 4);
  param_4 = (undefined2 *)CONCAT22(*param_4,param_4._0_2_);
  if (iVar6 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc) - iVar6 >> 1;
  }
  uVar8 = CONCAT44(iVar6,iVar2);
  if (param_3 != 0) {
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(param_1 + 8) - iVar6 >> 1;
    }
    ExceptionList = &local_10;
    if (0x7fffffffU - iVar6 < param_3) {
      ExceptionList = &local_10;
      uVar8 = FUN_004aecb0();
    }
    iVar6 = (int)((ulonglong)uVar8 >> 0x20);
    uVar3 = (uint)uVar8;
    if (iVar6 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 8) - iVar6 >> 1;
    }
    if (uVar3 < iVar2 + param_3) {
      if (0x7fffffff - (uVar3 >> 1) < uVar3) {
        uVar3 = 0;
      }
      else {
        uVar3 = uVar3 + (uVar3 >> 1);
      }
      if (iVar6 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(param_1 + 8) - iVar6 >> 1;
      }
      if (uVar3 < iVar2 + param_3) {
        if (iVar6 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(param_1 + 8) - iVar6 >> 1;
        }
        uVar3 = iVar6 + param_3;
      }
      pvVar4 = operator_new(uVar3 * 2);
      local_8 = 0;
      iVar6 = FUN_0068b7a0(*(undefined4 *)(param_1 + 4),param_2,pvVar4,param_1,param_2);
      FUN_004aefa0(iVar6,param_3,(int)&param_4 + 2,param_1,param_2);
      FUN_0068b7a0(param_2,*(undefined4 *)(param_1 + 8),iVar6 + param_3 * 2,param_1,param_2);
      pvVar1 = *(void **)(param_1 + 4);
      if (pvVar1 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(param_1 + 8) - (int)pvVar1 >> 1;
      }
      if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar1);
      }
      *(void **)(param_1 + 0xc) = (void *)(uVar3 * 2 + (int)pvVar4);
      *(void **)(param_1 + 8) = (void *)((int)pvVar4 + (param_3 + iVar6) * 2);
      *(void **)(param_1 + 4) = pvVar4;
      ExceptionList = local_10;
      return;
    }
    iVar6 = *(int *)(param_1 + 8);
    iVar2 = param_3 * 2;
    if ((uint)(iVar6 - param_2 >> 1) < param_3) {
      FUN_0068b7a0(param_2,iVar6,iVar2 + param_2,param_1,iVar2);
      local_8 = 2;
      FUN_004af9b0(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2 >> 1),
                   (int)&param_4 + 2);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar2;
      FUN_007191a0(param_2,*(int *)(param_1 + 8) + param_3 * -2,(int)&param_4 + 2);
      ExceptionList = local_10;
      return;
    }
    iVar7 = iVar6 + param_3 * -2;
    uVar5 = FUN_0068b7a0(iVar7,iVar6,iVar6,param_1,iVar2);
    *(undefined4 *)(param_1 + 8) = uVar5;
    FUN_004aee20(param_2,iVar7,iVar6);
    FUN_007191a0(param_2,iVar2 + param_2,(int)&param_4 + 2);
  }
  ExceptionList = local_10;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
