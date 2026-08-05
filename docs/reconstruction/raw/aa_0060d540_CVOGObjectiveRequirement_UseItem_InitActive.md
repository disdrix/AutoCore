# Raw capture: CVOGObjectiveRequirement_UseItem_InitActive

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d540` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0060d540` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_InitActive` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall CVOGObjectiveRequirement_UseItem_InitActive(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  
  if (*(char *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) + 0x7e) != '\0') {
    if ((*(int *)(param_1 + 0x18) != -1) && (*(char *)(param_1 + 0x24) != '\0')) {
      uVar4 = 1;
      if (*(char *)(param_1 + 0x25) == '\0') {
        uVar4 = *(undefined4 *)(param_1 + 0x50);
      }
      cVar3 = FUN_005310a0(*(int *)(param_1 + 0x18),uVar4);
      if (cVar3 == '\0') {
        puVar1 = *(undefined4 **)(*(int *)(param_1 + 4) + 0x14c);
        iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);
        FUN_007a4480(1,"Failed to give item %d to %I64d, objective %d mission: %S(%d)",
                     *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(iVar2 + 0x164 + param_2),
                     *(undefined4 *)(iVar2 + 0x168 + param_2),
                     *(undefined4 *)(*(int *)(param_1 + 4) + 0x10),puVar1 + 1,*puVar1);
      }
    }
    if ((*(int *)(param_1 + 0x2c) != -1) && (*(char *)(param_1 + 0x31) != '\0')) {
      uVar4 = 1;
      if (*(char *)(param_1 + 0x32) == '\0') {
        uVar4 = *(undefined4 *)(param_1 + 0x50);
      }
      cVar3 = FUN_005310a0(*(int *)(param_1 + 0x2c),uVar4);
      if (cVar3 == '\0') {
        puVar1 = *(undefined4 **)(*(int *)(param_1 + 4) + 0x14c);
        iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);
        FUN_007a4480(1,"Failed to give item %d to %I64d, objective %d mission: %S(%d)",
                     *(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(iVar2 + 0x164 + param_2),
                     *(undefined4 *)(iVar2 + 0x168 + param_2),
                     *(undefined4 *)(*(int *)(param_1 + 4) + 0x10),puVar1 + 1,*puVar1);
      }
    }
  }
  return;
}
```
