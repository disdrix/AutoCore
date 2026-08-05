# Annotated low-level: FUN_0094bfa0

| Field | Value |
|---|---|
| Stable ID | `aa_0094bfa0` |
| VA | `0x0094bfa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0094bfa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0094bfa0(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x10a0);
  if ((iVar1 != 0) && (DAT_00d1775e = (undefined1)param_1, *(int *)(iVar1 + 0x5b4) != 0)) {
    (**(code **)(**(int **)(iVar1 + 0x5b4) + 0x3c8))(param_1,1);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
