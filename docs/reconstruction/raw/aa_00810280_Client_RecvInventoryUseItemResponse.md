# Raw capture: Client_RecvInventoryUseItemResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810280` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00810280` |
| **Canonical name** | `Client_RecvInventoryUseItemResponse` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Client_RecvInventoryUseItemResponse(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int unaff_ESI;
  
  if ((*(int *)(param_1 + 0xe98) != 0) && (*(int *)(*(int *)(param_1 + 0xe98) + 0x250) != 0)) {
    if (*(int *)(unaff_ESI + 0x10) < 1) {
      iVar2 = FUN_00571d80(*(undefined4 *)(unaff_ESI + 8),*(undefined4 *)(unaff_ESI + 0xc),0);
      if (iVar2 != 0) {
        FUN_007fee30();
        FUN_00933310(param_1,1,0,0xffffffff,0xffffffff);
      }
    }
    else {
      piVar3 = (int *)FUN_00571010(*(undefined4 *)(unaff_ESI + 8),*(undefined4 *)(unaff_ESI + 0xc));
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x260))(*(undefined4 *)(unaff_ESI + 0x10));
        *(undefined2 *)(piVar3 + 0x60) = *(undefined2 *)(unaff_ESI + 0x14);
      }
    }
    Client_RefreshOpenMissionUiWindows(param_1);
    if (*(int *)(param_1 + 0x309c) != 0) {
      (**(code **)(**(int **)(param_1 + 0x309c) + 4))(0);
    }
    piVar3 = *(int **)(param_1 + 0x10b0);
    if ((piVar3 != (int *)0x0) && (cVar1 = (**(code **)(*piVar3 + 0x3d8))(), cVar1 != '\0')) {
      (**(code **)(*piVar3 + 0x450))(0);
    }
  }
  return;
}
```
