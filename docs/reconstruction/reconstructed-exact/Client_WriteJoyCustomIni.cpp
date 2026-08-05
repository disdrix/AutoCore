// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, for×1, do×1, while×1.
//  - Notable callees: fputs×64, FUN_007a4480, FUN_00816270, FUN_0081e700, fclose, fopen.
//  - Strings: "joy_custom.ini"; ");

    if (_File == (FILE *)0x0) {

      FUN_007a4480(1,"; ")

      ;

      return;

    }

    fputs("; ",_File);

    fputs(".
//  - Return sites: 2.

// =============================================================================
// Client_WriteJoyCustomIni
// -----------------------------------------------------------------------------
// Purpose:  Writes joy_custom.ini template including Drive axes and QuickBarNext/Prev/Use/Page.
//
// Address:  0x0081e700  (autoassault.exe, image base 0x400000)
// Stable:   aa_0081e700
// System:   input-drive-control
//
// String evidence: "joy_custom.ini" / QuickBarNext / Accelerate / Reverse
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_0081e700.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_0081e700 using string evidence: "joy_custom.ini" / QuickBarNext / Accelerate / Reverse
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void Client_WriteJoyCustomIni(int param_1)

{

  char cVar1;

  FILE *_File;

  undefined **ppuVar2;

  int *piVar3;

  

  if (DAT_00d1b608 != (code *)0x0) {

    _File = fopen("joy_custom.ini","w");

    if (_File == (FILE *)0x0) {

      FUN_007a4480(1,"Unable to create joy_custom.ini file for saving, all changes will be lost...")

      ;

      return;

    }

    fputs("#\n",_File);

    fputs("# Mappings are in the form:\n",_File);

    fputs("#\n",_File);

    fputs("#   INPUT=FUNCTION\n",_File);

    fputs("#\n",_File);

    fputs("# Inputs are:\n",_File);

    fputs("#\n",_File);

    fputs("#   Button000 to Button127\n",_File);

    fputs("#\n",_File);

    fputs("#\tAxisX-\tAxisX+\n",_File);

    fputs("#\tAxisY-\tAxisY+\n",_File);

    fputs("#\tAxisZ-\tAxisZ+\n",_File);

    fputs("#\tAxisRotX-\tAxisRotX+\n",_File);

    fputs("#\tAxisRotY-\tAxisRotY+\n",_File);

    fputs("#\tAxisRotZ-\tAxisRotZ+\n",_File);

    fputs("#\tAxisSlider1-\tAxisSlider1+\n",_File);

    fputs("#\tAxisSlider2-\tAxisSlider2+\n",_File);

    fputs("#\tAxisForceX-\tAxisForceX+\n",_File);

    fputs("#\tAxisForceY-\tAxisForceY+\n",_File);

    fputs("#\tAxisForceZ-\tAxisForceZ+\n",_File);

    fputs("#\n",_File);

    fputs("# The \'-\' axis is in the negative direction of a stick/hat, \'+\' is in the positive direction.\n"

          ,_File);

    fputs("#\n",_File);

    fputs("#\tPOV1_N\tPOV1_E\tPOV1_S\tPOV1_W\n",_File);

    fputs("#\tPOV2_N\tPOV2_E\tPOV2_S\tPOV2_W\n",_File);

    fputs("#\tPOV3_N\tPOV3_E\tPOV3_S\tPOV3_W\n",_File);

    fputs("#\tPOV4_N\tPOV4_E\tPOV4_S\tPOV4_W\n",_File);

    fputs("#\n",_File);

    fputs("# POV is a direction controller, such as point-of-view hats or D-Pads,\n",_File);

    fputs("#\t N=North, E=East, S=South, W=West\n",_File);

    fputs("#\n",_File);

    fputs("# Functions are:\n",_File);

    fputs("#\n",_File);

    fputs("#   Fire1\n",_File);

    fputs("#   Fire2\n",_File);

    fputs("#\n",_File);

    fputs("#   Accelerate\n",_File);

    fputs("#   Reverse\n",_File);

    fputs("#   Brake\n",_File);

    fputs("#   Left\n",_File);

    fputs("#   Right\n",_File);

    fputs("#\n",_File);

    fputs("#   Okay\n",_File);

    fputs("#   Cancel\n",_File);

    fputs("#   Context\n",_File);

    fputs("#   Target\n",_File);

    fputs("#\n",_File);

    fputs("#   LookUp\n",_File);

    fputs("#   LookDown\n",_File);

    fputs("#   LookLeft\n",_File);

    fputs("#   LookRight\n",_File);

    fputs("#\n",_File);

    fputs("#   QuickBarNext\n",_File);

    fputs("#   QuickBarPrev\n",_File);

    fputs("#   QuickBarUse\n",_File);

    fputs("#   QuickBarPage\n",_File);

    fputs("#\n",_File);

    fputs("# The code that parses this INI file is VERY PICKY about whitespace and comments\n",_File

         );

    fputs("# Whitespace: don\'t use it.\n",_File);

    fputs("# Comments: Comments MUST start a line - don\'t go commenting next to settings\n",_File);

    fputs("# Comment out everything that you\'re not using!\n",_File);

    fputs("#\n",_File);

    fputs("# The in-game slash command \"/initjoystick\" reloads this file.\n",_File);

    fputs("#\n\n\n\n",_File);

    piVar3 = (int *)(param_1 + 0x1088);

    ppuVar2 = &PTR_s_Fire1_00af9400;

    do {

      if (*piVar3 != 0) {

        cVar1 = FUN_00816270(*ppuVar2);

        if (cVar1 == '\0') break;

      }

      ppuVar2 = ppuVar2 + 1;

      piVar3 = piVar3 + 1;

    } while ((int)ppuVar2 < 0xaf944c);

    fclose(_File);

    (*DAT_00d1b608)(&DAT_00d1b20c,"joy_custom.ini");

  }

  return;

}
