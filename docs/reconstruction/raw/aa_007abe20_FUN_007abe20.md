# Raw capture: FUN_007abe20

| Field | Value |
|---|---|
| **Stable ID** | `aa_007abe20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007abe20` |
| **Canonical name** | `FUN_007abe20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007abe20(int *param_1)

{
  undefined4 *puVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  local_c = 0;
  *(undefined1 *)((int)param_1 + 0xcf) = 1;
  if (param_1[0xa5] == 0) {
    local_10 = 0;
  }
  else {
    puVar1 = (undefined4 *)(**(code **)(*param_1 + 0x140))(local_8,1);
    local_10 = *puVar1;
    local_c = puVar1[1];
  }
  (**(code **)(*param_1 + 0x2cc))(&local_10);
  return;
}
```
