# Raw capture: FUN_007fb2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb2b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fb2b0` |
| **Canonical name** | `FUN_007fb2b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fb2b0(uint param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  int in_EAX;
  
  piVar1 = *(int **)(in_EAX + 0x110c);
  piVar2 = *(int **)(in_EAX + 0x1110);
  piVar3 = *(int **)(in_EAX + 0x1108);
  if ((param_1 & param_2) == 0xffffffff) {
    if (piVar2 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar2 + 0x3d8))();
      if (cVar4 != '\0') {
        (**(code **)(*piVar2 + 0x450))(0xffffffff,0xffffffff);
      }
    }
    if (piVar3 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar3 + 0x3d8))();
      if (cVar4 != '\0') {
        (**(code **)(*piVar3 + 0x450))(0xffffffff,0xffffffff);
      }
    }
    if (piVar1 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar1 + 0x3d8))();
      if (cVar4 != '\0') {
        (**(code **)(*piVar1 + 0x450))(0xffffffff,0xffffffff);
        return;
      }
    }
  }
  else {
    if (piVar2 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar2 + 0x3d8))();
      if (cVar4 != '\0') {
        (**(code **)(*piVar2 + 0x450))(param_1,param_2);
      }
    }
    if (piVar3 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar3 + 0x3d8))();
      if (cVar4 != '\0') {
        (**(code **)(*piVar3 + 0x450))(param_1,param_2);
      }
    }
    if (piVar1 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar1 + 0x3d8))();
      if (cVar4 != '\0') {
        (**(code **)(*piVar1 + 0x450))(param_1,param_2);
      }
    }
  }
  return;
}
```
