// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×13, return×3, do×1, while×1.
//  - Notable callees: FUN_007a4480×4, CONCAT31, CVOGCharacter_SetQuickBarItem, CVOGCharacter_SetQuickBarSkill, CVOGReaction_GiveItemByCbid, Client_RecvCreateCharacter, Client_RefreshLocalCharacterLevelUi, CreateCharacterExtended.
//  - Strings: "allocatenewobjectfromcbid failed %d"; "allocatenewobjectfromcbid %d"; "after createfrompacket"; "end createcharfrompacket".
//  - Return sites: 3.

// =============================================================================
// Client_RecvCreateCharacter
// -----------------------------------------------------------------------------
// Stable ID: aa_008146b0
// Address:   0x008146b0  (autoassault.exe, image base 0x400000)
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

void __fastcall Client_RecvCreateCharacter(int param_1,int param_2)



{

  int iVar1;

  char in_AL;

  char cVar2;

  void *pvVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint uVar7;

  byte slot;

  uint *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  void *pvStack_4;

  

  iVar6 = *(int *)(param_2 + 0xe98);

  if (((iVar6 == 0) ||

      (iVar1 = *(int *)(*(int *)(iVar6 + 4) + 4),

      *(int *)(iVar1 + 0x164 + iVar6) != *(int *)(param_1 + 0x90))) ||

     (*(int *)(iVar1 + 0x168 + iVar6) != *(int *)(param_1 + 0x94))) {

    pvVar3 = Client_LookupObjectByTfid_Inferred

                       (*(byte *)(param_1 + 0x98),*(uint *)(param_1 + 0x90),

                        *(uint *)(param_1 + 0x94));

    if (pvVar3 == (void *)0x0) {

      if (((*(int *)(param_2 + 0x508) == *(int *)(param_1 + 0x90)) &&

          (*(int *)(param_2 + 0x50c) == *(int *)(param_1 + 0x94))) && (in_AL == '\0')) {

        return;

      }

      piVar4 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(param_1 + 4));

      if (piVar4 == (int *)0x0) {

        FUN_007a4480(1,"allocatenewobjectfromcbid failed %d",*(uint32_t /* width from decompiler */ *)(param_1 + 4));

        return;

      }

      (**(code **)(*piVar4 + 8))(*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 0xe04),0);

      FUN_007a4480(0,"allocatenewobjectfromcbid %d",*(uint32_t /* width from decompiler */ *)(param_1 + 4));

      uVar9 = 0;

      uVar5 = (**(code **)(*piVar4 + 0x210))(0,*(int *)(param_2 + 0xe98) != 0);

      FUN_004d32c0(uVar5,uVar9);

      iVar6 = (**(code **)(*piVar4 + 0x1dc))();

      if ((*(int *)(param_2 + 0x508) == *(int *)(param_1 + 0x90)) &&

         (*(int *)(param_2 + 0x50c) == *(int *)(param_1 + 0x94))) {

        FUN_0092f540();

      }

      uVar7 = CONCAT31((int3)((uint)*(int *)(iVar6 + 4) >> 8),~*(byte *)(param_1 + 0x129)) &

              0xffffff01;

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0xc4))

                (param_1,2,*(uint32_t /* width from decompiler */ *)(param_2 + 0xe04),1,uVar7,uVar7);

      FUN_004027f0(param_2 + 0xf08);

      if (*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xa8 + iVar6) != 0) {

        FUN_004dea70();

      }

      FUN_007a4480(0,"after createfrompacket");

      pvVar3 = pvStack_4;

      if ((*(int *)(param_2 + 0x508) == *(int *)(param_1 + 0x90)) &&

         (*(int *)(param_2 + 0x50c) == *(int *)(param_1 + 0x94))) {

        Client_RefreshLocalCharacterLevelUi();

        if (((*(byte *)(param_1 + 0x129) & 1) == 0) &&

           ((*(uint *)(*(int *)(param_2 + 0xe98) + 0x210) &

            *(uint *)(*(int *)(param_2 + 0xe98) + 0x214)) != 0xffffffff)) {

          if (*(int *)(*(int *)(param_2 + 0xf38) + 0xc70) != 0) {

            *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0xf38) + 0xc70) = 0;

          }

          if ((*(int **)(param_2 + 0xf40) != (int *)0x0) &&

             (**(int **)(param_2 + 0xf40) == *(int *)(param_2 + 0xf38))) {

            *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0xf38) + 0x60c) = 0;

            FUN_0090dd50();

          }

        }

        if (in_AL != '\0') {

                    /* CreateCharacterExtended (in_AL/extended): restore 100 QuickBar item COIDs

                       from packet+0x410 and skill ids from packet+0x730. */

          slot = 0;

          piVar4 = (int *)(param_1 + 0x730);

          puVar8 = (uint *)(param_1 + 0x410);

          do {

            CVOGCharacter_SetQuickBarItem(*(void **)(param_2 + 0xe98),slot,*puVar8,puVar8[1]);

            CVOGCharacter_SetQuickBarSkill(*(void **)(param_2 + 0xe98),slot,*piVar4);

            slot = slot + 1;

            puVar8 = puVar8 + 2;

            piVar4 = piVar4 + 1;

          } while (slot < 100);

          if (*(int *)(param_2 + 0x10b0) != 0) {

            FUN_008a0e10(*(int *)(param_2 + 0x10b0));

          }

          FUN_0094c2d0();

          FUN_0094c350();

          *(uint8_t *)(param_2 + 0x31f4) = 0;

          FUN_0094c2a0();

          FUN_009430f0();

        }

      }

    }

    if ((((*(int *)(param_2 + 0xe98) != 0) && (*(int *)(*(int *)(param_2 + 0xe98) + 0xcb0) != 0)) &&

        (cVar2 = FUN_00574a30(pvVar3), cVar2 != '\0')) &&

       (*(int **)(param_2 + 0x10a0) != (int *)0x0)) {

      (**(code **)(**(int **)(param_2 + 0x10a0) + 0x448))();

      (**(code **)(**(int **)(param_2 + 0x10a0) + 0x34c))();

    }

    FUN_007a4480(0,"end createcharfrompacket");

  }

  return;

}
