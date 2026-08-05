// =============================================================================
// FUN_0092d800
// -----------------------------------------------------------------------------
// Stable ID: aa_0092d800
// Address:   0x0092d800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092d800 @ 0x0092d800
// Stable ID: aa_0092d800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: while×5, do×4, for×2, return×1.
//  - Notable callees: strtok×2, FUN_0092d800.
//  - Return sites: 1.

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

char * FUN_0092d800(char *param_1)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  char *pcVar4;

  uint uVar5;

  uint uVar6;

  char *unaff_EBX;

  

  *unaff_EBX = '\0';

  pcVar3 = strtok((char *)0x0,param_1);

  while (pcVar4 = pcVar3, pcVar3 != (char *)0x0) {

    do {

      cVar2 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar2 != '\0');

    uVar5 = (int)pcVar4 - (int)pcVar3;

    pcVar4 = unaff_EBX + -1;

    do {

      pcVar1 = pcVar4 + 1;

      pcVar4 = pcVar4 + 1;

    } while (*pcVar1 != '\0');

    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar3;

      pcVar3 = pcVar3 + 4;

      pcVar4 = pcVar4 + 4;

    }

    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *pcVar4 = *pcVar3;

      pcVar3 = pcVar3 + 1;

      pcVar4 = pcVar4 + 1;

    }

    pcVar3 = unaff_EBX + -1;

    do {

      pcVar4 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar4 != '\0');

    *(uint16_t *)pcVar3 = DAT_00a2a000;

    pcVar3 = strtok((char *)0x0,param_1);

  }

  pcVar3 = unaff_EBX;

  do {

    cVar2 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar2 != '\0');

  unaff_EBX[(int)(pcVar3 + (-1 - (int)(unaff_EBX + 1)))] = '\0';

  return pcVar3 + (-1 - (int)(unaff_EBX + 1));

}
