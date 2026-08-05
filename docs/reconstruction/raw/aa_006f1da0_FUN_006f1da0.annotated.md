# Annotated low-level: FUN_006f1da0

| Field | Value |
|---|---|
| Stable ID | `aa_006f1da0` |
| VA | `0x006f1da0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006f1da0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006f1da0(int param_1,undefined1 *param_2,int param_3,int *param_4)

{
  if ((0x15 < *(int *)(param_3 + 8)) && (*param_4 <= *(int *)(param_1 + 0x14))) {
    *param_2 = 0;
    return;
  }
  *param_2 = 1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
