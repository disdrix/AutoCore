# Annotated low-level: FUN_004cd5d0

| Field | Value |
|---|---|
| Stable ID | `aa_004cd5d0` |
| VA | `0x004cd5d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cd5d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004cd5d0(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0xe82c + param_2 * 4);
  *piVar1 = *piVar1 + 1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
