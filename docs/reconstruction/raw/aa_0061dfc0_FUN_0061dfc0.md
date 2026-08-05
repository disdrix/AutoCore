# Raw capture: FUN_0061dfc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061dfc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0061dfc0` |
| **Canonical name** | `FUN_0061dfc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4
FUN_0061dfc0(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  CVOGHBBase *pAction;
  int iVar6;
  int iVar7;
  int *piVar8;
  char local_15;
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a881b;
  local_c = ExceptionList;
  local_14 = 0;
  ExceptionList = &local_c;
  pvVar2 = (void *)FUN_0058ab60(param_6);
  local_15 = '\0';
  iVar6 = 0;
  do {
    piVar8 = (int *)(param_4 + local_15 * 0x10);
    if (((*piVar8 == -1) && (piVar8[1] == -1)) && ((char)piVar8[2] == '\0')) {
      if (pvVar2 != (void *)0x0) {
        operator_delete__(pvVar2);
      }
      if (local_14 == 0) {
        ExceptionList = local_c;
        return 0;
      }
      pvVar5 = operator_new(0x6d0);
      local_4 = 0;
      if (pvVar5 == (void *)0x0) {
        pAction = (CVOGHBBase *)0x0;
      }
      else {
        pAction = (CVOGHBBase *)
                  FUN_00618180(param_1,param_2,param_3,param_1,param_5,param_6,0,(float)local_14);
      }
      local_4 = 0xffffffff;
      if (pAction->pOwnerObject == (void *)0x0) {
        (**(code **)pAction->pVTable)(1);
        ExceptionList = pvVar2;
        return 1;
      }
      CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);
      CVOGHBBase_Start(pAction);
      ExceptionList = local_c;
      return 1;
    }
    cVar1 = FUN_00589b80(*(undefined4 *)(param_2 + 0xe4),
                         CONCAT22(local_15 >> 7,*(undefined2 *)((int)pvVar2 + local_15 * 2)));
    iVar7 = iVar6;
    if (cVar1 == '\0') {
      local_14 = local_14 + 1;
      iVar3 = CVOGReaction_ResolveObjectTarget
                        (CONCAT31((int3)((uint)piVar8[1] >> 8),(char)piVar8[2]),*piVar8,piVar8[1]);
      if (iVar3 != 0) {
        iVar4 = __RTDynamicCast(iVar3,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                &CVOGCreature::RTTI_Type_Descriptor,0);
        if (iVar4 == 0) {
          iVar4 = __RTDynamicCast(iVar3,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                  &CVOGVehicle::RTTI_Type_Descriptor,0);
          if (iVar4 != 0) {
            iVar3 = __RTDynamicCast(iVar3,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                    &CVOGVehicle::RTTI_Type_Descriptor,0);
            iVar4 = __RTDynamicCast(*(undefined4 *)
                                     (*(int *)(*(int *)(iVar3 + 4) + 4) + 0xb0 + iVar3),0,
                                    &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                    &CVOGCreature::RTTI_Type_Descriptor,0);
            if (iVar4 != 0) goto LAB_0061e0e5;
          }
        }
        else {
LAB_0061e0e5:
          iVar7 = iVar4;
          if (iVar6 != 0) {
            (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0x238))
                      (2,*(undefined4 *)(param_2 + 0x5fc),
                       (int)(short)(*(short *)(param_2 + 0x5f6) + *(short *)(param_2 + 0x174)),0,
                       *(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6,0,0,0);
          }
        }
      }
    }
    local_15 = local_15 + '\x01';
    iVar6 = iVar7;
  } while( true );
}
```
