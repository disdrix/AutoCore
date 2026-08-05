// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_0092f710
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f710
// Callee of Named_Client_InitInstance
// Address:   0x0092f710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper. Evidence string: "keymap.ini". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "keymap.ini"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×8, do×3, while×3, return×2.
//  - Notable callees: strtok×3, FUN_007f72e0×2, FUN_0092db30×2, fgets×2, strncpy×2, FUN_007f9230, FUN_007f9480, FUN_0092f710.
//  - Strings: "keymap.ini".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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

void Named_CalleeOf_Named_Client_InitInstance_0092f710(int param_1)



{

  char cVar1;

  FILE *_File;

  char *pcVar2;

  char *pcVar3;

  int iVar4;

  uint16_t local_c18;

  uint8_t local_c16;

  uint32_t /* width from decompiler */ local_c14;

  uint16_t local_c10;

  uint8_t local_c0e;

  uint local_c08;

  FILE *local_c04;

  char local_c00 [512];

  char local_a00 [512];

  char local_800 [2048];

  

  _File = fopen("keymap.ini","r");

  local_c04 = _File;

  if (_File == (FILE *)0x0) {

    FUN_007f9480(param_1 + 0x116c);

    return;

  }

  local_c16 = DAT_00a152e2;

  local_c18 = DAT_00a152e0;

  local_c10 = DAT_00a152dc;

  local_c0e = DAT_00a152de;

  pcVar2 = fgets(local_800,0x800,_File);

  do {

    if (pcVar2 == (char *)0x0) {

      fclose(_File);

      return;

    }

    pcVar2 = strstr(local_800,(char *)&local_c10);

    if (pcVar2 != (char *)0x0) {

      *pcVar2 = '\0';

    }

    local_c14 = 0;

    pcVar2 = strtok(local_800,(char *)&local_c18);

    if (pcVar2 != (char *)0x0) {

      pcVar3 = pcVar2;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      if (1 < (uint)((int)pcVar3 - (int)(pcVar2 + 1))) {

        iVar4 = 0;

        do {

          local_c08 = FUN_007f9230(pcVar2);

          local_c08 = local_c08 & 0xff;

          if (local_c08 != 0) break;

          iVar4 = iVar4 + 1;

        } while (iVar4 < 4);

        _File = local_c04;

        if (((iVar4 != 4) && (local_c08 != 0)) &&

           (pcVar2 = strtok((char *)0x0,(char *)&local_c18), _File = local_c04,

           pcVar2 != (char *)0x0)) {

          strncpy(local_a00,pcVar2,0x1ff);

          local_c00[0] = '\0';

          pcVar2 = strtok((char *)0x0,(char *)&local_c18);

          if (pcVar2 != (char *)0x0) {

            strncpy(local_c00,pcVar2,0x1ff);

          }

          FUN_0092db30(&local_c14);

          FUN_007f72e0(param_1 + 0x116c,iVar4);

          FUN_0092db30(&local_c14);

          FUN_007f72e0(param_1 + 0x116c,iVar4);

          _File = local_c04;

        }

      }

    }

    pcVar2 = fgets(local_800,0x800,_File);

  } while( true );

}
