# Annotated low-level: FUN_005ded20

| Field | Value |
|---|---|
| Stable ID | `aa_005ded20` |
| VA | `0x005ded20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ded20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __fastcall FUN_005ded20(undefined4 *param_1)

{
  short *psVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  *(undefined2 *)((int)param_1 + 6) = 1;
  *param_1 = &PTR_FUN_009dbae4;
  uVar3 = (**(code **)(*DAT_00d030f0 + 4))(1);
  FUN_00631fd0(uVar3);
  uVar3 = (**(code **)(*DAT_00d030f0 + 4))(2);
  FUN_00631fd0(uVar3);
  puVar2 = (undefined4 *)param_1[4];
  psVar1 = (short *)((int)puVar2 + 6);
  *psVar1 = *psVar1 + -1;
  if (*psVar1 == 0) {
    (**(code **)*puVar2)(1);
  }
  puVar2 = (undefined4 *)param_1[7];
  *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;
  if (*(short *)((int)puVar2 + 6) == 0) {
    (**(code **)*puVar2)(1);
  }
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
