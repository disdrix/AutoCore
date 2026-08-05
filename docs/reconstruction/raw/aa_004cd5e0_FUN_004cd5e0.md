# Raw capture: FUN_004cd5e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd5e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cd5e0` |
| **Canonical name** | `FUN_004cd5e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004cd5e0(int param_1)

{
  *(int *)(param_1 + 0xe828) = *(int *)(param_1 + 0xe828) + -1;
  return;
}
```
