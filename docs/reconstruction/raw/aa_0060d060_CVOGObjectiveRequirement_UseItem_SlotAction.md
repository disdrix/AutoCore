# Raw capture: CVOGObjectiveRequirement_UseItem_SlotAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d060` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0060d060` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_SlotAction` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall
CVOGObjectiveRequirement_UseItem_SlotAction
          (int param_1,undefined4 param_2,int param_3,char *param_4,size_t param_5)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  char local_200 [512];
  
  FUN_007a69d0();
  uVar5 = *(undefined4 *)(param_1 + 0x50);
  iVar4 = (int)*(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);
  uVar2 = FUN_007a6de0(*(undefined4 *)(param_1 + 0x20),0xffffffff);
  sprintf(local_200,"%s: %i / %i",uVar2,iVar4,uVar5);
  strncat(param_4,local_200,param_5);
  pcVar3 = local_200;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  return (int)pcVar3 - (int)(local_200 + 1);
}
```
