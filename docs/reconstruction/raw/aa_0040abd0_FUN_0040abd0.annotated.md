# Annotated low-level: FUN_0040abd0

| Field | Value |
|---|---|
| Stable ID | `aa_0040abd0` |
| VA | `0x0040abd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040abd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_0040abd0(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < 3)) {
    return *(undefined4 *)(param_1 + 0xd58 + param_2 * 4);
  }
  return 0xffffffff;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
