# Raw capture: FUN_006fde40

| Field | Value |
|---|---|
| **Stable ID** | `aa_006fde40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006fde40` |
| **Canonical name** | `FUN_006fde40` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_006fde40(uint *param_1,int *param_2,int *param_3,float *param_4,int param_5,float *param_6)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  char cVar14;
  uint uVar15;
  bool bVar16;
  float *pfVar17;
  float *pfVar18;
  uint uVar19;
  undefined2 *puVar20;
  float *pfVar21;
  float *pfVar22;
  uint uVar23;
  int iVar24;
  uint *puVar25;
  int iVar26;
  uint *unaff_EDI;
  uint *puVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 *puStack_f4;
  float fStack_ec;
  uint *local_e8;
  float fStack_e4;
  float fStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d4;
  uint uStack_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_b8;
  float local_b4;
  float fStack_b0;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_40;
  float fStack_30;
  
  *param_1 = (int)*(char *)(param_5 + 8);
  local_e8 = param_1 + 1;
  *local_e8 = (int)*(char *)(param_5 + 9);
  pfVar1 = (float *)(param_1 + 8);
  local_b4 = 0.0;
  local_d4 = 0x2edbe6ff;
  (**(code **)(*param_2 + 0x34))(param_5,*param_1,pfVar1);
  (**(code **)(*param_3 + 0x34))(param_5 + *param_1 * 2,*puStack_f4,param_1 + 0x38);
  uVar19 = *unaff_EDI;
  iVar24 = uVar19 - 1;
  pfVar22 = (float *)(param_1 + 0x28);
  pfVar18 = (float *)(param_1 + 0x38);
  if (3 < (int)uVar19) {
    puStack_f4 = (undefined4 *)(uVar19 >> 2);
    iVar24 = iVar24 + (int)puStack_f4 * -4;
    pfVar17 = pfVar18;
    pfVar21 = (float *)(param_1 + 0x2e);
    do {
      fVar2 = *pfVar17;
      fVar3 = pfVar17[1];
      fVar4 = pfVar17[2];
      *pfVar22 = fVar3 * param_4[4] + fVar4 * param_4[8] + fVar2 * *param_4 + param_4[0xc];
      pfVar21[-5] = fVar3 * param_4[5] + fVar4 * param_4[9] + fVar2 * param_4[1] + param_4[0xd];
      pfVar21[-4] = fVar3 * param_4[6] + fVar4 * param_4[10] + fVar2 * param_4[2] + param_4[0xe];
      pfVar21[-3] = 0.0;
      fVar2 = pfVar17[4];
      fVar3 = pfVar17[5];
      fVar4 = pfVar17[6];
      pfVar21[-2] = fVar3 * param_4[4] + fVar4 * param_4[8] + fVar2 * *param_4 + param_4[0xc];
      pfVar21[-1] = fVar3 * param_4[5] + fVar4 * param_4[9] + fVar2 * param_4[1] + param_4[0xd];
      *pfVar21 = fVar3 * param_4[6] + fVar4 * param_4[10] + fVar2 * param_4[2] + param_4[0xe];
      pfVar21[1] = 0.0;
      fVar2 = pfVar17[8];
      fVar3 = pfVar17[9];
      fVar4 = pfVar17[10];
      pfVar21[2] = fVar3 * param_4[4] + fVar4 * param_4[8] + fVar2 * *param_4 + param_4[0xc];
      pfVar18 = pfVar17 + 0x10;
      pfVar21[3] = fVar3 * param_4[5] + fVar4 * param_4[9] + fVar2 * param_4[1] + param_4[0xd];
      pfVar21[4] = fVar3 * param_4[6] + fVar4 * param_4[10] + fVar2 * param_4[2] + param_4[0xe];
      pfVar21[5] = 0.0;
      fVar2 = pfVar17[0xc];
      fVar3 = pfVar17[0xd];
      fVar4 = pfVar17[0xe];
      pfVar21[6] = fVar3 * param_4[4] + fVar4 * param_4[8] + fVar2 * *param_4 + param_4[0xc];
      pfVar21[7] = fVar3 * param_4[5] + fVar4 * param_4[9] + fVar2 * param_4[1] + param_4[0xd];
      pfVar21[8] = fVar3 * param_4[6] + fVar4 * param_4[10] + fVar2 * param_4[2] + param_4[0xe];
      pfVar21[9] = 0.0;
      pfVar22 = pfVar22 + 0x10;
      puStack_f4 = (undefined4 *)((int)puStack_f4 - 1);
      pfVar17 = pfVar18;
      pfVar21 = pfVar21 + 0x10;
    } while (puStack_f4 != (undefined4 *)0x0);
  }
  if (-1 < iVar24) {
    iVar24 = iVar24 + 1;
    do {
      fVar2 = *pfVar18;
      fVar3 = pfVar18[1];
      iVar24 = iVar24 + -1;
      fVar4 = pfVar18[2];
      *pfVar22 = fVar3 * param_4[4] + fVar4 * param_4[8] + fVar2 * *param_4 + param_4[0xc];
      pfVar22[1] = fVar3 * param_4[5] + fVar4 * param_4[9] + fVar2 * param_4[1] + param_4[0xd];
      pfVar22[2] = fVar3 * param_4[6] + fVar4 * param_4[10] + fVar2 * param_4[2] + param_4[0xe];
      pfVar22[3] = 0.0;
      pfVar18 = pfVar18 + 4;
      pfVar22 = pfVar22 + 4;
    } while (iVar24 != 0);
  }
  uVar29 = 0;
LAB_006fe0d0:
  fStack_ec = fStack_ec + fStack_ec;
  uStack_cc = uStack_cc + 1;
  uVar19 = *param_1 << 3 | *unaff_EDI;
  param_1[4] = 0;
  while (uVar19 - 9 < 0x19) {
    switch((&switchD_006fe108::switchdataD_006ff2a0)
           [(&switchD_006fe108::switchdataD_006ff2cc)[uVar19 - 9]]) {
    case (undefined *)0x6fe10f:
      uVar28 = 8;
      uVar19 = param_1[2];
      pfVar22 = (float *)(param_1 + 0x28);
      pfVar18 = pfVar1;
      puVar25 = param_1;
      puVar27 = unaff_EDI;
      goto LAB_006fe14d;
    case (undefined *)0x6fe12f:
      uVar28 = 0xfffffff8;
      uVar19 = param_1[2];
      pfVar18 = (float *)(param_1 + 0x28);
      pfVar22 = pfVar1;
      puVar25 = unaff_EDI;
      puVar27 = param_1;
LAB_006fe14d:
      iVar24 = FUN_006fc000(pfVar18,pfVar22,puVar25,puVar27,uVar19 == 2,uVar28);
      if (iVar24 != 1) {
        if (iVar24 == 2) {
switchD_006fe108_caseD_6fe162:
          fStack_88 = (float)param_1[0xc] - *pfVar1;
          fStack_84 = (float)param_1[0xd] - (float)param_1[9];
          fStack_80 = (float)param_1[0xe] - (float)param_1[10];
          fStack_7c = (float)param_1[0xf] - (float)param_1[0xb];
          fStack_78 = (float)param_1[0x2c] - (float)param_1[0x28];
          fStack_74 = (float)param_1[0x2d] - (float)param_1[0x29];
          fStack_70 = (float)param_1[0x2e] - (float)param_1[0x2a];
          fStack_6c = (float)param_1[0x2f] - (float)param_1[0x2b];
          uVar19 = FUN_006f6ef0(pfVar1,&fStack_88,param_1 + 0x28,&fStack_78,param_1 + 0x4c);
          if (uVar19 != 0) {
            if ((uVar19 & 1) == 0) {
              if ((uVar19 & 2) != 0) goto LAB_006fe224;
            }
            else {
              *pfVar1 = (float)param_1[0xc];
              param_1[9] = param_1[0xd];
              param_1[10] = param_1[0xe];
              param_1[0xb] = param_1[0xf];
LAB_006fe224:
              *param_1 = 1;
            }
            if ((uVar19 & 4) == 0) {
              if ((uVar19 & 8) != 0) {
                *unaff_EDI = 1;
              }
            }
            else {
              param_1[0x28] = param_1[0x2c];
              param_1[0x29] = param_1[0x2d];
              param_1[0x2a] = param_1[0x2e];
              param_1[0x2b] = param_1[0x2f];
              param_1[0x38] = param_1[0x3c];
              param_1[0x39] = param_1[0x3d];
              param_1[0x3a] = param_1[0x3e];
              param_1[0x3b] = param_1[0x3f];
              *unaff_EDI = 1;
            }
            goto LAB_006fe6de;
          }
          param_1[0x4b] = 0;
          param_1[0x48] = (uint)(fStack_70 * fStack_84 - fStack_74 * fStack_80);
          param_1[0x49] = (uint)(fStack_78 * fStack_80 - fStack_88 * fStack_70);
          param_1[0x4a] = (uint)(fStack_88 * fStack_74 - fStack_78 * fStack_84);
          if ((*pfVar1 - (float)param_1[0x28]) * (float)param_1[0x48] +
              ((float)param_1[9] - (float)param_1[0x29]) * (float)param_1[0x49] +
              ((float)param_1[10] - (float)param_1[0x2a]) * (float)param_1[0x4a] < g_flZero)
          goto LAB_006fee17;
          param_1[0x48] = (uint)-(float)param_1[0x48];
          param_1[0x49] = (uint)-(float)param_1[0x49];
          param_1[0x4a] = (uint)-(float)param_1[0x4a];
          fVar2 = -(float)param_1[0x4b];
          goto LAB_006fee11;
        }
        goto LAB_006fee17;
      }
      goto switchD_006fe108_caseD_6fe6f7;
    case (undefined *)0x6fe162:
      goto switchD_006fe108_caseD_6fe162;
    case (undefined *)0x6fe2b4:
      iVar24 = FUN_006fbc20(0xbf800000);
      if (iVar24 < 0) goto switchD_006fe108_caseD_6fe6f7;
      *unaff_EDI = *unaff_EDI - 1;
      iVar26 = iVar24 + 10;
      param_1[iVar26 * 4] = param_1[0x34];
      param_1[iVar26 * 4 + 1] = param_1[0x35];
      param_1[iVar26 * 4 + 2] = param_1[0x36];
      param_1[iVar26 * 4 + 3] = param_1[0x37];
      puVar25 = param_1 + (iVar24 + 0xe) * 4;
      *puVar25 = param_1[0x44];
      puVar25[1] = param_1[0x45];
      puVar25[2] = param_1[0x46];
      puVar25[3] = param_1[0x47];
    case (undefined *)0x6fe32e:
      iVar24 = FUN_006fb890(pfVar1,param_1 + 0x28,8);
      if (iVar24 == 0xe) {
LAB_006fee17:
        param_1[2] = *unaff_EDI;
        bVar16 = false;
        goto LAB_006fe700;
      }
      iVar24 = (int)(char)(&DAT_00a0eeec)[iVar24];
      if (iVar24 < 0) {
        iVar24 = iVar24 + 8;
        if (3 < iVar24) {
          iVar24 = 1;
        }
        *unaff_EDI = *unaff_EDI - 1;
        iVar26 = iVar24 + 10;
        param_1[iVar26 * 4] = param_1[0x30];
        param_1[iVar26 * 4 + 1] = param_1[0x31];
        param_1[iVar26 * 4 + 2] = param_1[0x32];
        param_1[iVar26 * 4 + 3] = param_1[0x33];
        puVar25 = param_1 + (iVar24 + 0xe) * 4;
        *puVar25 = param_1[0x40];
        puVar25[1] = param_1[0x41];
        puVar25[2] = param_1[0x42];
        puVar25[3] = param_1[0x43];
switchD_006fe108_caseD_6fea14:
        fVar2 = (float)param_1[0x2c] - (float)param_1[0x28];
        fVar3 = (float)param_1[0x2d] - (float)param_1[0x29];
        fStack_40 = (float)param_1[0x2e] - (float)param_1[0x2a];
        fStack_a8 = (float)param_1[0x2c] - *pfVar1;
        fStack_a4 = (float)param_1[0x2d] - (float)param_1[9];
        fStack_a0 = (float)param_1[0x2e] - (float)param_1[10];
        fStack_c8 = (float)param_1[0x28] - *pfVar1;
        fStack_c4 = (float)param_1[0x29] - (float)param_1[9];
        fStack_c0 = (float)param_1[0x2a] - (float)param_1[10];
        if (g_flZero <= fStack_a8 * fVar2 + fStack_a4 * fVar3 + fStack_a0 * fStack_40) {
          iVar24 = 0;
        }
        else {
          iVar24 = 8;
        }
        if (g_flZero <= fStack_c8 * fVar2 + fStack_c4 * fVar3 + fStack_c0 * fStack_40) {
          iVar26 = 0;
        }
        else {
          iVar26 = 8;
        }
        if (iVar24 == iVar26) {
          if (iVar24 != 0) {
            param_1[0x28] = param_1[0x2c];
            param_1[0x29] = param_1[0x2d];
            param_1[0x2a] = param_1[0x2e];
            param_1[0x2b] = param_1[0x2f];
            param_1[0x38] = param_1[0x3c];
            param_1[0x39] = param_1[0x3d];
            param_1[0x3a] = param_1[0x3e];
            param_1[0x3b] = param_1[0x3f];
          }
          *unaff_EDI = *unaff_EDI - 1;
switchD_006fe108_caseD_6feddc:
          param_1[0x48] = (uint)((float)param_1[0x28] - *pfVar1);
          param_1[0x49] = (uint)((float)param_1[0x29] - (float)param_1[9]);
          param_1[0x4a] = (uint)((float)param_1[0x2a] - (float)param_1[10]);
          fVar2 = (float)param_1[0x2b] - (float)param_1[0xb];
LAB_006fee11:
          param_1[0x4b] = (uint)fVar2;
          goto LAB_006fee17;
        }
        param_1[0x4b] = 0;
        bVar16 = false;
        fVar8 = fStack_c0 * fStack_a4 - fStack_c4 * fStack_a0;
        fVar9 = fStack_c8 * fStack_a0 - fStack_a8 * fStack_c0;
        fVar4 = fStack_a8 * fStack_c4 - fStack_c8 * fStack_a4;
        param_1[0x48] = (uint)(fVar9 * fStack_40 - fVar4 * fVar3);
        param_1[0x49] = (uint)(fVar2 * fVar4 - fVar8 * fStack_40);
        param_1[0x4a] = (uint)(fVar8 * fVar3 - fVar2 * fVar9);
        param_1[2] = *unaff_EDI;
        goto LAB_006fe700;
      }
      uVar23 = (uint)(char)(&DAT_00a0eefc)[iVar24];
      fVar2 = *pfVar1;
      uVar19 = (uint)(char)(&DAT_00a0eefe)[iVar24];
      pfVar22 = (float *)(param_1 + (iVar24 + 10) * 4);
      fVar3 = *pfVar22;
      fVar4 = (float)param_1[9];
      pfVar18 = (float *)(param_1 + (uVar23 + 10) * 4);
      fVar8 = pfVar22[1];
      fVar9 = (float)param_1[10];
      fVar10 = pfVar22[2];
      pfVar17 = (float *)(param_1 + (uVar19 + 10) * 4);
      fStack_58 = *pfVar17 - *pfVar22;
      fStack_54 = pfVar17[1] - pfVar22[1];
      fStack_50 = pfVar17[2] - pfVar22[2];
      if (g_flZero <=
          (*pfVar18 - *pfVar22) * (fVar2 - fVar3) +
          (pfVar18[1] - pfVar22[1]) * (fVar4 - fVar8) + (pfVar18[2] - pfVar22[2]) * (fVar9 - fVar10)
         ) {
        *unaff_EDI = 2;
        *pfVar17 = (float)param_1[0x30];
        pfVar17[1] = (float)param_1[0x31];
        pfVar17[2] = (float)param_1[0x32];
        pfVar17[3] = (float)param_1[0x33];
        puVar25 = param_1 + (uVar19 + 0xe) * 4;
        *puVar25 = param_1[0x40];
        puVar25[1] = param_1[0x41];
        puVar25[2] = param_1[0x42];
        puVar25[3] = param_1[0x43];
      }
      else {
        *unaff_EDI = 2;
        *pfVar18 = (float)param_1[0x30];
        pfVar18[1] = (float)param_1[0x31];
        pfVar18[2] = (float)param_1[0x32];
        pfVar18[3] = (float)param_1[0x33];
        puVar25 = param_1 + (uVar23 + 0xe) * 4;
        *puVar25 = param_1[0x40];
        puVar25[1] = param_1[0x41];
        bVar16 = fStack_58 * (fVar2 - fVar3) +
                 fStack_54 * (fVar4 - fVar8) + fStack_50 * (fVar9 - fVar10) < g_flZero;
        puVar25[2] = param_1[0x42];
        puVar25[3] = param_1[0x43];
        if (bVar16) {
          uVar15 = *unaff_EDI;
          if (uVar19 == uVar15) {
            uVar19 = uVar23;
          }
          *unaff_EDI = uVar15 - 1;
          iVar24 = uVar15 + 9;
          puVar25 = param_1 + (uVar19 + 10) * 4;
          *puVar25 = param_1[iVar24 * 4];
          puVar25[1] = param_1[iVar24 * 4 + 1];
          puVar25[2] = param_1[iVar24 * 4 + 2];
          puVar25[3] = param_1[iVar24 * 4 + 3];
          iVar24 = *unaff_EDI + 0xe;
          iVar26 = uVar19 + 0xe;
LAB_006fe6a4:
          puVar25 = param_1 + iVar24 * 4;
          puVar27 = param_1 + iVar26 * 4;
          *puVar27 = *puVar25;
          puVar27[1] = puVar25[1];
          puVar27[2] = puVar25[2];
          puVar27[3] = puVar25[3];
        }
      }
LAB_006fe6de:
      uVar19 = *param_1 << 3 | *unaff_EDI;
      break;
    case (undefined *)0x6fe536:
      iVar24 = FUN_006fbc20(0x3f800000);
      if (-1 < iVar24) {
        *param_1 = *param_1 - 1;
        puVar25 = param_1 + (iVar24 + 2) * 4;
        *puVar25 = param_1[0x14];
        puVar25[1] = param_1[0x15];
        puVar25[2] = param_1[0x16];
        puVar25[3] = param_1[0x17];
switchD_006fe108_caseD_6fe574:
        iVar24 = FUN_006fb890(param_1 + 0x28,pfVar1,0xfffffff8);
        if (iVar24 == 0xe) goto LAB_006fee17;
        iVar24 = (int)(char)(&DAT_00a0eeec)[iVar24];
        if (-1 < iVar24) {
          cVar14 = (&DAT_00a0eefc)[iVar24];
          fVar2 = (float)param_1[0x28];
          uVar19 = (uint)(char)(&DAT_00a0eefe)[iVar24];
          pfVar22 = (float *)(param_1 + (iVar24 + 2) * 4);
          fVar3 = *pfVar22;
          fVar4 = (float)param_1[0x29];
          pfVar18 = (float *)(param_1 + ((int)cVar14 + 2U) * 4);
          fVar8 = pfVar22[1];
          fVar9 = (float)param_1[0x2a];
          fVar10 = pfVar22[2];
          fVar11 = *pfVar18;
          pfVar17 = (float *)(param_1 + (uVar19 + 2) * 4);
          fVar12 = *pfVar22;
          fVar13 = pfVar18[1];
          fVar5 = pfVar22[1];
          fVar6 = pfVar18[2];
          fVar7 = pfVar22[2];
          fStack_68 = *pfVar17 - *pfVar22;
          fStack_64 = pfVar17[1] - pfVar22[1];
          fStack_60 = pfVar17[2] - pfVar22[2];
          *param_1 = 2;
          if ((fVar11 - fVar12) * (fVar2 - fVar3) +
              (fVar13 - fVar5) * (fVar4 - fVar8) + (fVar6 - fVar7) * (fVar9 - fVar10) < g_flZero) {
            *pfVar18 = (float)param_1[0x10];
            pfVar18[1] = (float)param_1[0x11];
            pfVar18[2] = (float)param_1[0x12];
            pfVar18[3] = (float)param_1[0x13];
            if (g_flZero <=
                fStack_68 * (fVar2 - fVar3) +
                fStack_64 * (fVar4 - fVar8) + fStack_60 * (fVar9 - fVar10)) goto LAB_006fe6de;
            uVar23 = *param_1;
            if (uVar19 == uVar23) {
              uVar19 = (int)cVar14;
            }
            *param_1 = uVar23 - 1;
            iVar24 = uVar23 + 1;
            iVar26 = uVar19 + 2;
            goto LAB_006fe6a4;
          }
          *pfVar17 = (float)param_1[0x10];
          pfVar17[1] = (float)param_1[0x11];
          pfVar17[2] = (float)param_1[0x12];
          pfVar17[3] = (float)param_1[0x13];
          goto LAB_006fe6de;
        }
        iVar24 = iVar24 + 8;
        if (3 < iVar24) {
          iVar24 = 1;
        }
        *param_1 = *param_1 - 1;
        puVar25 = param_1 + (iVar24 + 2) * 4;
        *puVar25 = param_1[0x10];
        puVar25[1] = param_1[0x11];
        puVar25[2] = param_1[0x12];
        puVar25[3] = param_1[0x13];
switchD_006fe108_caseD_6fec24:
        fVar2 = (float)param_1[0xc] - *pfVar1;
        fVar3 = (float)param_1[0xd] - (float)param_1[9];
        fStack_30 = (float)param_1[0xe] - (float)param_1[10];
        fStack_98 = (float)param_1[0xc] - (float)param_1[0x28];
        fStack_94 = (float)param_1[0xd] - (float)param_1[0x29];
        fStack_90 = (float)param_1[0xe] - (float)param_1[0x2a];
        fStack_b8 = *pfVar1 - (float)param_1[0x28];
        local_b4 = (float)param_1[9] - (float)param_1[0x29];
        fStack_b0 = (float)param_1[10] - (float)param_1[0x2a];
        if (g_flZero <= fStack_98 * fVar2 + fStack_94 * fVar3 + fStack_90 * fStack_30) {
          iVar24 = 0;
        }
        else {
          iVar24 = 8;
        }
        if (g_flZero <= fStack_b8 * fVar2 + local_b4 * fVar3 + fStack_b0 * fStack_30) {
          iVar26 = 0;
        }
        else {
          iVar26 = 8;
        }
        if (iVar24 == iVar26) {
          if (iVar24 != 0) {
            *pfVar1 = (float)param_1[0xc];
            param_1[9] = param_1[0xd];
            param_1[10] = param_1[0xe];
            param_1[0xb] = param_1[0xf];
            param_1[0x18] = param_1[0x1c];
            param_1[0x19] = param_1[0x1d];
            param_1[0x1a] = param_1[0x1e];
            param_1[0x1b] = param_1[0x1f];
          }
          *param_1 = *param_1 - 1;
          goto switchD_006fe108_caseD_6feddc;
        }
        param_1[0x4b] = 0;
        bVar16 = false;
        fVar8 = fStack_b0 * fStack_94 - local_b4 * fStack_90;
        fVar9 = fStack_b8 * fStack_90 - fStack_98 * fStack_b0;
        fVar4 = fStack_98 * local_b4 - fStack_b8 * fStack_94;
        param_1[0x48] = (uint)(fVar4 * fVar3 - fVar9 * fStack_30);
        param_1[0x49] = (uint)(fVar8 * fStack_30 - fVar2 * fVar4);
        param_1[0x4a] = (uint)(fVar2 * fVar9 - fVar8 * fVar3);
        param_1[2] = *unaff_EDI;
        goto LAB_006fe700;
      }
      goto switchD_006fe108_caseD_6fe6f7;
    case (undefined *)0x6fe574:
      goto switchD_006fe108_caseD_6fe574;
    case (undefined *)0x6fe6f7:
      goto switchD_006fe108_caseD_6fe6f7;
    case (undefined *)0x6fea14:
      goto switchD_006fe108_caseD_6fea14;
    case (undefined *)0x6fec24:
      goto switchD_006fe108_caseD_6fec24;
    case (undefined *)0x6feddc:
      goto switchD_006fe108_caseD_6feddc;
    }
  }
switchD_006fe108_caseD_6fe6f7:
  bVar16 = true;
LAB_006fe700:
  fVar2 = (float)param_1[0x4a] * (float)param_1[0x4a] +
          (float)param_1[0x49] * (float)param_1[0x49] + (float)param_1[0x48] * (float)param_1[0x48];
  fVar3 = ((float)param_1[0x28] - *pfVar1) * (float)param_1[0x48] +
          ((float)param_1[0x29] - (float)param_1[9]) * (float)param_1[0x49] +
          ((float)param_1[0x2a] - (float)param_1[10]) * (float)param_1[0x4a];
  if ((bVar16) || (fVar3 * fVar3 * fVar3 <= fStack_ec * _DAT_00a0f008 * fVar2)) {
    if ((char)param_1[3] == '\0') {
      uVar29 = FUN_006fc8d0(param_2,param_3,param_4,param_5);
    }
    else {
      if (4 < (int)(*unaff_EDI + *param_1)) {
        if ((int)*unaff_EDI < (int)*param_1) {
          *param_1 = 3;
          *unaff_EDI = 1;
        }
        else {
          *param_1 = 1;
          *unaff_EDI = 3;
        }
      }
      uVar29 = 3;
    }
LAB_006ff195:
    fVar2 = (float)param_1[0x28];
    fVar3 = *pfVar1;
    fVar4 = (float)param_1[0x29];
    fVar8 = (float)param_1[9];
    fVar9 = (float)param_1[0x2a];
    fVar10 = (float)param_1[10];
    fVar11 = (float)param_1[0x4a];
    fVar12 = (float)param_1[0x49];
    fVar13 = (float)param_1[0x48];
    fVar6 = (float)param_1[0x4a] * (float)param_1[0x4a] +
            (float)param_1[0x49] * (float)param_1[0x49] +
            (float)param_1[0x48] * (float)param_1[0x48];
    fVar5 = g_flZero;
    if (fVar6 != g_flZero) {
      fVar5 = g_flOne / SQRT(fVar6);
    }
    *param_6 = fVar5 * (float)param_1[0x48];
    param_6[1] = fVar5 * (float)param_1[0x49];
    param_6[2] = fVar5 * (float)param_1[0x4a];
    param_6[3] = fVar5 * (float)param_1[0x4b];
    param_6[3] = fVar5 * ((fVar2 - fVar3) * fVar13 +
                         (fVar4 - fVar8) * fVar12 + (fVar9 - fVar10) * fVar11);
    *(char *)(param_5 + 8) = (char)*param_1;
    *(char *)(param_5 + 9) = (char)*unaff_EDI;
    iVar24 = 0;
    puVar25 = param_1 + 0xb;
    do {
      *(short *)(param_5 + iVar24 * 2) = (short)*puVar25;
      iVar24 = iVar24 + 1;
      puVar25 = puVar25 + 4;
    } while (iVar24 < (int)*param_1);
    iVar26 = 0;
    puVar20 = (undefined2 *)(param_5 + iVar24 * 2);
    param_1 = param_1 + 0x3b;
    do {
      *puVar20 = (short)*param_1;
      puVar20 = puVar20 + 1;
      iVar26 = iVar26 + 1;
      param_1 = param_1 + 4;
    } while (iVar26 < (int)*unaff_EDI);
    return uVar29;
  }
  fVar2 = fVar2 * fStack_ec;
  uVar19 = uStack_cc & 1;
  if (((uVar19 != 0) && (*param_1 != (int)*(char *)(param_5 + 10))) && (param_1[4] != 8)) {
    (**(code **)(*param_2 + 0x30))(param_1 + 0x48,param_1 + (*param_1 + 2) * 4);
    uVar23 = *param_1;
    pfVar22 = (float *)(param_1 + (uVar23 + 2) * 4);
    fVar3 = ((float)param_1[(uVar23 + 2) * 4] - *pfVar1) * (float)param_1[0x48] +
            (pfVar22[1] - (float)param_1[9]) * (float)param_1[0x49] +
            (pfVar22[2] - (float)param_1[10]) * (float)param_1[0x4a];
    if (fVar2 < ABS(fVar3) * fVar3) {
      if (uVar23 == 2) {
LAB_006fe86e:
        fVar3 = (*pfVar22 - (float)param_1[0xc]) * (float)param_1[0x48] +
                (pfVar22[1] - (float)param_1[0xd]) * (float)param_1[0x49] +
                (pfVar22[2] - (float)param_1[0xe]) * (float)param_1[0x4a];
        if (ABS(fVar3) * fVar3 < fVar2) goto LAB_006fee27;
      }
      else if (uVar23 == 3) {
        fVar3 = (*pfVar22 - (float)param_1[0x10]) * (float)param_1[0x48] +
                (pfVar22[1] - (float)param_1[0x11]) * (float)param_1[0x49] +
                (pfVar22[2] - (float)param_1[0x12]) * (float)param_1[0x4a];
        if (ABS(fVar3) * fVar3 < fVar2) goto LAB_006fee27;
        goto LAB_006fe86e;
      }
      *param_1 = uVar23 + 1;
      goto LAB_006fe0d0;
    }
  }
LAB_006fee27:
  if ((*unaff_EDI == (int)*(char *)(param_5 + 0xb)) || (param_1[4] == 0xfffffff8)) {
LAB_006ff01c:
    if (((uVar19 != 0) || (*param_1 == (int)*(char *)(param_5 + 10))) || (param_1[4] == 8))
    goto LAB_006ff195;
    (**(code **)(*param_2 + 0x30))(param_1 + 0x48,param_1 + (*param_1 + 2) * 4);
    uVar19 = *param_1;
    pfVar22 = (float *)(param_1 + (uVar19 + 2) * 4);
    fVar3 = ((float)param_1[(uVar19 + 2) * 4] - *pfVar1) * (float)param_1[0x48] +
            (pfVar22[1] - (float)param_1[9]) * (float)param_1[0x49] +
            (pfVar22[2] - (float)param_1[10]) * (float)param_1[0x4a];
    if (ABS(fVar3) * fVar3 <= fVar2) goto LAB_006ff195;
    if (uVar19 == 2) {
LAB_006ff0f8:
      fVar3 = (*pfVar22 - (float)param_1[0xc]) * (float)param_1[0x48] +
              (pfVar22[1] - (float)param_1[0xd]) * (float)param_1[0x49] +
              (pfVar22[2] - (float)param_1[0xe]) * (float)param_1[0x4a];
      if (ABS(fVar3) * fVar3 < fVar2) goto LAB_006ff195;
    }
    else if (uVar19 == 3) {
      fVar3 = (*pfVar22 - (float)param_1[0x10]) * (float)param_1[0x48] +
              (pfVar22[1] - (float)param_1[0x11]) * (float)param_1[0x49] +
              (pfVar22[2] - (float)param_1[0x12]) * (float)param_1[0x4a];
      if (fVar2 <= ABS(fVar3) * fVar3) goto LAB_006ff0f8;
      goto LAB_006ff195;
    }
    *param_1 = uVar19 + 1;
  }
  else {
    fVar3 = (float)param_1[0x48];
    fVar4 = (float)param_1[0x49];
    fVar8 = (float)param_1[0x4a];
    uStack_dc = 0;
    local_e8 = (uint *)-(fVar3 * *param_4 + fVar4 * param_4[1] + fVar8 * param_4[2]);
    fStack_e4 = -(fVar3 * param_4[4] + fVar4 * param_4[5] + fVar8 * param_4[6]);
    fStack_e0 = -(fVar3 * param_4[8] + fVar4 * param_4[9] + fVar8 * param_4[10]);
    (**(code **)(*param_3 + 0x30))(&local_e8,param_1 + (*unaff_EDI + 0xe) * 4);
    uVar23 = *unaff_EDI;
    pfVar22 = (float *)(param_1 + (uVar23 + 0xe) * 4);
    fVar3 = (pfVar22[1] - (float)param_1[0x39]) * fStack_e4 +
            (pfVar22[2] - (float)param_1[0x3a]) * fStack_e0 +
            ((float)param_1[(uVar23 + 0xe) * 4] - (float)param_1[0x38]) * (float)local_e8;
    if (ABS(fVar3) * fVar3 <= fVar2) goto LAB_006ff01c;
    if (uVar23 == 2) {
LAB_006fef74:
      fVar3 = (pfVar22[1] - (float)param_1[0x3d]) * fStack_e4 +
              (pfVar22[2] - (float)param_1[0x3e]) * fStack_e0 +
              (float)local_e8 * (*pfVar22 - (float)param_1[0x3c]);
      if (ABS(fVar3) * fVar3 < fVar2) goto LAB_006ff01c;
    }
    else if (uVar23 == 3) {
      fVar3 = (pfVar22[1] - (float)param_1[0x41]) * fStack_e4 +
              (pfVar22[2] - (float)param_1[0x42]) * fStack_e0 +
              (float)local_e8 * (*pfVar22 - (float)param_1[0x40]);
      if (ABS(fVar3) * fVar3 < fVar2) goto LAB_006ff01c;
      goto LAB_006fef74;
    }
    fVar2 = *pfVar22;
    fVar3 = pfVar22[1];
    fVar4 = pfVar22[2];
    pfVar22 = (float *)(param_1 + (uVar23 + 10) * 4);
    *pfVar22 = fVar2 * *param_4 + fVar3 * param_4[4] + fVar4 * param_4[8] + param_4[0xc];
    pfVar22[1] = fVar3 * param_4[5] + fVar4 * param_4[9] + fVar2 * param_4[1] + param_4[0xd];
    pfVar22[2] = fVar3 * param_4[6] + fVar4 * param_4[10] + fVar2 * param_4[2] + param_4[0xe];
    pfVar22[3] = 0.0;
    *unaff_EDI = *unaff_EDI + 1;
  }
  goto LAB_006fe0d0;
}
```
