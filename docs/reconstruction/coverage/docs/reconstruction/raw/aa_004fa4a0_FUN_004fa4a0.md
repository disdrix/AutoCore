# Raw capture: FUN_004fa4a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fa4a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fa4a0` |
| **Canonical name** | `FUN_004fa4a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004fa4a0(int param_1,char param_2)

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  undefined4 unaff_EBX;
  int iVar4;
  undefined4 unaff_ESI;
  int iVar5;
  float fVar6;
  float fVar7;
  uint local_64;
  uint local_58;
  float fStack_54;
  float local_50;
  float local_4c;
  float local_48;
  float fStack_44;
  uint uStack_40;
  float fStack_3c;
  float fStack_38;
  undefined1 local_2c [4];
  float fStack_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  
  if (*(int *)(param_1 + 600) != 0) {
    iVar4 = param_2 * 0xc0 +
            *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x1a0) + 4) + 0xc) + 0x80);
    if (*(char *)(iVar4 + 0x80) == '\0') {
      *(undefined1 *)(param_2 + 0xf4 + *(int *)(param_1 + 600)) = 0;
      return;
    }
    FUN_004e88e0(&local_50,iVar4 + 0x20);
    if (((local_50 == DAT_00d1a6c0) && (local_4c == DAT_00d1a6c4)) && (local_48 == DAT_00d1a6c8)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    fVar6 = local_48 - *(float *)(DAT_00b04c70 + 0x230);
    local_4c = local_4c - *(float *)(DAT_00b04c70 + 0x22c);
    fVar7 = local_50 - *(float *)(DAT_00b04c70 + 0x228);
    if ((!bVar1) && (SQRT(fVar6 * fVar6 + fVar7 * fVar7 + local_4c * local_4c) <= _DAT_009d82f4)) {
      FUN_004e88e0(local_2c,*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x40);
      FUN_0076f5f0(local_2c,local_2c);
      if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe4f8) != 0) {
        local_64 = 0xff808080;
        uVar2 = FUN_004a8b20(local_50,local_48);
        iVar5 = (int)*(char *)(*(int *)(param_1 + 600) + 0xb0);
        cVar3 = FUN_004a8890(uVar2);
        if (cVar3 == '\0') {
          cVar3 = FUN_004a8810(uVar2);
          if (cVar3 == '\0') {
            cVar3 = FUN_004a8850(uVar2);
            if (cVar3 == '\0') {
              cVar3 = FUN_004a8870(uVar2);
              if (cVar3 == '\0') {
                cVar3 = FUN_004a88f0(uVar2);
                if (cVar3 == '\0') {
                  cVar3 = FUN_004a8830(uVar2);
                  if (cVar3 != '\0') {
                    local_64 = 0xff101010;
                  }
                }
                else {
                  local_64 = 0xff141400;
                  FUN_005a8f90((int)param_2 + iVar5 * 4,*(undefined4 *)(iVar4 + 0x8c));
                }
              }
              else {
                local_64 = 0xff141400;
                FUN_005a8f90((int)param_2 + iVar5 * 3,*(undefined4 *)(iVar4 + 0x8c));
              }
            }
            else {
              local_64 = 0xff141400;
              FUN_005a8f90((int)param_2 + iVar5 * 2,*(undefined4 *)(iVar4 + 0x8c));
            }
          }
          else {
            local_64 = 0xff002000;
            FUN_005a8f90((int)param_2,*(undefined4 *)(iVar4 + 0x8c));
          }
        }
        else {
          local_64 = 0xff808080;
          FUN_005a8f90(param_2 + iVar5,*(undefined4 *)(iVar4 + 0x8c));
        }
        if ((DAT_00a110d8 < *(float *)(iVar4 + 0x94)) &&
           (DAT_009cd10c <
            SQRT(*(float *)(iVar4 + 0x20) * *(float *)(iVar4 + 0x20) +
                 *(float *)(iVar4 + 0x24) * *(float *)(iVar4 + 0x24) +
                 *(float *)(iVar4 + 0x28) * *(float *)(iVar4 + 0x28)))) {
          local_58 = local_64 & 0xffffff;
          FUN_006a3db0();
          (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x3c) + 0x58))(iVar4 + 0x20,&local_20);
          fVar6 = local_20 * local_20 + fStack_24 * fStack_24 + fStack_28 * fStack_28;
          if (SQRT(fVar6) <= DAT_009cd10c) {
            return;
          }
          fVar6 = SQRT(fVar6);
          fVar7 = g_flOne / fVar6;
          fVar6 = fVar6 * DAT_00aaa9b0;
          local_4c = fVar7 * fStack_28;
          local_48 = fStack_24 * fVar7;
          fStack_44 = local_20 * fVar7;
          fStack_1c = fStack_1c * fVar7;
          uStack_40 = local_58;
          fStack_38 = local_50;
          fStack_3c = fStack_54 + g_flOverheatCoolFrac;
          fStack_28 = local_4c;
          fStack_24 = local_48;
          local_20 = fStack_44;
          cVar3 = FUN_004a8830(unaff_EBX);
          if ((cVar3 != '\0') || (cVar3 = FUN_004a8850(unaff_EBX), cVar3 != '\0')) {
            FUN_007a0120(1,0,2,0x26,0,0,0x40c00000,0x3f800000,0x3f333333,fVar6,0,unaff_ESI,uVar2,
                         uStack_40,fStack_3c,fStack_38,uStack_40,fStack_3c,fStack_38,local_4c,
                         local_48,fStack_44,DAT_00afdfd4,DAT_00afdfd8,DAT_00afdfdc,DAT_00d1a6c0,
                         DAT_00d1a6c4,DAT_00d1a6c8,0);
          }
        }
      }
      *(undefined1 *)(param_2 + 0xf4 + *(int *)(param_1 + 600)) = 1;
    }
  }
  return;
}
```
