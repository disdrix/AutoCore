# Raw capture: FUN_008b6eb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008b6eb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008b6eb0` |
| **Canonical name** | `FUN_008b6eb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_008b6eb0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  float10 fVar5;
  
  if ((param_3 < 0xa7fe) || (0xb3b5 < param_3)) {
    if (param_3 == 40000) {
      if (param_2 == 8) {
        FUN_007fca10();
        return 1;
      }
    }
    else if (param_3 == 0x9c43) {
      if (param_2 == 0x1a) {
        piVar1 = *(int **)(param_1 + 0x524);
        if (((piVar1 != (int *)0x0) && (DAT_00d1ad2c != -4)) &&
           (iVar3 = FUN_00401c30(), *(int *)(param_1 + 0x520) < iVar3)) {
          fVar5 = (float10)(**(code **)(*piVar1 + 0x458))();
          iVar3 = FUN_00401c30();
          iVar3 = iVar3 - *(int *)(param_1 + 0x520);
          fVar2 = (float)iVar3;
          if (iVar3 < 0) {
            fVar2 = fVar2 + _DAT_00aaa5dc;
          }
          if (*(int *)(param_1 + 0x52c) != (int)ROUND(fVar2 * (float)fVar5)) {
            *(int *)(param_1 + 0x52c) = (int)ROUND(fVar2 * (float)fVar5);
            FUN_008b6be0(0xffffffff,0xffffffff);
            DAT_00d1d8f4 = 1;
            DAT_00d1d8f5 = 0;
            if (DAT_00d1d8dc != (int *)0x0) {
              (**(code **)(*DAT_00d1d8dc + 4))(0);
            }
          }
        }
        return 1;
      }
    }
    else if ((param_3 == 0x9c44) && (param_2 == 7)) {
      return 1;
    }
    uVar4 = FUN_0087b500(param_2,param_3);
    return uVar4;
  }
  if ((param_2 != 5) && (param_2 == 6)) {
    DAT_00d1d8f4 = 1;
    DAT_00d1d8f5 = 0;
    if (DAT_00d1d8dc != (int *)0x0) {
      (**(code **)(*DAT_00d1d8dc + 4))(0);
    }
    return 1;
  }
  return 1;
}
```
