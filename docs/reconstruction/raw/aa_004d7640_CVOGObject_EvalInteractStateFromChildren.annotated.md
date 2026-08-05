# Annotated low-level: CVOGObject_EvalInteractStateFromChildren

| Field | Value |
|---|---|
| Stable ID | `aa_004d7640` |
| VA | `0x004d7640` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d7640`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGObject_EvalInteractStateFromChildren
   
   Aggregate interact state from child dialog/give-mission entries on an NPC object (type 0x12).
   Reaction-like child types:
     0x1e GiveMission: state 6 (new) or 7 (core) if not completed
     0x1f active objective: state 4
     0x25 deliver/use paths via helpers
   Picks highest priority state (complete=8 wins over lower). */

char CVOGObject_EvalInteractStateFromChildren
               (void *param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  undefined4 *puVar5;
  void *pvVar6;
  int iVar7;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined1 local_24 [4];
  void *local_20;
  undefined4 local_1c;
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined4 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a219b;
  local_c = ExceptionList;
  if (*(int *)(*(int *)(param_2 + 0xa8) + 0x38) != 0x12) {
    return '\x01';
  }
  ExceptionList = &local_c;
  local_14 = FUN_0040fb90();
  local_10 = (undefined4 *)0x0;
  local_4 = 0;
  local_20 = (void *)FUN_0040fb90();
  local_1c = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  if (param_1 == (void *)0x0) {
    iVar7 = 0;
  }
  else {
    iVar7 = *(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1;
  }
  (**(code **)(*(int *)(*(int *)(*(int *)(param_4 + 4) + 4) + 4 + param_4) + 0x130))
            (iVar7,1,local_18,local_24,0);
  if (unaff_EBP == 0) {
    FUN_00403430();
    FUN_00403430();
    ExceptionList = local_20;
    return '\0';
  }
  cVar4 = '\0';
  for (local_10 = (undefined4 *)*unaff_ESI; local_10 != unaff_ESI;
      local_10 = (undefined4 *)*local_10) {
    iVar7 = local_10[2];
    cVar3 = *(char *)(iVar7 + 0x1d1);
    if (cVar3 == '\x1e') {
      uVar1 = *(uint *)(iVar7 + 0x25c);
      puVar5 = (undefined4 *)FUN_0053fff0();
      if ((void *)*puVar5 == (void *)0x0) {
        pvVar6 = (void *)0x0;
      }
      else {
        pvVar6 = CNDHash_LookupByKey((void *)*puVar5,uVar1);
      }
      bVar2 = false;
      if ((pvVar6 != (void *)0x0) && (*(short *)((int)pvVar6 + 0xac) == -1)) {
        bVar2 = true;
      }
      uVar1 = *(uint *)(iVar7 + 0x25c);
      for (iVar7 = *(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 0x540) + 0x10) +
                                    (*(uint *)(*(int *)((int)param_1 + 0x540) + 8) & uVar1) * 4) + 4
                           ); iVar7 != 0; iVar7 = *(int *)(iVar7 + 0xc)) {
        if (uVar1 == *(uint *)(iVar7 + 0x10)) {
          if ((iVar7 != 0) && (*(int *)(iVar7 + 8) != 0)) goto LAB_004d7894;
          break;
        }
      }
      if ((!bVar2) && (bVar2 = CVOGCharacter_HasCompletedMission(param_1,uVar1), bVar2))
      goto LAB_004d7894;
      FUN_00547920(0);
      if (*(char *)((int)pvVar6 + 0x169) == '\0') {
        if ('\x05' < cVar4) goto LAB_004d7894;
        cVar4 = '\x06';
      }
      else {
        if ('\x06' < cVar4) goto LAB_004d7894;
        cVar4 = '\a';
      }
    }
    else {
      if (cVar3 != '%') {
        if (cVar3 == '\x1f') {
          pvVar6 = CNDHash_LookupByKey(*(void **)((int)param_1 + 0x548),*(uint *)(iVar7 + 0x25c));
          if ((pvVar6 == (void *)0x0) || ('\x03' < cVar4)) goto LAB_004d7894;
          cVar4 = '\x04';
        }
        else {
          if ('\x01' < cVar4) goto LAB_004d7894;
          cVar4 = '\x02';
        }
        goto LAB_004d7899;
      }
      cVar3 = FUN_004d3ba0(iVar7,param_1);
      if (cVar4 < cVar3) {
        cVar4 = FUN_004d3ba0(iVar7,param_1);
      }
      if (cVar4 < '\x06') {
        cVar3 = FUN_004d2e50(iVar7,param_1);
        if (cVar4 < cVar3) {
          cVar4 = FUN_004d2e50(iVar7,param_1);
        }
        pvVar6 = local_c;
        if ((cVar4 < '\x06') &&
           (cVar3 = CVOGObject_EvalOfferableMissionInteractState(local_c,param_1,&local_4),
           cVar4 < cVar3)) {
          cVar4 = CVOGObject_EvalOfferableMissionInteractState(pvVar6,param_1,&local_4);
        }
      }
LAB_004d7894:
      if (cVar4 == '\b') break;
    }
LAB_004d7899:
  }
  FUN_00403430();
  FUN_00403430();
  ExceptionList = local_20;
  return cVar4;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
