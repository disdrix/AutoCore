# Annotated low-level: FUN_0076cec0

| Field | Value |
|---|---|
| Stable ID | `aa_0076cec0` |
| VA | `0x0076cec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0076cec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined * FUN_0076cec0(undefined4 param_1,char *param_2)

{
  _vsnprintf(&DAT_00d19530,0x1000,param_2,&stack0x0000000c);
  return &DAT_00d19530;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
