# Annotated low-level: FUN_0054cac0

| Field | Value |
|---|---|
| Stable ID | `aa_0054cac0` |
| VA | `0x0054cac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0054cac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0054cac0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(float *)(param_1 + 0xe0) != g_flZero) {
    FUN_005781b0(param_3,param_2,"conversion_percent] (item converts to %% sell value)\n",1);
  }
  FUN_00578190(param_1,param_2,param_3);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
