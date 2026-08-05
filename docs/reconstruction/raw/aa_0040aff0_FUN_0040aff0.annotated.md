# Annotated low-level: FUN_0040aff0

| Field | Value |
|---|---|
| Stable ID | `aa_0040aff0` |
| VA | `0x0040aff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040aff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0040aff0(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x228);
  param_2[1] = *(undefined4 *)(param_1 + 0x22c);
  param_2[2] = *(undefined4 *)(param_1 + 0x230);
  param_2[3] = *(undefined4 *)(param_1 + 0x234);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
