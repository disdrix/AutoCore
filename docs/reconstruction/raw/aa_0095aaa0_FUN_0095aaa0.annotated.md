# Annotated low-level: FUN_0095aaa0

| Field | Value |
|---|---|
| Stable ID | `aa_0095aaa0` |
| VA | `0x0095aaa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0095aaa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0095aaa0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00a152ec;
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete__((void *)param_1[1]);
  }
  param_1[1] = 0;
  if ((void *)param_1[2] != (void *)0x0) {
    operator_delete__((void *)param_1[2]);
  }
  param_1[2] = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
