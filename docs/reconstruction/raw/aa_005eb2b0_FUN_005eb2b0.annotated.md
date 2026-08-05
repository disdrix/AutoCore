# Annotated low-level: FUN_005eb2b0

| Field | Value |
|---|---|
| Stable ID | `aa_005eb2b0` |
| VA | `0x005eb2b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005eb2b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005eb2b0(int param_1,int *param_2)

{
  short *psVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined1 auStack_30 [44];
  
  *(short *)((int)param_2 + 6) = *(short *)((int)param_2 + 6) + 1;
  uVar3 = (**(code **)(*param_2 + 0x14))();
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x54) = uVar3;
  psVar1 = (short *)((int)puVar2 + 6);
  *psVar1 = *psVar1 + -1;
  if (*psVar1 == 0) {
    (**(code **)*puVar2)(1);
  }
  *(int **)(param_1 + 0xc) = param_2;
  if (*(int *)(param_1 + 8) != 0) {
    (**(code **)(*param_2 + 0x18))
              (param_1 + 0x80,*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0xcc) + 8),auStack_30
              );
    FUN_00634450(&stack0xffffffc4);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
