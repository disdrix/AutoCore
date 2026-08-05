# Annotated low-level: FUN_005fea70

| Field | Value |
|---|---|
| Stable ID | `aa_005fea70` |
| VA | `0x005fea70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fea70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_005fea70(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  FUN_004ce940();
  puVar1 = (undefined4 *)FUN_00508b10(param_2);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(param_1 + -0xe0,param_3,0);
    return 1;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
