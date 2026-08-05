# Annotated low-level: FUN_0053dee0

| Field | Value |
|---|---|
| Stable ID | `aa_0053dee0` |
| VA | `0x0053dee0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0053dee0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0053dee0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  *(uint *)(param_1 + 0x30) = g_dwClientTickMs;
  if (*(int *)(param_1 + 8) == 0) {
    puVar4 = (undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);
  }
  else {
    puVar4 = (undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0);
  }
  puVar1 = *(undefined4 **)(param_1 + 0x2c);
  *puVar1 = *puVar4;
  puVar1[1] = puVar4[1];
  puVar1[2] = puVar4[2];
  puVar1[3] = puVar4[3];
  if (*(int *)(param_1 + 8) == 0) {
    puVar4 = (undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1);
  }
  else {
    puVar4 = (undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x30);
  }
  iVar2 = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(iVar2 + 0x10) = *puVar4;
  *(undefined4 *)(iVar2 + 0x14) = puVar4[1];
  *(undefined4 *)(iVar2 + 0x18) = puVar4[2];
  *(undefined4 *)(iVar2 + 0x1c) = puVar4[3];
  if (*(int *)(param_1 + 8) != 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x3c);
    iVar3 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar2 + 0x40);
    *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(iVar2 + 0x44);
    *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar2 + 0x48);
    *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar2 + 0x4c);
    iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x3c);
    iVar3 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(iVar2 + 0x50);
    *(undefined4 *)(iVar3 + 0x34) = *(undefined4 *)(iVar2 + 0x54);
    *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(iVar2 + 0x58);
    *(undefined4 *)(iVar3 + 0x3c) = *(undefined4 *)(iVar2 + 0x5c);
    return;
  }
  iVar2 = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(iVar2 + 0x20) = 0;
  *(undefined4 *)(iVar2 + 0x24) = 0;
  *(undefined4 *)(iVar2 + 0x28) = 0;
  *(undefined4 *)(iVar2 + 0x2c) = 0;
  iVar2 = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(iVar2 + 0x30) = 0;
  *(undefined4 *)(iVar2 + 0x34) = 0;
  *(undefined4 *)(iVar2 + 0x38) = 0;
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
