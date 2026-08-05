# Raw capture: FUN_005e1dd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e1dd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005e1dd0` |
| **Canonical name** | `FUN_005e1dd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005e1dd0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_009dc844;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  param_1[4] = 0;
  return;
}
```
