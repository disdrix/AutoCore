# Raw capture: FUN_004b8dc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b8dc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004b8dc0` |
| **Canonical name** | `FUN_004b8dc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004b8dc0(int param_1,char param_2,undefined4 param_3)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (param_2 != *(char *)(param_1 + 0xb)) {
    *(char *)(param_1 + 0xb) = param_2;
    piVar2 = (int *)**(int **)(param_1 + 0x1e0);
    if (piVar2 != *(int **)(param_1 + 0x1e0)) {
      do {
        FUN_005bbb90(*(undefined1 *)(param_1 + 0xb),param_3);
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)*(int *)(param_1 + 0x1e0));
    }
    piVar2 = (int *)**(int **)(param_1 + 0x204);
    if (piVar2 != *(int **)(param_1 + 0x204)) {
      do {
        FUN_0058e930(*(undefined1 *)(param_1 + 0xb));
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)*(int *)(param_1 + 0x204));
    }
    if (*(char *)(param_1 + 0xb) != '\0') {
      FUN_004b7e50(0,0,0,0,0,0);
      FUN_004b6fc0();
      return;
    }
    piVar2 = (int *)**(int **)(param_1 + 0x1ec);
    if (piVar2 != *(int **)(param_1 + 0x1ec)) {
      do {
        iVar4 = piVar2[2];
        uVar1 = (uint)*(byte *)(iVar4 + 0x128);
        uVar6 = *(undefined4 *)(iVar4 + 0x124);
        uVar5 = 0;
        uVar3 = *(undefined4 *)(iVar4 + 0x120);
        Client_GetMissionCompleteAudioTable(uVar3,uVar6,uVar1,iVar4,0);
        FUN_00723b20(uVar3,uVar6,uVar1,iVar4,uVar5);
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)*(int *)(param_1 + 0x1ec));
    }
    if ((*(int *)(param_1 + 0x1fc) != 0) &&
       (piVar2 = (int *)**(int **)(param_1 + 0x1f8), piVar2 != *(int **)(param_1 + 0x1f8))) {
      do {
        iVar4 = piVar2[2];
        uVar6 = 1;
        FUN_00720d40(iVar4,1);
        FUN_007203b0(iVar4,uVar6);
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)*(int *)(param_1 + 0x1f8));
    }
  }
  return;
}
```
