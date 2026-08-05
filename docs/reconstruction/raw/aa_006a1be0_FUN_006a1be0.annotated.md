# Annotated low-level: FUN_006a1be0

| Field | Value |
|---|---|
| Stable ID | `aa_006a1be0` |
| VA | `0x006a1be0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a1be0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
float10 FUN_006a1be0(float param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_006a35e0();
  return ((float10)param_2 - (float10)param_1) * fVar1 + (float10)param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
