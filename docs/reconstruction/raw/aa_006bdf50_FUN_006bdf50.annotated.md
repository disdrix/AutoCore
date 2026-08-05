# Annotated low-level: FUN_006bdf50

| Field | Value |
|---|---|
| Stable ID | `aa_006bdf50` |
| VA | `0x006bdf50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bdf50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006bdf50(int param_1,undefined2 *param_2,int *param_3,int param_4)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  uint uVar14;
  int iVar15;
  undefined2 uVar16;
  int iVar17;
  undefined1 auStackY_100 [152];
  undefined4 local_48;
  undefined2 local_40;
  int local_38;
  int local_28 [2];
  int local_20;
  int local_1c;
  int local_18;
  int local_14 [2];
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar10 = param_4;
  iVar7 = param_1;
  *(undefined4 *)(param_4 + 8) = 0;
  FUN_006bdc00(*(undefined4 *)(param_1 + 8));
  FUN_006bdb00(param_1,1,param_4,local_14);
  FUN_006bdc00(*(undefined4 *)((int)param_2 + 8));
  FUN_006bdb00(param_2,auStackY_100,param_4,local_28);
  iVar11 = param_3[1] * 3 + *(int *)(param_4 + 8);
  piVar1 = (int *)(param_4 + 4);
  if ((int)(*(uint *)(param_4 + 0xc) & 0x7fffffff) < iVar11) {
    FUN_005b3300(piVar1,iVar11,8);
  }
  param_1 = 0;
  if (0 < param_3[1]) {
    param_4 = 0;
    do {
      piVar12 = (int *)(*param_3 + param_4);
      puVar6 = (undefined2 *)*piVar12;
      *(undefined2 *)(piVar12 + 2) = *puVar6;
      *(undefined2 *)(piVar12 + 3) =
           *(undefined2 *)(*(int *)(iVar7 + 4) + (uint)(ushort)puVar6[2] * 8);
      *(undefined2 *)((int)piVar12 + 0xe) = *(undefined2 *)piVar12[1];
      uVar4 = ((undefined2 *)piVar12[1])[1];
      uVar14 = (uint)*(ushort *)(local_14[0] + ((int)puVar6 - *(int *)(iVar7 + 4) >> 3) * 2);
      if (uVar14 == 0xffff) {
        iVar11 = 0;
      }
      else {
        iVar11 = *piVar1 + uVar14 * 8;
      }
      *piVar12 = iVar11;
      uVar14 = (uint)*(ushort *)(local_28[0] + ((int)((uint)uVar4 << 3) >> 3) * 2);
      if (uVar14 == 0xffff) {
        iVar11 = 0;
      }
      else {
        iVar11 = *piVar1 + uVar14 * 8;
      }
      piVar12[1] = iVar11;
      param_4 = param_4 + 0x10;
      param_1 = param_1 + 1;
    } while (param_1 < param_3[1]);
  }
  iVar7 = *piVar1;
  iVar11 = *(int *)(iVar10 + 8);
  param_2 = (undefined2 *)0x0;
  local_38 = param_3[1];
  local_48 = 0xffff;
  local_48._0_2_ = 0xffff;
  uVar16 = (undefined2)local_48;
  if (-1 < local_38 + -1) {
    iVar15 = (local_38 + -1) * 0x10;
    piVar12 = (int *)*param_3;
    do {
      piVar13 = (int *)(*param_3 + iVar15);
      uVar8 = *(undefined4 *)(iVar10 + 8);
      iVar17 = *(int *)(iVar10 + 8);
      *(int *)(iVar10 + 8) = iVar17 + 1;
      puVar6 = (undefined2 *)(*piVar1 + iVar17 * 8);
      uVar9 = *(undefined4 *)(iVar10 + 8);
      iVar17 = *(int *)(iVar10 + 8);
      *(int *)(iVar10 + 8) = iVar17 + 1;
      puVar3 = (undefined2 *)(*piVar1 + iVar17 * 8);
      iVar17 = *piVar13;
      local_40 = (undefined2)uVar9;
      param_1._0_2_ = (undefined2)uVar8;
      if (iVar17 == *piVar12) {
        iVar17 = piVar13[1];
        if (*(short *)(iVar17 + 6) == 2) {
          uVar5 = *(undefined2 *)(iVar17 + 2);
          uVar14 = (uint)*(ushort *)(iVar17 + 2);
          iVar17 = iVar7;
        }
        else {
          uVar5 = (undefined2)*(undefined4 *)(iVar10 + 8);
          uVar14 = *(uint *)(iVar10 + 8);
          *(uint *)(iVar10 + 8) = uVar14 + 1;
          iVar17 = *piVar1;
        }
        puVar2 = (undefined2 *)(iVar17 + uVar14 * 8);
        *puVar6 = *(undefined2 *)piVar13[1];
        puVar6[2] = local_40;
        puVar6[1] = (undefined2)local_48;
        if (param_2 != (undefined2 *)0x0) {
          param_2[1] = (undefined2)param_1;
        }
        *puVar2 = *(undefined2 *)((int)piVar13 + 0xe);
        puVar2[2] = (undefined2)param_1;
        puVar2[1] = (short)(piVar13[1] - iVar7 >> 3);
        *(undefined2 *)(piVar13[1] + 2) = uVar5;
        uVar16 = (undefined2)piVar13[2];
        param_1._0_2_ = uVar5;
      }
      else {
        if (*(short *)(iVar17 + 6) == 2) {
          uVar16 = *(undefined2 *)(iVar17 + 2);
          uVar14 = (uint)*(ushort *)(iVar17 + 2);
          iVar17 = iVar7;
        }
        else {
          uVar16 = (undefined2)*(undefined4 *)(iVar10 + 8);
          uVar14 = *(uint *)(iVar10 + 8);
          *(uint *)(iVar10 + 8) = uVar14 + 1;
          iVar17 = *piVar1;
        }
        puVar2 = (undefined2 *)(iVar17 + uVar14 * 8);
        *puVar6 = *(undefined2 *)((int)piVar13 + 0xe);
        puVar6[2] = uVar16;
        puVar6[1] = (undefined2)local_48;
        if (param_2 != (undefined2 *)0x0) {
          param_2[1] = (undefined2)param_1;
        }
        *puVar2 = (short)piVar13[3];
        puVar2[2] = local_40;
        puVar2[1] = (short)(*piVar13 - iVar7 >> 3);
        *(undefined2 *)(*piVar13 + 2) = uVar16;
        uVar16 = *(undefined2 *)*piVar13;
      }
      *puVar3 = uVar16;
      puVar3[2] = (undefined2)param_1;
      iVar15 = iVar15 + -0x10;
      local_38 = local_38 + -1;
      piVar12 = piVar13;
      param_2 = puVar3;
      local_48 = uVar9;
      uVar16 = local_40;
    } while (local_38 != 0);
  }
  local_48._0_2_ = uVar16;
  param_2[1] = (short)iVar11;
  *(undefined2 *)(iVar7 + 2 + iVar11 * 8) = (undefined2)local_48;
  piVar1 = DAT_00b05060;
  uVar14 = local_18 * 2 + 0xfU & 0xfffffff0;
  if ((uVar14 == 0) || ((local_1c != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {
    piVar12 = DAT_00b05060 + 3;
    DAT_00b05060[2] = DAT_00b05060[2] - uVar14;
    piVar1[3] = *piVar12 + uVar14;
  }
  else {
    (**(code **)(*DAT_00b05060 + 0x28))(local_1c,uVar14);
  }
  if (-1 < local_20) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_28[0],local_20 << 1,0x12);
  }
  piVar1 = DAT_00b05060;
  uVar14 = iStack_4 * 2 + 0xfU & 0xfffffff0;
  if ((uVar14 == 0) || ((iStack_8 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {
    piVar12 = DAT_00b05060 + 3;
    DAT_00b05060[2] = DAT_00b05060[2] - uVar14;
    piVar1[3] = *piVar12 + uVar14;
  }
  else {
    (**(code **)(*DAT_00b05060 + 0x28))(iStack_8,uVar14);
  }
  if (-1 < iStack_c) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_14[0],iStack_c << 1,0x12);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
