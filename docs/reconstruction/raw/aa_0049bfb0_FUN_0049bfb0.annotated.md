# Annotated low-level: FUN_0049bfb0

| Field | Value |
|---|---|
| Stable ID | `aa_0049bfb0` |
| VA | `0x0049bfb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0049bfb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0049bfb0(undefined4 *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int *piVar1;
  
  if (param_2 == param_3) {
    *param_1 = param_4;
    return;
  }
  do {
    piVar1 = param_4;
    if (*param_2 != *param_5) {
      piVar1 = param_4 + 1;
      *param_4 = *param_2;
    }
    param_2 = param_2 + 1;
    param_4 = piVar1;
  } while (param_2 != param_3);
  *param_1 = piVar1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
