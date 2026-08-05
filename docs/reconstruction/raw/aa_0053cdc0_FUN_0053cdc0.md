# Raw capture: FUN_0053cdc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053cdc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0053cdc0` |
| **Canonical name** | `FUN_0053cdc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_0053cdc0(int param_1,int param_2)

{
  uint *puVar1;
  
  if (param_2 != 0) {
    *(undefined **)(param_1 + 4) = &DAT_009d0014;
    FUN_00518940();
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x180 + param_1);
  *puVar1 = *puVar1 | 0x20;
  return param_1;
}
```
