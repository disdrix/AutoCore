# Annotated low-level: FUN_008e3cd0

| Field | Value |
|---|---|
| Stable ID | `aa_008e3cd0` |
| VA | `0x008e3cd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008e3cd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_008e3cd0(int param_1,undefined4 *param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_EAX;
  int iVar4;
  char *pcVar5;
  int *extraout_EAX;
  int iVar6;
  char *pcVar7;
  int *unaff_EDI;
  undefined4 *puVar8;
  int local_120;
  int iStack_11c;
  undefined4 auStack_118 [2];
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined1 auStack_108 [3];
  undefined4 uStack_105;
  undefined1 auStack_fe [254];
  
  param_1 = param_1 - (int)param_2;
  local_120 = 5;
  do {
    if (*(int *)(param_1 + (int)param_2) == 0) {
      (**(code **)(*(int *)*param_2 + 4))(0);
    }
    else {
      iVar4 = (**(code **)(*(int *)*param_2 + 700))();
      if ((iVar4 == 0) || (*(char *)(in_EAX + 0x7e3) != '\0')) {
        pcVar5 = (char *)(**(code **)(**(int **)(param_1 + (int)param_2) + 0x160))();
        pcVar7 = (char *)((int)&uStack_105 + 1);
        do {
          cVar1 = *pcVar5;
          *pcVar7 = cVar1;
          pcVar5 = pcVar5 + 1;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        puVar3 = &uStack_105;
        do {
          puVar8 = puVar3;
          puVar3 = (undefined4 *)((int)puVar8 + 1);
        } while (*(char *)((int)puVar8 + 1) != '\0');
        *(undefined4 *)((int)puVar8 + 1) = DAT_00a2c534;
        piVar2 = (int *)*param_2;
        *(undefined2 *)((int)puVar8 + 5) = DAT_00a2c538;
        *(undefined1 *)((int)puVar8 + 7) = DAT_00a2c53a;
        iVar4 = (**(code **)(*piVar2 + 0x50))((int)&uStack_105 + 1,1,0);
        if (iVar4 < 0) {
          (**(code **)(*(int *)*param_2 + 0x50))("i_d_qb_2d_btn_slot_off.dds",1,0);
        }
        (**(code **)(*(int *)*param_2 + 0x2c4))();
      }
      auStack_118[0] = *(undefined4 *)(*(int *)(*(int *)(param_1 + (int)param_2) + 0xa8) + 0x34);
      iStack_11c = 0;
      Map_LowerBoundFindByIntKey((void *)(in_EAX + 0x7e8),auStack_108,auStack_118,unaff_EDI);
      iVar4 = *extraout_EAX;
      *(int *)(in_EAX + 0x800) = iVar4;
      if (iVar4 == *(int *)(in_EAX + 0x7ec)) {
        uStack_110 = *(undefined4 *)(*(int *)(*(int *)(param_1 + (int)param_2) + 0xa8) + 0x34);
        uStack_10c = 1;
        FUN_0040ed60(auStack_118,&uStack_110);
      }
      else {
        iStack_11c = *(int *)(iVar4 + 0x10);
        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
      }
      FUN_008e3bd0();
      iVar4 = FUN_005711c0(*(undefined4 *)(*(int *)(*(int *)(param_1 + (int)param_2) + 0xa8) + 0x34)
                           ,0);
      if (*(char *)(DAT_00d1b644 + 0xf5) != '\0') {
        iVar6 = FUN_005711c0(*(undefined4 *)
                              (*(int *)(*(int *)(param_1 + (int)param_2) + 0xa8) + 0x34),0);
        iVar4 = iVar4 + iVar6;
      }
      if (iVar4 <= iStack_11c) {
        *(undefined1 *)(in_EAX + 0x7d8) = 0;
      }
      (**(code **)(*(int *)*param_2 + 0xcc))(1);
      (**(code **)(*(int *)*param_2 + 0x158))(0,&stack0xfffffecc);
      (**(code **)(*(int *)*param_2 + 0x34c))();
    }
    param_2 = param_2 + 1;
    local_120 = local_120 + -1;
  } while (local_120 != 0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
