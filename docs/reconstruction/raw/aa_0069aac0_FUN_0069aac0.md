# Raw capture: FUN_0069aac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0069aac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0069aac0` |
| **Canonical name** | `FUN_0069aac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0069aac0(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (*(float *)(*param_1 + 0x2c) < *(float *)(*param_2 + 0x2c)) {
    iVar1 = *param_2;
    *param_2 = *param_1;
    *param_1 = iVar1;
  }
  if (*(float *)(*param_2 + 0x2c) < *(float *)(*param_3 + 0x2c)) {
    iVar1 = *param_3;
    *param_3 = *param_2;
    *param_2 = iVar1;
  }
  if (*(float *)(*param_1 + 0x2c) < *(float *)(*param_2 + 0x2c)) {
    iVar1 = *param_2;
    *param_2 = *param_1;
    *param_1 = iVar1;
  }
  return;
}
```
