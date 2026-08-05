# Annotated low-level: FUN_004fedc0

| Field | Value |
|---|---|
| Stable ID | `aa_004fedc0` |
| VA | `0x004fedc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fedc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
FUN_004fedc0(int param_1,int *param_2,int param_3,undefined4 param_4,undefined4 param_5,int *param_6
            ,undefined4 param_7)

{
  void **ppvVar1;
  char cVar2;
  uint3 uVar8;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar9;
  CVOGHBBase *pAction;
  undefined4 unaff_retaddr;
  undefined4 uVar10;
  undefined4 uVar11;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &DAT_009a2d8e;
  pvStack_c = ExceptionList;
  ppvVar1 = &pvStack_c;
  if ((char)param_7 != '\0') {
    uVar8 = (uint3)((uint)ExceptionList >> 8);
    if ((*(char *)((int)param_2 + 0x151) == '\0') && ((char)param_6 != '\0')) {
      iVar4 = CONCAT31(uVar8,1);
    }
    else {
      iVar4 = (uint)uVar8 << 8;
    }
    ExceptionList = &pvStack_c;
    FUN_005c93f0(param_2,param_3,param_4,0,iVar4,param_7);
    ppvVar1 = ExceptionList;
  }
  ExceptionList = ppvVar1;
  if (param_3 == 2) {
    if ((char)param_6 != '\0') {
      uVar9 = 0;
      do {
        iVar4 = *(int *)(*(int *)(param_1 + -0x410) + uVar9 * 4);
        if (iVar4 != 0) {
          Vehicle_AttachWeapon(iVar4,uVar9,1);
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < 3);
    }
    iVar4 = *(int *)(*(int *)(param_1 + -0x66c) + 4);
    iVar7 = *(int *)(iVar4 + -0x5c8 + param_1);
    pAction = (CVOGHBBase *)0x0;
    if (((iVar7 != 0) && (*(char *)(iVar7 + 0xf5) == '\0')) &&
       (cVar2 = (**(code **)(*(int *)(iVar4 + -0x66c + param_1) + 0x198))(), cVar2 == '\0')) {
      pvVar3 = operator_new(0x28);
      uStack_4 = 0;
      if (pvVar3 != (void *)0x0) {
        pAction = (CVOGHBBase *)Vehicle_CreateWeaponTrackAction(param_1 + -0x670);
      }
      uStack_4 = 0xffffffff;
      CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 +
                                            param_1) + 0xe4ec),pAction);
      CVOGHBBase_Start(pAction);
    }
  }
  FUN_0053d970(1);
  if (param_3 != 2) goto LAB_004ff10b;
  if (param_2[0x57] != -1) {
    if (*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1) != 0) {
      param_6 = Object_ResolveFromTFID((TFID_16 *)(param_2 + 0x7a));
    }
    if ((param_6 == (int *)0x0) &&
       (param_6 = (int *)CVOGReaction_GiveItemByCbid(param_2[0x57]), param_6 != (int *)0x0)) {
      (**(code **)(*param_6 + 8))
                (param_2[0x57],
                 *(undefined4 *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1),1);
      (**(code **)(*param_6 + 0xc4))
                (param_2 + 0x56,2,
                 *(undefined4 *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1),
                 unaff_retaddr,0,2,0);
    }
    iVar4 = __RTDynamicCast(param_6,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                            &CVOGSimpleObject<class_CVOGGraphicsBase>::RTTI_Type_Descriptor,0);
    if (iVar4 == 0) {
      FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",param_2[0x57]);
    }
    else {
      FUN_004fe620(iVar4,0,1);
    }
  }
  if (param_2[0x1c3] == -1) {
    *(undefined4 *)(param_1 + -0x40c) = 0;
    goto LAB_004ff10b;
  }
  if ((*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1) == 0) ||
     (piVar5 = Object_ResolveFromTFID((TFID_16 *)(param_2 + 0x1e6)), piVar5 == (int *)0x0)) {
    piVar5 = (int *)CVOGReaction_GiveItemByCbid(param_2[0x1c3]);
    if (piVar5 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar5 + 0x1e0))();
      if (iVar4 != 0) {
        (**(code **)(*piVar5 + 8))
                  (param_2[0x1c3],
                   *(undefined4 *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1),1);
        iVar4 = (**(code **)(*piVar5 + 0x1e0))();
        (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0xc4))
                  (param_2 + 0x1c2,2,
                   *(undefined4 *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1),
                   unaff_retaddr,param_2,2,0);
      }
      goto LAB_004ff0b2;
    }
  }
  else {
LAB_004ff0b2:
    iVar4 = (**(code **)(*piVar5 + 0x1e0))();
    if (iVar4 != 0) {
      uVar11 = 1;
      uVar10 = 0;
      uVar6 = __RTDynamicCast(piVar5,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                              &CVOGWeaponMelee::RTTI_Type_Descriptor,0,0,1);
      FUN_004fe800(uVar6,uVar10,uVar11);
      goto LAB_004ff10b;
    }
  }
  FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",param_2[0x1c3]);
LAB_004ff10b:
  iVar4 = *(int *)(*(int *)(param_1 + -0x66c) + 4);
  if (*(int *)(iVar4 + -0x5c8 + param_1) != 0) {
    iVar7 = FUN_004bb040(*(undefined1 *)(iVar4 + -0x504 + param_1),param_2[0x36],param_2[0x37]);
    iVar4 = iVar7;
    if (iVar7 != 0) {
      iVar4 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;
    }
    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c + param_1) + 0x158))
              (iVar4);
    if (iVar7 != 0) {
      if (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1) + 0xf5) ==
          '\0') {
        FUN_004f3e40(iVar7);
      }
      *(bool *)(param_1 + -0x56f) = *(char *)(iVar7 + 0x30c) == '\0';
      if ((char)param_2[0x54] == '\0') {
        FUN_004c49d0(param_1 + -0x670);
      }
    }
    piVar5 = *(int **)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c0 + param_1);
    if ((((piVar5 != (int *)0x0) && (iVar4 = (**(code **)(*piVar5 + 0x1dc))(), iVar4 != 0)) &&
        (*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4 ==
         *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1) + 0xe8a0)))
       && (*(int *)(iVar4 + 0x250) == param_1 + -0x670)) {
      FUN_0053d970(0);
      if (*(char *)(iVar4 + 0x30c) == '\0') {
        *(undefined1 *)(param_1 + -0x56f) = 1;
        (**(code **)(*(int *)(param_1 + -0x670) + 4))();
        (**(code **)(*(int *)(param_1 + -0x630) + 0x18))(0);
      }
      iVar7 = 0;
      iVar4 = 3;
      do {
        if (*(int *)(iVar7 + *(int *)(param_1 + -0x410)) != 0) {
          FUN_0056be70();
        }
        iVar7 = iVar7 + 4;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if (*(int *)(param_1 + -0x40c) != 0) {
        FUN_0056be70();
      }
      iVar4 = *(int *)(*(int *)(param_1 + -0x66c) + 4);
      piVar5 = *(int **)(iVar4 + -0x548 + param_1);
      if (((piVar5 != (int *)0x0) && (*(int *)(iVar4 + param_1 + -0x544) - (int)piVar5 >> 2 != 0))
         && (*piVar5 != 0)) {
        FUN_004b6a00();
      }
    }
    if (((*param_2 == 0x201e) && (*(int *)(param_1 + -0x628) != 0)) &&
       ((iVar4 = *(int *)(*(int *)(param_1 + -0x628) + 0x94), iVar4 != 0 &&
        (iVar4 = __RTDynamicCast(iVar4,0,&gfxLODHandler::RTTI_Type_Descriptor,
                                 &gfxLODHandler_AutoAssault::RTTI_Type_Descriptor,0), iVar4 != 0))))
    {
      FUN_00760fe0(0,0x4479c000);
    }
    if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1) + 0xe898) !=
        0) {
      FUN_004962b0();
    }
  }
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
