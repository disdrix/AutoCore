# Annotated low-level: FUN_0061fdf0

| Field | Value |
|---|---|
| Stable ID | `aa_0061fdf0` |
| VA | `0x0061fdf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0061fdf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0061fdf0(int *param_1,undefined4 *param_2)

{
  ushort uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  void *pvVar7;
  CVOGHBBase *pAction;
  TFID_16 *pA;
  float fVar8;
  undefined4 uVar9;
  uint *puVar10;
  int iStack_cc8;
  uint *puStack_cc4;
  undefined4 uStack_cc0;
  undefined4 uStack_cbc;
  undefined4 uStack_cb8;
  undefined4 uStack_cb4;
  undefined4 local_cac;
  int *local_ca8;
  void *pvStack_ca4;
  TFID_16 aTStack_ca0 [100];
  uint auStack_660 [401];
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a88b3;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  FUN_0061b6f0(&local_cac);
  local_ca8 = (int *)FUN_00578270();
  if ((local_ca8 != (int *)0x0) && (cVar3 = (**(code **)(*local_ca8 + 0x198))(), cVar3 == '\0')) {
    if ((*(char *)(param_1[0x1a2] + 0x7e) != '\0') && (param_1[4] != 0)) {
      iVar4 = CVOGReaction_RandomUnitScalar();
      if (0xfffff < *(int *)(iVar4 + 0xc)) {
        *(undefined4 *)(iVar4 + 0xc) = 0;
      }
      uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
      if (0x19 < (uint)uVar1 % 100) {
        iVar4 = __RTDynamicCast(param_1[6],0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                &CVOGCreature::RTTI_Type_Descriptor,0);
        if (((iVar4 == 0) || (*(int *)(iVar4 + 0x250) == 0)) &&
           (iVar4 = __RTDynamicCast(param_1[6],0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                    &CVOGPhysicsBase::RTTI_Type_Descriptor,0), iVar4 == 0))
        goto LAB_0062016b;
        puVar5 = (undefined4 *)FUN_00404c90();
        uStack_cc0 = *puVar5;
        uStack_cbc = puVar5[1];
        uStack_cb8 = puVar5[2];
        uStack_cb4 = puVar5[3];
        aTStack_ca0[0].bGlobal = (undefined1)DAT_009e2df8;
        aTStack_ca0[0].bPad0 = DAT_009e2df8._1_1_;
        aTStack_ca0[0].bPad1 = DAT_009e2df8._2_1_;
        aTStack_ca0[0].bPad2 = DAT_009e2df8._3_1_;
        aTStack_ca0[0].dwCoidLo = DAT_009e2df0;
        aTStack_ca0[0].dwCoidHi = DAT_009e2df4;
        aTStack_ca0[0].bPad3 = (undefined1)DAT_009e2dfc;
        aTStack_ca0[0].bPad4 = DAT_009e2dfc._1_1_;
        aTStack_ca0[0].bPad5 = DAT_009e2dfc._2_1_;
        aTStack_ca0[0].bPad6 = DAT_009e2dfc._3_1_;
        fVar8 = DAT_00a0f524;
        if ((float)param_1[0x17] != g_flZero) {
          fVar8 = (float)param_1[0x17];
        }
        cVar3 = *(char *)((int)param_1 + 0x102);
        if (cVar3 == '\0') {
          cVar3 = '\x04';
        }
        Skill_GatherTargetsInArea
                  (aTStack_ca0,0,param_1[0x1a2],param_1[6],&uStack_cc0,(float)(int)fVar8,cVar3,1,
                   0xffffffff,0,0,1,0,0,0xbf800000);
        iVar4 = TFID_NotEquals(aTStack_ca0,&DAT_009e2df0);
        if (((char)iVar4 != '\0') && (0 < param_1[0x1b4])) {
          puVar10 = auStack_660;
          uVar9 = 600;
          CVOGReaction_RandomUnitScalar(600,puVar10);
          FUN_0051b720(uVar9,puVar10);
          param_1[0x1b4] = param_1[0x1b4] + -1;
          param_1[0x1b5] = param_1[0x1b5] + -1;
          iStack_cc8 = 0;
          iVar6 = TFID_NotEquals(aTStack_ca0,&DAT_009e2df0);
          iVar4 = 0;
          if ((char)iVar6 != '\0') {
            puStack_cc4 = auStack_660;
            pA = aTStack_ca0;
            do {
              pvVar7 = Object_ResolveFromTFID(aTStack_ca0);
              if (pvVar7 != (void *)0x0) {
                pvStack_ca4 = operator_new(0x6e0);
                uStack_14 = 0;
                if (pvStack_ca4 == (void *)0x0) {
                  pAction = (CVOGHBBase *)0x0;
                }
                else {
                  pAction = (CVOGHBBase *)
                            FUN_0061f940(local_ca8,param_1 + 9,param_1[0x1a2],pvVar7,&DAT_00d02af0,
                                         param_1[0x1aa],param_1[0x1b4],param_1[0x1b5]);
                }
                uStack_14 = 0xffffffff;
                if (pAction->pOwnerObject == (void *)0x0) {
                  (**(code **)pAction->pVTable)(1);
                }
                else {
                  CVOGHBList_Enqueue(*(void **)(param_1[0x1a2] + 0xe4ec),pAction);
                  CVOGHBBase_Start(pAction);
                  iStack_cc8 = iStack_cc8 + 1;
                  *puStack_cc4 = pA->dwCoidLo;
                  puStack_cc4[1] = pA->dwCoidHi;
                  uVar2 = *(uint *)&pA->bPad3;
                  puStack_cc4[2] = *(uint *)&pA->bGlobal;
                  puStack_cc4[3] = uVar2;
                  puStack_cc4 = puStack_cc4 + 4;
                }
              }
              pA = pA + 1;
              iVar6 = TFID_NotEquals(pA,&DAT_009e2df0);
              iVar4 = iStack_cc8;
            } while ((char)iVar6 != '\0');
          }
          auStack_660[iVar4 * 4] = DAT_009e2df0;
          auStack_660[iVar4 * 4 + 1] = DAT_009e2df4;
          auStack_660[iVar4 * 4 + 2] = DAT_009e2df8;
          auStack_660[iVar4 * 4 + 3] = DAT_009e2dfc;
        }
      }
    }
    *param_2 = local_cac;
    ExceptionList = pvStack_1c;
    return;
  }
  (**(code **)(*param_1 + 0x18))(1,1);
LAB_0062016b:
  *param_2 = 0;
  ExceptionList = pvStack_1c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
