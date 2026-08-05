# Annotated low-level: FUN_0061cdc0

| Field | Value |
|---|---|
| Stable ID | `aa_0061cdc0` |
| VA | `0x0061cdc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0061cdc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
bool FUN_0061cdc0(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  char cVar1;
  char cVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  void *pvVar8;
  int iVar9;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar10;
  CVOGHBBase *pAction;
  float fVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  char local_46;
  int local_44;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a87db;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  pvVar3 = (void *)FUN_0058ab60(param_6);
  local_44 = 0;
  local_46 = '\0';
  while( true ) {
    iVar9 = local_46 * 0x10;
    puVar6 = (undefined4 *)(iVar9 + param_4);
    if (((*(int *)(iVar9 + param_4) == -1) && (puVar6[1] == -1)) && (*(char *)(puVar6 + 2) == '\0'))
    break;
    cVar1 = FUN_00589b80(*(undefined4 *)(param_2 + 0xe4),
                         CONCAT22(local_46 >> 7,*(undefined2 *)((int)pvVar3 + local_46 * 2)));
    iVar9 = CVOGReaction_ResolveObjectTarget
                      (CONCAT31((int3)((uint)puVar6[1] >> 8),*(undefined1 *)(puVar6 + 2)),*puVar6,
                       puVar6[1]);
    if (((iVar9 != 0) &&
        (iVar9 = __RTDynamicCast(iVar9,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                 &CVOGCreature::RTTI_Type_Descriptor,0), iVar9 != 0)) &&
       ((cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9) + 0x198))(),
        cVar2 != '\0' && (*(char *)(param_3 + 0x7e) != '\0')))) {
      local_44 = local_44 + 1;
      FUN_004d0e90(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9);
      if (((*(float *)(param_2 + 0x160) != g_flZero) && (cVar1 == '\0')) &&
         (iVar4 = (**(code **)(*param_1 + 0x210))(0), iVar4 != 0)) {
        iVar5 = (int)*(float *)(param_2 + 0x164);
        puVar6 = (undefined4 *)
                 (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1a0))();
        uStack_30 = *puVar6;
        uStack_2c = puVar6[1];
        uStack_28 = puVar6[2];
        uStack_24 = puVar6[3];
        fVar11 = *(float *)(param_2 + 0x160);
        iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9) + 0x27c))();
        if (fVar11 <= (float)iVar7) {
          fVar11 = *(float *)(param_2 + 0x160);
        }
        else {
          iVar9 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9) + 0x27c))();
          fVar11 = (float)iVar9;
        }
        uVar12 = *(undefined4 *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xa8 + iVar4);
        uVar14 = 0;
        uVar13 = 0;
        iVar9 = (int)fVar11;
        puVar6 = &uStack_30;
        FUN_004ce940(iVar4,uVar12,puVar6,iVar9,iVar5,0,0);
        FUN_0050ac80(iVar4,uVar12,puVar6,iVar9,iVar5,uVar13,uVar14);
      }
    }
    local_46 = local_46 + '\x01';
  }
  pAction = (CVOGHBBase *)0x0;
  if (local_44 != 0) {
    pvVar8 = operator_new(0x6d0);
    uStack_14 = 0;
    if (pvVar8 != (void *)0x0) {
      pAction = (CVOGHBBase *)
                FUN_00618180(param_1,param_2,param_3,param_1,param_5,param_6,0,0x3f800000);
    }
    uStack_14 = 0xffffffff;
    if (pAction->pOwnerObject == (void *)0x0) {
      (**(code **)pAction->pVTable)(1);
      uVar10 = extraout_var_00;
    }
    else {
      CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);
      CVOGHBBase_Start(pAction);
      uVar10 = extraout_var;
    }
    if (*(void **)(param_2 + 0x150) != (void *)0x0) {
      puVar6 = CVOGReaction_ResolveSkillTargets
                         (*(void **)(param_2 + 0x150),
                          CONCAT22(uVar10,*(short *)(param_2 + 0x5f6) + *(short *)(param_2 + 0x174))
                         );
      CVOGReaction_CastSkillOnTarget(puVar6,param_1,param_1,0,0,&DAT_00d02ad0,0,0xffffffff,0,0);
                    /* WARNING: Subroutine does not return */
      operator_delete(puVar6);
    }
  }
  if (pvVar3 != (void *)0x0) {
    operator_delete__(pvVar3);
  }
  ExceptionList = pvStack_1c;
  return local_44 != 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
