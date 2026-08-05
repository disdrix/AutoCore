# Raw capture: FUN_0066bfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0066bfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0066bfb0` |
| **Canonical name** | `FUN_0066bfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0066bfb0(int param_1,int param_2)

{
  FUN_00651a40(param_2);
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(param_1 + 0x3c);
  return;
}
```
