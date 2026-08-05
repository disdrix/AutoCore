// =============================================================================
// FUN_007a6610
// -----------------------------------------------------------------------------
// Stable ID: aa_007a6610
// Address:   0x007a6610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a6610 @ 0x007a6610
// Stable ID: aa_007a6610
// Embedded strings (evidence for future rename):
//   - "[$gender]"
//   - "[$/gender]"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: while×5, if×3, return×2.
//  - Notable callees: strstr×3, FUN_007a6610.
//  - Strings: "[$gender]"; "[$/gender]".
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

void FUN_007a6610(void)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  int unaff_EBX;

  char *pcVar4;

  char *pcVar5;

  

  pcVar2 = strstr(*(char **)(unaff_EBX + 4 + *(int *)(unaff_EBX + 0xc0) * 4),"[$gender]");

  while( true ) {

    if (pcVar2 == (char *)0x0) {

      return;

    }

    pcVar4 = pcVar2 + 9;

    pcVar3 = strstr(*(char **)(unaff_EBX + 4 + *(int *)(unaff_EBX + 0xc0) * 4),"[$/gender]");

    if (pcVar3 == (char *)0x0) break;

    if (*(int *)(unaff_EBX + 0xbc) == 1) {

      cVar1 = *pcVar4;

      while (cVar1 != '|') {

        *pcVar2 = cVar1;

        pcVar4 = pcVar2 + 10;

        pcVar2 = pcVar2 + 1;

        cVar1 = *pcVar4;

      }

    }

    else {

      cVar1 = *pcVar4;

      while (cVar1 != '|') {

        pcVar4 = pcVar4 + 1;

        cVar1 = *pcVar4;

      }

      pcVar5 = pcVar4 + 1;

      cVar1 = pcVar4[1];

      while (cVar1 != '[') {

        pcVar5 = pcVar5 + 1;

        *pcVar2 = cVar1;

        pcVar2 = pcVar2 + 1;

        cVar1 = *pcVar5;

      }

    }

    pcVar3 = pcVar3 + 10;

    cVar1 = *pcVar3;

    while (cVar1 != '\0') {

      pcVar3 = pcVar3 + 1;

      *pcVar2 = cVar1;

      pcVar2 = pcVar2 + 1;

      cVar1 = *pcVar3;

    }

    *pcVar2 = '\0';

    pcVar2 = strstr(*(char **)(unaff_EBX + 4 + *(int *)(unaff_EBX + 0xc0) * 4),"[$gender]");

  }

  return;

}
