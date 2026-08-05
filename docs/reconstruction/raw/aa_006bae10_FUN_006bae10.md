# Raw capture: FUN_006bae10

| Field | Value |
|---|---|
| **Stable ID** | `aa_006bae10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006bae10` |
| **Canonical name** | `FUN_006bae10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006bae10(int param_1,int param_2,int param_3,code *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  undefined1 local_56;
  undefined1 uStack_55;
  int local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  do {
    puVar1 = (undefined4 *)(param_1 + (param_2 + param_3 >> 1) * 0x14);
    local_30 = *puVar1;
    local_2c = puVar1[1];
    local_28 = puVar1[2];
    local_24 = puVar1[3];
    local_20 = puVar1[4];
    iVar5 = param_3;
    iVar6 = param_2;
    do {
      local_54 = param_1 + iVar6 * 0x14;
      pcVar4 = (char *)(*param_4)(&local_56,local_54,&local_30);
      cVar3 = *pcVar4;
      while (cVar3 != '\0') {
        local_54 = local_54 + 0x14;
        iVar6 = iVar6 + 1;
        pcVar4 = (char *)(*param_4)(&local_56,local_54,&local_30);
        cVar3 = *pcVar4;
      }
      local_54 = param_1 + iVar5 * 0x14;
      pcVar4 = (char *)(*param_4)(&uStack_55,&local_30,local_54);
      cVar3 = *pcVar4;
      while (cVar3 != '\0') {
        local_54 = local_54 + -0x14;
        iVar5 = iVar5 + -1;
        pcVar4 = (char *)(*param_4)(&uStack_55,&local_30,local_54);
        cVar3 = *pcVar4;
      }
      if (iVar5 < iVar6) break;
      if (iVar5 != iVar6) {
        puVar1 = (undefined4 *)(param_1 + iVar5 * 0x14);
        uStack_50 = *puVar1;
        uStack_4c = puVar1[1];
        uStack_48 = puVar1[2];
        uStack_44 = puVar1[3];
        uStack_40 = puVar1[4];
        puVar2 = (undefined4 *)(param_1 + iVar6 * 0x14);
        *puVar1 = *puVar2;
        puVar1[1] = puVar2[1];
        puVar1[2] = puVar2[2];
        puVar1[3] = puVar2[3];
        puVar1[4] = puVar2[4];
        *puVar2 = uStack_50;
        puVar2[1] = uStack_4c;
        puVar2[2] = uStack_48;
        puVar2[3] = uStack_44;
        puVar2[4] = uStack_40;
      }
      iVar5 = iVar5 + -1;
      iVar6 = iVar6 + 1;
    } while (iVar6 <= iVar5);
    if (param_2 < iVar5) {
      FUN_006bae10(param_1,param_2,iVar5,param_4);
    }
    param_2 = iVar6;
    if (param_3 <= iVar6) {
      return;
    }
  } while( true );
}
```
