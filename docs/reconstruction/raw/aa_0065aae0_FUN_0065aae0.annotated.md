# Annotated low-level: FUN_0065aae0

| Field | Value |
|---|---|
| Stable ID | `aa_0065aae0` |
| VA | `0x0065aae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0065aae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0065aae0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[2];
  *param_1 = &PTR_FUN_009e5ee0;
  *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;
  if (*(short *)((int)puVar1 + 6) == 0) {
    (**(code **)*puVar1)(1);
  }
  *param_1 = &PTR_LAB_009cc290;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
