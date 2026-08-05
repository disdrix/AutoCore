# Annotated low-level: FUN_0065ace0

| Field | Value |
|---|---|
| Stable ID | `aa_0065ace0` |
| VA | `0x0065ace0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0065ace0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0065ace0(int *param_1,int param_2)

{
  int *piVar1;
  
  param_2 = param_2 + 1;
  if (param_2 <= param_1[2]) {
    piVar1 = (int *)(*param_1 + param_2 * 4);
    do {
      if (*piVar1 != -1) {
        return;
      }
      param_2 = param_2 + 1;
      piVar1 = piVar1 + 1;
    } while (param_2 <= param_1[2]);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
