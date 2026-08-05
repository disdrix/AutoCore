# Raw capture: FUN_007ad3c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ad3c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007ad3c0` |
| **Canonical name** | `FUN_007ad3c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall
FUN_007ad3c0(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  
  uVar4 = param_8;
  uVar3 = param_7;
  uVar2 = param_6;
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x2b0) != 0) &&
     (cVar5 = (**(code **)(**(int **)(param_1 + 0x2b0) + 0x27c))
                        (param_2,param_3,param_4,param_5,param_6,param_7,param_8), cVar5 != '\0')) {
    return 1;
  }
  param_2 = (int *)0xffffffff;
  (**(code **)(*piVar1 + 0x25c))(uVar4,param_3,param_4,param_5,uVar2,uVar3,&param_2,0);
  return 1;
}
```
