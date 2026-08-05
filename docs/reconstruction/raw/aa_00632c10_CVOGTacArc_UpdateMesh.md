# Raw capture: CVOGTacArc_UpdateMesh

| Field | Value |
|---|---|
| **Stable ID** | `aa_00632c10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00632c10` |
| **Canonical name** | `CVOGTacArc_UpdateMesh` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall CVOGTacArc_UpdateMesh(int param_1,float param_2)

{
  uint *puVar1;
  int *piVar2;
  undefined4 uVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined4 *puVar18;
  int iVar19;
  float10 fVar20;
  float fVar21;
  float fVar22;
  double dVar23;
  char local_35;
  undefined2 uStack_34;
  char cStack_32;
  float local_30;
  float local_2c;
  undefined4 local_28;
  float local_24;
  int iStack_1c;
  float afStack_14 [2];
  float fStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  if ((*(int *)(param_1 + 0x18) == 0) || (*(int *)(param_1 + 0x1c) == 0)) {
    return 0xffffffff;
  }
  iVar13 = *(int *)(param_1 + 0x20);
  if (iVar13 == 0) {
    local_2c = *(float *)(param_1 + 0x44);
    local_35 = *(char *)(param_1 + 0x40);
    iVar13 = *(int *)(param_1 + 0x50);
    local_24 = *(float *)(param_1 + 0x4c);
    local_30 = *(float *)(param_1 + 0x48);
  }
  else {
    local_2c = *(float *)(iVar13 + 0xdc);
    local_35 = *(char *)(iVar13 + 0xcb);
    local_24 = *(float *)(iVar13 + 0xd8);
    iVar13 = FUN_0056a680(0);
    iVar14 = *(int *)(param_1 + 0x20);
    local_30 = *(float *)(iVar14 + 0xe8);
    piVar2 = *(int **)(*(int *)(*(int *)(iVar14 + 4) + 4) + 0xb0 + iVar14);
    if ((piVar2 != (int *)0x0) && (iVar14 = (**(code **)(*piVar2 + 0x19c))(), iVar14 != 0)) {
      local_30 = *(float *)(iVar14 + 0x34) + local_30;
    }
  }
  local_28 = 0xffffffff;
  if (ABS(local_2c) < g_flOne) {
    fVar20 = (float10)_CIacos();
    local_2c = (float)fVar20;
  }
  else {
    bVar4 = local_2c <= 0.0;
    local_2c = 0.0;
    if (bVar4) {
      local_2c = DAT_009e3530;
    }
  }
  iVar14 = *(int *)(param_1 + 0x28);
  fVar5 = (float)*(int *)(param_1 + 0x28);
  if (iVar14 < 0) {
    fVar5 = fVar5 + _DAT_00aaa5dc;
  }
  fStack_c = (local_2c + local_2c) / fVar5;
  fStack_4 = (float)(iVar14 * 5);
  if (iVar14 * 5 < 0) {
    fStack_4 = fStack_4 + _DAT_00aaa5dc;
  }
  fStack_4 = g_flOne / fStack_4;
  uVar17 = *(undefined4 *)(param_1 + 0x30);
  uVar3 = *(undefined4 *)(param_1 + 0x38);
  uStack_8 = *(undefined4 *)(param_1 + 0x3c);
  *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) + param_2;
  iVar19 = -1;
  afStack_14[0] = param_2 * g_flMultiKillCountBlend + *(float *)(param_1 + 0x14);
  iStack_1c = -1;
  *(float *)(param_1 + 0x14) = afStack_14[0];
  fVar6 = g_flOne;
  if (local_35 == '\0') {
    if (*(char *)(param_1 + 4) != '\0') {
      param_2 = param_2 + *(float *)(param_1 + 0xc);
      *(float *)(param_1 + 0xc) = param_2;
      if (param_2 < *(float *)(param_1 + 8)) {
        cStack_32 = (char)((uint)uVar17 >> 0x10);
        cVar10 = FUN_006a3db0();
        uStack_34._1_1_ = (char)((uint)uVar17 >> 8);
        cVar11 = FUN_006a3db0();
        uStack_34._0_1_ = (char)uVar17;
        uStack_34 = CONCAT11(uStack_34._1_1_ + cVar11,(char)uStack_34);
        cVar11 = FUN_006a3db0();
        cVar12 = FUN_006a3db0();
        uVar17 = CONCAT13('f' - cVar12,
                          (int3)CONCAT31(CONCAT12(cStack_32 + cVar10,uStack_34) >> 8,
                                         (char)uStack_34 + cVar11));
      }
      else {
        *(undefined1 *)(param_1 + 4) = 0;
        *(undefined4 *)(param_1 + 0xc) = 0;
      }
    }
    goto LAB_00632eea;
  }
  local_24 = local_24 / ((float)iVar13 * g_flMsToSeconds_Inferred);
  *(undefined1 *)(param_1 + 4) = 1;
  if (fVar6 < local_24) {
LAB_00632e1f:
    local_35 = '\0';
    uVar17 = uVar3;
  }
  else {
    if (0.0 <= local_24) {
      if (fVar6 <= local_24) goto LAB_00632e1f;
    }
    else {
      local_24 = 0.0;
    }
    iVar19 = (int)(fVar5 * local_24 * DAT_00a0f298);
    iStack_1c = iVar14 - iVar19;
    uVar17 = local_28;
  }
LAB_00632eea:
  dVar23 = modf((double)afStack_14[0],(double *)afStack_14);
  uVar9 = DAT_00a14000;
  fVar6 = DAT_00a0f734;
  fVar5 = g_flOverheatCoolFrac;
  afStack_14[0] = (float)dVar23 * DAT_00a0f734;
  iVar13 = 0;
  if (0 < *(int *)(param_1 + 0x28)) {
    iVar14 = 0;
    fVar21 = afStack_14[0];
    local_2c = 0.0 - local_2c;
    do {
      fVar8 = g_flMultiKillCountBlend;
      if ((local_35 != '\0') && ((iVar13 < iVar19 || (uVar17 = uStack_8, iStack_1c <= iVar13)))) {
        uVar17 = uVar3;
      }
      fVar20 = (float10)fsin((float10)local_2c);
      fVar22 = local_2c + fStack_c;
      *(float *)(iVar14 + *(int *)(param_1 + 0x2c)) = (float)(fVar20 * (float10)local_30);
      fVar20 = (float10)fcos((float10)local_2c);
      *(float *)(*(int *)(param_1 + 0x2c) + 4 + iVar14) = fVar5;
      fVar7 = g_flOne;
      *(float *)(*(int *)(param_1 + 0x2c) + 8 + iVar14) = (float)(fVar20 * (float10)local_30);
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xc + iVar14) = uVar17;
      *(float *)(*(int *)(param_1 + 0x2c) + 0x10 + iVar14) = fVar8;
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x14 + iVar14) = uVar9;
      *(float *)(*(int *)(param_1 + 0x2c) + 0x18 + iVar14) = fVar21;
      fVar21 = fVar21 + fStack_4;
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x1c + iVar14) = 0;
      if (fVar7 < fVar21) {
        fVar21 = fVar7;
      }
      fVar20 = (float10)fsin((float10)fVar22);
      iVar13 = iVar13 + 1;
      iVar14 = iVar14 + 0x60;
      *(float *)(*(int *)(param_1 + 0x2c) + -0x40 + iVar14) = (float)(fVar20 * (float10)local_30);
      fVar20 = (float10)fcos((float10)fVar22);
      *(float *)(*(int *)(param_1 + 0x2c) + -0x3c + iVar14) = fVar5;
      *(float *)(*(int *)(param_1 + 0x2c) + -0x38 + iVar14) = (float)(fVar20 * (float10)local_30);
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + -0x34 + iVar14) = uVar17;
      *(float *)(*(int *)(param_1 + 0x2c) + -0x30 + iVar14) = fVar8;
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + -0x2c + iVar14) = uVar9;
      *(float *)(*(int *)(param_1 + 0x2c) + -0x28 + iVar14) = fVar21;
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + -0x24 + iVar14) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + -0x20 + iVar14) = 0;
      *(float *)(*(int *)(param_1 + 0x2c) + -0x1c + iVar14) = fVar5;
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + -0x18 + iVar14) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + -0x14 + iVar14) = uVar17;
      *(float *)(*(int *)(param_1 + 0x2c) + -0x10 + iVar14) = fVar8;
      *(float *)(*(int *)(param_1 + 0x2c) + -0xc + iVar14) = fVar6;
      *(float *)(*(int *)(param_1 + 0x2c) + -8 + iVar14) = (float)dVar23;
      *(float *)(*(int *)(param_1 + 0x2c) + -4 + iVar14) = fVar7;
      local_2c = fVar22;
    } while (iVar13 < *(int *)(param_1 + 0x28));
  }
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x14) = uVar9;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x50) = 0;
  *(float *)(*(int *)(param_1 + 0x2c) + 0x54) = fVar6;
  iVar13 = (*(int *)(param_1 + 0x28) + -1) * 0x60;
  *(undefined4 *)(iVar13 + 0x30 + *(int *)(param_1 + 0x2c)) = 0;
  *(undefined4 *)(iVar13 + 0x34 + *(int *)(param_1 + 0x2c)) = uVar9;
  *(undefined4 *)(iVar13 + 0x50 + *(int *)(param_1 + 0x2c)) = 0;
  *(float *)(iVar13 + 0x54 + *(int *)(param_1 + 0x2c)) = fVar6;
  iVar13 = *(int *)(param_1 + 0x1c);
  *(uint *)(iVar13 + 0xbc) = *(uint *)(iVar13 + 0xbc) | 1;
  iVar14 = *(int *)(iVar13 + 0x14);
  iVar19 = *(int *)(param_1 + 0x28) * 3;
  if (*(int *)(iVar14 + 0x10) != 0) {
    if (iVar19 < 1) {
      iVar19 = *(int *)(iVar14 + 0x18);
    }
    puVar15 = (undefined4 *)FUN_00746520(*(undefined4 *)(iVar14 + 0x14),iVar19,1);
    if (puVar15 != (undefined4 *)0x0) {
      puVar18 = *(undefined4 **)(param_1 + 0x2c);
      for (uVar16 = (uint)(*(int *)(param_1 + 0x28) * 0x60) >> 2; uVar16 != 0; uVar16 = uVar16 - 1)
      {
        *puVar15 = *puVar18;
        puVar18 = puVar18 + 1;
        puVar15 = puVar15 + 1;
      }
      for (iVar14 = 0; iVar14 != 0; iVar14 = iVar14 + -1) {
        *(undefined1 *)puVar15 = *(undefined1 *)puVar18;
        puVar18 = (undefined4 *)((int)puVar18 + 1);
        puVar15 = (undefined4 *)((int)puVar15 + 1);
      }
      if (*(int *)(*(int *)(iVar13 + 0x14) + 0x10) != 0) {
        FUN_007464e0();
      }
      puVar1 = (uint *)(*(int *)(param_1 + 0x1c) + 0xbc);
      *puVar1 = *puVar1 & 0xfffffffe;
      return 0;
    }
  }
  if (*(int *)(*(int *)(iVar13 + 0x14) + 0x10) != 0) {
    FUN_007464e0();
  }
  return 0xffffffff;
}
```
