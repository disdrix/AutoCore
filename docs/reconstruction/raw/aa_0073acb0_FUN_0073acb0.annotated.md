# Annotated low-level: FUN_0073acb0

| Field | Value |
|---|---|
| Stable ID | `aa_0073acb0` |
| VA | `0x0073acb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0073acb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
float10 __fastcall FUN_0073acb0(int param_1)

{
  FUN_00464900();
  return (float10)*(float *)(param_1 + 0x21c);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
