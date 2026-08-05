# Raw capture: FUN_0096fff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096fff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0096fff0` |
| **Canonical name** | `FUN_0096fff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int FUN_0096fff0(int *param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  undefined4 *in_EAX;
  int iVar3;
  int iVar4;
  
  cVar2 = FUN_0096fdf0();
  iVar3 = FUN_00753160(param_2,*in_EAX,in_EAX[1],in_EAX[2],in_EAX[3]);
  if (((iVar3 == -1) && (cVar2 != '\0')) && (iVar1 = *param_1, iVar1 != 0)) {
    iVar4 = *(int *)(iVar1 + 0x18);
    if (*(int *)(iVar1 + 0x18) == 0) {
      iVar4 = iVar1;
    }
    if (iVar4 != iVar1) {
      FUN_00448fc0(iVar4);
    }
  }
  return iVar3;
}
```
