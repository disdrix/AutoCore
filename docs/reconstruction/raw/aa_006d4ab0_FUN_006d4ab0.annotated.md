# Annotated low-level: FUN_006d4ab0

| Field | Value |
|---|---|
| Stable ID | `aa_006d4ab0` |
| VA | `0x006d4ab0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006d4ab0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006d4ab0(int *param_1,undefined4 *param_2,undefined4 param_3,int *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined8 uVar5;
  float *pfVar6;
  float *pfVar7;
  int local_e8;
  char local_e4 [4];
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float local_cc;
  int *local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a0;
  float local_9c;
  float local_98;
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
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_4c;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  int *local_20;
  undefined4 *local_1c;
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "TtmultiRay-cvx";
    uVar5 = rdtsc();
    DAT_00bc5644[1] = (int)uVar5;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  local_b4 = (int *)*param_2;
  iVar4 = *param_1;
  FUN_0063a3f0(param_2[2] + 0x20,param_1[2] + 0x20);
  local_e8 = *(int *)(iVar4 + 0x14);
  pfVar7 = *(float **)(iVar4 + 0x10);
  local_20 = param_1;
  local_1c = param_2;
  local_4c = 0;
  if (0 < local_e8) {
    pfVar6 = pfVar7 + 6;
    do {
      fVar1 = *pfVar7;
      fVar2 = pfVar6[-5];
      fVar3 = pfVar6[-4];
      local_64 = 0;
      local_cc = 1.0;
      local_70 = local_b0 * fVar1 + local_a0 * fVar2 + local_90 * fVar3 + local_80;
      local_6c = local_ac * fVar1 + local_9c * fVar2 + local_8c * fVar3 + local_7c;
      local_68 = local_a8 * fVar1 + local_98 * fVar2 + local_88 * fVar3 + local_78;
      fVar1 = pfVar6[-2];
      fVar2 = pfVar6[-1];
      fVar3 = *pfVar6;
      local_54 = 0;
      local_60 = local_b0 * fVar1 + local_a0 * fVar2 + local_90 * fVar3 + local_80;
      local_5c = local_ac * fVar1 + local_9c * fVar2 + local_8c * fVar3 + local_7c;
      local_58 = local_a8 * fVar1 + local_98 * fVar2 + local_88 * fVar3 + local_78;
      (**(code **)(*local_b4 + 0x20))(local_e4,&local_70,&local_e0);
      if (local_e4[0] != '\0') {
        iVar4 = param_2[2];
        fVar1 = g_flOne - local_cc;
        fVar2 = local_60 * local_cc + local_70 * fVar1;
        fVar3 = local_5c * local_cc + local_6c * fVar1;
        fVar1 = local_58 * local_cc + local_68 * fVar1;
        fStack_40 = fVar2 * *(float *)(iVar4 + 0x20) +
                    fVar3 * *(float *)(iVar4 + 0x30) + fVar1 * *(float *)(iVar4 + 0x40) +
                    *(float *)(iVar4 + 0x50);
        fStack_3c = fVar2 * *(float *)(iVar4 + 0x24) +
                    fVar3 * *(float *)(iVar4 + 0x34) + fVar1 * *(float *)(iVar4 + 0x44) +
                    *(float *)(iVar4 + 0x54);
        fStack_38 = fVar2 * *(float *)(iVar4 + 0x28) +
                    fVar3 * *(float *)(iVar4 + 0x38) + fVar1 * *(float *)(iVar4 + 0x48) +
                    *(float *)(iVar4 + 0x58);
        fStack_34 = (local_cc - g_flOne) * pfVar6[-3];
        fStack_30 = local_e0 * *(float *)(iVar4 + 0x20) +
                    fStack_dc * *(float *)(iVar4 + 0x30) + fStack_d8 * *(float *)(iVar4 + 0x40);
        fStack_2c = local_e0 * *(float *)(iVar4 + 0x24) +
                    fStack_dc * *(float *)(iVar4 + 0x34) + fStack_d8 * *(float *)(iVar4 + 0x44);
        fStack_28 = local_e0 * *(float *)(iVar4 + 0x28) +
                    fStack_dc * *(float *)(iVar4 + 0x38) + fStack_d8 * *(float *)(iVar4 + 0x48);
        uStack_24 = 0;
        (**(code **)(*param_4 + 4))(&fStack_40);
      }
      pfVar7 = pfVar7 + 8;
      pfVar6 = pfVar6 + 8;
      local_e8 = local_e8 + -1;
    } while (local_e8 != 0);
  }
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d2878;
    uVar5 = rdtsc();
    DAT_00bc5644[1] = (int)uVar5;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
