# Raw capture: FUN_006ec7f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ec7f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ec7f0` |
| **Canonical name** | `FUN_006ec7f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006ec7f0(int *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  undefined **local_a8;
  uint uStack_a4;
  float fStack_9c;
  int local_98;
  int iStack_94;
  undefined ***pppuStack_90;
  int iStack_8c;
  undefined1 *local_88;
  int *local_84;
  float fStack_80;
  float fStack_7c;
  undefined1 local_70 [32];
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  
  iVar4 = *param_1;
  local_98 = iVar4;
  FUN_006e8880(param_1[2]);
  FUN_006c7fa0(0);
  local_88 = local_70;
  local_84 = param_1;
  iStack_94 = (**(code **)(*(int *)*param_2 + 0x14))();
  iVar6 = 0;
  if (0 < *(int *)(iVar4 + 0xc)) {
    pfVar5 = (float *)(iVar4 + 0x18);
    do {
      fVar1 = pfVar5[-2];
      fVar2 = pfVar5[-1];
      iVar4 = param_1[2];
      fVar3 = *pfVar5;
      pppuStack_90 = &local_a8;
      fStack_80 = fStack_50 * fVar1 + fStack_40 * fVar2 + fStack_30 * fVar3;
      fStack_7c = fStack_4c * fVar1 + fStack_3c * fVar2 + fStack_2c * fVar3;
      fStack_20 = fStack_80 + *(float *)(iVar4 + 0x50);
      fStack_1c = fStack_7c + *(float *)(iVar4 + 0x54);
      fStack_18 = fStack_38 * fVar2 + fStack_28 * fVar3 + fStack_48 * fVar1 +
                  *(float *)(iVar4 + 0x58);
      uStack_14 = *(undefined4 *)(iVar4 + 0x5c);
      fStack_9c = pfVar5[1];
      iStack_8c = iVar6;
      iVar4 = FUN_00668190();
      (**(code **)(*param_3 + 0x218c + (iVar4 * 0x20 + iStack_94) * 4))
                (&pppuStack_90,param_2,param_3,param_4);
      iVar6 = iVar6 + 1;
      pfVar5 = pfVar5 + 4;
    } while (iVar6 < *(int *)(local_98 + 0xc));
  }
  local_a8 = &PTR_FUN_009d81e8;
  if ((char)(uStack_a4 >> 8) < '\0') {
    uStack_a4 = uStack_a4 & 0xffff7fff;
    FUN_005ffdb0(0);
  }
  return;
}
```
