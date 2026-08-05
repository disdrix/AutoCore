# Annotated low-level: FUN_007abdd0

| Field | Value |
|---|---|
| Stable ID | `aa_007abdd0` |
| VA | `0x007abdd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007abdd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_007abdd0(int *param_1,undefined4 *param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  (**(code **)(*param_1 + 0x68))();
  *(undefined1 *)((int)param_1 + 0xbd) = param_3;
  param_1[0xad] = (int)param_2;
  if (param_2 != (undefined4 *)0x0) {
    (**(code **)*param_2)(param_1[0xa6]);
    uVar1 = (**(code **)(*param_1 + 0x1a0))();
    *(undefined4 *)(param_1[0xad] + 4) = uVar1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
