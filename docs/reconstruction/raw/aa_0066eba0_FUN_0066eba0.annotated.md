# Annotated low-level: FUN_0066eba0

| Field | Value |
|---|---|
| Stable ID | `aa_0066eba0` |
| VA | `0x0066eba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0066eba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0066eba0(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_0066f320();
    return;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
