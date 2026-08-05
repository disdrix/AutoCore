# Annotated low-level: FUN_006f1ef0

| Field | Value |
|---|---|
| Stable ID | `aa_006f1ef0` |
| VA | `0x006f1ef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006f1ef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006f1ef0(uint param_1)

{
  if (param_1 < 0x100) {
    FUN_006f3a00(9,param_1);
    return;
  }
  if (param_1 < 0x10000) {
    FUN_006f3a60(10,param_1);
    return;
  }
  FUN_006f3c40(0xb,param_1);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
