# Annotated low-level: FUN_005c8eb0

| Field | Value |
|---|---|
| Stable ID | `aa_005c8eb0` |
| VA | `0x005c8eb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005c8eb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005c8eb0(int param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  uint uVar3;
  
  FUN_00512af0();
  uVar3 = (uint)*(ushort *)
                 (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -100 + param_1) +
                          0x3c) + 0x3f8);
  *(uint *)(param_1 + -0x2c) = uVar3;
  *(uint *)(param_1 + -0x30) = uVar3;
  if (uVar3 == 0) {
    pbVar1 = (byte *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + 0x71 + param_1);
    *pbVar1 = *pbVar1 | 4;
  }
  uVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -100 + param_1
                                          ) + 0x3c) + 0x14))();
  *(undefined4 *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -0xfc + param_1) = uVar2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
