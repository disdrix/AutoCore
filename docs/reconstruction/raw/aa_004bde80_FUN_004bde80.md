# Raw capture: FUN_004bde80

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bde80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bde80` |
| **Canonical name** | `FUN_004bde80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int FUN_004bde80(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0xc0) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0) >> 2;
  }
  if (0 < iVar2) {
    piVar4 = *(int **)(param_1 + 0xc0);
    do {
      iVar3 = *(int *)(*piVar4 + 0x14);
      if (iVar3 == 0) {
        iVar5 = 0;
LAB_004bded3:
        iVar3 = 0;
      }
      else {
        iVar5 = *(int *)(iVar3 + 0x18);
        if (*(int *)(iVar3 + 0x10) == 0) goto LAB_004bded3;
        iVar3 = *(int *)(*(int *)(iVar3 + 0x10) + 8);
      }
      iVar1 = iVar1 + iVar3 * iVar5;
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return iVar1;
}
```
