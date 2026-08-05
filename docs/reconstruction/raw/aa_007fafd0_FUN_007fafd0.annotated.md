# Annotated low-level: FUN_007fafd0

| Field | Value |
|---|---|
| Stable ID | `aa_007fafd0` |
| VA | `0x007fafd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fafd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007fafd0(undefined4 *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b328e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_00a8467c;
  local_4 = 0;
  puVar3 = param_1 + 0x126;
  iVar2 = 3;
  do {
    if ((void *)*puVar3 != (void *)0x0) {
      operator_delete__((void *)*puVar3);
    }
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_007f9c60();
  pvVar1 = (void *)param_1[0x14d];
  if (pvVar1 != (void *)0x0) {
    FUN_0096efd0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  param_1[0x14d] = 0;
  if ((void *)param_1[0x14e] != (void *)0x0) {
    operator_delete__((void *)param_1[0x14e]);
  }
  param_1[0x14e] = 0;
  if ((void *)param_1[0x14f] != (void *)0x0) {
    operator_delete__((void *)param_1[0x14f]);
  }
  param_1[0x14f] = 0;
  local_4 = 0xffffffff;
  FUN_007b5be0();
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
