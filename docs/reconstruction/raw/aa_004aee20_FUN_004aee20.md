# Raw capture: FUN_004aee20

| Field | Value |
|---|---|
| **Stable ID** | `aa_004aee20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004aee20` |
| **Canonical name** | `FUN_004aee20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004aee20(int param_1,int param_2,undefined2 *param_3)

{
  for (; param_1 != param_2; param_2 = param_2 + -2) {
    param_3 = param_3 + -1;
    *param_3 = *(undefined2 *)(param_2 + -2);
  }
  return;
}
```
