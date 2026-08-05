# Raw capture: FUN_005b6da0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b6da0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b6da0` |
| **Canonical name** | `FUN_005b6da0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005b6da0(int param_1)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  float *pfVar7;
  undefined4 *puVar8;
  int iVar9;
  float *pfVar10;
  float10 fVar11;
  int *local_9c;
  undefined1 local_98;
  undefined1 uStack_97;
  undefined1 uStack_96;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float afStack_7c [4];
  undefined4 uStack_6c;
  float fStack_68;
  float fStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  float fStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  float fStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [8];
  void *pvStack_24;
  undefined4 uStack_18;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a6a09;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  fVar11 = (float10)FUN_00687130();
  local_9c = (int *)(float)fVar11;
  FUN_00687150(0);
  FUN_0068a4d0(*(undefined4 *)(param_1 + 0x50),8,0xffffffff,0xffffffff,0xffffffff);
  FUN_00687150(local_9c);
  FUN_0096f530();
  local_4 = 0;
  FUN_00989e00(&local_9c,"NDTreeBillboard.fx");
  FUN_009701d0(&local_9c);
  FUN_00970140("DiffuseTexture",**(undefined4 **)(param_1 + 0x24));
  piVar5 = operator_new(0xdc);
  local_4._0_1_ = 1;
  local_9c = piVar5;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    FUN_00748960();
    *piVar5 = (int)&PTR_FUN_009d9924;
    piVar5[1] = (int)&PTR_LAB_009d9914;
    piVar5[0x34] = -1;
    piVar5[0x35] = -1;
    piVar5[0x36] = -1;
    *(undefined1 *)(piVar5 + 0x33) = 0;
    piVar5[0x31] = 0;
    piVar5[0x32] = 0;
  }
  *(int **)(param_1 + 0x18) = piVar5;
  local_4 = (uint)local_4._1_3_ << 8;
  uVar6 = (**(code **)(**(int **)(param_1 + 8) + 0xc))();
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 100) = uVar6;
  iVar3 = **(int **)(param_1 + 0x18);
  uVar6 = (**(code **)(**(int **)(param_1 + 8) + 100))();
  (**(code **)(iVar3 + 0x34))(uVar6);
  piVar5 = local_9c;
  iVar3 = *(int *)(param_1 + 0x18);
  if ((local_9c != (int *)0x0) && (local_9c[1] = local_9c[1] + 1, local_9c[1] == 1)) {
    (**(code **)(*local_9c + 4))();
  }
  piVar4 = *(int **)(iVar3 + 0x20);
  if (piVar4 != (int *)0x0) {
    piVar1 = piVar4 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*piVar4 + 8))();
    }
  }
  *(int **)(iVar3 + 0x20) = piVar5;
  *(undefined1 *)(iVar3 + 0x24) = local_98;
  *(undefined1 *)(iVar3 + 0x25) = uStack_97;
  *(undefined1 *)(iVar3 + 0x26) = uStack_96;
  iVar3 = *(int *)(param_1 + 0x18);
  *(uint *)(iVar3 + 0xbc) = *(uint *)(iVar3 + 0xbc) | 1;
  if (*(int *)(*(int *)(param_1 + 0x174) + 0x128) == 0) {
    FUN_00687320(&fStack_94);
    afStack_7c[1] = fStack_84 - fStack_90;
    fStack_68 = fStack_80 - fStack_8c;
    if (fStack_80 - fStack_8c < fStack_88 - fStack_94) {
      fStack_68 = fStack_88 - fStack_94;
    }
    fStack_68 = fStack_68 * DAT_00a0f298;
    puVar8 = *(undefined4 **)(*(int *)(param_1 + 0x50) + 0xf4);
    afStack_7c[3] = (float)*puVar8;
    afStack_7c[0] = 0.0 - fStack_68;
    afStack_7c[2] = 0.0;
    uStack_5c = puVar8[2];
    uStack_60 = 0;
    uStack_48 = puVar8[4];
    uStack_50 = 0;
    uStack_4c = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = puVar8[6];
    uStack_6c = puVar8[1];
    uStack_58 = puVar8[3];
    uStack_44 = puVar8[5];
    uStack_30 = puVar8[7];
    fStack_64 = afStack_7c[1];
    fStack_54 = fStack_68;
    fStack_40 = afStack_7c[0];
    uVar6 = FUN_00414bc0(0x102);
    puStack_8._0_1_ = 2;
    FUN_00414c20(4,uVar6,0x22,0);
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    uStack_18 = 0;
    uStack_14 = 0;
    if (pvStack_24 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvStack_24);
    }
    iVar9 = *(int *)(iVar3 + 0x14);
    if ((*(int *)(iVar9 + 0x10) != 0) &&
       (pfVar7 = (float *)FUN_00746520(*(undefined4 *)(iVar9 + 0x14),*(undefined4 *)(iVar9 + 0x18),0
                                      ), pfVar7 != (float *)0x0)) {
      pfVar10 = afStack_7c;
      for (iVar9 = 0x14; iVar9 != 0; iVar9 = iVar9 + -1) {
        *pfVar7 = *pfVar10;
        pfVar10 = pfVar10 + 1;
        pfVar7 = pfVar7 + 1;
      }
    }
    if (*(int *)(*(int *)(iVar3 + 0x14) + 0x10) != 0) {
      FUN_007464e0();
    }
    *(undefined4 *)(*(int *)(param_1 + 0x174) + 0x118) = *(undefined4 *)(iVar3 + 0x14);
  }
  else {
    piVar5 = *(int **)(*(int *)(param_1 + 0x174) + 0x118);
    if ((piVar5 != (int *)0x0) && (piVar5[1] = piVar5[1] + 1, piVar5[1] == 1)) {
      (**(code **)(*piVar5 + 4))();
    }
    piVar4 = *(int **)(iVar3 + 0x14);
    if (piVar4 != (int *)0x0) {
      piVar1 = piVar4 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar4 + 8))();
      }
    }
    *(int **)(iVar3 + 0x14) = piVar5;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 0xac) = 6;
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 0xa8) = 2;
  FUN_0096f740();
  puVar2 = (uint *)(*(int *)(param_1 + 0x18) + 0xbc);
  *puVar2 = *puVar2 & 0xfffffffe;
  FUN_007647c0(*(undefined4 *)(param_1 + 0x18));
  if (*(int *)(*(int *)(param_1 + 0x18) + 0x20) == 0) {
    puVar8 = (undefined4 *)&stack0xffffff60;
  }
  else {
    puVar8 = (undefined4 *)FUN_00752370(auStack_2c,"AlphaRefValue");
  }
  *(undefined4 *)(*(int *)(param_1 + 0x18) + 0xd8) = *puVar8;
  puStack_8 = (undefined1 *)0xffffffff;
  FUN_0096f510();
  ExceptionList = pvStack_10;
  return;
}
```
