// =============================================================================
// FUN_0076c5d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c5d0
// Address:   0x0076c5d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076c5d0 @ 0x0076c5d0
// Stable ID: aa_0076c5d0
// Embedded strings (evidence for future rename):
//   - "%s_%4.4d_%2.2d_%2.2d.log"
//   - ";

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×1, while×1.
//  - Notable callees: strrchr×2, FUN_0076c5d0, GetLocalTime, _mkdir, _snprintf, fclose, fopen, perror.
//  - Strings: "%s_%4.4d_%2.2d_%2.2d.log"; ";

  }

  else {

    pcVar3 = "; "Unable to open new log file!".
//  - Return sites: 3.

  }

  else {

    pcVar3 = "
//   - "Unable to open new log file!"
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

void FUN_0076c5d0(void)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  FILE *pFVar4;

  uint uVar5;

  int unaff_ESI;

  _SYSTEMTIME local_114;

  char local_104 [260];

  

  GetLocalTime(&local_114);

  uVar5 = (uint)local_114.wDay;

  if (uVar5 == *(uint *)(unaff_ESI + 0x20)) {

    return;

  }

  pcVar3 = *(char **)(unaff_ESI + 0x14);

  if (pcVar3 != (char *)0x0) {

    iVar2 = -(int)pcVar3;

    do {

      cVar1 = *pcVar3;

      pcVar3[(int)(local_104 + iVar2)] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar3 = strrchr(local_104,0x5c);

    if ((pcVar3 != (char *)0x0) || (pcVar3 = strrchr(local_104,0x2f), pcVar3 != (char *)0x0)) {

      *pcVar3 = '\0';

    }

    _mkdir(local_104);

  }

  _snprintf((char *)(unaff_ESI + 0x24),0x1ff,"%s_%4.4d_%2.2d_%2.2d.log",

            *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),(uint)local_114.wYear,(uint)local_114.wMonth,uVar5);

  if (*(int *)(unaff_ESI + 0x1c) == 1) {

    pcVar3 = "a";

  }

  else {

    pcVar3 = "w";

  }

  pFVar4 = fopen((char *)(unaff_ESI + 0x24),pcVar3);

  if (pFVar4 == (FILE *)0x0) {

    perror("Unable to open new log file!");

    return;

  }

  if (*(FILE **)(unaff_ESI + 0x18) != (FILE *)0x0) {

    fclose(*(FILE **)(unaff_ESI + 0x18));

  }

  *(FILE **)(unaff_ESI + 0x18) = pFVar4;

  *(uint *)(unaff_ESI + 0x20) = uVar5;

  return;

}
