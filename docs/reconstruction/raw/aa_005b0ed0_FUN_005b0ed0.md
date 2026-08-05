# Raw capture: FUN_005b0ed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b0ed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b0ed0` |
| **Canonical name** | `FUN_005b0ed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005b0ed0(int param_1)

{
  uint *puVar1;
  byte bVar2;
  bool bVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_24 [32];
  
  if ((*(int *)(param_1 + 0x5c) != 0) && (*(int *)(param_1 + 0x50) != 0)) {
    piVar5 = (int *)(**(code **)(**(int **)(param_1 + 0x50) + 0x1c8))();
    (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0x240))
              (*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x10));
    bVar2 = *(byte *)(*(int *)(param_1 + 0x5c) + 0x8a);
    cVar4 = (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0x198))();
    if ((cVar4 == '\0') || (bVar2 != 0)) {
      cVar4 = (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0x198))();
      if ((cVar4 == '\0') && (bVar2 != 0)) {
        *(undefined4 *)(*(int *)(piVar5[1] + 4) + 0xd0 + (int)piVar5) = 0;
        FUN_004d0e90((int)piVar5 + *(int *)(piVar5[1] + 4) + 4);
      }
      else {
        puVar1 = (uint *)((int)piVar5 + *(int *)(piVar5[1] + 4) + 0x180);
        *puVar1 = *puVar1 ^ ((uint)bVar2 << 8 ^
                            *(uint *)((int)piVar5 + *(int *)(piVar5[1] + 4) + 0x180)) & 0x100;
      }
    }
    else {
      FUN_0053dd40();
      iVar6 = (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0x1cc))();
      if (iVar6 != 0) {
        uVar7 = (**(code **)(*(int *)((int)piVar5 + *(int *)(piVar5[1] + 4) + 4) + 0x1cc))();
        FUN_004c00f0(uVar7);
      }
    }
    iVar6 = piVar5[2];
    if (iVar6 != 0) {
      if ((*(char *)(iVar6 + 0x40) == '\0') || (*(int *)(iVar6 + 8) == 0)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      if (bVar3) {
        iVar6 = *(int *)(param_1 + 0x5c);
        uStack_44 = 0;
        uStack_40 = 0;
        uStack_3c = 0;
        uStack_38 = 0;
        uStack_2c = *(undefined4 *)(iVar6 + 0x6c);
        uStack_30 = *(undefined4 *)(iVar6 + 0x68);
        uStack_34 = *(undefined4 *)(iVar6 + 100);
        uStack_28 = 0;
        FUN_00797170(auStack_24);
        (**(code **)(*piVar5 + 0x24))(&uStack_34,auStack_24,&uStack_44,&uStack_44,0);
      }
    }
  }
  return;
}
```
