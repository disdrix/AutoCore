// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×11, return×5.
//  - Notable callees: Client_RefreshOpenMissionUiWindows×3, FUN_007fdfb0×3, CONCAT31×2, FUN_00513eb0, FUN_005710c0, FUN_00571620, FUN_00571b80, FUN_007a69d0.
//  - Return sites: 5.

// =============================================================================
// Inv_Failed_on_TradeRemoveItem_Response_tserver_retur
// -----------------------------------------------------------------------------
// Stable ID: aa_008134d0
// Address:   0x008134d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Failed on TradeRemoveItem_Response - tserver returned fail (Get a programmer)."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Inv_Failed_on_TradeRemoveItem_Response_tserver_retur(void)



{

  int iVar1;

  bool bVar2;

  int in_EAX;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  

  if (*(int *)(in_EAX + 0xe98) != 0) {

    FUN_007a69d0();

    if (*(char *)(unaff_ESI + 0x29) == '\0') {

      FUN_007fdfb0(in_EAX,

                   "Failed on TradeRemoveItem_Response - tserver returned fail (Get a programmer).",

                   0xffffffff,1,0);

      return;

    }

    iVar3 = *(int *)(in_EAX + 0x1050);

    if (iVar3 == 0) {

      FUN_007fdfb0(in_EAX,

                   "Failed on TradeRemoveItem_Response - Trade dialog box doesn\'t exist (Get a programmer)."

                   ,0xffffffff,1,0);

      return;

    }

    iVar4 = *(int *)(in_EAX + 0xe98);

    iVar1 = *(int *)(*(int *)(iVar4 + 4) + 4);

    iVar6 = 0;

    bVar2 = false;

    if ((*(int *)(iVar1 + 0x164 + iVar4) == *(int *)(unaff_ESI + 8)) &&

       (*(int *)(iVar1 + 0x168 + iVar4) == *(int *)(unaff_ESI + 0xc))) {

      if (*(int *)(iVar3 + 0x588) != 0) {

        iVar6 = *(int *)(*(int *)(iVar3 + 0x588) + 0x56c);

      }

      bVar2 = true;

    }

    else {

      iVar4 = *(int *)(in_EAX + 0xe98);

      iVar1 = *(int *)(*(int *)(iVar4 + 4) + 4);

      if ((*(int *)(iVar1 + 0x164 + iVar4) == *(int *)(unaff_ESI + 0x10)) &&

         ((*(int *)(iVar1 + 0x168 + iVar4) == *(int *)(unaff_ESI + 0x14) &&

          (*(int *)(iVar3 + 0x58c) != 0)))) {

        iVar6 = *(int *)(*(int *)(iVar3 + 0x58c) + 0x56c);

      }

    }

    iVar3 = CVOGReaction_ResolveObjectTarget

                      (1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c));

    if ((iVar6 != 0) && (iVar3 != 0)) {

      iVar4 = FUN_00571b80(iVar3,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24),0);

      if ((!bVar2) && ((iVar4 != 0 && (*(int *)(iVar4 + 0xac) == 0)))) {

        FUN_009440e0(iVar4,1,0,0xffffffff,0xffffffff);

      }

      Client_RefreshOpenMissionUiWindows(in_EAX);

    }

    if (((bVar2) && (iVar4 = *(int *)(*(int *)(in_EAX + 0xe98) + 0x250), iVar4 != 0)) &&

       (*(int *)(iVar4 + 0x2b0) != 0)) {

      if (*(char *)(unaff_ESI + 0x28) != '\0') {

        iVar4 = FUN_005710c0(*(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0xa8) + 0x34),0,0);

        if (iVar4 != 0) {

          FUN_00513eb0(iVar3);

          Client_RefreshOpenMissionUiWindows(in_EAX);

          return;

        }

        uVar8 = 1;

        uVar7 = 0xffffffff;

        uVar5 = FUN_007a6de0("Failed on TradeRemoveItem_Response - Adding to existing, but not found."

                             ,0xffffffff);

        FUN_007fdfb0(in_EAX,uVar5,uVar7,uVar8,iVar4);

        return;

      }

      FUN_00571620(iVar3,CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24) >> 8),

                                  *(uint8_t *)(unaff_ESI + 0x20)),

                   CONCAT31((int3)((uint)iVar4 >> 8),*(uint8_t *)(unaff_ESI + 0x21)),

                   *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24));

      Client_RefreshOpenMissionUiWindows(in_EAX);

    }

  }

  return;

}
