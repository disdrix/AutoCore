# Raw capture: CVOGReaction_GiveItemByCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a170` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051a170` |
| **Canonical name** | `CVOGReaction_GiveItemByCbid` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Factory function to create an inventory item by CBI type ID.
   
   Parameters:
   iParam - Item creation parameters pointer (0 = special case for type 0x1a, 0x20)
   
   Returns: Pointer to created item, or 0 on failure
   
   Item type codes (from itemDef+0x38):
   1 - Weapon (0x250 bytes)
   3 - Armor (0x2a0 bytes)
   4 - Module (0x2a0 bytes)
   6 - Currency (0x250 bytes)
   8 - Container (0x260 bytes)
   0xa - Vehicle (0x270 bytes)
   0xc - Special (sub-type from +0x3c: \t=0x2e0, \x11=0x2e0, else=0x2e0)
   0xe - Mount (0x800 bytes)
   0x10 - Pet (0x2f0 bytes)
   0x12 - Consumable (0x690 bytes)
   0x14 - Mission item (0xf30 bytes)
   0x16 - Crafting material (0x690 bytes)
   0x1a - Ammo (0x250 bytes)
   0x1c - Quest item (0x270 bytes)
   0x1e - Trade good (0x260 bytes)
   0x20 - Blueprint (0x1d0 bytes)
   0x22 - Upgrade (0x500 bytes)
   0x30 - Key (0x210 bytes)
   0x32 - Data chip (0x260 bytes)
   0x36 - Repair kit (0x370 bytes)
   0x38 - Paint (0x350 bytes)
   0x3a - Salvage (0x270 bytes)
   0x3c - Resource (0x250 bytes)
   0x3e - Token (0x1f0 bytes)
   0x42 - Component (0x2a0 bytes)
   0x48 - Misc (0x3f0 bytes) */

int __cdecl CVOGReaction_GiveItemByCbid(int iParam)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  
  iVar2 = FUN_00404d70(iParam);
                    /* // Get item definition via FUN_00404d70 */
  if (iVar2 == 0) {
                    /* // Switch on item type (itemDef+0x38), allocate appropriate struct */
    return 0;
  }
  switch(*(undefined4 *)(iVar2 + 0x38)) {
  case 1:
    pvVar4 = operator_new(0x250);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_005c7f30(1);
    if (iVar2 == 0) {
      return 0;
    }
    goto LAB_0051a2b0;
  default:
    FUN_007a4480(0,"VOG_DEBUG_STOP");
    return 0;
  case 3:
                    /* // Type 0xc (special): sub-type from +0x3c determines constructor */
    pvVar4 = operator_new(0x2a0);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_005c82a0(1);
    if (iVar2 == 0) {
      return 0;
    }
    goto LAB_0051a2b0;
  case 4:
    pvVar4 = operator_new(0x2a0);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_0051ef40(1);
    if (iVar2 == 0) {
      return 0;
    }
    goto LAB_0051a2b0;
  case 6:
    pvVar4 = operator_new(0x250);
    goto LAB_0051a4da;
  case 8:
    pvVar4 = operator_new(0x260);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_006092a0(1);
    break;
  case 10:
    pvVar4 = operator_new(0x270);
    if (iParam == 0) {
      if (pvVar4 == (void *)0x0) {
        return 0;
      }
      iVar2 = FUN_00609620(1);
      if (iVar2 == 0) {
        return 0;
      }
    }
    else {
      if (pvVar4 == (void *)0x0) {
        return 0;
      }
      iVar2 = FUN_00609620(1);
      if (iVar2 == 0) {
        return 0;
      }
    }
    goto LAB_0051a2b0;
  case 0xc:
    if (*(int *)(iVar2 + 0x3c) == 0) {
      FUN_004f1e20(1,1);
    }
    cVar1 = *(char *)(*(int *)(iVar2 + 0x3c) + 0x3f4);
    if (cVar1 == '\t') {
      pvVar4 = operator_new(0x2e0);
      if (pvVar4 == (void *)0x0) goto LAB_0051a350;
      iVar2 = FUN_005ff780(1);
    }
    else if (cVar1 == '\x11') {
      pvVar4 = operator_new(0x2e0);
      if (pvVar4 == (void *)0x0) goto LAB_0051a350;
      iVar2 = FUN_005ff910(1);
    }
    else {
      pvVar4 = operator_new(0x2e0);
      if (pvVar4 == (void *)0x0) {
LAB_0051a350:
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_0056e730(1);
      }
    }
    break;
  case 0xe:
    pvVar4 = operator_new(0x800);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_00501970(1);
    break;
  case 0x10:
    pvVar4 = operator_new(0x2f0);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_005a84f0(1);
    break;
  case 0x12:
    pvVar4 = operator_new(0x690);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_004c9aa0(1);
    break;
  case 0x14:
    pvVar4 = operator_new(0xf30);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_00536920(1);
    break;
  case 0x16:
    pvVar4 = operator_new(0x690);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_00588dc0(1);
    if (iVar2 == 0) {
      return 0;
    }
    goto LAB_0051a2b0;
  case 0x1a:
    pvVar4 = operator_new(0x250);
    if (iParam != 0) {
      if (pvVar4 == (void *)0x0) {
        return 0;
      }
      iVar2 = FUN_005c7f30(1);
      if (iVar2 == 0) {
        return 0;
      }
      goto LAB_0051a5c3;
    }
LAB_0051a4da:
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_005c7f30(1);
    break;
  case 0x1c:
    pvVar4 = operator_new(0x270);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_005fe7a0(1);
    break;
  case 0x1e:
    pvVar4 = operator_new(0x260);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_00605940(1);
    break;
  case 0x20:
    pvVar4 = operator_new(0x1d0);
    if (iParam == 0) {
      if (pvVar4 == (void *)0x0) {
        return 0;
      }
      piVar3 = (int *)FUN_0051e7d0(1);
      if (piVar3 == (int *)0x0) {
        return 0;
      }
      return *(int *)(*piVar3 + 4) + (int)piVar3;
    }
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    piVar3 = (int *)FUN_0051e7d0(1);
    if (piVar3 == (int *)0x0) {
      return 0;
    }
    return *(int *)(*piVar3 + 4) + (int)piVar3;
  case 0x22:
    pvVar4 = operator_new(0x500);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_00577df0(1);
    break;
  case 0x30:
    pvVar4 = operator_new(0x210);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_00575440();
    return iVar2;
  case 0x32:
    pvVar4 = operator_new(0x260);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_00608fb0(1);
    break;
  case 0x36:
    pvVar4 = operator_new(0x370);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_00566c10(1);
    break;
  case 0x38:
    pvVar4 = operator_new(0x350);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_005dbfa0(1);
    break;
  case 0x3a:
    pvVar4 = operator_new(0x270);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_0057b0e0();
    return iVar2;
  case 0x3c:
    pvVar4 = operator_new(0x250);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_006054a0(1);
    break;
  case 0x3e:
    pvVar4 = operator_new(0x1f0);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_005dfe20();
    return iVar2;
  case 0x42:
    pvVar4 = operator_new(0x2a0);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_0051ea10(1);
    if (iVar2 == 0) {
      return 0;
    }
LAB_0051a2b0:
    return *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2;
  case 0x48:
    pvVar4 = operator_new(0x3f0);
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    iVar2 = FUN_00607f90(1);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_0051a5c3:
  return *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2;
}
```
