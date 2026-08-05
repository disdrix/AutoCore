# Raw capture: FUN_005acef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005acef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005acef0` |
| **Canonical name** | `FUN_005acef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005acef0(int param_1)

{
  FUN_00418d70(&stack0x00000004);
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  return;
}
```
