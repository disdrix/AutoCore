# Annotated low-level: FUN_005bf7d0

| Field | Value |
|---|---|
| Stable ID | `aa_005bf7d0` |
| VA | `0x005bf7d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005bf7d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005bf7d0(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  param_2 = ((int)param_2 < 1) - 1 & param_2;
  uVar1 = *(int *)(param_1 + 4) * *(int *)(param_1 + 0x18) - 1;
  if ((int)uVar1 <= (int)param_2) {
    param_2 = uVar1;
  }
  param_3 = param_3 & ((int)param_3 < 1) - 1;
  uVar1 = *(int *)(param_1 + 8) * *(int *)(param_1 + 0x18) - 1;
  if ((int)param_3 < (int)uVar1) {
    uVar1 = param_3;
  }
  FUN_005bf530((int)param_2 % *(int *)(param_1 + 0x18),(int)uVar1 % *(int *)(param_1 + 0x18));
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
