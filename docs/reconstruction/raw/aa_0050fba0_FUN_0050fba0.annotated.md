# Annotated low-level: FUN_0050fba0

| Field | Value |
|---|---|
| Stable ID | `aa_0050fba0` |
| VA | `0x0050fba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0050fba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_0050fba0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  FUN_0050f270(param_2,param_3,param_4,param_1,param_4);
  return param_2 + param_3 * 300;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
