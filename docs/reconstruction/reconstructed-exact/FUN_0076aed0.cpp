// =============================================================================
// FUN_0076aed0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076aed0
// Address:   0x0076aed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076aed0 @ 0x0076aed0
// Stable ID: aa_0076aed0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: while×4, do×3, if×3, return×2.
//  - Notable callees: tolower×2, FUN_0076aed0.
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

char * __thiscall FUN_0076aed0(char *param_1,char *param_2)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  char *pcVar7;

  char *local_8;

  

  pcVar2 = param_1;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  pcVar3 = param_2;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  if (param_1 < pcVar2 + -((int)pcVar3 - (int)(param_2 + 1))) {

    iVar6 = (int)param_1 - (int)param_2;

    pcVar7 = param_2;

    local_8 = param_1;

    do {

      while( true ) {

        if (*pcVar7 == '\0') {

          return local_8;

        }

        iVar4 = tolower((int)pcVar7[iVar6]);

        iVar5 = tolower((int)*pcVar7);

        if (iVar4 != iVar5) break;

        pcVar7 = pcVar7 + 1;

      }

      local_8 = local_8 + 1;

      iVar6 = iVar6 + 1;

      pcVar7 = param_2;

    } while (local_8 < pcVar2 + -((int)pcVar3 - (int)(param_2 + 1)));

  }

  return (char *)0x0;

}
