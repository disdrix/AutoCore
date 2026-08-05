// =============================================================================
// FUN_0080fe10
// -----------------------------------------------------------------------------
// Stable ID: aa_0080fe10
// Address:   0x0080fe10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080fe10 @ 0x0080fe10
// Stable ID: aa_0080fe10
// Embedded strings (evidence for future rename):
//   - "Convoy Loot Mode switched to \'Killer Takes Loot\'."
//   - "Convoy Loot Mode switched to \'Even Distribution\'."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00574dd0, FUN_007a69d0, FUN_007a6de0, FUN_0080fe10, FUN_008f8200, __RTDynamicCast.
//  - Strings: "Convoy Loot Mode switched to \'Killer Takes Loot\'."; "Convoy Loot Mode switched to \'Even Distribution\'.".
//  - Return sites: 2.

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

void FUN_0080fe10(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_EBX;

  int unaff_ESI;

  char *pcVar3;

  

  FUN_007a69d0();

  if ((*(int *)(unaff_ESI + 0xe98) != 0) && (*(int *)(*(int *)(unaff_ESI + 0xe98) + 0xcb0) != 0)) {

    FUN_00574dd0((int)*(char *)(unaff_EBX + 5));

    iVar1 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x109c),0,&CVOGDialog::RTTI_Type_Descriptor,

                            &CDlgChatLog::RTTI_Type_Descriptor,0);

    if (iVar1 != 0) {

      if (*(char *)(unaff_EBX + 5) == '\0') {

        pcVar3 = "Convoy Loot Mode switched to \'Killer Takes Loot\'.";

      }

      else {

        if (*(char *)(unaff_EBX + 5) != '\x01') {

          return;

        }

        pcVar3 = "Convoy Loot Mode switched to \'Even Distribution\'.";

      }

      uVar2 = FUN_007a6de0(pcVar3,0xffffffff);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,uVar2,0);

      }

    }

  }

  return;

}
