# Raw capture: FUN_004de9f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004de9f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004de9f0` |
| **Canonical name** | `FUN_004de9f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004de9f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0xe720);
  if (piVar4 != *(int **)(param_1 + 0xe724)) {
    do {
      iVar2 = *piVar4;
      iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);
      iVar1 = iVar3 + iVar2;
      if (((*(uint *)(iVar3 + 0x3c + iVar2) & *(uint *)(iVar3 + 0x40 + iVar2)) != 0xffffffff) &&
         (*(int *)(*(int *)(iVar1 + 0xac) + 0x38) != 0x36)) {
        if (*(int *)(iVar1 + 0x134) != 0) {
          CVOGObject_SetInteractSpecialFX((void *)(iVar1 + 4),(void *)0x0);
        }
        iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4);
        iVar3 = iVar1 + iVar2;
        FUN_004dbef0(iVar3 + 4,0,*(undefined4 *)(iVar3 + 0x3c),*(undefined4 *)(iVar1 + 0x40 + iVar2)
                     ,0xffffffff);
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != *(int **)(param_1 + 0xe724));
  }
  return;
}
```
