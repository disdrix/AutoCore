# Raw capture: FUN_005a4ea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4ea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005a4ea0` |
| **Canonical name** | `FUN_005a4ea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int * __thiscall FUN_005a4ea0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int unaff_EBX;
  
  if (param_2 < 0x1001) {
    param_2 = 0x1000;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b05060 + 0x10))(param_2 + 0x10,0x12);
  *piVar2 = *(int *)(param_1 + 8);
  piVar2[1] = *(int *)(param_1 + 0xc);
  piVar2[2] = *(int *)(param_1 + 0x10);
  piVar2[3] = *(int *)(param_1 + 0x14);
  piVar1 = piVar2 + 4;
  *(int *)(param_1 + 0xc) = param_2 - unaff_EBX;
  *(int **)(param_1 + 0x10) = piVar2;
  *(int **)(param_1 + 0x14) = piVar1;
  *(int *)(param_1 + 8) = (int)piVar1 + unaff_EBX;
  return piVar1;
}
```
