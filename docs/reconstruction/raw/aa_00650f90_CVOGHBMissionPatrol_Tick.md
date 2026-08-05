# Raw capture: CVOGHBMissionPatrol_Tick

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650f90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00650f90` |
| **Canonical name** | `CVOGHBMissionPatrol_Tick` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall CVOGHBMissionPatrol_Tick(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  float fVar6;
  uint uVar7;
  
  iVar5 = 0;
  iVar1 = __RTDynamicCast(param_1[6],0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                          &CVOGCharacter::RTTI_Type_Descriptor,0);
  iVar3 = *(int *)(iVar1 + 0xcb0);
  iVar2 = FUN_00578270();
  uVar7 = 0;
  if (iVar3 == 0) {
    if (param_1[6] == iVar2) {
LAB_00651046:
      (**(code **)(*param_1 + 0x50))();
      fVar6 = (float)unaff_EBP * (float)param_1[0x61] + (float)param_1[0x41];
      if (fVar6 != (float)param_1[0x1b0]) {
        *(float *)(iVar1 + 0xc54) = (fVar6 - (float)param_1[0x1b0]) + *(float *)(iVar1 + 0xc54);
        param_1[0x1b0] = (int)fVar6;
        FUN_00578b30(uVar7);
        return;
      }
      goto LAB_00650fd8;
    }
  }
  else {
    uVar7 = (uint)*(byte *)(iVar3 + 0x1d8);
    if (param_1[6] == iVar2) goto LAB_00651046;
    do {
      iVar3 = FUN_00574760(iVar5);
      if (iVar3 != 0) {
        iVar4 = FUN_00574760(iVar5);
        iVar2 = *(int *)(*(int *)(iVar4 + 4) + 4);
        iVar3 = iVar2 + 0x164 + iVar4;
        if (((*(int *)(iVar2 + 0x164 + iVar4) == param_1[0x196]) &&
            (*(int *)(iVar3 + 4) == param_1[0x197])) &&
           (*(char *)(iVar3 + 8) == (char)param_1[0x198])) goto LAB_00651046;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
  }
  (**(code **)(*param_1 + 0x18))(1,1);
LAB_00650fd8:
  FUN_00578b30(uVar7);
  return;
}
```
