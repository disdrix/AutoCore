# Annotated low-level: FUN_0048eef0

| Field | Value |
|---|---|
| Stable ID | `aa_0048eef0` |
| VA | `0x0048eef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0048eef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0048eef0(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0xb8) == 0) {
    DAT_00b04820 = (undefined1)param_2;
    return;
  }
  if (*(int *)(*(int *)(param_1 + 0xb8) + 0xe89c) != 0) {
    FUN_0079db80(param_2);
    DAT_00b04820 = (undefined1)param_2;
    return;
  }
  DAT_00b04820 = (undefined1)param_2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
