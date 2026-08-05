# Annotated low-level: FUN_0051ffb0

| Field | Value |
|---|---|
| Stable ID | `aa_0051ffb0` |
| VA | `0x0051ffb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0051ffb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0051ffb0(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x664 + param_2 * 4) = param_3;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
