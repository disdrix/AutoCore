# Annotated low-level: FUN_004b4eb0

| Field | Value |
|---|---|
| Stable ID | `aa_004b4eb0` |
| VA | `0x004b4eb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004b4eb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004b4eb0(int *param_1)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  double dVar4;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a1475;
  local_c = ExceptionList;
  if ((int *)*param_1 != (int *)0x0) {
    local_58 = DAT_00aaa9ec;
    local_68 = 0;
    local_60 = 0;
    local_5c = 0;
    local_64 = 0;
    local_54 = 8;
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_10 = 0;
    local_38 = 0x44;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_20 = 0;
    local_1c = 1;
    local_18 = 0;
    local_14 = 1;
    local_28 = 0x55555554;
    local_24 = 0x55555554;
    local_74 = 0;
    local_70 = DAT_009cb240;
    local_6c = 0;
    ExceptionList = &local_c;
    if (DAT_00af0758 != '\0') {
      ExceptionList = &local_c;
      (**(code **)(*(int *)*param_1 + 0x5c))();
    }
    local_44 = 0;
    piVar1 = (int *)(**(code **)(*(int *)*param_1 + 0x10))(&local_74);
    param_1[1] = (int)piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x5c))(4,4,0);
      (**(code **)(*(int *)param_1[1] + 0x5c))(4,4,0);
      (**(code **)(*(int *)param_1[1] + 0x5c))(0,4,0);
      (**(code **)(*(int *)param_1[1] + 0x5c))(1,4,0);
      (**(code **)(*(int *)param_1[1] + 0x5c))(2,4,0);
      (**(code **)(*(int *)param_1[1] + 0x5c))(3,4,0);
      dVar4 = floor(_DAT_009cb238);
      (**(code **)(*(int *)param_1[1] + 0xe0))(0x3d088889,(int)ROUND(dVar4),0);
      (**(code **)(*(int *)param_1[1] + 0x5c))(0,2,1);
      (**(code **)(*(int *)param_1[1] + 0x5c))(0,3,1);
      (**(code **)(*(int *)param_1[1] + 0x5c))(1,2,1);
      (**(code **)(*(int *)param_1[1] + 0x5c))(1,3,1);
      (**(code **)(*(int *)param_1[1] + 0x5c))(2,3,0);
      (**(code **)(*(int *)param_1[1] + 0x5c))(5,3,0);
      (**(code **)(*(int *)param_1[1] + 0x5c))(5,2,1);
      (**(code **)(*(int *)param_1[1] + 0x5c))(5,4,0);
      FUN_004b4ba0();
      pvVar2 = operator_new(8);
      uStack_4 = 0;
      if (pvVar2 != (void *)0x0) {
        iVar3 = FUN_00498ad0();
        param_1[4] = iVar3;
        ExceptionList = local_c;
        return;
      }
      param_1[4] = 0;
    }
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
