# Raw capture: FUN_006f5de0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006f5de0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006f5de0` |
| **Canonical name** | `FUN_006f5de0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006f5de0(int param_1,int param_2,int param_3,int param_4,int *param_5,int param_6,
                 int *param_7)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  ushort uVar8;
  undefined4 *puVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_40 [15];
  
  fVar1 = *(float *)(*(int *)(param_3 + 0xc) + 4);
  fVar1 = fVar1 * fVar1;
  iVar11 = -1;
  iVar12 = 0;
  if (0 < *param_7) {
    pfVar10 = (float *)(param_6 + 0x28);
    do {
      fVar6 = pfVar10[-10] - *(float *)(param_4 + 0x10);
      fVar5 = pfVar10[-9] - *(float *)(param_4 + 0x14);
      fVar4 = pfVar10[-8] - *(float *)(param_4 + 0x18);
      fVar4 = fVar6 * fVar6 + fVar5 * fVar5 + fVar4 * fVar4;
      if ((fVar4 < fVar1) &&
         (fVar5 = pfVar10[-2] - *(float *)(param_4 + 0x40),
         fVar7 = pfVar10[-1] - *(float *)(param_4 + 0x44),
         fVar6 = *pfVar10 - *(float *)(param_4 + 0x48),
         fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6 < _DAT_00a0eee4)) {
        iVar11 = iVar12;
        fVar1 = fVar4;
      }
      iVar12 = iVar12 + 1;
      pfVar10 = pfVar10 + 0xc;
    } while (iVar12 < *param_7);
    if (-1 < iVar11) {
      uVar2 = *(undefined4 *)(iVar11 * 0x30 + 0x1c + param_6);
      puVar9 = (undefined4 *)(iVar11 * 0x30 + param_6);
      *puVar9 = *(undefined4 *)(param_4 + 0x10);
      puVar9[1] = *(undefined4 *)(param_4 + 0x14);
      puVar9[2] = *(undefined4 *)(param_4 + 0x18);
      puVar9[3] = *(undefined4 *)(param_4 + 0x1c);
      puVar9[4] = *(undefined4 *)(param_4 + 0x30);
      puVar9[5] = *(undefined4 *)(param_4 + 0x34);
      puVar9[6] = *(undefined4 *)(param_4 + 0x38);
      puVar9[7] = *(undefined4 *)(param_4 + 0x3c);
      puVar9[8] = *(undefined4 *)(param_4 + 0x40);
      puVar9[9] = *(undefined4 *)(param_4 + 0x44);
      puVar9[10] = *(undefined4 *)(param_4 + 0x48);
      puVar9[0xb] = *(undefined4 *)(param_4 + 0x4c);
      puVar9[0xb] = *(undefined4 *)(param_4 + 0x20);
      uVar3 = *(undefined4 *)(param_4 + 0x24);
      puVar9[7] = uVar2;
      puVar9[3] = uVar3;
      return;
    }
    if (3 < iVar12) {
      puVar9 = local_40;
      goto LAB_006f5f1b;
    }
  }
  puVar9 = (undefined4 *)(iVar12 * 0x30 + param_6);
LAB_006f5f1b:
  *puVar9 = *(undefined4 *)(param_4 + 0x10);
  puVar9[1] = *(undefined4 *)(param_4 + 0x14);
  puVar9[2] = *(undefined4 *)(param_4 + 0x18);
  puVar9[3] = *(undefined4 *)(param_4 + 0x1c);
  puVar9[4] = *(undefined4 *)(param_4 + 0x30);
  puVar9[5] = *(undefined4 *)(param_4 + 0x34);
  puVar9[6] = *(undefined4 *)(param_4 + 0x38);
  puVar9[7] = *(undefined4 *)(param_4 + 0x3c);
  puVar9[8] = *(undefined4 *)(param_4 + 0x40);
  puVar9[9] = *(undefined4 *)(param_4 + 0x44);
  puVar9[10] = *(undefined4 *)(param_4 + 0x48);
  puVar9[0xb] = *(undefined4 *)(param_4 + 0x4c);
  puVar9[3] = *(undefined4 *)(param_4 + 0x24);
  puVar9[0xb] = *(undefined4 *)(param_4 + 0x20);
  iVar11 = *(int *)(param_2 + 8);
  FUN_005d68f0(*(int *)(param_1 + 8) + 0x20,puVar9);
  FUN_005d68f0(iVar11 + 0x20,puVar9 + 4);
  fVar1 = *(float *)(param_4 + 0x24);
  local_60 = puVar9[8];
  fVar4 = g_flOne - fVar1;
  local_5c = puVar9[9];
  local_64 = puVar9[0xb];
  local_70 = local_90 * fVar1 + local_80 * fVar4;
  local_6c = local_8c * fVar1 + local_7c * fVar4;
  local_68 = local_88 * fVar1 + local_78 * fVar4;
  local_58 = puVar9[10];
  local_54 = local_64;
  uVar8 = (**(code **)(*param_5 + 4))(param_1,param_2,param_3,&local_70);
  if (uVar8 != 0xffff) {
    puVar9[7] = uVar8 | 0x3f000000;
    iVar11 = *param_7;
    *param_7 = iVar11 + 1;
    if (4 < iVar11 + 1) {
      iVar11 = FUN_006f5670(&stack0xffffff40,param_1,param_2,param_5);
      *param_7 = iVar11;
    }
  }
  return;
}
```
