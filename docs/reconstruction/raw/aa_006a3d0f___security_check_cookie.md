# Raw capture: __security_check_cookie

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d0f` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a3d0f` |
| **Canonical name** | `__security_check_cookie` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: This is an inlined function */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_00af5894) {
    return;
  }
  FUN_006a3cde();
  return;
}
```
