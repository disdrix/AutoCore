# Raw capture: FUN_004badf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004badf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004badf0` |
| **Canonical name** | `FUN_004badf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004badf0(int param_1)

{
  *(undefined1 *)(param_1 + 0xe) = 0;
  return;
}
```
