// READABILITY (auto CF):
//  - Body size: ~176 non-empty decompiler lines.
//  - Control keywords: if×15, return×12, switch×1.
//  - Notable callees: Client_PlayNamedInterfaceSound×6, NetObject_SetMaskBits×5, FUN_0040da70×4, Client_GetMissionCompleteAudioTable×3, FUN_004fe110×3, FUN_005034a0×3, FUN_004fe620, FUN_004fe800.
//  - Strings: "menu_unequip_item"; "menu_unequip_weapon".
//  - Return sites: 12.

// =============================================================================
// Inv_menu_unequip_weapon_00504f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00504f60
// Address:   0x00504f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "menu_unequip_weapon"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * __thiscall Inv_menu_unequip_weapon_00504f60(void *param_1,int *param_2)



{

  short sVar1;

  void *pvVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ uVar13;

  

  if (param_2 == (int *)0x0) {

    return (int *)0x0;

  }

  *(byte *)((int)param_1 + 0x1d5) = *(byte *)((int)param_1 + 0x1d5) | 4;

  switch(*(uint32_t /* width from decompiler */ *)(param_2[0x2a] + 0x38)) {

  case 6:

    sVar1 = *(short *)(*(int *)(param_2[0x2a] + 0x3c) + 0x3f4);

    if (sVar1 != 10) {

      if (sVar1 != 0xb) {

        return (int *)0x0;

      }

      uVar13 = 0;

      uVar12 = 0x1e;

      uVar11 = 0;

      uVar10 = 0;

      uVar9 = 0xffffffff;

      uVar8 = 0xffffffff;

      uVar7 = 0;

      pcVar6 = "menu_unequip_item";

      Client_GetMissionCompleteAudioTable("menu_unequip_item",0,0xffffffff,0xffffffff,0,0,0x1e,0);

      Client_PlayNamedInterfaceSound(pcVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12,uVar13);

      param_2 = (void *)0x0;

      Vehicle_SetEquippedRaceItem(param_1,(void *)0x0,&param_2,'\0');

      if (param_2 == (void *)0x0) {

        return (int *)0x0;

      }

      piVar3 = (int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 4 + (int)param_2);

      if (piVar3 == (int *)0x0) {

        return (int *)0x0;

      }

      piVar4 = (int *)(**(code **)(*piVar3 + 0x1cc))();

      (**(code **)(*piVar4 + 0x18))(0);

      return piVar3;

    }

    uVar13 = 0;

    uVar12 = 0x1e;

    uVar11 = 0;

    uVar10 = 0;

    uVar9 = 0xffffffff;

    uVar8 = 0xffffffff;

    uVar7 = 0;

    pcVar6 = "menu_unequip_item";

    Client_GetMissionCompleteAudioTable("menu_unequip_item",0,0xffffffff,0xffffffff,0,0,0x1e,0);

    Client_PlayNamedInterfaceSound(pcVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12,uVar13);

    pvVar2 = *(void **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0x18 + (int)param_1);

    if (pvVar2 != (void *)0x0) {

      NetObject_SetMaskBits(pvVar2,0,0x40);

    }

    param_2 = (void *)0x0;

    FUN_004fe620(0,&param_2,0);

    break;

  default:

    return (int *)0x0;

  case 10:

    piVar3 = (int *)FUN_005034a0(1);

    return piVar3;

  case 0xc:

    (**(code **)(*param_2 + 0x1e0))();

    iVar5 = FUN_0040da70();

    if (*(char *)(iVar5 + 0x3f4) == '\t') {

      uVar13 = 0;

      uVar12 = 0x1e;

      uVar11 = 0;

      uVar10 = 0;

      uVar9 = 0xffffffff;

      uVar8 = 0xffffffff;

      uVar7 = 0;

      pcVar6 = "menu_unequip_weapon";

      Client_GetMissionCompleteAudioTable("menu_unequip_weapon",0,0xffffffff,0xffffffff,0,0,0x1e,0);

      Client_PlayNamedInterfaceSound(pcVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12,uVar13);

      pvVar2 = *(void **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0x18 + (int)param_1);

      if (pvVar2 != (void *)0x0) {

        NetObject_SetMaskBits(pvVar2,0,0x20);

      }

      param_2 = (void *)0x0;

      FUN_004fe800(0,&param_2,0);

    }

    else {

      iVar5 = FUN_0040da70();

      if ((*(byte *)(iVar5 + 0x536) & 2) == 0) {

        iVar5 = FUN_0040da70();

        if ((*(byte *)(iVar5 + 0x536) & 0x10) == 0) {

          iVar5 = FUN_0040da70();

          if ((*(byte *)(iVar5 + 0x536) & 4) == 0) {

            return (int *)0x0;

          }

          uVar13 = 0;

          uVar12 = 0x1e;

          uVar11 = 0;

          uVar10 = 0;

          uVar9 = 0xffffffff;

          uVar8 = 0xffffffff;

          uVar7 = 0;

          pcVar6 = "menu_unequip_weapon";

          Client_GetMissionCompleteAudioTable

                    ("menu_unequip_weapon",0,0xffffffff,0xffffffff,0,0,0x1e,0);

          Client_PlayNamedInterfaceSound(pcVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12,uVar13);

          pvVar2 = *(void **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0x18 + (int)param_1);

          if (pvVar2 != (void *)0x0) {

            NetObject_SetMaskBits(pvVar2,0,0x10);

          }

          param_2 = (void *)0x0;

          FUN_004fe110(0,2,&param_2);

        }

        else {

          uVar13 = 0;

          uVar12 = 0x1e;

          uVar11 = 0;

          uVar10 = 0;

          uVar9 = 0xffffffff;

          uVar8 = 0xffffffff;

          uVar7 = 0;

          pcVar6 = "menu_unequip_weapon";

          Client_GetMissionCompleteAudioTable

                    ("menu_unequip_weapon",0,0xffffffff,0xffffffff,0,0,0x1e,0);

          Client_PlayNamedInterfaceSound(pcVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12,uVar13);

          pvVar2 = *(void **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0x18 + (int)param_1);

          if (pvVar2 != (void *)0x0) {

            NetObject_SetMaskBits(pvVar2,0,8);

          }

          param_2 = (void *)0x0;

          FUN_004fe110(0,1,&param_2);

        }

      }

      else {

        uVar13 = 0;

        uVar12 = 0x1e;

        uVar11 = 0;

        uVar10 = 0;

        uVar9 = 0xffffffff;

        uVar8 = 0xffffffff;

        uVar7 = 0;

        pcVar6 = "menu_unequip_weapon";

        Client_GetMissionCompleteAudioTable

                  ("menu_unequip_weapon",0,0xffffffff,0xffffffff,0,0,0x1e,0);

        Client_PlayNamedInterfaceSound(pcVar6,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12,uVar13);

        pvVar2 = *(void **)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0x18 + (int)param_1);

        if (pvVar2 != (void *)0x0) {

          NetObject_SetMaskBits(pvVar2,0,4);

        }

        param_2 = (void *)0x0;

        FUN_004fe110(0,0,&param_2);

      }

    }

    break;

  case 0x10:

    piVar3 = (int *)FUN_005034a0(2);

    return piVar3;

  case 0x1c:

    piVar3 = (int *)FUN_005034a0(3);

    return piVar3;

  }

  if ((param_2 != (void *)0x0) &&

     (piVar3 = (int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 4 + (int)param_2),

     piVar3 != (int *)0x0)) {

    piVar4 = (int *)(**(code **)(*piVar3 + 0x1cc))();

    (**(code **)(*piVar4 + 0x18))(0);

    return piVar3;

  }

  return (int *)0x0;

}
