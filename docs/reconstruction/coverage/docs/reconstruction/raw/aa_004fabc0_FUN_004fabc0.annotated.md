# Annotated low-level: FUN_004fabc0

| Field | Value |
|---|---|
| Stable ID | `aa_004fabc0` |
| VA | `0x004fabc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fabc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __thiscall FUN_004fabc0(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_2 == (int *)0x0) {
    return 8;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  param_2[0x5f] = param_2[0x5f] | 0x10;
  FUN_00512670();
  if (((uint)param_2[0x5f] >> 0x13 & 1) != 0) {
    return 9;
  }
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0xf6) != '\0')) {
    return 0xf;
  }
  uVar5 = 0;
  uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0,1);
  cVar2 = FUN_00514390(uVar3,uVar5);
  if (cVar2 != '\0') {
    switch(*(undefined4 *)(param_2[0x2a] + 0x38)) {
    case 6:
      uVar3 = __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                              &CVOGSimpleObject<class_CVOGGraphicsBase>::RTTI_Type_Descriptor,0,
                              param_3);
      uVar4 = FUN_004f6940(uVar3,param_3);
      return uVar4;
    default:
      return 8;
    case 8:
    case 0x32:
      return 0xc;
    case 10:
      uVar3 = (**(code **)(*param_2 + 500))(param_3);
      uVar4 = FUN_004f6840(uVar3,param_3);
      return uVar4;
    case 0xc:
      uVar3 = (**(code **)(*param_2 + 0x1e0))(param_3);
      uVar4 = FUN_004f65e0(uVar3,param_3);
      return uVar4;
    case 0xe:
      goto switchD_004fac7b_caseD_e;
    case 0x10:
      uVar3 = (**(code **)(*param_2 + 0x1f0))(param_3);
      uVar4 = FUN_004f6890(uVar3,param_3);
      return uVar4;
    case 0x1c:
      uVar3 = (**(code **)(*param_2 + 0x1f8))(param_3);
      uVar4 = FUN_004f67e0(uVar3,param_3);
      return uVar4;
    }
  }
  return 6;
switchD_004fac7b_caseD_e:
  cVar2 = FUN_004ce5f0(param_1);
  if (cVar2 == '\0') {
    return 1;
  }
  cVar2 = FUN_004f6560();
  return -(uint)(cVar2 != '\0') & 0xe;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
