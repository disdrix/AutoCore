// =============================================================================
// FUN_0080c130
// -----------------------------------------------------------------------------
// Stable ID: aa_0080c130
// Address:   0x0080c130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080c130 @ 0x0080c130
// Stable ID: aa_0080c130
// Embedded strings (evidence for future rename):
//   - "Trade request refused."
//   - "Failed on TradeRequest_Response - Trade dialog box doesn\'t exist (Get a programmer)."
//   - "That person is currently too busy to trade."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: FUN_007fc360×3, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_007fef20, FUN_0080c130, FUN_008841d0, exist.
//  - Strings: "Trade request refused."; "That person is currently too busy to trade.".
//  - Return sites: 4.

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

void FUN_0080c130(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int unaff_EDI;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  

  FUN_007a69d0();

  if (*(char *)(in_EAX + 0x10) == '\0') {

    if (*(char *)(in_EAX + 0x11) == '\0') {

      FUN_007fc360();

      iVar1 = *(int *)(unaff_EDI + 0xe98);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcd8) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcdc) = 0xffffffff;

      iVar1 = *(int *)(unaff_EDI + 0xe98);

      iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

      if ((*(int *)(in_EAX + 8) == *(int *)(iVar2 + 0x164 + iVar1)) &&

         (*(int *)(in_EAX + 0xc) == *(int *)(iVar2 + 0x168 + iVar1))) {

        return;

      }

      pcVar5 = "Trade request refused.";

    }

    else {

      if (*(int *)(unaff_EDI + 0x1050) != 0) {

        FUN_007fc360();

        pvVar3 = Client_LookupObjectByTfid_Inferred

                           (1,*(uint *)(*(int *)(unaff_EDI + 0xe98) + 0xcd8),

                            *(uint *)(*(int *)(unaff_EDI + 0xe98) + 0xcdc));

        if (pvVar3 == (void *)0x0) {

          return;

        }

        FUN_008841d0();

        FUN_007fef20(8,1,0);

        return;

      }

      pcVar5 = 

      "Failed on TradeRequest_Response - Trade dialog box doesn\'t exist (Get a programmer).";

    }

  }

  else {

    FUN_007fc360();

    iVar1 = *(int *)(unaff_EDI + 0xe98);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcd8) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcdc) = 0xffffffff;

    pcVar5 = "That person is currently too busy to trade.";

  }

  uVar8 = 0;

  uVar7 = 1;

  uVar6 = 0xffffffff;

  uVar4 = FUN_007a6de0(pcVar5,0xffffffff);

  FUN_007fdfb0(unaff_EDI,uVar4,uVar6,uVar7,uVar8);

  return;

}
