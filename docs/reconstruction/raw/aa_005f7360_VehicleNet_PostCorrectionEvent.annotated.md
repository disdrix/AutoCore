# Annotated low-level: VehicleNet_PostCorrectionEvent

| Field | Value |
|---|---|
| Stable ID | `aa_005f7360` |
| VA | `0x005f7360` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005f7360`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
VehicleNet_PostCorrectionEvent
          (int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  float fVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  void *pvVar8;
  undefined4 *puVar9;
  int iVar10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a7b81;
  pvStack_c = ExceptionList;
  iVar10 = 0;
  ExceptionList = &pvStack_c;
  if (*(int *)(param_1 + 0x50) != 0) {
    ExceptionList = &pvStack_c;
    iVar6 = (**(code **)(**(int **)(param_1 + 0x50) + 0x1d4))();
    pvVar4 = param_2;
    fVar3 = g_flOne;
    if (*(char *)(iVar6 + 0x103) == '\0') {
      if (param_2 != (void *)0x0) {
        *(undefined4 *)((int)param_2 + 0xd0) = 0xffffffff;
        *(undefined4 *)((int)param_2 + 0x84) = 1;
        *(undefined1 *)((int)param_2 + 0xa0) = 1;
        *(float *)((int)param_2 + 0x80) = fVar3;
        *(undefined4 *)((int)param_2 + 8) = 0xffffffff;
        *(undefined4 *)((int)param_2 + 0xc) = 0xffffffff;
        *(undefined4 *)((int)param_2 + 0x28) = 0xffffffff;
        *(undefined4 *)((int)param_2 + 0x2c) = 0xffffffff;
        *(undefined4 *)((int)param_2 + 0x30) = 0xffffffff;
        *(undefined4 *)((int)param_2 + 0x34) = 0xffffffff;
        *(undefined4 *)((int)param_2 + 0x38) = 0xffffffff;
        puVar7 = operator_new(0x18);
        if (puVar7 == (undefined4 *)0x0) {
          puVar7 = (undefined4 *)0x0;
        }
        else {
          puVar7[2] = 0;
        }
        *puVar7 = 0xffffffff;
        puVar7[1] = 0;
        param_2 = puVar7;
        pvVar8 = operator_new(0x18);
        uStack_4 = 0;
        if (pvVar8 != (void *)0x0) {
          iVar10 = FUN_00424ce0(0,0);
        }
        piVar2 = (int *)puVar7[2];
        uStack_4 = 0xffffffff;
        if (piVar2 != (int *)0x0) {
          piVar1 = piVar2 + 2;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar2 + 8))();
          }
        }
        uVar5 = param_4;
        puVar7[2] = iVar10;
        if (iVar10 != 0) {
          *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + 1;
        }
        FUN_005a2120(pvVar4,param_4,1);
        puVar7[3] = *(undefined4 *)(puVar7[2] + 0xc);
        puVar7[4] = uVar5;
        FUN_005b2d70(&param_2);
        puVar7 = malloc(0x40);
        *puVar7 = 0x203c;
        puVar7[2] = *(undefined4 *)((int)pvVar4 + 0x90);
        puVar7[3] = *(undefined4 *)((int)pvVar4 + 0x94);
        puVar7[4] = *(undefined4 *)((int)pvVar4 + 0x98);
        puVar7[5] = *(undefined4 *)((int)pvVar4 + 0x9c);
        iVar10 = *(int *)(param_1 + 0x50);
        puVar7[6] = *(undefined4 *)(iVar10 + 0x160);
        puVar7[7] = *(undefined4 *)(iVar10 + 0x164);
        puVar7[8] = *(undefined4 *)(iVar10 + 0x168);
        puVar7[9] = *(undefined4 *)(iVar10 + 0x16c);
        puVar7[10] = *param_3;
        puVar7[0xb] = param_3[1];
        *(undefined1 *)(puVar7 + 0xc) = *(undefined1 *)(param_3 + 2);
        *(undefined1 *)(puVar7 + 0xe) = 1;
        puVar9 = operator_new(0x18);
        iVar10 = 0;
        if (puVar9 == (undefined4 *)0x0) {
          puVar9 = (undefined4 *)0x0;
        }
        else {
          puVar9[2] = 0;
        }
        *puVar9 = 0xffffffff;
        puVar9[1] = 0;
        param_2 = puVar9;
        param_3 = operator_new(0x18);
        uStack_4 = 1;
        if (param_3 != (void *)0x0) {
          iVar10 = FUN_00424ce0(0,0);
        }
        piVar2 = (int *)puVar9[2];
        uStack_4 = 0xffffffff;
        if (piVar2 != (int *)0x0) {
          piVar1 = piVar2 + 2;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar2 + 8))();
          }
        }
        puVar9[2] = iVar10;
        if (iVar10 != 0) {
          *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + 1;
        }
        iVar10 = puVar9[2];
        if (*(char *)(iVar10 + 0x14) != '\0') {
          *(undefined1 *)(iVar10 + 0x14) = 0;
          free(*(void **)(iVar10 + 0xc));
        }
        *(undefined4 **)(iVar10 + 0xc) = puVar7;
        *(undefined4 *)(iVar10 + 0x10) = 0x40;
        *(undefined1 *)(iVar10 + 0x14) = 1;
        puVar9[3] = *(undefined4 *)(puVar9[2] + 0xc);
        puVar9[4] = 0x40;
        FUN_005b2d70(&param_2);
        FUN_005a0b30(param_1,param_1 + 0x40);
        ExceptionList = pvStack_c;
        return;
      }
      puVar7 = malloc(0x30);
      *puVar7 = 0x203e;
      puVar7[2] = *param_3;
      puVar7[3] = param_3[1];
      puVar7[4] = param_3[2];
      puVar7[5] = param_3[3];
      iVar6 = *(int *)(param_1 + 0x50);
      puVar7[6] = *(undefined4 *)(iVar6 + 0x160);
      puVar7[7] = *(undefined4 *)(iVar6 + 0x164);
      puVar7[8] = *(undefined4 *)(iVar6 + 0x168);
      puVar7[9] = *(undefined4 *)(iVar6 + 0x16c);
      *(undefined1 *)((int)puVar7 + 0x2a) = 2;
      *(undefined1 *)(puVar7 + 10) = 0;
      *(undefined1 *)((int)puVar7 + 0x29) = 0;
      puVar9 = operator_new(0x18);
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        puVar9[2] = 0;
      }
      *puVar9 = 0xffffffff;
      puVar9[1] = 0;
      param_3 = puVar9;
      param_2 = operator_new(0x18);
      uStack_4 = 2;
      if (param_2 != (void *)0x0) {
        iVar10 = FUN_00424ce0(0,0);
      }
      piVar2 = (int *)puVar9[2];
      uStack_4 = 0xffffffff;
      if (piVar2 != (int *)0x0) {
        piVar1 = piVar2 + 2;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar2 + 8))();
        }
      }
      puVar9[2] = iVar10;
      if (iVar10 != 0) {
        *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + 1;
      }
      iVar10 = puVar9[2];
      if (*(char *)(iVar10 + 0x14) != '\0') {
        *(undefined1 *)(iVar10 + 0x14) = 0;
        free(*(void **)(iVar10 + 0xc));
      }
      *(undefined4 **)(iVar10 + 0xc) = puVar7;
      *(undefined4 *)(iVar10 + 0x10) = 0x30;
      *(undefined1 *)(iVar10 + 0x14) = 1;
      puVar9[3] = *(undefined4 *)(puVar9[2] + 0xc);
      puVar9[4] = 0x30;
      FUN_005b2d70(&param_3);
      FUN_005a0b30(param_1,param_1 + 0x40);
      ExceptionList = pvStack_c;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(param_2);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
