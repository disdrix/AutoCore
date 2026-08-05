# Annotated low-level: FUN_005bfa60

| Field | Value |
|---|---|
| Stable ID | `aa_005bfa60` |
| VA | `0x005bfa60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005bfa60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005bfa60(int param_1)

{
  FUN_005bf720();
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x14));
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
