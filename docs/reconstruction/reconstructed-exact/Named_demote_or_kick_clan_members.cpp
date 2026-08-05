// =============================================================================
// Named_demote_or_kick_clan_members
// -----------------------------------------------------------------------------
// Stable ID: aa_008f1580
// Address:   0x008f1580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_demote_or_kick_clan_members @ 0x008f1580
// Stable ID: aa_008f1580
// Embedded strings (evidence for future rename):
//   - "To view clan member details:"
//   - "To promote/demote or kick clan members:"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×13, goto×3, return×1.
//  - Notable callees: FUN_008f0f40×3, FUN_008f0f80×3, FUN_008f1070×3, FUN_008f1290, Named_demote_or_kick_clan_members.
//  - Strings: "To view clan member details:"; "To promote/demote or kick clan members:".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "To promote/demote or kick clan members:"
 * Domain alias of FUN_008f1580 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_demote_or_kick_clan_members(int *param_1)



{

  int in_EAX;

  int *piVar1;

  char *pcVar2;

  

  param_1[0x148] = in_EAX;

  if (in_EAX == 0) {

    FUN_008f1070(1);

    FUN_008f0f80(0);

    FUN_008f0f40();

    if ((int *)param_1[0x14f] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x14f] + 0x1d8))

                ("If you wish to create a clan, input the name you would like into the box below and click \'Submit Clan\'.  Keep in mind, however, that founding a clan is not free.  It will cost you an amount specified by the \'Creation Fee\'."

                 ,1,1);

    }

    piVar1 = (int *)param_1[0x163];

    if (piVar1 == (int *)0x0) goto LAB_008f16a5;

    pcVar2 = "";

  }

  else {

    if (in_EAX != 1) {

      if (in_EAX == 2) {

        FUN_008f1070(0);

        FUN_008f0f80(1);

        FUN_008f0f40();

        if ((int *)param_1[0x14f] != (int *)0x0) {

          (**(code **)(*(int *)param_1[0x14f] + 0x1d8))

                    ("Contact your Clan Leader if you need any of the clan settings changed.  The current settings are displayed below."

                     ,1,1);

        }

        if ((int *)param_1[0x163] != (int *)0x0) {

          (**(code **)(*(int *)param_1[0x163] + 0x1d8))("To view clan member details:",1,1);

        }

        if ((int *)param_1[0x164] != (int *)0x0) {

          (**(code **)(*(int *)param_1[0x164] + 0xcc))(0);

        }

      }

      goto LAB_008f16a5;

    }

    FUN_008f1070(0);

    FUN_008f0f80(1);

    FUN_008f0f40();

    if ((int *)param_1[0x14f] != (int *)0x0) {

      (**(code **)(*(int *)param_1[0x14f] + 0x1d8))

                ("As Clan Leader, you are entitled to alter the clan\'s titles and the Message of the Day.  Once you have made your changes, click the \'Accept Changes\' button to finalize them."

                 ,1,1);

    }

    piVar1 = (int *)param_1[0x163];

    if (piVar1 == (int *)0x0) goto LAB_008f16a5;

    pcVar2 = "To promote/demote or kick clan members:";

  }

  (**(code **)(*piVar1 + 0x1d8))(pcVar2,1,1);

LAB_008f16a5:

  if ((int *)param_1[0x14f] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x14f] + 0x34c))();

  }

  if ((int *)param_1[0x163] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x163] + 0x34c))();

  }

  FUN_008f1290();

                    /* WARNING: Could not recover jumptable at 0x008f16d4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x448))();

  return;

}
