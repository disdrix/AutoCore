// =============================================================================
// FUN_007f9480
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9480
// Address:   0x007f9480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007f9480 @ 0x007f9480
// Stable ID: aa_007f9480
// Embedded strings (evidence for future rename):
//   - ");

// READABILITY (auto CF):
//  - Body size: ~179 non-empty decompiler lines.
//  - Control keywords: if×18, do×3, while×3, return×2, for×1.
//  - Notable callees: fprintf×87, FUN_007f5120×12, FUN_007a6de0×7, ESCAPE, FUN_007a69d0, FUN_007f9480, GetFileAttributesA, NUMPAD9.
//  - Strings: ");

  if (_File != (FILE *)0x0) {

    fprintf(_File,"; ");

    fprintf(_File,"; "%s="; "+%s".
//  - Return sites: 2.

  if (_File != (FILE *)0x0) {

    fprintf(_File,"
//   - ");

    fprintf(_File,"
//   - ");

    pcVar3 = (char *)FUN_007a6de0("
//   - ",0xffffffff);

    fprintf(_File,pcVar3);

    pcVar3 = (char *)FUN_007a6de0("
//   - ")

    ;

    fprintf(_File,"
//   - "

           );

    fprintf(_File,"
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

uint32_t /* width from decompiler */ FUN_007f9480(int param_1)



{

  LPCSTR in_EAX;

  DWORD DVar1;

  FILE *_File;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  int iVar4;

  int local_8;

  

  if (in_EAX == (LPCSTR)0x0) {

    return 0;

  }

  FUN_007a69d0();

  DVar1 = GetFileAttributesA(in_EAX);

  if ((DVar1 != 0xffffffff) && ((DVar1 & 1) != 0)) {

    SetFileAttributesA(in_EAX,DVar1 & 0xfffffffe);

  }

  _File = fopen(in_EAX,"w");

  if (_File != (FILE *)0x0) {

    fprintf(_File,"////////////////////////////////////////////////////////////////\n");

    fprintf(_File,"// AUTO ASSAULT KEY MAPPING FILE\n");

    fprintf(_File,"////////////////////////////////////////////////////////////////\n\n");

    fprintf(_File,"// Instructions:\n");

    fprintf(_File,"// Use this file to assign custom hotkeys\n");

    fprintf(_File,"// You must use the exact same description text seen in-game to assign a key\n");

    fprintf(_File,"// Format:\n");

    fprintf(_File,"// Description Text=X;\n");

    fprintf(_File,"// use \'//\' for comments, special character codes are listed at the bottom\n");

    fprintf(_File,"// of this file.\n\n\n");

    fprintf(_File,"//////////////////////////////////////////\n");

    fprintf(_File,"// universal commands\n");

    pcVar3 = (char *)(param_1 + 0xd);

    local_8 = 5;

    do {

      if ((*pcVar3 != '\0') && (pcVar3[-1] == '\0')) {

        uVar2 = FUN_007a6de0(pcVar3,0xffffffff);

        fprintf(_File,"%s=",uVar2);

        if (*(short *)(pcVar3 + -7) != 0) {

          uVar2 = FUN_007f5120();

          fprintf(_File,"%s",uVar2);

          if (*(short *)(pcVar3 + 0x23) != 0) {

            uVar2 = FUN_007f5120();

            fprintf(_File,"+%s",uVar2);

          }

        }

        if (*(short *)(pcVar3 + -5) != 0) {

          uVar2 = FUN_007f5120();

          fprintf(_File,";%s",uVar2);

          if (*(short *)(pcVar3 + 0x25) != 0) {

            uVar2 = FUN_007f5120();

            fprintf(_File,"+%s",uVar2);

          }

        }

        fprintf(_File,";\n");

      }

      pcVar3 = pcVar3 + 0x34;

      local_8 = local_8 + -1;

    } while (local_8 != 0);

    fprintf(_File,"\n\n");

    pcVar3 = (char *)FUN_007a6de0("//////////////////////////////////////////\n",0xffffffff);

    fprintf(_File,pcVar3);

    pcVar3 = (char *)FUN_007a6de0("// action view commands\n",0xffffffff);

    fprintf(_File,pcVar3);

    pcVar3 = (char *)(param_1 + 0x249);

    local_8 = 0x78;

    do {

      if ((*pcVar3 != '\0') && (pcVar3[-1] == '\0')) {

        uVar2 = FUN_007a6de0(pcVar3,0xffffffff);

        fprintf(_File,"%s=",uVar2);

        if (*(short *)(pcVar3 + -7) != 0) {

          uVar2 = FUN_007f5120();

          fprintf(_File,"%s",uVar2);

          if (*(short *)(pcVar3 + 0x23) != 0) {

            uVar2 = FUN_007f5120();

            fprintf(_File,"+%s",uVar2);

          }

        }

        if (*(short *)(pcVar3 + -5) != 0) {

          uVar2 = FUN_007f5120();

          fprintf(_File,";%s",uVar2);

          if (*(short *)(pcVar3 + 0x25) != 0) {

            uVar2 = FUN_007f5120();

            fprintf(_File,"+%s",uVar2);

          }

        }

        fprintf(_File,";\n");

      }

      pcVar3 = pcVar3 + 0x34;

      local_8 = local_8 + -1;

    } while (local_8 != 0);

    fprintf(_File,"\n\n");

    pcVar3 = (char *)FUN_007a6de0("//////////////////////////////////////////\n",0xffffffff);

    fprintf(_File,pcVar3);

    pcVar3 = (char *)FUN_007a6de0("// camera controls\n",0xffffffff);

    fprintf(_File,pcVar3);

    pcVar3 = (char *)(param_1 + 0x1aa9);

    iVar4 = 0x14;

    do {

      if ((*pcVar3 != '\0') && (pcVar3[-1] == '\0')) {

        uVar2 = FUN_007a6de0(pcVar3,0xffffffff);

        fprintf(_File,"%s=",uVar2);

        if (*(short *)(pcVar3 + -7) != 0) {

          uVar2 = FUN_007f5120();

          fprintf(_File,"%s",uVar2);

          if (*(short *)(pcVar3 + 0x23) != 0) {

            uVar2 = FUN_007f5120();

            fprintf(_File,"+%s",uVar2);

          }

        }

        if (*(short *)(pcVar3 + -5) != 0) {

          uVar2 = FUN_007f5120();

          fprintf(_File,";%s",uVar2);

          if (*(short *)(pcVar3 + 0x25) != 0) {

            uVar2 = FUN_007f5120();

            fprintf(_File,"+%s",uVar2);

          }

        }

        fprintf(_File,";\n");

      }

      pcVar3 = pcVar3 + 0x34;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

    fprintf(_File,"\n\n");

    fprintf(_File,"///////////////////////////////////////////////////////////////////////////\n");

    fprintf(_File,"// KEY CODES\n");

    fprintf(_File,"///////////////////////////////////////////////////////////////////////////\n\n")

    ;

    fprintf(_File,"// Alphanumeric Keys:\n");

    fprintf(_File,"// For letters or numbers, just use the uppercase character (e.g. 9 or A).\n\n\n"

           );

    fprintf(_File,"// Function Keys:\n");

    fprintf(_File,"// For F1-F12, just type the key name (e.g. F9).\n\n\n");

    fprintf(_File,"// Special Character Keys:\n");

    fprintf(_File,"// ~ = GRAVE\n");

    fprintf(_File,"// \\ = BACKSLASH\n");

    fprintf(_File,"//   = SPACE\n");

    fprintf(_File,"// \' = APOSTROPHE\n");

    fprintf(_File,"// , = COMMA\n");

    fprintf(_File,"// - = MINUS\n");

    fprintf(_File,"// . = PERIOD\n");

    fprintf(_File,"// = = EQUALS\n");

    fprintf(_File,"// [ = LBRACKET\n");

    fprintf(_File,"// ] = RBRACKET\n");

    fprintf(_File,"// ; = SEMICOLON\n");

    fprintf(_File,"// / = SLASH      (Reserved, Cannot be bound)\n\n\n");

    fprintf(_File,"// Modifier Keys:\n");

    fprintf(_File,"// Shift = SHIFT\t(Reserved, Cannot be bound)\n");

    fprintf(_File,"// Ctrl\t= CONTROL\n");

    fprintf(_File,"// Alt\t= ALT\n");

    fprintf(_File,"// PgDn \t= NEXT\n");

    fprintf(_File,"// PgUp \t= PRIOR\n");

    fprintf(_File,"// Home\t\t= HOME\n");

    fprintf(_File,"// End \t\t= END\n");

    fprintf(_File,"// Ins\t\t= INSERT\n");

    fprintf(_File,"// Del\t\t= DELETE\n");

    fprintf(_File,"// Tab\t\t= TAB\n");

    fprintf(_File,"// Num Lock \t= NUMLOCK\n");

    fprintf(_File,"// Caps Lock\t= CAPITAL\n");

    fprintf(_File,"// Scroll Lock\t= SCROLL\n");

    fprintf(_File,"// Backspace\t= BACK\n");

    fprintf(_File,"// Enter\t= RETURN (Reserved, Cannot be bound)\n");

    fprintf(_File,"// Esc\t\t= ESCAPE (Reserved, Cannot be bound)\n\n\n");

    fprintf(_File,"// Number Pad Keys:\n");

    fprintf(_File,"// NUMPAD0 - NUMPAD9 (Numbers on pad)\n");

    fprintf(_File,"// * = MULTIPLY\n");

    fprintf(_File,"// - = SUBTRACT\n");

    fprintf(_File,"// + = ADD\n");

    fprintf(_File,"// . = DECIMAL\n");

    fprintf(_File,"// / = DIVIDE\n");

    fprintf(_File,"// Enter = NUMPADENTER\n\n\n");

    fprintf(_File,"// Arrow Keys:\n");

    fprintf(_File,"// UP\n");

    fprintf(_File,"// LEFT\n");

    fprintf(_File,"// RIGHT\n");

    fprintf(_File,"// DOWN\n");

    fclose(_File);

  }

  return 1;

}
