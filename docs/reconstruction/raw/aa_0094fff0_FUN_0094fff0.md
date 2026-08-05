# Raw capture: FUN_0094fff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094fff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0094fff0` |
| **Canonical name** | `FUN_0094fff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0094fff0(int param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((*(int *)(param_1 + 0xe98) != 0) && (*(int *)(param_1 + 0x31f0) != 0)) {
    iVar1 = *(int *)(param_1 + 0xe98);
    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 4);
    iVar1 = FUN_004c22a0(*(undefined4 *)(iVar3 + 0x164 + iVar1),
                         *(undefined4 *)(iVar3 + 0x168 + iVar1));
    if ((iVar1 != 0) && (1 < *(int *)(iVar1 + 0x24))) {
      uVar4 = 0xffffffff;
      uVar5 = 0xffffffff;
      pcVar2 = strtok((char *)0x0,param_3);
      if (pcVar2 == (char *)0x0) {
        if (*(int **)(param_1 + 0x3048) == (int *)0x0) {
          return 1;
        }
        iVar1 = (**(code **)(**(int **)(param_1 + 0x3048) + 0x210))(0);
        if (iVar1 == 0) {
          return 1;
        }
        iVar3 = (**(code **)(**(int **)(param_1 + 0x3048) + 0x210))(0);
        iVar1 = *(int *)(*(int *)(iVar3 + 4) + 4);
        uVar4 = *(undefined4 *)(iVar1 + 0x164 + iVar3);
        uVar5 = *(undefined4 *)(iVar1 + 0x168 + iVar3);
        iVar1 = (**(code **)(**(int **)(param_1 + 0x3048) + 0x210))(0);
        iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x160))();
        if (iVar1 == 0) {
          return 1;
        }
      }
      FUN_0094bfe0(uVar4,uVar5);
    }
  }
  return 1;
}
```
