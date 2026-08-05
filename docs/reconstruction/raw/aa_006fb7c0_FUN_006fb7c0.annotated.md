# Annotated low-level: FUN_006fb7c0

| Field | Value |
|---|---|
| Stable ID | `aa_006fb7c0` |
| VA | `0x006fb7c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006fb7c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
byte __fastcall FUN_006fb7c0(float *param_1)

{
  float *in_EAX;
  
  return (DAT_00bc5638 < ABS(param_1[2] - in_EAX[2])) << 1 |
         (DAT_00bc5634 < ABS(param_1[1] - in_EAX[1])) << 2 |
         (DAT_00bc5630 < ABS(*param_1 - *in_EAX)) * -8 & 0xeU;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
