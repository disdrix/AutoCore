# Raw capture: FUN_006ceae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ceae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ceae0` |
| **Canonical name** | `FUN_006ceae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_006ceae0(int param_1)

{
  FUN_0066dcf0();
  *(undefined4 *)(param_1 + 4) = 0;
  return param_1;
}
```
