# Raw capture: AuthRequest_Serialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071e460` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071e460` |
| **Canonical name** | `AuthRequest_Serialize` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall AuthRequest_Serialize(int param_1)

{
  FUN_0044cbd0();
  FUN_00480af0();
  FUN_00480af0();
  FUN_00439810();
  FUN_00480b50(param_1 + 0x34);
  return 0;
}
```
