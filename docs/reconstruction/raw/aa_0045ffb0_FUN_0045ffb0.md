# Raw capture: FUN_0045ffb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045ffb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0045ffb0` |
| **Canonical name** | `FUN_0045ffb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0045ffb0(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 == param_4) {
    *param_2 = param_3;
    return;
  }
  iVar2 = FUN_00460aa0(*(undefined4 *)(param_1 + 8),param_3,param_3);
  iVar1 = *(int *)(param_1 + 8);
  for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x20) {
    FUN_0045f5d0();
  }
  *(int *)(param_1 + 8) = iVar2;
  *param_2 = param_3;
  return;
}
```
