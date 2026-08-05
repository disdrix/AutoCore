# Raw capture: FUN_006e1fd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006e1fd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006e1fd0` |
| **Canonical name** | `FUN_006e1fd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006e1fd0(int param_1,int *param_2,int *param_3,int param_4,int *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  float *pfVar9;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  int *local_70;
  int *local_6c;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  float local_50;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "TtSphereTriangle";
    uVar8 = rdtsc();
    DAT_00bc5644[1] = (int)uVar8;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  iVar4 = *param_3;
  local_70 = param_2;
  local_6c = param_3;
  fVar1 = *(float *)(iVar4 + 0x10);
  fVar2 = *(float *)(iVar4 + 0x14);
  iVar5 = param_2[2];
  fVar3 = *(float *)(iVar4 + 0x18);
  iVar6 = *param_2;
  iVar7 = param_3[2];
  pfVar9 = (float *)(iVar7 + 0x20);
  local_40 = fVar1 * *pfVar9 + fVar2 * *(float *)(iVar7 + 0x30) + fVar3 * *(float *)(iVar7 + 0x40) +
             *(float *)(iVar7 + 0x50);
  local_3c = fVar2 * *(float *)(iVar7 + 0x34) +
             fVar3 * *(float *)(iVar7 + 0x44) + fVar1 * *(float *)(iVar7 + 0x24) +
             *(float *)(iVar7 + 0x54);
  local_38 = fVar2 * *(float *)(iVar7 + 0x38) +
             fVar3 * *(float *)(iVar7 + 0x48) + fVar1 * *(float *)(iVar7 + 0x28) +
             *(float *)(iVar7 + 0x58);
  local_34 = 0;
  fVar1 = *(float *)(iVar4 + 0x20);
  fVar2 = *(float *)(iVar4 + 0x24);
  fVar3 = *(float *)(iVar4 + 0x28);
  local_30 = fVar1 * *pfVar9 + fVar2 * *(float *)(iVar7 + 0x30) + fVar3 * *(float *)(iVar7 + 0x40) +
             *(float *)(iVar7 + 0x50);
  local_2c = fVar2 * *(float *)(iVar7 + 0x34) +
             fVar3 * *(float *)(iVar7 + 0x44) + fVar1 * *(float *)(iVar7 + 0x24) +
             *(float *)(iVar7 + 0x54);
  local_28 = fVar2 * *(float *)(iVar7 + 0x38) +
             fVar3 * *(float *)(iVar7 + 0x48) + fVar1 * *(float *)(iVar7 + 0x28) +
             *(float *)(iVar7 + 0x58);
  local_24 = 0;
  fVar1 = *(float *)(iVar4 + 0x30);
  fVar2 = *(float *)(iVar4 + 0x34);
  fVar3 = *(float *)(iVar4 + 0x38);
  local_20 = fVar1 * *pfVar9 + fVar2 * *(float *)(iVar7 + 0x30) + fVar3 * *(float *)(iVar7 + 0x40) +
             *(float *)(iVar7 + 0x50);
  local_1c = fVar2 * *(float *)(iVar7 + 0x34) +
             fVar3 * *(float *)(iVar7 + 0x44) + fVar1 * *(float *)(iVar7 + 0x24) +
             *(float *)(iVar7 + 0x54);
  local_18 = fVar2 * *(float *)(iVar7 + 0x38) +
             fVar3 * *(float *)(iVar7 + 0x48) + fVar1 * *(float *)(iVar7 + 0x28) +
             *(float *)(iVar7 + 0x58);
  local_14 = 0;
  FUN_006f7820((float *)(iVar5 + 0x50),&local_40,param_1 + 0x10,&local_60);
  local_84 = *(float *)(iVar6 + 0xc) + *(float *)(iVar4 + 0xc);
  if (local_50 < local_84 + *(float *)(param_4 + 8)) {
    fVar1 = *(float *)(iVar4 + 0xc) - local_50;
    local_80 = local_60;
    local_90 = local_60 * fVar1 + *(float *)(iVar5 + 0x50);
    local_78 = local_58;
    local_74 = local_54;
    local_7c = local_5c;
    local_8c = local_5c * fVar1 + *(float *)(iVar5 + 0x54);
    local_88 = local_58 * fVar1 + *(float *)(iVar5 + 0x58);
    local_84 = local_50 - local_84;
    (**(code **)(*param_5 + 4))(&local_90);
  }
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d2878;
    uVar8 = rdtsc();
    DAT_00bc5644[1] = (int)uVar8;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```
