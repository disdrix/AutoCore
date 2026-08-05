# Annotated low-level: FUN_006f7fe0

| Field | Value |
|---|---|
| Stable ID | `aa_006f7fe0` |
| VA | `0x006f7fe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006f7fe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006f7fe0(float *param_1,float *param_2,undefined4 *param_3)

{
  if (((*param_1 <= *param_2) && (param_1[1] <= *param_2)) && (param_1[2] <= *param_2)) {
    *param_3 = 0;
    return;
  }
  *param_3 = 1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
