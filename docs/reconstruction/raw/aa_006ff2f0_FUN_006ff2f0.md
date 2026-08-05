# Raw capture: FUN_006ff2f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ff2f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ff2f0` |
| **Canonical name** | `FUN_006ff2f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_006ff2f0(int param_1,float *param_2,byte *param_3,float *param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  byte bVar10;
  int *piVar11;
  float fVar12;
  char *pcVar13;
  int iVar14;
  float *pfVar15;
  byte *pbVar16;
  uint uVar17;
  int iVar18;
  uint auStack_340 [64];
  int **ppiStack_240;
  int *piStack_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  int iStack_230;
  float *pfStack_22c;
  undefined1 *puStack_228;
  int iStack_224;
  undefined4 uStack_220;
  float *pfStack_21c;
  byte *pbStack_218;
  float *pfStack_214;
  int iStack_204;
  uint local_1f8;
  float local_1f0;
  float local_1ec;
  uint local_1e8;
  int local_1d8;
  float local_1d0;
  float local_1cc;
  float local_1c8;
  float local_1c4;
  float local_1c0;
  float local_1bc;
  float local_1b8;
  float local_1b4;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  undefined1 local_181;
  int *local_180;
  float local_17c;
  float local_178;
  float local_174;
  float local_170;
  float local_16c;
  float local_168;
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
  float local_128 [4];
  float local_118;
  
  bVar10 = *param_3;
  while (pfStack_214 = (float *)(uint)bVar10, pfStack_214 < 0x6c) {
    local_1d8 = 999;
    switch(pfStack_214) {
    case (float *)0x0:
      goto switchD_006ff327_caseD_0;
    case (float *)0x1:
    case (float *)0x2:
    case (float *)0x3:
    case (float *)0x4:
      fVar7 = (float)param_3[1];
      fVar8 = (float)param_3[2];
      local_118 = (float)param_3[3];
      param_4[3] = param_4[3];
      fVar6 = (float)(1 << (bVar10 & 0x1f));
      *param_4 = *param_4 - fVar7;
      param_4[1] = param_4[1] - fVar8;
      param_4[2] = param_4[2] - local_118;
      param_4[7] = param_4[7];
      param_4[4] = param_4[4] - fVar7;
      param_4[5] = param_4[5] - fVar8;
      param_4[6] = param_4[6] - local_118;
      *param_4 = fVar6 * *param_4;
      param_4[1] = fVar6 * param_4[1];
      param_4[2] = fVar6 * param_4[2];
      param_4[3] = fVar6 * param_4[3];
      param_4[4] = fVar6 * param_4[4];
      param_4[5] = fVar6 * param_4[5];
      param_4[6] = fVar6 * param_4[6];
      param_4[7] = fVar6 * param_4[7];
      local_1d0 = fVar7 + *param_2;
      local_1cc = fVar8 + param_2[1];
      local_1c8 = local_118 + param_2[2];
      local_1d0 = (fVar7 + *param_2) * fVar6;
      local_1cc = (fVar8 + param_2[1]) * fVar6;
      local_1c8 = (local_118 + param_2[2]) * fVar6;
      local_1c4 = param_2[3] * fVar6;
      local_1ac = (float)((int)param_2[9] + (int)pfStack_214);
      param_3 = param_3 + 4;
      local_1a8 = fVar6 * param_2[10];
      local_1c0 = fVar6 * param_2[4];
      local_1bc = fVar6 * param_2[5];
      local_1b8 = fVar6 * param_2[6];
      local_1b4 = fVar6 * param_2[7];
      local_1b0 = fVar6 * param_2[8];
      local_1a0 = param_2[0xc];
      local_1a4 = param_2[0xb];
      param_2 = &local_1d0;
      goto LAB_006ff716;
    case (float *)0x5:
      param_3 = param_3 + param_3[1] + 2;
      goto LAB_006ff716;
    case (float *)0x6:
      param_3 = param_3 + (uint)param_3[1] * 0x100 + param_3[2] + 3;
      goto LAB_006ff716;
    case (float *)0x7:
      param_3 = param_3 + (uint)CONCAT11(param_3[1],param_3[2]) * 0x100 + param_3[3] + 4;
      goto LAB_006ff716;
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
      goto switchD_006ff327_caseD_8;
    case (float *)0x9:
      if (param_2 != &local_1d0) {
        local_1d0 = *param_2;
        local_1cc = param_2[1];
        local_1c8 = param_2[2];
        local_1c4 = param_2[3];
        local_1c0 = param_2[4];
        local_1bc = param_2[5];
        local_1b8 = param_2[6];
        local_1b4 = param_2[7];
        local_1b0 = param_2[8];
        local_1ac = param_2[9];
        local_1a8 = param_2[10];
        local_1a4 = param_2[0xb];
        local_1a0 = param_2[0xc];
        param_2 = &local_1d0;
      }
      local_1a4 = (float)((int)local_1a4 + (uint)param_3[1]);
      param_3 = param_3 + 2;
      goto LAB_006ff716;
    case (float *)0xa:
      if (param_2 != &local_1d0) {
        local_1d0 = *param_2;
        local_1cc = param_2[1];
        local_1c8 = param_2[2];
        local_1c4 = param_2[3];
        local_1c0 = param_2[4];
        local_1bc = param_2[5];
        local_1b8 = param_2[6];
        local_1b4 = param_2[7];
        local_1b0 = param_2[8];
        local_1ac = param_2[9];
        local_1a8 = param_2[10];
        local_1a4 = param_2[0xb];
        local_1a0 = param_2[0xc];
        param_2 = &local_1d0;
      }
      local_1a4 = (float)((int)local_1a4 + (uint)CONCAT11(param_3[1],param_3[2]));
      param_3 = param_3 + 3;
      goto LAB_006ff716;
    case (float *)0xb:
      if (param_2 != &local_1d0) {
        local_1d0 = *param_2;
        local_1cc = param_2[1];
        local_1c8 = param_2[2];
        local_1c4 = param_2[3];
        local_1c0 = param_2[4];
        local_1bc = param_2[5];
        local_1b8 = param_2[6];
        local_1b4 = param_2[7];
        local_1b0 = param_2[8];
        local_1ac = param_2[9];
        local_1a8 = param_2[10];
        local_1a4 = param_2[0xb];
        local_1a0 = param_2[0xc];
        param_2 = &local_1d0;
      }
      local_1a4 = (float)CONCAT31(CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]),param_3[4]);
      param_3 = param_3 + 5;
      goto LAB_006ff716;
    case (float *)0x10:
    case (float *)0x11:
    case (float *)0x12:
      local_1d8 = (int)pfStack_214 - 0x10;
      local_1f0 = (float)param_3[2] - param_2[(int)pfStack_214 - 0xc];
      local_1ec = (float)param_3[1] + param_2[(int)pfStack_214 - 0xc];
      fVar6 = param_4[local_1d8];
      fVar7 = param_4[(int)pfStack_214 - 0xc];
      break;
    case (float *)0x13:
      local_1ec = param_2[6] + param_2[5] + param_2[6] + param_2[5];
      local_1f0 = (float)((uint)param_3[2] << 1) - local_1ec;
      local_1ec = (float)((uint)param_3[1] << 1) + local_1ec;
      fVar6 = param_4[2] + param_4[1];
      fVar7 = param_4[6] + param_4[5];
      break;
    case (float *)0x14:
      local_1ec = param_2[6] + param_2[5] + param_2[6] + param_2[5];
      local_1f0 = (float)(int)((uint)param_3[2] * 2 + -0xff) - local_1ec;
      local_1ec = (float)(int)((uint)param_3[1] * 2 + -0xff) + local_1ec;
      fVar6 = param_4[1] - param_4[2];
      fVar7 = param_4[5] - param_4[6];
      break;
    case (float *)0x15:
      local_1ec = param_2[6] + param_2[4] + param_2[6] + param_2[4];
      local_1f0 = (float)((uint)param_3[2] << 1) - local_1ec;
      local_1ec = (float)((uint)param_3[1] << 1) + local_1ec;
      fVar6 = param_4[2] + *param_4;
      fVar7 = param_4[6] + param_4[4];
      break;
    case (float *)0x16:
      local_1ec = param_2[6] + param_2[4] + param_2[6] + param_2[4];
      local_1f0 = (float)(int)((uint)param_3[2] * 2 + -0xff) - local_1ec;
      local_1ec = (float)(int)((uint)param_3[1] * 2 + -0xff) + local_1ec;
      fVar6 = *param_4 - param_4[2];
      fVar7 = param_4[4] - param_4[6];
      break;
    case (float *)0x17:
      local_1ec = param_2[5] + param_2[4] + param_2[5] + param_2[4];
      local_1f0 = (float)((uint)param_3[2] << 1) - local_1ec;
      local_1ec = (float)((uint)param_3[1] << 1) + local_1ec;
      fVar6 = param_4[1] + *param_4;
      fVar7 = param_4[5] + param_4[4];
      break;
    case (float *)0x18:
      local_1ec = param_2[5] + param_2[4] + param_2[5] + param_2[4];
      local_1f0 = (float)(int)((uint)param_3[2] * 2 + -0xff) - local_1ec;
      local_1ec = (float)(int)((uint)param_3[1] * 2 + -0xff) + local_1ec;
      fVar6 = *param_4 - param_4[1];
      fVar7 = param_4[4] - param_4[5];
      break;
    case (float *)0x19:
      local_1f0 = (float)((uint)param_3[2] * 3) - param_2[8];
      local_1ec = (float)((uint)param_3[1] * 3) + param_2[8];
      fVar6 = param_4[2] + param_4[1] + *param_4;
      fVar7 = param_4[6] + param_4[5] + param_4[4];
      break;
    case (float *)0x1a:
      local_1f0 = (float)(int)((param_3[2] - 0x55) * 3) - param_2[8];
      local_1ec = (float)(int)((param_3[1] - 0x55) * 3) + param_2[8];
      fVar6 = (param_4[1] + *param_4) - param_4[2];
      fVar7 = (param_4[5] + param_4[4]) - param_4[6];
      break;
    case (float *)0x1b:
      local_1f0 = (float)(int)((param_3[2] - 0x55) * 3) - param_2[8];
      local_1ec = (float)(int)((param_3[1] - 0x55) * 3) + param_2[8];
      fVar6 = (*param_4 - param_4[1]) + param_4[2];
      fVar7 = (param_4[4] - param_4[5]) + param_4[6];
      break;
    case (float *)0x1c:
      local_1f0 = (float)(int)((param_3[2] - 0xaa) * 3) - param_2[8];
      local_1ec = (float)(int)((param_3[1] - 0xaa) * 3) + param_2[8];
      fVar6 = (*param_4 - param_4[1]) - param_4[2];
      fVar7 = (param_4[4] - param_4[5]) - param_4[6];
      break;
    case (float *)0x20:
    case (float *)0x21:
    case (float *)0x22:
      local_1f8 = (uint)param_3[2];
      local_1d8 = (int)pfStack_214 - 0x20;
      pbVar16 = param_3 + 3;
      local_1e8 = 0;
      local_1f0 = (float)param_3[1] - param_2[(int)pfStack_214 - 0x1c];
      local_1ec = g_flOne + (float)param_3[1] + param_2[(int)pfStack_214 - 0x1c];
      fVar6 = param_4[local_1d8];
      fVar7 = param_4[(int)pfStack_214 - 0x1c];
      goto LAB_006ff6f4;
    case (float *)0x23:
    case (float *)0x24:
    case (float *)0x25:
      local_1d8 = (int)pfStack_214 - 0x23;
      local_1f0 = (float)param_3[2] - param_2[(int)pfStack_214 - 0x1f];
      pbVar16 = param_3 + 7;
      local_1ec = (float)param_3[1] + param_2[(int)pfStack_214 - 0x1f];
      fVar6 = param_4[local_1d8];
      fVar7 = param_4[(int)pfStack_214 - 0x1f];
      local_1e8 = (uint)CONCAT11(param_3[3],param_3[4]);
      local_1f8 = (uint)CONCAT11(param_3[5],param_3[6]);
      goto LAB_006ff6f4;
    case (float *)0x26:
    case (float *)0x27:
    case (float *)0x28:
      pbVar16 = param_3 + 2;
      iVar14 = (int)pfStack_214 - 0x26;
      fVar6 = (float)param_3[1] - param_2[(int)pfStack_214 - 0x22];
      param_3 = param_3 + 3;
      fVar7 = (float)*pbVar16;
      goto LAB_006ffc8a;
    case (float *)0x29:
    case (float *)0x2a:
    case (float *)0x2b:
      pbVar16 = param_3 + 1;
      pbVar1 = param_3 + 2;
      pbVar2 = param_3 + 3;
      pbVar3 = param_3 + 5;
      iVar14 = (int)pfStack_214 - 0x29;
      pbVar4 = param_3 + 4;
      pbVar5 = param_3 + 6;
      param_3 = param_3 + 7;
      fVar6 = ((float)CONCAT21(CONCAT11(*pbVar16,*pbVar1),*pbVar2) * *(float *)(param_1 + 0x14) *
               param_2[10] - param_2[iVar14]) - param_2[(int)pfStack_214 - 0x25];
      fVar7 = (float)CONCAT21(CONCAT11(*pbVar4,*pbVar3),*pbVar5) * *(float *)(param_1 + 0x14) *
              param_2[10] - param_2[iVar14];
LAB_006ffc8a:
      fVar7 = fVar7 + param_2[iVar14 + 4];
      fVar8 = param_4[iVar14];
      fVar9 = param_4[iVar14 + 4];
      if (fVar9 <= fVar8) {
        if (fVar8 < fVar6) {
          return;
        }
        if (fVar7 < fVar9) {
          return;
        }
        iVar14 = 1;
      }
      else {
        if (fVar9 < fVar6) {
          return;
        }
        if (fVar7 < fVar8) {
          return;
        }
        iVar14 = 0;
      }
      local_170 = *param_4;
      local_16c = param_4[1];
      fVar12 = fVar8 - fVar7;
      local_168 = param_4[2];
      local_180 = (int *)param_4[4];
      local_164 = param_4[3];
      local_178 = param_4[6];
      local_17c = param_4[5];
      local_174 = param_4[7];
      if (fVar12 * (fVar9 - fVar7) < g_flZero) {
        fVar12 = fVar12 / (fVar12 - (fVar9 - fVar7));
        fVar7 = g_flOne - fVar12;
        param_4[iVar14 * -4 + 4] = fVar7 * local_170 + fVar12 * (float)local_180;
        param_4[iVar14 * -4 + 5] = local_16c * fVar7 + local_17c * fVar12;
        param_4[iVar14 * -4 + 6] = local_168 * fVar7 + local_178 * fVar12;
        param_4[iVar14 * -4 + 7] = local_164 * fVar7 + local_174 * fVar12;
      }
      fVar8 = fVar8 - fVar6;
      if (fVar8 * (fVar9 - fVar6) < g_flZero) {
        pfVar15 = param_4 + iVar14 * 4;
        fVar8 = fVar8 / (fVar8 - (fVar9 - fVar6));
        fVar6 = g_flOne - fVar8;
        *pfVar15 = fVar6 * local_170 + fVar8 * (float)local_180;
        pfVar15[1] = local_16c * fVar6 + local_17c * fVar8;
        pfVar15[2] = local_168 * fVar6 + local_178 * fVar8;
        pfVar15[3] = local_164 * fVar6 + local_174 * fVar8;
      }
      goto LAB_006ff716;
    default:
      uVar17 = (int)pfStack_214 - 0x30;
      goto LAB_007002db;
    case (float *)0x50:
      uVar17 = (uint)param_3[1];
      goto LAB_007002db;
    case (float *)0x51:
      uVar17 = (uint)CONCAT11(param_3[1],param_3[2]);
      goto LAB_007002db;
    case (float *)0x52:
      uVar17 = (uint)CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]);
      goto LAB_007002db;
    case (float *)0x53:
      uVar17 = (uint)param_3[4] + (uint)CONCAT11(param_3[1],param_3[2]) * 0x10000 +
               (uint)param_3[3] * 0x100;
LAB_007002db:
      iVar14 = *(int *)(param_1 + 0x2c);
      iVar18 = uVar17 + (int)param_2[0xb];
      piVar11 = *(int **)(**(int **)(iVar14 + 0x38) + 0xc);
      iStack_224 = *(int *)(iVar14 + 0x30);
      pfStack_21c = *(float **)(iVar14 + 0x38);
      uStack_220 = *(undefined4 *)(iVar14 + 0x34);
      puStack_228 = &local_181;
      pfStack_22c = (float *)0x700314;
      pbStack_218 = (byte *)piVar11;
      pfStack_214 = (float *)iVar18;
      pcVar13 = (char *)(**(code **)**(undefined4 **)(iStack_224 + 4))();
      if (*pcVar13 == '\0') {
        return;
      }
      pfStack_22c = local_128;
      uStack_234 = 0x70032d;
      iStack_230 = iVar18;
      local_180 = (int *)(**(code **)(*piVar11 + 0x34))();
      local_174 = *(float *)(*(int *)(iStack_204 + 0x2c) + 0x38);
      local_178 = *(float *)((int)local_174 + 8);
      uStack_234 = 0x70035d;
      local_17c = (float)iVar18;
      iVar14 = (**(code **)(*local_180 + 0x14))();
      uStack_234 = *(undefined4 *)(iStack_204 + 0x28);
      piStack_23c = *(int **)(*(int *)(iStack_204 + 0x2c) + 0x30);
      auStack_340[0x3f] = *(undefined4 *)(*(int *)(iStack_204 + 0x2c) + 0x34);
      uStack_238 = *(undefined4 *)(iStack_204 + 0x24);
      ppiStack_240 = &local_180;
      auStack_340[0x3e] = 0x700389;
      (**(code **)(*piStack_23c + 0x318c + (*(int *)(iStack_204 + 0x18) * 0x20 + iVar14) * 4))();
      *(undefined4 *)(iStack_204 + 0x1c) = *(undefined4 *)(*(int *)(iStack_204 + 0x24) + 4);
      return;
    case (float *)0x60:
    case (float *)0x61:
    case (float *)0x62:
    case (float *)0x63:
      pbVar16 = param_3 + 1;
      param_3 = param_3 + 2;
      auStack_340[(int)pfStack_214 + 8] = (uint)*pbVar16;
      goto LAB_0070021d;
    case (float *)0x64:
    case (float *)0x65:
    case (float *)0x66:
    case (float *)0x67:
      auStack_340[(int)pfStack_214 + 4] = (uint)CONCAT11(param_3[1],param_3[2]);
      param_3 = param_3 + 3;
      goto LAB_0070021d;
    case (float *)0x68:
    case (float *)0x69:
    case (float *)0x6a:
    case (float *)0x6b:
      auStack_340[(int)pfStack_214] =
           CONCAT31(CONCAT21(CONCAT11(param_3[1],param_3[2]),param_3[3]),param_3[4]);
      param_3 = param_3 + 5;
LAB_0070021d:
      if (param_2 != &local_1d0) {
        local_1d0 = *param_2;
        local_1cc = param_2[1];
        local_1c8 = param_2[2];
        local_1c4 = param_2[3];
        local_1c0 = param_2[4];
        local_1bc = param_2[5];
        local_1b8 = param_2[6];
        local_1b4 = param_2[7];
        local_1b0 = param_2[8];
        local_1ac = param_2[9];
        local_1a8 = param_2[10];
        local_1a4 = param_2[0xb];
        param_2 = &local_1d0;
      }
      goto LAB_006ff716;
    }
    local_1f8 = (uint)param_3[3];
    pbVar16 = param_3 + 4;
    local_1e8 = 0;
LAB_006ff6f4:
    if ((local_1f0 <= fVar7) || (local_1f0 <= fVar6)) {
      param_3 = pbVar16 + local_1f8;
      if ((fVar6 <= local_1ec) || (fVar7 <= local_1ec)) {
        local_150 = *param_4;
        fVar8 = fVar6 - local_1ec;
        local_14c = param_4[1];
        local_148 = param_4[2];
        fVar6 = fVar6 - local_1f0;
        local_144 = param_4[3];
        local_140 = param_4[4];
        local_13c = param_4[5];
        fVar9 = fVar7 - local_1ec;
        local_138 = param_4[6];
        local_134 = param_4[7];
        fVar7 = fVar7 - local_1f0;
        pfStack_21c = param_2;
        if (fVar9 <= fVar8) {
          if (fVar7 * fVar6 < g_flZero) {
            fVar6 = fVar6 / (fVar6 - fVar7);
            fVar7 = g_flOne - fVar6;
            local_140 = fVar7 * *param_4 + fVar6 * param_4[4];
            local_13c = fVar7 * param_4[1] + fVar6 * param_4[5];
            local_138 = fVar7 * param_4[2] + fVar6 * param_4[6];
            local_134 = fVar7 * param_4[3] + fVar6 * param_4[7];
          }
          pfStack_214 = &local_150;
          uStack_220 = 0x6ffa8d;
          pbStack_218 = param_3;
          FUN_006ff2f0();
          if (fVar9 * fVar8 < g_flZero) {
            fVar8 = fVar8 / (fVar8 - fVar9);
            fVar6 = g_flOne - fVar8;
            *param_4 = fVar6 * *param_4 + fVar8 * param_4[4];
            param_4[1] = fVar6 * param_4[1] + fVar8 * param_4[5];
            param_4[2] = fVar6 * param_4[2] + fVar8 * param_4[6];
            param_4[3] = fVar6 * param_4[3] + fVar8 * param_4[7];
          }
          if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x20)) {
            pfVar15 = *(float **)(param_1 + 0x2c);
            fVar6 = *(float *)(param_1 + 0x1c);
            fVar9 = g_flOne - fVar6;
            *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x1c);
            local_160 = fVar6 * pfVar15[4] + fVar9 * *pfVar15;
            local_15c = fVar6 * pfVar15[5] + fVar9 * pfVar15[1];
            local_158 = fVar6 * pfVar15[6] + fVar9 * pfVar15[2];
            fVar7 = pfVar15[3];
            fVar8 = pfVar15[7];
            pfVar15 = *(float **)(param_1 + 0x10);
            param_4[4] = local_160 - *pfVar15;
            param_4[5] = local_15c - pfVar15[1];
            param_4[6] = local_158 - pfVar15[2];
            param_4[7] = (fVar6 * fVar8 + fVar9 * fVar7) - pfVar15[3];
            fVar6 = param_2[10];
            param_4[4] = fVar6 * param_4[4];
            param_4[5] = fVar6 * param_4[5];
            param_4[6] = fVar6 * param_4[6];
            param_4[7] = fVar6 * param_4[7];
            param_4[4] = param_4[4] - *param_2;
            param_4[5] = param_4[5] - param_2[1];
            param_4[6] = param_4[6] - param_2[2];
            param_4[7] = param_4[7] - param_2[3];
            if ((local_1d8 < 3) && (local_1ec < param_4[local_1d8 + 4])) {
              return;
            }
          }
          param_3 = param_3 + (local_1e8 - local_1f8);
        }
        else {
          if (fVar9 * fVar8 < g_flZero) {
            fVar8 = fVar8 / (fVar8 - fVar9);
            fVar9 = g_flOne - fVar8;
            local_140 = fVar8 * param_4[4] + fVar9 * *param_4;
            local_13c = fVar9 * param_4[1] + fVar8 * param_4[5];
            local_138 = fVar9 * param_4[2] + fVar8 * param_4[6];
            local_134 = fVar9 * param_4[3] + fVar8 * param_4[7];
          }
          pfStack_214 = &local_150;
          pbStack_218 = param_3 + (local_1e8 - local_1f8);
          uStack_220 = 0x6ff8a0;
          FUN_006ff2f0();
          if (fVar7 * fVar6 < g_flZero) {
            fVar6 = fVar6 / (fVar6 - fVar7);
            fVar7 = g_flOne - fVar6;
            *param_4 = fVar6 * param_4[4] + fVar7 * *param_4;
            param_4[1] = fVar7 * param_4[1] + fVar6 * param_4[5];
            param_4[2] = fVar7 * param_4[2] + fVar6 * param_4[6];
            param_4[3] = fVar7 * param_4[3] + fVar6 * param_4[7];
          }
          if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x20)) {
            pfVar15 = *(float **)(param_1 + 0x2c);
            fVar6 = *(float *)(param_1 + 0x1c);
            fVar9 = g_flOne - fVar6;
            *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x1c);
            local_130 = fVar6 * pfVar15[4] + fVar9 * *pfVar15;
            local_12c = fVar6 * pfVar15[5] + fVar9 * pfVar15[1];
            local_128[0] = fVar6 * pfVar15[6] + fVar9 * pfVar15[2];
            fVar7 = pfVar15[3];
            fVar8 = pfVar15[7];
            pfVar15 = *(float **)(param_1 + 0x10);
            param_4[4] = local_130 - *pfVar15;
            param_4[5] = local_12c - pfVar15[1];
            param_4[6] = local_128[0] - pfVar15[2];
            param_4[7] = (fVar6 * fVar8 + fVar9 * fVar7) - pfVar15[3];
            fVar6 = param_2[10];
            param_4[4] = fVar6 * param_4[4];
            param_4[5] = fVar6 * param_4[5];
            param_4[6] = fVar6 * param_4[6];
            param_4[7] = fVar6 * param_4[7];
            param_4[4] = param_4[4] - *param_2;
            param_4[5] = param_4[5] - param_2[1];
            param_4[6] = param_4[6] - param_2[2];
            param_4[7] = param_4[7] - param_2[3];
            if ((local_1d8 < 3) && (param_4[local_1d8 + 4] < local_1f0)) {
switchD_006ff327_caseD_0:
              return;
            }
          }
        }
      }
    }
    else {
      param_3 = pbVar16 + local_1e8;
    }
LAB_006ff716:
    bVar10 = *param_3;
  }
switchD_006ff327_caseD_8:
  pbStack_218 = (byte *)0xa0e298;
  pfStack_21c = (float *)0x6ff73b;
  pfStack_21c = (float *)(**(code **)(*DAT_00d030e0 + 4))();
  uStack_220 = 0x6ff741;
  FUN_00631f10();
  pfStack_214 = (float *)0x6ff74f;
  (**(code **)(*DAT_00d030e0 + 4))();
  pfStack_214 = (float *)0x6ff756;
  FUN_00631f70();
  _DAT_00000000 = 0;
  return;
}
```
