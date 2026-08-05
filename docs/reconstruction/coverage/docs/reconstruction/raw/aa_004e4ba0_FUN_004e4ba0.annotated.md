# Annotated low-level: FUN_004e4ba0

| Field | Value |
|---|---|
| Stable ID | `aa_004e4ba0` |
| VA | `0x004e4ba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004e4ba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_004e4ba0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  FUN_004e2eb0(param_2,param_3,param_4,param_1,param_4);
  return param_3 * 0x40 + param_2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
