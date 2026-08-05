# Raw capture: FUN_004e9aa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e9aa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004e9aa0` |
| **Canonical name** | `FUN_004e9aa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004e9aa0(undefined4 *param_1,float param_2,float param_3,int param_4,float *param_5,
                    float param_6,char param_7)

{
  int *piVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  double dVar15;
  float fStack_524;
  float local_518;
  int *local_508;
  float local_504;
  float local_500;
  undefined **local_4fc;
  float local_4f8;
  float fStack_4e0;
  int iStack_4cc;
  undefined1 auStack_4b4 [16];
  undefined1 auStack_4a4 [16];
  undefined4 *puStack_494;
  undefined4 uStack_484;
  int iStack_47c;
  float fStack_454;
  float fStack_450;
  float fStack_44c;
  int *piStack_448;
  undefined4 uStack_438;
  int iStack_430;
  float fStack_3fc;
  float fStack_3f8;
  float fStack_3f4;
  float fStack_3f0;
  float fStack_3e0;
  undefined1 auStack_3d8 [8];
  float fStack_3d0;
  float afStack_3b8 [4];
  float local_3a8 [47];
  undefined **ppuStack_2ec;
  undefined1 uStack_2e8;
  undefined1 *puStack_2e4;
  int iStack_2e0;
  undefined4 uStack_2dc;
  undefined1 auStack_2d8 [272];
  int *apiStack_1c8 [50];
  undefined1 auStack_100 [200];
  void *pvStack_38;
  int iStack_30;
  undefined1 uStack_28;
  void *local_1c;
  undefined1 *puStack_18;
  uint local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a2690;
  local_1c = ExceptionList;
  local_504 = DAT_00d1f040;
  ExceptionList = &local_1c;
  FUN_0076cf00();
  local_14 = 0;
  if ((param_4 != 0) && (*(int *)(param_4 + 8) != 0)) {
    if (param_7 == '\0') {
      fVar14 = *(float *)(param_4 + 0x34);
      local_504 = fVar14;
      FUN_004e8930(param_2,fVar14,param_6,param_3);
      local_14 = 0xffffffff;
      local_504 = fVar14;
      FUN_0076cef0();
      ExceptionList = local_1c;
      return (float10)local_504;
    }
    local_508 = (int *)(param_2 + param_3 + g_flOne);
    fVar10 = (float10)FUN_0040d0a0();
    fVar11 = (float)fVar10 * g_flLevelUpUiBase_Inferred;
    fVar12 = fVar11 * _DAT_009ccbbc;
    local_518 = (float)(fVar10 * (float10)DAT_00aaa668);
    dVar15 = ceil((double)fVar12);
    fVar14 = g_flLevelUpUiBase_Inferred;
    if ((double)g_flLevelUpUiBase_Inferred <= dVar15 + (double)g_flOne) {
      dVar15 = ceil((double)fVar12);
      fVar14 = (float)dVar15 + g_flOne;
    }
    fVar13 = DAT_00aaabc0;
    if (fVar14 + g_flOne < DAT_00aaabc0) {
      dVar15 = ceil((double)fVar12);
      if ((double)g_flLevelUpUiBase_Inferred <= dVar15 + (double)g_flOne) {
        fVar10 = (float10)FUN_0040f520();
        fVar13 = (float)(fVar10 + (float10)g_flOne) + g_flOne;
      }
      else {
        fVar13 = g_flLevelUpUiBase_Inferred + g_flOne;
      }
    }
    iVar7 = (int)fVar13;
    iVar4 = iVar7 + -1;
    if (param_6 != DAT_00aaa668) {
      iVar4 = iVar7 + -2;
    }
    iVar5 = iVar7 * 4 + -4;
    iVar8 = 0;
    if (0 < iVar5) {
      do {
        fVar10 = (float10)fsin((float10)local_518);
        afStack_3b8[iVar8 + 5] = 0.0;
        afStack_3b8[iVar8 + 7] = 0.0;
        iVar9 = iVar8 + 4;
        fVar14 = fVar11 / (float)iVar4 + local_518;
        afStack_3b8[iVar9] = (float)(fVar10 * (float10)(float)local_508);
        fVar10 = (float10)fcos((float10)local_518);
        afStack_3b8[iVar8 + 6] = (float)(fVar10 * (float10)(float)local_508);
        iVar8 = iVar9;
        local_518 = fVar14;
      } while (iVar9 < iVar5);
    }
    afStack_3b8[iVar7 * 4 + 3] = 0.0;
    afStack_3b8[iVar7 * 4 + 2] = 0.0;
    afStack_3b8[iVar7 * 4 + 1] = 0.0;
    afStack_3b8[iVar7 * 4] = 0.0;
    local_500 = 0.0;
    local_4fc = (undefined **)0x0;
    local_4f8 = -0.0;
    local_14 = CONCAT31(local_14._1_3_,1);
    iVar4 = (**(code **)(*DAT_00b05060 + 0x10))(0xe0,0x22);
    *(undefined2 *)(iVar4 + 4) = 0xe0;
    local_1c._0_1_ = 2;
    DAT_00b03e60 = (undefined4 *)FUN_006c90d0(afStack_3b8 + 4,local_518,0x10,&local_508);
    local_1c = (void *)((uint)local_1c._1_3_ << 8);
    if (-1 < (int)local_500) {
      (**(code **)(*DAT_00b05060 + 0x14))(local_508,(int)local_500 << 4,0x12);
    }
    fVar14 = param_5[1];
    if (ABS(*param_5 * 0.0 + param_5[2] + fVar14 * 0.0) < g_flOne) {
      _CIacos();
    }
    FUN_005eb8d0();
    local_508 = (int *)*param_1;
    local_500 = (float)param_1[2];
    local_4fc = (undefined **)param_1[3];
    puStack_494 = DAT_00b03e60;
    local_1c = (void *)CONCAT31(local_1c._1_3_,3);
    (**(code **)(**(int **)(*(int *)(param_4 + 8) + 0xc) + 0x18))
              (*(int *)(*(int *)(param_4 + 8) + 0x3c) + 0x80,0x3dcccccd,auStack_3d8);
    fVar13 = (fStack_3d0 - fStack_3e0) * DAT_00a0f298 + fStack_3e0;
    piStack_448 = local_508;
    local_504 = 0.0;
    local_500 = g_flOne;
    local_4fc = (undefined **)0x0;
    local_4f8 = 0.0;
    fStack_454 = fVar11;
    fStack_450 = fVar13;
    fStack_44c = fVar12;
    FUN_00567ce0(&local_504,unaff_ESI);
    FUN_005eadb0(auStack_4b4);
    FUN_005eb790(auStack_4a4);
    puVar3 = DAT_00b03e60;
    *(short *)((int)DAT_00b03e60 + 6) = *(short *)((int)DAT_00b03e60 + 6) + -1;
    uStack_28 = 4;
    if (*(short *)((int)puVar3 + 6) == 0) {
      (**(code **)*puVar3)(1);
    }
    iVar7 = (**(code **)(*apiStack_1c8[0] + 0x14))();
    iVar5 = (**(code **)(**(int **)(*(int *)(param_4 + 8) + 0xc) + 0x14))();
    piVar1 = *(int **)(*(int *)(*(int *)(param_4 + 8) + 8) + 0xcc);
    iVar4 = *piVar1;
    puStack_2e4 = auStack_2d8;
    ppuStack_2ec = &PTR_FUN_009ccbb4;
    uStack_2dc = 0x80000010;
    iStack_2e0 = 0;
    uStack_2e8 = 0;
    uStack_28 = 5;
    (**(code **)(iVar4 + 0x118c + (iVar7 * 0x20 + iVar5) * 4))
              (apiStack_1c8,*(int *)(param_4 + 8) + 0xc,piVar1,&ppuStack_2ec);
    if (iStack_2e0 != 0) {
      iVar7 = (**(code **)(*DAT_00b05060 + 0x10))(0x10,0x22);
      *(undefined2 *)(iVar7 + 4) = 0x10;
      iStack_30._0_1_ = 6;
      piVar6 = (int *)FUN_006c7fa0(0x3dcccccd);
      iStack_30._0_1_ = 5;
      FUN_005eb8d0();
      fStack_3f8 = local_518;
      iStack_30._0_1_ = 7;
      piStack_448 = piVar6;
      fStack_3fc = fVar14 * 0.0;
      fStack_3f4 = fVar11;
      fStack_3f0 = fVar13;
      FUN_005eb790(&fStack_44c);
      *(short *)((int)piVar6 + 6) = *(short *)((int)piVar6 + 6) + -1;
      iStack_30._0_1_ = 8;
      if (*(short *)((int)piVar6 + 6) == 0) {
        (**(code **)*piVar6)(1);
      }
      iVar5 = (**(code **)(*piVar6 + 0x14))();
      iVar7 = piVar1[2];
      pcVar2 = *(code **)(unaff_ESI + 0x218c + (iVar5 * 0x20 + unaff_EDI) * 4);
      piVar1[2] = iVar4;
      local_4fc = &PTR_FUN_009ccba8;
      iStack_4cc = 0;
      fStack_4e0 = DAT_009ccb84;
      local_4f8 = DAT_009ccb84;
      iStack_30._0_1_ = 9;
      (*pcVar2)(auStack_100,*(int *)(param_4 + 8) + 0xc,piVar1,&local_4fc);
      piVar1[2] = iVar7;
      if ((iStack_4cc != 0) && (fStack_524 = fStack_4e0 - param_2, fStack_524 <= param_3)) {
        if (fStack_524 <= g_flMsToSeconds_Inferred) {
          fStack_524 = g_flMsToSeconds_Inferred;
        }
        local_4fc = &PTR_LAB_009ccb90;
        iStack_30._0_1_ = 7;
        FUN_005eb7d0();
        iStack_30._0_1_ = 5;
        FUN_004eae80();
        iStack_30._0_1_ = 4;
        FUN_004eacc0();
        iStack_30._0_1_ = 3;
        FUN_005eb7d0();
        iStack_30 = (uint)iStack_30._1_3_ << 8;
        FUN_004eae80();
        iStack_30 = 0xffffffff;
        FUN_0076cef0();
        ExceptionList = pvStack_38;
        return (float10)fStack_524;
      }
      local_4fc = &PTR_LAB_009ccb90;
      iStack_30 = CONCAT31(iStack_30._1_3_,7);
      FUN_005eb7d0();
      uStack_28 = 5;
      if (-1 < iStack_430) {
        (**(code **)(*DAT_00b05060 + 0x14))(uStack_438,iStack_430 * 8,0x12);
      }
    }
    uStack_28 = 4;
    FUN_004eacc0();
    uStack_28 = 3;
    FUN_005eb7d0();
    local_14 = local_14 & 0xffffff00;
    if (-1 < iStack_47c) {
      (**(code **)(*DAT_00b05060 + 0x14))(uStack_484,iStack_47c * 8,0x12);
    }
  }
  local_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_1c;
  return (float10)g_flZero;
}
```
