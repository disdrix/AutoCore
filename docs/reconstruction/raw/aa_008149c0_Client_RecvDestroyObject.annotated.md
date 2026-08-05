# Annotated low-level: Client_RecvDestroyObject

| Field | Value |
|---|---|
| Stable ID | `aa_008149c0` |
| VA | `0x008149c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008149c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void Client_RecvDestroyObject(int param_1)

{
  char cVar1;
  int in_EAX;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int unaff_EDI;
  uint *puVar8;
  char *pcVar9;
  undefined4 uVar10;
  uint auStack_434 [8];
  char acStack_414 [1028];
  int iStack_10;
  
  FUN_007a69d0();
  if ((*(int *)(in_EAX + 0xc78) == 0) ||
     (cVar1 = (**(code **)(**(int **)(in_EAX + 0xc78) + 8))(), cVar1 == '\0')) {
    if (*(int *)(in_EAX + 0xe98) == 0) {
      return;
    }
    iVar4 = *(int *)(*(int *)(in_EAX + 0xe98) + 0x250);
    if (iVar4 == 0) {
      return;
    }
    iVar5 = *(int *)(*(int *)(iVar4 + 4) + 4);
    if (*(int *)(iVar5 + 0x164 + iVar4) != *(int *)(param_1 + 8)) {
      return;
    }
    if (*(int *)(iVar5 + 0x168 + iVar4) != *(int *)(param_1 + 0xc)) {
      return;
    }
    FUN_00802170();
    return;
  }
  piVar2 = (int *)CVOGReaction_ResolveObjectTarget
                            (*(undefined1 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 8),
                             *(undefined4 *)(param_1 + 0xc));
  if (piVar2 == (int *)0x0) {
    return;
  }
  if (*(int *)(in_EAX + 0xe98) != 0) {
    iVar4 = *(int *)(in_EAX + 0xe98);
    iVar5 = *(int *)(*(int *)(iVar4 + 4) + 4);
    if ((*(int *)(iVar5 + 0x164 + iVar4) == *(int *)(param_1 + 0x20)) &&
       (*(int *)(iVar5 + 0x168 + iVar4) == *(int *)(param_1 + 0x24))) {
      return;
    }
  }
  (**(code **)(*piVar2 + 600))
            (*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34),
             *(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x3c));
  auStack_434[0] = piVar2[0x13];
  piVar3 = Object_ResolveFromTFID((TFID_16 *)&stack0xfffffbc0);
  if (((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x210))(0), iVar4 != 0)) &&
     ((*(int *)(in_EAX + 0xe98) == 0 ||
      ((*(int *)(*(int *)(in_EAX + 0xe98) + 0xcb0) == 0 ||
       (cVar1 = FUN_005749d0(iVar4), cVar1 != '\0')))))) {
    FUN_00522600(piVar2);
  }
  iVar4 = (**(code **)(*piVar2 + 0x210))(0);
  if (((*(int *)(in_EAX + 0xe98) != 0) && (iVar5 = (**(code **)(*piVar2 + 0x214))(), iVar5 != 0)) &&
     (((iVar4 == *(int *)(in_EAX + 0xe98) ||
       ((((*(int *)(*(int *)(in_EAX + 0xe98) + 0xcb0) != 0 &&
          (cVar1 = FUN_005749d0(iVar4), cVar1 != '\0')) || (unaff_EDI == *(int *)(in_EAX + 0xe98)))
        || ((*(int *)(*(int *)(in_EAX + 0xe98) + 0xcb0) != 0 &&
            (cVar1 = FUN_005749d0(unaff_EDI), cVar1 != '\0')))))) &&
      (*(int *)(iStack_10 + 0x28) != 1)))) {
    auStack_434[0] = auStack_434[0] & 0xffffff00;
    if ((piVar3 == (int *)0x0) || (piVar3 == piVar2)) {
      if (*(char *)(iStack_10 + 0x40) != '\0') goto LAB_00814d50;
      uVar6 = 0xffffffff;
      if (iVar4 == 0) {
        uVar10 = (**(code **)(*piVar2 + 0x15c))(0xffffffff);
      }
      else {
        uVar10 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160))();
      }
      uVar6 = FUN_007a6de0(uVar10,uVar6);
      uVar10 = FUN_007a6de0("Was Destroyed",0xffffffff);
      sprintf(acStack_414,"%s %s!",uVar6,uVar10);
    }
    else {
      if (unaff_EDI == 0) {
        iVar5 = (**(code **)(*piVar3 + 0x1d8))();
        if ((iVar5 == 0) || (iVar5 = (**(code **)(*piVar3 + 0x1d8))(), *(int *)(iVar5 + 0x250) == 0)
           ) {
          uVar6 = (**(code **)(*piVar3 + 0x15c))();
        }
        else {
          iVar5 = (**(code **)(*piVar3 + 0x1d8))();
          uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 0x250) + 4) + 4) + 4 +
                                       *(int *)(iVar5 + 0x250)) + 0x15c))();
        }
      }
      else {
        uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(unaff_EDI + 4) + 4) + 4 + unaff_EDI) + 0x160
                            ))();
      }
      uVar10 = 0xffffffff;
      if (iVar4 == 0) {
        uVar7 = (**(code **)(*piVar2 + 0x15c))(0xffffffff);
      }
      else {
        uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160))();
      }
      uVar10 = FUN_007a6de0(uVar7,uVar10);
      uVar7 = FUN_007a6de0("Has Destroyed",0xffffffff);
      sprintf(acStack_414,"%s %s %s!",uVar6,uVar7,uVar10);
    }
    uVar7 = 0;
    pcVar9 = acStack_414;
    puVar8 = auStack_434;
    uVar10 = 0x10;
    uVar6 = __RTDynamicCast(*(undefined4 *)(in_EAX + 0x109c),0,&CVOGDialog::RTTI_Type_Descriptor,
                            &CDlgChatLog::RTTI_Type_Descriptor,0,0x10,puVar8,pcVar9,0);
    FUN_008f8200(uVar6,uVar10,puVar8,pcVar9,uVar7);
  }
LAB_00814d50:
  FUN_009440e0(piVar2,*(undefined1 *)(iStack_10 + 0x40),*(undefined4 *)(iStack_10 + 0x28),
               *(undefined4 *)(iStack_10 + 0x18),*(undefined4 *)(iStack_10 + 0x1c));
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
