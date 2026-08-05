# Raw capture: FUN_005c8eb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c8eb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005c8eb0` |
| **Canonical name** | `FUN_005c8eb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
