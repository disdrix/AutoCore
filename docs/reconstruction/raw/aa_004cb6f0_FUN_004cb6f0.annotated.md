# Annotated low-level: FUN_004cb6f0

| Field | Value |
|---|---|
| Stable ID | `aa_004cb6f0` |
| VA | `0x004cb6f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cb6f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_004cb6f0(undefined4 *param_1,int *param_2,int *param_3,int *param_4)

{
  if (param_2 == param_3) {
    *param_1 = param_2;
    return;
  }
  do {
    if (((*param_2 == *param_4) && (param_2[1] == param_4[1])) &&
       ((char)param_2[2] == (char)param_4[2])) break;
    param_2 = param_2 + 4;
  } while (param_2 != param_3);
  *param_1 = param_2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
