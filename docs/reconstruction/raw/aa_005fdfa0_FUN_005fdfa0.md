# Raw capture: FUN_005fdfa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fdfa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fdfa0` |
| **Canonical name** | `FUN_005fdfa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005fdfa0(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x28);
  param_2[2] = *(undefined4 *)(param_1 + 0x38);
  param_2[1] = *(undefined4 *)(param_1 + 0x2c);
  *(undefined1 *)(param_2 + 3) = *(undefined1 *)(param_1 + 0x3c);
  return;
}
```
