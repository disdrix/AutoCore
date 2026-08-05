# Raw capture: FUN_007ab7c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ab7c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007ab7c0` |
| **Canonical name** | `FUN_007ab7c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_007ab7c0(int *param_1,undefined4 *param_2)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = *param_2;
  local_4 = param_2[1];
  (**(code **)(*param_1 + 0x110))(&local_8);
  return;
}
```
