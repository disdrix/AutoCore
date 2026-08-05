# Raw capture: FUN_004fbb50

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbb50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fbb50` |
| **Canonical name** | `FUN_004fbb50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004fbb50(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) != 0) &&
     (param_2 != (int *)0x0)) {
    FUN_004e2600(&LAB_004f5400,param_2 + 0x58,0);
    piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
    if ((piVar1 != (int *)0x0) &&
       ((iVar2 = (**(code **)(*piVar1 + 0x1dc))(), iVar2 != 0 &&
        (iVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) +
                             0x1dc))(), *(int *)(iVar2 + 0x250) != 0)))) {
      (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x1dc))();
      FUN_004e2600(&LAB_004f5400,param_2 + 0x58,0);
    }
    (**(code **)(*param_2 + 0x40))(1);
  }
  return;
}
```
