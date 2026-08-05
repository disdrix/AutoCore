# Annotated low-level: CVOGSpawnPoint_CreateTemplateVehicle

| Field | Value |
|---|---|
| Stable ID | a_00564290 |
| VA | 0x00564290 |
| System | unknown |
| Date | 2026-07-23 |
| Refined | manager-pass industrial |

## Purpose (manager refine)

Spawn template AI vehicle; terrain cast and waypoint init.

## Named callees (decompiler)

- CVOGSpawnPoint_CreateTemplateVehicle
- CVOGMap_CastTerrainHeight
- FUN_004e9720
- FUN_007a4480
- FUN_00501970
- FUN_00503780
- FUN_00563ab0
- FUN_00566f00
- Object_GetRootRaceId
- FUN_00512460
- CVOGWaypoint_InitFromSpawn
- FUN_004bc180
- FUN_005138e0
- FUN_004024d0
- FUN_0053d970

## Machine-level notes

- Source: raw capture for a_00564290.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.
- Manager refine: case table + callees extracted; full dual review still open.

## Pseudocode (annotated copy of raw)

`c
int __thiscall
CVOGSpawnPoint_CreateTemplateVehicle(int param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  float10 fVar9;
  undefined4 local_50;
  float local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  void *pvStack_28;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a4ae8;
  local_1c = ExceptionList;
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 4);
  local_50 = *(undefined4 *)(iVar5 + 0x84 + param_1);
  iVar5 = iVar5 + 0x84 + param_1;
  local_4c = *(float *)(iVar5 + 4);
  local_48 = *(undefined4 *)(iVar5 + 8);
  local_44 = *(undefined4 *)(iVar5 + 0xc);
  puVar8 = (undefined4 *)0x0;
  ExceptionList = &local_1c;
  fVar9 = (float10)CVOGMap_CastTerrainHeight(local_50,local_48,local_4c + g_flVehicleHpTechCoeff,0);
  local_4c = (float)fVar9;
  if (*(char *)(param_1 + 0x1a9) != '\0') {
    cVar3 = FUN_004e9720(*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1),
                         &local_50,*(undefined4 *)(param_1 + 0x9c),0x40a00000,&local_40,0x14,5);
    if (cVar3 == '\0') {
      iVar5 = *(int *)(*(int *)(param_1 + 4) + 4);
      local_30 = *(float *)(iVar5 + 0x84 + param_1);
      FUN_007a4480(0,
                   "Couldn\'t find a spawn position for template AI: %d %0.2f %0.2f %0.2f, radius %0.1f"
                   ,param_2,(double)local_30,(double)*(float *)(iVar5 + 0x88 + param_1),
                   (double)*(float *)(iVar5 + 0x8c + param_1),(double)*(float *)(param_1 + 0x9c));
      ExceptionList = local_1c;
      return 0;
    }
    local_50 = local_40;
    local_4c = local_3c;
    local_48 = local_38;
    local_44 = local_34;
  }
  pvVar4 = operator_new(0x800);
  local_14 = 0;
  if (pvVar4 != (void *)0x0) {
    puVar8 = (undefined4 *)FUN_00501970();
  }
  local_14 = 0xffffffff;
  cVar3 = FUN_00503780();
  if (cVar3 == '\0') {
    if (puVar8 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)(*(int *)(puVar8[1] + 4) + 4 + (int)puVar8))();
    }
    FUN_007a4480(0,"VOG_DEBUG_STOP");
    ExceptionList = local_1c;
    return 0;
  }
  (**(code **)(**(int **)(*(int *)(puVar8[1] + 4) + 0xb0 + (int)puVar8) + 0x1d8))();
  FUN_00563ab0();
  iVar5 = *(int *)(puVar8[1] + 4);
  *(undefined4 *)(iVar5 + 0x84 + (int)puVar8) = local_50;
  *(float *)(iVar5 + 0x88 + (int)puVar8) = local_4c;
  *(undefined4 *)(iVar5 + 0x8c + (int)puVar8) = local_48;
  *(undefined4 *)((int)puVar8 + iVar5 + 0x90) = local_44;
  puVar1 = (undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1);
  puVar2 = (undefined4 *)(*(int *)(puVar8[1] + 4) + 0x94 + (int)puVar8);
  *puVar2 = *puVar1;
  puVar2[1] = puVar1[1];
  puVar2[2] = puVar1[2];
  puVar2[3] = puVar1[3];
  iVar5 = (**(code **)(*(int *)(*(int *)(puVar8[1] + 4) + 4 + (int)puVar8) + 0x214))();
  FUN_00566f00();
  *(int *)(iVar5 + 600) = param_1;
  if (*(char *)(param_1 + 0x1a8) != '\0') {
    Object_GetRootRaceId((void *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1));
    FUN_00512460();
    if (*(int *)(*(int *)(puVar8[1] + 4) + 0xb0 + (int)puVar8) != 0) {
      Object_GetRootRaceId((void *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1));
      FUN_00512460();
    }
  }
  uVar7 = *(uint *)(param_1 + 0xa0) & *(uint *)(param_1 + 0xa4);
  if (uVar7 == 0xffffffff) {
    uVar7 = 0xffffff01;
  }
  else {
    uVar7 = uVar7 & 0xffffff00;
  }
  CVOGWaypoint_InitFromSpawn
            (*(uint *)(param_1 + 0xa0),*(uint *)(param_1 + 0xa4),0xffffffff,
             *(undefined4 *)(param_1 + 0x7c),uVar7,0);
  FUN_00566f00();
  puVar8[0xa0] = param_1;
  (**(code **)(*(int *)(*(int *)(puVar8[1] + 4) + 4 + (int)puVar8) + 0x2a4))();
  FUN_004bc180(*(undefined4 *)(*(int *)(puVar8[1] + 4) + 0xb0 + (int)puVar8));
  FUN_005138e0();
  FUN_004024d0(*(int *)(puVar8[1] + 4) + 4 + (int)puVar8);
  piVar6 = (int *)(**(code **)(*(int *)(*(int *)(puVar8[1] + 4) + 4 + (int)puVar8) + 0x214))();
  (**(code **)(*piVar6 + 0xc0))();
  if (param_4 != '\0') {
    *(undefined1 *)(puVar8 + 0x45) = 1;
    (**(code **)*puVar8)();
    FUN_0053d970(1);
  }
  ExceptionList = pvStack_28;
  return *(int *)(puVar8[1] + 4) + 4 + (int)puVar8;
}
`

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Dual independent reconstruction review for this manager unit.
