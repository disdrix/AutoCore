// READABILITY (auto CF):
//  - Body size: ~194 non-empty decompiler lines.
//  - Control keywords: if×11, goto×6, return×3, switch×1.
//  - Notable callees: Client_PlayNamedInterfaceSound×9, case×9, Client_GetMissionCompleteAudioTable×8, NetObject_SetMaskBits×7, FUN_004fe110, FUN_004fe620, FUN_004fe800, FUN_004ff510.
//  - Strings: "menu_unequip_powerplant"; "menu_unequip_wheelset"; "menu_unequip_armor"; "menu_unequip_weapon".
//  - Return sites: 3.

// =============================================================================
// Inv_menu_unequip_powerplant_005034a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005034a0
// Address:   0x005034a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "menu_unequip_powerplant"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * __thiscall Inv_menu_unequip_powerplant_005034a0(void *param_1,void *param_2)



{

  int iVar1;

  void *pvVar2;

  int *piVar3;

  int *piVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  

  piVar4 = (int *)0x0;

  switch(param_2) {

  case (void *)0x1:

    uVar12 = 0;

    uVar11 = 0x1e;

    uVar10 = 0;

    uVar9 = 0;

    uVar8 = 0xffffffff;

    uVar7 = 0xffffffff;

    uVar6 = 0;

    pcVar5 = "menu_unequip_powerplant";

    Client_GetMissionCompleteAudioTable

              ("menu_unequip_powerplant",0,0xffffffff,0xffffffff,0,0,0x1e,0);

    Client_PlayNamedInterfaceSound(pcVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12);

    param_2 = (void *)0x0;

    Vehicle_EquipPowerPlant(param_1,(void *)0x0,&param_2,false);

    goto LAB_005034ee;

  case (void *)0x2:

    pvVar2 = *(void **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0x18 + (int)param_1);

    if (pvVar2 != (void *)0x0) {

      NetObject_SetMaskBits(pvVar2,0,1);

    }

    uVar12 = 0;

    uVar11 = 0x1e;

    uVar10 = 0;

    uVar9 = 0;

    uVar8 = 0xffffffff;

    uVar7 = 0xffffffff;

    uVar6 = 0;

    pcVar5 = "menu_unequip_wheelset";

    Client_GetMissionCompleteAudioTable("menu_unequip_wheelset",0,0xffffffff,0xffffffff,0,0,0x1e,0);

    Client_PlayNamedInterfaceSound(pcVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12);

    param_2 = (void *)0x0;

    FUN_004ff510(0,&param_2,0);

LAB_005034ee:

    if (param_2 == (void *)0x0) {

      return (int *)0x0;

    }

    piVar4 = (int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 4 + (int)param_2);

    goto LAB_00503733;

  case (void *)0x3:

    uVar12 = 0;

    uVar11 = 0x1e;

    uVar10 = 0;

    uVar9 = 0;

    uVar8 = 0xffffffff;

    uVar7 = 0xffffffff;

    uVar6 = 0;

    pcVar5 = "menu_unequip_armor";

    Client_GetMissionCompleteAudioTable("menu_unequip_armor",0,0xffffffff,0xffffffff,0,0,0x1e,0);

    Client_PlayNamedInterfaceSound(pcVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12);

    pvVar2 = *(void **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0x18 + (int)param_1);

    if (pvVar2 != (void *)0x0) {

      NetObject_SetMaskBits(pvVar2,0x40000000,0);

    }

    iVar1 = *(int *)((int)param_1 + 0x254);

    Vehicle_SetEquippedArmor(param_1,(void *)0x0,'\0');

    if (iVar1 == 0) {

      return (int *)0x0;

    }

    piVar4 = (int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);

    goto LAB_00503733;

  case (void *)0x4:

    uVar12 = 0;

    uVar11 = 0x1e;

    uVar10 = 0;

    uVar9 = 0;

    uVar8 = 0xffffffff;

    uVar7 = 0xffffffff;

    uVar6 = 0;

    pcVar5 = "menu_unequip_weapon";

    Client_GetMissionCompleteAudioTable("menu_unequip_weapon",0,0xffffffff,0xffffffff,0,0,0x1e,0);

    Client_PlayNamedInterfaceSound(pcVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12);

    pvVar2 = *(void **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0x18 + (int)param_1);

    if (pvVar2 != (void *)0x0) {

      NetObject_SetMaskBits(pvVar2,0,4);

    }

    uVar6 = 0;

    goto LAB_00503715;

  case (void *)0x5:

    uVar12 = 0;

    uVar11 = 0x1e;

    uVar10 = 0;

    uVar9 = 0;

    uVar8 = 0xffffffff;

    uVar7 = 0xffffffff;

    uVar6 = 0;

    pcVar5 = "menu_unequip_weapon";

    Client_GetMissionCompleteAudioTable("menu_unequip_weapon",0,0xffffffff,0xffffffff,0,0,0x1e,0);

    Client_PlayNamedInterfaceSound(pcVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12);

    pvVar2 = *(void **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0x18 + (int)param_1);

    if (pvVar2 != (void *)0x0) {

      NetObject_SetMaskBits(pvVar2,0,8);

    }

    uVar6 = 1;

    goto LAB_00503715;

  case (void *)0x6:

    uVar12 = 0;

    uVar11 = 0x1e;

    uVar10 = 0;

    uVar9 = 0;

    uVar8 = 0xffffffff;

    uVar7 = 0xffffffff;

    uVar6 = 0;

    pcVar5 = "menu_unequip_weapon";

    Client_GetMissionCompleteAudioTable("menu_unequip_weapon",0,0xffffffff,0xffffffff,0,0,0x1e,0);

    Client_PlayNamedInterfaceSound(pcVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12);

    pvVar2 = *(void **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0x18 + (int)param_1);

    if (pvVar2 != (void *)0x0) {

      NetObject_SetMaskBits(pvVar2,0,0x10);

    }

    uVar6 = 2;

LAB_00503715:

    param_2 = (void *)0x0;

    FUN_004fe110(0,uVar6,&param_2);

    break;

  case (void *)0x7:

    uVar12 = 0;

    uVar11 = 0x1e;

    uVar10 = 0;

    uVar9 = 0;

    uVar8 = 0xffffffff;

    uVar7 = 0xffffffff;

    uVar6 = 0;

    pcVar5 = "menu_unequip_weapon";

    Client_GetMissionCompleteAudioTable("menu_unequip_weapon",0,0xffffffff,0xffffffff,0,0,0x1e,0);

    Client_PlayNamedInterfaceSound(pcVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12);

    pvVar2 = *(void **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0x18 + (int)param_1);

    if (pvVar2 != (void *)0x0) {

      NetObject_SetMaskBits(pvVar2,0,0x20);

    }

    param_2 = (void *)0x0;

    FUN_004fe800(0,&param_2,0);

    break;

  case (void *)0x8:

    uVar12 = 0;

    uVar11 = 0x1e;

    uVar10 = 0;

    uVar9 = 0;

    uVar8 = 0xffffffff;

    uVar7 = 0xffffffff;

    uVar6 = 0;

    pcVar5 = "menu_unequip_item";

    Client_GetMissionCompleteAudioTable("menu_unequip_item",0,0xffffffff,0xffffffff,0,0,0x1e,0);

    Client_PlayNamedInterfaceSound(pcVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12);

    param_2 = (void *)0x0;

    Vehicle_SetEquippedRaceItem(param_1,(void *)0x0,&param_2,'\0');

    break;

  case (void *)0x9:

    uVar12 = 0;

    uVar11 = 0x1e;

    uVar10 = 0;

    uVar9 = 0;

    uVar8 = 0xffffffff;

    uVar7 = 0xffffffff;

    uVar6 = 0;

    pcVar5 = "menu_unequip_item";

    Client_GetMissionCompleteAudioTable("menu_unequip_item",0,0xffffffff,0xffffffff,0,0,0x1e,0);

    Client_PlayNamedInterfaceSound(pcVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12);

    pvVar2 = *(void **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0x18 + (int)param_1);

    if (pvVar2 != (void *)0x0) {

      NetObject_SetMaskBits(pvVar2,0,0x40);

    }

    param_2 = (void *)0x0;

    FUN_004fe620(0,&param_2,0);

    break;

  default:

    goto switchD_005034ba_default;

  }

  if (param_2 != (void *)0x0) {

    piVar4 = (int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 4 + (int)param_2);

LAB_00503733:

    if (piVar4 != (int *)0x0) {

      piVar3 = (int *)(**(code **)(*piVar4 + 0x1cc))();

      (**(code **)(*piVar3 + 0x18))(0);

    }

  }

switchD_005034ba_default:

  return piVar4;

}
