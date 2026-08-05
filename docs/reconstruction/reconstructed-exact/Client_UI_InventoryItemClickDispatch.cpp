// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: if×11, do×6, return×5, for×5, while×5.
//  - Notable callees: FUN_007a6de0×2, Client_SendInventoryDrop_Hardpoint, Client_SendInventoryGrab_Hardpoint, Client_UI_InventoryItemClickDispatch, FUN_004fabc0, FUN_00513fc0, FUN_00795b10, FUN_007a69d0.
//  - Strings: "Broken: ".
//  - Return sites: 5.

// =============================================================================
// Client_UI_InventoryItemClickDispatch
// -----------------------------------------------------------------------------
// Purpose:  UI click dispatcher for inventory / equip items. Routes to
//           Grab_Hardpoint when store cursor empty, Drop_Hardpoint when cursor
//           held; handles permanent-customize confirm dialog.
//
// Address:  0x008635b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_008635b0
// System:   inventory-transfer
//
// Convention: __fastcall; pWidget in ECX (was decomp param_1).
//
// Control flow summary:
//   1) DAT_00d1b6d8 required
//   2) item = pWidget vtbl+0x3ac(); if null/store not ready and char+0xcd0==0
//      → Client_SendInventoryGrab_Hardpoint
//   3) else if cursor held + FUN_00862860:
//        optional permanent-customize modal (flags bit20 / FUN_00513fc0)
//        → Client_SendInventoryDrop_Hardpoint
//   4) DAT_00d1e440 / DAT_00d1e438 stash widget/item for confirm callback
//
// Related: Client_SendInventoryGrab_Hardpoint, Client_SendInventoryDrop_Hardpoint
// Exactness: Scaffold body below mirrors raw; plate human-refined.
// Dual reviews: pending.
// =============================================================================

/*
 * UI click dispatcher for inventory/equip items.
 * Notes retained for body recovery:
 * - If item vtable+0x3ac null or store UI not ready: if char+0xcd0==0 → Grab_Hardpoint.
 * - Else if cursor item + FUN_00862860: Drop_Hardpoint after optional customize warning.
 * - Customize warning when item flags bit20 clear and FUN_00513fc0(TFID) true; modal text permanent customize.
 * - Globals DAT_00d1e440 / DAT_00d1e438 stash widget/item for confirm callback.
 */

// ---- Full decompiler body (width-normalized; human notes above) ----
// pWidget = ECX (__fastcall); was decomp param_1
uint32_t /* decomp width */ __fastcall Client_UI_InventoryItemClickDispatch(int *pWidget)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  int *piVar5;

  uint32_t /* decomp width */ uVar6;

  int iVar7;

  uint uVar8;

  char *pcVar9;

  uint32_t /* decomp width */ *puVar10;

  char *pcVar11;

  uint32_t /* decomp width */ uVar12;

  uint8_t uStack_410;

  uint8_t uStack_40f;

  uint8_t uStack_40e;

  uint8_t uStack_40d;

  uint8_t auStack_40c [3];

  char cStack_409;

  char acStack_408 [2];

  uint32_t /* decomp width */ auStack_406 [256];

  

  if (DAT_00d1b6d8 != 0) {

    iVar2 = (**(code **)(*pWidget + 0x3ac))();

    if ((((iVar2 == 0) || (DAT_00d1bdfa == '\0')) || (DAT_00d1b978 == (int *)0x0)) ||

       ((cVar1 = (**(code **)(*DAT_00d1b978 + 0x3d8))(), cVar1 == '\0' ||

        (cVar1 = (**(code **)(*DAT_00d1b978 + 0xd0))(), cVar1 == '\0')))) {

      if (*(int *)(DAT_00d1b6d8 + 0xcd0) == 0) {

        Client_SendInventoryGrab_Hardpoint();

        return 1;

      }

      iVar2 = (**(code **)(*DAT_00d1b1f8 + 0x3ac))();

      if ((iVar2 != 0) && (cVar1 = FUN_00862860(), cVar1 != '\0')) {

        if (DAT_00d1b6d8 != 0) {

          if ((*(int *)(DAT_00d1b6d8 + 0x250) != 0) && (iVar7 = FUN_004fabc0(iVar2,0), iVar7 != 0))

          {

            FUN_00931db0();

            return 1;

          }

          if (((DAT_00d1b6d8 != 0) && ((*(uint *)(iVar2 + 0x17c) >> 0x14 & 1) == 0)) &&

             (cVar1 = FUN_00513fc0(*(uint32_t /* decomp width */ *)(iVar2 + 0x160),*(uint32_t /* decomp width */ *)(iVar2 + 0x164)),

             cVar1 != '\0')) {

            DAT_00d1e440 = pWidget[0x37];

            DAT_00d1e438 = iVar2;

            FUN_007fdfb0(&DAT_00d1a840,

                         "Warning: This will permanently customize this item to you!  If you do this, you will no longer be able to trade it.  Are you sure?"

                         ,0x4e5b,1,0);

            return 1;

          }

        }

        Client_SendInventoryDrop_Hardpoint(pWidget);

      }

    }

    else if (DAT_00d1b978[0x68ae] != 0) {

      acStack_408[0] = '[';

      acStack_408[1] = '\0';

      puVar10 = auStack_406;

      for (iVar2 = 0xff; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar10 = 0;

        puVar10 = puVar10 + 1;

      }

      *(uint16_t *)puVar10 = 0;

      FUN_007a69d0();

      iVar2 = (**(code **)(*pWidget + 0x3ac))();

      if ((*(uint *)(iVar2 + 0x17c) >> 0x13 & 1) != 0) {

        pcVar3 = (char *)FUN_007a6de0("Broken: ",0xffffffff);

        pcVar4 = pcVar3;

        do {

          cVar1 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        pcVar11 = &cStack_409;

        do {

          pcVar9 = pcVar11 + 1;

          pcVar11 = pcVar11 + 1;

        } while (*pcVar9 != '\0');

        pcVar9 = pcVar3;

        for (uVar8 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

          *(uint32_t /* decomp width */ *)pcVar11 = *(uint32_t /* decomp width */ *)pcVar9;

          pcVar9 = pcVar9 + 4;

          pcVar11 = pcVar11 + 4;

        }

        for (uVar8 = (int)pcVar4 - (int)pcVar3 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

          *pcVar11 = *pcVar9;

          pcVar9 = pcVar9 + 1;

          pcVar11 = pcVar11 + 1;

        }

      }

      piVar5 = (int *)(**(code **)(*pWidget + 0x3ac))();

      uVar12 = 0xffffffff;

      uVar6 = (**(code **)(*piVar5 + 0x15c))(0xffffffff);

      pcVar3 = (char *)FUN_007a6de0(uVar6,uVar12);

      pcVar4 = pcVar3;

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      pcVar11 = &cStack_409;

      do {

        pcVar9 = pcVar11 + 1;

        pcVar11 = pcVar11 + 1;

      } while (*pcVar9 != '\0');

      pcVar9 = pcVar3;

      for (uVar8 = (uint)((int)pcVar4 - (int)pcVar3) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *(uint32_t /* decomp width */ *)pcVar11 = *(uint32_t /* decomp width */ *)pcVar9;

        pcVar9 = pcVar9 + 4;

        pcVar11 = pcVar11 + 4;

      }

      for (uVar8 = (int)pcVar4 - (int)pcVar3 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

        *pcVar11 = *pcVar9;

        pcVar9 = pcVar9 + 1;

        pcVar11 = pcVar11 + 1;

      }

      pcVar4 = &cStack_409;

      do {

        pcVar3 = pcVar4 + 1;

        pcVar4 = pcVar4 + 1;

      } while (*pcVar3 != '\0');

      iVar2 = *pWidget;

      *(uint16_t *)pcVar4 = DAT_00a62c94;

      piVar5 = (int *)(**(code **)(iVar2 + 0x3ac))();

      iVar2 = (**(code **)(*piVar5 + 0x210))(0);

      if (iVar2 == 0) {

        uVar6 = 0xffffffff;

        uVar12 = 0xffffffff;

      }

      else {

        piVar5 = (int *)(**(code **)(*pWidget + 0x3ac))();

        iVar7 = (**(code **)(*piVar5 + 0x210))(0);

        iVar2 = *(int *)(*(int *)(iVar7 + 4) + 4);

        uVar6 = *(uint32_t /* decomp width */ *)(iVar2 + 0x164 + iVar7);

        uVar12 = *(uint32_t /* decomp width */ *)(iVar2 + 0x168 + iVar7);

      }

      uStack_40e = 0xff;

      uStack_40f = 0;

      uStack_410 = 0xff;

      uStack_40d = 0xff;

      iVar2 = (**(code **)(*pWidget + 0x3ac))();

      FUN_00795b10(auStack_40c,1,*(uint32_t /* decomp width */ *)(iVar2 + 0x160),*(uint32_t /* decomp width */ *)(iVar2 + 0x164),uVar6

                   ,uVar12,&uStack_410,0);

      if (DAT_00d1b978[0xac] != 0) {

        iVar2 = *(int *)DAT_00d1b978[0xac];

        uVar6 = (**(code **)(*DAT_00d1b978 + 0x88))();

        (**(code **)(iVar2 + 0x3c0))(uVar6);

      }

      iVar2 = *DAT_00d1b978;

      uVar6 = (**(code **)(*(int *)DAT_00d1b978[0x68ae] + 0x88))();

      (**(code **)(iVar2 + 0x3c0))(uVar6);

      return 1;

    }

  }

  return 1;

}
