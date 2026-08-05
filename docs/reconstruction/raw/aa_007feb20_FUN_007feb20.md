# Raw capture: FUN_007feb20

| Field | Value |
|---|---|
| **Stable ID** | `aa_007feb20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007feb20` |
| **Canonical name** | `FUN_007feb20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007feb20(void)

{
  int *piVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  
  FUN_007fca10();
  FUN_007fca10();
  FUN_007fca10();
  FUN_007fca10();
  FUN_007fca10();
  FUN_007fdcc0(in_EAX);
  if (((*(int **)(in_EAX + 0xf40) != (int *)0x0) &&
      (iVar3 = *(int *)(in_EAX + 0xf38), **(int **)(in_EAX + 0xf40) == iVar3)) && (iVar3 != 0)) {
    if (*(int *)(iVar3 + 0xcb0) != 0) {
      (**(code **)(**(int **)(iVar3 + 0xcb0) + 4))(0);
    }
    if (*(int *)(*(int *)(in_EAX + 0xf38) + 0xcb4) != 0) {
      (**(code **)(**(int **)(*(int *)(in_EAX + 0xf38) + 0xcb4) + 4))(0);
    }
    if (*(int *)(*(int *)(in_EAX + 0xf38) + 0xcb8) != 0) {
      (**(code **)(**(int **)(*(int *)(in_EAX + 0xf38) + 0xcb8) + 4))(0);
    }
    if (*(int *)(*(int *)(in_EAX + 0xf38) + 0xcc0) != 0) {
      (**(code **)(**(int **)(*(int *)(in_EAX + 0xf38) + 0xcc0) + 4))(0);
    }
  }
  if (*(int *)(in_EAX + 0x1164) != 0) {
    cVar2 = (**(code **)(**(int **)(in_EAX + 0x1164) + 0x3d8))();
    if (cVar2 != '\0') {
      (**(code **)(**(int **)(in_EAX + 0x1164) + 4))(0);
    }
  }
  iVar3 = 0;
  piVar4 = (int *)(in_EAX + 0x1030);
  do {
    *(undefined1 *)(in_EAX + 0x5c + iVar3) = 0;
    piVar1 = (int *)*piVar4;
    if (piVar1 != (int *)0x0) {
      if (((((iVar3 == 0x14) || (iVar3 == 0x15)) ||
           ((iVar3 == 0xb || ((iVar3 == 9 || (iVar3 == 7)))))) || (iVar3 == 6)) ||
         (((iVar3 == 0xf || (iVar3 == 10)) || (iVar3 == 0x10)))) {
        cVar2 = (**(code **)(*piVar1 + 0x3d8))();
        if (cVar2 != '\0') {
          FUN_007fca10();
        }
      }
      else {
        cVar2 = (**(code **)(*piVar1 + 0x3d8))();
        if (cVar2 != '\0') {
          cVar2 = (**(code **)(*(int *)*piVar4 + 0xd0))();
          if (cVar2 != '\0') {
            *(undefined1 *)(in_EAX + 0x5c + iVar3) = 1;
            (**(code **)(*(int *)*piVar4 + 4))(0);
          }
        }
      }
    }
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar3 < 0x3a);
  return;
}
```
