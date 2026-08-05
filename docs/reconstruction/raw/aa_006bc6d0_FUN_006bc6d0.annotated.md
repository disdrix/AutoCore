# Annotated low-level: FUN_006bc6d0

| Field | Value |
|---|---|
| Stable ID | `aa_006bc6d0` |
| VA | `0x006bc6d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bc6d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006bc6d0(float *param_1,undefined4 *param_2,int *param_3,int *param_4,int *param_5)

{
  short *psVar1;
  short *psVar2;
  float fVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  float local_1c;
  int local_18;
  
  puVar4 = param_2;
  if (param_3[1] == 0) {
    local_1c = *(float *)(*param_4 + 4);
  }
  else if (param_4[1] == 0) {
    local_1c = *(float *)(*param_3 + 4);
  }
  else {
    local_1c = *(float *)(*param_4 + 4);
    if (*(float *)(*param_3 + 4) < local_1c) {
      local_1c = *(float *)(*param_3 + 4);
    }
  }
  psVar1 = (short *)param_2[1];
  local_18 = 0;
  if (0 < param_3[1]) {
    do {
      fVar3 = *(float *)(*param_3 + 4 + local_18 * 8) - local_1c;
      if (*param_1 < fVar3) break;
      psVar2 = *(short **)(*param_3 + local_18 * 8);
      fVar3 = fVar3 + (float)param_2[4];
      uVar7 = (uint)*(ushort *)*param_2;
      if (0 < param_5[1]) {
        puVar5 = (undefined4 *)*param_5;
        iVar6 = 0;
        do {
          if (((*(short *)*puVar5 == *psVar2) && (*(short *)puVar5[1] == *psVar1)) &&
             (puVar5[3] == uVar7)) {
            puVar5 = (undefined4 *)(*param_5 + iVar6 * 0x14);
            if (*(float *)(*param_5 + 0x10 + iVar6 * 0x14) < fVar3) {
              *puVar5 = psVar2;
              puVar5[1] = psVar1;
              puVar5[2] = param_2;
              puVar5[3] = uVar7;
              puVar5[4] = fVar3;
            }
            goto LAB_006bc805;
          }
          iVar6 = iVar6 + 1;
          puVar5 = puVar5 + 5;
        } while (iVar6 < param_5[1]);
      }
      if (param_5[1] == (param_5[2] & 0x7fffffffU)) {
        FUN_005b3370(param_5,0x14);
      }
      puVar5 = (undefined4 *)(*param_5 + param_5[1] * 0x14);
      *puVar5 = psVar2;
      puVar5[1] = psVar1;
      puVar5[2] = param_2;
      puVar5[3] = uVar7;
      puVar5[4] = fVar3;
      param_5[1] = param_5[1] + 1;
LAB_006bc805:
      local_18 = local_18 + 1;
    } while (local_18 < param_3[1]);
  }
  psVar1 = (short *)*param_2;
  param_2 = (undefined4 *)0x0;
  if (0 < param_4[1]) {
    while( true ) {
      fVar3 = *(float *)(*param_4 + 4 + (int)param_2 * 8) - local_1c;
      if (*param_1 < fVar3) break;
      fVar3 = fVar3 + (float)puVar4[4];
      psVar2 = *(short **)(*param_4 + (int)param_2 * 8);
      uVar7 = (uint)*(ushort *)puVar4[1];
      iVar6 = 0;
      if (0 < param_5[1]) {
        puVar5 = (undefined4 *)*param_5;
        do {
          if (((*(short *)*puVar5 == *psVar1) && (*(short *)puVar5[1] == *psVar2)) &&
             (puVar5[3] == uVar7)) {
            puVar5 = (undefined4 *)(*param_5 + iVar6 * 0x14);
            if (*(float *)(*param_5 + 0x10 + iVar6 * 0x14) < fVar3) {
              *puVar5 = psVar1;
              puVar5[1] = psVar2;
              puVar5[2] = puVar4;
              puVar5[3] = uVar7;
              puVar5[4] = fVar3;
            }
            goto LAB_006bc8f4;
          }
          iVar6 = iVar6 + 1;
          puVar5 = puVar5 + 5;
        } while (iVar6 < param_5[1]);
      }
      if (param_5[1] == (param_5[2] & 0x7fffffffU)) {
        FUN_005b3370(param_5,0x14);
      }
      puVar5 = (undefined4 *)(*param_5 + param_5[1] * 0x14);
      *puVar5 = psVar1;
      puVar5[1] = psVar2;
      puVar5[2] = puVar4;
      puVar5[3] = uVar7;
      puVar5[4] = fVar3;
      param_5[1] = param_5[1] + 1;
LAB_006bc8f4:
      param_2 = (undefined4 *)((int)param_2 + 1);
      if (param_4[1] <= (int)param_2) {
        return;
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
