# Raw capture: InventoryGrid_FindFreeSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_005713a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005713a0` |
| **Canonical name** | `InventoryGrid_FindFreeSlot` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall
FUN_005713a0(int param_1,uint param_2,undefined4 param_3,byte *param_4,byte *param_5,char param_6)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int extraout_ECX;
  char cVar4;
  uint uVar5;
  byte bVar6;
  undefined4 local_c;
  
  if ((param_4 == (byte *)0x0) || (param_5 == (byte *)0x0)) {
    return 0;
  }
  if (((char)param_2 != '\0') && ((char)param_3 != '\0')) {
    if (param_6 == -1) {
      bVar2 = 0;
      cVar4 = (char)*(undefined4 *)(param_1 + 0xc) - (char)param_3;
    }
    else {
      cVar4 = (char)*(undefined4 *)(param_1 + 0x1c);
      bVar2 = cVar4 * param_6;
      cVar4 = (cVar4 - (char)param_3) + bVar2;
    }
    if (bVar2 < (byte)(cVar4 + 1U)) {
      do {
        bVar6 = 0;
        local_c = local_c & 0xffffff00;
        if (0 < (int)((*(int *)(param_1 + 8) - (param_2 & 0xff)) + 1)) {
          uVar5 = 0;
          do {
            iVar3 = *(int *)(param_1 + 0xc) * uVar5 + (uint)bVar2;
            if ((*(uint *)(*(int *)(param_1 + 0x28) + iVar3 * 8) &
                *(uint *)(*(int *)(param_1 + 0x28) + 4 + iVar3 * 8)) == 0xffffffff) {
              cVar1 = FUN_00570840(param_2,param_3,local_c,bVar2,0);
              param_1 = extraout_ECX;
              if (cVar1 != '\0') {
                *param_4 = bVar6;
                *param_5 = bVar2;
                return 1;
              }
            }
            bVar6 = bVar6 + 1;
            uVar5 = (uint)bVar6;
            local_c = CONCAT31(local_c._1_3_,bVar6);
          } while ((int)uVar5 < (int)((*(int *)(param_1 + 8) - (param_2 & 0xff)) + 1));
        }
        bVar2 = bVar2 + 1;
      } while (bVar2 < (byte)(cVar4 + 1U));
    }
    return 0;
  }
  *param_4 = 0;
  *param_5 = 0;
  return 1;
}
```
