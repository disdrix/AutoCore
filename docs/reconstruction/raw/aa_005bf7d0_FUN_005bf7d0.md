# Raw capture: FUN_005bf7d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bf7d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005bf7d0` |
| **Canonical name** | `FUN_005bf7d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005bf7d0(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  param_2 = ((int)param_2 < 1) - 1 & param_2;
  uVar1 = *(int *)(param_1 + 4) * *(int *)(param_1 + 0x18) - 1;
  if ((int)uVar1 <= (int)param_2) {
    param_2 = uVar1;
  }
  param_3 = param_3 & ((int)param_3 < 1) - 1;
  uVar1 = *(int *)(param_1 + 8) * *(int *)(param_1 + 0x18) - 1;
  if ((int)param_3 < (int)uVar1) {
    uVar1 = param_3;
  }
  FUN_005bf530((int)param_2 % *(int *)(param_1 + 0x18),(int)uVar1 % *(int *)(param_1 + 0x18));
  return;
}
```
