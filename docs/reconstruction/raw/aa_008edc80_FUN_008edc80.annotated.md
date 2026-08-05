# Annotated low-level: FUN_008edc80

| Field | Value |
|---|---|
| Stable ID | `aa_008edc80` |
| VA | `0x008edc80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008edc80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008edc80(int param_1,uint param_2)

{
  uchar areaId;
  bool bVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  float *pfVar6;
  int iVar7;
  uint key;
  float *local_3c;
  int local_34;
  float local_30;
  float local_28;
  undefined1 local_24 [4];
  int *piStack_20;
  undefined1 auStack_18 [12];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b164d;
  local_c = ExceptionList;
  if (((*(int *)(param_1 + 0x67c) != 0) && (DAT_00d1b644 != 0)) && (DAT_00d1b644 != -0xa0)) {
    ExceptionList = &local_c;
    key = param_2;
    pvVar2 = (void *)FUN_00541a80();
    pvVar2 = CNDHash_LookupByKey(pvVar2,key);
    if (((pvVar2 != (void *)0x0) && (*(int *)((int)pvVar2 + 0x18) == 0)) &&
       (*(int *)((int)pvVar2 + 0x14) == 0)) {
      local_3c = (float *)0x0;
      if (*(uint *)(DAT_00d1b644 + 0xfc) != param_2) {
        FUN_0040e180();
        if (local_34 == *(int *)(param_1 + 0x560)) {
          FUN_008ed6d0(param_1,param_2);
          piVar3 = (int *)FUN_0040e180();
          local_34 = *piVar3;
        }
        if (local_34 != *(int *)(param_1 + 0x560)) {
          local_3c = (float *)(local_34 + 0x10);
        }
      }
      FUN_004023f0();
      local_4 = 0;
      iVar4 = FUN_0040e340();
      piVar3 = (int *)FUN_0040e490(*(int *)(param_1 + 0x67c) + 0x624);
      while (piVar3 != (int *)0x0) {
        iVar7 = piVar3[0x133];
        if (iVar7 != 0) {
          piVar5 = (int *)CVOGReaction_ResolveObjectTarget
                                    (0,*(undefined4 *)(iVar7 + 8),*(undefined4 *)(iVar7 + 0xc));
          if (piVar5 != (int *)0x0) {
            FUN_00404060();
            (**(code **)(*piVar5 + 0x124))(local_24);
            piVar5 = (int *)*piStack_20;
            if (piVar5 != piStack_20) {
              do {
                (**(code **)(*(int *)piVar5[2] + 0x144))();
                pfVar6 = (float *)FUN_004e88e0(auStack_18,piVar5[2] + 0x80);
                local_30 = *pfVar6;
                piVar5 = (int *)*piVar5;
                local_28 = pfVar6[2];
              } while (piVar5 != piStack_20);
              goto LAB_008ede46;
            }
          }
          local_28 = *(float *)(iVar7 + 0x18);
          local_30 = *(float *)(iVar7 + 0x10);
        }
LAB_008ede46:
        if (local_3c == (float *)0x0) {
          areaId = CVOGTerrain_SampleExploredAreaId
                             (*(void **)(DAT_00d1b644 + 0xe4f8),local_30,local_28);
        }
        else {
          areaId = *(uchar *)((int)local_3c[1] *
                              (int)((local_30 - *local_3c * DAT_00a0f298) * (g_flOne / *local_3c)) +
                              (int)local_3c[3] +
                             (int)((local_28 - *local_3c * DAT_00a0f298) * (g_flOne / *local_3c)));
        }
        bVar1 = false;
        if (DAT_00d1b6d8 != (void *)0x0) {
          bVar1 = CVOGCharacter_IsAreaExplored(DAT_00d1b6d8,param_2,areaId);
        }
        if ((areaId == '\0') || (bVar1 != false)) {
          (**(code **)(*piVar3 + 4))(1);
        }
        else {
          (**(code **)(*piVar3 + 4))(0);
        }
        FUN_0040e380(*(int *)(param_1 + 0x67c) + 0x624,piVar3);
        iVar7 = FUN_0040e340();
        if (iVar7 == iVar4) break;
        piVar3 = (int *)FUN_0040e490(*(int *)(param_1 + 0x67c) + 0x624);
      }
      local_4 = 0xffffffff;
      FUN_00404060();
                    /* WARNING: Subroutine does not return */
      operator_delete(piStack_20);
    }
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
