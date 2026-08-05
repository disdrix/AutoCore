# Annotated low-level: FUN_005dec40

| Field | Value |
|---|---|
| Stable ID | `aa_005dec40` |
| VA | `0x005dec40` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005dec40`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_005dec40(undefined4 *param_1,byte param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = param_1[6];
  *param_1 = &PTR_LAB_009db9e0;
  while (iVar1 != 0) {
    puVar2 = (undefined4 *)param_1[6];
    param_1[6] = *puVar2;
    (*(code *)PTR__aligned_free_00af3bd0)(puVar2);
    iVar1 = param_1[6];
  }
  *param_1 = &PTR_LAB_009db9b4;
  if ((param_2 & 1) == 0) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(param_1);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
