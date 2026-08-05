# Annotated low-level: FUN_005bdea0

| Field | Value |
|---|---|
| Stable ID | `aa_005bdea0` |
| VA | `0x005bdea0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005bdea0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005bdea0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  if (pvVar2 != *(void **)(param_1 + 4)) {
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar2);
  }
  FUN_005bddf0(**(undefined4 **)(param_1 + 4),param_2,param_3,param_3);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
