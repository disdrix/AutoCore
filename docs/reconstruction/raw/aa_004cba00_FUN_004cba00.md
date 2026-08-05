# Raw capture: FUN_004cba00

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cba00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cba00` |
| **Canonical name** | `FUN_004cba00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cba00(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = FUN_004cb4b0(param_3);
  if (iVar1 != *(int *)(param_1 + 4)) {
    if ((*(int *)(iVar1 + 0x14) <= (int)param_3[1]) &&
       ((*(int *)(iVar1 + 0x14) < (int)param_3[1] || (*(uint *)(iVar1 + 0x10) <= *param_3)))) {
      *param_2 = iVar1;
      return;
    }
  }
  *param_2 = *(int *)(param_1 + 4);
  return;
}
```
