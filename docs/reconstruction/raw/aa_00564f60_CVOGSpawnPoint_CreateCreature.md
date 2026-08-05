# Raw capture: CVOGSpawnPoint_CreateCreature

| Field | Value |
|---|---|
| **Stable ID** | `aa_00564f60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00564f60` |
| **Canonical name** | `CVOGSpawnPoint_CreateCreature` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGSpawnPoint::CreateCreature
   
   AutoCore: static IsNPC spawn height.
   When Speed>0 OR spawn flag OR IsNPC==1: terrain raycast (Y+3), then
   Y += rlFlyingHeight (flag bit4 clear) + creature[+0x120] foot offset.
   See Documentation/NPC_SPAWN_HEIGHT.md and SpawnPoint.ApplyStaticNpcSpawnHeight. */

int __thiscall
CVOGSpawnPoint_CreateCreature(int param_1,int param_2,undefined4 param_3,char param_4)

{
  undefined4 *puVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  float *pfVar7;
  void *pvVar8;
  uint uVar9;
  float10 fVar10;
  undefined4 uStack_84;
  float fStack_80;
  void *pvStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  float fStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  void *pvStack_38;
  void *pvStack_20;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a4b0f;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  iVar4 = FUN_00404d70(param_2);
  if (iVar4 == 0) {
    FUN_007a4480();
    ExceptionList = pvStack_20;
    return 0;
  }
  if (*(int *)(iVar4 + 0x38) != 0x12) {
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 4);
    FUN_007a4480(1,"!!Old vehicle spawn: %d, not a template for spawn %I64d Map %d",param_2,
                 *(undefined4 *)(param_1 + 0x164 + iVar4),*(undefined4 *)(param_1 + iVar4 + 0x168),
                 *(undefined4 *)(*(int *)(param_1 + 0xa8 + iVar4) + 0xfc));
    ExceptionList = pvStack_20;
    return 0;
  }
  if (*(char *)(param_1 + 0xa8) == '\0') {
    pvStack_7c = operator_new(0x690);
    puStack_18 = (undefined1 *)0x0;
    if (pvStack_7c == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_004c9aa0(1);
    }
    puStack_18 = (undefined1 *)0xffffffff;
    (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 8))
              (param_2,*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1),1);
    goto LAB_005650e0;
  }
  iVar4 = *(int *)(param_1 + 0x1c0);
  if (iVar4 == 0) {
LAB_0056506d:
    *(undefined4 *)(param_1 + 0x1c0) = 0;
    iVar4 = FUN_004cf2a0(param_3,param_2,1);
    *(int *)(param_1 + 0x1c0) = iVar4;
    if (iVar4 == 0) {
      FUN_007a4480(1,"Error: Unable to generate creature, cbid:%d leveloffset:%d",param_2,param_3);
      ExceptionList = pvStack_20;
      return 0;
    }
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x218))
              (*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1));
  }
  else if (*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x34) != param_2) {
    if (iVar4 != 0) {
      (*(code *)**(undefined4 **)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4))(1);
    }
    goto LAB_0056506d;
  }
  piVar5 = (int *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x1c0) + 4) + 4) + 4 +
                                       *(int *)(param_1 + 0x1c0)) + 0x21c))();
  piVar5 = (int *)(**(code **)(*piVar5 + 0x1d8))();
LAB_005650e0:
  iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);
  uVar9 = *(uint *)(iVar4 + 0xe6d8);
  iVar6 = *(int *)(iVar4 + 0xe6dc);
  *(uint *)(iVar4 + 0xe6d8) = uVar9 + 1;
  *(uint *)(iVar4 + 0xe6dc) = iVar6 + (uint)(0xfffffffe < uVar9);
  FUN_00512160(uVar9,iVar6,0);
  (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0x218))
            (*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1));
  uVar9 = *(uint *)(param_1 + 0xa0) & *(uint *)(param_1 + 0xa4);
  CVOGWaypoint_InitFromSpawn
            (*(uint *)(param_1 + 0xa0),*(uint *)(param_1 + 0xa4),0xffffffff,
             *(undefined4 *)(param_1 + 0x7c),CONCAT31((int3)(uVar9 >> 8),uVar9 == 0xffffffff),0);
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 4);
  uStack_84 = *(undefined4 *)(param_1 + 0x84 + iVar4);
  fStack_80 = *(float *)(param_1 + 0x88 + iVar4);
  pvStack_7c = *(void **)(param_1 + 0x8c + iVar4);
  uStack_78 = *(undefined4 *)(param_1 + 0x90 + iVar4);
                    /* Height path: Speed>0 || spawnFlag || IsNPC==1 → terrain cast,
                       +FlyingHeight, +foot@0x120 */
  iVar4 = *(int *)(*(int *)(*(int *)(piVar5[1] + 4) + 0xac + (int)piVar5) + 0x3c);
  if (((*(int *)(iVar4 + 0x4e0) != 1) && (*(char *)(param_1 + 0x1a9) != '\0')) &&
     (g_flZero < *(float *)(iVar4 + 0x4c0))) {
    cVar3 = FUN_004e9720(*(undefined4 *)(param_1 + 0xa8 + *(int *)(*(int *)(param_1 + 4) + 4)),
                         &uStack_84,*(undefined4 *)(param_1 + 0x9c),
                         *(undefined4 *)
                          (*(int *)(*(int *)(*(int *)(piVar5[1] + 4) + 0xac + (int)piVar5) + 0x3c) +
                          0x4d4),&uStack_74,0x14,5);
    if (cVar3 == '\0') {
      fVar2 = *(float *)(param_1 + 0x9c);
      iVar4 = FUN_00567020();
      iVar6 = FUN_00567020();
      pfVar7 = (float *)FUN_00567020();
      FUN_007a4480(0xffffffff,
                   "Couldn\'t find a spawn position for creature AI: %d %0.2f %0.2f %0.2f, radius %0.1f"
                   ,param_2,(double)*pfVar7,(double)*(float *)(iVar6 + 4),
                   (double)*(float *)(iVar4 + 8),(double)fVar2);
      (*(code *)**(undefined4 **)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5))();
      ExceptionList = pvStack_20;
      return 0;
    }
    uStack_84 = uStack_74;
    pvStack_7c = (void *)uStack_6c;
    fStack_80 = fStack_70;
    uStack_78 = uStack_68;
  }
  iVar4 = *(int *)(*(int *)(*(int *)(piVar5[1] + 4) + 0xac + (int)piVar5) + 0x3c);
  if (((g_flZero < *(float *)(iVar4 + 0x4c0)) || (*(char *)(param_1 + 0x1a9) != '\0')) ||
     (*(int *)(iVar4 + 0x4e0) == 1)) {
    fVar10 = (float10)CVOGMap_CastTerrainHeight
                                (uStack_84,pvStack_7c,fStack_80 + g_flVehicleHpTechCoeff,0);
    fStack_80 = (float)fVar10;
    if (((uint)piVar5[0x80] >> 4 & 1) == 0) {
      fStack_80 = *(float *)(*(int *)(*(int *)(*(int *)(piVar5[1] + 4) + 0xac + (int)piVar5) + 0x3c)
                            + 0x4d4) + fStack_80;
    }
    fStack_80 = (float)piVar5[0x48] + fStack_80;
  }
  iVar4 = *(int *)(piVar5[1] + 4);
  *(undefined4 *)(iVar4 + 0x84 + (int)piVar5) = uStack_84;
  *(float *)(iVar4 + 0x88 + (int)piVar5) = fStack_80;
  *(void **)(iVar4 + 0x8c + (int)piVar5) = pvStack_7c;
  *(undefined4 *)((int)piVar5 + iVar4 + 0x90) = uStack_78;
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 4);
  puVar1 = (undefined4 *)(*(int *)(piVar5[1] + 4) + 0x94 + (int)piVar5);
  iVar4 = iVar6 + 0x94 + param_1;
  *puVar1 = *(undefined4 *)(iVar6 + 0x94 + param_1);
  puVar1[1] = *(undefined4 *)(iVar4 + 4);
  puVar1[2] = *(undefined4 *)(iVar4 + 8);
  puVar1[3] = *(undefined4 *)(iVar4 + 0xc);
  if (*(char *)(param_1 + 0x1a8) != '\0') {
    Object_GetRootRaceId((void *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1));
    FUN_00512460();
  }
  FUN_005138e0(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);
  FUN_004d4040();
  FUN_004bc180();
  if ((*(uint *)(*(int *)(piVar5[1] + 4) + 0x3c + (int)piVar5) &
      *(uint *)((int)piVar5 + *(int *)(piVar5[1] + 4) + 0x40)) != 0xffffffff) {
    FUN_004dbef0();
  }
  if ((*(char *)((int)piVar5 + 0x30b) != '\0') &&
     (pvVar8 = NDSpecialFX_LoadFromScriptName("generic_elite",-1,0), pvVar8 != (void *)0x0)) {
    (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0xf8))();
  }
  (**(code **)(*piVar5 + 0xc0))(0,0xffffffff);
  FUN_00566f00();
  piVar5[0x96] = param_1;
  FUN_004024d0();
  if (param_4 != '\0') {
    param_1 = param_1 + *(int *)(*(int *)(param_1 + 4) + 4);
    (**(code **)*piVar5)(*(undefined4 *)(param_1 + 0xa8),&stack0xffffff74,param_1 + 0x94,0);
    if ((piVar5[2] != 0) && (*(char *)(piVar5[2] + 0x40) == '\0')) {
      FUN_0053d970();
    }
  }
  ExceptionList = pvStack_38;
  return *(int *)(piVar5[1] + 4) + 4 + (int)piVar5;
}
```
