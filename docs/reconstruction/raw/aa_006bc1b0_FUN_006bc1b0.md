# Raw capture: FUN_006bc1b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006bc1b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006bc1b0` |
| **Canonical name** | `FUN_006bc1b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_006bc1b0(int param_1)

{
  undefined4 uVar1;
  
  if (**(ushort **)(param_1 + 0x14) < **(ushort **)(param_1 + 0x10)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    *(ushort **)(param_1 + 0x10) = *(ushort **)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = uVar1;
  }
  if (**(ushort **)(param_1 + 0x18) < **(ushort **)(param_1 + 0x14)) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x18) = uVar1;
  }
  if (**(ushort **)(param_1 + 0x14) < **(ushort **)(param_1 + 0x10)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    *(ushort **)(param_1 + 0x10) = *(ushort **)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = uVar1;
  }
  return;
}
```
