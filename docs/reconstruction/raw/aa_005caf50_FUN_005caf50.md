# Raw capture: FUN_005caf50

| Field | Value |
|---|---|
| **Stable ID** | `aa_005caf50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005caf50` |
| **Canonical name** | `FUN_005caf50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005caf50(int param_1)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 0;
  FUN_005c9710(&local_8);
  FUN_005c9780(&local_4);
  FUN_005ca540(local_8,1);
  FUN_005ca5e0(local_4,1);
  *(undefined1 *)(param_1 + -0x1f) = 0;
  return;
}
```
