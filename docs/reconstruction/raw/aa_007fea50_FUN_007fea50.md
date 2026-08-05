# Raw capture: FUN_007fea50

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fea50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fea50` |
| **Canonical name** | `FUN_007fea50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fea50(void)

{
  char cVar1;
  int unaff_EBX;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  
  pcVar4 = (char *)(unaff_EBX + 0x5c);
  piVar3 = (int *)(unaff_EBX + 0x1030);
  iVar2 = 0x3a;
  do {
    if ((*pcVar4 != '\0') && (*piVar3 != 0)) {
      cVar1 = (**(code **)(*(int *)*piVar3 + 0x3d8))();
      if ((cVar1 != '\0') && (*pcVar4 != '\0')) {
        (**(code **)(*(int *)*piVar3 + 4))(1);
      }
    }
    piVar3 = piVar3 + 1;
    pcVar4 = pcVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (*(int *)(unaff_EBX + 0x1164) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_EBX + 0x1164) + 0x3d8))();
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(unaff_EBX + 0x1164) + 4))(1);
    }
  }
  if (((*(int **)(unaff_EBX + 0xf40) != (int *)0x0) &&
      (iVar2 = *(int *)(unaff_EBX + 0xf38), **(int **)(unaff_EBX + 0xf40) == iVar2)) && (iVar2 != 0)
     ) {
    if (*(int *)(iVar2 + 0xcb0) != 0) {
      (**(code **)(**(int **)(iVar2 + 0xcb0) + 4))(1);
    }
    if (*(int *)(*(int *)(unaff_EBX + 0xf38) + 0xcc0) != 0) {
      piVar3 = *(int **)(*(int *)(unaff_EBX + 0xf38) + 0xcc0);
      (**(code **)(*piVar3 + 0x444))(piVar3[0x158]);
    }
  }
  return;
}
```
