# Raw capture: FUN_005db5a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005db5a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005db5a0` |
| **Canonical name** | `FUN_005db5a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005db5a0(int param_1,int *param_2)

{
  char cVar1;
  RACE_ID_INFERRED RVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  void *pvVar7;
  bool bVar8;
  undefined1 *puVar9;
  undefined4 *pB;
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [16];
  undefined1 auStack_10 [16];
  
  if (param_2 == (int *)0x0) {
    return;
  }
  if (*(char *)(param_1 + 0xde) == '\0') {
    return;
  }
  *(uint *)(param_1 + 0x194) = g_dwClientTickMs;
  if (*(char *)(param_1 + 0x160) == '\0') {
    return;
  }
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x181 + param_1) & 0x20) == 0) {
    return;
  }
  cVar1 = (**(code **)(*param_2 + 0x198))();
  if (cVar1 != '\0') {
    return;
  }
  switch(*(undefined1 *)(param_1 + 0xdc)) {
  case 0:
    iVar4 = (**(code **)(*param_2 + 0x210))(0);
    if (iVar4 != 0) {
LAB_005db706:
      FUN_004d0250(param_1,param_2);
      return;
    }
    if (*(int *)(param_2[0x2a] + 0x38) == 0x12) {
      pB = &DAT_009db5b0;
      puVar9 = auStack_30;
      __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                      &CVOGCreature::RTTI_Type_Descriptor,0,puVar9);
      pvVar7 = (void *)FUN_004ba740(puVar9);
      iVar4 = TFID_NotEquals(pvVar7,pB);
      if ((char)iVar4 != '\0') {
LAB_005db673:
        FUN_004d0250(param_1,param_2);
        return;
      }
    }
    break;
  case 1:
    bVar8 = *(int *)(param_2[0x2a] + 0x38) == 0x12;
    goto LAB_005db69a;
  case 2:
    bVar8 = *(int *)(param_2[0x2a] + 0x38) == 0xe;
LAB_005db69a:
    if (bVar8) {
      FUN_004d0250(param_1,param_2);
      return;
    }
    break;
  case 3:
    iVar4 = (**(code **)(*param_2 + 0x214))();
    if ((iVar4 != 0) &&
       (iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1),
       RVar2 = Object_GetRootRaceId((void *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4)),
       RVar2 != *(RACE_ID_INFERRED *)(iVar3 + 0xf8))) goto LAB_005db706;
    break;
  case 4:
    pvVar7 = *(void **)(param_1 + 0x128);
    if (pvVar7 != *(void **)(param_1 + 300)) {
      do {
        if (*(int *)(param_2[0x2a] + 0x38) == 0xe) {
          iVar4 = __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                  &CVOGVehicle::RTTI_Type_Descriptor,0);
          iVar4 = *(int *)(iVar4 + 0x280);
LAB_005db768:
          if ((iVar4 != 0) &&
             (iVar4 = TFID_EqualsObjectId((void *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0x164 + iVar4
                                                  ),pvVar7), (char)iVar4 != '\0')) {
            FUN_004d0250(param_1,param_2);
          }
        }
        else {
          if (*(int *)(param_2[0x2a] + 0x38) == 0x12) {
            iVar4 = __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                    &CVOGCreature::RTTI_Type_Descriptor,0);
            iVar4 = *(int *)(iVar4 + 600);
            goto LAB_005db768;
          }
          iVar4 = TFID_EqualsObjectId(pvVar7,param_2 + 0x58);
          if ((char)iVar4 != '\0') goto LAB_005db673;
        }
        pvVar7 = (void *)((int)pvVar7 + 0x10);
        if (pvVar7 == *(void **)(param_1 + 300)) {
          return;
        }
      } while( true );
    }
    break;
  case 5:
    iVar4 = (**(code **)(*param_2 + 0x214))();
    if (iVar4 != 0) {
      uVar5 = FUN_0040aff0(auStack_20);
      iVar4 = FUN_004bb070(uVar5);
      if ((iVar4 != 0) && (piVar6 = *(int **)(param_1 + 0x128), piVar6 != *(int **)(param_1 + 300)))
      {
        do {
          iVar3 = (**(code **)(*param_2 + 0x1d4))();
          if (iVar3 != 0) {
            iVar3 = (**(code **)(*param_2 + 0x1d4))();
            if ((*(int *)(iVar3 + 0x14c) == *piVar6) &&
               (*(int *)(iVar3 + 0x14c) >> 0x1f == piVar6[1])) {
              FUN_004d0250(param_1,*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4);
              return;
            }
          }
          piVar6 = piVar6 + 4;
        } while (piVar6 != *(int **)(param_1 + 300));
      }
    }
    break;
  case 6:
    iVar4 = (**(code **)(*param_2 + 0x214))();
    if (iVar4 != 0) {
      uVar5 = FUN_0040aff0(auStack_10);
      iVar4 = FUN_004bb070(uVar5);
      if ((iVar4 != 0) && (piVar6 = *(int **)(param_1 + 0x128), piVar6 != *(int **)(param_1 + 300)))
      {
        while ((*(int *)(param_2[0x2a] + 0x34) != *piVar6 ||
               (*(int *)(param_2[0x2a] + 0x34) >> 0x1f != piVar6[1]))) {
          piVar6 = piVar6 + 4;
          if (piVar6 == *(int **)(param_1 + 300)) {
            return;
          }
        }
        FUN_004d0250(param_1,*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4);
        return;
      }
    }
    break;
  default:
    FUN_007a4480(0,"VOG_DEBUG_STOP");
    return;
  }
  return;
}
```
