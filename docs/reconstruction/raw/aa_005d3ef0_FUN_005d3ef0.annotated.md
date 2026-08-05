# Annotated low-level: FUN_005d3ef0

| Field | Value |
|---|---|
| Stable ID | `aa_005d3ef0` |
| VA | `0x005d3ef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d3ef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005d3ef0(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined1 uVar3;
  float fVar4;
  
  FUN_00507260(param_2);
  iVar2 = *(int *)(param_1 + 0x3c);
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(iVar2 + 0xb0);
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(iVar2 + 0xb4);
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(iVar2 + 0xb8);
  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(iVar2 + 0xbc);
  iVar2 = *(int *)(param_1 + 0x3c);
  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(iVar2 + 0x30);
  *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(iVar2 + 0x34);
  *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(iVar2 + 0x38);
  *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(iVar2 + 0x3c);
  iVar2 = *(int *)(param_1 + 0x3c);
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(iVar2 + 0x40);
  *(undefined4 *)(param_2 + 0x44) = *(undefined4 *)(iVar2 + 0x44);
  *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(iVar2 + 0x48);
  *(undefined4 *)(param_2 + 0x4c) = *(undefined4 *)(iVar2 + 0x4c);
  iVar2 = *(int *)(param_1 + 0x3c);
  *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(iVar2 + 0x50);
  *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(iVar2 + 0x54);
  *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(iVar2 + 0x58);
  *(undefined4 *)(param_2 + 0x5c) = *(undefined4 *)(iVar2 + 0x5c);
  uVar3 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x18))();
  *(undefined1 *)(param_2 + 0xb4) = uVar3;
  (**(code **)(**(int **)(param_1 + 0x3c) + 0x24))(param_2 + 0x60);
  fVar1 = *(float *)(*(int *)(param_1 + 0x3c) + 0x2c);
  fVar4 = 0.0;
  if (fVar1 != 0.0) {
    fVar4 = g_flOne / fVar1;
  }
  *(float *)(param_2 + 0xa0) = fVar4;
  iVar2 = *(int *)(param_1 + 0x3c);
  *(undefined4 *)(param_2 + 0x90) = *(undefined4 *)(iVar2 + 0x20);
  *(undefined4 *)(param_2 + 0x94) = *(undefined4 *)(iVar2 + 0x24);
  *(undefined4 *)(param_2 + 0x98) = *(undefined4 *)(iVar2 + 0x28);
  *(undefined4 *)(param_2 + 0x9c) = *(undefined4 *)(iVar2 + 0x2c);
  *(undefined4 *)(param_2 + 0xac) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(param_2 + 0xa4) = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x14);
  *(undefined4 *)(param_2 + 0xa8) = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x18);
  *(undefined4 *)(param_2 + 0xb0) = *(undefined4 *)(param_1 + 0x50);
  if (*(int **)(param_1 + 0x54) != (int *)0x0) {
    uVar3 = (**(code **)(**(int **)(param_1 + 0x54) + 0x1c))();
    *(undefined1 *)(param_2 + 0xb5) = uVar3;
    return;
  }
  *(undefined1 *)(param_2 + 0xb5) = 1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
