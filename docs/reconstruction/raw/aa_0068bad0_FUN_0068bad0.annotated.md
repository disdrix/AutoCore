# Annotated low-level: FUN_0068bad0

| Field | Value |
|---|---|
| Stable ID | `aa_0068bad0` |
| VA | `0x0068bad0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0068bad0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_0068bad0(int param_1,int param_2)

{
  return *(int *)(param_1 + 0xb4) + param_2 * 8;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
