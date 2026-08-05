# Raw capture: FUN_005bc3c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bc3c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005bc3c0` |
| **Canonical name** | `FUN_005bc3c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x005bd8bf) */
/* WARNING: Removing unreachable block (ram,0x005bd8fc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005bc3c0(int *param_1,float *param_2,int param_3,int param_4)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  ushort uVar4;
  int iVar5;
  float fVar6;
  char cVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int *piVar12;
  void *pvVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  float10 fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fStack_94;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float afStack_60 [3];
  undefined4 uStack_54;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [20];
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a6bd4;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  param_1[0x233] = param_1[0x233] + 1;
  *(int *)(DAT_00d17958 + 0x148) = *(int *)(DAT_00d17958 + 0x148) + 1;
  iVar8 = param_1[2];
  if ((iVar8 != 0) && ((*(byte *)(iVar8 + 0x90e) & 1) != 0)) {
    if (*(int **)(iVar8 + 0x914) != (int *)0x0) {
      iVar8 = (**(code **)(**(int **)(iVar8 + 0x914) + 0xc))();
      param_1[0x220] = *(int *)(iVar8 + 0x90);
      param_1[0x221] = *(int *)(iVar8 + 0x94);
      param_1[0x222] = *(int *)(iVar8 + 0x98);
      iVar8 = (**(code **)(**(int **)(param_1[2] + 0x914) + 0xc))();
      fStack_78 = (*(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x88) -
                  *(float *)(iVar8 + 0x8c) * *(float *)(iVar8 + 0x84)) * g_flLevelUpUiBase_Inferred;
      fStack_7c = (*(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x84) +
                  *(float *)(iVar8 + 0x8c) * *(float *)(iVar8 + 0x88)) * g_flLevelUpUiBase_Inferred;
      fStack_80 = g_flOne - (*(float *)(iVar8 + 0x84) * *(float *)(iVar8 + 0x84) +
                            *(float *)(iVar8 + 0x88) * *(float *)(iVar8 + 0x88)) *
                            g_flLevelUpUiBase_Inferred;
      param_1[0x226] = (int)fStack_80;
      param_1[0x227] = (int)fStack_7c;
      param_1[0x228] = (int)fStack_78;
      iVar8 = (**(code **)(**(int **)(param_1[2] + 0x914) + 0xc))();
      fVar18 = *(float *)(iVar8 + 0x84);
      fStack_78 = g_flOne - (*(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x80) + fVar18 * fVar18)
                            * g_flLevelUpUiBase_Inferred;
      fStack_80 = (*(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x88) +
                  *(float *)(iVar8 + 0x84) * *(float *)(iVar8 + 0x8c)) * g_flLevelUpUiBase_Inferred;
      fStack_7c = (fVar18 * *(float *)(iVar8 + 0x88) -
                  *(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x8c)) * g_flLevelUpUiBase_Inferred;
      param_1[0x223] = (int)fStack_80;
      param_1[0x224] = (int)fStack_7c;
      param_1[0x225] = (int)fStack_78;
      iVar8 = (**(code **)(**(int **)(param_1[2] + 0x914) + 0xc))();
      fStack_78 = g_flLevelUpUiBase_Inferred;
      fVar6 = g_flOne;
      fVar18 = *(float *)(iVar8 + 0x80);
      fVar17 = *(float *)(iVar8 + 0x8c);
      fVar19 = *(float *)(iVar8 + 0x84);
      fVar3 = *(float *)(iVar8 + 0x88);
      fStack_7c = g_flOne - (*(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x80) +
                            *(float *)(iVar8 + 0x88) * *(float *)(iVar8 + 0x88)) *
                            g_flLevelUpUiBase_Inferred;
      fStack_80 = (*(float *)(iVar8 + 0x84) * *(float *)(iVar8 + 0x80) -
                  *(float *)(iVar8 + 0x88) * *(float *)(iVar8 + 0x8c)) * g_flLevelUpUiBase_Inferred;
      param_1[0x229] = (int)fStack_80;
      fStack_78 = (fVar18 * fVar17 + fVar19 * fVar3) * fStack_78;
      param_1[0x22a] = (int)fStack_7c;
      param_1[0x22b] = (int)fStack_78;
      if ((*(byte *)((int)param_1 + 0x98d) & 2) == 0) {
        iVar8 = (**(code **)(**(int **)(param_1[2] + 0x914) + 0xc))();
        param_1[0x22f] = *(int *)(iVar8 + 0x9c);
      }
      else {
        param_1[0x22f] = (int)fVar6;
      }
    }
    if ((*(byte *)((int)param_1 + 0x989) & 8) == 0) {
      *(undefined1 *)((int)param_1 + 0x7f9) = 1;
    }
    param_1[2] = 0;
  }
  fVar18 = g_flZero;
  if (*(char *)((int)param_1 + 0x7ff) != '\0') {
    *(undefined1 *)((int)param_1 + 0x7ff) = 0;
    ExceptionList = pvStack_1c;
    return 1;
  }
  fVar17 = (float)param_1[0x204];
  fVar19 = *param_2;
  param_1[0x204] = (int)(fVar17 - fVar19);
  if (fVar18 < fVar17 - fVar19) {
    ExceptionList = pvStack_1c;
    return 1;
  }
  puVar10 = (undefined4 *)*param_1;
  if ((((puVar10 == (undefined4 *)0x0) ||
       (puVar9 = (undefined4 *)(**(code **)*puVar10)(), puVar9 != puVar10)) ||
      ((9 < param_1[0x233] && (iVar8 = (**(code **)*puVar10)(), *(int *)(iVar8 + 0x14) == 0)))) &&
     ((*(char *)((int)param_1 + 0x7f9) != '\0' && (param_1[0x28a] == 0)))) {
    ExceptionList = pvStack_1c;
    return 0;
  }
  if ((((*(byte *)((int)param_1 + 0x989) & 8) != 0) && (param_1[2] != 0)) &&
     ((*(byte *)(param_1[2] + 0x90e) & 1) == 0)) {
    ExceptionList = pvStack_1c;
    return 1;
  }
  if ((puVar10 != (undefined4 *)0x0) &&
     (puVar9 = (undefined4 *)(**(code **)*puVar10)(), puVar9 == puVar10)) {
    (**(code **)*puVar10)();
  }
  if ((char)param_1[0x1fe] != '\0') {
    if (param_1[1] == 0) {
      param_1[0x202] = (int)((float)param_1[0x202] - *param_2);
    }
    else {
      param_1[0x202] = (int)((float)param_1[0x202] - *(float *)(param_1[1] + 0x34) * *param_2);
    }
    if (*(char *)((int)param_1 + 0x7f9) != '\0') {
      if (puVar10 == (undefined4 *)0x0) {
        ExceptionList = pvStack_1c;
        return 1;
      }
      if ((9 < param_1[0x233]) && (iVar8 = (**(code **)*puVar10)(), *(int *)(iVar8 + 0x14) == 0)) {
        ExceptionList = pvStack_1c;
        return 1;
      }
    }
    if ((float)param_1[0x202] <= 0.0 && (float)param_1[0x202] != 0.0) {
      if ((*(byte *)((int)param_1 + 0x989) & 0x20) == 0) {
        *(undefined1 *)((int)param_1 + 0x7fa) = 1;
      }
      else if ((*(byte *)((int)param_1 + 0x989) & 0x10) != 0) {
        if (param_1[1] == 0) {
          ExceptionList = pvStack_1c;
          return 1;
        }
        FUN_004b8dc0(0,0);
        ExceptionList = pvStack_1c;
        return 1;
      }
    }
  }
  FUN_005b83e0();
  param_1[0x205] = param_1[0x20e];
  param_1[0x206] = param_1[0x20f];
  param_1[0x207] = param_1[0x210];
  param_1[0x208] = param_1[0x211];
  param_1[0x209] = param_1[0x212];
  param_1[0x20a] = param_1[0x213];
  param_1[0x20b] = param_1[0x214];
  param_1[0x20c] = param_1[0x215];
  param_1[0x20d] = param_1[0x216];
  piVar12 = param_1 + 5;
  do {
    FUN_005b83e0();
    fVar17 = DAT_00af3f70;
    fVar18 = g_flOne;
    piVar12 = (int *)piVar12[0xbd];
  } while (piVar12 != param_1 + 5);
  iVar8 = param_1[2];
  if ((iVar8 != 0) && (-1 < (char)*(byte *)((int)param_1 + 0x989))) {
    if (((*(byte *)(iVar8 + 0x90e) & 1) == 0) || ((*(byte *)((int)param_1 + 0x989) & 8) != 0)) {
      if (*(int **)(iVar8 + 0x914) == (int *)0x0) {
        param_1[0x220] = *(int *)(iVar8 + 0x824);
        param_1[0x221] = *(int *)(iVar8 + 0x828);
        param_1[0x222] = *(int *)(iVar8 + 0x82c);
        param_1[0x226] = *(int *)(iVar8 + 0x83c);
        param_1[0x227] = *(int *)(iVar8 + 0x840);
        param_1[0x228] = *(int *)(iVar8 + 0x844);
        param_1[0x223] = *(int *)(iVar8 + 0x830);
        param_1[0x224] = *(int *)(iVar8 + 0x834);
        param_1[0x225] = *(int *)(iVar8 + 0x838);
        param_1[0x22f] = (int)fVar18;
      }
      else {
        iVar8 = (**(code **)(**(int **)(iVar8 + 0x914) + 0xc))();
        param_1[0x220] = *(int *)(iVar8 + 0x90);
        param_1[0x221] = *(int *)(iVar8 + 0x94);
        param_1[0x222] = *(int *)(iVar8 + 0x98);
        iVar8 = (**(code **)(**(int **)(param_1[2] + 0x914) + 0xc))();
        fStack_78 = (*(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x88) -
                    *(float *)(iVar8 + 0x8c) * *(float *)(iVar8 + 0x84)) *
                    g_flLevelUpUiBase_Inferred;
        fStack_7c = (*(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x84) +
                    *(float *)(iVar8 + 0x8c) * *(float *)(iVar8 + 0x88)) *
                    g_flLevelUpUiBase_Inferred;
        fStack_80 = g_flOne - (*(float *)(iVar8 + 0x84) * *(float *)(iVar8 + 0x84) +
                              *(float *)(iVar8 + 0x88) * *(float *)(iVar8 + 0x88)) *
                              g_flLevelUpUiBase_Inferred;
        param_1[0x226] = (int)fStack_80;
        param_1[0x227] = (int)fStack_7c;
        param_1[0x228] = (int)fStack_78;
        iVar8 = (**(code **)(**(int **)(param_1[2] + 0x914) + 0xc))();
        fVar18 = *(float *)(iVar8 + 0x84);
        fStack_78 = g_flOne - (*(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x80) + fVar18 * fVar18
                              ) * g_flLevelUpUiBase_Inferred;
        fStack_80 = (*(float *)(iVar8 + 0x84) * *(float *)(iVar8 + 0x8c) +
                    *(float *)(iVar8 + 0x88) * *(float *)(iVar8 + 0x80)) *
                    g_flLevelUpUiBase_Inferred;
        fStack_7c = (fVar18 * *(float *)(iVar8 + 0x88) -
                    *(float *)(iVar8 + 0x8c) * *(float *)(iVar8 + 0x80)) *
                    g_flLevelUpUiBase_Inferred;
        param_1[0x223] = (int)fStack_80;
        param_1[0x224] = (int)fStack_7c;
        param_1[0x225] = (int)fStack_78;
        iVar8 = (**(code **)(**(int **)(param_1[2] + 0x914) + 0xc))();
        fStack_78 = g_flLevelUpUiBase_Inferred;
        fVar6 = g_flOne;
        fVar18 = *(float *)(iVar8 + 0x80);
        fVar17 = *(float *)(iVar8 + 0x8c);
        fVar19 = *(float *)(iVar8 + 0x84);
        fVar3 = *(float *)(iVar8 + 0x88);
        fStack_7c = g_flOne - (*(float *)(iVar8 + 0x80) * *(float *)(iVar8 + 0x80) +
                              *(float *)(iVar8 + 0x88) * *(float *)(iVar8 + 0x88)) *
                              g_flLevelUpUiBase_Inferred;
        fStack_80 = (*(float *)(iVar8 + 0x84) * *(float *)(iVar8 + 0x80) -
                    *(float *)(iVar8 + 0x88) * *(float *)(iVar8 + 0x8c)) *
                    g_flLevelUpUiBase_Inferred;
        param_1[0x229] = (int)fStack_80;
        fStack_78 = (fVar18 * fVar17 + fVar19 * fVar3) * fStack_78;
        param_1[0x22a] = (int)fStack_7c;
        param_1[0x22b] = (int)fStack_78;
        if ((*(byte *)((int)param_1 + 0x98d) & 2) == 0) {
          iVar8 = (**(code **)(**(int **)(param_1[2] + 0x914) + 0xc))();
          param_1[0x22f] = *(int *)(iVar8 + 0x9c);
        }
        else {
          param_1[0x22f] = (int)fVar6;
        }
        iVar8 = *param_1;
        if (iVar8 != 0) {
          puVar10 = (undefined4 *)FUN_004a6930(param_1 + 0x220);
          *(undefined4 *)(iVar8 + 0x2c) = *puVar10;
          *(undefined4 *)(iVar8 + 0x30) = puVar10[1];
          *(undefined4 *)(iVar8 + 0x34) = puVar10[2];
          iVar8 = (**(code **)(**(int **)(param_1[2] + 0x914) + 0xc))();
          uVar11 = FUN_004ba6f0(iVar8 + 0x80);
          FUN_005bb1d0(uVar11);
        }
      }
      cVar7 = FUN_0040cf00(0x358637bd);
      if ((cVar7 != '\0') && (DAT_00b03e64 == '\0')) {
        uVar11 = 0;
        uVar14 = 0;
        uVar15 = 0;
        if ((param_1[1] != 0) && (iVar8 = *(int *)(param_1[1] + 0x10), iVar8 != 0)) {
          uVar11 = *(undefined4 *)(iVar8 + 0x160);
          uVar14 = *(undefined4 *)(iVar8 + 0x164);
          uVar15 = *(undefined4 *)(*(int *)(iVar8 + 0xa8) + 0x34);
        }
        DAT_00b454f9 = DAT_00b454f9 + '\x01';
        if (DAT_00b454f9 == '\0') {
          FUN_007a4480(0xffffffff,"Emitter found at 0,0,0: %d %I64d",uVar15,uVar11,uVar14);
        }
      }
      if (param_1[0x261] == 0) {
        param_1[0x211] = param_1[0x223];
        param_1[0x212] = param_1[0x224];
        param_1[0x213] = param_1[0x225];
      }
      pfVar1 = (float *)(param_1 + 0x214);
      *pfVar1 = (float)param_1[0x226];
      param_1[0x215] = param_1[0x227];
      param_1[0x216] = param_1[0x228];
      fVar18 = DAT_00aaa668;
      if (param_1[0x261] == 3) {
        pfVar2 = (float *)(param_1 + 0x211);
        *pfVar2 = (float)param_1[0x223];
        param_1[0x212] = param_1[0x224];
        param_1[0x213] = param_1[0x225];
        *pfVar2 = *pfVar2 * fVar18;
        param_1[0x212] = (int)((float)param_1[0x212] * fVar18);
        param_1[0x213] = (int)((float)param_1[0x213] * fVar18);
        *pfVar1 = *pfVar1 * fVar18;
        param_1[0x215] = (int)((float)param_1[0x215] * fVar18);
        param_1[0x216] = (int)((float)param_1[0x216] * fVar18);
      }
      iVar8 = param_1[2];
      param_1[0x22c] = *(int *)(iVar8 + 0x87c);
      param_1[0x22d] = *(int *)(iVar8 + 0x880);
      param_1[0x22e] = *(int *)(iVar8 + 0x884);
      param_1[0x217] = *(int *)(iVar8 + 0x87c);
      param_1[0x218] = *(int *)(iVar8 + 0x880);
      param_1[0x219] = *(int *)(iVar8 + 0x884);
    }
    else {
      param_1[2] = 0;
    }
    if ((*(byte *)((int)param_1 + 0x989) & 8) != 0) {
      param_1[2] = 0;
    }
    goto LAB_005bd44d;
  }
  if ((param_1[1] == 0) ||
     ((piVar12 = *(int **)(param_1[1] + 0x10), piVar12 == (int *)0x0 ||
      ((*(byte *)((int)param_1 + 0x989) & 0x88) != 0)))) {
    if ((*(byte *)((int)param_1 + 0x98a) & 1) != 0) {
      fVar18 = DAT_009cc4dc;
      fVar19 = DAT_009cc4dc;
      if (*(int *)(param_3 + 0xe4f8) != 0) {
        iVar8 = *(int *)(param_3 + 0xe4f8);
        fVar18 = (float)*(int *)(iVar8 + 0x14) * *(float *)(iVar8 + 0x18) * DAT_00a0f298;
        fVar19 = (float)*(int *)(iVar8 + 0x10) * *(float *)(iVar8 + 0x18) * DAT_00a0f298;
      }
      fVar3 = *(float *)(param_4 + 0x98);
      param_1[0x220] = (int)(((*(float *)(param_4 + 0x90) - fVar19) / fVar19) * DAT_00af3f70);
      param_1[0x221] = 0;
      param_1[0x222] = (int)(((fVar3 - fVar18) / fVar18) * fVar17);
    }
    fVar18 = g_flOne;
    if ((param_1[1] == 0) || (*(char *)(param_1[1] + 4) == '\0')) {
      param_1[0x226] = (int)g_flOne;
      param_1[0x227] = 0;
      param_1[0x228] = 0;
      param_1[0x223] = 0;
      param_1[0x224] = 0;
      param_1[0x225] = (int)fVar18;
      param_1[0x229] = 0;
      param_1[0x22a] = (int)fVar18;
      param_1[0x22b] = 0;
    }
    goto LAB_005bd44d;
  }
  if (((uint)piVar12[0x5f] >> 6 & 1) != 0) {
    iVar8 = (**(code **)(*piVar12 + 0x1cc))();
    if ((iVar8 == 0) || (*(int *)(iVar8 + 8) == 0)) {
      piVar12 = (int *)FUN_004e88e0(&fStack_70,*(int *)(*(int *)(iVar8 + 4) + 4) + 0x84 + iVar8);
      param_1[0x220] = *piVar12;
      param_1[0x221] = piVar12[1];
      param_1[0x222] = piVar12[2];
      FUN_004e8ad0(*(int *)(*(int *)(iVar8 + 4) + 4) + 0x94 + iVar8,&fStack_80);
      piVar12 = (int *)FUN_004e88e0(&fStack_70,&fStack_80);
      param_1[0x226] = *piVar12;
      param_1[0x227] = piVar12[1];
      param_1[0x228] = piVar12[2];
      FUN_004e8a40(*(int *)(*(int *)(iVar8 + 4) + 4) + 0x94 + iVar8,&fStack_80);
      piVar12 = (int *)FUN_004e88e0(&fStack_70,&fStack_80);
      param_1[0x223] = *piVar12;
      param_1[0x224] = piVar12[1];
      param_1[0x225] = piVar12[2];
      FUN_004e8b60(*(int *)(*(int *)(iVar8 + 4) + 4) + 0x94 + iVar8,&fStack_80);
      piVar12 = (int *)FUN_004e88e0(&fStack_70,&fStack_80);
      param_1[0x229] = *piVar12;
      param_1[0x22a] = piVar12[1];
      param_1[0x22b] = piVar12[2];
      fVar18 = g_flOne;
      if ((*(byte *)((int)param_1 + 0x98d) & 2) == 0) {
        fVar18 = *(float *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 0xbc + iVar8);
      }
      iVar5 = *param_1;
      param_1[0x22f] = (int)fVar18;
      if (iVar5 != 0) {
        puVar10 = (undefined4 *)FUN_004a6930(param_1 + 0x220);
        *(undefined4 *)(iVar5 + 0x2c) = *puVar10;
        *(undefined4 *)(iVar5 + 0x30) = puVar10[1];
        *(undefined4 *)(iVar5 + 0x34) = puVar10[2];
        uVar11 = FUN_004f2e70(*(int *)(*(int *)(iVar8 + 4) + 4) + 0x94 + iVar8);
        goto LAB_005bd17c;
      }
    }
    else {
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) + 0x108))
                (param_1[0x230],param_1 + 0x220,&fStack_70,param_1[0x231]);
      fStack_78 = g_flLevelUpUiBase_Inferred;
      fVar18 = g_flOne;
      fVar19 = (fStack_6c * fStack_70 + fStack_64 * fStack_68) * g_flLevelUpUiBase_Inferred;
      fVar17 = (fStack_68 * fStack_70 - fStack_6c * fStack_64) * g_flLevelUpUiBase_Inferred;
      param_1[0x226] =
           (int)(g_flOne -
                (fStack_68 * fStack_68 + fStack_6c * fStack_6c) * g_flLevelUpUiBase_Inferred);
      param_1[0x227] = (int)fVar19;
      param_1[0x228] = (int)fVar17;
      param_1[0x223] = (int)((fStack_6c * fStack_64 + fStack_68 * fStack_70) * fStack_78);
      param_1[0x224] = (int)((fStack_6c * fStack_68 - fStack_64 * fStack_70) * fStack_78);
      param_1[0x225] = (int)(fVar18 - (fStack_70 * fStack_70 + fStack_6c * fStack_6c) * fStack_78);
      fVar18 = g_flOne;
      fStack_80 = (fStack_6c * fStack_70 - fStack_64 * fStack_68) * fStack_78;
      fStack_7c = g_flOne - (fStack_70 * fStack_70 + fStack_68 * fStack_68) * fStack_78;
      param_1[0x229] = (int)fStack_80;
      fStack_78 = (fStack_64 * fStack_70 + fStack_6c * fStack_68) * fStack_78;
      param_1[0x22a] = (int)fStack_7c;
      param_1[0x22b] = (int)fStack_78;
      if ((*(byte *)((int)param_1 + 0x98d) & 2) == 0) {
        iVar8 = (**(code **)(**(int **)(iVar8 + 8) + 0xc))();
        param_1[0x22f] = *(int *)(iVar8 + 0x9c);
      }
      else {
        param_1[0x22f] = (int)fVar18;
      }
      iVar8 = *param_1;
      if (iVar8 != 0) {
        puVar10 = (undefined4 *)FUN_004a6930(param_1 + 0x220);
        *(undefined4 *)(iVar8 + 0x2c) = *puVar10;
        *(undefined4 *)(iVar8 + 0x30) = puVar10[1];
        *(undefined4 *)(iVar8 + 0x34) = puVar10[2];
        uVar11 = FUN_004ba6f0(&fStack_70);
LAB_005bd17c:
        FUN_005bb1d0(uVar11);
      }
    }
    if (param_1[0x261] == 0) {
      param_1[0x211] = param_1[0x223];
      param_1[0x212] = param_1[0x224];
      param_1[0x213] = param_1[0x225];
    }
    pfVar1 = (float *)(param_1 + 0x214);
    *pfVar1 = (float)param_1[0x226];
    param_1[0x215] = param_1[0x227];
    param_1[0x216] = param_1[0x228];
    fVar18 = DAT_00aaa668;
    if (param_1[0x261] == 3) {
      pfVar2 = (float *)(param_1 + 0x211);
      *pfVar2 = (float)param_1[0x223];
      param_1[0x212] = param_1[0x224];
      param_1[0x213] = param_1[0x225];
      *pfVar2 = *pfVar2 * fVar18;
      param_1[0x212] = (int)((float)param_1[0x212] * fVar18);
      param_1[0x213] = (int)((float)param_1[0x213] * fVar18);
      *pfVar1 = *pfVar1 * fVar18;
      param_1[0x215] = (int)((float)param_1[0x215] * fVar18);
      param_1[0x216] = (int)((float)param_1[0x216] * fVar18);
    }
  }
  piVar12 = *(int **)(param_1[1] + 0x10);
  if (((((uint)piVar12[0x5f] >> 5 & 1) == 0) &&
      ((piVar12 = (int *)piVar12[0x2b], piVar12 == (int *)0x0 ||
       (((uint)piVar12[0x5f] >> 5 & 1) == 0)))) ||
     (iVar8 = (**(code **)(*piVar12 + 0x1c8))(), *(int *)(iVar8 + 8) == 0)) {
    param_1[0x22c] = 0;
    param_1[0x22d] = 0;
    param_1[0x22e] = 0;
  }
  else {
    param_1[0x22c] = *(int *)(*(int *)(*(int *)(iVar8 + 8) + 0x3c) + 0x40);
    param_1[0x22d] = *(int *)(*(int *)(*(int *)(iVar8 + 8) + 0x3c) + 0x44);
    param_1[0x22e] = *(int *)(*(int *)(*(int *)(iVar8 + 8) + 0x3c) + 0x48);
  }
  param_1[0x217] = param_1[0x22c];
  param_1[0x218] = param_1[0x22d];
  param_1[0x219] = param_1[0x22e];
  cVar7 = FUN_0040cf00(0x358637bd);
  if ((cVar7 != '\0') && (DAT_00b03e64 == '\0')) {
    uVar11 = 0;
    uVar14 = 0;
    uVar15 = 0;
    if ((param_1[1] != 0) && (iVar8 = *(int *)(param_1[1] + 0x10), iVar8 != 0)) {
      uVar11 = *(undefined4 *)(iVar8 + 0x160);
      uVar14 = *(undefined4 *)(iVar8 + 0x164);
      uVar15 = *(undefined4 *)(*(int *)(iVar8 + 0xa8) + 0x34);
    }
    DAT_00b454f8 = DAT_00b454f8 + '\x01';
    if (DAT_00b454f8 == '\0') {
      FUN_007a4480(0xffffffff,"Emitter found at 0,0,0: %d %I64d",uVar15,uVar11,uVar14);
    }
  }
LAB_005bd44d:
  fVar18 = (float)param_1[0x23c];
  fVar17 = (float)param_1[0x23b];
  fStack_70 = fVar18 * (float)param_1[0x223];
  fVar19 = (float)param_1[0x23a];
  fStack_80 = (float)param_1[0x226] * fVar19 + fVar17 * (float)param_1[0x229] + fStack_70;
  pfVar1 = (float *)(param_1 + 0x21a);
  fVar3 = (float)param_1[0x22f];
  fStack_7c = (float)param_1[0x227] * fVar19 + (float)param_1[0x22a] * fVar17 +
              (float)param_1[0x224] * fVar18;
  *pfVar1 = fStack_80;
  param_1[0x21b] = (int)fStack_7c;
  fStack_78 = (float)param_1[0x228] * fVar19 + (float)param_1[0x22b] * fVar17 +
              (float)param_1[0x225] * fVar18;
  param_1[0x21c] = (int)fStack_78;
  *pfVar1 = fVar3 * *pfVar1;
  param_1[0x21b] = (int)(fVar3 * (float)param_1[0x21b]);
  param_1[0x21c] = (int)(fVar3 * (float)param_1[0x21c]);
  if ((char)param_1[0x1ff] == '\0') {
    if ((*(char *)((int)param_1 + 0x7fe) != '\0') || (*(char *)((int)param_1 + 0x7fd) != '\0')) {
      fStack_80 = *pfVar1 + (float)param_1[0x220];
      fStack_7c = (float)param_1[0x221] + (float)param_1[0x21b];
      fStack_78 = (float)param_1[0x222] + (float)param_1[0x21c];
      param_1[0x20e] = (int)fStack_80;
      param_1[0x20f] = (int)fStack_7c;
      param_1[0x210] = (int)fStack_78;
    }
  }
  else if ((*(char *)((int)param_1 + 0x7fa) == '\0') || (*(char *)((int)param_1 + 0x7fe) != '\0')) {
    FUN_005bb1f0(param_2,0);
    if ((char)param_1[0x1fe] != '\0') {
      fVar18 = (float)param_1[0x200];
      fVar17 = *param_2;
      param_1[0x200] = (int)(fVar18 - fVar17);
      if (*(char *)((int)param_1 + 0x7fe) == '\0') {
        if (fVar18 - fVar17 <= 0.0) {
          piVar12 = *(int **)(param_1[4] + 0x2f4);
          param_1[4] = (int)piVar12;
          param_1[0x200] = *piVar12;
          if ((*(byte *)(param_1[4] + 0x1e4) & 4) != 0) {
            iVar8 = CVOGReaction_RandomUnitScalar();
            if (0xfffff < *(int *)(iVar8 + 0xc)) {
              *(undefined4 *)(iVar8 + 0xc) = 0;
            }
            uVar4 = *(ushort *)(*(int *)(iVar8 + 8) + *(int *)(iVar8 + 0xc) * 2);
            *(int *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) + 1;
            param_1[0x200] =
                 (int)((float)uVar4 * *(float *)(param_1[4] + 4) * DAT_00aaa638 +
                      (float)param_1[0x200]);
          }
        }
      }
      else {
        fStack_80 = *pfVar1 + (float)param_1[0x220];
        fStack_7c = (float)param_1[0x21b] + (float)param_1[0x221];
        fStack_78 = (float)param_1[0x21c] + (float)param_1[0x222];
        param_1[0x20e] = (int)fStack_80;
        param_1[0x20f] = (int)fStack_7c;
        param_1[0x210] = (int)fStack_78;
      }
      if (((((param_1[0x234] == 0) ||
            (iVar8 = (**(code **)(**(int **)(param_1[1] + 0x10) + 0x214))(), iVar8 == 0)) ||
           (iVar5 = *(int *)(param_3 + 0xe8a0), iVar5 == 0)) ||
          (((param_1[0x234] != 2 || (*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8 == iVar5)) &&
           ((param_1[0x234] != 4 ||
            (cVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 4) + 4 + iVar8) + 0x298))
                               (iVar5), cVar7 == '\0')))))) && (iVar8 = param_1[4], iVar8 != 0)) {
        fVar16 = (float10)FUN_00404bd0(param_1 + 0x220);
        fVar18 = *(float *)(*(int *)(param_3 + 0xe898) + 0x54);
        if (0.0 < *(float *)(iVar8 + 0x1d0)) {
          fVar18 = *(float *)(iVar8 + 0x1d0);
        }
        fStack_94 = g_flOne;
        fVar17 = (float)fVar16 / fVar18;
        if (g_flOne <= (float)fVar16 / fVar18) {
          fVar17 = g_flOne;
        }
        if (*(float *)(iVar8 + 0x1cc) <= fVar17 && fVar17 != *(float *)(iVar8 + 0x1cc)) {
          fStack_94 = (g_flOne - fVar17) / (g_flOne - *(float *)(iVar8 + 0x1cc));
        }
        if (((*(byte *)(iVar8 + 0x1e4) & 2) != 0) && (*(float *)(iVar8 + 0x1d4) != 0.0)) {
          _DAT_00b454f4 = *(float *)(iVar8 + 0x1d8) + _DAT_00b454f4;
          if (DAT_00aaa7dc < _DAT_00b454f4) {
            iVar8 = CVOGReaction_RandomUnitScalar();
            if (0xfffff < *(int *)(iVar8 + 0xc)) {
              *(undefined4 *)(iVar8 + 0xc) = 0;
            }
            uVar4 = *(ushort *)(*(int *)(iVar8 + 8) + *(int *)(iVar8 + 0xc) * 2);
            *(int *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) + 1;
            DAT_00af3f6d = ((uVar4 & 1) != 0) * '\x02' + -1;
            iVar8 = CVOGReaction_RandomUnitScalar();
            if (0xfffff < *(int *)(iVar8 + 0xc)) {
              *(undefined4 *)(iVar8 + 0xc) = 0;
            }
            uVar4 = *(ushort *)(*(int *)(iVar8 + 8) + *(int *)(iVar8 + 0xc) * 2);
            *(int *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) + 1;
            _DAT_00b454f4 = 0.0;
            DAT_00af3f6c = ((uVar4 & 1) != 0) * '\x02' + -1;
          }
          fVar16 = (float10)fsin((float10)_DAT_00b454f4);
          fStack_80 = *(float *)(param_4 + 0x90);
          fStack_70 = *(float *)(param_4 + 0x80);
          fStack_6c = *(float *)(param_4 + 0x84);
          fStack_68 = *(float *)(param_4 + 0x88);
          fStack_64 = *(float *)(param_4 + 0x8c);
          afStack_60[2] =
               (float)(fVar16 * (float10)*(float *)(param_1[4] + 0x1d4) * (float10)fStack_94);
          fStack_7c = *(float *)(param_4 + 0x94);
          fStack_78 = *(float *)(param_4 + 0x98);
          afStack_60[0] = (float)(int)DAT_00af3f6d * afStack_60[2];
          afStack_60[2] = (float)(int)DAT_00af3f6c * afStack_60[2];
          afStack_60[1] = 0.0;
          uStack_54 = 0;
          FUN_004e8860(&fStack_70,auStack_50);
          FUN_004e8910(&fStack_80,auStack_40);
          FUN_004e8bf0(auStack_40,auStack_50,afStack_60,auStack_30);
          FUN_004e88a0(auStack_30,&fStack_80);
          FUN_0040cf90(&fStack_80);
        }
        if ((((*(byte *)(param_1[4] + 0x1e4) & 1) != 0) && (*(int *)(param_3 + 0x78) != 0)) &&
           (param_1[1] != 0)) {
          FUN_005552c0(*(float *)(param_1[1] + 0x38) * fStack_94,param_1[4] + 0x13c);
        }
      }
    }
  }
  else {
    fVar18 = (float)param_1[0x20e];
    fVar17 = (float)param_1[0x20f];
    fVar19 = (float)param_1[0x210];
    if (*(char *)((int)param_1 + 0x7fd) != '\0') {
      fVar3 = *param_2;
      param_1[0x20e] = (int)(fVar3 * (float)param_1[0x22c] + fVar18);
      param_1[0x20f] = (int)((float)param_1[0x22d] * fVar3 + (float)param_1[0x20f]);
      param_1[0x210] = (int)((float)param_1[0x22e] * fVar3 + (float)param_1[0x210]);
    }
    fStack_78 = g_flOne / *param_2;
    fStack_80 = ((float)param_1[0x20e] - fVar18) * fStack_78;
    fStack_7c = ((float)param_1[0x20f] - fVar17) * fStack_78;
    param_1[0x217] = (int)fStack_80;
    fStack_78 = fStack_78 * ((float)param_1[0x210] - fVar19);
    param_1[0x218] = (int)fStack_7c;
    param_1[0x219] = (int)fStack_78;
  }
  fVar18 = g_flOne;
  if (*(char *)((int)param_1 + 0x7fe) == '\0') {
    pfVar1 = (float *)(param_1 + 0x217);
    *pfVar1 = (float)param_1[0x20e] - (float)param_1[0x205];
    param_1[0x218] = (int)((float)param_1[0x20f] - (float)param_1[0x206]);
    param_1[0x219] = (int)((float)param_1[0x210] - (float)param_1[0x207]);
    fVar17 = fVar18 / *param_2;
    *pfVar1 = fVar17 * *pfVar1;
    param_1[0x219] = (int)(fVar17 * (float)param_1[0x219]);
    param_1[0x218] = (int)(fVar17 * (float)param_1[0x218]);
    fStack_80 = (float)param_1[0x220] - (float)param_1[0x21d];
    fStack_7c = (float)param_1[0x221] - (float)param_1[0x21e];
    pfVar1 = (float *)(param_1 + 0x22c);
    fStack_78 = (float)param_1[0x222] - (float)param_1[0x21f];
    *pfVar1 = fStack_80;
    param_1[0x22d] = (int)fStack_7c;
    param_1[0x22e] = (int)fStack_78;
    fVar18 = fVar18 / *param_2;
    *pfVar1 = fVar18 * *pfVar1;
    param_1[0x22d] = (int)(fVar18 * (float)param_1[0x22d]);
    param_1[0x22e] = (int)(fVar18 * (float)param_1[0x22e]);
  }
  else if ((((*(byte *)(param_1 + 0x263) & 0x80) != 0) && (param_1[3] == 0)) &&
          ((param_1[2] != 0 && (*(int *)(param_1[2] + 0x914) != 0)))) {
    pvVar13 = operator_new(0x10);
    uStack_14 = 0;
    if (pvVar13 == (void *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_005c4e70();
    }
    param_1[3] = iVar8;
    uStack_14 = 0xffffffff;
    FUN_005c4f00(*(undefined4 *)(param_1[2] + 0x914));
  }
  param_1[0x21d] = param_1[0x220];
  param_1[0x21e] = param_1[0x221];
  param_1[0x21f] = param_1[0x222];
  if ((char)param_1[0x1fe] != '\0') {
    if ((*(char *)((int)param_1 + 0x7fa) != '\0') && (*(char *)((int)param_1 + 0x7fe) == '\0')) {
      if (param_1[0x28a] != 0) {
        ExceptionList = pvStack_1c;
        return 1;
      }
      *(undefined1 *)((int)param_1 + 0x7f9) = 1;
      ExceptionList = pvStack_1c;
      return 1;
    }
    FUN_005b83e0();
    piVar12 = param_1 + 5;
    do {
      FUN_005b83e0();
      piVar12 = (int *)piVar12[0xbd];
    } while (piVar12 != param_1 + 5);
    if (*param_1 == 0) {
      FUN_005bc120(param_2,param_3);
    }
  }
  *(undefined1 *)((int)param_1 + 0x7fe) = 0;
  ExceptionList = pvStack_1c;
  return 1;
}
```

---

## W28-I dual seal append (2026-07-29)

| Field | Value |
|---|---|
| **Body** | `0x005bc3c0`–`0x005bdce6` exclusive (**6438** B / `0x1926`) |
| **Epilogue** | `8B E5 5D C2 0C 00` @ `0x005bdce0` → **ret 0x0C**; pad `CC` |
| **Prologue** | `55 8B EC 83 E4 F0 6A FF 68 D4 6B 9A 00` (SEH `LAB_009a6bd4`) |
| **ABI** | `__thiscall` ECX=emitter; stack `(float* dt, int host_field_2c, int camera_or_world)`; return 0=remove / 1=keep |
| **Caller (1)** | `FUN_004b8ed0` `NDSpecialFX_HostTick_Inferred` @ `0x004b90ef` |
| **Key child** | `FUN_005bc120` `Emitter_SpawnOnIntervalTick_Inferred` @ call `0x005bdcc1` |
| **String** | `"Emitter found at 0,0,0: %d %I64d"` |
| **Name** | `Emitter_UpdateTick_Inferred` |
| **Tools** | `decompile_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes` |
| **Live decompile** | ≡ raw 2026-07-23 body (full CF) |

### Constants (`read_memory`)

| Symbol / VA | Bytes | Float |
|---|---|---|
| `DAT_00a10e74` (`g_flLevelUpUiBase_Inferred`) | `00 00 00 40` | **2.0** (quat factor; name misnomer) |
| `DAT_00aaa668` | `00 00 80 bf` | **-1.0** |
| `DAT_00af3f70` | `00 00 20 c1` | **-10.0** |

### HostTick keep contract

```
c = Emitter_UpdateTick(payload, dt, host+0x2c, camera)
if c == 0: unlink list node; delete node; FUN_005be310(payload)
else: ObjectMotion_SlotListTick(payload, dt, host+0x2c)
```
