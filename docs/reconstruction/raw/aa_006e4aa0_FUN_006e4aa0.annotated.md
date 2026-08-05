# Annotated low-level: FUN_006e4aa0

| Field | Value |
|---|---|
| Stable ID | `aa_006e4aa0` |
| VA | `0x006e4aa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006e4aa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
FUN_006e4aa0(int param_1,undefined1 *param_2,int *param_3,int *param_4,int param_5,float *param_6)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float local_1e0 [4];
  float local_1d0;
  float local_1cc;
  float local_1c8;
  float local_1c0;
  float local_1bc;
  float local_1b8;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a0;
  float local_19c;
  float local_198;
  float local_188;
  undefined1 local_174;
  
  iVar1 = *param_3;
  iVar2 = *param_4;
  if (g_flZero < *(float *)(param_1 + 0x2c)) {
    if (DAT_00bc5644 < DAT_00bc5648) {
      *DAT_00bc5644 = "StTim";
      uVar5 = rdtsc();
      DAT_00bc5644[1] = (int)uVar5;
      DAT_00bc5644 = DAT_00bc5644 + 3;
    }
    pfVar3 = (float *)param_4[2];
    pfVar4 = (float *)param_3[2];
    local_188 = pfVar3[6] - pfVar3[2];
    local_1e0[0] = (pfVar3[4] - *pfVar3) - (pfVar4[4] - *pfVar4);
    fVar6 = *(float *)(param_1 + 0x2c) -
            (local_1e0[0] * *(float *)(param_1 + 0x20) +
             ((pfVar3[5] - pfVar3[1]) - (pfVar4[5] - pfVar4[1])) * *(float *)(param_1 + 0x24) +
             (local_188 - (pfVar4[6] - pfVar4[2])) * *(float *)(param_1 + 0x28) + pfVar4[3] +
            pfVar3[3]);
    *(float *)(param_1 + 0x2c) = fVar6;
    if (g_flZero < fVar6) goto LAB_006e4d75;
  }
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "StGsk";
    uVar5 = rdtsc();
    DAT_00bc5644[1] = (int)uVar5;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  FUN_0063a3f0(param_3[2] + 0x20,param_4[2] + 0x20);
  local_174 = 0;
  iVar8 = FUN_006fde40(iVar1,iVar2,&local_1d0,param_1 + 0xc,local_1e0);
  if (iVar8 == 0) {
    FUN_006fb6d0(param_1 + 0xc,local_1e0,param_6);
    FUN_005d6ae0(param_3[2] + 0x20,param_6);
    fVar6 = (param_6[8] - *(float *)(iVar1 + 0xc)) - *(float *)(iVar2 + 0xc);
    param_6[8] = fVar6;
    if (fVar6 < *(float *)(param_5 + 8)) {
      fVar7 = -*(float *)(iVar1 + 0xc);
      param_6[4] = fVar7 * *param_6 + param_6[4];
      param_6[5] = fVar7 * param_6[1] + param_6[5];
      param_6[6] = fVar7 * param_6[2] + param_6[6];
      param_6[7] = fVar7 * param_6[3] + param_6[7];
      fVar6 = -fVar6;
      local_1a0 = (fVar6 * *param_6 + param_6[4]) - local_1a0;
      local_19c = (fVar6 * param_6[1] + param_6[5]) - local_19c;
      local_198 = (fVar6 * param_6[2] + param_6[6]) - local_198;
      param_6[0xc] = local_1d0 * local_1a0 + local_1c8 * local_198 + local_1cc * local_19c;
      param_6[0xd] = local_1c0 * local_1a0 + local_1b8 * local_198 + local_1bc * local_19c;
      param_6[0xe] = local_1b0 * local_1a0 + local_1a8 * local_198 + local_1ac * local_19c;
      *param_2 = 1;
      return;
    }
    if ((*(int *)(param_1 + 0x18) == 0) && (**(char **)(param_5 + 0xc) != '\0')) {
      *(float *)(param_1 + 0x20) = param_6[0x10];
      *(float *)(param_1 + 0x24) = param_6[0x11];
      *(float *)(param_1 + 0x28) = param_6[0x12];
      *(float *)(param_1 + 0x2c) = param_6[0x13];
      *(float *)(param_1 + 0x2c) = fVar6 - *(float *)(param_5 + 8) * DAT_00aaaa10;
    }
  }
LAB_006e4d75:
  *param_2 = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
