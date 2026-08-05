// =============================================================================
// Named_CalleeOf_Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml_008cedd0
// -----------------------------------------------------------------------------
// Stable ID: aa_008cedd0
// Callee of Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml
// Address:   0x008cedd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml: combat/reward helper. Evidence string: "Commando". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_fec_2d_btn_class_commando"
//   - "i_d_fec_2d_btn_class_engineer"
//   - "i_d_fec_2d_btn_class_lieutenant"
//   - "i_d_fec_2d_btn_class_bountyhunter"
//   - "Commando"
//   - "Engineer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: if×31, goto×4, return×2.
//  - Notable callees: FUN_008cedd0.
//  - Strings: "i_d_fec_2d_btn_class_commando"; "i_d_fec_2d_btn_class_engineer"; "i_d_fec_2d_btn_class_lieutenant"; "i_d_fec_2d_btn_class_bountyhunter".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml
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

void Named_CalleeOf_Named_i_d_fec_2d_wnd_tooltip_attrib_combat_xml_008cedd0(void)



{

  int in_EAX;

  int unaff_ESI;

  char *pcVar1;

  

  if (in_EAX == 0) {

    if (*(int *)(unaff_ESI + 0x6d0) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x3ac))("i_d_fec_2d_btn_class_commando");

    }

    if (*(int *)(unaff_ESI + 0x6d4) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x3ac))("i_d_fec_2d_btn_class_engineer");

    }

    if (*(int *)(unaff_ESI + 0x6d8) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x3ac))("i_d_fec_2d_btn_class_lieutenant");

    }

    if (*(int *)(unaff_ESI + 0x6dc) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x3ac))("i_d_fec_2d_btn_class_bountyhunter");

    }

    if (*(int *)(unaff_ESI + 0x6d0) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x308))("Commando");

    }

    if (*(int *)(unaff_ESI + 0x6d4) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x308))("Engineer");

    }

    if (*(int *)(unaff_ESI + 0x6d8) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x308))("Lieutenant");

    }

    if (*(int *)(unaff_ESI + 0x6dc) == 0) goto LAB_008cf081;

    pcVar1 = "Bounty Hunter";

  }

  else if (in_EAX == 1) {

    if (*(int *)(unaff_ESI + 0x6d0) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x3ac))("i_d_fec_2d_btn_class_champion");

    }

    if (*(int *)(unaff_ESI + 0x6d4) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x3ac))("i_d_fec_2d_btn_class_shaman");

    }

    if (*(int *)(unaff_ESI + 0x6d8) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x3ac))("i_d_fec_2d_btn_class_archon");

    }

    if (*(int *)(unaff_ESI + 0x6dc) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x3ac))("i_d_fec_2d_btn_class_avenger");

    }

    if (*(int *)(unaff_ESI + 0x6d0) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x308))("Champion");

    }

    if (*(int *)(unaff_ESI + 0x6d4) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x308))("Shaman");

    }

    if (*(int *)(unaff_ESI + 0x6d8) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x308))("Archon");

    }

    if (*(int *)(unaff_ESI + 0x6dc) == 0) goto LAB_008cf081;

    pcVar1 = "Avenger";

  }

  else {

    if (in_EAX != 2) goto LAB_008cf081;

    if (*(int *)(unaff_ESI + 0x6d0) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x3ac))("i_d_fec_2d_btn_class_terminator");

    }

    if (*(int *)(unaff_ESI + 0x6d4) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x3ac))("i_d_fec_2d_btn_class_constructor");

    }

    if (*(int *)(unaff_ESI + 0x6d8) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x3ac))("i_d_fec_2d_btn_class_mastermind");

    }

    if (*(int *)(unaff_ESI + 0x6dc) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x3ac))("i_d_fec_2d_btn_class_agent");

    }

    if (*(int *)(unaff_ESI + 0x6d0) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x308))("Terminator");

    }

    if (*(int *)(unaff_ESI + 0x6d4) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x308))("Constructor");

    }

    if (*(int *)(unaff_ESI + 0x6d8) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x308))("MasterMind");

    }

    if (*(int *)(unaff_ESI + 0x6dc) == 0) goto LAB_008cf081;

    pcVar1 = "Agent";

  }

  (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x308))(pcVar1);

LAB_008cf081:

  if (*(int *)(unaff_ESI + 0x6d0) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0xd4))(1);

    (**(code **)(**(int **)(unaff_ESI + 0x6d0) + 0x34c))();

  }

  if (*(int *)(unaff_ESI + 0x6d4) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0xd4))(1);

    (**(code **)(**(int **)(unaff_ESI + 0x6d4) + 0x34c))();

  }

  if (*(int *)(unaff_ESI + 0x6d8) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0xd4))(1);

    (**(code **)(**(int **)(unaff_ESI + 0x6d8) + 0x34c))();

  }

  if (*(int *)(unaff_ESI + 0x6dc) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0xd4))(1);

                    /* WARNING: Could not recover jumptable at 0x008cf117. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x34c))();

    return;

  }

  return;

}
