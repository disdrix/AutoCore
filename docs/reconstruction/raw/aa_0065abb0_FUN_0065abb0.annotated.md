# Annotated low-level: FUN_0065abb0

| Field | Value |
|---|---|
| Stable ID | `aa_0065abb0` |
| VA | `0x0065abb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0065abb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0065abb0(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_009e46ec;
  (**(code **)(*DAT_00b05060 + 4))(param_1[6]);
  piVar1 = (int *)(param_1[4] + -4);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    FUN_00638180();
  }
  piVar1 = (int *)(param_1[3] + -4);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    FUN_00638180();
  }
  *param_1 = &PTR_LAB_009cc290;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
