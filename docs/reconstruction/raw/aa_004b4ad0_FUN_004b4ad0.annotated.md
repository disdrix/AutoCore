# Annotated low-level: FUN_004b4ad0

| Field | Value |
|---|---|
| Stable ID | `aa_004b4ad0` |
| VA | `0x004b4ad0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004b4ad0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004b4ad0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *unaff_retaddr;
  
  if ((*param_1 != 0) && (param_1[1] != 0)) {
    uVar1 = (**(code **)(*(int *)param_1[1] + 0x188))(param_3);
    *unaff_retaddr = uVar1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
