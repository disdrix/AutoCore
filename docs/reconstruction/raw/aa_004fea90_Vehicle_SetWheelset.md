# Raw capture: Vehicle_SetWheelset

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fea90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fea90` |
| **Canonical name** | `Vehicle_SetWheelset` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Vehicle_SetWheelset (0x004FEA90)
   Sets vehicle+0x258 (offset 600) to wheelset object. Validates type==0x10.
   Called from EquipFromCreate and InventoryEquip (0x203C) path.
   See docs/nullWheels.md, PATH_A_DEBUGGER.md. Imported from AutoCore decompile dump 2026-07-11. */

void __thiscall Vehicle_SetWheelset(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  uint unaff_ESI;
  uint uVar5;
  
  FUN_00512670();
  *(int *)(param_1 + 600) = param_2;
  if (param_2 != 0) {
    if (*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x38) != 0x10) {
      iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);
      iVar1 = param_2 + iVar2;
      FUN_007a4480(1,"Set wheelset1 of unhappy type: CBID:%d COID:%I64d",
                   *(undefined4 *)(*(int *)(iVar1 + 0xac) + 0x34),*(undefined4 *)(iVar1 + 0x164),
                   *(undefined4 *)(param_2 + 0x168 + iVar2));
    }
    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 600) + 4) + 4) + 4 +
                         *(int *)(param_1 + 600)) + 0x158))
              (*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);
    iVar2 = *(int *)(param_1 + 600);
    if (iVar2 != 0) {
      iVar2 = *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2;
    }
    FUN_004fdcb0(iVar2);
    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 600) + 4) + 4) + 4 +
                         *(int *)(param_1 + 600)) + 0x218))
              (*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1));
    cVar4 = '\0';
    uVar5 = unaff_ESI & 0xffffff00;
    if ('\0' < *(char *)(*(int *)(param_1 + 600) + 0xb0)) {
      do {
        iVar2 = FUN_005a6e00(uVar5);
        if (iVar2 != 0) {
          piVar3 = (int *)FUN_005a6e00(uVar5);
          (**(code **)(*piVar3 + 0x1c))
                    (*(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac +
                                                 param_1) + 0x3c) + 0x600 + cVar4 * 4) *
                     g_flLevelUpUiBase_Inferred);
        }
        cVar4 = cVar4 + '\x01';
        uVar5 = CONCAT31((int3)(uVar5 >> 8),cVar4);
      } while (cVar4 < *(char *)(*(int *)(param_1 + 600) + 0xb0));
    }
  }
  return;
}
```
