# Raw capture: FUN_004fed40

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fed40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fed40` |
| **Canonical name** | `FUN_004fed40` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_004fed40(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_005cae70(param_2,param_3);
  FUN_004ce940();
  iVar1 = FUN_00404d70(param_2);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x3c) == 0) {
      FUN_004f1e20(1,1);
    }
    puVar2 = (undefined4 *)(*(int *)(iVar1 + 0x3c) + 0x4c0);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)FUN_00508bb0(*puVar2);
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(param_1 + -0x670,param_3,1);
        return 1;
      }
    }
  }
  return 0;
}
```
