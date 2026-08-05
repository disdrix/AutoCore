// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×17, return×5, for×2.
//  - Notable callees: FUN_00807550×3, Client_CreateVehicleObjectApply×2, FUN_007fb2b0×2, FUN_008024d0×2, FUN_009972a0×2, CONCAT31, CVOGHBList_Enqueue, CVOGReaction_GiveItemByCbid.
//  - Strings: "allocatenewobjectfromcbid failed %d Get a programmer".
//  - Return sites: 5.

// =============================================================================
// Client_CreateVehicleObjectApply
// -----------------------------------------------------------------------------
// Stable ID: aa_00812630
// Address:   0x00812630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Client_CreateVehicleObjectApply (0x00812630)

   CreateVehicle / object-table apply for opcode 0x201D create buffer (game create +

   ghost materialize). Can lead to EquipFromCreate for nested wheelset.

   See OWNER_WHEEL_RACE_RE.md. Imported from AutoCore decompile dump 2026-07-11. */



void __thiscall Client_CreateVehicleObjectApply(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  void *pvVar7;

  uint64_t uVar8;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009bb4e1;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  iVar2 = FUN_004bb010(param_1 + 0x90);

  if (iVar2 == 0) {

    piVar4 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(param_1 + 4));

    if (piVar4 != (int *)0x0) {

      iVar2 = (**(code **)(*piVar4 + 0x1d4))();

      if (iVar2 != 0) {

        (**(code **)(*piVar4 + 8))(*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 0xe04),0);

        if (*(char *)(param_1 + 0xa1) != '\0') {

          *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8) = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc) = 0xffffffff;

        }

        uVar8 = (**(code **)(*piVar4 + 0x1d4))();

        cVar1 = *(char *)(*(int *)(param_2 + 0xe04) + 0xf5);

        pvVar7 = (void *)CONCAT31((int3)((ulonglong)uVar8 >> 0x28),cVar1 == '\0');

        (**(code **)(*(int *)(*(int *)(*(int *)((int)uVar8 + 4) + 4) + 4 + (int)uVar8) + 0xc4))

                  (param_1,2,*(uint32_t /* width from decompiler */ *)(param_2 + 0xe04),*(char *)(param_1 + 0xa1) == '\0',

                   pvVar7,cVar1 == '\0',uStack_4);

        if (*(char *)(param_1 + 0xa1) != '\0') {

          (**(code **)(*piVar4 + 0x158))(0);

          FUN_009972a0();

          FUN_008024d0(param_2,DAT_00d1d86c,DAT_00d1d870,0,0,0,piVar4[0x58],piVar4[0x59]);

        }

        if (*(char *)(param_1 + 0xc0) != '\0') {

          FUN_007fb2b0(piVar4[0x58],piVar4[0x59]);

        }

        if ((*(char *)(param_1 + 0xa7) == '\0') &&

           ((*(uint *)(param_1 + 8) & *(uint *)(param_1 + 0xc)) == 0xffffffff)) {

          if (*(char *)(param_1 + 0x151) != '\0') {

            FUN_0092a3b0(piVar4);

            FUN_00807550(piVar4);

            ExceptionList = pvVar7;

            return;

          }

          (**(code **)(*piVar4 + 0x1d4))();

          FUN_004027f0(param_2 + 0xefc);

          if ((*(int *)(param_2 + 0x508) == *(int *)(param_1 + 0xd8)) &&

             (*(int *)(param_2 + 0x50c) == *(int *)(param_1 + 0xdc))) {

            iVar2 = (**(code **)(*piVar4 + 0x1d4))();

            if (iVar2 != 0) {

              *(uint8_t *)(iVar2 + 0x105) = *(uint8_t *)(param_2 + 0x9c4);

              *(uint8_t *)(iVar2 + 0x106) = *(uint8_t *)(param_2 + 0x9c4);

              iVar3 = FUN_00404a00();

              if (iVar3 != 0) {

                iVar3 = FUN_00418d40();

                if (iVar3 != 0) {

                  FUN_004b6a00();

                }

              }

            }

            if ((((*(int *)(param_2 + 0xe98) != 0) &&

                 (*(char *)(*(int *)(param_2 + 0xe98) + 0x30c) != '\0')) &&

                (*(int **)(param_2 + 0xf40) != (int *)0x0)) &&

               (**(int **)(param_2 + 0xf40) == *(int *)(param_2 + 0xf38))) {

              pvVar5 = operator_new(0x44);

              if (pvVar5 == (void *)0x0) {

                uVar6 = 0;

              }

              else {

                uVar6 = FUN_00599550(iVar2,*(uint32_t /* width from decompiler */ *)(param_2 + 0xe04));

              }

              *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0xf38) + 0xc70) = uVar6;

              CVOGHBList_Enqueue(*(void **)(param_2 + 0xd38),

                                 *(CVOGHBBase **)(*(int *)(param_2 + 0xf38) + 0xc70));

              FUN_005081d0();

              FUN_00807550(piVar4);

              ExceptionList = pvVar7;

              return;

            }

          }

        }

        else {

          iVar2 = *(int *)(param_2 + 0x4d0);

          cVar1 = FUN_0092a200();

          if (cVar1 != '\0') {

            *(uint8_t *)(iVar2 + 4) = 1;

          }

        }

        FUN_00807550(piVar4);

        ExceptionList = pvVar7;

        return;

      }

    }

    FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer",

                 *(uint32_t /* width from decompiler */ *)(param_1 + 4));

  }

  else {

    if (*(char *)(param_1 + 0xa1) != '\0') {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x84))();

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0xc4))

                (param_1,2,*(uint32_t /* width from decompiler */ *)(param_2 + 0xe04),0,0,0,0);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x134) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14c);

      FUN_009972a0();

      iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4) + iVar2;

      FUN_008024d0(param_2,DAT_00d1d86c,DAT_00d1d870,0,0,0,*(uint32_t /* width from decompiler */ *)(iVar3 + 0x164),

                   *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168));

    }

    if (*(char *)(param_1 + 0xc0) != '\0') {

      iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);

      FUN_007fb2b0(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + iVar2),*(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + iVar2));

      ExceptionList = pvStack_c;

      return;

    }

  }

  ExceptionList = pvStack_c;

  return;

}
