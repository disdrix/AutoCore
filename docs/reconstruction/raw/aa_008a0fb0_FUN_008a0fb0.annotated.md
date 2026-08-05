# Annotated low-level: FUN_008a0fb0

| Field | Value |
|---|---|
| Stable ID | `aa_008a0fb0` |
| VA | `0x008a0fb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008a0fb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_008a0fb0(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x50c) + param_2 < 0) {
    FUN_008a0ed0();
    return;
  }
  FUN_008a0ed0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
