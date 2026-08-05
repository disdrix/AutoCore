# Annotated low-level: FUN_0084ffc0

| Field | Value |
|---|---|
| Stable ID | `aa_0084ffc0` |
| VA | `0x0084ffc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0084ffc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0084ffc0(void)

{
  void *pvVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  
  pvVar1 = *(void **)(in_EAX + 0x5a0);
  if (pvVar1 != (void *)0x0) {
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(in_EAX + 0x5a4);
  *(undefined4 *)(in_EAX + 0x5a0) = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(in_EAX + 0x5a8);
  *(undefined4 *)(in_EAX + 0x5a4) = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  pvVar1 = *(void **)(in_EAX + 0x5ac);
  *(undefined4 *)(in_EAX + 0x5a8) = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  *(undefined4 *)(in_EAX + 0x5ac) = 0;
  puVar3 = (undefined4 *)(in_EAX + 0x5b0);
  iVar2 = 0x14;
  do {
    pvVar1 = (void *)*puVar3;
    if (pvVar1 != (void *)0x0) {
      FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar3 = (undefined4 *)(in_EAX + 0x600);
  iVar2 = 9;
  do {
    pvVar1 = (void *)*puVar3;
    if (pvVar1 != (void *)0x0) {
      FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
