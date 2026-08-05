# Raw capture: FUN_006cf3b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cf3b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006cf3b0` |
| **Canonical name** | `FUN_006cf3b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_006cf3b0(int *param_1,int *param_2,byte *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  undefined4 auStack_1a4 [4];
  uint auStack_194 [4];
  uint auStack_184 [75];
  undefined4 uStack_58;
  undefined4 uStack_54;
  int *piStack_50;
  byte *pbStack_4c;
  int local_38 [4];
  int local_28;
  int local_24;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  bVar5 = *param_3;
  while (pbStack_4c = (byte *)(uint)bVar5, pbStack_4c < 0x6c) {
    piStack_50 = param_2;
    switch(pbStack_4c) {
    case (byte *)0x0:
      return;
    case (byte *)0x1:
    case (byte *)0x2:
    case (byte *)0x3:
    case (byte *)0x4:
      local_18 = (uint)param_3[1] + param_2[8] << (bVar5 & 0x1f);
      local_14 = (uint)param_3[2] + param_2[9] << (bVar5 & 0x1f);
      local_10 = (uint)param_3[3] + param_2[10] << (bVar5 & 0x1f);
      local_8 = param_2[0xc] + (int)pbStack_4c;
      bVar5 = 0x10 - (char)(param_2[0xc] + (int)pbStack_4c);
      local_28 = (param_1[8] >> (bVar5 & 0x1f)) - local_18;
      local_24 = (param_1[9] >> (bVar5 & 0x1f)) - local_14;
      local_20 = (param_1[10] >> (bVar5 & 0x1f)) - local_10;
      local_38[0] = ((param_1[4] >> (bVar5 & 0x1f)) + 1) - local_18;
      local_38[1] = ((param_1[5] >> (bVar5 & 0x1f)) + 1) - local_14;
      local_38[2] = ((param_1[6] >> (bVar5 & 0x1f)) + 1) - local_10;
      local_4 = param_2[0xd];
      local_c = param_2[0xb];
      param_2 = local_38;
      pbVar9 = param_3 + 4;
      break;
    case (byte *)0x5:
      pbVar9 = param_3 + param_3[1] + 2;
      break;
    case (byte *)0x6:
      pbVar9 = param_3 + (uint)param_3[1] * 0x100 + param_3[2] + 3;
      break;
    case (byte *)0x7:
      pbVar9 = param_3 + (uint)CONCAT11(param_3[1],param_3[2]) * 0x100 + param_3[3] + 4;
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
      goto switchD_006cf3d7_caseD_8;
    case (byte *)0x9:
      bVar5 = param_3[1];
      if (param_2 != local_38) {
        piVar10 = param_2;
        piVar12 = local_38;
        for (iVar7 = 0xe; param_2 = local_38, iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar12 = *piVar10;
          piVar10 = piVar10 + 1;
          piVar12 = piVar12 + 1;
        }
      }
      local_c = local_c + (uint)bVar5;
      pbVar9 = param_3 + 2;
      break;
    case (byte *)0xa:
      bVar5 = param_3[1];
      bVar1 = param_3[2];
      if (param_2 != local_38) {
        piVar10 = param_2;
        piVar12 = local_38;
        for (iVar7 = 0xe; param_2 = local_38, iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar12 = *piVar10;
          piVar10 = piVar10 + 1;
          piVar12 = piVar12 + 1;
        }
      }
      local_c = local_c + (uint)CONCAT11(bVar5,bVar1);
      pbVar9 = param_3 + 3;
      break;
    case (byte *)0xb:
      bVar5 = param_3[1];
      bVar1 = param_3[2];
      bVar2 = param_3[3];
      bVar3 = param_3[4];
      if (param_2 != local_38) {
        piVar10 = param_2;
        piVar12 = local_38;
        for (iVar7 = 0xe; param_2 = local_38, iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar12 = *piVar10;
          piVar10 = piVar10 + 1;
          piVar12 = piVar12 + 1;
        }
      }
      local_c = CONCAT31(CONCAT21(CONCAT11(bVar5,bVar1),bVar2),bVar3);
      pbVar9 = param_3 + 5;
      break;
    case (byte *)0x10:
    case (byte *)0x11:
    case (byte *)0x12:
      pbVar9 = param_3 + 4;
      if ((int)(uint)param_3[2] < param_2[(int)pbStack_4c - 0x10]) {
        pbVar9 = pbVar9 + param_3[3];
        if (param_2[(int)pbStack_4c - 0xc] < (int)(uint)param_3[1]) {
          pbStack_4c = (byte *)((int)pbVar9 - (uint)param_3[3]);
          uStack_54 = 0x6cf5c2;
          FUN_006cf3b0();
        }
      }
      else if ((int)(uint)param_3[1] <= param_2[(int)pbStack_4c - 0xc]) {
        return;
      }
      break;
    case (byte *)0x13:
      iVar4 = param_2[6] + param_2[5];
      iVar7 = (uint)param_3[1] << 1;
      iVar11 = (uint)param_3[2] << 1;
      iVar6 = param_2[2] + param_2[1];
      goto LAB_006cf552;
    case (byte *)0x14:
      iVar4 = param_2[5] - param_2[2];
      iVar6 = param_2[1] - param_2[6];
      iVar7 = (uint)param_3[1] * 2 + -0xff;
      iVar11 = (uint)param_3[2] * 2 + -0xff;
      goto LAB_006cf552;
    case (byte *)0x15:
      iVar4 = param_2[6] + param_2[4];
      iVar7 = (uint)param_3[1] << 1;
      iVar11 = (uint)param_3[2] << 1;
      iVar6 = param_2[2] + *param_2;
      goto LAB_006cf552;
    case (byte *)0x16:
      iVar4 = param_2[4] - param_2[2];
      iVar6 = *param_2 - param_2[6];
      iVar7 = (uint)param_3[1] * 2 + -0xff;
      iVar11 = (uint)param_3[2] * 2 + -0xff;
      goto LAB_006cf552;
    case (byte *)0x17:
      iVar4 = param_2[5] + param_2[4];
      iVar7 = (uint)param_3[1] << 1;
      iVar11 = (uint)param_3[2] << 1;
      iVar6 = param_2[1] + *param_2;
      goto LAB_006cf552;
    case (byte *)0x18:
      iVar4 = param_2[4] - param_2[1];
      iVar6 = *param_2;
      iVar7 = (uint)param_3[1] * 2 + -0xff;
      iVar11 = (uint)param_3[2] * 2 + -0xff;
      goto LAB_006cf54f;
    case (byte *)0x19:
      iVar7 = (uint)param_3[1] * 3;
      iVar11 = (uint)param_3[2] * 3;
      iVar4 = param_2[6] + param_2[5] + param_2[4];
      iVar6 = param_2[2] + param_2[1] + *param_2;
      goto LAB_006cf552;
    case (byte *)0x1a:
      iVar7 = (param_3[1] - 0x55) * 3;
      iVar11 = (param_3[2] - 0x55) * 3;
      iVar4 = (param_2[5] - param_2[2]) + param_2[4];
      iVar6 = (param_2[1] - param_2[6]) + *param_2;
      goto LAB_006cf552;
    case (byte *)0x1b:
      iVar7 = (param_3[1] - 0x55) * 3;
      iVar11 = (param_3[2] - 0x55) * 3;
      iVar4 = (param_2[6] - param_2[1]) + param_2[4];
      iVar6 = (param_2[2] - param_2[5]) + *param_2;
      goto LAB_006cf552;
    case (byte *)0x1c:
      iVar7 = (param_3[1] - 0xaa) * 3;
      iVar11 = (param_3[2] - 0xaa) * 3;
      iVar4 = (param_2[4] - param_2[2]) - param_2[1];
      iVar6 = *param_2 - param_2[6];
LAB_006cf54f:
      iVar6 = iVar6 - param_2[5];
LAB_006cf552:
      pbVar9 = param_3 + 4;
      if (iVar11 < iVar6) {
        bVar5 = param_3[3];
        if (iVar4 < iVar7) {
          uStack_54 = 0x6cf57e;
          pbStack_4c = pbVar9;
          FUN_006cf3b0();
          pbVar9 = pbVar9 + bVar5;
        }
        else {
          pbVar9 = pbVar9 + bVar5;
        }
      }
      else if (iVar7 <= iVar4) {
        return;
      }
      break;
    case (byte *)0x20:
    case (byte *)0x21:
    case (byte *)0x22:
      pbVar9 = param_3 + 3;
      if ((int)(uint)param_3[1] < param_2[(int)pbStack_4c - 0x20]) {
        pbVar9 = pbVar9 + param_3[2];
        if (param_2[(int)pbStack_4c - 0x1c] <= (int)(uint)param_3[1]) {
          pbStack_4c = (byte *)((int)pbVar9 - (uint)param_3[2]);
          uStack_54 = 0x6cf5f9;
          FUN_006cf3b0();
        }
      }
      break;
    case (byte *)0x23:
    case (byte *)0x24:
    case (byte *)0x25:
      if ((int)(uint)param_3[2] < param_2[(int)pbStack_4c - 0x23]) {
        pbVar9 = param_3 + CONCAT11(param_3[5],param_3[6]) + 7;
        if (param_2[(int)pbStack_4c - 0x1f] < (int)(uint)param_3[1]) {
          pbStack_4c = pbVar9 + ((uint)CONCAT11(param_3[3],param_3[4]) -
                                (uint)CONCAT11(param_3[5],param_3[6]));
          uStack_54 = 0x6cf66e;
          FUN_006cf3b0();
        }
      }
      else {
        if ((int)(uint)param_3[1] <= param_2[(int)pbStack_4c - 0x1f]) {
          return;
        }
        pbVar9 = param_3 + CONCAT11(param_3[3],param_3[4]) + 7;
      }
      break;
    case (byte *)0x26:
    case (byte *)0x27:
    case (byte *)0x28:
      if (param_2[(int)pbStack_4c - 0x26] < (int)(uint)param_3[1]) {
        return;
      }
      if ((int)(uint)param_3[2] <= param_2[(int)pbStack_4c - 0x22]) {
        return;
      }
      pbVar9 = param_3 + 3;
      break;
    case (byte *)0x29:
    case (byte *)0x2a:
    case (byte *)0x2b:
      if (param_1[(int)pbStack_4c - 0x25] <
          (int)(uint)CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3])) {
        return;
      }
      if ((int)(uint)CONCAT21(CONCAT11(param_3[4],param_3[5]),param_3[6]) <
          param_1[(int)pbStack_4c - 0x21]) {
        return;
      }
      pbVar9 = param_3 + 7;
      break;
    default:
      uVar8 = (int)pbStack_4c - 0x30;
      goto LAB_006cf962;
    case (byte *)0x50:
      uVar8 = (uint)param_3[1];
      goto LAB_006cf962;
    case (byte *)0x51:
      uVar8 = (uint)CONCAT11(param_3[1],param_3[2]);
      goto LAB_006cf962;
    case (byte *)0x52:
      uVar8 = (uint)CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]);
      goto LAB_006cf962;
    case (byte *)0x53:
      uVar8 = CONCAT31(CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]),param_3[4]);
LAB_006cf962:
      iVar7 = param_2[0xb];
      param_1 = (int *)*param_1;
      if (param_1[1] == (param_1[2] & 0x7fffffffU)) {
        pbStack_4c = (byte *)0x4;
        uStack_54 = 0x6cf982;
        piStack_50 = param_1;
        FUN_005b3370();
      }
      *(uint *)(*param_1 + param_1[1] * 4) = iVar7 + uVar8;
      param_1[1] = param_1[1] + 1;
      return;
    case (byte *)0x60:
    case (byte *)0x61:
    case (byte *)0x62:
    case (byte *)0x63:
      pbVar9 = param_3 + 2;
      auStack_184[(int)pbStack_4c] = (uint)param_3[1];
      goto LAB_006cf8a5;
    case (byte *)0x64:
    case (byte *)0x65:
    case (byte *)0x66:
    case (byte *)0x67:
      auStack_194[(int)pbStack_4c] = (uint)CONCAT11(param_3[1],param_3[2]);
      pbVar9 = param_3 + 3;
      goto LAB_006cf8a5;
    case (byte *)0x68:
    case (byte *)0x69:
    case (byte *)0x6a:
    case (byte *)0x6b:
      auStack_1a4[(int)pbStack_4c] =
           CONCAT31(CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]),param_3[4]);
      pbVar9 = param_3 + 5;
LAB_006cf8a5:
      if (param_2 != local_38) {
        piVar10 = local_38;
        for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar10 = *param_2;
          param_2 = param_2 + 1;
          piVar10 = piVar10 + 1;
        }
        param_2 = local_38;
      }
    }
    param_3 = pbVar9;
    bVar5 = *pbVar9;
  }
switchD_006cf3d7_caseD_8:
  piStack_50 = (int *)0xa0e298;
  uStack_54 = 0x6cf8e2;
  uStack_54 = (**(code **)(*DAT_00d030e0 + 4))();
  uStack_58 = 0x6cf8e8;
  FUN_00631f10();
  pbStack_4c = (byte *)0x6cf8f6;
  (**(code **)(*DAT_00d030e0 + 4))();
  pbStack_4c = (byte *)0x6cf8fd;
  FUN_00631f70();
  _DAT_00000000 = 0;
  return;
}
```
