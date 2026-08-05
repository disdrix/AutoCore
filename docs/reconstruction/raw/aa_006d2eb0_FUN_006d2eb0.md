# Raw capture: FUN_006d2eb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006d2eb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006d2eb0` |
| **Canonical name** | `FUN_006d2eb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006d2eb0(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  local_8 = param_2[2];
  local_4 = param_2;
  local_10 = *(undefined4 *)(*param_2 + 0xc);
  local_c = param_2[1];
  FUN_006eb9c0(param_1,&local_10,param_3,param_4);
  return;
}
```
