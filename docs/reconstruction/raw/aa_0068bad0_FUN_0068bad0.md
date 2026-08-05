# Raw capture: FUN_0068bad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068bad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0068bad0` |
| **Canonical name** | `FUN_0068bad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_0068bad0(int param_1,int param_2)

{
  return *(int *)(param_1 + 0xb4) + param_2 * 8;
}
```
