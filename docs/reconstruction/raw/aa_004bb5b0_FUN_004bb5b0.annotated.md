# Annotated low-level: FUN_004bb5b0

| Field | Value |
|---|---|
| Stable ID | `aa_004bb5b0` |
| VA | `0x004bb5b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bb5b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bb5b0(int param_1,float param_2,float *param_3,float *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  float10 fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  
  iVar2 = CVOGReaction_ResolveObjectTarget
                    (CONCAT31((int3)((uint)*(undefined4 *)(param_1 + 0x44) >> 8),
                              *(undefined1 *)(param_1 + 0x35)),*(undefined4 *)(param_1 + 0x40),
                     *(undefined4 *)(param_1 + 0x44));
  if ((*(char *)(param_1 + 0x39) == '\0') && (*(char *)(param_1 + 0x37) == '\0')) {
    if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0xac), iVar2 != 0)) {
      if (*(char *)(iVar2 + 0x168) == '\x01') {
        if (((*(int *)(iVar2 + 0x160) != *param_5) || (*(int *)(iVar2 + 0x164) != param_5[1])) &&
           ((iVar1 = *(int *)(iVar2 + 0xac), iVar1 == 0 ||
            ((*(int *)(iVar1 + 0x160) != *param_5 || (*(int *)(iVar1 + 0x164) != param_5[1]))))))
        goto LAB_004bb680;
        FUN_0071f8a0(0);
LAB_004bb647:
        *(undefined4 *)(param_1 + 0x188) = 0;
        goto LAB_004bb652;
      }
LAB_004bb680:
      if ((iVar2 != 0) && (*(char *)(iVar2 + 0x168) == '\x01')) {
        if (((*(int *)(iVar2 + 0x160) == *param_5) && (*(int *)(iVar2 + 0x164) == param_5[1])) ||
           (((iVar2 = *(int *)(iVar2 + 0xac), iVar2 != 0 && (*(int *)(iVar2 + 0x160) == *param_5))
            && (*(int *)(iVar2 + 0x164) == param_5[1])))) goto LAB_004bb647;
      }
    }
    piVar3 = (int *)FUN_0071f8a0(0);
    if (piVar3 != (int *)0x0) {
      fVar7 = *(float *)(param_1 + 0x154) - param_3[1];
      fVar5 = *(float *)(param_1 + 0x158) - param_3[2];
      fVar6 = *(float *)(param_1 + 0x150) - *param_3;
      fVar8 = fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6;
      if (_DAT_009cb32c < SQRT(fVar8)) {
        if (fVar8 == 0.0) {
          fVar8 = 0.0;
        }
        else {
          fVar8 = g_flOne / SQRT(fVar8);
        }
        fVar6 = fVar8 * fVar6;
        fVar7 = fVar7 * fVar8;
        fVar5 = fVar5 * fVar8;
      }
      fVar7 = fVar5 * param_4[2] + fVar7 * param_4[1] + fVar6 * *param_4;
      fVar6 = param_3[2] - *(float *)(param_1 + 0x158);
      fVar5 = *param_3 - *(float *)(param_1 + 0x150);
      fVar5 = SQRT(fVar6 * fVar6 + fVar5 * fVar5);
      fVar6 = ABS(fVar7);
      Client_GetMissionCompleteAudioTable(fVar6);
      FUN_007227e0(fVar6);
      if (*(float *)(param_1 + 0x180) <= 0.0) {
        *(float *)(param_1 + 0x180) = DAT_009cb324;
      }
      if (*(float *)(param_1 + 0x184) <= 0.0) {
        *(undefined4 *)(param_1 + 0x184) = DAT_009cb328;
      }
      if (fVar5 < *(float *)(param_1 + 0x184) || fVar5 == *(float *)(param_1 + 0x184)) {
        fVar5 = (g_flOne - fVar5 / *(float *)(param_1 + 0x180)) * *(float *)(param_1 + 400);
      }
      else {
        uVar9 = 0;
        Client_GetMissionCompleteAudioTable(0);
        fVar4 = (float10)FUN_007227e0(uVar9);
        fVar5 = (float)fVar4;
        iVar2 = FUN_0071f760(0);
        if (iVar2 != 0) {
          *(undefined1 *)(param_1 + 0x38) = 1;
        }
      }
      if (*(int *)(param_1 + 0x2c) == 0x28) {
        if (DAT_009cb324 < *(float *)(param_1 + 0x18c)) {
          fVar5 = *(float *)(param_1 + 400) * fVar5 * param_2;
        }
        else {
          fVar5 = *(float *)(param_1 + 400) * *(float *)(param_1 + 0x18c) * fVar5 * param_2 *
                  g_flMultiKillCountBlend;
        }
      }
      else {
        fVar5 = fVar5 * param_2;
      }
      Client_GetMissionCompleteAudioTable(fVar5);
      fVar4 = (float10)FUN_007227e0(fVar5);
      *(float *)(param_1 + 0x1b0) = (float)fVar4;
      fVar7 = fVar7 * _DAT_009cb3e4;
      *(float *)(param_1 + 0x188) = fVar7;
      (**(code **)(*piVar3 + 0x40))(piVar3,(int)ROUND(fVar7));
      return;
    }
  }
  else {
    FUN_0071f8a0(0);
    *(undefined4 *)(param_1 + 0x188) = 0;
    if (*(char *)(param_1 + 0x38) == '\0') {
LAB_004bb652:
      param_2 = *(float *)(param_1 + 400) * param_2;
    }
    else {
      param_2 = 0.0;
    }
    Client_GetMissionCompleteAudioTable(param_2);
    fVar4 = (float10)FUN_007227e0(param_2);
    *(float *)(param_1 + 0x1b0) = (float)fVar4;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
