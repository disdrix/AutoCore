// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, for×1.
//  - Notable callees: FUN_00512460×2, FUN_00566f00×2, FUN_007a4480×2, Object_GetRootRaceId×2, CVOGMap_CastTerrainHeight, CVOGSpawnPoint_CreateTemplateVehicle, FUN_004024d0, FUN_004bc180.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 3.

// =============================================================================
// CVOGSpawnPoint_CreateTemplateVehicle
// -----------------------------------------------------------------------------
// Purpose:  Spawn a template vehicle from a spawn point (map vehicle/NPC driver host).
//           Parallel path to CreateCreature for vehicle templates.
//
// Address:  0x00564290  (autoassault.exe, image base 0x400000)
// Stable:   aa_00564290
// System:   npc-ai / spawn
//
// Used for DR: driver NPCs and parked template vehicles.
// Post-spawn may attach path COID for CVOGHBAIDriver_ReturnToNormalLocation.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

int __thiscall
CVOGSpawnPoint_CreateTemplateVehicle(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,char param_4)
{
  uint32_t /* width from decompiler */ *puVar1;
  uint32_t /* width from decompiler */ *puVar2;
  char cVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint32_t /* width from decompiler */ *puVar8;
  float10 fVar9;
  uint32_t /* width from decompiler */ local_50;
  float local_4c;
  uint32_t /* width from decompiler */ local_48;
  uint32_t /* width from decompiler */ local_44;
  uint32_t /* width from decompiler */ local_40;
  float local_3c;
  uint32_t /* width from decompiler */ local_38;
  uint32_t /* width from decompiler */ local_34;
  float local_30;
  void *pvStack_28;
  void *local_1c;
  uint8_t *puStack_18;
  uint32_t /* width from decompiler */ local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a4ae8;
  local_1c = ExceptionList;
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 4);
  local_50 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x84 + param_1);
  iVar5 = iVar5 + 0x84 + param_1;
  local_4c = *(float *)(iVar5 + 4);
  local_48 = *(uint32_t /* width from decompiler */ *)(iVar5 + 8);
  local_44 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc);
  puVar8 = (uint32_t /* width from decompiler */ *)0x0;
  ExceptionList = &local_1c;
  fVar9 = (float10)CVOGMap_CastTerrainHeight(local_50,local_48,local_4c + g_flVehicleHpTechCoeff,0);
  local_4c = (float)fVar9;
  if (*(char *)(param_1 + 0x1a9) != '\0') {
    cVar3 = FUN_004e9720(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1),
                         &local_50,*(uint32_t /* width from decompiler */ *)(param_1 + 0x9c),0x40a00000,&local_40,0x14,5);
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
    puVar8 = (uint32_t /* width from decompiler */ *)FUN_00501970();
  }
  local_14 = 0xffffffff;
  cVar3 = FUN_00503780();
  if (cVar3 == '\0') {
    if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {
      (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(puVar8[1] + 4) + 4 + (int)puVar8))();
    }
    FUN_007a4480(0,"VOG_DEBUG_STOP");
    ExceptionList = local_1c;
    return 0;
  }
  (**(code **)(**(int **)(*(int *)(puVar8[1] + 4) + 0xb0 + (int)puVar8) + 0x1d8))();
  FUN_00563ab0();
  iVar5 = *(int *)(puVar8[1] + 4);
  *(uint32_t /* width from decompiler */ *)(iVar5 + 0x84 + (int)puVar8) = local_50;
  *(float *)(iVar5 + 0x88 + (int)puVar8) = local_4c;
  *(uint32_t /* width from decompiler */ *)(iVar5 + 0x8c + (int)puVar8) = local_48;
  *(uint32_t /* width from decompiler */ *)((int)puVar8 + iVar5 + 0x90) = local_44;
  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1);
  puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(puVar8[1] + 4) + 0x94 + (int)puVar8);
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
             *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c),uVar7,0);
  FUN_00566f00();
  puVar8[0xa0] = param_1;
  (**(code **)(*(int *)(*(int *)(puVar8[1] + 4) + 4 + (int)puVar8) + 0x2a4))();
  FUN_004bc180(*(uint32_t /* width from decompiler */ *)(*(int *)(puVar8[1] + 4) + 0xb0 + (int)puVar8));
  FUN_005138e0();
  FUN_004024d0(*(int *)(puVar8[1] + 4) + 4 + (int)puVar8);
  piVar6 = (int *)(**(code **)(*(int *)(*(int *)(puVar8[1] + 4) + 4 + (int)puVar8) + 0x214))();
  (**(code **)(*piVar6 + 0xc0))();
  if (param_4 != '\0') {
    *(uint8_t *)(puVar8 + 0x45) = 1;
    (**(code **)*puVar8)();
    FUN_0053d970(1);
  }
  ExceptionList = pvStack_28;
  return *(int *)(puVar8[1] + 4) + 4 + (int)puVar8;
}
