# Raw capture: FUN_0074efe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074efe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0074efe0` |
| **Canonical name** | `FUN_0074efe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0074efe0(int param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_ESI;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    if (in_EAX == 0) {
      in_EAX = (**(code **)(**(int **)(param_1 + 0xc) + 0xec))(*(int **)(param_1 + 0xc));
    }
    uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x38))(*(int **)(param_1 + 0xc),in_EAX,param_2)
    ;
    iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x4c))
                      (*(int **)(param_1 + 0xc),uVar1,unaff_ESI);
    if (iVar2 != 0) {
      iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x54))
                        (*(int **)(param_1 + 0xc),iVar2,param_2,0xffffffff);
      if (-1 < iVar2) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}
```
