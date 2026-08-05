// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×15, switch×4, return×3, goto×1.
//  - Notable callees: FUN_00571010×2, FUN_007a6de0×2, FUN_007fdfb0×2, CVOGHBList_Enqueue, Client_RefreshOpenMissionUiWindows, FUN_005081d0, FUN_00513e30, FUN_00513fc0.
//  - Strings: "Failed to switch Vehicle on client, get a programmer!".
//  - Return sites: 3.

// =============================================================================
// Inv_Failed_to_switch_Vehicle_on_client_vehicle_not_f_00810360
// -----------------------------------------------------------------------------
// Stable ID: aa_00810360
// Address:   0x00810360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Failed to switch Vehicle on client, vehicle not found in inventory!"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Inv_Failed_to_switch_Vehicle_on_client_vehicle_not_f_00810360(int param_1)



{

  char cVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int unaff_ESI;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b809d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007a69d0();

  if (*(char *)(param_1 + 0x18) == '\0') {

    pcVar6 = 

    "The inventory of your current vehicle will not fit in the new chassis, please reduce your inventory to fit in the number of tabs that the new vehicle has."

    ;

  }

  else if ((*(int *)(unaff_ESI + 0xe98) == 0) ||

          (*(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250) == 0)) {

    pcVar6 = "Failed to switch Vehicle on server, no character or vehicle found!";

  }

  else {

    iVar2 = FUN_00571010(*(uint32_t /* width from decompiler */ *)(param_1 + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

    if (iVar2 == 0) {

      iVar2 = FUN_00571010(*(uint32_t /* width from decompiler */ *)(param_1 + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

      if (iVar2 == 0) {

        pcVar6 = "Failed to switch Vehicle on client, vehicle not found in inventory!";

        goto LAB_00810649;

      }

    }

    if (*(int *)(*(int *)(iVar2 + 0xa8) + 0x38) == 0xe) {

      iVar2 = __RTDynamicCast(iVar2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                              &CVOGVehicle::RTTI_Type_Descriptor,0);

      local_10 = 0;

      if (iVar2 != 0) {

        *(uint8_t *)(unaff_ESI + 0x30b4) = 1;

        *(uint8_t *)(unaff_ESI + 0x30b5) = 0;

        if (*(int **)(unaff_ESI + 0x309c) != (int *)0x0) {

          (**(code **)(**(int **)(unaff_ESI + 0x309c) + 4))(0);

        }

        if (*(int **)(unaff_ESI + 0x1078) != (int *)0x0) {

          cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1078) + 0xd0))();

          if (cVar1 != '\0') {

            FUN_007fca10();

          }

        }

        iVar3 = FUN_005252f0(iVar2,&local_10,*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

        if (iVar3 != 0) {

          uVar9 = 0;

          uVar8 = 1;

          uVar7 = 0xffffffff;

          uVar5 = FUN_007a6de0("Failed to switch Vehicle on client, get a programmer!",0xffffffff);

          FUN_007fdfb0(unaff_ESI,uVar5,uVar7,uVar8,uVar9);

          ExceptionList = local_c;

          return;

        }

        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);

        cVar1 = FUN_00513fc0(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + iVar2),

                             *(uint32_t /* width from decompiler */ *)(iVar3 + iVar2 + 0x168));

        if (cVar1 != '\0') {

          FUN_00513e30(1);

        }

        iVar2 = *(int *)(unaff_ESI + 0x1078);

        if (iVar2 != 0) {

          *(uint32_t /* width from decompiler */ *)(iVar2 + 0x514) = *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xe98) + 0x250);

          FUN_008801b0(iVar2);

        }

        iVar3 = *(int *)(*(int *)(unaff_ESI + 0x1040) + 0x50c);

        if ((iVar3 != 0) && (*(int *)(iVar3 + 0x580) != 0)) {

          FUN_0085e970();

        }

        if (iVar2 != 0) {

          FUN_007fef20(0x12,1,0);

        }

        pvVar4 = operator_new(0x44);

        uStack_4 = 0;

        if (pvVar4 == (void *)0x0) {

          uVar5 = 0;

        }

        else {

          uVar5 = FUN_00599550(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xe98) + 0x250),

                               *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xe04));

        }

        uStack_4 = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xf38) + 0xc70) = uVar5;

        CVOGHBList_Enqueue(*(void **)(unaff_ESI + 0xd38),

                           *(CVOGHBBase **)(*(int *)(unaff_ESI + 0xf38) + 0xc70));

        FUN_005081d0();

        *(uint8_t *)(*(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250) + 0x105) =

             *(uint8_t *)(unaff_ESI + 0x9c4);

        *(uint8_t *)(*(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250) + 0x106) =

             *(uint8_t *)(unaff_ESI + 0x9c4);

        Client_RefreshOpenMissionUiWindows(unaff_ESI);

      }

      ExceptionList = local_c;

      return;

    }

    pcVar6 = "Failed to switch Vehicle on client, object request not a vehicle!";

  }

LAB_00810649:

  uVar9 = 0;

  uVar8 = 1;

  uVar7 = 0xffffffff;

  uVar5 = FUN_007a6de0(pcVar6,0xffffffff);

  FUN_007fdfb0(unaff_ESI,uVar5,uVar7,uVar8,uVar9);

  ExceptionList = local_c;

  return;

}
