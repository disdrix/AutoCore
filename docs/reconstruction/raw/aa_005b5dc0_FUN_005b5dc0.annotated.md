# Annotated low-level: FUN_005b5dc0

| Field | Value |
|---|---|
| Stable ID | `aa_005b5dc0` |
| VA | `0x005b5dc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005b5dc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005b5dc0(int param_1,uint param_2)

{
  int *piVar1;
  uint *puVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  int *piVar13;
  void *pvVar14;
  uint uVar15;
  int *piVar16;
  void *local_30;
  undefined1 auStack_2c [12];
  void *pvStack_20;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar14 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a698c;
  local_c = ExceptionList;
  iVar4 = *(int *)(param_1 + 0x50);
  uVar3 = *(ushort *)(iVar4 + 0x10);
  ExceptionList = &local_c;
  *(uint *)(param_1 + 0x58) = (uint)uVar3;
  if (uVar3 < 2) {
    ExceptionList = pvVar14;
    return;
  }
  local_30 = operator_new(0xdc);
  local_4 = 0;
  if (local_30 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_005b4bc0();
  }
  *(undefined4 *)(param_1 + 0xc) = uVar5;
  local_4 = 0xffffffff;
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0xc))();
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 100) = uVar5;
  iVar9 = **(int **)(param_1 + 0xc);
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 100))();
  (**(code **)(iVar9 + 0x34))(uVar5);
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xac) = 5;
  FUN_0096f530();
  local_4 = 1;
  FUN_00989e00(&local_30,"NDTree.fx");
  FUN_009701d0(&local_30);
  FUN_00970140("DiffuseTexture",**(undefined4 **)(param_1 + 0x170));
  if (DAT_00b05348 != (undefined4 *)0x0) {
    FUN_00970140("DarkTexture",*DAT_00b05348);
  }
  FUN_004148e0(auStack_2c);
  iVar9 = *(int *)(param_1 + 0xc);
  *(uint *)(iVar9 + 0xbc) = *(uint *)(iVar9 + 0xbc) | 1;
  pvVar14 = (void *)(*(int *)(param_1 + 0xc) + 8);
  local_30 = pvVar14;
  uVar6 = FUN_00687210();
  uVar6 = uVar6 & 0xffff;
  if ((char)param_2 == '\0') {
    pvVar7 = operator_new__(uVar6 * 2);
    uVar11 = 0;
    *(void **)(param_1 + 0x60) = pvVar7;
    if (uVar6 != 0) {
      uVar15 = 0;
      do {
        FUN_0068a4d0(*(undefined4 *)(param_1 + 0x50),1,uVar11,0xffffffff,0xffffffff);
        if (*(short *)(iVar4 + 4) == 0) {
          *(undefined2 *)(*(int *)(param_1 + 0x60) + uVar15 * 2) = 0;
        }
        else {
          *(undefined2 *)(*(int *)(param_1 + 0x60) + uVar15 * 2) = **(undefined2 **)(iVar4 + 8);
        }
        uVar11 = uVar11 + 1;
        uVar15 = uVar11 & 0xffff;
        pvVar14 = local_30;
      } while (uVar15 < uVar6);
    }
  }
  if (*(int *)(*(int *)(param_1 + 0x174) + 0x128) == 0) {
    if (*(char *)(*(int *)(param_1 + 4) + 0x7d) == '\0') {
      uVar11 = 2;
      uVar6 = 2;
      param_2 = 2;
    }
    else {
      uVar11 = 0;
      param_2 = 0;
      uVar6 = 0;
    }
    uVar5 = FUN_00414bc0(DAT_00af3ef4);
    local_4._0_1_ = 2;
    iVar8 = FUN_00414c20(*(undefined4 *)(param_1 + 0x58),uVar5,uVar11 | 0x20,0);
    local_4 = CONCAT31(local_4._1_3_,1);
    uStack_14 = 0;
    uStack_10 = 0;
    if (pvStack_20 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvStack_20);
    }
    if (iVar8 < 0) goto LAB_005b62ef;
    iVar8 = *(int *)(iVar9 + 0x14);
    if (*(int *)(iVar8 + 0x10) == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_00746520(*(undefined4 *)(iVar8 + 0x14),*(undefined4 *)(iVar8 + 0x18),0);
    }
    if (iVar8 == 0) {
      if (*(int *)(*(int *)(iVar9 + 0x14) + 0x10) != 0) {
        FUN_007464e0();
      }
      if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(param_1 + 0xc))(1);
      }
      *(undefined4 *)(param_1 + 0xc) = 0;
      goto LAB_005b62ef;
    }
    FUN_0074b510();
    uVar11 = 0;
    if (*(int *)(param_1 + 0x58) != 0) {
      puVar12 = (undefined4 *)(iVar8 + 0x18);
      iVar8 = 0;
      do {
        puVar10 = (undefined4 *)(*(int *)(iVar4 + 0x24) + iVar8);
        puVar12[-6] = *puVar10;
        puVar12[-5] = puVar10[1];
        puVar12[-4] = puVar10[2];
        FUN_0074ba50(*(int *)(iVar4 + 0x24) + iVar8,0xc,1);
        puVar10 = (undefined4 *)(*(int *)(iVar4 + 0x18) + iVar8);
        puVar12[-3] = *puVar10;
        puVar12[-2] = puVar10[1];
        puVar12[-1] = puVar10[2];
        *puVar12 = *(undefined4 *)(*(int *)(iVar4 + 0x28) + uVar11 * 8);
        puVar12[1] = *(undefined4 *)(*(int *)(iVar4 + 0x28) + 4 + uVar11 * 8);
        puVar12[2] = (float)*(byte *)(*(int *)(iVar4 + 0x34) + uVar11);
        puVar12[3] = *(undefined4 *)(*(int *)(iVar4 + 0x30) + uVar11 * 4);
        uVar11 = uVar11 + 1;
        puVar12 = puVar12 + 10;
        iVar8 = iVar8 + 0xc;
        uVar6 = param_2;
      } while (uVar11 < *(uint *)(param_1 + 0x58));
    }
    if (*(int *)(*(int *)(iVar9 + 0x14) + 0x10) != 0) {
      FUN_007464e0();
    }
    FUN_0068a4d0(*(undefined4 *)(param_1 + 0x50),1,0,0xffffffff,0xffffffff);
    pvVar14 = local_30;
    iVar8 = FUN_0044b9c0(**(undefined2 **)(param_1 + 0x60),uVar6 | 0x20,0,0);
    if (iVar8 < 0) goto LAB_005b62ef;
    iVar8 = *(int *)((int)pvVar14 + 4);
    if ((*(int *)(iVar8 + 0x10) != 0) &&
       (puVar12 = (undefined4 *)
                  FUN_00743be0(*(undefined4 *)(iVar8 + 0x18),*(undefined4 *)(iVar8 + 0x1c),0x800),
       puVar12 != (undefined4 *)0x0)) {
      uVar6 = (uint)**(ushort **)(iVar4 + 8) * 2;
      puVar10 = (undefined4 *)**(undefined4 **)(iVar4 + 0xc);
      for (uVar11 = uVar6 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
    }
    if (*(int *)(*(int *)((int)pvVar14 + 4) + 0x10) != 0) {
      FUN_00743ba0();
    }
    *(undefined4 *)(*(int *)(param_1 + 0x174) + 0x104) = *(undefined4 *)(iVar9 + 0x14);
    *(undefined4 *)(*(int *)(param_1 + 0x174) + 0x108) = *(undefined4 *)((int)pvVar14 + 4);
    puVar2 = (uint *)(*(int *)(param_1 + 0xc) + 0xbc);
    *puVar2 = *puVar2 & 0xfffffffe;
    piVar16 = *(int **)(param_1 + 0xc);
    if ((*(byte *)(piVar16 + 0x2f) & 1) != 0) {
      (**(code **)(*piVar16 + 0x5c))();
    }
    piVar13 = (int *)(*(int *)(param_1 + 0x174) + 0x130);
    piVar16 = piVar16 + 10;
    for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
      *piVar16 = *piVar13;
      piVar13 = piVar13 + 1;
      piVar16 = piVar16 + 1;
    }
  }
  else {
    piVar16 = *(int **)(*(int *)(param_1 + 0x174) + 0x104);
    if ((piVar16 != (int *)0x0) && (piVar16[1] = piVar16[1] + 1, piVar16[1] == 1)) {
      (**(code **)(*piVar16 + 4))();
    }
    piVar13 = *(int **)(iVar9 + 0x14);
    if (piVar13 != (int *)0x0) {
      piVar1 = piVar13 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar13 + 8))();
      }
    }
    *(int **)(iVar9 + 0x14) = piVar16;
    piVar16 = *(int **)(*(int *)(param_1 + 0x174) + 0x108);
    if ((piVar16 != (int *)0x0) && (piVar16[1] = piVar16[1] + 1, piVar16[1] == 1)) {
      (**(code **)(*piVar16 + 4))();
    }
    piVar13 = *(int **)((int)pvVar14 + 4);
    if (piVar13 != (int *)0x0) {
      piVar1 = piVar13 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar13 + 8))();
      }
    }
    *(int **)((int)pvVar14 + 4) = piVar16;
    puVar2 = (uint *)(*(int *)(param_1 + 0xc) + 0xbc);
    *puVar2 = *puVar2 & 0xfffffffe;
    piVar16 = *(int **)(param_1 + 0xc);
    if ((*(byte *)(piVar16 + 0x2f) & 1) != 0) {
      (**(code **)(*piVar16 + 0x5c))();
    }
    piVar13 = (int *)(*(int *)(param_1 + 0x174) + 0x130);
    piVar16 = piVar16 + 10;
    for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
      *piVar16 = *piVar13;
      piVar13 = piVar13 + 1;
      piVar16 = piVar16 + 1;
    }
    FUN_0068a4d0(*(undefined4 *)(param_1 + 0x50),1,0,0xffffffff,0xffffffff);
  }
  *(uint *)(*(int *)(param_1 + 0xc) + 0xa8) = **(ushort **)(iVar4 + 8) - 2;
  FUN_0096f740();
  FUN_007647c0(*(undefined4 *)(param_1 + 0xc));
  if (*(int *)(*(int *)(param_1 + 0xc) + 0x20) == 0) {
    param_2 = 0xffffffff;
    puVar12 = &param_2;
  }
  else {
    puVar12 = (undefined4 *)FUN_00752370(&param_2,"WindMatrices");
  }
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xd0) = *puVar12;
LAB_005b62ef:
  local_4 = 0xffffffff;
  FUN_0096f510();
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
