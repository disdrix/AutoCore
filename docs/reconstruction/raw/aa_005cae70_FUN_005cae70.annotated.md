# Annotated low-level: FUN_005cae70

| Field | Value |
|---|---|
| Stable ID | `aa_005cae70` |
| VA | `0x005cae70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005cae70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_005cae70(int param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_00404d70(param_2);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = *(int *)(iVar2 + 0x3c);
  if (iVar3 == 0) {
    FUN_004f1e20(0,1);
    iVar3 = *(int *)(iVar2 + 0x3c);
    if (iVar3 == 0) {
      return 0;
    }
  }
  iVar4 = *(int *)(*(int *)(param_1 + -0x10c) + 4);
  iVar2 = iVar4 + -0x10c + param_1;
  iVar4 = (int)*(short *)(iVar4 + -0x22 + param_1) + (int)*(short *)(iVar4 + -0x24 + param_1);
  if (0x50 < iVar4) {
    iVar4 = 0x50;
  }
  sVar1 = *(short *)(iVar3 + 0x3f0);
  iVar3 = CONCAT22((short)((uint)iVar3 >> 0x10),sVar1);
  if ((short)iVar4 < sVar1) {
    if (0x50 < sVar1) {
      *(undefined2 *)(iVar2 + 0xea) = 0x50;
      return 1;
    }
    iVar3 = (int)sVar1;
    *(short *)(iVar2 + 0xea) = sVar1;
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
