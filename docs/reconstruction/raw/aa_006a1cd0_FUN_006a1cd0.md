# Raw capture: FUN_006a1cd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a1cd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a1cd0` |
| **Canonical name** | `FUN_006a1cd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_006a1cd0(undefined4 param_1)

{
  if (DAT_00d08f98 == '\0') {
    FUN_006a1c00(0xffffffff);
  }
  return param_1;
}
```
