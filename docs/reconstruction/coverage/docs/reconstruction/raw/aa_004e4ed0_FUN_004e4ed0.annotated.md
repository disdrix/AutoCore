# Annotated low-level: FUN_004e4ed0

| Field | Value |
|---|---|
| Stable ID | `aa_004e4ed0` |
| VA | `0x004e4ed0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004e4ed0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004e4ed0(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  void *pvVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined4 local_54 [16];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009a2530;
  local_10 = ExceptionList;
  iVar6 = *(int *)(param_1 + 4);
  local_14 = &stack0xffffffa0;
  puVar7 = local_54;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *param_4;
    param_4 = param_4 + 1;
    puVar7 = puVar7 + 1;
  }
  if (iVar6 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 0xc) - iVar6 >> 6;
  }
  uVar8 = CONCAT44(iVar6,iVar5);
  if (param_3 != 0) {
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(param_1 + 8) - iVar6 >> 6;
    }
    ExceptionList = &local_10;
    if (0x3ffffffU - iVar6 < param_3) {
      ExceptionList = &local_10;
      uVar8 = FUN_004e1050();
    }
    iVar6 = (int)((ulonglong)uVar8 >> 0x20);
    uVar2 = (uint)uVar8;
    if (iVar6 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(param_1 + 8) - iVar6 >> 6;
    }
    if (uVar2 < iVar5 + param_3) {
      if (0x3ffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar6 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_1 + 8) - iVar6 >> 6;
      }
      if (uVar2 < iVar5 + param_3) {
        if (iVar6 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(param_1 + 8) - iVar6 >> 6;
        }
        uVar2 = iVar6 + param_3;
      }
      pvVar3 = operator_new(uVar2 * 0x40);
      local_8 = 0;
      iVar6 = FUN_004e2560(*(undefined4 *)(param_1 + 4),param_2,pvVar3,param_1,param_2);
      FUN_004e2eb0(iVar6,param_3,local_54,param_1,param_2);
      FUN_004e2560(param_2,*(undefined4 *)(param_1 + 8),iVar6 + param_3 * 0x40,param_1,param_2);
      pvVar1 = *(void **)(param_1 + 4);
      if (pvVar1 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(param_1 + 8) - (int)pvVar1 >> 6;
      }
      if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar1);
      }
      *(void **)(param_1 + 0xc) = (void *)(uVar2 * 0x40 + (int)pvVar3);
      *(void **)(param_1 + 8) = (void *)((param_3 + iVar6) * 0x40 + (int)pvVar3);
      *(void **)(param_1 + 4) = pvVar3;
      ExceptionList = local_10;
      return;
    }
    iVar6 = *(int *)(param_1 + 8);
    if ((uint)(iVar6 - param_2 >> 6) < param_3) {
      iVar5 = param_3 * 0x40;
      FUN_004e2560(param_2,iVar6,iVar5 + param_2,param_1,iVar5);
      local_8 = 2;
      FUN_004e4ba0(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2 >> 6),local_54);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar5;
      FUN_004e1320(param_2,*(int *)(param_1 + 8) + param_3 * -0x40,local_54);
      ExceptionList = local_10;
      return;
    }
    iVar5 = iVar6 + param_3 * -0x40;
    uVar4 = FUN_004e2560(iVar5,iVar6,iVar6,param_1,param_3 * 0x40);
    *(undefined4 *)(param_1 + 8) = uVar4;
    FUN_004e2500(param_2,iVar5,iVar6);
    FUN_004e1320(param_2,param_3 * 0x40 + param_2,local_54);
  }
  ExceptionList = local_10;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
