# Raw capture: FUN_005dab60

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dab60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dab60` |
| **Canonical name** | `FUN_005dab60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005dab60(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = FUN_004e2320(param_3);
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
