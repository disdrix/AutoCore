# Raw capture: FUN_005feab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005feab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005feab0` |
| **Canonical name** | `FUN_005feab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005feab0(int param_1)

{
  *(undefined4 *)(param_1 + -0x1c) = 0;
  *(undefined4 *)(param_1 + -0x18) = 0;
  *(undefined2 *)(param_1 + -0x14) = 0;
  return;
}
```
