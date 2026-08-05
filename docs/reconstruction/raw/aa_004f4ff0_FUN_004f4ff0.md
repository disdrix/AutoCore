# Raw capture: FUN_004f4ff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4ff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f4ff0` |
| **Canonical name** | `FUN_004f4ff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004f4ff0(int param_1,char param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  bVar2 = false;
  iVar5 = 0;
  do {
    piVar1 = *(int **)(*(int *)(param_1 + 0x260) + iVar5);
    if (piVar1 != (int *)0x0) {
      cVar3 = (**(code **)(*piVar1 + 0x40))();
      if (cVar3 != '\0') {
        if ((param_2 == '\0') || (*(char *)(param_1 + 0x108) == '\0')) {
          iVar4 = (**(code **)(*piVar1 + 0x5c))
                            (*(undefined4 *)
                              (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 +
                                                param_1) + 0xe4e8) + 0x1c),param_3);
          bVar2 = (bool)(bVar2 | 0 < iVar4);
        }
        else {
          FUN_0056bf70();
          bVar2 = false;
        }
      }
    }
    iVar5 = iVar5 + 4;
  } while (iVar5 < 0xc);
  if ((!bVar2) && (param_3 == 0)) {
    *(undefined1 *)(param_1 + 0x108) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 0x108) = 1;
  return;
}
```
