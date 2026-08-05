# Raw capture: FUN_0040aff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040aff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040aff0` |
| **Canonical name** | `FUN_0040aff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0040aff0(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x228);
  param_2[1] = *(undefined4 *)(param_1 + 0x22c);
  param_2[2] = *(undefined4 *)(param_1 + 0x230);
  param_2[3] = *(undefined4 *)(param_1 + 0x234);
  return;
}
```
