# Annotated low-level: FUN_006cec90

| Field | Value |
|---|---|
| Stable ID | `aa_006cec90` |
| VA | `0x006cec90` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006cec90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_006cec90(int *param_1,int *param_2,byte *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  undefined4 auStack_1a4 [4];
  uint auStack_194 [4];
  uint auStack_184 [78];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int *piStack_44;
  byte *pbStack_40;
  int local_28 [4];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  bVar1 = *param_3;
  while (pbStack_40 = (byte *)(uint)bVar1, pbStack_40 < 0x6c) {
    piStack_44 = param_2;
    switch(pbStack_40) {
    case (byte *)0x0:
      return;
    case (byte *)0x1:
    case (byte *)0x2:
    case (byte *)0x3:
    case (byte *)0x4:
      local_8 = param_2[8] - (int)pbStack_40;
      local_18 = (uint)param_3[1] + param_2[4] << (bVar1 & 0x1f);
      bVar5 = (byte)(param_2[8] - (int)pbStack_40);
      local_28[0] = (param_1[4] >> (bVar5 & 0x1f)) - local_18;
      local_14 = (uint)param_3[2] + param_2[5] << (bVar1 & 0x1f);
      local_28[1] = (param_1[5] >> (bVar5 & 0x1f)) - local_14;
      local_10 = (uint)param_3[3] + param_2[6] << (bVar1 & 0x1f);
      local_28[2] = (param_1[6] >> (bVar5 & 0x1f)) - local_10;
      local_28[3] = (param_1[7] >> (bVar5 & 0x1f)) + 1;
      local_c = param_2[7];
      local_4 = param_2[9];
      param_2 = local_28;
      pbVar8 = param_3 + 4;
      break;
    case (byte *)0x5:
      pbVar8 = param_3 + param_3[1] + 2;
      break;
    case (byte *)0x6:
      pbVar8 = param_3 + (uint)param_3[1] * 0x100 + param_3[2] + 3;
      break;
    case (byte *)0x7:
      pbVar8 = param_3 + (uint)CONCAT11(param_3[1],param_3[2]) * 0x100 + param_3[3] + 4;
      break;
    case (byte *)0x8:
    case (byte *)0xc:
    case (byte *)0xd:
    case (byte *)0xe:
    case (byte *)0xf:
    case (byte *)0x1d:
    case (byte *)0x1e:
    case (byte *)0x1f:
    case (byte *)0x2c:
    case (byte *)0x2d:
    case (byte *)0x2e:
    case (byte *)0x2f:
    case (byte *)0x54:
    case (byte *)0x55:
    case (byte *)0x56:
    case (byte *)0x57:
    case (byte *)0x58:
    case (byte *)0x59:
    case (byte *)0x5a:
    case (byte *)0x5b:
    case (byte *)0x5c:
    case (byte *)0x5d:
    case (byte *)0x5e:
    case (byte *)0x5f:
      goto switchD_006cecb8_caseD_8;
    case (byte *)0x9:
      bVar1 = param_3[1];
      if (param_2 != local_28) {
        piVar9 = local_28;
        for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar9 = *param_2;
          param_2 = param_2 + 1;
          piVar9 = piVar9 + 1;
        }
        param_2 = local_28;
      }
      local_c = local_c + (uint)bVar1;
      pbVar8 = param_3 + 2;
      break;
    case (byte *)0xa:
      bVar1 = param_3[1];
      bVar5 = param_3[2];
      if (param_2 != local_28) {
        piVar9 = local_28;
        for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar9 = *param_2;
          param_2 = param_2 + 1;
          piVar9 = piVar9 + 1;
        }
        param_2 = local_28;
      }
      local_c = local_c + (uint)CONCAT11(bVar1,bVar5);
      pbVar8 = param_3 + 3;
      break;
    case (byte *)0xb:
      bVar1 = param_3[1];
      bVar5 = param_3[2];
      bVar2 = param_3[3];
      bVar3 = param_3[4];
      if (param_2 != local_28) {
        piVar9 = local_28;
        for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar9 = *param_2;
          param_2 = param_2 + 1;
          piVar9 = piVar9 + 1;
        }
        param_2 = local_28;
      }
      local_c = CONCAT31(CONCAT21(CONCAT11(bVar1,bVar5),bVar2),bVar3);
      pbVar8 = param_3 + 5;
      break;
    case (byte *)0x10:
    case (byte *)0x11:
    case (byte *)0x12:
      uVar4 = (uint)param_3[1];
      uVar6 = (uint)param_3[2];
      iVar7 = param_2[(int)pbStack_40 - 0x10];
      iVar10 = param_2[3];
      goto LAB_006cedcd;
    case (byte *)0x13:
      iVar7 = param_2[2] + param_2[1];
      uVar4 = (uint)param_3[1] << 1;
      uVar6 = (uint)param_3[2] << 1;
      iVar10 = param_2[3] + 1 + (param_2[3] >> 1);
      goto LAB_006cedcd;
    case (byte *)0x14:
      iVar7 = param_2[1];
      goto LAB_006cece6;
    case (byte *)0x15:
      iVar7 = param_2[2] + *param_2;
      uVar4 = (uint)param_3[1] << 1;
      uVar6 = (uint)param_3[2] << 1;
      iVar10 = param_2[3] + 1 + (param_2[3] >> 1);
      goto LAB_006cedcd;
    case (byte *)0x16:
      iVar7 = *param_2;
LAB_006cece6:
      iVar10 = param_2[2];
LAB_006cece9:
      uVar4 = (uint)param_3[1] << 1;
      uVar6 = (uint)param_3[2] << 1;
      iVar7 = (iVar7 - iVar10) + 0xff;
      iVar10 = param_2[3] + 1 + (param_2[3] >> 1);
      goto LAB_006cedcd;
    case (byte *)0x17:
      iVar7 = param_2[1] + *param_2;
      uVar4 = (uint)param_3[1] << 1;
      uVar6 = (uint)param_3[2] << 1;
      iVar10 = param_2[3] + 1 + (param_2[3] >> 1);
      goto LAB_006cedcd;
    case (byte *)0x18:
      iVar7 = *param_2;
      iVar10 = param_2[1];
      goto LAB_006cece9;
    case (byte *)0x19:
      iVar7 = param_2[2] + param_2[1] + *param_2;
      uVar4 = (uint)param_3[1] * 3;
      uVar6 = (uint)param_3[2] * 3;
      iVar10 = param_2[3] << 2;
      goto LAB_006cedcd;
    case (byte *)0x1a:
      iVar7 = param_2[1];
      iVar10 = param_2[2];
      goto LAB_006ced82;
    case (byte *)0x1b:
      iVar7 = param_2[2];
      iVar10 = param_2[1];
LAB_006ced82:
      iVar7 = (iVar7 - iVar10) + 0xff + *param_2;
LAB_006ced8d:
      uVar4 = (uint)param_3[1] * 3;
      uVar6 = (uint)param_3[2] * 3;
      iVar10 = param_2[3] << 2;
LAB_006cedcd:
      pbVar8 = param_3 + 4;
      if ((int)uVar6 <= iVar10 + iVar7) {
        pbVar8 = pbVar8 + param_3[3];
        if (iVar7 <= (int)(iVar10 + uVar4)) {
          pbStack_40 = (byte *)((int)pbVar8 - (uint)param_3[3]);
          uStack_48 = 0x6cedfc;
          FUN_006cec90();
        }
      }
      break;
    case (byte *)0x1c:
      iVar7 = ((*param_2 - param_2[2]) - param_2[1]) + 0x1fe;
      goto LAB_006ced8d;
    case (byte *)0x20:
    case (byte *)0x21:
    case (byte *)0x22:
      pbVar8 = param_3 + 3;
      if ((int)(uint)param_3[1] <= param_2[3] + param_2[(int)pbStack_40 - 0x20]) {
        pbVar8 = pbVar8 + param_3[2];
        if (param_2[(int)pbStack_40 - 0x20] <= (int)(param_2[3] + 1 + (uint)param_3[1])) {
          pbStack_40 = (byte *)((int)pbVar8 - (uint)param_3[2]);
          uStack_48 = 0x6cee39;
          FUN_006cec90();
        }
      }
      break;
    case (byte *)0x23:
    case (byte *)0x24:
    case (byte *)0x25:
      if (param_2[(int)pbStack_40 - 0x23] + param_2[3] < (int)(uint)param_3[2]) {
        pbVar8 = param_3 + CONCAT11(param_3[3],param_3[4]) + 7;
      }
      else {
        pbVar8 = param_3 + CONCAT11(param_3[5],param_3[6]) + 7;
        if (param_2[(int)pbStack_40 - 0x23] <= (int)(param_2[3] + (uint)param_3[1])) {
          pbStack_40 = pbVar8 + ((uint)CONCAT11(param_3[3],param_3[4]) -
                                (uint)CONCAT11(param_3[5],param_3[6]));
          uStack_48 = 0x6ceea7;
          FUN_006cec90();
        }
      }
      break;
    case (byte *)0x26:
    case (byte *)0x27:
    case (byte *)0x28:
      if (param_2[3] + param_2[(int)pbStack_40 - 0x26] < (int)(uint)param_3[1]) {
        return;
      }
      if ((int)((uint)param_3[2] + param_2[3]) < param_2[(int)pbStack_40 - 0x26]) {
        return;
      }
      pbVar8 = param_3 + 3;
      break;
    case (byte *)0x29:
    case (byte *)0x2a:
    case (byte *)0x2b:
      if (param_1[7] + param_1[(int)pbStack_40 - 0x25] <
          (int)(uint)CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3])) {
        return;
      }
      if ((int)((uint)param_3[6] + (uint)CONCAT11(param_3[4],param_3[5]) * 0x100 + param_1[7]) <
          param_1[(int)pbStack_40 - 0x25]) {
        return;
      }
      pbVar8 = param_3 + 7;
      break;
    default:
      uVar4 = (int)pbStack_40 - 0x30;
      goto LAB_006cf1a1;
    case (byte *)0x50:
      uVar4 = (uint)param_3[1];
      goto LAB_006cf1a1;
    case (byte *)0x51:
      uVar4 = (uint)CONCAT11(param_3[1],param_3[2]);
      goto LAB_006cf1a1;
    case (byte *)0x52:
      uVar4 = (uint)CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]);
      goto LAB_006cf1a1;
    case (byte *)0x53:
      uVar4 = CONCAT31(CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]),param_3[4]);
LAB_006cf1a1:
      iVar7 = param_2[7];
      param_1 = (int *)*param_1;
      if (param_1[1] == (param_1[2] & 0x7fffffffU)) {
        pbStack_40 = (byte *)0x4;
        uStack_48 = 0x6cf1c0;
        piStack_44 = param_1;
        FUN_005b3370();
      }
      *(uint *)(*param_1 + param_1[1] * 4) = iVar7 + uVar4;
      param_1[1] = param_1[1] + 1;
      return;
    case (byte *)0x60:
    case (byte *)0x61:
    case (byte *)0x62:
    case (byte *)0x63:
      pbVar8 = param_3 + 2;
      auStack_184[(int)pbStack_40] = (uint)param_3[1];
      goto LAB_006cf0e3;
    case (byte *)0x64:
    case (byte *)0x65:
    case (byte *)0x66:
    case (byte *)0x67:
      auStack_194[(int)pbStack_40] = (uint)CONCAT11(param_3[1],param_3[2]);
      pbVar8 = param_3 + 3;
      goto LAB_006cf0e3;
    case (byte *)0x68:
    case (byte *)0x69:
    case (byte *)0x6a:
    case (byte *)0x6b:
      auStack_1a4[(int)pbStack_40] =
           CONCAT31(CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]),param_3[4]);
      pbVar8 = param_3 + 5;
LAB_006cf0e3:
      if (param_2 != local_28) {
        piVar9 = param_2;
        piVar11 = local_28;
        for (iVar7 = 10; param_2 = local_28, iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar11 = *piVar9;
          piVar9 = piVar9 + 1;
          piVar11 = piVar11 + 1;
        }
      }
    }
    param_3 = pbVar8;
    bVar1 = *pbVar8;
  }
switchD_006cecb8_caseD_8:
  piStack_44 = (int *)0xa0e298;
  uStack_48 = 0x6cf121;
  uStack_48 = (**(code **)(*DAT_00d030e0 + 4))();
  uStack_4c = 0x6cf127;
  FUN_00631f10();
  pbStack_40 = (byte *)0x6cf135;
  (**(code **)(*DAT_00d030e0 + 4))();
  pbStack_40 = (byte *)0x6cf13c;
  FUN_00631f70();
  _DAT_00000000 = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
