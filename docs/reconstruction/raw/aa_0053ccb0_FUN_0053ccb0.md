# Raw capture: FUN_0053ccb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053ccb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0053ccb0` |
| **Canonical name** | `FUN_0053ccb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0053ccb0(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    if ((*(int *)(param_1 + 8) - iVar1) / 0x14 != 0) {
      iVar1 = (param_3 - iVar1) / 0x14;
      goto LAB_0053ccf5;
    }
  }
  iVar1 = 0;
LAB_0053ccf5:
  FUN_0053c9b0(param_3,1,param_4);
  *param_2 = *(int *)(param_1 + 4) + iVar1 * 0x14;
  return;
}
```
