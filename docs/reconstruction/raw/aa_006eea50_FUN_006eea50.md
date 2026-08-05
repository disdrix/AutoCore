# Raw capture: FUN_006eea50

| Field | Value |
|---|---|
| **Stable ID** | `aa_006eea50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006eea50` |
| **Canonical name** | `FUN_006eea50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006eea50(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  local_8 = param_3[2];
  local_4 = param_3;
  local_c = param_3[1];
  local_10 = *(undefined4 *)(*param_3 + 0xc);
  (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))(&local_10,param_2,param_4);
  return;
}
```
