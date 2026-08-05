# Annotated low-level: FUN_0043ade0

| Field | Value |
|---|---|
| Stable ID | `aa_0043ade0` |
| VA | `0x0043ade0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0043ade0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0043ade0(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009bdcb1;
  local_c = ExceptionList;
  local_4 = 0;
  if (param_1 != (undefined4 *)0x0) {
    if (param_2 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(param_2 + 4);
    }
    piVar1 = (int *)*piVar2;
    if ((piVar1 != (int *)0x0) &&
       (ExceptionList = &local_c, piVar1[1] = piVar1[1] + 1, piVar1[1] == 1)) {
      (**(code **)(*piVar1 + 4))();
    }
    param_1[1] = *piVar2;
    *param_1 = &PTR_FUN_00a9da78;
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
