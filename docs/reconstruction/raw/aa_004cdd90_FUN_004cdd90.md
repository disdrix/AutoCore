# Raw capture: FUN_004cdd90

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cdd90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cdd90` |
| **Canonical name** | `FUN_004cdd90` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_004cdd90(int param_1)

{
  return *(int *)(param_1 + 0xe4a4) + 0xe0;
}
```
