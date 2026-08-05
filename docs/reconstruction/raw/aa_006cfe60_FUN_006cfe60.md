# Raw capture: FUN_006cfe60

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cfe60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006cfe60` |
| **Canonical name** | `FUN_006cfe60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_006cfe60(int param_1,float *param_2,byte *param_3,float *param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  byte bVar7;
  float fVar8;
  char *pcVar9;
  int *piVar10;
  float *pfVar11;
  uint uVar12;
  int iVar13;
  byte *pbVar14;
  uint auStack_334 [81];
  int **ppiStack_1f0;
  float *pfStack_1ec;
  byte *pbStack_1e8;
  float *pfStack_1e4;
  uint local_1cc;
  float local_1c8;
  float local_1c0;
  uint local_1bc;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  float local_19c;
  undefined4 local_198;
  float local_194;
  undefined1 local_18d;
  int local_18c;
  float local_188;
  float local_184;
  float local_180;
  float local_17c;
  float local_178;
  float local_174;
  float local_170;
  float local_16c;
  int *local_168;
  float local_164;
  float local_160;
  float local_15c;
  float local_158;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_118;
  undefined1 local_110 [268];
  
  bVar7 = *param_3;
  local_18c = 999;
  while (pfStack_1e4 = (float *)(uint)bVar7, pfStack_1e4 < 0x6c) {
    local_18c = 999;
    switch(pfStack_1e4) {
    case (float *)0x0:
      goto switchD_006cfe97_caseD_0;
    case (float *)0x1:
    case (float *)0x2:
    case (float *)0x3:
    case (float *)0x4:
      fVar4 = (float)param_3[1];
      fVar5 = (float)param_3[2];
      local_118 = (float)param_3[3];
      param_4[3] = param_4[3];
      fVar3 = (float)(1 << (bVar7 & 0x1f));
      *param_4 = *param_4 - fVar4;
      param_4[1] = param_4[1] - fVar5;
      param_4[2] = param_4[2] - local_118;
      param_4[7] = param_4[7];
      param_4[4] = param_4[4] - fVar4;
      param_4[5] = param_4[5] - fVar5;
      param_4[6] = param_4[6] - local_118;
      *param_4 = fVar3 * *param_4;
      param_4[1] = fVar3 * param_4[1];
      param_4[2] = fVar3 * param_4[2];
      param_4[3] = fVar3 * param_4[3];
      param_4[4] = fVar3 * param_4[4];
      param_4[5] = fVar3 * param_4[5];
      param_4[6] = fVar3 * param_4[6];
      param_4[7] = fVar3 * param_4[7];
      local_1b0 = fVar4 + *param_2;
      local_1ac = fVar5 + param_2[1];
      local_1a8 = local_118 + param_2[2];
      local_1b0 = (fVar4 + *param_2) * fVar3;
      local_1ac = (fVar5 + param_2[1]) * fVar3;
      local_1a8 = (local_118 + param_2[2]) * fVar3;
      local_1a4 = param_2[3] * fVar3;
      local_1a0 = (float)((int)param_2[4] + (int)pfStack_1e4);
      param_3 = param_3 + 4;
      local_19c = fVar3 * param_2[5];
      local_194 = param_2[7];
      local_198 = param_2[6];
      param_2 = &local_1b0;
      goto LAB_006d01f2;
    case (float *)0x5:
      param_3 = param_3 + param_3[1] + 2;
      goto LAB_006d01f2;
    case (float *)0x6:
      param_3 = param_3 + (uint)param_3[1] * 0x100 + param_3[2] + 3;
      goto LAB_006d01f2;
    case (float *)0x7:
      param_3 = param_3 + (uint)CONCAT11(param_3[1],param_3[2]) * 0x100 + param_3[3] + 4;
      goto LAB_006d01f2;
    case (float *)0x8:
    case (float *)0xc:
    case (float *)0xd:
    case (float *)0xe:
    case (float *)0xf:
    case (float *)0x1d:
    case (float *)0x1e:
    case (float *)0x1f:
    case (float *)0x2c:
    case (float *)0x2d:
    case (float *)0x2e:
    case (float *)0x2f:
    case (float *)0x54:
    case (float *)0x55:
    case (float *)0x56:
    case (float *)0x57:
    case (float *)0x58:
    case (float *)0x59:
    case (float *)0x5a:
    case (float *)0x5b:
    case (float *)0x5c:
    case (float *)0x5d:
    case (float *)0x5e:
    case (float *)0x5f:
      goto switchD_006cfe97_caseD_8;
    case (float *)0x9:
      if (param_2 != &local_1b0) {
        local_1b0 = *param_2;
        local_1ac = param_2[1];
        local_1a8 = param_2[2];
        local_1a4 = param_2[3];
        local_1a0 = param_2[4];
        local_19c = param_2[5];
        local_198 = param_2[6];
        local_194 = param_2[7];
        param_2 = &local_1b0;
      }
      local_198 = (float)((int)local_198 + (uint)param_3[1]);
      param_3 = param_3 + 2;
      goto LAB_006d01f2;
    case (float *)0xa:
      if (param_2 != &local_1b0) {
        local_1b0 = *param_2;
        local_1ac = param_2[1];
        local_1a8 = param_2[2];
        local_1a4 = param_2[3];
        local_1a0 = param_2[4];
        local_19c = param_2[5];
        local_198 = param_2[6];
        local_194 = param_2[7];
        param_2 = &local_1b0;
      }
      local_198 = (float)((int)local_198 + (uint)CONCAT11(param_3[1],param_3[2]));
      param_3 = param_3 + 3;
      goto LAB_006d01f2;
    case (float *)0xb:
      if (param_2 != &local_1b0) {
        local_1b0 = *param_2;
        local_1ac = param_2[1];
        local_1a8 = param_2[2];
        local_1a4 = param_2[3];
        local_1a0 = param_2[4];
        local_19c = param_2[5];
        local_198 = param_2[6];
        local_194 = param_2[7];
        param_2 = &local_1b0;
      }
      local_198 = (float)CONCAT31(CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]),param_3[4]);
      param_3 = param_3 + 5;
      goto LAB_006d01f2;
    case (float *)0x10:
    case (float *)0x11:
    case (float *)0x12:
      local_18c = (int)pfStack_1e4 - 0x10;
      local_1c8 = (float)param_3[1];
      local_1c0 = (float)param_3[2];
      fVar3 = param_4[local_18c];
      fVar4 = param_4[(int)pfStack_1e4 - 0xc];
      break;
    case (float *)0x13:
      local_1c8 = (float)((uint)param_3[1] << 1);
      local_1c0 = (float)((uint)param_3[2] << 1);
      fVar3 = param_4[2] + param_4[1];
      fVar4 = param_4[6] + param_4[5];
      break;
    case (float *)0x14:
      local_1c8 = (float)(int)((uint)param_3[1] * 2 + -0xff);
      local_1c0 = (float)(int)((uint)param_3[2] * 2 + -0xff);
      fVar3 = param_4[1] - param_4[2];
      fVar4 = param_4[5] - param_4[6];
      break;
    case (float *)0x15:
      local_1c8 = (float)((uint)param_3[1] << 1);
      local_1c0 = (float)((uint)param_3[2] << 1);
      fVar3 = param_4[2] + *param_4;
      fVar4 = param_4[6] + param_4[4];
      break;
    case (float *)0x16:
      local_1c8 = (float)(int)((uint)param_3[1] * 2 + -0xff);
      local_1c0 = (float)(int)((uint)param_3[2] * 2 + -0xff);
      fVar3 = *param_4 - param_4[2];
      fVar4 = param_4[4] - param_4[6];
      break;
    case (float *)0x17:
      local_1c8 = (float)((uint)param_3[1] << 1);
      local_1c0 = (float)((uint)param_3[2] << 1);
      fVar3 = param_4[1] + *param_4;
      fVar4 = param_4[5] + param_4[4];
      break;
    case (float *)0x18:
      local_1c8 = (float)(int)((uint)param_3[1] * 2 + -0xff);
      local_1c0 = (float)(int)((uint)param_3[2] * 2 + -0xff);
      fVar3 = *param_4 - param_4[1];
      fVar4 = param_4[4] - param_4[5];
      break;
    case (float *)0x19:
      local_1c8 = (float)((uint)param_3[1] * 3);
      local_1c0 = (float)((uint)param_3[2] * 3);
      fVar3 = param_4[2] + param_4[1] + *param_4;
      fVar4 = param_4[6] + param_4[5] + param_4[4];
      break;
    case (float *)0x1a:
      local_1c8 = (float)(int)((param_3[1] - 0x55) * 3);
      local_1c0 = (float)(int)((param_3[2] - 0x55) * 3);
      fVar3 = (param_4[1] + *param_4) - param_4[2];
      fVar4 = (param_4[5] + param_4[4]) - param_4[6];
      break;
    case (float *)0x1b:
      local_1c8 = (float)(int)((param_3[1] - 0x55) * 3);
      local_1c0 = (float)(int)((param_3[2] - 0x55) * 3);
      fVar3 = (*param_4 - param_4[1]) + param_4[2];
      fVar4 = (param_4[4] - param_4[5]) + param_4[6];
      break;
    case (float *)0x1c:
      local_1c8 = (float)(int)((param_3[1] - 0xaa) * 3);
      local_1c0 = (float)(int)((param_3[2] - 0xaa) * 3);
      fVar3 = (*param_4 - param_4[1]) - param_4[2];
      fVar4 = (param_4[4] - param_4[5]) - param_4[6];
      break;
    case (float *)0x20:
    case (float *)0x21:
    case (float *)0x22:
      local_1cc = (uint)param_3[2];
      pbVar14 = param_3 + 3;
      local_18c = (int)pfStack_1e4 - 0x20;
      local_1bc = 0;
      local_1c0 = (float)param_3[1];
      local_1c8 = (float)param_3[1] + g_flOne;
      fVar3 = param_4[local_18c];
      fVar4 = param_4[(int)pfStack_1e4 - 0x1c];
      goto LAB_006d01d0;
    case (float *)0x23:
    case (float *)0x24:
    case (float *)0x25:
      local_1c8 = (float)param_3[1];
      local_18c = (int)pfStack_1e4 - 0x23;
      local_1c0 = (float)param_3[2];
      pbVar14 = param_3 + 7;
      fVar3 = param_4[local_18c];
      fVar4 = param_4[(int)pfStack_1e4 - 0x1f];
      local_1bc = (uint)CONCAT11(param_3[3],param_3[4]);
      local_1cc = (uint)CONCAT11(param_3[5],param_3[6]);
      goto LAB_006d01d0;
    case (float *)0x26:
    case (float *)0x27:
    case (float *)0x28:
      pbVar14 = param_3 + 1;
      pbVar1 = param_3 + 2;
      iVar13 = (int)pfStack_1e4 - 0x26;
      param_3 = param_3 + 3;
      fVar3 = (float)*pbVar14;
      fVar4 = (float)*pbVar1;
      goto LAB_006d0747;
    case (float *)0x29:
    case (float *)0x2a:
    case (float *)0x2b:
      pbVar14 = param_3 + 5;
      iVar13 = (int)pfStack_1e4 - 0x29;
      pbVar1 = param_3 + 4;
      pbVar2 = param_3 + 6;
      fVar3 = (float)CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]) *
              *(float *)(param_1 + 0x14) * param_2[5] - param_2[iVar13];
      param_3 = param_3 + 7;
      fVar4 = (float)CONCAT21(CONCAT11(*pbVar1,*pbVar14),*pbVar2) * *(float *)(param_1 + 0x14) *
              param_2[5] - param_2[iVar13];
LAB_006d0747:
      fVar5 = param_4[iVar13];
      fVar6 = param_4[iVar13 + 4];
      if (fVar6 <= fVar5) {
        if (fVar5 < fVar3) {
          return;
        }
        if (fVar4 < fVar6) {
          return;
        }
        iVar13 = 1;
      }
      else {
        if (fVar6 < fVar3) {
          return;
        }
        if (fVar4 < fVar5) {
          return;
        }
        iVar13 = 0;
      }
      local_16c = param_4[1];
      local_170 = *param_4;
      fVar8 = fVar5 - fVar4;
      local_164 = param_4[3];
      local_17c = param_4[5];
      local_168 = (int *)param_4[2];
      local_174 = param_4[7];
      local_180 = param_4[4];
      local_178 = param_4[6];
      if (fVar8 * (fVar6 - fVar4) < g_flZero) {
        fVar8 = fVar8 / (fVar8 - (fVar6 - fVar4));
        fVar4 = g_flOne - fVar8;
        param_4[iVar13 * -4 + 4] = fVar4 * local_170 + fVar8 * local_180;
        param_4[iVar13 * -4 + 5] = local_16c * fVar4 + local_17c * fVar8;
        param_4[iVar13 * -4 + 6] = (float)local_168 * fVar4 + local_178 * fVar8;
        param_4[iVar13 * -4 + 7] = local_164 * fVar4 + local_174 * fVar8;
      }
      fVar5 = fVar5 - fVar3;
      if (fVar5 * (fVar6 - fVar3) < g_flZero) {
        pfVar11 = param_4 + iVar13 * 4;
        fVar5 = fVar5 / (fVar5 - (fVar6 - fVar3));
        fVar3 = g_flOne - fVar5;
        *pfVar11 = fVar3 * local_170 + fVar5 * local_180;
        pfVar11[1] = local_16c * fVar3 + local_17c * fVar5;
        pfVar11[2] = (float)local_168 * fVar3 + local_178 * fVar5;
        pfVar11[3] = local_164 * fVar3 + local_174 * fVar5;
      }
      goto LAB_006d01f2;
    default:
      uVar12 = (int)pfStack_1e4 - 0x30;
      goto LAB_006d0c89;
    case (float *)0x50:
      uVar12 = (uint)param_3[1];
      goto LAB_006d0c89;
    case (float *)0x51:
      uVar12 = (uint)CONCAT11(param_3[1],param_3[2]);
      goto LAB_006d0c89;
    case (float *)0x52:
      uVar12 = (uint)CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]);
      goto LAB_006d0c89;
    case (float *)0x53:
      uVar12 = (uint)param_3[4] + (uint)CONCAT11(param_3[1],param_3[2]) * 0x10000 +
               (uint)param_3[3] * 0x100;
LAB_006d0c89:
      iVar13 = uVar12 + (int)param_2[6];
      if (*(undefined4 **)(param_1 + 0x44) != (undefined4 *)0x0) {
        pbStack_1e8 = *(byte **)(param_1 + 100);
        pfStack_1ec = (float *)(param_1 + 0x20);
        ppiStack_1f0 = (int **)&local_18d;
        auStack_334[0x50] = 0x6d0cab;
        pfStack_1e4 = (float *)iVar13;
        pcVar9 = (char *)(**(code **)**(undefined4 **)(param_1 + 0x44))();
        if (*pcVar9 == '\0') {
          return;
        }
      }
      pfStack_1e4 = (float *)local_110;
      pfStack_1ec = (float *)0x6d0ccb;
      pbStack_1e8 = (byte *)iVar13;
      piVar10 = (int *)(**(code **)(**(int **)(param_1 + 100) + 0x34))();
      pfStack_1ec = *(float **)((int)local_1c0 + 0x58);
      if (pfStack_1ec != (float *)0x0) {
        ppiStack_1f0 = (int **)((int)local_1c0 + 0x20);
        auStack_334[0x50] = (int)&local_198 + 3;
        auStack_334[0x4f] = 0x6d0ce7;
        pcVar9 = (char *)(**(code **)(*piVar10 + 0x20))();
        if (*pcVar9 == '\0') {
          return;
        }
        *(undefined1 *)((int)local_1c0 + 0x50) = 1;
        *(undefined4 *)((int)local_1c0 + 0x54) =
             *(undefined4 *)(*(int *)((int)local_1c0 + 0x58) + 0x14);
        *(int *)(*(int *)((int)local_1c0 + 0x58) + 0x10) = iVar13;
        return;
      }
      local_15c = *(float *)((int)local_1c0 + 0x60);
      local_160 = *(float *)((int)local_15c + 8);
      pfStack_1ec = *(float **)((int)local_1c0 + 0x5c);
      ppiStack_1f0 = &local_168;
      auStack_334[0x50] = (int)local_1c0 + 0x20;
      auStack_334[0x4f] = 0x6d0d3c;
      local_168 = piVar10;
      local_164 = (float)iVar13;
      (**(code **)(*piVar10 + 0x24))();
      *(undefined4 *)((int)local_1c0 + 0x54) = *(undefined4 *)(*(int *)((int)local_1c0 + 0x5c) + 4);
      return;
    case (float *)0x60:
    case (float *)0x61:
    case (float *)0x62:
    case (float *)0x63:
      pbVar14 = param_3 + 1;
      param_3 = param_3 + 2;
      auStack_334[(int)pfStack_1e4 + 8] = (uint)*pbVar14;
      goto LAB_006d0bee;
    case (float *)0x64:
    case (float *)0x65:
    case (float *)0x66:
    case (float *)0x67:
      auStack_334[(int)pfStack_1e4 + 4] = (uint)CONCAT11(param_3[1],param_3[2]);
      param_3 = param_3 + 3;
      goto LAB_006d0bee;
    case (float *)0x68:
    case (float *)0x69:
    case (float *)0x6a:
    case (float *)0x6b:
      auStack_334[(int)pfStack_1e4] =
           CONCAT31(CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]),param_3[4]);
      param_3 = param_3 + 5;
LAB_006d0bee:
      if (param_2 != &local_1b0) {
        local_1b0 = *param_2;
        local_1ac = param_2[1];
        local_1a8 = param_2[2];
        local_1a4 = param_2[3];
        local_1a0 = param_2[4];
        local_19c = param_2[5];
        local_198 = param_2[6];
        param_2 = &local_1b0;
      }
      goto LAB_006d01f2;
    }
    local_1cc = (uint)param_3[3];
    pbVar14 = param_3 + 4;
    local_1bc = 0;
LAB_006d01d0:
    if ((local_1c0 <= fVar4) || (local_1c0 <= fVar3)) {
      param_3 = pbVar14 + local_1cc;
      if ((fVar3 <= local_1c8) || (fVar4 <= local_1c8)) {
        local_150 = *param_4;
        fVar5 = fVar3 - local_1c8;
        local_14c = param_4[1];
        local_148 = param_4[2];
        local_188 = fVar3 - local_1c0;
        local_144 = param_4[3];
        local_140 = param_4[4];
        local_13c = param_4[5];
        local_184 = fVar4 - local_1c8;
        local_138 = param_4[6];
        local_134 = param_4[7];
        fVar4 = fVar4 - local_1c0;
        pfStack_1ec = param_2;
        if (local_184 <= fVar5) {
          if (fVar4 * local_188 < g_flZero) {
            fVar3 = local_188 / (local_188 - fVar4);
            fVar4 = g_flOne - fVar3;
            local_140 = fVar3 * param_4[4] + fVar4 * *param_4;
            local_13c = fVar4 * param_4[1] + fVar3 * param_4[5];
            local_138 = fVar4 * param_4[2] + fVar3 * param_4[6];
            local_134 = fVar4 * param_4[3] + fVar3 * param_4[7];
          }
          pfStack_1e4 = &local_150;
          ppiStack_1f0 = (int **)0x6d0564;
          pbStack_1e8 = param_3;
          FUN_006cfe60();
          if (local_184 * fVar5 < g_flZero) {
            fVar5 = fVar5 / (fVar5 - local_184);
            fVar3 = g_flOne - fVar5;
            *param_4 = fVar3 * *param_4 + fVar5 * param_4[4];
            param_4[1] = fVar3 * param_4[1] + fVar5 * param_4[5];
            param_4[2] = fVar3 * param_4[2] + fVar5 * param_4[6];
            param_4[3] = fVar3 * param_4[3] + fVar5 * param_4[7];
          }
          if (*(float *)(param_1 + 0x54) < g_flOne) {
            fVar3 = *(float *)(param_1 + 0x54);
            fVar6 = g_flOne - fVar3;
            local_160 = fVar3 * *(float *)(param_1 + 0x30) + fVar6 * *(float *)(param_1 + 0x20);
            local_15c = fVar3 * *(float *)(param_1 + 0x34) + fVar6 * *(float *)(param_1 + 0x24);
            local_158 = fVar3 * *(float *)(param_1 + 0x38) + fVar6 * *(float *)(param_1 + 0x28);
            fVar4 = *(float *)(param_1 + 0x2c);
            fVar5 = *(float *)(param_1 + 0x3c);
            pfVar11 = *(float **)(param_1 + 0x10);
            param_4[4] = local_160 - *pfVar11;
            param_4[5] = local_15c - pfVar11[1];
            param_4[6] = local_158 - pfVar11[2];
            param_4[7] = (fVar3 * fVar5 + fVar6 * fVar4) - pfVar11[3];
            fVar3 = param_2[5];
            param_4[4] = fVar3 * param_4[4];
            param_4[5] = fVar3 * param_4[5];
            param_4[6] = fVar3 * param_4[6];
            param_4[7] = fVar3 * param_4[7];
            param_4[4] = param_4[4] - *param_2;
            param_4[5] = param_4[5] - param_2[1];
            param_4[6] = param_4[6] - param_2[2];
            param_4[7] = param_4[7] - param_2[3];
            if ((local_18c < 3) && (local_1c8 < param_4[local_18c + 4])) {
              return;
            }
          }
          param_3 = param_3 + (local_1bc - local_1cc);
        }
        else {
          if (local_184 * fVar5 < g_flZero) {
            fVar5 = fVar5 / (fVar5 - local_184);
            fVar3 = g_flOne - fVar5;
            local_140 = fVar5 * param_4[4] + fVar3 * *param_4;
            local_13c = fVar3 * param_4[1] + fVar5 * param_4[5];
            local_138 = fVar3 * param_4[2] + fVar5 * param_4[6];
            local_134 = fVar3 * param_4[3] + fVar5 * param_4[7];
          }
          pfStack_1e4 = &local_150;
          pbStack_1e8 = param_3 + (local_1bc - local_1cc);
          ppiStack_1f0 = (int **)0x6d037c;
          FUN_006cfe60();
          if (fVar4 * local_188 < g_flZero) {
            fVar3 = local_188 / (local_188 - fVar4);
            fVar4 = g_flOne - fVar3;
            *param_4 = fVar3 * param_4[4] + fVar4 * *param_4;
            param_4[1] = fVar4 * param_4[1] + fVar3 * param_4[5];
            param_4[2] = fVar4 * param_4[2] + fVar3 * param_4[6];
            param_4[3] = fVar4 * param_4[3] + fVar3 * param_4[7];
          }
          if (*(float *)(param_1 + 0x54) < g_flOne) {
            fVar3 = *(float *)(param_1 + 0x54);
            fVar6 = g_flOne - fVar3;
            local_130 = fVar3 * *(float *)(param_1 + 0x30) + fVar6 * *(float *)(param_1 + 0x20);
            local_12c = fVar3 * *(float *)(param_1 + 0x34) + fVar6 * *(float *)(param_1 + 0x24);
            local_128 = fVar3 * *(float *)(param_1 + 0x38) + fVar6 * *(float *)(param_1 + 0x28);
            fVar4 = *(float *)(param_1 + 0x2c);
            fVar5 = *(float *)(param_1 + 0x3c);
            pfVar11 = *(float **)(param_1 + 0x10);
            param_4[4] = local_130 - *pfVar11;
            param_4[5] = local_12c - pfVar11[1];
            param_4[6] = local_128 - pfVar11[2];
            param_4[7] = (fVar3 * fVar5 + fVar6 * fVar4) - pfVar11[3];
            fVar3 = param_2[5];
            param_4[4] = fVar3 * param_4[4];
            param_4[5] = fVar3 * param_4[5];
            param_4[6] = fVar3 * param_4[6];
            param_4[7] = fVar3 * param_4[7];
            param_4[4] = param_4[4] - *param_2;
            param_4[5] = param_4[5] - param_2[1];
            param_4[6] = param_4[6] - param_2[2];
            param_4[7] = param_4[7] - param_2[3];
            if ((local_18c < 3) && (param_4[local_18c + 4] < local_1c0)) {
switchD_006cfe97_caseD_0:
              return;
            }
          }
        }
      }
    }
    else {
      param_3 = pbVar14 + local_1bc;
    }
LAB_006d01f2:
    bVar7 = *param_3;
    local_18c = 999;
  }
switchD_006cfe97_caseD_8:
  local_18c = 999;
  pbStack_1e8 = (byte *)0xa0e298;
  pfStack_1ec = (float *)0x6d0217;
  pfStack_1ec = (float *)(**(code **)(*DAT_00d030e0 + 4))();
  ppiStack_1f0 = (int **)0x6d021d;
  FUN_00631f10();
  pfStack_1e4 = (float *)0x6d022b;
  (**(code **)(*DAT_00d030e0 + 4))();
  pfStack_1e4 = (float *)0x6d0232;
  FUN_00631f70();
  _DAT_00000000 = 0;
  return;
}
```
