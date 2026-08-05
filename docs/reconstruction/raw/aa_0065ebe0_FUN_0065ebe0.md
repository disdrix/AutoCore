# Raw capture: FUN_0065ebe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0065ebe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0065ebe0` |
| **Canonical name** | `FUN_0065ebe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0065ebe0(int param_1,undefined4 *param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x60) = *param_2;
  *(undefined4 *)(param_1 + 100) = param_2[1];
  *(undefined4 *)(param_1 + 0x68) = param_2[2];
  *(undefined4 *)(param_1 + 0x6c) = param_2[3];
  FUN_005eb040(param_3);
  return;
}
```
