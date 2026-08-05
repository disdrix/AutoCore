# Annotated low-level: FUN_004aae00

| Field | Value |
|---|---|
| Stable ID | `aa_004aae00` |
| VA | `0x004aae00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004aae00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
FUN_004aae00(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 param_7)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float fVar7;
  float local_e0;
  float local_dc;
  uint local_d4;
  undefined1 local_d0 [204];
  
  if (DAT_00b03631 == '\0') {
    if (*(char *)(param_1 + 0x398) == '\0') {
      FUN_004aac50();
    }
    fVar7 = (float)(int)ROUND(*(float *)(param_1 + 0x18) * DAT_00a0f6d0);
    local_e0 = (float)param_3 / fVar7;
    if (local_e0 <= 0.0) {
      local_e0 = 0.0;
    }
    uVar6 = (uint)ROUND(local_e0);
    local_e0 = (float)param_5 / fVar7;
    if ((float)param_5 / fVar7 <= 0.0) {
      local_e0 = 0.0;
    }
    local_dc = (float)param_4 / fVar7;
    local_e0 = (float)(int)ROUND(local_e0);
    if (local_dc <= 0.0) {
      local_dc = 0.0;
    }
    local_d4 = (uint)ROUND(local_dc);
    local_dc = (float)param_6 / fVar7;
    if ((float)param_6 / fVar7 <= 0.0) {
      local_dc = 0.0;
    }
    uVar2 = (uint)ROUND(local_dc);
    uVar4 = (uVar2 - local_d4) * ((int)local_e0 - uVar6);
    if (DAT_00af3f74 <= uVar4 && uVar4 - DAT_00af3f74 != 0) {
      uVar4 = (int)local_e0 + uVar6 >> 1;
      uVar5 = local_d4 + uVar2 >> 1;
      uVar2 = (int)ROUND(SQRT((float10)(int)DAT_00af3f74)) - 1U >> 1;
      uVar6 = uVar4 - uVar2;
      uVar6 = uVar6 & -(uint)(uVar6 != 0);
      uVar4 = uVar4 + uVar2;
      local_e0 = (float)(-(uint)(uVar4 != 0) & uVar4);
      local_d4 = uVar5 - uVar2;
      local_d4 = -(uint)(local_d4 != 0) & local_d4;
      uVar2 = uVar2 + uVar5;
      uVar2 = -(uint)(uVar2 != 0) & uVar2;
    }
    FUN_004a9120(param_7,uVar6,local_e0,local_d4,uVar2);
    FUN_00972cc0();
    for (; (uVar6 <= (uint)local_e0 && (uVar4 = local_d4, uVar6 < *(uint *)(param_1 + 900)));
        uVar6 = uVar6 + 1) {
      for (; (uVar4 <= uVar2 && (uVar4 < *(uint *)(param_1 + 0x388))); uVar4 = uVar4 + 1) {
        piVar1 = *(int **)(*(int *)(param_1 + 0x38c) + (*(int *)(param_1 + 900) * uVar4 + uVar6) * 4
                          );
        if (piVar1 != (int *)0x0) {
          FUN_005be760();
          if ((*(byte *)(piVar1 + 0x2f) & 1) != 0) {
            (**(code **)(*piVar1 + 0x5c))();
          }
          iVar3 = FUN_0075c960(piVar1 + 10,local_d0);
          if (iVar3 != -1) {
            (**(code **)(*piVar1 + 0x3c))(param_2);
          }
        }
      }
    }
    (**(code **)(**(int **)(param_1 + 0x390) + 0x3c))(param_2);
    return;
  }
  if (DAT_00b03632 == '\0') {
    FUN_005c0f40(param_1);
    DAT_00b03632 = '\x01';
  }
  (**(code **)(**(int **)(param_1 + 0x390) + 0x3c))(param_2);
  CVOGTerrainChunker_SubmitForRendering(param_2);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
