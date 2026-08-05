# Raw capture: FUN_006ee0b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ee0b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ee0b0` |
| **Canonical name** | `FUN_006ee0b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006ee0b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined **local_c;
  undefined1 local_8;
  undefined4 local_4;
  
  local_4 = param_4;
  local_8 = 0;
  local_c = &PTR_LAB_00a0e32c;
  FUN_006ede50(param_2,param_1,param_3,&local_c);
  return;
}
```
