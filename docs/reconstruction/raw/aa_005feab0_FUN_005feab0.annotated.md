# Annotated low-level: FUN_005feab0

| Field | Value |
|---|---|
| Stable ID | `aa_005feab0` |
| VA | `0x005feab0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005feab0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005feab0(int param_1)

{
  *(undefined4 *)(param_1 + -0x1c) = 0;
  *(undefined4 *)(param_1 + -0x18) = 0;
  *(undefined2 *)(param_1 + -0x14) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
