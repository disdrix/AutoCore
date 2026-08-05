# Annotated low-level: FUN_005ef3a0

| Field | Value |
|---|---|
| Stable ID | `aa_005ef3a0` |
| VA | `0x005ef3a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ef3a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
float10 FUN_005ef3a0(float param_1,float param_2)

{
  if (param_1 <= param_2) {
    param_1 = param_2;
  }
  return (float10)param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
