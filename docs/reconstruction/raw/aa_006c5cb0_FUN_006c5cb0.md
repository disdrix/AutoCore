# Raw capture: FUN_006c5cb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c5cb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c5cb0` |
| **Canonical name** | `FUN_006c5cb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006c5cb0(int param_1,int param_2)

{
  FUN_006cec70(param_2);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x10);
  return;
}
```
