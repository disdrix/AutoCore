# Annotated low-level: FUN_004ff6f0

| Field | Value |
|---|---|
| Stable ID | `aa_004ff6f0` |
| VA | `0x004ff6f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ff6f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004ff6f0(uint param_1)

{
  void *pvVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint local_4;
  
  FUN_004fecb0();
  FUN_004fcc40();
  *(undefined1 *)(param_1 + 0x4a0) = 0;
  local_4 = param_1 & 0xffffff00;
  piVar4 = (int *)(param_1 + 0x300);
  piVar3 = (int *)(param_1 + 0x334);
  do {
    if (*piVar4 != 0) {
      FUN_00583f10(0,*piVar4,1,local_4);
    }
    if ((int *)*piVar3 != (int *)0x0) {
      (**(code **)(*(int *)*piVar3 + 0x1c))();
      if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar3)(1);
      }
    }
    *piVar3 = 0;
    if ((undefined4 *)piVar3[-1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar3[-1])(1);
    }
    pvVar1 = (void *)piVar3[-2];
    piVar3[-1] = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_0074ecf0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    iVar5 = *piVar4;
    piVar3[-2] = 0;
    if (iVar5 != 0) {
      pvVar1 = *(void **)(iVar5 + 0x78);
      if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar1);
      }
      if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar4)(1);
      }
    }
    cVar2 = (char)local_4 + '\x01';
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
    piVar3 = piVar3 + 3;
    local_4 = CONCAT31(local_4._1_3_,cVar2);
  } while (cVar2 < '\x03');
  piVar4 = (int *)(param_1 + 0x30c);
  iVar5 = 8;
  do {
    if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar4)(1);
    }
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((*(int *)(param_1 + 0x360) != 0) &&
     (pvVar1 = *(void **)(*(int *)(param_1 + 0x360) + 0x78), pvVar1 != (void *)0x0)) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  if (*(undefined4 **)(param_1 + 0x360) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x360))(1);
  }
  *(undefined4 *)(param_1 + 0x360) = 0;
  if (*(undefined4 **)(param_1 + 0x364) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x364))(1);
  }
  *(undefined4 *)(param_1 + 0x364) = 0;
  thunk_FUN_00584290();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
