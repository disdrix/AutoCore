# Raw capture: FUN_006fa7d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006fa7d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006fa7d0` |
| **Canonical name** | `FUN_006fa7d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_006fa7d0(int param_1,int param_2,undefined4 param_3,undefined2 param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  uint uVar15;
  float *pfVar16;
  int iVar17;
  bool bVar18;
  undefined2 uVar19;
  uint local_6c;
  uint local_68;
  undefined4 local_64;
  undefined4 local_60;
  float local_5c;
  undefined4 local_58;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30 [4];
  float local_20 [7];
  
  if (0 < *(int *)(param_2 + 0x54)) {
    iVar7 = *(int *)**(int **)(param_1 + 0x10);
    iVar17 = (((int *)**(int **)(param_1 + 0x10))[1] - *(int *)(param_2 + 0x54)) * 0x30;
    fVar1 = *(float *)(iVar17 + 0x10 + iVar7);
    iVar17 = iVar17 + iVar7;
    pfVar16 = *(float **)(param_1 + 0x14);
    fVar2 = *(float *)(iVar17 + 0x14);
    fVar3 = *(float *)(iVar17 + 0x18);
    local_44 = 0;
    local_34 = 0;
    pfVar8 = *(float **)(param_1 + 0x18);
    fVar4 = *(float *)(iVar17 + 0x10);
    fVar5 = *(float *)(iVar17 + 0x14);
    fVar6 = *(float *)(iVar17 + 0x18);
    local_50 = fVar4 * *pfVar8 + fVar5 * pfVar8[1] + fVar6 * pfVar8[2];
    local_4c = fVar5 * pfVar8[5] + fVar4 * pfVar8[4] + fVar6 * pfVar8[6];
    local_48 = fVar5 * pfVar8[9] + fVar4 * pfVar8[8] + fVar6 * pfVar8[10];
    local_40 = -(fVar1 * *pfVar16 + fVar2 * pfVar16[1] + fVar3 * pfVar16[2]);
    local_3c = -(fVar1 * pfVar16[4] + fVar2 * pfVar16[5] + fVar3 * pfVar16[6]);
    local_38 = -(fVar1 * pfVar16[8] + fVar2 * pfVar16[9] + fVar3 * pfVar16[10]);
    local_20[0] = ABS(local_40);
    local_20[1] = ABS(local_3c);
    local_20[2] = ABS(local_38);
    local_30[3] = ABS((float)_DAT_00aaa608);
    local_30[0] = ABS(local_50);
    local_30[1] = ABS(local_4c);
    local_30[2] = ABS(local_48);
    bVar18 = ABS(local_40) <= ABS(local_3c);
    if (bVar18) {
      local_60 = 0x40;
    }
    else {
      local_60 = 0x80;
    }
    local_68 = (uint)bVar18;
    uVar15 = (uint)bVar18;
    if (local_20[uVar15] < ABS(local_38)) {
      local_68 = 2;
      local_60 = 0x20;
      uVar15 = 2;
    }
    if (local_30[0] <= local_30[1]) {
      local_64 = 0x40;
    }
    else {
      local_64 = 0x80;
    }
    local_6c = (uint)(local_30[0] <= local_30[1]);
    if (local_30[local_6c] < ABS(local_48)) {
      local_6c = 2;
      local_64 = 0x20;
    }
    if ((_DAT_00a0ef10 <= local_20[uVar15]) && (_DAT_00a0ef10 <= local_30[local_6c])) {
      local_20[3] = local_30[3];
      uVar13 = FUN_006f80d0(*(undefined4 *)(param_1 + 0xb0 + uVar15 * 4));
      uVar19 = 0x6f;
      uVar14 = FUN_006f80d0(*(undefined4 *)(param_1 + 0xc0 + local_6c * 4));
      param_3 = CONCAT22(uVar13,(undefined2)local_68);
      local_58 = CONCAT22(uVar14,(short)local_6c + 3);
      local_5c = 1.0;
      if (0 < *(int *)(param_2 + 0x54)) {
        pfVar16 = (float *)(iVar17 + 0xc);
        iVar17 = *(int *)(param_2 + 0x54);
        do {
          if (*pfVar16 < local_5c) {
            local_5c = *pfVar16;
          }
          pfVar16 = pfVar16 + 0xc;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
      }
      uVar15 = CONCAT22(uVar19,param_4);
      FUN_006f8d00(param_2,param_3,uVar15,local_64,local_5c);
      FUN_006f8e00(param_2,local_58,uVar15 & 0xffff0000,local_60,local_5c);
      if (3 < *(int *)(param_2 + 0x50)) {
        *(undefined1 *)(param_2 + 0x58) = 1;
        return;
      }
      if (DAT_00d09690 != '\0') {
        uVar9 = *(undefined4 *)(&DAT_00a0ef24 + local_6c * 2);
        local_50 = -local_50;
        uVar10 = *(undefined4 *)(&DAT_00a0ef24 + local_68 * 2);
        uVar11 = *(undefined4 *)(&UNK_00a0ef28 + local_68 * 4);
        local_4c = -local_4c;
        uVar12 = *(undefined4 *)(&UNK_00a0ef28 + local_6c * 4);
        local_48 = -local_48;
        local_44 = 0;
        FUN_006fa6f0(param_2,uVar10,uVar9,uVar11,uVar12,&local_40,&local_50,local_5c);
        FUN_006fa6f0(param_2,uVar10,uVar12,uVar11,uVar9,&local_40,&local_50,local_5c);
        FUN_006fa6f0(param_2,uVar11,uVar9,uVar10,uVar12,&local_40,&local_50,local_5c);
        FUN_006fa6f0(param_2,uVar11,uVar12,uVar10,uVar9,&local_40,&local_50,local_5c);
      }
      FUN_006f7d90(param_2,local_60,local_64);
    }
  }
  return;
}
```
