# Raw capture: FUN_0061fcf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061fcf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0061fcf0` |
| **Canonical name** | `FUN_0061fcf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0061fcf0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(float *)(param_1 + 0x160) != g_flZero) {
    FUN_005781b0(param_3,param_2,"virus decays)\n",0);
  }
  if (*(float *)(param_1 + 0x164) != g_flZero) {
    FUN_005781b0(param_3,param_2,"op_scalar_2] (max virus jumps)\n",1);
  }
  FUN_0061a370(param_1,param_2,param_3);
  return;
}
```
