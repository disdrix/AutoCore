// =============================================================================
// UI_initjoystick_reloads_this_file
// -----------------------------------------------------------------------------
// Stable ID: aa_0081e73a
// Address:   0x0081e73a  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_initjoystick_reloads_this_file @ 0x0081e73a
// Stable ID: aa_0081e73a
// Embedded strings (evidence for future rename):
//   - ",unaff_EDI);

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: fputs×64, FUN_00816270, UI_initjoystick_reloads_this_file, fclose.
//  - Strings: ",unaff_EDI);

  fputs("; "

        ,unaff_EDI);

  fputs("; ",

        unaff_EDI);

  fputs("; ",unaff_EDI

       );

  fputs(".
//  - Return sites: 1.

  fputs("
//   - "

        ,unaff_EDI);

  fputs("
//   - ",

        unaff_EDI);

  fputs("
//   - ",unaff_EDI

       );

  fputs("
//   - "/initjoystick\" reloads this file.\n"
//   - "#\n\n\n\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "/initjoystick" reloads this file.
"
 * Domain alias of FUN_0081e73a (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void UI_initjoystick_reloads_this_file(uint32_t /* width from decompiler */ param_1,int param_2)



{

  char cVar1;

  undefined **ppuVar2;

  int *piVar3;

  FILE *unaff_EDI;

  

  fputs("#\n",unaff_EDI);

  fputs("# Mappings are in the form:\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("#   INPUT=FUNCTION\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("# Inputs are:\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("#   Button000 to Button127\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("#\tAxisX-\tAxisX+\n",unaff_EDI);

  fputs("#\tAxisY-\tAxisY+\n",unaff_EDI);

  fputs("#\tAxisZ-\tAxisZ+\n",unaff_EDI);

  fputs("#\tAxisRotX-\tAxisRotX+\n",unaff_EDI);

  fputs("#\tAxisRotY-\tAxisRotY+\n",unaff_EDI);

  fputs("#\tAxisRotZ-\tAxisRotZ+\n",unaff_EDI);

  fputs("#\tAxisSlider1-\tAxisSlider1+\n",unaff_EDI);

  fputs("#\tAxisSlider2-\tAxisSlider2+\n",unaff_EDI);

  fputs("#\tAxisForceX-\tAxisForceX+\n",unaff_EDI);

  fputs("#\tAxisForceY-\tAxisForceY+\n",unaff_EDI);

  fputs("#\tAxisForceZ-\tAxisForceZ+\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("# The \'-\' axis is in the negative direction of a stick/hat, \'+\' is in the positive direction.\n"

        ,unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("#\tPOV1_N\tPOV1_E\tPOV1_S\tPOV1_W\n",unaff_EDI);

  fputs("#\tPOV2_N\tPOV2_E\tPOV2_S\tPOV2_W\n",unaff_EDI);

  fputs("#\tPOV3_N\tPOV3_E\tPOV3_S\tPOV3_W\n",unaff_EDI);

  fputs("#\tPOV4_N\tPOV4_E\tPOV4_S\tPOV4_W\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("# POV is a direction controller, such as point-of-view hats or D-Pads,\n",unaff_EDI);

  fputs("#\t N=North, E=East, S=South, W=West\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("# Functions are:\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("#   Fire1\n",unaff_EDI);

  fputs("#   Fire2\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("#   Accelerate\n",unaff_EDI);

  fputs("#   Reverse\n",unaff_EDI);

  fputs("#   Brake\n",unaff_EDI);

  fputs("#   Left\n",unaff_EDI);

  fputs("#   Right\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("#   Okay\n",unaff_EDI);

  fputs("#   Cancel\n",unaff_EDI);

  fputs("#   Context\n",unaff_EDI);

  fputs("#   Target\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("#   LookUp\n",unaff_EDI);

  fputs("#   LookDown\n",unaff_EDI);

  fputs("#   LookLeft\n",unaff_EDI);

  fputs("#   LookRight\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("#   QuickBarNext\n",unaff_EDI);

  fputs("#   QuickBarPrev\n",unaff_EDI);

  fputs("#   QuickBarUse\n",unaff_EDI);

  fputs("#   QuickBarPage\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("# The code that parses this INI file is VERY PICKY about whitespace and comments\n",

        unaff_EDI);

  fputs("# Whitespace: don\'t use it.\n",unaff_EDI);

  fputs("# Comments: Comments MUST start a line - don\'t go commenting next to settings\n",unaff_EDI

       );

  fputs("# Comment out everything that you\'re not using!\n",unaff_EDI);

  fputs("#\n",unaff_EDI);

  fputs("# The in-game slash command \"/initjoystick\" reloads this file.\n",unaff_EDI);

  fputs("#\n\n\n\n",unaff_EDI);

  piVar3 = (int *)(param_2 + 0x1088);

  ppuVar2 = &PTR_s_Fire1_00af9400;

  do {

    if (*piVar3 != 0) {

      cVar1 = FUN_00816270(*ppuVar2);

      if (cVar1 == '\0') break;

    }

    ppuVar2 = ppuVar2 + 1;

    piVar3 = piVar3 + 1;

  } while ((int)ppuVar2 < 0xaf944c);

  fclose(unaff_EDI);

  (*DAT_00d1b608)(&DAT_00d1b20c,"joy_custom.ini");

  return;

}
