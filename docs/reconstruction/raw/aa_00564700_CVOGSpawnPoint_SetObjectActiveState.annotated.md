# Annotated low-level: CVOGSpawnPoint_SetObjectActiveState

| Field | Value |
|---|---|
| Stable ID | `aa_00564700` |
| VA | `0x00564700` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00564700`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CVOGSpawnPoint::SetObjectActiveState
   
   Activates/deactivates spawned object. Special path when IsNPC==1. */

uint CVOGSpawnPoint_SetObjectActiveState(int *param_1,char *param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  float *pfVar7;
  uint uVar8;
  bool bStack_39;
  uint uStack_38;
  undefined4 local_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a4afa;
  pvStack_1c = ExceptionList;
  local_34 = DAT_00d1f040;
  ExceptionList = &pvStack_1c;
  FUN_0076cf00("CVOGSpawnPoint::SetObjectActiveState()");
  cVar1 = *param_2;
  local_14 = 0;
  iVar3 = (**(code **)(*param_1 + 0x1c8))();
  iVar4 = (**(code **)(*param_1 + 0x1d8))();
  if (iVar4 == 0) {
    if (*(int *)(param_1[0x2a] + 0x38) == 0xe) {
      if (param_1[0x2b] != 0) {
        CVOGSpawnPoint_SetObjectActiveState(param_1[0x2b],param_2,0);
      }
    }
    else {
      iVar4 = *(int *)(iVar3 + 8);
      if (cVar1 == '\0') {
        if ((iVar4 != 0) && (*(int *)(iVar4 + 8) != 0)) {
          FUN_00561450(&bStack_39,*(undefined4 *)(iVar3 + 8));
        }
      }
      else if (iVar4 != 0) {
        if (*(int *)(iVar4 + 8) == 0) {
          FUN_00560ec0(iVar4);
        }
        FUN_005070d0();
      }
    }
  }
  else {
    piVar5 = (int *)(**(code **)(*param_1 + 0x1d8))();
    if (g_dwClientTickMs < piVar5[0x82] + 15000U) {
      (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 600))
                (DAT_009d2988,DAT_009d298c,DAT_009d2990,DAT_009d2994);
      if (*(int *)(*(int *)(piVar5[1] + 4) + 0xb0 + (int)piVar5) == 0) {
        *(undefined4 *)((int)piVar5 + *(int *)(piVar5[1] + 4) + 100) = 0;
      }
      else {
        FUN_005063c0(0);
      }
      iVar4 = *(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5);
      uVar6 = (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0x244))();
      (**(code **)(iVar4 + 0x240))(uVar6);
    }
    if (*(int *)(iVar3 + 8) != 0) {
      if ((cVar1 == '\0') ||
         (uStack_38 = uStack_38 & 0xffffff00,
         *(int *)(*(int *)(*(int *)(*(int *)(piVar5[1] + 4) + 0xac + (int)piVar5) + 0x3c) + 0x4e0)
         == 1)) {
        uStack_38 = CONCAT31(uStack_38._1_3_,1);
      }
      FUN_0053d970(uStack_38);
      *(char *)(piVar5 + 0xc1) = cVar1;
    }
    if (cVar1 == '\0') {
      (**(code **)(*piVar5 + 100))(0,0x3f800000,1,0xbf800000);
    }
    iVar3 = piVar5[0x94];
    if (iVar3 != 0) {
      *(bool *)(iVar3 + 0x101) = cVar1 == '\0';
      if (*(int *)(iVar3 + 8) == 0) {
        bStack_39 = false;
      }
      else {
        iVar4 = (**(code **)(**(int **)(*(int *)(iVar3 + 8) + 0x3c) + 0x18))();
        bStack_39 = iVar4 == 6;
      }
      FUN_0053d970(cVar1 == '\0');
      if ((((bStack_39 != false) && (cVar1 != '\0')) &&
          (*(char *)(*(int *)(iVar3 + 0x280) + 0x1a9) != '\0')) &&
         (g_flMultiKillCountBlend < *(float *)(*(int *)(iVar3 + 0x280) + 0x9c))) {
        pfVar7 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) +
                                      0x1a0))();
        fStack_30 = *pfVar7;
        fStack_2c = pfVar7[1];
        fStack_28 = pfVar7[2];
        fStack_24 = pfVar7[3];
        iVar4 = CVOGReaction_RandomUnitScalar();
        if (0xfffff < *(int *)(iVar4 + 0xc)) {
          *(undefined4 *)(iVar4 + 0xc) = 0;
        }
        uVar2 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
        *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
        fStack_30 = ((float)uVar2 * _DAT_009d2a3c + fStack_30) - DAT_00a110d8;
        iVar4 = CVOGReaction_RandomUnitScalar();
        if (0xfffff < *(int *)(iVar4 + 0xc)) {
          *(undefined4 *)(iVar4 + 0xc) = 0;
        }
        uVar2 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);
        *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;
        fStack_28 = ((float)uVar2 * _DAT_009d2a3c + fStack_28) - DAT_00a110d8;
        FUN_005d5510(&fStack_30,5000);
      }
      FUN_004e2600(&LAB_00512ac0,param_2,0);
    }
    if ((*(char *)(piVar5[0x3e] + 0x50) == '\0') ||
       ((iVar3 != 0 && (*(char *)(*(int *)(iVar3 + 0xf8) + 0x50) == '\0')))) {
      *(bool *)((int)piVar5 + 0x207) = cVar1 == '\0';
      if (cVar1 != '\0') {
        FUN_004e2600(&LAB_00512ac0,param_2,0);
      }
    }
    else {
      FUN_004e2600(&LAB_00512ac0,param_2,0);
    }
  }
  local_14 = 0xffffffff;
  uVar8 = FUN_0076cef0();
  ExceptionList = pvStack_1c;
  return uVar8 & 0xffffff00;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
