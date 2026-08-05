# Annotated low-level: FUN_004ffe60

| Field | Value |
|---|---|
| Stable ID | `aa_004ffe60` |
| VA | `0x004ffe60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ffe60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004ffe60(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  undefined1 auStack_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009a2df4;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined ***)(param_1 + -0x670) = &PTR_Vehicle_TryActivatePhysics_009cd77c;
  *(undefined ***)(param_1 + -0x630) = &PTR_FUN_009cd740;
  *(undefined ***)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c + param_1) = &PTR_LAB_009cd47c;
  iVar3 = *(int *)(*(int *)(param_1 + -0x66c) + 4);
  *(int *)(iVar3 + -0x670 + param_1) = iVar3 + -0x66c;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c0 + param_1) = 0;
  local_4 = 6;
  if (*(void **)(param_1 + -0x4cc) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(param_1 + -0x4cc));
  }
  *(undefined4 *)(param_1 + -0x4cc) = 0;
  if (*(undefined4 **)(param_1 + -0x3ec) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + -0x3ec))(1);
  }
  *(undefined4 *)(param_1 + -0x3ec) = 0;
  (**(code **)(*(int *)(param_1 + -0x630) + 4))();
  iVar3 = *(int *)(param_1 + -0x2b8);
  if (iVar3 != 0) {
    puVar1 = *(undefined4 **)(iVar3 + 4);
    if (puVar1 != *(undefined4 **)(iVar3 + 8)) {
      if (*(undefined4 **)*puVar1 != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)*puVar1)(1);
      }
      *(undefined4 *)*puVar1 = 0;
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)*puVar1);
    }
    iVar3 = *(int *)(param_1 + -0x2b8);
    if (*(void **)(iVar3 + 4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(*(void **)(iVar3 + 4));
    }
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    pvVar2 = *(void **)(param_1 + -0x2b8);
    if (pvVar2 != (void *)0x0) {
      if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(*(void **)((int)pvVar2 + 4));
      }
      *(undefined4 *)((int)pvVar2 + 4) = 0;
      *(undefined4 *)((int)pvVar2 + 8) = 0;
      *(undefined4 *)((int)pvVar2 + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar2);
    }
    *(undefined4 *)(param_1 + -0x2b8) = 0;
  }
  if (*(int *)(param_1 + -0x3f0) != 0) {
    FUN_00564260((int *)(param_1 + -0x670));
    *(undefined4 *)(param_1 + -0x3f0) = 0;
  }
  if (*(int *)(param_1 + -0x3fc) != 0) {
    *(undefined4 *)(*(int *)(param_1 + -0x3fc) + 0x278) = 0;
    *(undefined4 *)(param_1 + -0x3fc) = 0;
  }
  if (*(int *)(param_1 + -0x3f8) != 0) {
    *(undefined4 *)(*(int *)(param_1 + -0x3f8) + 0x274) = 0;
    *(undefined4 *)(param_1 + -0x3f8) = 0;
  }
  (**(code **)(*(int *)(param_1 + -0x670) + 4))();
  if (*(int *)(param_1 + -0x3c0) != 0) {
    FUN_00570f50();
    if (*(undefined4 **)(param_1 + -0x3c0) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + -0x3c0))(1);
    }
    *(undefined4 *)(param_1 + -0x3c0) = 0;
  }
  piVar4 = (int *)(param_1 + -0x324);
  iVar3 = 8;
  do {
    if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar4)(1);
    }
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pvVar2 = *(void **)(param_1 + -0x334);
  if (pvVar2 != (void *)0x0) {
    FUN_004a2670();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar2);
  }
  *(undefined4 *)(param_1 + -0x334) = 0;
  if (*(undefined4 **)(param_1 + -0x2c0) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + -0x2c0))(1);
  }
  *(undefined4 *)(param_1 + -0x2c0) = 0;
  if (*(void **)(param_1 + -0x410) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + -0x410));
  }
  *(undefined4 *)(param_1 + -0x410) = 0;
  if (*(undefined4 **)(param_1 + -0x578) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + -0x578))(1);
  }
  *(undefined4 *)(param_1 + -0x578) = 0;
  *(undefined4 *)(param_1 + -0x418) = 0;
  if (*(void **)(param_1 + -0x68) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(param_1 + -0x68));
  }
  *(undefined4 *)(param_1 + -0x68) = 0;
  *(undefined4 *)(param_1 + -100) = 0;
  *(undefined4 *)(param_1 + -0x60) = 0;
  if (*(void **)(param_1 + -0x78) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(param_1 + -0x78));
  }
  *(undefined4 *)(param_1 + -0x78) = 0;
  *(undefined4 *)(param_1 + -0x74) = 0;
  *(undefined4 *)(param_1 + -0x70) = 0;
  if (*(void **)(param_1 + -0x88) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(param_1 + -0x88));
  }
  *(undefined4 *)(param_1 + -0x88) = 0;
  *(undefined4 *)(param_1 + -0x84) = 0;
  *(undefined4 *)(param_1 + -0x80) = 0;
  if (*(void **)(param_1 + -0x2dc) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(param_1 + -0x2dc));
  }
  *(undefined4 *)(param_1 + -0x2dc) = 0;
  *(undefined4 *)(param_1 + -0x2d8) = 0;
  *(undefined4 *)(param_1 + -0x2d4) = 0;
  if (*(void **)(param_1 + -0x340) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(param_1 + -0x340));
  }
  *(undefined4 *)(param_1 + -0x340) = 0;
  *(undefined4 *)(param_1 + -0x33c) = 0;
  *(undefined4 *)(param_1 + -0x338) = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_00407140(auStack_10,**(undefined4 **)(param_1 + -0x3b4),*(undefined4 **)(param_1 + -0x3b4));
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + -0x3b4));
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
