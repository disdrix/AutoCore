# Raw capture: FUN_005fecb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fecb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fecb0` |
| **Canonical name** | `FUN_005fecb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005fecb0(int param_1,float param_2)

{
  float *pfVar1;
  ushort uVar2;
  float fVar3;
  int iVar4;
  char *_Source;
  uint uVar5;
  size_t _Count;
  char local_64 [4];
  char local_60 [2];
  char local_5e;
  
  iVar4 = CVOGReaction_RandomUnitScalar();
  if (0xfffff < *(int *)(iVar4 + 0xc)) {
    *(undefined4 *)(iVar4 + 0xc) = 0;
  }
  uVar2 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
  *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
  fVar3 = g_flVehicleHpTechCoeff;
  uVar5 = (uint)uVar2 % 6;
  if ((param_2 != 0.0) &&
     (pfVar1 = (float *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x1c + param_1),
     *pfVar1 <= param_2 && param_2 != *pfVar1)) {
    uVar5 = 0;
  }
  if (uVar5 == 0) {
    *(short *)(param_1 + -0x2a) = *(short *)(param_1 + -0x2a) + -0x14;
    iVar4 = *(int *)(*(int *)(param_1 + -0xdc) + 4);
    *(float *)(iVar4 + -0x1c + param_1) = *(float *)(iVar4 + -0x1c + param_1) * DAT_00a0f298;
    local_64 = (char  [4])s_Light_009dd768._0_4_;
    local_60 = (char  [2])s_Light_009dd768._4_2_;
    local_5e = s_Light_009dd768[6];
  }
  else {
    if (uVar5 != 1) {
      return;
    }
    if ((param_2 != 0.0) &&
       (param_2 < *(float *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x1c + param_1) *
                  g_flVehicleHpTechCoeff)) {
      return;
    }
    if (0x55 < *(short *)(param_1 + -0x2a)) {
      return;
    }
    *(short *)(param_1 + -0x2a) = *(short *)(param_1 + -0x2a) + 10;
    iVar4 = *(int *)(*(int *)(param_1 + -0xdc) + 4);
    *(float *)(iVar4 + -0x1c + param_1) = *(float *)(iVar4 + -0x1c + param_1) * fVar3;
    local_64 = (char  [4])DAT_009dd770;
    local_60 = (char  [2])DAT_009dd774;
    local_5e = DAT_009dd776;
  }
  _Count = 0x5d;
  _Source = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1)
                                + 0x15c))();
  strncat(local_64,_Source,_Count);
  FUN_00516720(local_64);
  return;
}
```
