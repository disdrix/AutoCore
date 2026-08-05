// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_0080dcc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080dcc0
// Callee of Client_PacketDispatch
// Address:   0x0080dcc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper. Evidence string: "Attempting... Failed!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Attempting... Failed!"
//   - "Percent Chance To Memorize:"
//   - "You Had No Chance Of Memorizing The Item!"
//   - "Attempting... Success!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×11, do×2, return×2, while×1.
//  - Notable callees: FUN_007a6de0×7, FUN_007a69d0×6, FUN_00524290×2, FUN_008f8200×2, sprintf×2, Client_RefreshOpenMissionUiWindows, FUN_00524190, FUN_0052cec0.
//  - Strings: "Attempting... Failed!"; "Percent Chance To Memorize:"; "%s %d%% - %s"; "You Had No Chance Of Memorizing The Item!".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Client_PacketDispatch_0080dcc0(void)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  int unaff_ESI;

  int unaff_EDI;

  float10 fVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  float local_104;

  char local_100 [256];

  

  FUN_007a69d0();

  if (*(char *)(unaff_EDI + 0x13) != '\0') {

    if (*(char *)(unaff_EDI + 0x12) != '\0') {

      iVar2 = CVOGReaction_ResolveObjectTarget

                        (1,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc));

      if ((iVar2 == 0) || (DAT_00d1b6d8 == 0)) {

        local_104 = 0.0;

      }

      else {

        fVar4 = (float10)FUN_0052cec0(iVar2);

        local_104 = (float)fVar4;

      }

      uVar9 = 0xffffffff;

      if (*(char *)(unaff_EDI + 0x13) == '\0') {

        if (DAT_00aaa664 <= local_104) {

          pcVar7 = "Attempting... Failed!";

          FUN_007a69d0("Attempting... Failed!");

          uVar9 = FUN_007a6de0(pcVar7,uVar9);

          uVar5 = 0xffffffff;

          pcVar7 = "Percent Chance To Memorize:";

          FUN_007a69d0("Percent Chance To Memorize:",0xffffffff,(int)(local_104 * DAT_00aaa7ac),

                       uVar9);

          uVar9 = FUN_007a6de0(pcVar7,uVar5);

          sprintf(local_100,"%s %d%% - %s",uVar9);

        }

        else {

          pcVar7 = "You Had No Chance Of Memorizing The Item!";

          FUN_007a69d0("You Had No Chance Of Memorizing The Item!");

          pcVar3 = (char *)FUN_007a6de0(pcVar7,uVar9);

          pcVar7 = local_100;

          do {

            cVar1 = *pcVar3;

            *pcVar7 = cVar1;

            pcVar3 = pcVar3 + 1;

            pcVar7 = pcVar7 + 1;

          } while (cVar1 != '\0');

        }

        if ((DAT_00d1b780 != 0) && (DAT_00d1b8dc != 0)) {

          FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_100,0);

        }

      }

      else {

        pcVar7 = "Attempting... Success!";

        FUN_007a69d0("Attempting... Success!",0xffffffff);

        uVar9 = FUN_007a6de0(pcVar7,uVar9);

        uVar5 = 0xffffffff;

        pcVar7 = "Percent Chance To Memorize:";

        FUN_007a69d0("Percent Chance To Memorize:",0xffffffff,(int)(local_104 * DAT_00aaa7ac),uVar9)

        ;

        uVar9 = FUN_007a6de0(pcVar7,uVar5);

        sprintf(local_100,"%s %d%% - %s",uVar9);

        if ((DAT_00d1b780 != 0) && (DAT_00d1b8dc != 0)) {

          FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_100,0);

        }

        FUN_007fef20(0,1,0);

        FUN_00888b00(DAT_00d1b870,1);

        *(uint8_t *)(unaff_ESI + 0x30d0) = 0;

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30c8) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8);

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30cc) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc);

        uVar9 = FUN_00524290();

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30d4) = uVar9;

        iVar2 = FUN_00524290();

        uVar9 = 0;

        if (iVar2 == -1) {

          uVar8 = 0;

          uVar6 = 0x4e43;

          uVar5 = FUN_007a6de0("You have successfully memorized this item! All of your available slots are full, however, so you must overwrite an existing memory item. Select an item from Memory to replace, or hit cancel if you do not wish to memorize the new object."

                               ,0xffffffff);

        }

        else {

          uVar8 = 1;

          uVar6 = 0x4e41;

          uVar5 = FUN_007a6de0("You have successfully memorized this item! Do you wish to add it your Item Memory so that you can craft it in the future?"

                               ,0xffffffff);

        }

        FUN_007fdfb0(unaff_ESI,uVar5,uVar6,uVar8,uVar9);

      }

      if (*(char *)(unaff_EDI + 0x12) != '\0') {

        return;

      }

    }

    if ((*(char *)(unaff_EDI + 0x11) != '\0') &&

       (iVar2 = CVOGReaction_ResolveObjectTarget

                          (1,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc)),

       iVar2 != 0)) {

      FUN_00524190(*(uint8_t *)(unaff_EDI + 0x10),iVar2);

      Client_RefreshOpenMissionUiWindows(unaff_ESI);

    }

  }

  return;

}
