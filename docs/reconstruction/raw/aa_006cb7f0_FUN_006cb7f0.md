# Raw capture: FUN_006cb7f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cb7f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006cb7f0` |
| **Canonical name** | `FUN_006cb7f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006cb7f0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *local_8;
  
  local_8 = (undefined1 *)((uint)local_8 & 0xffffff00);
  (**(code **)(*param_1 + 0x24))(param_3,0);
  *local_8 = 0xf0;
  return;
}
```
