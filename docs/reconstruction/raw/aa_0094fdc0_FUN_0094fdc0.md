# Raw capture: FUN_0094fdc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094fdc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0094fdc0` |
| **Canonical name** | `FUN_0094fdc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0094fdc0(int param_1,undefined4 param_2,char *param_3)

{
  char *pcVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (*(int *)(param_1 + 0xe98) == 0) {
    return 1;
  }
  if (*(int *)(param_1 + 0x31f0) == 0) {
    return 1;
  }
  pcVar1 = strtok((char *)0x0,param_3);
  if (pcVar1 == (char *)0x0) {
    if (*(int **)(param_1 + 0x3048) == (int *)0x0) {
      return 1;
    }
    iVar3 = (**(code **)(**(int **)(param_1 + 0x3048) + 0x210))(0);
    if (iVar3 == 0) {
      return 1;
    }
    iVar4 = (**(code **)(**(int **)(param_1 + 0x3048) + 0x210))(0);
    iVar3 = *(int *)(*(int *)(iVar4 + 4) + 4);
    uVar6 = *(uint *)(iVar3 + 0x164 + iVar4);
    uVar5 = *(uint *)(iVar3 + 0x168 + iVar4);
  }
  else {
    puVar2 = (uint *)FUN_004c2310(pcVar1);
    if (puVar2 == (uint *)0x0) {
      return 1;
    }
    uVar6 = *puVar2;
    uVar5 = puVar2[1];
  }
  if ((uVar6 & uVar5) != 0xffffffff) {
    FUN_0094c200(uVar6,uVar5);
  }
  return 1;
}
```
